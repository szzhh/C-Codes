#include<iostream>
using namespace std;
 int f(int i)
 {	
 char m;
 if(i>15) f(i/16);
 if((m=i%16+'0')>0x39) m+=7;
  cout<<m;
 }
main()
{
	int n;
	cout<<"输入一个十进制的数：";
	cin>>n;
	cout<<"转换为十六进制为：";
	f(n);
	cout<<endl; 
}
