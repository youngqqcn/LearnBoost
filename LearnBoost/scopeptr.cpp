#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/05 13:49
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

#include <boost/scoped_ptr.hpp>  //作用域指针

using namespace std;
using namespace boost;


/*
模仿 boost::scope_ptr 实现自己的 MyScopePtr
*/
template <typename T>
class MyScopePtr
{
private:
	T * px;
	MyScopePtr(MyScopePtr const & other) {};
	MyScopePtr& operator = (MyScopePtr const & other) {};

	void operator == (MyScopePtr const &)const {};
	void operator != (MyScopePtr const &)const {};
public:
	explicit MyScopePtr(T *p = 0) { this->px = p; };
	~MyScopePtr() 
	{ 
		if (px) 
		{
			//delete []px;  //这里存在问题, 当管理 new[] 时, 如果只使用
			delete px;  // delete , 则会释放资源错误!
			px = NULL;
		} 
	};

	void reset(T *p = 0) 
	{ 
		if (this->px)  delete this->px; 
		this->px = p; 
	};

	T& operator *()const { return *px; }
	T& operator ->()const { return *px; }
	T* get()const { return px; }

	explicit operator bool()const
	{
		return (NULL == this->px) ? true : false;
	}

	void swap(MyScopePtr &b)
	{
		T *tmp;
		tmp = this->px;
		this->px = b->px;
		b->px = tmp;
	}

	friend bool operator == (MyScopePtr<T> const &p, std::nullptr_t);
};

template<class T> inline
bool operator == (MyScopePtr<T> const &p, std::nullptr_t)
{
	return (nullptr == p.get()) ? (true) : (false);
}



void foo1()
{
	//scoped_ptr<int> pInt(new int[100]);
	MyScopePtr<int> pInt(new int[100]);

	for (int i = 0; i < 100; i++)
	{
		*(pInt.get() + i) = i;
	}
	for (int i = 0;i < 100; i++)
	{
		std::cout << pInt.get()[i] << std::endl;
	}

}
void foo2()
{
	scoped_ptr<int> pInt(new int[100]);
	//scoped_ptr<int> pInt2(pInt); //error
	scoped_ptr<int> pInt2(std::nullptr_t);

	for (int i = 0; i < 100; i++)
	{
		*(pInt.get() + i) = i;
	}

	//pInt2 = pInt; //error


	for (int i = 0;i < 100; i++)
	{
		std::cout << pInt.get()[i] << std::endl;
	}

}

void foo3()
{
	scoped_ptr<int> pInt(nullptr);
	//scoped_ptr<int> pInt2(pInt); //error
	scoped_ptr<int> pInt2(std::nullptr_t);

	if (pInt == nullptr)
	{
		std::cout << "pInt is null" << std::endl;
		return;
	}

	for (int i = 0; i < 100; i++)
	{
		*(pInt.get() + i) = i;
	}

	//pInt2 = pInt; //error


	for (int i = 0;i < 100; i++)
	{
		std::cout << pInt.get()[i] << std::endl;
	}
}

void foo4()
{
	MyScopePtr<std::string> p1(new string[100]);
	for (int i =0; i < 100; i++)
	{
		char buf[100] = { 0 };
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "hello %d", i);
		*(p1.get() + i) = std::string(buf);
	}
	for (int i = 0;i < 50; i++)
	{
		std::cout << p1.get()[i] << std::endl;
	}

}



int main(void)
{
	//foo1();
	
	//foo3();
	foo4();

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif