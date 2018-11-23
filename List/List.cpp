#include "List.h"

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
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;
}
int main()
{
  test1();
  return 0;
}
