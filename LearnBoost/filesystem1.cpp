#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 16:11
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

#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

int main(void)
{

	path p("C:\\Users\\yqq\\Documents\\Visual Studio 2015\\Projects\\LearnBoost\\test.txt");

	std::cout << p.string() << std::endl;

	std::cout << p.filename() << std::endl;

	std::cout << p.extension() << std::endl;
	std::cout << p.root_directory() << std::endl;
	std::cout << p.root_path() << std::endl;
	std::cout << p.has_filename() << std::endl;

	//file_status fs()
	if (status(p.string()).type() == character_file)
	{
		std::cout << "character_file" << std::endl;
	}
	else if (status(p.string()).type() == regular_file)
	{
		std::cout << "regular_file" << std::endl;
	}
	else
	{
	}

	std::cout <<"�ļ���С: " << file_size(p) << std::endl;


	//����Ŀ¼���ļ�
	
	namespace fs = boost::filesystem;
	path p2("C:\\Users\\yqq\\Documents\\Visual Studio 2015\\Projects\\LearnBoost\\test");

	//���Ŀ¼������ �򴴽�
	if (false == fs::exists(p2))
	{
		if (!create_directory(p2))
		{
			std::cout << "����Ŀ¼ʧ��" << std::endl;
		}

	}

	try
	{
		//����ı���ļ�������(����ʱ�� �޸�ʱ���)
		copy_file(p, path(p2.string() + "\\test.txt"));

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;

	if(fs::exists(p2) && fs::is_directory(p2))
	{
		//std::cout << "�Ƿǿ�Ŀ¼" << std::endl;
		if (fs::is_empty(p2))
		{
			remove(p2); //ɾ���ļ�
			std::cout << "��ͨɾ���ɹ�" << std::endl;
		}
		else
		{
			remove_all(p2); //���Եݹ�ɾ��
			std::cout << "�ݹ�ɾ���ɹ�" << std::endl;
		}
	}
	else
	{
		std::cout << "Ŀ¼������" << std::endl;
	}



	//std::cout << "hello world" << std::endl;

	::system("pause");
	return 0;
}
#endif