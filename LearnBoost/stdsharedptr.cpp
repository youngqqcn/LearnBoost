#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/05 16:12
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

using namespace std;

void foo1()
{
	typedef std::shared_ptr<std::string> SStr;
	typedef std::list<SStr> LS;

	SStr str1(new string("hello1"));
	SStr str2(new string("hello2"));
	SStr str3(new string("hello3"));

	LS ls;

	ls.push_back(str1);
	ls.push_back(str2);
	ls.push_back(str3);


	for (auto it = ls.begin(); it != ls.end(); it++)
	{
		std::cout << *(*it) << std::endl;
	}
}


void foo2()
{
	typedef std::shared_ptr<std::list<std::string> >  SL;
	typedef std::list<SL> SSL;

	SSL llStr;

	for (int j = 0; j < 10; j++)
	{
		SL	lstr;
		list<std::string> *tmpL = new list<std::string>(100);
		for (int i = 0; i < 10; i++)
		{
			char buf[100] = { 0 };
			memset(buf, 0, sizeof(buf));
			sprintf(buf, "hello %d", i);
			tmpL->push_back(string(buf));
		}
		lstr.reset(tmpL);
		llStr.push_back(lstr);
	}

	for (auto it = llStr.begin(); it != llStr.end() ; it++)
	{
		auto tmpPTR = *it;
		auto tmpList = *tmpPTR;
		for (auto it2 = tmpList.begin(); it2 != tmpList.end(); it2++)
		{
			std::cout << *it2 << std::endl;
		}
	}

}


class MySocket
{
public:
	MySocket()
	{
		std::cout << "创建Socket" << std::endl;
	}

	~MySocket()
	{

	}

	void Open()
	{
		std::cout << "打卡Socket" << std::endl;
	}

	static void MySocket::Close(MySocket * sock);  //函数的参数必须是 MySocket*

};

//定义一个删除其
void MySocket::Close(MySocket * sock)  //函数的参数必须是 MySocket*
{
	std::cout << "关闭socket " << std::endl;
}

void foo3()
{
	MySocket sock;
	std::shared_ptr<MySocket> p(new MySocket(), MySocket::Close);
}

int main(void)
{
	foo2();
	//foo3();

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif