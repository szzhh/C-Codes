#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void trans10to16(int a[],int b[5][1]) 
{
	int n;
	for(n=0;n<5;n++)
	{
		b[n][0]=a[n];
		printf("%d is translated to %x\n",a[n],b[n][0]);
	}
}
int main()
{
srand((unsigned)time(NULL));
int number[5];
int results[5][1];
int i;
for(i=0;i<5;i++)
{
	number[i]=rand()%65535;
}
printf("The results are:\n");
  trans10to16(number,results);
  return 0;
}


