//使用三方库 httplib.h 实现HTTPClient  发送post请求给HTTPServer
//仅需引入 httplib.h 头文件 
// httplib 开源库声明及具体介绍参见->   https://github.com/yhirose/cpp-httplib
//2021.8.24 --by yyt6801

#include <httplib.h>

using namespace httplib;
int main(){
    //向HttpServer发送post请求
    httplib::Client cli("127.0.0.1", 1234);

    char* send_data = "That's what you want to send to HTTPServer";
    httplib::Params params;
    params.emplace("send_data", send_data);
    if (auto res = cli.Post("/Http_Service", params)) {
        if (res->status == 200) {
            std::cout << res->body << std::endl;
        }
    }
    else {
        auto err = res.error();
    }
}
				