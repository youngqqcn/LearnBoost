#if 0
#include <functional>
#include <iostream>

/*
C++11 之所以引入 std::ref 
就是为了解决 std::bind  参数传递时(默认是拷贝传参) 
可以选择 "引用传参"(已使用std::ref)
*/

void f(int& n1, int& n2, const int& n3)
{
	std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
	++n1; // increments the copy of n1 stored in the function object
	++n2; // increments the main()'s n2
		  // ++n3; // compile error
}

int main()
{
	int n1 = 1, n2 = 2, n3 = 3;
	std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
	n1 = 10;
	n2 = 11;
	n3 = 12;


	std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
	bound_f(); //调用绑定的函数
	std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';


	system("pause");
	return 0;
}
#endif