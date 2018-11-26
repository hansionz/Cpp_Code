#include "List.h"

//测试遍历
void test1()
{
  zsc::List<int> l;
  l.PushBack(1);
  l.PushBack(2);
  l.PushBack(3);
  l.PushBack(4);
  l.PushBack(5);
  zsc::List<int>::iterator it = l.begin();
  while(it != l.end())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  for(auto& e: l)
  {
    cout << e << " ";
  }
  cout << endl;
}
/*测试构造*/
void test2()
{
  zsc:: List<int> l(10,5);
  zsc::List<int>::iterator it = l.begin();

  vector<string> v(3,"hehe");
  zsc::List<string> l1(v.begin(), v.end());

  zsc::List<int> l2(l);

  zsc::List<string> l3;
  l3 = l1;
  while(it != l.end())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  for(auto e : l3)
  {
    cout << e << " ";
  }
  cout << endl;
}
/*测试list modify*/
void test3()
{
  int arr[] = {1,2,3,4};
  zsc::List<int> l(arr,arr+(sizeof(arr)/sizeof(arr[0])));
  l.PushBack(5);
  l.PushFront(0);
  l.PopBack();
  l.PopFront();

  zsc::List<int>::iterator pos = l.Find(3);
  l.Insert(pos,0);
  zsc::List<int>::iterator pos1 = l.Find(2);
  l.Erase(pos1);

  for(auto e : l)
  {
    cout << e << " ";
  }
  cout << endl;
}
/*测试List capacity*/
void test4()
{
  zsc::List<int> l(10,10);
  cout << l.Size() << endl;
  cout << l.Empty() << endl;
  l.Resize(5);
  for(auto& e : l)
  {
    cout << e << " ";
  }
  cout << endl;
}
/*测试List Access*/
void test5()
{
  zsc::List<int> l(5,10);
  l.Front() = 5;
  int x = l.Back();
  cout << x << endl;

  for(const auto& e:l)
  {
    cout << e << " ";
  }
  cout << endl;
}
/*测试迭代器*/
void test6()
{
  int arr[] ={1,2,3,4};
  zsc::List<int> l(arr, arr+(sizeof(arr)/sizeof(arr[0])));
  zsc::List<int>::iterator it = l.begin();
  ++it;
  //cout << *(it++) << endl;
  //--it 
  //--it;
  cout << *(it--) << endl;
}
void test7()
{
  zsc::List<int> l(4,10);
  zsc::List<int> l1(l);
  l.PushBack(1);
  l.PopFront();
  for(auto e : l1)
  {
    cout << e << " ";
  }
  cout << endl;
}
void test8()
{
  zsc::List<string> l(5,"he");
  zsc::List<string>::const_iterator cit = l.cbegin();
  while(cit != l.cend())
  {
    //*cit = 2;const迭代器不能修改
    cout << *cit << " ";
    ++cit;
  }
  cout << endl;
}
int main()
{
  test8();
  return 0;
}
