#include <stdio.h>
int f(int x,int y)
{
   int n,m,t;
   if(x<y)
     {
        t=x;
        x=y;
        y=t;
      }
   m=x*y;
   n=x%y;
   while(n!=0)
       {
       x=y;
       y=n;
       n=x%y;
       }
  printf("最大公约数是:%d\n",y);
  return y;	
}
int g(int x,int y)
{
   int n,m,t,k;
   if(x<y)
     {
        t=x;
        x=y;
        y=t;
      }
   m=x*y;
   n=x%y;
   while(n!=0)
       {
       x=y;
       y=n;
       n=x%y;
       }
       k=m/y;
  printf("最小公倍数是:%d\n",k);
  return k;	
}
int inNumber()
{
	int z;
	scanf("%d",&z);
    while(z<0)
       {
        printf("请从新输入一个整数:\n");
        scanf("%d",&z);
        }
    return z;
}
int main()
{
 int a,b,c,d;
 a=inNumber();
 b=inNumber();
 c=f(a,b);
 d=g(a,b);
 printf("a=%d\tb=%d\nc=%d\td=%d\n",a,b,c,d);
 return 0;
}
