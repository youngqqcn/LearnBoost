#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 15:13
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <memory>
#include <regex>
#include <codecvt>

#include <boost/any.hpp>

using namespace boost;
using namespace std;

int main(void)
{
	any a1(string("hello"));
	//any a1("hello");

	try
	{
		std::cout << any_cast<string>(a1) << std::endl;
		//std::cout << any_cast<char *>(a1) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif