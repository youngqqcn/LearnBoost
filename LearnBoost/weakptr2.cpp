#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 11:44
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

#include <boost/enable_shared_from_this.hpp>  //对象的自我管理
#include <boost/make_shared.hpp>

using namespace std;

//using namespace boost;

//template<typename T>
class MyClass : public enable_shared_from_this<MyClass>
{
public:
	MyClass() :x(0) {};
	MyClass(int n) : x(n) {};
	int x;
	void print() { std::cout << "MyClass()" << x << std::endl; }
};


void dont_do_this()
{
	// 用 shared_ptr 管理栈上的对象!!!
	//编译不会保存, 但是会运行时崩溃
	MyClass my; 
	auto p = my.shared_from_this();
}




int main(void)
{
	/*
	auto sp = std::make_shared<MyClass>(555);
	sp->print();

	auto p = sp->shared_from_this();
	p->x = 98989;
	p->print();
	*/

	dont_do_this();
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif