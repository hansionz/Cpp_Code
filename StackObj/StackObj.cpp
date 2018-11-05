#include <iostream>
using namespace std;

class StackType
{
 public:
   StackType()
   {}
   void Print()
   {
     cout << "StackType:" << this << endl;
   }
 private:
   //不能再堆上创建，我们可以考虑直接把operator new和new的定位表达式声明为私有的
   //将operator new声明为私有的，就把new的定位表达式也声明为私有的了
   void* operator new(size_t size);
   void operator delete(void* p);
};
int main()
{
  StackType st1;//ok 
  st1.Print();
  //StackType st2 = new StackType();//不行，因为operator new被屏蔽了
  //StackType* st3 = (StackType*)malloc(sizeof(StackType));
  //new(st3)StackType();//不行，因为new的定位表达式也被屏蔽
  return 0;
}
