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
	//object_pool<��, �ڴ��������>
	object_pool<MyStruct> opl;
	auto p = opl.malloc(); //������Ҫ��ô��

	char *buf = (char *)malloc(100);

	std::cout << opl.is_from(p) << std::endl;
	std::cout << opl.is_from((MyStruct *)buf) << std::endl;


	if (buf)
	{
		delete buf;
		buf = NULL;
	}

	//���� ����MyStruct����������
}

void foo2()
{
	object_pool<MyStruct> pl;
	auto p =  pl.construct(8, 9);
	std::cout << p->a << " " << p->b << std::endl;

	//�����MyStruct�Ĺ��캯������������
}

struct MyStruct1
{
	int a;
	int b;
};


//��λnew
void foo3()
{
	//int *pInt = new int(10);
	//int *pint2 = new(pInt) int;
	char *pCh = new char[100];
	MyStruct1 *pCh2 = new(pCh + 55)(MyStruct1); //��һ��MyStruct�� pCh + 55��λ��
	pCh2->a = 10;
	pCh2->b = 15;

	char *get = pCh + 55;

	std::cout << ((MyStruct1 *)get)->a << std::endl;
	std::cout << ((MyStruct1 *)get)->b << std::endl;



	delete[]pCh;
}

//��λnew
void foo4()
{
	//int *pInt = new int(10);
	//int *pint2 = new(pInt) int;
	char *pCh = new char[100];
	new(pCh + 55)(MyStruct1); //��һ��MyStruct�� pCh + 55��λ��

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