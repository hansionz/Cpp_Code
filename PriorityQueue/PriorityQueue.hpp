#ifndef __PRI_QUEUE_H__
#define __PRI_QUEUE_H__

#include <iostream>
#include <vector>

using namespace std;

namespace zsc
{
	/**
	  * 模拟实现优先级队列
	  */ 
  template<class T>
  class Less 
  {
  public:
    bool operator()(const T& x1, const T& x2)
    {
      return x1 < x2;
    }
  };
  template<class T>
  class Greater 
  {
  public:
    bool operator()(const T& x1, const T& x2)
    {
      return x1 > x2;
    }
  };
  template<class T, class Container = vector<T>, class Compare = Greater<T> >
  class PriorityQueue
  {
  public:
    void AdjustUp(int child)
    {
      int parent = (child - 1) / 2;
      while(child > 0)
      {
        Compare com;
        //if(_con[parent] <  _con[child])
        if(com(_con[child], _con[parent]))
        {
          swap(_con[parent], _con[child]);
          child = parent;
          parent = (child - 1) / 2;
        }
        else 
        {
          break;
        }
      }
    }
    void AdjustDown(int parent)
    {
      int child = 2*parent + 1;
      while(child < _con.size())
      {
        Compare com;
        if(child + 1 < _con.size() && com(_con[child + 1], _con[child]))
        {
          ++child;
        }
        //if(_con[child] > _con[parent])
        if(com(_con[child], _con[parent]))
        {
          swap(_con[child], _con[parent]);
          parent = child;
          child = 2*parent + 1;
        }
        else 
        {
          break;
        }
      }
    }
    void Push(const T& data)
    {
      _con.push_back(data);
      AdjustUp(_con.size() - 1);
    }
    void Pop()
    {
      swap(_con[0], _con[_con.size() - 1]);
      _con.pop_back();
      AdjustDown(0);
    }
    size_t Size() const 
    {
      return _con.size();
    }
    bool Empty() const 
    {
      return _con.empty();
    }
    T& Top()
    {
      return _con[0];
    }
  private:
    Container _con;
  };
}
#endif 
