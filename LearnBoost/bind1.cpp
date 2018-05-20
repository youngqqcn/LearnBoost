#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 16:04
*Author:yqq
*Descriptions:绑定普通函数
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <memory>
#include <algorithm>
#include <regex>
#include <codecvt>

#include <functional>   //bind


using namespace std;
using namespace std::placeholders;  // _1 , _2 ...这东西

int f(int a, int b) { return a + b; }
int g(int a, int b, int c) { return a + b * c; }



int main(void)
{
	std::cout << std::bind(f, 1, 2)() << std::endl;
	std::cout << std::bind(g, 1, 2, 3)() << std::endl;

	int x2, x3;
	auto ff = std::bind(g, 100, std::ref(x2), std::ref(x3));

	for (int i = 0; i < 10; i++ )
	{
		x2 = i;
		x3 = i;
		std::cout << ff() << std::endl; //调用函数
	}

	std::cout << "---------------" << std::endl;

	auto fx = std::bind(g, _1, _2, 99);
	
	std::cout << fx(9, 3, 7) << std::endl;  // 7 没有用

	std::cout <<9 + 3 * 99 << std::endl;
	std::cout <<9 + 3 * 7 << std::endl;
	



	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif