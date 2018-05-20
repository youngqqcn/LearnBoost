#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 16:21
*Author:yqq
*Descriptions: 绑定  成员函数
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


#include <functional>   //bind


using namespace std;
using namespace std::placeholders;  // _1 , _2 ...这东西

struct MyStruct
{
	int f(int a, int b) { return a + b; }
};


int main(void)
{
	MyStruct obj;

	auto fx = std::bind(&MyStruct::f, obj, _1, 200);
	std::cout << fx(88) << std::endl;
	
	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif