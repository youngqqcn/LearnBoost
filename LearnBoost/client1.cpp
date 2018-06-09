#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/06/09 15:52
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
#include <numeric>

#include <boost/asio.hpp>
using namespace boost::asio;

using namespace std;

int main(void)
{
	try {
		typedef ip::tcp::acceptor acceptor_type;
		typedef ip::tcp::endpoint endpoint_type;
		typedef ip::tcp::socket	socket_type;
		typedef ip::address address_type;

		std::cout << "client start. " << endl;
		io_service io;

		socket_type sock(io);
		endpoint_type ep(address_type::from_string("127.0.0.1"), 8888);

		sock.connect(ep);
		cout << sock.available() << endl;

		//vector<char> str(sock.available() + 1, 0);
		//sock.receive(buffer(str));

		vector<char> buf(5, 0);
		boost::system::error_code ec;

		for (;;)
		{
			sock.read_some(buffer(buf), ec);
			//sock.read_some()
			if (ec) break;
			std::cout << &buf[0];
		}

		//std::cout << "receive from" << sock.remote_endpoint().address();
		//cout << &buf[0] << endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif