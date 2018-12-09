#include "Queue.hpp"

int main()
{
  zsc::Queue<int, list<int> > q;
  q.Push(1); 
  q.Push(2);
  q.Push(3);

  cout << q.Size() << endl;

  while(!q.Empty())
  {
    cout << q.Front() << endl;
    q.Pop();
  }
  cout << q.Size() << endl;

  return 0;
}
