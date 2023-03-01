#include<iostream>
using namespace std;
class M {
    int a;
public:
    M(int t) { a = t; }
    int geta() { return a; }
};
class N {
    int a, b;
    const int c;
    int &d;
    M m1;
public:
    N(int t) : m1(++t), d(b), c(++t), a(++t) {
        b = 2 * t;
    }
    void print() {
        cout << "m1.a = " << m1.geta() << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
    }
};
int main()
{
    N n1(1);
    n1.print();
    return 0;
}