#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/08/20 12:00
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <boost/smart_ptr.hpp>

#include <boost/weak_ptr.hpp>
#include <boost/scoped_array.hpp>

using namespace std;



class A 
{
public:
	A() 
	{ 
		std::cout << "A()" << std::endl; 
	};

	virtual ~A() 
	{
		std::cout << "~A()" << std::endl;
	};

public:

	void Fun() { std::cout << "hello world" << std::endl; }

};


int TestSmartPtr1()
{
	boost::shared_ptr<A> p1(new A);

	std::cout << p1.use_count() << std::endl; //对象被引用的个数

	//boost::shared_ptr<A> p2(p1);
	//std::cout << p1.use_count() << std::endl; // 对象被引用的个数


	p1.reset();//此处会自动释放堆对象

	std::cout <<"after reset:"<< p1.use_count() << std::endl;




	return 0;
}

int TestSmartPtr2()
{

	vector<boost::shared_ptr<A>> v1;

	boost::shared_ptr<A> p1(new A);

	std::cout << p1.use_count() << std::endl;

	v1.push_back(p1);
	std::cout << p1.use_count() << std::endl;


	return 0;
}

int TestSmartPtr3()
{
	int *p = new int(24);



	//不要把一个指针赋给多个智能指针管理 
	//boost::shared_ptr<int> p1(p);
	//boost::shared_ptr<int> p2(p);
	//boost::shared_ptr<int> p3(p); 


	return 0;
}


int TestWeakPtr1()
{
	boost::weak_ptr<A> p;

	boost::shared_ptr<A> p2(new A);
	std::cout << p2.use_count() << std::endl;

	p = p2;

	std::cout << p2.use_count() << std::endl;


	boost::shared_ptr<A> p3(new A);
	std::cout << p3.use_count() << std::endl;

	if (NULL == p3)
	{
		std::cout << "object is destroyed." << std::endl;
	}
	else
	{
		std::cout << "object is not destroyed." << std::endl;
		p3->Fun();
	}



	boost::shared_ptr<A> p4 = p.lock();
	if (NULL == p4)
	{
		std::cout << "object is destroyed." << std::endl;

	}
	else
	{
		p4->Fun();
	}


	boost::scoped_array<A> x(new A[3]); //自动释放



	return 0;
}

int TestScopedArray()
{

	int *a = new int[1000];


	for (int i = 0; i < 1000; i++)
	{
		a[i] = i;
	}
	//boost::scoped_array<int> sa(new int[1000]);
	boost::scoped_array<int> sa(a);

	int *b = new int[3423];
	boost::scoped_array<int> sa1(b);

	//sa = sa1; // Error

	for (int i = 0; i < 1000; i++)
	{
		std::cout << sa[i] << std::endl;
	}



	return 0;
}

int TestScopedPtr()
{
	boost::scoped_ptr<string> ps(new string("Hello World!"));
	std::cout << *ps << std::endl;
	std::cout << ps->size() << std::endl;


	boost::scoped_ptr<int> pi(new int);
	if (pi)
	{
		*pi = 989;
		std::cout << *pi << std::endl;
		pi.reset();
		if (NULL == pi)
		{
			std::cout << "pi is be destroyed." << std::endl;
		}
	}
	else
	{
		std::cout << "pi is null"<< std::endl;
	}


	return 0;
}


int main(void)
{
	//TestSmartPtr1();
	//TestSmartPtr2();
	//TestSmartPtr3();
	//TestWeakPtr1();
	//TestScopedArray();
	//TestScopedPtr();
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}

#endif