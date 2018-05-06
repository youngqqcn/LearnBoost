#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/06 11:25
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

//#include <boost/weak_ptr.hpp>

using namespace std;
//using namespace boost;

int main(void)
{

	std::shared_ptr<string> sharedPtr(new string("hello"));
	std::weak_ptr<string> weakPtr(sharedPtr);


	auto sharePtr2 = sharedPtr;
	auto sharePtr3 = sharePtr2;
	auto sharePtr4 = sharePtr3;

	std::cout << weakPtr.use_count() << std::endl; //4

	if (!weakPtr.expired()) //���shared_ptrû��ʧЧ
	{
		*(weakPtr.lock()) = "�㷢�͵����͵�";
		std::cout << *sharedPtr << std::endl;
	}

	//�ֶ��ͷ�
	sharePtr2.~shared_ptr();
	sharePtr3.~shared_ptr();
	sharePtr4.~shared_ptr();

	std::cout << "�ֶ��ͷ�֮������ü���: " << weakPtr.use_count() << std::endl; //4

	sharedPtr.~shared_ptr();  //�ͷ�
	std::cout << "�ֶ��ͷ�shreadPtr������ü���: " << weakPtr.use_count() << std::endl; //4

	if (weakPtr.expired())
	{
		std::cout << "�Ѿ�ʧЧ" << std::endl;
	}

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif