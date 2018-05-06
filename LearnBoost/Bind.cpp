#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/11/19 10:43
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

#include <boost/bind.hpp>
#include <functional>

using namespace std;
using namespace boost;



void add(int a, int b)
{
	cout << a + b << endl;
}

int main(void)
{
	vector<int> arr;
	arr.push_back(100);
	arr.push_back(11);
	arr.push_back(55);

	//for_each(arr.begin(), arr.end(), bind1st(add(), 10));


	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif