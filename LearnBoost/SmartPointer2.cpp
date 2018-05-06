#if 0
#define _CRT_SECURE_NO_WARNINGS  


/**
*Date: 2017/11/18 17:29
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

//#include <boost/smart_ptr/allocate_shared_array.hpp>
//#include <boost/smart_ptr.hpp>
#include <boost/scoped_ptr.hpp>  //◊˜”√”Ú÷∏’Î

using namespace std;
using namespace boost;

int main(void)
{
	scoped_ptr<int> sp(new int);

	*sp = 112;

	cout << *sp.get() << endl;


	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif