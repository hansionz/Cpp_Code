#include "Date.h"


int main()
{
	Date d1(2018, 10, 29);
	d1.Print();
	d1 += 3;
	d1.Print();
	Date d2(2018, 10, 27);
	d2 -= 12;
	d2.Print();
	Date ol(2018, 10, 27);
	Date o2(1998, 3, 6);
	int ret = ol - o2;
	cout << ret << endl;
}