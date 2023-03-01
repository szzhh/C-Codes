#include<iostream>
using namespace std;
class  X
{
    int m, n;
public:
    X( int a, int b) { m = a; n = b;}
    X( const X & objX) { m = objX.m; n = objX.n; }
    void show()
	{
		cout<<m<<' '<<n<<endl;
	} 
};
main ( )
{
    X  a(1, 2);	     // 调用构造函数X(int, int)
    X  b(a);           // 调用构造函数X(const X &)
    X  c = b;         // 调用构造函数X( const X &)
    a.show();
    b.show();
    c.show();
}
