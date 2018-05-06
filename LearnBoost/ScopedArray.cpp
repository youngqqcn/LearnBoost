#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2017/11/18 17:53
*Author:yqq
*Descriptions:none
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>


#include <ctime>
#include <cstdlib>

#include <boost/scoped_array.hpp>
using namespace boost;

using namespace std;





int main(void)
{
	int size = 1000;

	scoped_array<int> pArr(new int[size]); //»ñÈ¡ÄÚ´æ

	std::srand(std::time(0));
	for (int i =0; i < size; i++)
	{
		//cout << sizeof(pArr.get()) << endl;
		//cout << sizeof(pArr) << endl;
		pArr[i] = rand();
		printf("%d\n", pArr[i]);
	}
	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif