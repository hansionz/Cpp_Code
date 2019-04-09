#include <iostream>
#include <vector>
#include <map>
#include <initializer_list>

using namespace std;

// 测试列表初始化
void Test1()
{
    // 内置类型的列表初始化
    // 列表初始化可以在{}之前使用等号，其效果与不使用=没有什么区别
    int x1 = {2};
    int x2{3};
    int arr1[3] = {1,2,3};
    int arr2[]{2,3,4};
    int *arr3 = new int[5]{1,2,3,4,5};
    vector<int> v{1,2,3,4};
    map<int, int> m{{1,2},{3,4}};

    // 自定义类型的列表初始化
    // 1.单个对象的列表初始化
    class Point
    {
        public:
            Point(int x, int y)
                :_x(x)
                ,_y(y)
            {}
            void Get()
            {
                cout << _x << _y << endl;
            }
        private:
            int _x;
            int _y;
    };

    Point p{1,2};
}
// 2.多个对象的列表初始化
// 注:多个对象想要支持列表初始化,需给该类(模板类)添加一个带有initializer_list类型参数的构造函数
// initializer_list是系统自定义的类模板，该类模板中主要有三个方法：begin()、end()迭代器
// 以及获取区间中元素个数的方法size()
template<class T>
class Vec 
{
    public:
        Vec(initializer_list<T> l)
            :_capacity(l.size())
            ,_size(0)
    {
        arr = new T[_capacity];
        for(auto e : l)
        {
            arr[_size++] = e;
        }
    }
    private:
        T* arr;
        size_t _size;
        size_t _capacity;
};
using namespace std;

// 测试变量类型推导
void Test2()
{
    // auto 
    short a = 3000;
    short b = 3000;
    // 这样会存在问题
    short c = a + b;
    // 这样就不会有问题
    auto d = a + b;

    map<int, char> m{{65, 'A'},{66, 'B'}};
    // map的迭代器类型
    map<int, char>::iterator it = m.begin();
    // 使用auto
    auto ait = m.begin();

    // decltype
    int x = 10;
    int y = 20;
    // 此处x + y 不会运算,只是推演出类型
    decltype(x + y) z;
    cout << typeid(z).name() << endl;

    // decltype也可以推演出返回值的类型,但是不执行函数
}

// 测试范围for循环
void Test3()
{
    vector<int> v{1,2,3,4};
    for(auto e:v)
    {
        cout << e << endl;
    }
}

// 测试final和override
void Test4()
{
    // final修饰类,表示该类不能被继承
    // final修饰虚函数,表示该虚函数不能被重写
    // 在子类中被override修饰的虚函数如果在基类中没有对应的虚函数,
}
int main()
{
    Test1();
    Test2();
    return 0;
}
