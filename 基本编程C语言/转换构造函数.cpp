#include<iostream>
using namespace std;
	class AB{
    int x; 
    char y;
    public:
       void show()
       {
       	cout<<x<<" "<<y<<endl;
       }
    	AB(char m){
            x=1;
			y=m;
        }
       	AB(int n){ 
            x=n;
            y='y';
		}
};
main()
{
  AB rtemp=2; 
  AB tmp='z';
  rtemp.show();
  tmp.show();	
}
