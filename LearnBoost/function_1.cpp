#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 18:55
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
#include <algorithm>
#include <regex>
#include <codecvt>
#include <functional>
using namespace std::placeholders;
using namespace std;

struct MyStruct
{
	int add(int a, int b) { return a + b; }

};

int main(void)
{
	//第1种方式
	function<int(MyStruct&, int, int)> func1;
	func1 = bind(&MyStruct::add, _1, _2, _3);
	std::cout << func1(MyStruct(), 99, 99) << std::endl;

	//第2种方式
	function<int(int, int) > func2;
	MyStruct obj;
	func2 = bind(&MyStruct::add, &obj, _1, _2); //bind时才给出类的实例
	std::cout << func2(77, 77) << std::endl;

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif