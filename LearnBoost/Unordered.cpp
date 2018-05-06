#if 0
#include <iostream>
#include<boost/unordered_set.hpp>
#include<string>


using namespace std;

void main()
{
	boost::unordered_set<std::string> myhashset;
	myhashset.insert("ABC");
	myhashset.insert("ABCA");
	myhashset.insert("ABCAG");


	for (auto ib = myhashset.begin(); ib != myhashset.end();ib++)
	{
		cout << *ib << endl;
	}
	std::cout << (myhashset.find("ABCA1") != myhashset.end()) << endl;

	cin.get();

}
#endif