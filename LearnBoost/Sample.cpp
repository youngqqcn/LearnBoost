#if 0
#include "boost/thread.hpp"
#include <iostream>
using namespace std;

boost::mutex mutex;

void wait(int sec) {
	boost::this_thread::sleep(boost::posix_time::seconds(sec));
}

void work() {
	for (int i = 0;i<5;i++) {
		wait(1);
		cout << "id: " << 1 << " " << i << endl;
	}
}
void work1(int id) {
	for (int i = 0;i<5;i++) {
		wait(1);
		cout << "id: " << id << " " << i << endl;
	}
}

void work2(int id) {
	for (int i = 0;i<5;i++) {
		mutex.lock();
		cout << "id: " << id << " " << i << endl;
		mutex.unlock();

		/******** 其他互斥锁
		boost::lock_guard<boost::mutex> lock(mutex);  lock_guard在内部构造和析构函数分别自动调用lock()和unlock()，所以能自动将当前域设为互斥访问区域。
		更多资料请参考： http://zh.highscore.de/cpp/boost/multithreading.html
		********************/
	}
}

int main() 
{
	//boost::thread th1(&work); //最简单的调用，不带任何参数
	//boost::thread th2(&work); //最简单的调用，不带任何参数


#if 1
	boost::thread th2(boost::bind(&work1, 2));
	boost::thread th3(boost::bind(&work1, 3)); // bind的一个重要应用，绑定参数！这里两个线程不加任何互斥，打印出来的是乱序
#endif

#if 0
	boost::thread th2(boost::bind(&work2, 4));
	boost::thread th3(boost::bind(&work2, 5)); // 4,5线程加简单的互斥锁，结果按次序打印
#endif

	//th1.join();  // 阻塞当前进程，等待调用线程完成，防止主线程先结束
	th2.join();
	th3.join();
	//th2.join();
	//th3.join();
	//th4.join();
	//th5.join();

	system("pause");
	return 0;
}


#endif