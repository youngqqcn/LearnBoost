#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/20 11:39
*Author:yqq
*Descriptions:  �Զ���������
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
#include <numeric>
#include <functional>
using namespace std;

#include "slots.h"
//
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
using namespace boost;

int main1(void)
{
	signal<void()> sig;
	sig.connect(slots<10>()); //ok
	sig(); //����????

	auto ptr = new slots<20>; //ָ��
	sig.connect(std::ref(*ptr)); //����

	//��Ȼ����û�б���, ��������δ�����....
	delete ptr; //�ͷ�
	ptr = NULL;
	sig(); //����????
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}


int main2()
{
	typedef signal<void()> signal_t;
	signal_t sig;
	sig.connect(slots<10>()); //��ͨ�÷�
	//sig();


	//auto p = std::make_shared<slots<20>>(); //error
	auto p = boost::make_shared<slots<20>>();
	sig.connect(signal_t::slot_type(std::ref(*p)).track(p));
	sig();
	std::cout << "----------------------" << std::endl;

	p.reset(); //���ٲۺ���

	sig();  //ֻʣ  slots<10>() ��



	system("pause");
	return 0;
}

int main3()
{
	typedef signal<void()> signal_t;
	typedef signal_t::slot_type slot_t;
	signal_t sig;
	sig.connect(slots<10>()); //��ͨ�÷�


	auto p1 = boost::make_shared<slots<20>>(); //error
	auto p2 = boost::make_shared<slots<30>>(); //error


	std::function<void()> func = std::ref(*p1);
	sig.connect(slot_t(func).track(p1));

	//bind
	sig.connect(slot_t(&slots<30>::operator(), p2.get()).track(p2) );

	sig();
	std::cout << "--------------" << std::endl;
	p1.reset(); //����
	p2.reset(); //����

	sig(); 




	system("pause");
	return 0;
}


int main()
{


	//////////////////////////////////////////////////////////////////////////
	typedef signal<int(int)> signal_t;
	typedef signal_t::slot_type slot_t;

	std::cout << "--------------" << std::endl;


	signal_t sig2;

	auto p3 = boost::make_shared<slots_2<50>>();

	//sig2.connect(slot_t(&slots_2<50>::operator(), p3.get(), std::placeholders::_1).track(p3)); //error!!!
	sig2.connect(slot_t(&slots_2<50>::operator(), p3.get(), _1).track(p3));

	sig2(3);



	system("pause");
	return 0;
}
#endif