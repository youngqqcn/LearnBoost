#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 13:36
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

#include <boost/intrusive_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

using namespace std;
using namespace boost;


//直接继承辅助 引用计数类
struct MyCounter : public boost::intrusive_ref_counter<MyCounter>
{
	MyCounter() { std::cout << "create" << std::endl; }
	~MyCounter() { std::cout << "delete" << std::endl; }

};
void foo()
{
	intrusive_ptr<MyCounter> ip(new MyCounter);
}

//自己实现引用计数类
struct MyCounter0
{
public:
	MyCounter0() :m_count(0) { std::cout << "create" << std::endl; };
	~MyCounter0(){  std::cout << "delete" << std::endl; };
	int m_count;
};

#if 1  //必须实现以下两个回调函数
void  intrusive_ptr_add_ref(MyCounter0 *p)
{
	++p->m_count;
}

void  intrusive_ptr_release(MyCounter0 *p)
{
	if (--p->m_count == 0)
		delete p;
}
#endif

void foo2()
{
	typedef intrusive_ptr<MyCounter0> CT;
	CT ip(new MyCounter0);
	CT ip2(ip);

	std::cout << ip->m_count << std::endl;
	CT ip3(ip.get(), false);  //弱引用, 相当于 weak_ptr
	std::cout << ip->m_count << std::endl;

}


int main(void)
{
	//foo();

//	foo2();
	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif