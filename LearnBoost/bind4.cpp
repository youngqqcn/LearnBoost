#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 16:42
*Author:yqq
*Descriptions:绑定函数对象
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <memory>
#include <algorithm>
#include <regex>
#include <codecvt>
#include <functional>
using namespace std::placeholders;
using namespace std;


//自定义 仿函数(重载了()运算符的类)
struct MyFunctor
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};



int main(void)
{
	auto MyAdd = std::bind(std::plus<int>(), _1, _2 );

	std::cout << MyAdd(23, 43) << std::endl;


	auto MyAdd2 = std::bind(MyFunctor(), _1 , _2 );

	std::cout << MyAdd2(23, 43) << std::endl;

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif