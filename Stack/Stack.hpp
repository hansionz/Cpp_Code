#include <iostream>
#include <list>
#include <deque>

using namespace std;
//使用双端队列实现栈
template<class T, class Container = deque<T> >
class Stack
{
public:
  void Push(const T& data)
  {
    _con.push_back(data);
  }
  void Pop()
  {
    _con.pop_back();
  }
  bool Empty() const 
  {
    return _con.empty();
  }
  size_t Size() const 
  {
    return _con.size();
  }
  T& Top()
  {
    return _con.back();
  }
  const T& Top() const 
  {
    return _con.back();
  }
private:
  Container _con;
};
