#if 0
#include <iostream>  
#include <iomanip>  
#include <memory>  
#include <functional>  

typedef   std::function<void(int)>   HandlerEvent;

//定义一个成员变量  
class Sharp
{
public:
	HandlerEvent handlerEvent;
};
//设置handlerEvent的值来动态装载事件响应函数  
class Rectangle
{
private:
	std::string name;
	Sharp sharp;
public:
	void initial(void);
	const Sharp getSharp() const;
	static void onEvent(int param)
	{
		std::cout << "invode onEvent method,get parameter: " << param << std::endl;
	}
};
//类的实现方法  
void Rectangle::initial()
{
	sharp.handlerEvent = HandlerEvent(&Rectangle::onEvent);
	std::cout << "invode initial function!" << std::endl;
}
const Sharp Rectangle::getSharp() const
{
	return sharp;
}

//测试函数  
int main(int argc, char *argv[]) {
	std::cout << "hi: " << std::setw(50) << "hello world!" << std::endl;
	Rectangle rectangle;
	rectangle.initial();
	rectangle.getSharp().handlerEvent(23);
	std::cin.get();
}
#endif