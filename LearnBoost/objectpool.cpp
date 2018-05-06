#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 14:41
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
#include <stdlib.h>

#include <boost/pool/object_pool.hpp>
using namespace boost;

using namespace std;


struct MyStruct
{
	MyStruct(int a, int b):a(a),b(b) { std::cout << "create" << std::endl; }
	~MyStruct() { std::cout << "delete" << std::endl; }

	int a;
	int b;

};


void foo()
{
	//object_pool<类, 内存分配类型>
	object_pool<MyStruct> opl;
	auto p = opl.malloc(); //尽量不要这么用

	char *buf = (char *)malloc(100);

	std::cout << opl.is_from(p) << std::endl;
	std::cout << opl.is_from((MyStruct *)buf) << std::endl;


	if (buf)
	{
		delete buf;
		buf = NULL;
	}

	//仅仅 调用MyStruct的析构函数
}

void foo2()
{
	object_pool<MyStruct> pl;
	auto p =  pl.construct(8, 9);
	std::cout << p->a << " " << p->b << std::endl;

	//会调用MyStruct的构造函数和析构函数
}

struct MyStruct1
{
	int a;
	int b;
};


//定位new
void foo3()
{
	//int *pInt = new int(10);
	//int *pint2 = new(pInt) int;
	char *pCh = new char[100];
	MyStruct1 *pCh2 = new(pCh + 55)(MyStruct1); //放一个MyStruct在 pCh + 55的位置
	pCh2->a = 10;
	pCh2->b = 15;

	char *get = pCh + 55;

	std::cout << ((MyStruct1 *)get)->a << std::endl;
	std::cout << ((MyStruct1 *)get)->b << std::endl;



	delete[]pCh;
}

//定位new
void foo4()
{
	//int *pInt = new int(10);
	//int *pint2 = new(pInt) int;
	char *pCh = new char[100];
	new(pCh + 55)(MyStruct1); //放一个MyStruct在 pCh + 55的位置

	((MyStruct1 *)(pCh + 55))->a = 99;
	((MyStruct1 *)(pCh + 55))->b = 55;

	char *get = pCh + 55;

	std::cout << ((MyStruct1 *)get)->a << std::endl;
	std::cout << ((MyStruct1 *)get)->b << std::endl;



	delete[]pCh;
}


int main(void)
{
	//foo();
	//foo();
	//foo2();
	foo4();

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif