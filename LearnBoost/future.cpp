#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/06/09 14:27
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

#include <boost/thread/future.hpp>
#include <boost/atomic.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/asio.hpp>
using namespace boost;

//#include <chrono>

using namespace std;


int Fab(int n)
{
	if (0 == n || 1 == n)
		return 1;
	return Fab(n - 1) + Fab(n - 2);
}

int main(void)
{
	auto f5 = async(std::bind(Fab, 5));
	auto f7 = async(launch::async, std::bind(Fab, 7));

	std::cout << f5.get() + f7.get() << std::endl;
	
	//auto f10 = async(std::bind(Fab, 10));
	//auto s = f10.wait_for(std::chrono::milliseconds(100));
	

	//std::cout << "hello world" << std::endl;
	std::system("pause");
	return 0;
}
#endif