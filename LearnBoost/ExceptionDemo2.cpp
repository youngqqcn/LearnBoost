#if 0
#if 1
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/04/06 12:15
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

using namespace std;


struct MyException : public std::exception
{
	//const throw() ���Ǻ���������������쳣���˵����
	//��ʾ what ���������׳��쳣�����ͣ�����˵���ŵ� () �
	//������û�����ͣ�������������������׳��쳣��
	//ͨ��������д����ľͱ�ʾ���������׳��κ����͵��쳣��
	const char *what() const throw()
	{
		return "this is a self-definition exception.";
	}

};


double foo(int a, int b)
{
	if(0 == b)
	{
		//throw "divisor is zero, please check arguments.";
		throw MyException();
	}
	else
	{
		return a / b;
	}
}




int main(void)
{
	try
	{
		foo(5, 0);
	}
	//catch (const char *msg)
	catch(MyException &e)
	{
		//cerr << msg << endl;
		//std::cerr << e.what() << endl;
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}
#endif

#endif