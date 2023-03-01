#include <iostream>
using namespace std;
class counter
{    
    unsigned int value;
public:
    counter( ) { value = 0; }
    counter operator++(int);
    void operator--();
    unsigned int operator()();
    friend void show(counter t)
    {
    	cout<<t.value<<endl;
    }
};
counter counter::operator++(int m)
{
	counter temp=*this;
    if (value < 65535) 
	value++; //此处++还是原先的含义
	return temp;
}
void counter::operator--()
{
    if (value > 0) 
	value--; //此处- -还是原先的含义

}
unsigned int counter::operator()()
{
    return value;
}
main()
{
    counter my_counter;
    for( int i=0;i<6;i++)
    {
        show(my_counter++);
        
        cout << "my_counter = "  << my_counter() << endl;
    }
    --my_counter;
    cout << "my_counter = " <<my_counter() << endl;
}
