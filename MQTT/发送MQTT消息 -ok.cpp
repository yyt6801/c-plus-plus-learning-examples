#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "MQTTClient.h"
#include <mqtt/client.h>
#pragma warning( disable : 4996 )

#define ADDRESS     "tcp://127.0.0.1:1883"
#define CLIENTID    "PCDP_Client"
#define QOS         1
#define TIMEOUT     10000L

int main(int argc, char* argv[])
{
	const std::string TOPIC = "PLTCM/TAGS";

	// 创建客户端
	mqtt::client cli(ADDRESS, CLIENTID);
	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(20);
	connOpts.set_clean_session(true);

	try {
		// 连接到客户端
		cli.connect(connOpts);

		// Keep the client running to receive messages
		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(1));

			// 创建并发布消息
			time_t now = time(NULL);
			tm* time_tm = localtime(&now);
			char strTime[25] = { 0 };
			sprintf(strTime, "%d-%02d-%02d %02d:%02d:%02d", time_tm->tm_year + 1900,
				time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
				time_tm->tm_min, time_tm->tm_sec);
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