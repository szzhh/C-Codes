#include<iostream>
using namespace std;
class CExample
{
private:
    int a;
public:
    //构造函数
    CExample(int b)
    {
        a = b;
        printf("constructor is called\n");
    }
    //拷贝构造函数
    CExample(const CExample& c)
    {
        a = c.a;
        printf("copy constructor is called\n");
    }
    //析构函数
    ~CExample()
    {
        cout << "destructor is called\n";
    }
    void Show()
    {
        cout << a << endl;
    }
};
CExample g_fun()
{
    CExample temp(0);
    return temp;
}
int main()
{

    CExample p=g_fun();
    p.Show();
    return 0;
}
