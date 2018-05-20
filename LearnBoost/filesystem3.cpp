#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/19 12:24
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
#include <Windows.h>

#include <boost/filesystem.hpp>
#include <boost/progress.hpp>

namespace fs = boost::filesystem;

using namespace boost;
using namespace fs;
using namespace std;


typedef recursive_directory_iterator rd_iterator;
vector<path> find_files(path p, const string& fileName)
{
	vector<path> result;
	result.clear();
	for (rd_iterator pos(p); pos != rd_iterator(); ++pos)
	{
		//�����Ŀ¼, ���ٵݹ�(���)����
		/*if (is_directory(*pos))
		{
		pos.no_push();
		}*/

		//���ӡ��Ŀ¼��
		//std::cout/* << pos.level() << ":"*/ << *pos << std::endl;

		string tmpName = (*pos).path().string();
		if (tmpName.find(fileName) != string::npos)
		{
			result.push_back((*pos).path());
			//std::cout << *pos << std::endl;
		}
	}
	return result;
}


int copy_files(const path& from_dir, const path& to_dir, const string& filename = ".cpp")
{
	if (!is_directory(from_dir))
	{
		std::cout << "from_dir is not a dir." << std::endl;
		return 0;
	}

	if (!exists(to_dir))
	{
		if (create_directories(to_dir)) //����Ŀ¼
		{
			std::cout << "create" << to_dir.string() << "success" << std::endl;
		}
	}
	
	if (!is_directory(to_dir))
	{
		std::cout << "to_dir is not a dir." << std::endl;
		return 0;
	}

	std::cout << "prepare for copy, please wait ...." << std::endl;

	auto v = find_files(from_dir, filename);  //����from_dir Ŀ¼�������ļ�(����Ŀ¼) 
	
	/*for (auto p : v)
	{
		std::cout << p.string() << std::endl;

	}
	return 0;*/
	
	if (v.empty())
	{
		std::cout << "0 file copied" << std::endl;
		return 0;
	}

	std::cout << "now begin copy files..." << std::endl;

	progress_display pd(v.size());  //������ʾ������

	for (auto &p : v)
	{
		string fileName = p.string().substr(from_dir.string().length());
		path tmp = to_dir / fileName;   //��Ȼ�������
		//std::cout << tmp.string() << std::endl;
		//std::cout << fileName << std::endl;

		if (!exists(tmp.parent_path()))
		{
			create_directories(tmp.parent_path()); //�ݹ鴴����Ŀ¼
		}
		try
		{
			if (exists(tmp))
				remove_all(tmp);
			copy_file(p, tmp); //�����ļ�
		}
		catch (const filesystem_error & e)
		{
			std::cout << e.what() << std::endl;
			return 0;
		}
		++pd; //���½�����
	}
	std::cout << v.size() << "file copied" << std::endl;
	return v.size();
}




int main(void)
{
	fs::path test = "C:\\Users\\yqq\\Documents\\Visual Studio 2015\\Projects\\LearnBoost\\LearnBoost";
	fs::path test2;

	//ʹ��append���Զ��� '\'
	test2 = path(test).remove_filename().append( "testdir");
	//std::cout << test2.string() << std::endl;
	//copy_file(test, test2);
	
	//std::cout << test.string() << std::endl;
	std::cout << test2.string() << std::endl;


	copy_files(test, test2, ".cpp"); //ֻ���� .cpp �ļ� 





	

	//std::cout << "hello world" << std::endl;
	::system("pause");
	return 0;
}
#endif