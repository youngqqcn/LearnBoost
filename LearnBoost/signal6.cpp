#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/20 11:19
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
#include <algorithm>
#include <regex>
#include <codecvt>
#include <numeric>
//#include <functional>
//using namespace std::placeholders;
//using namespace std;


#include <boost/signals2.hpp>
using namespace boost::signals2;

template<int N>
struct slots
{
	void operator()()
	{
		std::cout << "slot " << N  << " called" << std::endl;
	}
};

int main(void)
{
	signal<void()> sig;

	connection c1 =  sig.connect(0, slots<10>());
	connection c2 =  sig.connect(0, slots<20>());
	auto c3 = sig.connect(1, slots<30>());
	std::cout << "-----------------" << std::endl;
	sig();
	c1.disconnect();

	sig();

	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif