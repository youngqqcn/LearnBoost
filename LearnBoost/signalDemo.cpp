#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/20 13:38
*Author:yqq
*Descriptions:none
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
//#include <functional>
//using namespace std::placeholders;
using namespace std;

#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <boost/random.hpp>

using namespace boost;
using namespace boost::signals2;



//随机数发生器
typedef variate_generator<rand48, uniform_smallint<> > bool_rand;
bool_rand g_rand(rand48(time(0)), uniform_smallint<>(0, 100) );

typedef signal<void()> signal_t;
typedef signal_t::slot_type slot_t;



/*
这里必须是 extern

*/
extern char const baby1[] = "Tom";
extern char const baby2[] = "Jim";

extern char const nurse1[] = "Mary";
extern char const nurse2[] = "Kate";




class Ring
{
public:
	

	connection connect(const slot_t & s)
	{
		return alarm.connect(s);
	}

	void press()
	{
		std::cout << "Ring alarms...." << std::endl;
		alarm(); //发信号
	}


private:
	signal_t alarm;

};


//template <int N>
template <char const *N>
class nurse
{
public:
	nurse() :rand(g_rand) {};

	void action()
	{
		cout <<"nurse" << N;
		if (rand() > 30)
		{
			cout << " wakeup and open the door." << std::endl;
		}
		else
		{
			cout << " is sleeping..." << endl;
		}
	}

private:
	bool_rand &rand;
};


//template <int N>
template <char const *N>
class baby
{
public:
	baby():rand(g_rand) {  };

	void action()
	{
		cout << "Baby" << N;
		if (rand() > 50)
		{
			cout << " wakeup and crying loudly...." << endl;
		}
		else
		{
			cout << " is sleeping sweetly..." << endl;
		}
	}
private:
	bool_rand  rand;

};

struct guest
{
	void press(Ring& r)
	{
		std::cout << "A guest presses the ring." << std::endl;
		r.press();
	}
};






int main(void)
{
	Ring r;
	/*
	nurse<1> n1;
	nurse<2> n2;

	baby<1> b1;
	baby<2> b2;
	*/
	nurse<nurse1> n1;
	nurse<nurse2> n2;

	baby<baby1> b1;
	baby<baby2> b2;

	guest g;

	//r.connect(slot_t(&nurse<1>::action, n1));
	//r.connect(slot_t(&nurse<2>::action, n2));
	//r.connect(slot_t(&baby<1>::action, b1));
	//r.connect(slot_t(&baby<2>::action, b2));

	r.connect(slot_t(&nurse<nurse1>::action, n1));
	r.connect(slot_t(&nurse<nurse2>::action, n2));
	r.connect(slot_t(&baby<baby1>::action, b1));
	r.connect(slot_t(&baby<baby2>::action, b2));

	//r.connect(boost::bind(&nurse<2>::action, n2));
	//r.connect(boost::bind(&nurse<1>::action, b1));
	//r.connect(boost::bind(&nurse<2>::action, b2));

	g.press(r); //客人


	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif