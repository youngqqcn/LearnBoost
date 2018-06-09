#if 0
#include <iostream>    
#include <functional>   
#include <thread>      
#include <future>   
using namespace std;

//通过std::future获取共享状态的值
void printShareState(future<int>& state) {
	// 获取共享状态的值.
	int x = state.get();
	cout << "share state value : " << x << endl;
}

int main()
{
	// 创建一个 promise<int> 对象，状态值为int类型
	promise<int> prom;
	// 和 future 关联
	future<int> fut = prom.get_future();
	// 将 future 交给另外一个线程t.
	thread t(printShareState, ref(fut));
	// 设置共享状态的值, 此处和线程t保持同步.
	prom.set_value(10);
	t.join();
	system("pause");
	return 0;
}
#endif