#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 12:00
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


namespace fs = boost::filesystem;
using namespace fs;
using namespace std;

//�ݹ����Ŀ¼�����е��ļ�
void MyWalkDir(path p)
{
	if (exists(p))
	{
		for (fs::directory_iterator dirIt(p); dirIt != directory_iterator(); ++dirIt)
		{
			path tmpPath = (*dirIt).path();
			
			if (is_directory(tmpPath))
			{
				MyWalkDir(tmpPath);
			}
			else
			{
				std::cout << tmpPath.string() << std::endl;
			}

		}
	}
}

typedef fs::recursive_directory_iterator rd_iterator; //�ݹ������


void MyWalkDir2(path p)
{
	for (rd_iterator pos(p); pos != rd_iterator(); ++pos)
	{
		//�����Ŀ¼, ���ٵݹ�(���)����
		/*if (is_directory(*pos))
		{
			pos.no_push();
		}*/

		//���ӡ��Ŀ¼��
		std::cout/* << pos.level() << ":"*/ << *pos << std::endl;
	}
}


int main(void)
{
	fs::path test = "C:\\Users\\yqq\\Documents\\Visual Studio 2015\\Projects\\LearnBoost";
	//MyWalkDir(test);
	MyWalkDir2(test);
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif