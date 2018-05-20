#if 1
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/20 16:40
*Author:yqq
*Descriptions:条件变量 的使用    生产者-消费者 
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <memory>
#include <algorithm>
#include <regex>
#include <codecvt>
#include <numeric>
#include <stack>
//#include <functional>
//using namespace std::placeholders;
using namespace std; 

#define BOOST_THREAD_VERSION 5
#include <boost/thread.hpp>
#include <boost/thread/lock_factories.hpp>
using namespace boost;

class buffer
{
private:
	mutex mu;

	condition_variable_any cond_put;
	condition_variable_any cond_get;

	stack<int>  stk;
	int un_read, capacity;

	bool is_full()
	{
		return un_read == capacity;
	}

	bool is_empty()
	{
		return un_read == 0;
	}
public:

	buffer(size_t n) :un_read(0), capacity(n) {};

	void put(int x)
	{
		{
			auto lock = make_unique_lock(mu);

			for (;is_full();)
			{
				std::cout << "full waitting..." << std::endl;
				cond_put.wait(lock);
			}

			stk.push(x); //压栈
			++un_read;
		}

		cond_get.notify_one();

	}

	void get(int *x)
	{
		{
			auto lock = make_unique_lock(mu);
			for (;is_empty();)
			{
				std::cout << "empty waiting..." << std::endl;
				cond_get.wait(lock);
			}

			--un_read;
			*x = stk.top();
			stk.pop(); //出栈

		}
		cond_put.notify_one();
	}

};

buffer g_buf(5); 

void producer(int n)
{
	for (int i = 0;  i < n; ++i)
	{
		cout << "put " << i << endl;
		g_buf.put(i);
	}

}

void consumer(int n)
{
	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		x = -1;
		g_buf.get(&x);
		cout << "get " << x << endl;
	}
}



int main(void)
{
	thread_group tg;

	tg.create_thread(std::bind(producer, 20));
	tg.create_thread(std::bind(consumer, 10));
	tg.create_thread(std::bind(consumer, 10));

	tg.join_all(); //阻塞等待 所有子线程结束
	

	//std::cout << "hello world" << std::endl;
	::system("pause");
	return 0;
}
#endif