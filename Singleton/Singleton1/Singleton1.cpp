/**
 * 饿汉模式
 * 优点：简单
 * 缺点：可能导致启动慢(因为对象是在main入口之前创建的)
 **/  
#include <iostream>
using namespace std;

class Singleton
{
public:
  static Singleton* Getinstance()
  {
    return &_sInstance; 
  }
 //这里也可以直接返回值或者引用 
 // static Singleton& Getinstance()
 // {
 //   return _sInstance;
 // }
  void Print()
  {
    cout << "饿汉模式" << endl;
  }
private:
  Singleton()//构造器私有化，保证其他地方不能直接创建对象
  {}
  //防止拷贝构造,C++98只声明不定义
  Singleton(Singleton const& sl);
  //C++11已删除函数
  Singleton& operator=(Singleton const& sl) = delete;
  static Singleton _sInstance;
};
Singleton Singleton::_sInstance; //在main函数入口之前就已经创建好对象
int main()
{
  //Singleton s1; 在定义静态变量_sIntance时就已经创建了对象
  //Singleton s(*Singleton::Getinstance()); 
  //Singleton s1 = *Singleton::Getinstance();
  Singleton::Getinstance()->Print();
  return 0;
}
