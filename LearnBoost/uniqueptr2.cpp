#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 10:08
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

//#include <boost/make_unique.hpp>

using namespace std;

int main(void)
{
	unique_ptr<string> p1 = std::make_unique<string>("fdsdf");

	unique_ptr<string[]> p(new string[100]);  //ok
	//unique_ptr<string> p(new string[100]); //»á±À

	for (int i = 0; i < 100; i++)
	{
		*(p.get() + i) = "hello";
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << *(p.get() + i) << std::endl;
	}
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif