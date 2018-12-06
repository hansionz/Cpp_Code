#include <iostream>
#include <list>
#include <deque>

using namespace std;
//使用双端队列实现栈
template<class T, class Container = deque<T> >
class Stack
{
public:
  //入栈
  void Push(const T& data)
  {
    _con.push_back(data);
  }
  //出栈
  void Pop()
  {
    _con.pop_back();
  }
  //判断栈是否为空
  bool Empty() const 
  {
    return _con.empty();
  }
  //栈中元素的个数
  size_t Size() const 
  {
    return _con.size();
  }
  //获取栈顶元素
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
