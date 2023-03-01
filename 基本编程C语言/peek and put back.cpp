#include <iostream>
using namespace std;
int main( )
{
     char c[20];     int ch;
     cout<<"please enter a sentence:"<<endl;
     cin.getline(c,15,'/');
     cout<<"The first part is: "<<c<<endl;
     ch=cin.peek( );//观看当前字符
     cout<<"The next character(ASCII code) is: "<< ch <<endl;
     cin.putback(c[0]);             //将′I′插入到指针所指处 
     cin.getline(c,15,'/');
     cout<<"The second part is: "<<c<<endl;
    return 0;
}
