//
// Created by fredrik on 2023-10-29.
//

#ifndef GESALLPROV_TCP_CONNECTION_H
#define GESALLPROV_TCP_CONNECTION_H

#include <boost/asio.hpp>
#include <string>

namespace {
	std::string read_data(boost::asio::ip::tcp::socket & socket);
}

namespace tcp_connection
{
	std::string getData(boost::asio::io_service& io_service);
}

#endif //GESALLPROV_TCP_CONNECTION_H
