#include <iostream>
#include <cstddef>
#include <mutex>
using namespace std;

class Singleton
{
public:
  static Singleton* Getinstance()
  {
    if(_spInstance == NULL)
    {
      _spInstance = new Singleton();
    }
    return _spInstance;
  }
  void Print()
  {
    cout << "懒汉模式" << endl;
  }
  //定义
  class CGarbo 
  {
  public:
    ~ CGarbo()
    {
      if(Singleton::_spInstance)
        delete Singleton::_spInstance;
    }   
    void Print1()
    {
      cout << "析构函数" << endl;
    }
    //定义一个静态的成员变量,当程序结束时会自动调用这个对象的析构函数从而释放这个单例模式
    //析构函数不能定义在外部，因为定义在外部的话这个对象使用完了，就直接去调用析构了
    static CGarbo Garbo;
    static mutex _tex;
  };
private:
  Singleton()//构造器私有化，保证其他地方不能直接创建对象
  {}
  static Singleton* _spInstance;
};
Singleton* Singleton::_spInstance = NULL;
Singleton::CGarbo Garbo;
int main()
{
  Singleton::Getinstance()->Print();
  return 0;
}
