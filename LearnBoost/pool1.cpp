#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 14:19
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

#include <boost/pool/pool.hpp>

using namespace std;
using namespace boost;

void foo()
{
	pool<> pl(sizeof(int));

	int *pInt = static_cast<int *> (pl.malloc());
	if (!pInt) return;
	*pInt = 923432;

	std::cout << *pInt << std::endl;
}

struct MyStruct
{
	MyStruct() { std::cout << "create" << std::endl; };
	~MyStruct() { std::cout << "delete" << std::endl; };
	int a;
	int b;
	int c;
};

void foo2()
{
	//pool<MyStruct> pl(sizeof(MyStruct));
	//pool<内存分配类型>
	pool<> pl(0);
	MyStruct *p = static_cast<MyStruct *>( pl.ordered_malloc(10 * sizeof(MyStruct)));
	p->a = 10;
	p->b = 20;
	p->c = 30;

	//并不会调用MyStruct的构造函数和析构函数

}


int main(void)
{
	//foo();
	foo2();
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif