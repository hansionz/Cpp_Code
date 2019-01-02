/**
 * 虚拟菱形继承解决菱形继承的数据冗余和二义性问题
 * 
 */ 
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
};

class Stu:virtual public Person
{
protected:
  int num;//学号
};

class Tearch:virtual public Person 
{
protected:
  int id;//工号
};

class Ass :public Stu, public Tearch
{
protected:
  string major;
};

int main()
{
  Ass a;
  //这么访问会存在数据二义性
  //a.name = "zhangsan";
  //这么做可以消除二义性，但是依然存在数据冗余
  //a.Stu::name = "zhangsan";
  //a.Tearch::name = "lisi";
  
  //可以很好的解决二义性和数据冗余问题
  a.name = "zhangsan";

  return 0;
}
