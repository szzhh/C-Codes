#include<iostream>
using namespace std;
class Increment
{   const int increment;
    int count;
public:
    Increment( int, int);
    void show()
    {
    	cout<<increment<<" "<<count<<endl;
    }
};
Increment::Increment( int c=0, int i=1)
    :increment( i )     //初始化常成员数据increment
{  count = c; }

main()
{
	Increment i;
	i.show();
	
}
