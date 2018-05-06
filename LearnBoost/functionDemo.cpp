#if 0
#include <iostream>  
#include <iomanip>  
#include <memory>  
#include <functional>  

typedef   std::function<void(int)>   HandlerEvent;

//����һ����Ա����  
class Sharp
{
public:
	HandlerEvent handlerEvent;
};
//����handlerEvent��ֵ����̬װ���¼���Ӧ����  
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
//���ʵ�ַ���  
void Rectangle::initial()
{
	sharp.handlerEvent = HandlerEvent(&Rectangle::onEvent);
	std::cout << "invode initial function!" << std::endl;
}
const Sharp Rectangle::getSharp() const
{
	return sharp;
}

//���Ժ���  
int main(int argc, char *argv[]) {
	std::cout << "hi: " << std::setw(50) << "hello world!" << std::endl;
	Rectangle rectangle;
	rectangle.initial();
	rectangle.getSharp().handlerEvent(23);
	std::cin.get();
}
#endif