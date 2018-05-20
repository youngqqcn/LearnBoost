
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

#if 1   //��ʹ�û�����
void Add1(int *a)
{
	for (int i = 0; i < 10; i++)
	{
		*a = *a + 1;
		std::cout << *a << std::endl;
	}
}
#else   //ʹ�û�����
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


//��Ȼ������ ���ô���, ����   bind(&Add1, iCommon)   �� ֵ����??

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

	//���̻߳�û����
	std::cout <<"����Ľ����: "  << iCommon << std::endl;

	th1.join();
	th2.join();

	//��ʱ, �������߳��Ѿ�����
	std::cout <<"���Ľ����: "  << iCommon << std::endl;
	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif