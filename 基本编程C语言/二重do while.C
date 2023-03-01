#include<stdio.h>
#include<time.h>
#include<conio.h>
int main()
{
	clock_t start,end;
	start=clock();
	
  int a,b,n;
  a=0,b=0,n=0;
  float c,x;
do
{ a++;b=0;
  do
    { b++;c=100-(a+b);
      x=3*a+2*b+c/2;
      if(x==100)
      n++,
      printf("a=%d,b=%d,c=%1.0f\n",a,b,c);
     }while(b<50);
}while(a<33);
 printf("The num of method is:%d\n",n);
 
 end=clock();
 printf("and the time is%5.1ftime/n",difftime(end,start));
 return 0;
}
