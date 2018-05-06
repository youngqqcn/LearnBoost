#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/11/19 12:47
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <stdlib.h>

#include <boost/function.hpp>
#include <boost/bind.hpp>
using namespace std;
using namespace boost;

int main(void)
{
	//类似函数指针
	std::function<int(char *)> fun = atoi;
	cout << fun("56") + fun("44") << endl;
	
	fun = strlen;
	cout << fun("56") + fun("44") << endl;

	//使用函数指针实现
	int(*pFun)(const char *) = &atoi;
	cout << pFun("56") + pFun("44") << endl;

	int(*pFun2)(const char *, const char *) = &strcmp;
	cout << pFun2("hello", "helloa") << endl;
	cout << pFun2("hello", "hello") << endl;

	fun = boost::bind(strcmp, "yqq", _1);
	cout <<"tom is equal yqq:" << fun("tom") << endl;
	cout <<"yqq is equal yqq:" << fun("yqq") << endl;



	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif