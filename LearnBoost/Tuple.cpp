#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/04/05 18:15
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>


#include "boost/tuple/tuple_io.hpp"



using namespace std;

int main(void)
{
	auto t = std::make_tuple("yqq", 23, 5.5, 66.6, "hunan");

	std::cout << std::get<0>(t) << std::endl;
	std::cout << std::get<1>(t) << std::endl;
	std::cout << std::get<2>(t) << std::endl;
	std::cout << std::get<3>(t) << std::endl;
	std::cout << std::get<4>(t) << std::endl;



	//使用 boost中的tuple
	std::cout << boost::make_tuple("yqq", 23, 333232) << std::endl;
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif