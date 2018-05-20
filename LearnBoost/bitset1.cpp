#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 14:27
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

#include <boost/dynamic_bitset.hpp>

using namespace boost;
using namespace std;

#include <bitset>

int main(void)
{
	//bitset 不能动态增长

	bitset<10> bs1("1010");
	bitset<10> bs2("1011");
	std::cout << bs1.to_ulong() << std::endl;
	std::cout << bs2.to_ulong() << std::endl;



	std::cout << (bs1 ^ bs2) << std::endl;
	std::cout << (bs1 & bs2) << std::endl;
	std::cout << (bs1 | bs2) << std::endl;
	std::cout << (~bs1 ) << std::endl;
	std::cout << (~bs2 ) << std::endl;


	//bs1.push_back(); //不支持
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif