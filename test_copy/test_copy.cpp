#include<iostream>
using namespace std;

class MyClass
{
public:
	//���캯��
	MyClass(int i = 0)
	{
		cout << i;
	}
	// �������캯��
	MyClass(const MyClass &x) 
	{
		cout << 2;
	}
	//��ֵ���������,����MyClass��������Ϊ��������ֵ
	MyClass &operator=(const MyClass &x)
	{
		cout << 3;
		return *this;
	}
	//��������
	~MyClass()
	{
		cout << 4;
	}
};

int main()
{
	MyClass obj1(1), obj2(2); //���ù��캯��
	MyClass obj3 = obj1; //���ÿ������캯��
	MyClass obj4; //���ù��캯��
	obj4 = obj1; //���ø�ֵ���������
	// ���ճ������ 122034444
	return 0;
}
