//使用三方库 httplib.h 实现HTTPServer  监听Clinet发来的get/post请求
//仅需引入 httplib.h 头文件 
// httplib 开源库声明及具体介绍参见->   https://github.com/yhirose/cpp-httplib
//2021.7.6 --by yyt6801


#include <httplib.h>
#include <nlohmann/json.hpp>
using namespace nlohmann;
void readJson(json &json_data, std::string file_name) {
	std::string config_file = std::string("C:\\") + file_name;
	std::ifstream fin(config_file); //相对路径
	fin >> json_data;
	fin.close();
}
int main(void)
{
    using namespace httplib;

    Server svr;

    svr.Get("/hi", [](const Request& req, Response& res) {
    res.set_content("Hello World!", "text/plain");
    });

    svr.Get(R"(/numbers/(\d+))", [&](const Request& req, Response& res) {
    auto numbers = req.matches[1];
    res.set_content(numbers, "text/plain");
    });

    svr.Get("/body-header-param", [](const Request& req, Response& res) {
    if (req.has_header("Content-Length")) {
        auto val = req.get_header_value("Content-Length");
    }
    if (req.has_param("key")) {
        auto val = req.get_param_value("key");
    }
    res.set_content(req.body, "text/plain");
    });

    svr.Get("/stop", [&](const Request& req, Response& res) {
    svr.stop();
    });

    //监听post请求   Client的 post请求url为: http://ip:1234/Http_Service
    svr.Post("/Http_Service", [&](const Request& req, Response& res) {
        if (req.has_header("Content-Length")) {
            auto val = req.get_header_value("Content-Length");
            //std::cout << val << std::endl;
        }
        //receive the request body from Client
        const char* request_data = req.body.c_str();
        std::cout << request_data  << std::endl;
        
        //do what you want ...

        //return the response data to Client
        const char* strBuffer = "data--return to Client";
		std::cout << strBuffer << std::endl;
		json ret;
		readJson(ret, "res_json.json"); //获取json文件进行测试，之后直接从接口获取对应json数据

		res.set_content(ret.dump(), "text/plain");
    });

  svr.listen("0.0.0.0", 6801);
}
