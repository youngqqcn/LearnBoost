#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/08/21 23:18
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

using namespace std;

#include <boost/function.hpp>


bool Fun1(int i , double d)
{
	return i > d;
}


int Test1()
{

	boost::function<bool (int, double)> f;

	f = Fun1;

	std::cout << f(4344, 342.23) << std::endl; //1

	/*if (f(998, 3434.34))
	{
		std::cout << "big" << std::endl;
	}
	else
	{
		std::cout << "little" << std::endl;

	}*/

	return 0;
}


int main(void)
{
	
	Test1();

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif