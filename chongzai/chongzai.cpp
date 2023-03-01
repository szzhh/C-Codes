#include<iostream>
using namespace std;
class three_d
{
    int x, y, z;
public:
    three_d  operator + ( three_d);
    three_d  operator = (three_d);
    friend three_d operator  ++ (three_d&,int );
    void show ( );
    void assign (int, int, int);
};
three_d three_d::operator + (three_d t)
{
    three_d temp;
    temp.x = x + t.x;
    temp.y = y + t.y;
    temp.z = z + t.z;
    return temp;
}
three_d three_d::operator = (three_d t)
{
    x = t.x;    y = t.y;    z = t.z;
    return * this;
}

// жидиЁБ++ЁБ
three_d operator ++ (three_d& t,int )
{
    t.x++;    t.y++;    t.z++;
    return t;
}
void three_d::show()
{
    cout << x << "," << y << ","<< z << endl;
}
void three_d::assign (int mx, int my, int mz)
{
    x = mx;
    y = my;
    z = mz;
}
main()
{
    three_d a, b, c;
    a.assign (1, 2, 3);
    b.assign (10, 10, 10);
    a.show( );
    b.show( );
    c = a + b; c.show( );
    c = a + b + c; c.show( );
    c = b = a; c. show( ); b.show( );
    c++; c.show( );
}
