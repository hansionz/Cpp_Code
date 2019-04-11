#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// C++98中对数组进行排序
void Test1()
{
    int arr[] = {1, 5, 2, 4, 9, 3};

    // 默认是升序排序,小于比较
    sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
    for(int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << endl;
    }
    // 降序排序
    sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
    for(int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << endl;
    }
}

// C++98中对自定义类型进行排序
void Test2()
{
    struct good
    {
        string _name;
        double _price;
    };
    struct Compare
    {
        bool operator()(const good& gl, const good& gw)
        {
            return gl._price <= gw._price;
        }
    };

    good ga[] = {{"s", 2.1},{"v", 3.2},{"m", 1.7}};
    sort(ga, ga + sizeof(ga) / sizeof(ga[0]), Compare());

    for(int i = 0; i < sizeof(ga) / sizeof(ga[0]); i++)
    {
        cout << ga[i]._name << ":" << ga[i]._price << endl;
    }

    // c++11 lambda表达式写法
    good gb[] = {{"m", 2.1},{"c", 3.2},{"a", 1.7}};
    sort(gb, gb + sizeof(gb) / sizeof(gb[0]), [](const good& gl, const good& gw)
                                                { 
                                                    return gl._price <= gw._price; 
                                                });
    for(int i = 0; i < sizeof(gb) / sizeof(gb[0]); i++)
    {
        cout << gb[i]._name << ":" << gb[i]._price << endl;
    }
}
// C++11 lambda表达式
// [捕捉列表](参数列表)mutable(取消常属性,参数列表不能省略)->返回值类型{函数体}
void Test3()
{

}
int main()
{
    //Test1();
    Test2();
    return 0;
}
