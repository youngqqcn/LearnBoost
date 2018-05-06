#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/05 15:42
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <memory>

#include <boost/make_unique.hpp>

using namespace std;

int main(void)
{
	//unique_ptr<std::string> pStr(new std::string("helll"));
	//std::cout << *pStr << std::endl;

	typedef std::list<std::unique_ptr<string>>  LU;

	LU listUPtr(100);

	for (auto pos = listUPtr.begin(); pos != listUPtr.end(); pos++)
	{
		(*pos) = make_unique<string>("hello");
		//std::cout << *(*pos) << std::endl;
	}

	//LU listUP2;
	std::list<std::unique_ptr<string>> listUP2;
	listUP2.push_back(make_unique<string>("hello"));
	listUP2.push_back(make_unique<string>("hello"));
	listUP2.push_back(make_unique<string>("hello"));
	listUP2.push_back(make_unique<string>("hello"));

	for (auto pos = listUP2.begin(); pos != listUP2.end(); pos++)
	{
		(*pos) = make_unique<string>("hello");
		std::cout << *(*pos) << std::endl;
	}
	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif