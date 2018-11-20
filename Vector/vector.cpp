#include "vector.h"
void test1()
{
  zsc::Vector<int> v2(4,10);
  //int arr[] = {1,2,3,4};
  zsc::Vector<int> v1(v2.Begin(),v2.End());
  //cout << v1.Size() << endl;
  //zsc::Vector<int> v3(v2);
  //for(size_t i = 0; i < v1.Size(); i++)
  //{
  //  std::cout << v1[i] << " ";
  //}
  //std::cout << std::endl;
}
void test2()
{
  zsc::Vector<int> v;
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  v.PushBack(4);
  //zsc::Vector<int>::Iterator pos = v.Find(3);
  //v.Insert(v.End(),8);
  zsc::Vector<int>::Iterator it = v.Begin();
  while(it != v.End())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
}
int main()
{
  test1();
  return 0;
}
