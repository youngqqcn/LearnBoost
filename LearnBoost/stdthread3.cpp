#if 0
#include <stdio.h>
#include <stdlib.h>
#include <chrono>   
#include <iostream>  
#include <thread>  
using namespace std;

void exec_produce(int duration) {
	//��ֹ�߳����е�duration��
	this_thread::sleep_for(chrono::seconds(duration));
	//this_thread::get_id()��ȡ��ǰ�߳�id
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
	//�������ᱨ��,ԭ�����copy���������ã��൱����delete���������Ա���
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