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
		//阻止线程运行到10毫秒
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void exec_proc2(int& n)
{
	for (int i = 0; i < 5; ++i) {
		cout << "pass reference, executing thread " << n << endl;
		++n;
		//阻止线程运行到10毫秒
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

int main()
{
	int n = 0;
	// t1，使用默认构造函数，什么都没做
	thread t1;
	// t2，使用有参构造函数，传入函数名称（地址）exec_pro1，并以传值的方式传入args
	// 将会执行exec_proc1中的代码
	thread t2(exec_proc1, n + 1);
	// t3，使用有参构造函数，传入函数名称（地址）exec_pro1，并以传引用的方式传入args
	// 将会执行exec_proc1中的代码
	thread t3(exec_proc2, ref(n));
	// t4，使用移动构造函数，由t4接管t3的任务，t3不再是线程了
	thread t4(move(t3));
	// 可被 joinable 的 thread 对象必须在他们销毁之前被主线程 join 或者将其设置为 detached.
	t2.join();
	t4.join();
	cout << "the result of n is " << n << endl;
	system("pause");
	return 0;
}
#endif