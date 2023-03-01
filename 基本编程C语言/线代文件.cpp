#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream f1,f2;
    int i,j,k,a[5][5];
    
      f1.open("f1.txt");
    if(!f1) {
        cout << "文件1打开失败" << endl;
        return 1;
    }
    f2.open("f2.txt");
    if(!f2) {
        cout << "文件2打开失败" << endl;
        return 2;
    }
    
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            f1>>a[i][j];
            f2<<a[i][j]<<" ";
        }
        f2<<endl;
    }
    
    f2<<"其转置矩阵为："<<endl;
    for(i=0,k=1; i<5; i++)
        for(j=0; j<5; j++) {
            f2<<a[j][i]<<"  ";
            if(k%5==0)
            f2<<endl;
            k++;
        }
    f1.close();
    f2.close();
    return 0;
}
