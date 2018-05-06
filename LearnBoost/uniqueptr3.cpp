#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 11:13
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

int main(void)
{
	typedef list<string>  LS;
	std::unique_ptr<LS> p(new LS(100));

	LS *pLs = p.get();
	for (int i = 0; i < 100; i++)
	{
		pLs->push_back("hello");
	}

	for (auto it = pLs->begin(); it != pLs->end(); it++)
	{
		std::cout << *it << std::endl;
	}

	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif