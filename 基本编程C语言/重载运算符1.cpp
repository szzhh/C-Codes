#include<iostream>
using namespace std;
class Com
{    
    double Re, Im; 
public:
    Com( double r, double i) 
    { Re = r; Im = i; }
    Com( ) { Re = 0; Im =0; }
    Com(const Com&c) 
    {
     Re = c.Re;   Im = c.Im; 
	 cout<<"hello!"<<endl;	
    }
    Com operator +(Com);
    Com operator -(Com);
    Com operator =(Com);
    void show_Com( );
};
Com Com::operator +( Com c)
{
    Com tmp;
    tmp.Re = Re + c. Re;
    tmp.Im = Im + c.Im;
    return tmp;
}
Com Com::operator -( Com c)
{
    Com tmp;
    tmp.Re = Re -c. Re;
    tmp.Im = Im -c.Im;
    return tmp;
}
Com Com::operator = (Com c)
{
    Re = c.Re;   Im = c.Im; 
    cout<<"world"<<endl;
    return *this;
}
void Com::show_Com( )
{
    cout << Re <<"+" << Im  << "j" << endl;
}
main()
{    
    Com obj1(1, 2), obj2(2,3);
     obj1.show_Com();
    obj2.show_Com();
    Com obj3 = obj1+obj2;
    obj3.show_Com();
    Com obj4 = obj3-obj2;
    obj4.show_Com();
    Com obj5;
    obj5.show_Com();
    Com obj6=obj5=obj3;
    obj6.show_Com();
}
