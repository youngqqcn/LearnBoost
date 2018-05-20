#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 15:24
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <memory>
#include <regex>
#include <codecvt>
#include <algorithm>
//#include <boost/algorithm/algorithm.hpp>

//using namespace boost;
using namespace std;

struct square
{
	void operator()(int &x) {
		x = x * x;
	}
};

int main(void)
{
	typedef double(*pfunc)(double);
	pfunc pf = sqrt;
	std::cout << std::ref(pf)(4.3) << std::endl;

	square sq;
	int x = 4;
	std::ref(sq)(x);
	std::cout << x << std::endl;

	vector<int> v = { 1, 2, 3, 4, 5 };

	/*for_each(v.begin(), v.end(), [&](int x) {
		std::cout << x * x << " ";
	});
	std::cout << std::endl;*/


	//将 v 中的每个元素都 进行平方
	for_each(v.begin(), v.end(), std::ref(sq)  ); 

	//输出平方后的值
	for (auto xx : v)
	{
		std::cout << xx << " ";// << std::endl;
	}
	std::cout << std::endl;
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif