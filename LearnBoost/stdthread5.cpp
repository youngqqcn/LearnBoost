#if 0
#include <iostream>     
#include <chrono>      
#include <thread>  
#include <mutex>  
using namespace std;

timed_mutex my_mutex;

void my_task(int val, char tag) {
	//ÿ200ms���Ի�ȡ��,�����ȡ������whileѭ�����������һ���̱߳��
	//����0-200ms,��200ms֮ǰ�����ȡ�����������߳�������ʱ�䵽��200ms���ȡ��������
	//����������򷵻�false
	while (!my_mutex.try_lock_for(chrono::milliseconds(200))) {
		//int pid = this_thread::get_id().hash();
		cout << val;
	}
	//�ɹ�ȡ������Ȼ���߳�sleep��1000ms
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << tag << endl;
	my_mutex.unlock();
}

int main()
{
	thread threads[10];
	char end_tag[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' };
	//����10���̣߳��ֱ�ִ��my_task()�еĴ���
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