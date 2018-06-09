#if 0
#include <iostream>       
#include <thread>        
#include <mutex>         
using namespace std;

mutex my_mutex;

void print(int x) {
	cout << "value is " << x;
	cout << endl;
	this_thread::sleep_for(chrono::milliseconds(200));
}

void my_task(int id) {
	// lock_guard创建局部变量my_lock，会在lock_guard的构造方法中对my_mutex加锁
	lock_guard<mutex> my_lock(my_mutex);
	//由于自解锁的作用，下面的代码相当于临界区，执行过程不会被打断
	print(id);
	//运行结束时会析构my_lock，然后在析构函数中对my_mutex解锁
}

int main()
{
	thread threads[10];

	for (int i = 0; i < 10; ++i) {
		threads[i] = thread(my_task, i + 1);
	}

	for (auto& th : threads) {
		th.join();
	}

	system("pause");
	return 0;
}
#endif