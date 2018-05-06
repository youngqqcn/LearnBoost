#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/05 10:34
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


//自己写一个智能指针
template <typename T>
class MyAutoPtr
{
public:

	MyAutoPtr(T * p) : m_ptr(NULL)
	{
		if (!p) m_ptr = NULL;
		else m_ptr = p;
	};

	//MyAutoPtr(T[] p) : m_ptr(NULL)
	//{
	//	m_pArr = p;
	//}

	~MyAutoPtr()
	{
		//std::cout << "自动释放了内存" << std::endl;
		if (m_ptr)
		{
			std::cout << "自动释放了内存" << std::endl;
			//delete m_ptr;
			delete []m_ptr;
			m_ptr = NULL;
		}
		/*else if (m_pArr)
		{
			delete[] m_pArr;
		};*/
	};

	MyAutoPtr& operator = (const MyAutoPtr& other)
	{
		this->m_ptr = other.m_ptr;
		other.m_ptr = NULL;  //防止两个指针指向同一块内存, 重复释放
		delete other; //但是又会导致other不能再使用
		return *this;
	}

	T* get() 
	{ 
		return m_ptr; 
	}

public:
	T *m_ptr;
	//T[] m_pArr;

};


void foo()
{
	//std::auto_ptr<int> p (new int[100]);
	MyAutoPtr<int> p(new int[100]);

	int *pTmp = p.get();
	for (int i = 0; i < 100; i++)
	{
		*(pTmp + i) = i;
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << "pTmp[" << i << "]=" << pTmp[i] << std::endl;
	}
	//p.~MyAutoPtr();

	//std::cout << "hello world" << std::endl;
}

int main(void)
{
	foo();
	system("pause");
	return 0;
}
#endif