#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/11/18 18:21
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

#include <boost/scoped_array.hpp>
#include <boost/random.hpp>
#include <ctime>

using namespace boost;

using namespace std;



int main(void)
{

	int size = 1000;
	scoped_array<int> a(new int[size]);


	//rand48 r(std::time(0));
	//mt19937 r(std::time(0));  //随机数生成器
	lagged_fibonacci19937 r(std::time(0));
	for (int i = 0; i < size; i++)
	{
		a[i] = r() * 100000;
		cout << a[i] << endl;
	}
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif