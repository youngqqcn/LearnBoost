#if 0
#include <iostream>    
#include <functional>   
#include <thread>      
#include <future>   
using namespace std;

//ͨ��std::future��ȡ����״̬��ֵ
void printShareState(future<int>& state) {
	// ��ȡ����״̬��ֵ.
	int x = state.get();
	cout << "share state value : " << x << endl;
}

int main()
{
	// ����һ�� promise<int> ����״ֵ̬Ϊint����
	promise<int> prom;
	// �� future ����
	future<int> fut = prom.get_future();
	// �� future ��������һ���߳�t.
	thread t(printShareState, ref(fut));
	// ���ù���״̬��ֵ, �˴����߳�t����ͬ��.
	prom.set_value(10);
	t.join();
	system("pause");
	return 0;
}
#endif