#include<iostream>
using namespace std;
class A
{ public:
    A() { cout << "A的构造函数" << endl; }
    virtual ~A()   { cout << "A的析构函数" << endl; }
};
class B:public A
{ public:
    B() { cout << "B的构造函数" << endl; }
    ~B() { cout << "B的析构函数" << endl; }
};
main()
{   A *Ap = new B;	
    B *Bp2 = new B;
    delete Ap;
    delete Bp2;
}
