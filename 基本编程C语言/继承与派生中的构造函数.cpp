#include<iostream>
using namespace std;
class A
{   int pri;
public:
    int pub;
    A( )  { cout << "A的构造函数" << endl; }
    void set_pri(int i) { pri = i; }
    void set_pub(int j) { pub = j;}
    void print_pri( )
    {   cout << pri << " "; }
};
class B : public A
{    
    int pri1;
public:
    int pub1;
    B( )  { cout << "B的构造函数" << endl; }
    void set_pri1(int i) { pri1 = i; }
    void set_pub1(int j) { pub1 = j;}
    void print( )
    {   cout << pub << " " << pri1 << " " << pub1 << " "; 
    }
};
main( )
{   A objA;
    objA.set_pri(1);
    objA.set_pub(2);
    objA.print_pri( ); 
    cout << endl;
    B objB;
    objB.set_pri(3);
    objB.set_pub(4);
    objB.set_pri1(5);
    objB.set_pub1(6);
    objB.print_pri( );
    objB.print( );
    cout << endl;
    objB.pub = 7;
    objB.pub1 = 8;
    objB.print( );
}
