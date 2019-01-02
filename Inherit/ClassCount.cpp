/**
 * 统计一个基类的派生类存在多少个对象
 * 借助静态成员的特性，在继承体系中只有一个
 */ 
#include <iostream>

using namespace std;

class A
{
public:
  A()
  {
    ++count;
  }
public:
  static int count;
protected:
  int name;
};
//静态成员在类外定义
int A::count = 0;

class B : public A
{};
class C : public A
{};

int main()
{
  B b;
  C c;
  cout << A::count << endl;
  return 0;
}
