#if 0
#include <iostream>  
#include <thread>  
#include <mutex>    
using namespace std;

mutex my_mutex;
mutex some_mutex;

//ʹ�ú����������Ĺ��캯��
void my_task(int n, char c) {
	unique_lock<mutex> my_lock(my_mutex, defer_lock);
	my_lock.lock();
	for (int i = 0; i < n; ++i) {
		cout << c;
	}
	cout << endl;
	//���Զ�unlock
}

unique_lock<mutex> prepare_task()
{
	unique_lock<mutex> lock(some_mutex);

	cout << "print prepare data" << endl;
	//���ض�some_mutex������Ȩ����δ����
	return lock;
}
void finish_task(int v)
{
	//ȡ��prepare_task������������Ȩ
	unique_lock<mutex> lk(prepare_task());
	cout << "finished :" << v << endl;
	//����������
}

int main()
{
	thread t1(my_task, 50, '1');
	thread t2(my_task, 50, '2');

	t1.join();
	t2.join();

	thread threads[5];
	for (int i = 0; i < 5; ++i)
	{
		threads[i] = thread(finish_task, i);
	}
	for (auto& it : threads) {
		it.join();
	}
	system("pause");
	return 0;
}
#endif