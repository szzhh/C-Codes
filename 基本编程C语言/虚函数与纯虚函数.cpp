#include<iostream>
using namespace std;
class Virtualbase
{
public:
    virtual void Demon()=0;//prue virtual function
    virtual void Base() { cout << "this is farther class!" << endl; }
};
//sub class
class SubVirtual :public Virtualbase
{
public:
    void Demon() {
        cout << "this is SubVirtual!" << endl;
    }
        void Base() {
            cout << "this is subclass Base!" << endl;
        }
    };
 main()
{
       Virtualbase* inst = new SubVirtual(); //multstate pointer
        inst->Demon();
        inst->Base();
       //Virtualbase* inst1= new Virtualbase();
        //inst1->Base();
        system("pause");
}
