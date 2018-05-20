#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 10:43
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

#include <boost/utility/string_ref.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/assign.hpp>

using namespace boost;
using namespace std;

int main(void)
{

	string str1("readme.pdf");

	if (ends_with(str1, "pdf"))
	{
		std::cout << to_upper_copy(str1) << std::endl;
		std::cout << str1 << std::endl;
		to_upper(str1);
		std::cout << str1 << std::endl;
	}

	std::cout << ireplace_first_copy(str1, "rEaDme", "followme") << std::endl;
	std::cout << ierase_first_copy(str1, "FolLowme") << std::endl;
	std::cout << str1 << std::endl;

	ierase_first(str1, "reAdMe");
	std::cout << "删除readme之后: " << str1 << std::endl;

	std::cout << "========================" << std::endl;


	//容器的元素类型必须是  string 或者iterator_range<string::iterator> 
	//list<iterator_range<string::iterator>> lst;
	list<string> lst;
	string str2("helll;world; you; happy; lalal; tom; cat; dog; df;");
	split(lst, str2, is_any_of(";"));

	for (auto x : lst)
	{
		std::cout << x << std::endl;
	}



	std::cout << "========================" << std::endl;

	//容器可以是 vector list  deque
	//list<string> dq;
	//deque<string> dq;
	vector<string> dq;
	ifind_all(dq, str2, "la");
	for (auto x : dq)
	{
		std::cout << x << std::endl;
	}

	std::cout << "========================" << std::endl;

	string str3 = "samus,link.Zelda::Mario-Luigi+zelda";
	list<string> lst3;

	// token_compress_on : 当出现两个连续的 分隔符时, 将视为一个
	boost::split(lst3, str3, is_any_of(",.:-+"), boost::token_compress_on);
	for (auto x : lst3)
	{
		std::cout << x << std::endl;
	}

	std::cout << "========================" << std::endl;
	list<string> lst4 = boost::assign::list_of("Samus")("Link")("Zelda")("Mario");

	std::cout << join(lst4, "+") << std::endl;
	std::cout << join_if(lst4, "**", 
		[](string_ref s) {
		//[&](const  string & s) {
		return contains(s, "a");  //判断字符串是否包含  "a"
	}) << std::endl;

	
	std::cout << "========================" << std::endl;

	string str5("Samux||samus||mario||||Link");

	//查找迭代器
	{
		typedef find_iterator<string::iterator> string_find_iterator;
		string_find_iterator pos, end;

		for (pos = make_find_iterator(str5, first_finder("samus", is_equal())); pos != end; pos++) {
			std::cout << *pos << std::endl;
		}



		std::cout << "========================" << std::endl;
	}

	//分割迭代器

	{
		typedef split_iterator<string::iterator> string_split_iterator;
		string_split_iterator pos, end;

		for ( pos = make_split_iterator(str5, first_finder("||", is_equal()))
			;pos != end
			;pos++)
		{
			std::cout << "[" << *pos << "]" << std::endl;
		}

	}

	std::cout << "========================" << std::endl;
	//使用自动推到类型
	{
		auto pos = make_find_iterator(str5, first_finder("samus", is_equal()));
		decltype(pos) end;  //通过pos, 自动推导出 end 的类型
		for (; pos != end; ++pos)
		{
			std::cout << "[" << *pos << "];" << endl;
		}
	}


	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif