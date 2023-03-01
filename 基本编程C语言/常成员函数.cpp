#include<iostream>
using namespace std;
class R
{   int R1, R2;
public:
    R(int r1, int r2) { R1 = r1; R2 = r2; }
    void print() const ;
    void print();
};
void R::print() const { cout<<R1<<"-"<<R2<<endl; }
void R::print()
{ cout<<R1<<":"<<R2<<endl; }
main()
{  R a(2, 3);
    const R b(3, 4);
    a.print();   //调用void print();
    b.print();  //调用void print() const;
}
