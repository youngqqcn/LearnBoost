//#if 0
//// example4.cpp
//#include <iostream>
//#include "boost/chrono.hpp"
//using namespace std;
//
//// durations ��ʾһ��ʱ����
//typedef boost::chrono::hours hours;
//typedef boost::chrono::minutes minutes;
//typedef boost::chrono::seconds seconds;
//typedef boost::chrono::milliseconds milliseconds;
//typedef boost::chrono::microseconds microseconds;
//typedef boost::chrono::nanoseconds nanoseconds;
//
//// clock ��ʾ��ǰʱ�䣬���ڲ��ϵı仯
//typedef boost::chrono::system_clock system_clock;
//typedef boost::chrono::steady_clock steady_clock;
//typedef boost::chrono::high_resolution_clock high_resolution_clock;
//
//// time point ��ʾĳһ�������ʱ���
//typedef system_clock::time_point sys_tp;
//
//int main() 
//{
//	hours h1(1);
//	minutes m1(1);
//	minutes m2 = h1 + m1; //  ֻ��ת��Ϊ��С�ĵ�λ
//	cout << m2 << endl; // 61 minutes
//
//	hours h2 = boost::chrono::duration_cast<hours>(h1 + m1); //ǿ��ת��
//	cout << h2 << endl; // 1 hour
//
//	cout << system_clock::now() << endl;
//	
//
//	std::cin.get();
//	return 0;
//}
//#endif