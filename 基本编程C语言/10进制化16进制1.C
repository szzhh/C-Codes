#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void trans10to16(int *p,int *q) 
{
	static int n=0; 
    *q=*p;
	printf("%d is translated to %x\n",*p,*q);
	n++;
	if(n==5)
	return ;
	else
	trans10to16(p+1,q+1);
}
int main()
{
srand((unsigned)time(NULL));
int number[5];
int results[5][1];
int i,*a,*b;
for(i=0;i<5;i++)
{
	number[i]=rand()%65535;
}
a=&number[0];
b=&results[0][0];
printf("The results are:\n");
  trans10to16(a,b);
  return 0;
}
