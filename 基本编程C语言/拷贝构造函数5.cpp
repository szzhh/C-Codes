#include<iostream>
using namespace std;
class  X
{
    int a, b, c;
public:
    X(){a = 1; b = 1, c = 1;}
    X(const X & p) 
    {
        a = p.a; b = p.b; c = p.c;
        cout << "sum = " << a+b+c << endl;
    }
};
X f(X arg)
{
    return(arg);
}
int main( )
{
    X x1;
    X x2 = f(x1);//¿½±´Á½´Î 
    return 0;
}
