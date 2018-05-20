#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/12 15:43
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

using namespace std;

#include <boost/multi_array.hpp>
using namespace boost;

int main(void)
{
	multi_array<int, 3> m3(extents[2][3][4]); //ศýฮฌสýื้

	for (int x = 0 ; x < 2; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int z = 0; z < 4; z++)
			{
				m3[x][y][z] = x + y + z;
				std::cout << m3[x][y][z] << " ";
			}
			std::cout << endl;
		}
		std::cout << endl;
	}



	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif