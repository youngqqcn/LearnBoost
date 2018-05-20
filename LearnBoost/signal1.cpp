#if 1
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 21:08
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

//#include <boost/signals.hpp>
#include <boost/signals2.hpp>
#include <Windows.h>
using namespace boost::signals2;

void slot1()
{
	for (int i = 0 ;i < 10; i++)
	{
		std::cout << "slot1 called" << std::endl;
		Sleep(100);
	}
}
void slot2()
{
	std::cout << "slot2 called" << std::endl;
}

void foo(signal<void()> &sig)
{
	Sleep(1000 * 2);
	std::cout << "准备发送信号" << std::endl;
	sig(); //发送信号
	std::cout << "发送信号完毕" << std::endl;

}

int main(void)
{
	signal<void()> sig;
	sig.connect(&slot1);

	//sig(); //发送信号
	foo(sig);
	
	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif