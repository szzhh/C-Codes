#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int x) 
{
 int i; double b;
 b = sqrt(x);
 for (i = 2; i <= b; i++)
  if (x%i == 0) break;
 if(i>b)
  return true;
 else
  return false;
}
int main()
{
 int i = 101, k = 0;
 for (; i <= 200; i++)
 {
  if (isprime(i))
  {
   cout << i << '\t';
   k++;
  if (k % 8 == 0)
   cout << endl;
  }
 }
 return 0;
}
