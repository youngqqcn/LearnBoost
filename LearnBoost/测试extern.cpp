#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/20 15:50
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
#include <iostream>

using namespace std;

template < char const *name >
struct A
{
	A(){std::cout << name << std::endl;};
};

//char const p[] = "fsdfsdfsdf";   //error  涉及带有内部链接的对象的表达式不能用作非类型参数
extern char const p[] = "fsdfsdfsdf"; //ok
//extern char * const p = "sdfsdfdsf"; //error  模板参数无效，应为编译时常量表达式 	


int main()
{
	A<p> a;
	
	system("pause");
	return 0;
}

#endif