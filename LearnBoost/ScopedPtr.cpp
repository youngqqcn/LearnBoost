#if 0
#define _CRT_SECURE_NO_WARNINGS  


/**
*Date: 2017/11/18 17:50
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

#include <boost/scoped_ptr.hpp>

using namespace std;
using namespace boost;

int main(void)
{
	
	scoped_ptr<int> p(new int);

	*p = 15;

	cout << *p.get() << endl;
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif