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

		/******** ����������
		boost::lock_guard<boost::mutex> lock(mutex);  lock_guard���ڲ���������������ֱ��Զ�����lock()��unlock()���������Զ�����ǰ����Ϊ�����������
		����������ο��� http://zh.highscore.de/cpp/boost/multithreading.html
		********************/
	}
}

int main() 
{
	//boost::thread th1(&work); //��򵥵ĵ��ã������κβ���
	//boost::thread th2(&work); //��򵥵ĵ��ã������κβ���


#if 1
	boost::thread th2(boost::bind(&work1, 2));
	boost::thread th3(boost::bind(&work1, 3)); // bind��һ����ҪӦ�ã��󶨲��������������̲߳����κλ��⣬��ӡ������������
#endif

#if 0
	boost::thread th2(boost::bind(&work2, 4));
	boost::thread th3(boost::bind(&work2, 5)); // 4,5�̼߳Ӽ򵥵Ļ�����������������ӡ
#endif

	//th1.join();  // ������ǰ���̣��ȴ������߳���ɣ���ֹ���߳��Ƚ���
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