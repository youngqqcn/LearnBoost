#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/11/19 10:58
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

#include <functional>

using namespace std;


void func(int a)
{
	cout << __FUNCTION__ << "(" << a << ")->:" << endl;
}

class Demo
{
public:
	static int DemoFunc(int a) 
	{ 
		cout << __FUNCTION__ << "(" << a << ")->" << endl;
		return a;
	}
protected:
	
private:
};

class Bar
{
public:
	int operator()(int a)   //仿函数
	{
		cout << __FUNCTION__ << "(" << a << ")->:" << endl;
		return a;
	}
};


int main(void)
{
	function<void(int)> fry = func;  //绑定普通函数
	fry(9);

	function<int(int)> fr2 = Demo::DemoFunc; //绑定类的静态成员函数
	cout << fr2(343) << endl;


	Bar bar;
	fr2 = bar;
	cout << fr2(777) << endl;

	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif