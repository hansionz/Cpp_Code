/**
 *  懒汉模式
 *  优点：第一次调用函数创建对象
 *  缺点：复杂，不是线程安全的(两个线程并行处理可能会new出来两个对象，可以加锁解决)
 **/  
#include <iostream>
#include <cstddef>
#include <mutex>
using namespace std;

class Singleton
{
public:
  static Singleton* Getinstance()
  {
    //double check(双检查)
    if(_spInstance == NULL)
    {
       _tex.lock();//上一个互斥锁，保证线程安全
       if(_spInstance == NULL)
       {
         _spInstance = new Singleton();
       }
       _tex.unlock();//相当于二元信号量
    }
    return _spInstance;
  }
  void Print()
  {
    cout << "懒汉模式" << endl;
  }
  //定义内嵌垃圾处理类，专门负责释放空间
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
    //定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对
    static CGarbo Garbo;
  };
private:
  Singleton()//构造器私有化，保证其他地方不能直接创建对象
  {}
  Singleton(Singleton const& sl);
  Singleton& operator=(Singleton const& s1) = delete;
  static Singleton* _spInstance;
  static mutex _tex;
};
Singleton* Singleton::_spInstance = NULL;
Singleton::CGarbo Garbo;
mutex Singleton::_tex;

int main()
{
  Singleton::Getinstance()->Print();
  return 0;
}
