#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/20 10:23
*Author:yqq
*Descriptions: ·µ»ØÖµ
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


#include <boost/signals2.hpp>
using namespace boost::signals2;


template<int N>
struct slots
{
	int  operator()(int x)
	{
		std::cout << "slot " << N << " called" << std::endl;
		return x * N;
	}
};


int main(void)
{
	signal<int(int)> sig;
	sig.connect(slots<10>());
	sig.connect(slots<20>());
	sig.connect(slots<50>());

	std::cout << *sig(2) << std::endl;

	system("pause");
	return 0;
}
#endif