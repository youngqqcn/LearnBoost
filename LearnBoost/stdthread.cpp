#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/06/09 13:28
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <memory>
#include <algorithm>
#include <regex>
#include <codecvt>
#include <numeric>

#include <thread>
using namespace std;

void Hello()
{
	while(1)
		std::cout << "hello " << std::endl;
}

void World()
{
	while(1)
		std::cout << "world" << std::endl;
}



int main(void)
{
	std::thread t1(Hello);
	std::thread t2(World);
	t1.join();
	t2.join();


	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif