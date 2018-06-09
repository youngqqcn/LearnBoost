#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/06/09 15:40
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <memory>
#include <algorithm>
#include <regex>
#include <codecvt>
#include <exception>
#include <numeric>

using namespace std;

#include <boost/asio/ip/tcp.hpp>
using namespace boost;
using namespace boost::asio;

int main(void)
{
	try {
		typedef ip::tcp::acceptor acceptor_type;
		typedef ip::tcp::endpoint endpoint_type;
		typedef ip::tcp::socket	socket_type;

		std::cout << "server start. " << endl;
		io_service io;

		acceptor_type acceptor(io, endpoint_type(ip::tcp::v4(), 8888));

		std::cout << acceptor.local_endpoint().address() << endl;

		for (;;)
		{
			socket_type sock(io);
			acceptor.accept(sock);

			std::cout << "client:";
			std::cout << sock.remote_endpoint().address() << endl;

			sock.send(buffer("hello world"));
		}

	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	//std::cout << "hello world" << std::endl;
	std::system("pause");
	return 0;
}
#endif