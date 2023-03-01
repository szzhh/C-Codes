#include<stdio.h>
int main() 
{
      int a,b,c,d,x,y;
      for(a=1;a<=9;a++)
      {
      for(b=0;b<=9;b++)
      {
      for(c=0;c<=9;c++)
      {
      for(d=0;d<=9;d++)
      {
      x=1000*a+100*b+10*c+d;
      y=a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d; 
      if(x==y)
       {
        printf("%d%d%d%d\t",a,b,c,d);
       }
      }
      }
      }
      }
  return 0;
}
