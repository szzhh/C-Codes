#include<iostream>
using namespace std;
class AB{
    int x;
    char y;
    public:
    	AB(int a, char b):x(a), y(b){}
    	operator char(){
            return y;
        }
    	operator int(){
            return x;
        }
};
main ()
{
	int ans;
AB tmp(1,'a');
ans=1+tmp; 
cout<<ans<<endl;
}
