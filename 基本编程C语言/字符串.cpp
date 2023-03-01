#include <iostream>
using namespace std; 
class CPerson
{
public: 
void Print();
CPerson(int,string);
int age;
string name;
};
CPerson::CPerson(int a,string b)
{ age=a;name=b; } 
void CPerson::Print()
{
       cout<<"name="<<name<<",age="<<age<<endl;
} 
int main()
{
       CPerson ps(23,"lisi");
       ps.Print();
       return 0;
}
