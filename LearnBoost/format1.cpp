#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 10:24
*Author:yqq
*Descriptions:  了解一下即可,  和 printf , sprintf 作用相同
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

#include <boost/format.hpp>

using namespace std;
using namespace boost;

int main(void)
{
	format fmt("(%1% + %2%)");
	fmt % 2 % 5;
	std::cout << fmt << std::endl;
	fmt % "hello" % 5;
	std::cout << fmt << std::endl;


	int a = 3 , b = 3;
	format fmt2("%d * %d = %d");
	fmt2 % a % b % (a * b);
	std::cout << fmt2 << std::endl;
	
	format hexFmt("%08X");
	hexFmt % 255;
	std::cout << hexFmt << std::endl;


	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif