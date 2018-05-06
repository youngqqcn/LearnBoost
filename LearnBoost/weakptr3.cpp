#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 12:04
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

using namespace std;


//链表节点
struct Node
{

	~Node() { std::cout << "delete() " << std::endl; }

	typedef std::shared_ptr<Node> ptr_type;
	ptr_type next; // 指向下一个节点
};


//链表节点
struct Node2
{

	~Node2() { std::cout << "delete() " << std::endl; }

	typedef std::weak_ptr<Node2> ptr_type;
	ptr_type next; // 指向下一个节点
};



void foo1()
{
	auto p1 = std::make_shared<Node>();
	auto p2 = std::make_shared<Node>();

	// 循环引用(链表)
	p1->next = p2;
	p2->next = p1;

	//看看引用计数   都是2
	std::cout << p1.use_count() << std::endl;
	std::cout << p2.use_count() << std::endl;

	//std::cout << "hello world" << std::endl;
}

void foo2()
{
	auto p1 = std::make_shared<Node2>();
	auto p2 = std::make_shared<Node2>();

	//因为 next 是 weak_ptr  不会增加引用计数
	// 故, 不会形成 循环引用
	p1->next = p2;
	p2->next = p1;

	//看看引用计数   都是 1
	std::cout << p1.use_count() << std::endl;
	std::cout << p2.use_count() << std::endl;

	//std::cout << "hello world" << std::endl;
}


int main(void)
{
	foo1();  //并没有正确释放资源
	//foo2(); //正确释放了资源

	system("pause");
	return 0;
}
#endif