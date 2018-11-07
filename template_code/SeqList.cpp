#include <iostream>
#include <string.h>
using namespace std;
template<class T>
class Vector
{
 public:
   Vector(int capacity)
     :_pData(new T[capacity])
      , _size(0)
      ,_capacity(capacity)
      {}
   //析构函数,类外定义
   ~Vector();
   void checkcapacity()
   {
     if(_size == _capacity)
     {
       _capacity *= 2;
       T* tmp = new T[_capacity];
       memcpy(tmp, _pData, sizeof(T)*_size);
       delete[] _pData;
       _pData = tmp;
     }
   }
   //尾插
   void PushBack(const T& data)
   {
     checkcapacity();
     _pData[_size++] = data;
   }
   size_t GetSize()
   {
     return _size;
   }
   T* GetData()
   {
     return _pData;
   }
 private:
   T* _pData;
   size_t _size;
   size_t _capacity;
};
template<class T>
Vector<T>::~Vector()
{
  if(_pData)
  {
    delete[] _pData;
  }
  _size = _capacity = 0;
}
int main()
{
  Vector<int> s1(3);
  s1.PushBack(1);
  s1.PushBack(2);
  s1.PushBack(3);
  s1.PushBack(4);
  int i = 0;
  for(; i < s1.GetSize(); i++)
  {
    cout << s1.GetData()[i] << endl; 
  }
  return 0;
}
