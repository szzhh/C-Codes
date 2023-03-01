#include<iostream>
using namespace std;
class Com
{    
    double Re, Im; 
public:
    Com( double r=0, double i=0) 
    { Re = r; Im = i; }
    friend Com operator + ( Com,Com);
    void show()
    {
    	cout<<Re<<","<<Im<<endl;
    }
};
Com operator +( Com c1, Com c2)
{
    Com tmp;
    tmp.Re = c1.Re + c2.Re;
    tmp.Im = c1.Im + c2.Im;
    return tmp;
}

main()
{    
    Com Z(1, 2);
    Z.show();
    Z = Z + 27;  
    Z = 27 + Z;  
    Z.show();
}
