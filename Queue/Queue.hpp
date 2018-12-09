#ifndef __QUEUE_H__
#define __QUEUE_H__ 

#include <iostream>
#include <list>

using namespace std;
namespace zsc
{
  /**
   * 模拟实现队列
   */ 
  template<class T, class Container = list<T> >
  class Queue 
  {
  public:
    void Push(const T& data)
    {
      _con.push_back(data);
    }
    void Pop()
    {
      _con.pop_front();
    }
    T& Front()
    {
      return _con.front();
    }
    size_t Size() const 
    {
      return _con.size();
    }
    bool Empty() const 
    {
      return _con.empty();
    }
  private:
    Container _con;
  };
}
#endif //__QUEUE_H__
