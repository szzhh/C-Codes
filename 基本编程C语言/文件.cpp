#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream outfile;
    char ch;
    outfile.open("filel.txt");
    if(!outfile) {
        cout << "文件打开失败" << endl;
        return 1;
    }
    cout << "请输入一串字符串" << endl;
    do {
        cin.get(ch);
        if(ch!='#')outfile<<ch;
    }
    while(ch!='#');
    outfile<<"#";
    return 0;
}
