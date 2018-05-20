#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 16:30
*Author:yqq
*Descriptions: 绑定成员变量
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
#include <functional>
using namespace std::placeholders;
using namespace std;

struct point
{
	int x, y;
	point(int a = 0, int b = 0) :x(a), y(b) {};
	void print()
	{
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
};

int main(void)
{
	vector<point> v(10);
	vector<int> v2(10);

	//std::transform函数是将某操作应用于指定范围的每个元素
	//遍历v.begin() 到 v.end() 范围内的每个元素, 进行bind的操作, 然后填入 v2中
	transform(v.begin(), v.end(), v2.begin(), bind(&point::x, _1));
	for (auto x : v2)
	{
		std::cout << x << std::endl;
	}
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif