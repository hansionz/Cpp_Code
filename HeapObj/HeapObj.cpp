#include <iostream>
using namespace std;

class HeapType
{
 public:
   static HeapType* CreateObj()
   {
     return new HeapType;
   }
   void Print()
   {
     cout << "HeapType:" << this << endl;
   }
 private:
   HeapType()//构造函数私有化
   {}
   //防拷贝
   HeapType(HeapType const&);
   // HeapType& operator=(HeapType const&);
};
int main()
{
   HeapType::CreateObj()->Print();
   HeapType::CreateObj()->Print();
  return 0;
}
