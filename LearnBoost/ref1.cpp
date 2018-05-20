#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 15:07
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

//#include <boost/ref.hpp>
//using namespace  boost;
using namespace std;

int main(void)
{

	int a = 100;

	reference_wrapper<int> rw(a);
	std::cout << &rw << std::endl; //一个单独变量  与 a 不同
	std::cout << &a<< std::endl;

	//std::cout << (rw == a) << std::endl;

	string str1 = "hello";

	string &str11 = str1;  // 只是 str1 的一个别名而已
	std::cout << &str11 << endl;
	std::cout << &str1 << endl;



	//std::cout << (str11 == str1) << std::endl;
	//std::cout << str11 << std::endl;

	//reference_wrapper<string> rs(str1);
	//std::cout << (rs.get().size()) << std::endl;

	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif