#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
    string  username;
    string  password;
    char  a[20];
    do{
        cout  <<"用户名：";
        getline(cin,username,'\n');
        cout  <<"密码：";
        int z;
        for(z=0;z<20;z++)
        {
            a[z]=getch();     
            if (a[z] == 13) //响应回车
            {
                break;
            }
            else if (a[z] == '\b')  //响应退格键
            {
                if (z == 0) //如果当前已经没有字符，则直接跳出
                {
                    continue;
                }
                //屏幕上删掉的字符填成空格，并回退光标
                cout << "\b";
                cout << " ";
                cout << "\b";
                //将数组响应位置填成0
                z--;
                a[z] = 0;
                //将i往前置一位，因为接下来会执行for循环的i++
                z--;
                //清空输入缓冲，避免回车等其他字符捣乱
                cin.clear();
            }
            else
            {
                cout  << "*";
            }
        }
        cout << endl;
        //a字符串结尾，并赋给password
        a[z] = 0;
        password = a;
 
        if(username=="sunzhonghao" && password=="szh123")
            cout <<"登陆成功！" << endl;
        else
            cout  <<"用户名或密码错误请重新输入"<< endl;
    }
    while(username!="sunzhonghao" || password!="szh123");
}
