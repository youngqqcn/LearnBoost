//#if 0
//// example4.cpp
//#include <iostream>
//#include "boost/chrono.hpp"
//using namespace std;
//
//// durations 表示一段时间间隔
//typedef boost::chrono::hours hours;
//typedef boost::chrono::minutes minutes;
//typedef boost::chrono::seconds seconds;
//typedef boost::chrono::milliseconds milliseconds;
//typedef boost::chrono::microseconds microseconds;
//typedef boost::chrono::nanoseconds nanoseconds;
//
//// clock 表示当前时间，是在不断的变化
//typedef boost::chrono::system_clock system_clock;
//typedef boost::chrono::steady_clock steady_clock;
//typedef boost::chrono::high_resolution_clock high_resolution_clock;
//
//// time point 表示某一个具体的时间点
//typedef system_clock::time_point sys_tp;
//
//int main() 
//{
//	hours h1(1);
//	minutes m1(1);
//	minutes m2 = h1 + m1; //  只能转化为更小的单位
//	cout << m2 << endl; // 61 minutes
//
//	hours h2 = boost::chrono::duration_cast<hours>(h1 + m1); //强制转换
//	cout << h2 << endl; // 1 hour
//
//	cout << system_clock::now() << endl;
//	
//
//	std::cin.get();
//	return 0;
//}
//#endif