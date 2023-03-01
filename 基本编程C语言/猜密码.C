#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int number=rand()%11+10;
int a;
int count=1;
	do
	{
		printf("输入一个10-20之间的整数（这是你第%d次输入）：\n",count); 
		scanf("%d",&a);
		count++;
		if(a==number)
		{
		printf("right!\n"); 
	    break;
		}
		else printf("wrong!\n");
	}
		while (count<=5);
		if(a!=number)
		printf("fall!");
		return 0;
}