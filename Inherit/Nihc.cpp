/**
 * 实现一个不能被继承的类
 * 构造私有化,类内存在一个获得对象的静态方法，类似单例模式
 */ 
#include <iostream>

using namespace std;

class NonInherit1
{
public:
  static NonInherit1 GetInstace()
  {
    return NonInherit1();
  }
  //c++98 构造私有化让一个类不被继承
private:
  NonInherit1()
  {}
};
//c++11给出了新的关键字final让一个类不被继承
class NonInherit2 final
{};
int main()
{
  return 0;
}
