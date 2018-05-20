#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/20 11:04
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
		std::cout << "slot " << N << " called" << std::endl;
	}
};


int main(void)
{
	signal<void()> sig;
	sig.connect(slots<1>(), at_back);// δ������Ĳ�۱�־��at_back, �����еı���֮�����
	sig.connect(slots<100>(), at_front); // δ������Ĳ����at_front, �����еı���֮�����

	sig();

	std::cout << "-------------------" << std::endl;

	sig.connect(5, slots<43>(), at_back);
	sig.connect(5, slots<55>(), at_front);

	sig();
	std::cout << "-------------------" << std::endl;


	std::cout << sig.num_slots() << std::endl;

	sig.disconnect_all_slots();
	std::cout << sig.num_slots() << std::endl;

	sig(); //�Ѿ�û�вۺ���

	{
		//�ֲ�������
		scoped_connection sc = sig.connect(0, slots<10>());
		sig();
		//std::cout << *sig() <<std::endl;
	}
	sig();


	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif