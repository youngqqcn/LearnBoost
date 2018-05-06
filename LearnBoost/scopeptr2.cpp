#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 10:30
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

#include <boost/scoped_ptr.hpp>

using namespace std;

int main(void)
{
	boost::scoped_ptr<string> p1(new string("hello"));
	std::list<boost::scoped_ptr<std::string>> lst;
	lst.push_back(p1);
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif