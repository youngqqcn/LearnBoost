#if 0
#include <iostream>      
#include <thread>      
#include <mutex>  
using namespace std;

/**
�����Ҹ���Ϥ��constһ����volatile��һ���������η���type specifier����
���Ǳ�����������α���ͬ�̷߳��ʺ��޸ĵı��������������volatile��
�����ϻᵼ�������Ľ����Ҫô�޷���д���̳߳���Ҫô������ʧȥ�����Ż��Ļ��ᡣ
**/
volatile int counter = 0;
const int MAX_TIMES_VALUE = 10000;
mutex my_mutex;

void my_task() {
	for (int i = 0; i < MAX_TIMES_VALUE; ++i) {
		//���Ի�ȡ����try_lock()ʧ��ʱ����false
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