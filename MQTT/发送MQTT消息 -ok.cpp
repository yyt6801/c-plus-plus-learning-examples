#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqtt/client.h>
#pragma warning( disable : 4996 )

#define ADDRESS     "tcp://192.168.0.103:1883"
#define CLIENTID    "PCDP_Client4"
#define TOPIC		"chat"
#define USERNAME	"admin"
#define PASSWORD	"password"
#define QOS         1
#define TIMEOUT     10000L

int main(int argc, char* argv[])
{
	// 创建客户端
	mqtt::client cli(ADDRESS, CLIENTID);
	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(20);
	connOpts.set_user_name(USERNAME);
	connOpts.set_password(PASSWORD);
	connOpts.set_clean_session(true);

	try {
		// 连接到客户端
		cli.connect(connOpts);

		// Keep the client running to receive messages
		while (true) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			// 创建并发布消息
			//time_t now = time(NULL);
			//tm* time_tm = localtime(&now);
			//通过不同精度获取相差的毫秒数
			auto now = std::chrono::system_clock::now(); 
			time_t tt = std::chrono::system_clock::to_time_t(now);
			auto time_tm = localtime(&tt);

			uint64_t dis_millseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count()
				- std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count() * 1000;

			char strTime[25] = { 0 };
			sprintf(strTime, "%d-%02d-%02d %02d:%02d:%02d:%03d", time_tm->tm_year + 1900,
				time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
				time_tm->tm_min, time_tm->tm_sec, (int)dis_millseconds);
			std::cout << strTime << std::endl;

			const std::string PAYLOAD = strTime;
			auto msg = mqtt::make_message(TOPIC, PAYLOAD);
			msg->set_qos(QOS);
			cli.publish(msg);
		}

		// 断开连接
		cli.disconnect();
	}
	catch (const mqtt::exception& exc) {
		std::cerr << "Error: " << exc.what() << " ["
			<< exc.get_reason_code() << "]" << std::endl;
		return 1;
	}

	return 0;
}