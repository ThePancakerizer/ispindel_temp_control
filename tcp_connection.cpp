//
// Created by fredrik on 2023-10-29.
//

#include "tcp_connection.h"

using namespace boost::asio;
using ip::tcp;

namespace {
	std::string read_data(tcp::socket & socket) {
		std::string data{};
		
		boost::asio::streambuf buf{};
		boost::asio::read_until(socket, buf, "\n");
		
		streambuf::const_buffers_type bufs = buf.data();
		std::string s(buffers_begin(bufs), buffers_begin(bufs) + buf.size());
		data = boost::asio::buffer_cast<const char *>(buf.data());
		
		return data;
	}
}

namespace tcp_connection
{
	std::string getData(boost::asio::io_service& io_service)
	{
		tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 9001 ));
		tcp::socket socket_(io_service);
		acceptor_.accept(socket_);
		std::string message = read_data(socket_);
		socket_.close();
	}
}