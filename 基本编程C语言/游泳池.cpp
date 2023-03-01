#include <iostream>
#include <cmath>
using namespace std;
const double pi(3.14);
class pool{
private:
	double r;//半径
public:
	pool(double rr){r=rr;}
	double getPeri();//求周长
	double getArea();
 
};

double pool::getPeri(){
	return 2*pi*r;
}
double pool::getArea(){
	return pi*(r*r-(r-5)*(r-5));
}
int main (){
	double r;
	cout<<"输入半径:"; 
	cin>>r;
	pool po(r+5);
	cout<<"栅栏造价="<<po.getPeri()*50<<endl;
	cout<<"过道造价="<<po.getArea()*150<<endl;
	return 0;
}
