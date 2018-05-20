#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 16:30
*Author:yqq
*Descriptions: �󶨳�Ա����
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

	//std::transform�����ǽ�ĳ����Ӧ����ָ����Χ��ÿ��Ԫ��
	//����v.begin() �� v.end() ��Χ�ڵ�ÿ��Ԫ��, ����bind�Ĳ���, Ȼ������ v2��
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