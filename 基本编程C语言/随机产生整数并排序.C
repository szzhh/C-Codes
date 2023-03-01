#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void order(int *p)
{
	int a[20],i,j,n,itemp;
	printf("排序前为:\n");
	for(n=0;n<20;n++)
	{
		a[n]=*p++;
		printf("%d\t",a[n]);
		if((n+1)%5==0)
  			printf("\n");
	}
	
	for(i=1;i<=19;i++) 
  {
  	for(j=0;j<20-i;j++)
  	{
	  	if(a[j]>a[j+1])
	  	{
	  		itemp=a[j];
	  		a[j]=a[j+1];
	  		a[j+1]=itemp;
	  	}
	  }
  }
  printf("排序后为:\n");
  for(n=0;n<20;n++)
	{
		printf("%d\t",a[n]);
		if((n+1)%5==0)
  			printf("\n");
	}

}
int main()
{
	int b[20],*q,k;
	srand((unsigned)time(NULL));
	for(k=0;k<20;k++)
	{
		b[k]=rand();
	}
	q=&b[0];
	order(q);
	return 0;
}
