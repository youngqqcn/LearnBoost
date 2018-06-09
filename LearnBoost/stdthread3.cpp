#if 0
#include <stdio.h>
#include <stdlib.h>
#include <chrono>   
#include <iostream>  
#include <thread>  
using namespace std;

void exec_produce(int duration) {
	//阻止线程运行到duration秒
	this_thread::sleep_for(chrono::seconds(duration));
	//this_thread::get_id()获取当前线程id
	cout << "exec_produce thread " << this_thread::get_id()
		<< " has sleeped " << duration << " seconds" << endl;
}

int main(int argc, const char *argv[])
{
	thread threads[5];
	cout << "create 5 threads ..." << endl;
	for (int i = 0; i < 5; i++) {
		threads[i] = thread(exec_produce, i + 1);
	}
	cout << "finished creating 5 threads, and waiting for joining" << endl;
	//下面代码会报错,原因就是copy操作不可用，相当于是delete操作，所以报错
	/*for(auto it : threads) {
	it.join();
	}*/
	for (auto& it : threads) {
		it.join();
	}
	cout << "Finished!!!" << endl;
	system("pause");
	return 0;
}
#endif