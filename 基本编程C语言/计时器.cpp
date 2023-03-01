#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
int main(void)
{
time_t t_start,t_end;
t_start = time(NULL) ;
cout<<"计时已经开始，按Enter键暂停计时！！"<<endl;
getch();
t_end = time(NULL) ;
cout<<"时长为："<<difftime(t_end,t_start)<<"s"<<endl;
return 0;
}
