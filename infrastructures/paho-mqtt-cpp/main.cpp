#include <iostream>
#include "mqtt/client.h"
#include "mqtt/connect_options.h"
#include "mqtt/message.h"
#include "mqtt/exception.h"

using namespace std;
using namespace mqtt;

int main(int argc, char* argv[])
{
	const std::string TOPIC = "SISA/PAHO/TEST";
	const std::string PAYLOAD1 = "MSG_SISA_PAHO_TEST_1";
	const std::string ADDRESS = "test.mosquitto.org";
	const std::string CLIENT_ID = "ID123456789";
	const int QoS = 2;

	const char* PAYLOAD2 = "MSG_SISA_PAHO_TEST_2";

	// Create a client

	mqtt::client cli(ADDRESS, CLIENT_ID);

	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(20);
	connOpts.set_clean_session(true);

	try {
		// Connect to the client

		cli.connect(connOpts);

		// Publish using a message pointer.

		auto msg = mqtt::make_message(TOPIC, PAYLOAD1);
		msg->set_qos(QoS);

		cli.publish(msg);

		// Now try with itemized publish.

		cli.publish(TOPIC, PAYLOAD2, strlen(PAYLOAD2), 0, false);

		// Disconnect

		cli.disconnect();
	}
	catch (const mqtt::exception& exc) {
		std::cerr << "Error: " << exc.what() << " ["
			<< exc.get_reason_code() << "]" << std::endl;
		return 1;
	}

	return 0;
}

/*
 * http://www.eclipse.org/paho/clients/cpp/
 */
