#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

template<class Mutex>
class LockGuard
{
public:
  LockGuard(Mutex& mutex)
    :_mutex(mutex)
  {
    _mutex.lock();
  }
  ~LockGuard()
  {
    _mutex.unlock();
  }
private:
  LockGuard(const LockGuard<Mutex>&) = delete; 
  Mutex& _mutex;//必须要加引用,否则锁住的不是同一个互斥量对象
};
mutex _mtx;
static int n = 0;
void Func()
{
  for(size_t i = 0; i< 10000; i++)
  {
    LockGuard<mutex> lock(_mtx);
    n++;//保护n
  }
}
int main()
{ 
  int begin = clock();

  thread t1(Func);
  thread t2(Func);
  t1.join();
  t2.join();

  int end = clock();

  cout << n << endl;
  cout << "time:" <<  end-begin << endl;
  return 0;
}
