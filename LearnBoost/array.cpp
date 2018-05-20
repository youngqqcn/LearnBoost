#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 14:07
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


#include <array>    //封装的静态数组

using namespace std;

int main(void)
{
	std::array<int, 10> intArray = {0};

	for (auto i = intArray.begin(); i != intArray.end(); i++)
	{
		*i = 99;
		//std::cout <<*i << std::endl;
	}

	for (int i  =0 ; i < intArray.size(); i++)
	{
		std::cout << intArray[i] << std::endl;
	}

	unsigned long long uL = (1 << 64) - 1;

	std::cout << to_string(uL) << std::endl;

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif