#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 15:34
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

#include <boost/variant.hpp>

using namespace boost;
using namespace std;

int main(void)
{
	variant<int, string, double> v;
	v = "hello";

	std::cout << get<string>(v) << std::endl;

	v = 324.324;
	std::cout << get<double>(v) << std::endl;



	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif