#if 0
#include <iostream>      
#include <thread>      
#include <chrono>    
#include <mutex>    
using namespace std;

int value;
once_flag value_flag;

void setValue(int x) {
	value = x;
}

void my_task(int id) {

	this_thread::sleep_for(chrono::milliseconds(1000));

	//使setValue函数只被第一次执行的线程执行
	call_once(value_flag, setValue, id);
}

int main()
{
	thread threads[10];

	for (int i = 0; i < 10; ++i) {
		threads[i] = thread(my_task, i + 1);
	}

	for (auto& it : threads) {
		it.join();
	}
	cout << "Finished!! the result of value is : " << value << endl;
	system("pause");
	return 0;
}
#endif