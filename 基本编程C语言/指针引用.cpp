#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	int* p1, * p2, * p3;
	cin >> a >> b >> c;
	p1 = &a;
	p2 = &b;
	p3 = &c;
	void exchange(int*&p1, int*&p2, int*&p3);
    void swap(int* p1, int* p2);
	exchange(p1,p2,p3);
	cout << "a=" << *p1 << endl << "b=" << *p2 << endl << "c=" << *p3 << endl;
	return 0;
}
void exchange(int*&p1, int*&p2, int*&p3)
{	
	if (*p1 < *p2)swap(p1, p2);
	if (*p1 < *p3)swap(p1, p3);
	if (*p2 < *p3)swap(p2, p3);
	cout << "a=" << *p1 << endl << "b=" << *p2 << endl << "c=" << *p3 << endl;
}
void swap(int*p1, int*p2)
{
	int temp;
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
}
