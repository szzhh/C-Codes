#include <iostream>
using namespace std;
int main( )
{   char ch[20];
     cin.get(ch,20,'/');
     cout<<"The first part is:"<<ch<<endl;
     cin.ignore( );//跳过输入流中一个字符
     cin.get(ch,20,'/');
     cout<<"The second part is:"<<ch<<endl;
     cin.ignore( );//跳过输入流中一个字符
     cin.get(ch,20,'/');
     cout<<"The third part is:"<<ch<<endl;
     return 0;
}
