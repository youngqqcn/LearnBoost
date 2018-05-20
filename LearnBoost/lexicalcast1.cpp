#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 15:58
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

#include <boost/lexical_cast.hpp>
using namespace boost;

using namespace std;

int main(void)
{
	//字符串转数值
	std::cout << lexical_cast<int>("34324") << std::endl;
	
	try
	{
		std::cout << lexical_cast<double>("1.414fdffsa", 6) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "发生了异常 " << std::endl;
	}

	std::stringstream sstr;


	//标准
	std::cout << stoi(" 324 ") << std::endl;
	std::cout << stof(" 32.04 ") << std::endl;
	std::cout << stof(" 320432432L ") << std::endl;
	std::cout << stof(" 32.04rr32432 ") << std::endl;
	std::cout << std::to_string(23432ul) << std::endl;
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif