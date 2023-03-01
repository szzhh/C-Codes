#include <iostream>
using namespace std;
class counter
{
public:
    unsigned int value;
    counter() { value = 0; }
    void operator++();
    void operator--();
    unsigned int operator()();
};
void counter::operator++()
{
    if (value < 65535)
        value++; //此处++还是原先的含义
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
int main()
{
    counter my_counter;
    for (int i = 0;i < 6;i++)
    {
        my_counter.value++;
        cout << "my_counter = " << my_counter() << endl;
    }
    my_counter.value--;
    cout << "my_counter = " << my_counter() << endl;
    return 0;
}
