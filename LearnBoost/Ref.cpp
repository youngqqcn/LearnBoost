#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/11/19 14:09
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>


#include <boost/function.hpp>
#include <boost/ref.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;



void Print(std::ostream &os, int i)
{
	os << i << std::endl;
}

int main(void)
{
	boost::function<void(int)> fun;

	vector<int> vct;
	vct.push_back(11);
	vct.push_back(12);
	vct.push_back(13);
	vct.push_back(14);

	fun = boost::bind(Print, boost::ref(std::cout), _1);


	/*for_each(vct.begin(), vct.end(), [=](int a) {
		std::cout << a << std::endl;
	});*/

	for_each(vct.begin(), vct.end(), fun);
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif