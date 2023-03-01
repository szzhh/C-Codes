#include <iostream>
using namespace std;
class time
{
public:
time() //constructor.构造函数
{
hour=0;
minute=0;
sec=0;
}
time(const time &obj)  //拷贝构造函数
{
hour = obj.hour;
minute = obj.minute;
sec = obj.sec;
}
time& operator=(const time &obj)  //运算符重载，用来完成赋值函数
{
this->hour = obj.hour;
this->minute = obj.minute;
this->sec = obj.sec;
return *this;
}
void set_time();
void show_time();
private:
int hour;
int minute;
int sec;
};
int main()
{
class time t1;  //调用time()构造函数为成员赋初值
t1.show_time();
t1.set_time();
t1.show_time();
class time t2=t1;   //调用拷贝构造函数，为对象t2赋值
t2.show_time();
class time t3;
t3=t1;  //调用运算符重载=函数，为对象t3赋值
t3.show_time();
return 0;
}
void time::set_time()
{
cin >>hour;
cin >>minute;
cin >>sec;
}
void time::show_time()
{ 
cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
