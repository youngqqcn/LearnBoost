#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/11/18 20:37
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/random.hpp>
#include <ctime>
#include <cstdlib>
using namespace std;


class Demo
{
public:
	Demo(string str):m_str(str) { std::cout << "¹¹Ôì" << std::endl; };
	~Demo() { std::cout << "Îö¹¹" << std::endl; };

	void Print() { std::cout << "hahah" << std::endl; };

	string m_str;

protected:
	
private:
};

int main(void)
{
	boost::shared_ptr<Demo> sp(new Demo("yqq"));
	sp->Print();
	boost::shared_ptr<Demo> sp2(sp);
	sp2->Print();

	system("pause");


	return 0;
}





/*
int main(void)
{
	//std::shared_ptr<int> sp(new int(111));
	//boost::shared_ptr<int> sp(new int(1111));
	//cout << *sp.get() << endl;

	int size = 10000;
	boost::shared_array<int> sa(new int[size]);
	//boost::shared_array<int> sb(new int[10]);

	boost::mt19937 rdg(time(0));


	for (int i = 0; i < size; i++)
	{
		sa[i] = rdg();
		//std::cout << sa[i] << std::endl;
	}

	//sa.reset(sb, sb.get());

	for (int i = 0; i < 10; i++)
	{
		std::cout << sa[i] << std::endl;
	}


	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
*/
#endif
