#include "vector.h"
void test1()
{
  zsc::Vector<int> v2(5,10);
  int arr[] = {1,2,3,4,5,6};
  //zsc::Vector<int> v1(v2.Begin(),v2.End());
  zsc::Vector<int> v1(arr, arr+(sizeof(arr)/sizeof(arr[0])));
  cout << v1.Size() << endl;
  zsc::Vector<int> v3(v2);
  v3 = v1;
  for(size_t i = 0; i < v3.Size(); i++)
  {
    std::cout << v3[i] << " ";
  }
  std::cout << std::endl;
}
void test2()
{
  zsc::Vector<int> v;
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  v.PushBack(4);
  zsc::Vector<int>::Iterator pos = v.Find(3);
  v.Insert(pos,8);
  zsc::Vector<int>::Iterator it = v.Begin();
  while(it != v.End())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
}
void test3()
{
  zsc::Vector<int> v(10,5);
  v.Resize(5);
  for(size_t i = 0; i < v.Size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  v.Resize(12,0);
  for(size_t i = 0; i < v.Size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
void test4()
{
  int arr[] = {1,2,3,4,5,6};
  zsc::Vector<int> v1(arr, arr+(sizeof(arr)/sizeof(arr[0])));
  v1.PopBack();
  zsc::Vector<int>::Iterator pos = v1.Find(4);
  v1.Erase(pos);
  for(size_t i = 0;i < v1.Size(); i++)
  {
    cout << v1[i] << " ";
  }
  cout << endl;
}
void test5()
{
  zsc::Vector<string> v(10,"hehe");
  zsc::Vector<string> v1(v.Begin(),v.End());
  for(size_t i = 0;i < v1.Size(); i++)
  {
    cout << v1[i] << " ";
  }
  cout << endl;
}
int main()
{
  test5();
  return 0;
}
