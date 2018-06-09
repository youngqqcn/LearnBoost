#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/06/02 14:47
*Author:yqq
*Descriptions: std::regex 使用
摘自: https://www.cnblogs.com/szn409/p/7471427.html
*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(void)
{

	//8.regex_match使用示例
	regex re0("[0-9]+");
	regex re1("[0-9a-z]+");
	string str("abc123");
	bool nRe0 = regex_match(str, re0);  //nRe0 = false
	bool nRe1 = regex_match(str, re1);  //nRe1 = true

	std::cout << nRe0 << std::endl;
	std::cout << nRe1 << std::endl;

	//regex_match 必须匹配被分析串的全部，若不匹配返回 false ，否则返回 true                   //str = "ABCabc"

	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif