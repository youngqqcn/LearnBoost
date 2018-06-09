#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 15:02
*Author:yqq
*Descriptions:none
*/

#include <iostream>
//#include <string>
//#include <map>
//#include <list>
//#include <vector>
//#include <deque>
//#include <memory>
//#include <regex>
//#include <codecvt>

#include <tuple>

using namespace std;

int main(void)
{

	auto tp1 = make_tuple("1", 2, 3.3);

	//tp1._Myfirst = 99;
	tp1.
	std::cout << get<1>(tp1) << std::endl;
	
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif