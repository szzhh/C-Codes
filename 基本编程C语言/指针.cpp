#include<iostream>
using namespace std;
class CPerson
{
public:
void Print();
CPerson(int age,char *name);
private:
int age;
char *name;
};
CPerson::CPerson(int age,char *name)
{
this->age = age;
this->name = name;
}
void CPerson::Print()
{
 cout<<"name="<<*name<<",age="<<age<<endl;
}
main()
{
CPerson ps(23,"lisi");
ps.Print();
}
