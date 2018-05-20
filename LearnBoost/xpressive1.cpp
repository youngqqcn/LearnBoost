#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 11:45
*Author:yqq
*Descriptions:正则表达式
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

//#include <boost/regex.hpp>
#include <boost/xpressive/xpressive.hpp>

using namespace std;
using namespace boost::xpressive;

int main(void)
{

	{
		cregex reg = cregex::compile("a.c");
		std::cout << regex_match("abc", reg) << std::endl;

		std::cout << "================" << std::endl;
	}

	{
		string str("readme.txt.txt");

		sregex reg1 = sregex::compile("^re.*");
		sregex reg2 = sregex::compile(".*?txt");
		std::cout << regex_match(str, reg1) << std::endl;
		std::cout << regex_match(str, reg2) << std::endl;
		std::cout << "================" << std::endl;
	}

	{
		string str("readme.txt.txt");
		sregex reg2 = sregex::compile(".+?txt");  //非贪婪模式
		boost::xpressive::sregex_iterator pos(str.begin(), str.end(), reg2);
		decltype(pos) end;

		for (; pos != end; pos++)
		{
			std::cout << (*pos)[0] << std::endl;
		}
	}

	{
		string str = "*Link*||+Mario+||Zelda!!!||Metroid";
		sregex reg = sregex::compile("\\w+", boost::xpressive::icase);
		boost::xpressive::sregex_token_iterator pos(str.begin(), str.end(), reg);

		for (; pos != boost::xpressive::sregex_token_iterator(); pos++)
		{
			std::cout << "[" << *pos << "]"  ;
		}
		std::cout << std::endl;

	}


	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif