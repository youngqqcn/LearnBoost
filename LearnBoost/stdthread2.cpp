#if 0
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

using namespace std;

void exec_proc1(int n)
{
	for (int i = 0; i < 5; ++i) {
		cout << "pass value, executing thread " << n << endl;
		//��ֹ�߳����е�10����
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void exec_proc2(int& n)
{
	for (int i = 0; i < 5; ++i) {
		cout << "pass reference, executing thread " << n << endl;
		++n;
		//��ֹ�߳����е�10����
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

int main()
{
	int n = 0;
	// t1��ʹ��Ĭ�Ϲ��캯����ʲô��û��
	thread t1;
	// t2��ʹ���вι��캯�������뺯�����ƣ���ַ��exec_pro1�����Դ�ֵ�ķ�ʽ����args
	// ����ִ��exec_proc1�еĴ���
	thread t2(exec_proc1, n + 1);
	// t3��ʹ���вι��캯�������뺯�����ƣ���ַ��exec_pro1�����Դ����õķ�ʽ����args
	// ����ִ��exec_proc1�еĴ���
	thread t3(exec_proc2, ref(n));
	// t4��ʹ���ƶ����캯������t4�ӹ�t3������t3�������߳���
	thread t4(move(t3));
	// �ɱ� joinable �� thread �����������������֮ǰ�����߳� join ���߽�������Ϊ detached.
	t2.join();
	t4.join();
	cout << "the result of n is " << n << endl;
	system("pause");
	return 0;
}
#endif