#include <iostream>
#include <thread>

using namespace std;


// C++11中线程库的使用
void func()
{
    cout << "New Thread" << endl;
}
int main()
{
    thread t(func);
    t.join();
    cout << "Main thread" << endl;
    return 0;
}
