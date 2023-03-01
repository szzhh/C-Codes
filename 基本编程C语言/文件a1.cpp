#include <fstream>
#include<iostream>
using namespace std;
int main( )
{      int a[10];
ofstream outfile("f1.dat", ios::out); //定义文件流对象，打开磁盘文件f1.dat
if(!outfile)                        //如果打开失败，outfile返回0值
{  cerr << "open error!" << endl;
   exit(1);
}
cout << "enter 10 integer numbers:"<<endl;
for(int i=0;i<10;i++)
{  cin >> a[i];    outfile << a[i] << " ";   //向磁盘文件″f1.dat″输出数据
}
outfile.close();           //关闭磁盘文件″f1.dat″
return 0;
} 
