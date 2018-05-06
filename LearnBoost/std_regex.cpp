#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 15:51
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
#include <regex>  //C++11

using namespace std;

void foo()
{
	if (std::regex_match("subject", std::regex("(sub)(.*)")))
		std::cout << "string literal matched\n";

}

void foo2()
{
	std::string s("this subject has a submarine as a subsequence");
	std::smatch m;
	std::regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"  

	std::cout << "Target sequence: " << s << std::endl;
	std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
	std::cout << "The following matches and submatches were found:" << std::endl;

	while (std::regex_search(s, m, e)) {
		for (auto x = m.begin();x != m.end();x++)
			std::cout << x->str() << " ";
		std::cout << "--> ([^ ]*) match " << m.format("$2") << std::endl;
		s = m.suffix().str();
	}
}

void foo3()
{
	char buf[20];
	const char *first = "axayaz";
	const char *last = first + strlen(first);
	std::regex rx("a");
	std::string fmt("A");
	std::regex_constants::match_flag_type fonly =
		std::regex_constants::format_first_only;

	*std::regex_replace(&buf[0], first, last, rx, fmt) = '\0';
	std::cout << &buf[0] << std::endl;

	*std::regex_replace(&buf[0], first, last, rx, fmt, fonly) = '\0';
	std::cout << &buf[0] << std::endl;

	std::string str("adaeaf");
	std::cout << std::regex_replace(str, rx, fmt) << std::endl;

	std::cout << std::regex_replace(str, rx, fmt, fonly) << std::endl;

	return ;
}




int main(void)
{
	foo();
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif