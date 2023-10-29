//
// Created by Fredrik Ekstedt Karpers on 2023-10-29.
//

#include <iostream>
#include <fstream>
#include <boost/asio.hpp>

#include "config_parser.h"
#include "tcp_connection.h"
#include "plug_adapter.h"

#include "nlohmann/json.hpp"


using namespace boost::asio;
using ip::tcp;
using nlohmann::json_abi_v3_11_2::json;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		std::cout << "Provide path to config file in argument" << std::endl;
		return 1;
	}
	std::string configPath{argv[1]};
	boost::asio::io_service io_service;
	
	// Program main loop
	while(true) {
		std::ifstream config{configPath};
		if (!config.is_open()) {
			std::cerr << "Error opening the config file." << std::endl;
			return 1;
		}
		
		std::vector<settings_parser::TempPair> pairs = settings_parser::parse(config);
		config.close();
		
		std::string payload = tcp_connection::getData(io_service);
		
		json payload_json = json::parse(payload);
		float goalTemp = settings_parser::calculateGoal(payload_json["gravity"], pairs);
		plug_adapter::setWallPlug(payload_json["temp"], goalTemp, payload_json["interval"]);
	}
	
	
	return 0;
}
