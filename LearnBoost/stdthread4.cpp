#if 0
#include <iostream>      
#include <thread>      
#include <mutex>  
using namespace std;

/**
就像大家更熟悉的const一样，volatile是一个类型修饰符（type specifier）。
它是被设计用来修饰被不同线程访问和修改的变量。如果不加入volatile，
基本上会导致这样的结果：要么无法编写多线程程序，要么编译器失去大量优化的机会。
**/
volatile int counter = 0;
const int MAX_TIMES_VALUE = 10000;
mutex my_mutex;

void my_task() {
	for (int i = 0; i < MAX_TIMES_VALUE; ++i) {
		//尝试获取锁，try_lock()失败时返回false
		if (my_mutex.try_lock()) {
			++counter;
			my_mutex.unlock();
		}
	}
}

int main() {
	thread threads[10];
	for (int i = 0; i < 10; ++i) {
		threads[i] = thread(my_task);
	}

	for (auto& it : threads) {
		it.join();
	}

	cout << "Finished : the result of counter is " << counter << endl;
	system("pause");
	return 0;
}
#endif