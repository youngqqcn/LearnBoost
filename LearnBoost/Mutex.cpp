
#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/04/05 15:50
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>


#include "boost/thread.hpp"

using namespace std;


boost::mutex mutex;

#if 1   //不使用互斥量
void Add1(int *a)
{
	for (int i = 0; i < 10; i++)
	{
		*a = *a + 1;
		std::cout << *a << std::endl;
	}
}
#else   //使用互斥量
void Add1(int *a)
{
	mutex.lock();
	for (int i = 0; i < 10; i++)
	{
		*a = *a + 1;
		std::cout << *a  << std::endl;
	}
	mutex.unlock();
}
#endif


//虽然这里是 引用传递, 但是   bind(&Add1, iCommon)   是 值传递??

/*
void Add1(int &a)
{
	mutex.lock();
	for (int i = 0; i < 10; i++)
	{
		std::cout << a++ << std::endl;
	}
	mutex.unlock();
}
*/

int main(void)
{
	int iCommon = 0;
	//Add1(iCommon);

	boost::thread th1(bind( &Add1, &iCommon ));
	boost::thread th2(bind( &Add1, &iCommon ));

	//子线程还没启动
	std::cout <<"最初的结果是: "  << iCommon << std::endl;

	th1.join();
	th2.join();

	//此时, 所有子线程已经结束
	std::cout <<"最后的结果是: "  << iCommon << std::endl;
	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif