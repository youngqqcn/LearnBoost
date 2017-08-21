#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/08/20 10:59
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <random>
#include <time.h>

#include <boost/array.hpp>
#include <algorithm>

using namespace std;


int TestArray1()
{


	boost::array<int, 4> a = { 1, 2, 3 };


	for_each(a.begin(), a.end(), [=](auto aObject) {

		std::cout << aObject << std::endl;

	});

	return 0;
}

int TestArray2()
{

	boost::array<int, 100> a;

	srand((unsigned int)time(0));

#if 1
	//why this sentence is invalid??
	//since the type of argument be captured  is "int", not "int &".
	//for_each(a.begin(), a.end(), [&](auto aObject)mutable {


	//This is ok, do not use auto in argument list.
	for_each(a.begin(), a.end(), [&](int &aObject)mutable {
		aObject = rand() % 100;
	});



#endif

#if 0
	//Of course! This is  Ok!
	for (auto it = a.begin(); it != a.end(); it++)
	{
		*it = rand() % 100;
	}
#endif


	for (auto it = a.begin(); it != a.end(); it++) 
	{
		std::cout << *it << std::endl;
	}


	return 0;
}



int main(void)
{
	

	//TestArray1();
	TestArray2();



	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif