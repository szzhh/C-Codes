#include<iostream>
using namespace std;
class Time
{  
	int h, m;
public:
	Time()
	{h=m=0;}
	Time(int hh,int mm)
	{
		h=hh;
		m=mm;
	}
	Time operator+( Time &t) ;                             

//！！！！！！！！！！！！！！！！！！！！！
friend ostream & operator << ( ostream & os, Time t)

{
	os<<t.h<<":"<<t.m<<endl;
	return os;
}
};

//！！！！！！！！！！！！
Time Time::operator+(Time&t)
{
	Time sum;
	sum.m=m+t.m;
//！！！！！！！！！！！！！！！！！！！！！！
   if(sum.m>=60)
   sum.h=h+t.h+1;
   else
   {sum.h=h+t.h;}
   sum.m%=60;
if (sum.h>24)sum.h=sum.h-24;
	return sum;

}

int main()
{
	Time T1(3,40);
	Time T2(5,54);
	Time T3;
	T3=T1+T2;
	cout<<T3;
	return 0;
}
