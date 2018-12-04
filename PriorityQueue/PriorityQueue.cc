#include "PriorityQueue.hpp"

int main()
{
  zsc::PriorityQueue<int> pq;
  pq.Push(1);
  pq.Push(2);
  pq.Push(3);

  cout << pq.Top() << endl;

  while(!pq.Empty())
  {
    cout << pq.Top() << endl;
    pq.Pop();
  }
  return 0;
}
