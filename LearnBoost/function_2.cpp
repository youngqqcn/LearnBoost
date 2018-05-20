#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 20:43
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
#include <algorithm>
#include <regex>
#include <codecvt>
#include <functional>
using namespace std::placeholders;
using namespace std;


class demo_class
{
private:
	typedef function<void(int)> func_t;
	func_t func;
	int n;
public:
	demo_class(int i) :n(i) { };

	template< typename Callback >
	void accept(Callback f)
	{
		func = f;
	}

	void run()
	{
		func(n);
	}
};

void call_back_func(int i)
{
	std::cout << "call_back_func " << i * 2 << std::endl;
}

class call_back_obj
{
public:
	call_back_obj(int i) :x(i) {};
	void operator()(int i)
	{
		std::cout << i * x++ << std::endl;
	}
	

private:
	int x;
};



int main1(void)
{

	demo_class dc(100);
	dc.accept(call_back_func);
	dc.run();
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}

int main()
{
	demo_class dc(10);
	call_back_obj cbo(2); //函数对象(仿函数)
	dc.accept(std::ref(cbo));
	dc.run();
	dc.run();

	system("pause");
	return 0;
}





#endif