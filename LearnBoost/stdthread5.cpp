#if 0
#include <iostream>     
#include <chrono>      
#include <thread>  
#include <mutex>  
using namespace std;

timed_mutex my_mutex;

void my_task(int val, char tag) {
	//每200ms尝试获取锁,如果获取到跳出while循环，否则输出一次线程编号
	//比如0-200ms,在200ms之前如果获取不到锁，则线程阻塞，时间到了200ms如果取得了锁，
	//则加锁，否则返回false
	while (!my_mutex.try_lock_for(chrono::milliseconds(200))) {
		//int pid = this_thread::get_id().hash();
		cout << val;
	}
	//成功取得锁，然后将线程sleep到1000ms
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << tag << endl;
	my_mutex.unlock();
}

int main()
{
	thread threads[10];
	char end_tag[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' };
	//创建10个线程，分别执行my_task()中的代码
	for (int i = 0; i < 10; ++i) {
		threads[i] = thread(my_task, i, end_tag[i]);
	}

	for (auto& it : threads) {
		it.join();
	}
	system("pause");
	return 0;
}
#endif