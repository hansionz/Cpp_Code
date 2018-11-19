#include "Date.h"

int main()
{
	Date d1(2018, 11, 14);
	Date d2(d1);
	Date d3;
	d3 = d1;
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;

	/*Date d1(2018, 10, 29);
	d1.Print();
	d1 += 3;
	d1.Print();
	Date d2(2018, 10, 27);
	d2 -= 12;
	d2.Print();
	Date ol(2018, 10, 27);
	Date o2(1998, 3, 6);
	int ret = ol - o2;
	cout << ret << endl;*/
	//Date d(2018, 11, 13);
	//std::cout << d << std::endl;
	/*Date d1;
	cin >> d1;
	cout << d1 << endl;*/
}