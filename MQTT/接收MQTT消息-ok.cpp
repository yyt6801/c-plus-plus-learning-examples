#include <iostream>
#include <string>
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>

const std::string ADDRESS = "tcp://127.0.0.1:1883";
const std::string CLIENTID = "PCDP_Client";
const std::string TOPIC = "PLTCM/TAGS";
const int QOS = 1;

class callback : public virtual mqtt::callback
{
public:
	void connection_lost(const std::string& cause) override {
		std::cout << "\nConnection lost" << std::endl;
		if (!cause.empty())
			std::cout << "\tcause: " << cause << std::endl;
	}

	void message_arrived(mqtt::const_message_ptr msg) override {
		std::cout << "Message arrived" << std::endl;
		std::cout << "\ttopic: " << msg->get_topic() << std::endl;
		std::cout << "\tpayload: " << msg->to_string() << std::endl;

		// Parse JSON message
		try {
			auto json_msg = nlohmann::json::parse(msg->to_string());
			std::cout << "Parsed JSON: " << json_msg.dump(4) << std::endl;
		}
		catch (const nlohmann::json::parse_error& e) {
			std::cerr << "JSON parse error: " << e.what() << std::endl;
		}
	}
	void delivery_complete(mqtt::delivery_token_ptr token) override {}
};

int main() {
	mqtt::async_client client(ADDRESS, CLIENTID);
	callback cb;
	client.set_callback(cb);

	mqtt::connect_options connOpts;
	connOpts.set_clean_session(true);

	try {
		std::cout << "Connecting to the MQTT server..." << std::endl;
		client.connect(connOpts)->wait();
		std::cout << "Connected" << std::endl;

		std::cout << "Subscribing to topic '" << TOPIC << "'..." << std::endl;
		client.subscribe(TOPIC, QOS)->wait();
		std::cout << "Subscribed" << std::endl;

		// Keep the client running to receive messages
		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}

		// Disconnect and clean up
		client.disconnect()->wait();
		std::cout << "Disconnected" << std::endl;
	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc.what() << std::endl;
		return 1;
	}

	return 0;
}