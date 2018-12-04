#include "Stack.hpp"

int main()
{
  Stack<int> s;
  s.Push(1);
  s.Push(2);
  s.Push(3);
  
  cout << s.Top() << endl;
  s.Pop();
  cout << s.Top() << endl;
  
  cout << s.Empty() << endl;
  cout << s.Size() << endl;
  return 0;
}
