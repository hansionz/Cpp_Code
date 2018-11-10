#include<iostream>
using namespace std;

class MyClass
{
public:
	//构造函数
	MyClass(int i = 0)
	{
		cout << i;
	}
	// 拷贝构造函数
	MyClass(const MyClass &x) 
	{
		cout << 2;
	}
	//赋值运算符重载,返回MyClass的引用是为了连续赋值
	MyClass &operator=(const MyClass &x)
	{
		cout << 3;
		return *this;
	}
	//析构函数
	~MyClass()
	{
		cout << 4;
	}
};

int main()
{
	MyClass obj1(1), obj2(2); //调用构造函数
	MyClass obj3 = obj1; //调用拷贝构造函数
	MyClass obj4; //调用构造函数
	obj4 = obj1; //调用赋值运算符重载
	// 最终程序输出 122034444
	return 0;
}
