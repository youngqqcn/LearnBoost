#if 0
// exmaple6.cpp
#include <iostream>
#include <string>
#include <vector>

//#include <boost/program_options>
#include "boost/program_options.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
#if 1
	using namespace boost::program_options;
	options_description desc("Command line options");
	// ��������ѡ��: (ѡ��ȫ�ƣ���д)�� (��������->Ĭ��ֵ)��(����)
	desc.add_options()
		("help,h", "print help message")
		("person,p", value<string>()->default_value("world"), "person name")
		("file,f", value< vector<string> >(), "input file name");

	variables_map vm;  // �洢����Ĳ���
	store(parse_command_line(argc, argv, desc), vm);  // ��������ѡ���������
	notify(vm);

	if (vm.count("help")) {
		cout << desc << endl;
		return 0;
	}
	cout << "Hello " << vm["person"].as<string>() << endl;

	if (vm.count("file")) {
		vector<string> files(vm["file"].as< vector<string> >());
		cout << "Got " << files.size() << " files." << endl;
	}
#endif

	return 0;
}
#endif