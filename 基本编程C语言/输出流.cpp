#include <iostream>
#include <iomanip>//不要忘记包含此头文件
using namespace std;
 main()
{  int a = 34;    char *pt="China";    double pi=22.0/7.0;
    cout << "dec:" << dec << a << endl; //十进制形式输出
    cout << "hex:" << hex<< a << endl;//十六进制形式输出
    cout << "oct:" << setbase(8) << a << endl;//八进制形式输出
    cout << setw(10) << pt << endl; //指定域宽为10，输出字符串
    cout << setfill('*') << setw(10) << pt << endl; //指定域宽10，
                                                   // 输出字符串，空白处以′*′填充
     cout << setiosflags(ios::scientific) << setprecision(8); //按指数
                                                   //形式输出，8位小数
     cout << "pi=" << pi << endl;    //输出pi值
     cout << "pi=" << setprecision(4) << pi << endl;//改为4位小数
     cout << "pi=" << setiosflags(ios::fixed) << pi << endl;
                                                       //改为小数形式输出

}
