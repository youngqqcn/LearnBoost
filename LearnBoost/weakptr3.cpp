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


//����ڵ�
struct Node
{

	~Node() { std::cout << "delete() " << std::endl; }

	typedef std::shared_ptr<Node> ptr_type;
	ptr_type next; // ָ����һ���ڵ�
};


//����ڵ�
struct Node2
{

	~Node2() { std::cout << "delete() " << std::endl; }

	typedef std::weak_ptr<Node2> ptr_type;
	ptr_type next; // ָ����һ���ڵ�
};



void foo1()
{
	auto p1 = std::make_shared<Node>();
	auto p2 = std::make_shared<Node>();

	// ѭ������(����)
	p1->next = p2;
	p2->next = p1;

	//�������ü���   ����2
	std::cout << p1.use_count() << std::endl;
	std::cout << p2.use_count() << std::endl;

	//std::cout << "hello world" << std::endl;
}

void foo2()
{
	auto p1 = std::make_shared<Node2>();
	auto p2 = std::make_shared<Node2>();

	//��Ϊ next �� weak_ptr  �����������ü���
	// ��, �����γ� ѭ������
	p1->next = p2;
	p2->next = p1;

	//�������ü���   ���� 1
	std::cout << p1.use_count() << std::endl;
	std::cout << p2.use_count() << std::endl;

	//std::cout << "hello world" << std::endl;
}


int main(void)
{
	foo1();  //��û����ȷ�ͷ���Դ
	//foo2(); //��ȷ�ͷ�����Դ

	system("pause");
	return 0;
}
#endif