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
	// lock_guard�����ֲ�����my_lock������lock_guard�Ĺ��췽���ж�my_mutex����
	lock_guard<mutex> my_lock(my_mutex);
	//�����Խ��������ã�����Ĵ����൱���ٽ�����ִ�й��̲��ᱻ���
	print(id);
	//���н���ʱ������my_lock��Ȼ�������������ж�my_mutex����
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