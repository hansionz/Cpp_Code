#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

void test()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);	
	v.push_back(3);
	v.push_back(4);
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		++it;//vs编译器对erase检查严格，多了一个判断条件
	}
}
void test1()
{
	list<int> l1;//空构造
	list<int> l2(4, 10);//构造4个值为10的结点
	list<int> l3(l2);//拷贝构造
	list<int> l4(l2.begin(), l2.end());//使用l2的迭代器区间[begin,end)构造
	
	//C++11语法糖遍历
	for (auto& e : l4)
	{
		cout << e << " ";
	}
	cout << endl;

	int arr[] = { 1, 2, 3, 4 };//使用数组为迭代器区间构造
	list<int> l5(arr, arr + (sizeof(arr) / sizeof(int)));

	list<int>::reverse_iterator rit1 = l5.rbegin();
	list<int>::reverse_iterator rit2 = l5.rend();
	cout << *rit1 << endl;
	//cout << *rit2 << endl;
	list<int>::iterator it2 = l5.end();
	list<int>::iterator it1 = l5.begin();
	//cout << *it2 << endl;
	cout << *it1 << endl;

	//迭代器遍历
	list<int>::iterator it = l5.begin();
	while (it != l5.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test2()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));
	//正向迭代器 1 2 3 4
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		//*it *= 2;可以修改
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//正向const迭代器 1 2 3 4(但是*it不能修改)
	list<int>::const_iterator cit = l1.cbegin();
	while (cit != l1.cend())
	{
		//*cit *= 2; 不能修改
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
	//反向迭代器 4 3 2 1
	list<int>::reverse_iterator rit = l1.rbegin();
	while (rit != l1.rend())
	{
		//*rit *= 2; 可以修改
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//反向const迭代器 4 3 2 1
	list<int>::const_reverse_iterator crit = l1.crbegin();
	while (crit != l1.crend())
	{
		//*crit *= 2; 不可以修改
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}
void test3()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));
	int size = l1.size();
	//输出l1的大小
	cout << size << endl;
	//判断l1是否为空，不为空遍历打印
	if (l1.empty())
	{
		cout << "list为空" << endl;
	}
	else
	{
		for (auto e : l1)
		{
			cout << e << " ";
		}
		cout << " ";
	}
}
void test4()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));
	l1.front() = 10;//将l1中的第一个数据改为10
	const int& x = l1.back();//获取l1中最后一个结点值的const引用
	//x = 10;const引用不可改变
	cout << x << endl;
}
void PrintList(list<int>& l)
{
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
/*测试push_front、push_back、pop_front、pop_back*/
void test5()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));
	l1.push_front(0);
	l1.push_back(5);
	PrintList(l1);//0 1 2 3 4 5

	l1.pop_front();
	l1.pop_back();
	PrintList(l1);//1 2 3 4 
}
/*测试insert、erase*/
void test6()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));
	
	//获得值为3的迭代器
	list<int>::iterator pos = find(l1.begin(), l1.end(), 3);
	
	//在pos前插入值为0的结点
	l1.insert(pos, 0);
	PrintList(l1);//1 2 0 3 4 
	
	//在pos前插入5个值为8的结点
	l1.insert(pos, 2, 8);
	PrintList(l1);//1 2 0 8 8 3 4

	//在pos前插入[v.begin(), v.end)区间中的结点
	vector<int> v(2, 7);
	l1.insert(pos, v.begin(), v.end());
	PrintList(l1);//1 2 0 8 8 7 7 3 4

	//删除pos位置的元素
	l1.erase(pos);
	PrintList(l1);//1 2 0 8 8 7 7 4

	//删除迭代器区间的值
	l1.erase(l1.begin() , l1.end());
	PrintList(l1);//list为空
}
/* 测试resize、swap、clear */
void test7()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));
	PrintList(l1);//1 2 3 4

	//将l1中元素个数增加到10个，多出的元素用默认值填充    
	//如果list中放置的是内置类型，默认值为0
	//如果list中放置自定义类型元素，调用缺省构造函数
	l1.resize(6);
	PrintList(l1);//1 2 3 4 0 0

	//将l1中的元素增加到8个，多出的元素用8来填充
	l1.resize(8, 8);
	PrintList(l1);//1 2 3 4 0 0 8 8

	//将l1中的元素减少到5个 
	l1.resize(5);
	PrintList(l1);//1 2 3 4 0

	// 用vector中的元素来构造list    
	vector<int> v{ 4, 5, 6 };    
	list<int> l2(v.begin(), v.end());    
	PrintList(l2);//4 5 6

	//交换l1和l2的元素
	l1.swap(l2);
	PrintList(l1);//4 5 6
	PrintList(l2);//1 2 3 4 0

	// 将l2中的元素清空    
	l2.clear();    
	cout << l2.size() << endl;//0
	PrintList(l2);//空
}
/*测试emplace_back、emplace_front、emplace */
class Date {
public:    
	Date(int year = 1900, int month = 1, int day = 1) 
		: _year(year)
		, _month(month)
		, _day(day)    
	{ 
		cout << "Date(int, int, int):" << this << endl; 
	}

	Date(const Date& d) 
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)    
	{ 
		cout << "Date(const Date&):" << this << endl; 
	}

private:    
	int _year;    
	int _month;    
	int _day;
};
//push_back尾插：先构造好元素，然后将元素拷贝到节点中，插入时先调构造函数，再调拷贝构造函数 
//emplace_back尾插：先构造节点，然后调用构造函数在节点中直接构造对象 
//emplace_back比push_back更高效，少了一次拷贝构造函数的调用 
void test8()
{
	list<Date> l;    
	Date d(2018, 10, 20);    
	l.push_back(d); //构造--拷贝构造
	l.emplace_back(2018, 10, 21);  //插入时直接构造 
	l.emplace_front(2018, 10, 19); //插入时直接构造 
}
void test9()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));

	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		// erase()函数执行后，it所指向的节点已被删除
		//因此it无效，在下一次使用it时，必须先给其赋值
		//l1.erase(it);
		//++it;这样做编译器报错迭代器失效

		/*可以这么修改*/
		//it = l1.erase(it);//erase删除之后，返回下一个位置的迭代器
		l1.erase(it++);//也可以这么写，相当于it = l1.erase(it);
	}
}
int main()
{
	test9();
	return 0;
}
//1.打印函数尽量加上const(防止函数内修改)和引用(减少拷贝带来的代价)
//2.C++11中可以用auto，但是代码的可读性降低
//3.reference 代表value_type的引用
//4.vector的insert和erase迭代器都会失效()
//5.list的insert不会失效(不存在扩容)，erase也会存在失效(1-2-3,删除2,1-3，迭代器会出现野指针)
//splice 移花接木
//unique 去重(先排序在去重)
//sort 排序(归并排序)
//merge 合并两条链表
//6.模板不支持分类编译(.hcpp进阶模板)
//默认的习惯：不使用限定符可以使用struct(默认public),使用限定符使用class(默认private)
//Vector(const Vector& v = T()),T()是一个匿名对象
//设计实现双向链表(双向带头循环链表操作统一简单实用)