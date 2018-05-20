#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/05/20 10:33
*Author:yqq
*Descriptions: 合并器, 接收和处理 槽函数的返回值
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
#include <functional>
#include <numeric>
using namespace std::placeholders;
using namespace std;

#include <boost/signals2.hpp>
using namespace boost::signals2;


template<int N>
struct slots
{
	int  operator()(int x)
	{
		std::cout << "slot " << N << " called" << std::endl;
		return x * N;
	}
};

template < typename T>
class combiner
{
private:
	T v;

public:
	 
	typedef std::pair<T, T> result_type;
	
	combiner(T t = T()):v(t) {};

	template < typename InputIterator>
	result_type operator()(InputIterator begin, InputIterator end) const
	{
		if (begin == end)
			return result_type();

		vector<T> vct(begin, end);

		T sum = std::accumulate(vct.begin(), vct.end(), v);
		T max = *std::max_element(vct.begin(), vct.end());

		return result_type(sum, max);
	}
};



int main(void)
{
	signal<int(int), combiner<int>> sig;

	sig.connect(slots<10>());
	sig.connect(slots<20>());
	sig.connect(slots<30>(), at_front);

	auto x = sig(2);

	std::cout << x.first << "," << x.second << endl;

	

	//std::cout << "hello world" << std::endl;
	system("pause");
	return 0;
}
#endif