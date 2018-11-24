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
		++it;//vs��������erase����ϸ񣬶���һ���ж�����
	}
}
void test1()
{
	list<int> l1;//�չ���
	list<int> l2(4, 10);//����4��ֵΪ10�Ľ��
	list<int> l3(l2);//��������
	list<int> l4(l2.begin(), l2.end());//ʹ��l2�ĵ���������[begin,end)����
	
	//C++11�﷨�Ǳ���
	for (auto& e : l4)
	{
		cout << e << " ";
	}
	cout << endl;

	int arr[] = { 1, 2, 3, 4 };//ʹ������Ϊ���������乹��
	list<int> l5(arr, arr + (sizeof(arr) / sizeof(int)));

	list<int>::reverse_iterator rit1 = l5.rbegin();
	list<int>::reverse_iterator rit2 = l5.rend();
	cout << *rit1 << endl;
	//cout << *rit2 << endl;
	list<int>::iterator it2 = l5.end();
	list<int>::iterator it1 = l5.begin();
	//cout << *it2 << endl;
	cout << *it1 << endl;

	//����������
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
	//��������� 1 2 3 4
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		//*it *= 2;�����޸�
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//����const������ 1 2 3 4(����*it�����޸�)
	list<int>::const_iterator cit = l1.cbegin();
	while (cit != l1.cend())
	{
		//*cit *= 2; �����޸�
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
	//��������� 4 3 2 1
	list<int>::reverse_iterator rit = l1.rbegin();
	while (rit != l1.rend())
	{
		//*rit *= 2; �����޸�
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//����const������ 4 3 2 1
	list<int>::const_reverse_iterator crit = l1.crbegin();
	while (crit != l1.crend())
	{
		//*crit *= 2; �������޸�
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
	//���l1�Ĵ�С
	cout << size << endl;
	//�ж�l1�Ƿ�Ϊ�գ���Ϊ�ձ�����ӡ
	if (l1.empty())
	{
		cout << "listΪ��" << endl;
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
	l1.front() = 10;//��l1�еĵ�һ�����ݸ�Ϊ10
	const int& x = l1.back();//��ȡl1�����һ�����ֵ��const����
	//x = 10;const���ò��ɸı�
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
/*����push_front��push_back��pop_front��pop_back*/
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
/*����insert��erase*/
void test6()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));
	
	//���ֵΪ3�ĵ�����
	list<int>::iterator pos = find(l1.begin(), l1.end(), 3);
	
	//��posǰ����ֵΪ0�Ľ��
	l1.insert(pos, 0);
	PrintList(l1);//1 2 0 3 4 
	
	//��posǰ����5��ֵΪ8�Ľ��
	l1.insert(pos, 2, 8);
	PrintList(l1);//1 2 0 8 8 3 4

	//��posǰ����[v.begin(), v.end)�����еĽ��
	vector<int> v(2, 7);
	l1.insert(pos, v.begin(), v.end());
	PrintList(l1);//1 2 0 8 8 7 7 3 4

	//ɾ��posλ�õ�Ԫ��
	l1.erase(pos);
	PrintList(l1);//1 2 0 8 8 7 7 4

	//ɾ�������������ֵ
	l1.erase(l1.begin() , l1.end());
	PrintList(l1);//listΪ��
}
/* ����resize��swap��clear */
void test7()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));
	PrintList(l1);//1 2 3 4

	//��l1��Ԫ�ظ������ӵ�10���������Ԫ����Ĭ��ֵ���    
	//���list�з��õ����������ͣ�Ĭ��ֵΪ0
	//���list�з����Զ�������Ԫ�أ�����ȱʡ���캯��
	l1.resize(6);
	PrintList(l1);//1 2 3 4 0 0

	//��l1�е�Ԫ�����ӵ�8���������Ԫ����8�����
	l1.resize(8, 8);
	PrintList(l1);//1 2 3 4 0 0 8 8

	//��l1�е�Ԫ�ؼ��ٵ�5�� 
	l1.resize(5);
	PrintList(l1);//1 2 3 4 0

	// ��vector�е�Ԫ��������list    
	vector<int> v{ 4, 5, 6 };    
	list<int> l2(v.begin(), v.end());    
	PrintList(l2);//4 5 6

	//����l1��l2��Ԫ��
	l1.swap(l2);
	PrintList(l1);//4 5 6
	PrintList(l2);//1 2 3 4 0

	// ��l2�е�Ԫ�����    
	l2.clear();    
	cout << l2.size() << endl;//0
	PrintList(l2);//��
}
/*����emplace_back��emplace_front��emplace */
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
//push_backβ�壺�ȹ����Ԫ�أ�Ȼ��Ԫ�ؿ������ڵ��У�����ʱ�ȵ����캯�����ٵ��������캯�� 
//emplace_backβ�壺�ȹ���ڵ㣬Ȼ����ù��캯���ڽڵ���ֱ�ӹ������ 
//emplace_back��push_back����Ч������һ�ο������캯���ĵ��� 
void test8()
{
	list<Date> l;    
	Date d(2018, 10, 20);    
	l.push_back(d); //����--��������
	l.emplace_back(2018, 10, 21);  //����ʱֱ�ӹ��� 
	l.emplace_front(2018, 10, 19); //����ʱֱ�ӹ��� 
}
void test9()
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l1(arr, arr + (sizeof(arr) / sizeof(int)));

	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ��
		//���it��Ч������һ��ʹ��itʱ�������ȸ��丳ֵ
		//l1.erase(it);
		//++it;���������������������ʧЧ

		/*������ô�޸�*/
		//it = l1.erase(it);//eraseɾ��֮�󣬷�����һ��λ�õĵ�����
		l1.erase(it++);//Ҳ������ôд���൱��it = l1.erase(it);
	}
}
int main()
{
	test9();
	return 0;
}
//1.��ӡ������������const(��ֹ�������޸�)������(���ٿ��������Ĵ���)
//2.C++11�п�����auto�����Ǵ���Ŀɶ��Խ���
//3.reference ����value_type������
//4.vector��insert��erase����������ʧЧ()
//5.list��insert����ʧЧ(����������)��eraseҲ�����ʧЧ(1-2-3,ɾ��2,1-3�������������Ұָ��)
//splice �ƻ���ľ
//unique ȥ��(��������ȥ��)
//sort ����(�鲢����)
//merge �ϲ���������
//6.ģ�岻֧�ַ������(.hcpp����ģ��)
//Ĭ�ϵ�ϰ�ߣ���ʹ���޶�������ʹ��struct(Ĭ��public),ʹ���޶���ʹ��class(Ĭ��private)
//Vector(const Vector& v = T()),T()��һ����������
//���ʵ��˫������(˫���ͷѭ���������ͳһ��ʵ��)