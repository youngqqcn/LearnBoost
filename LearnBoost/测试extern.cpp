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

//char const p[] = "fsdfsdfsdf";   //error  �漰�����ڲ����ӵĶ���ı��ʽ�������������Ͳ���
extern char const p[] = "fsdfsdfsdf"; //ok
//extern char * const p = "sdfsdfdsf"; //error  ģ�������Ч��ӦΪ����ʱ�������ʽ 	


int main()
{
	A<p> a;
	
	system("pause");
	return 0;
}

#endif