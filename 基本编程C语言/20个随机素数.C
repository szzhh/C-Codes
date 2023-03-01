#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h> 
int main()
{
	int a[20],b,c,i,j,n,t;
srand((unsigned)time(NULL));	
	printf("这20个素数为:\n");
	for(n=0;n<20;)
	{
		i=rand()%98+2;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			break;
			else
			{
				if(j>sqrt(i)-1)
				{
					printf("%d\t",i);
					a[n]=i;
					n++;
					if(n%5==0)
					printf("\n");
				}
				else
				  continue;
			}
		}
	}
	printf("\n从小到大排列后为:\n");
	
    	for(b=1;b<20;b++)
	 {
 		for(n=0;n<20-b;n++)
 		{
		 	if(a[n]>a[n+1])
		 	{
			 t=a[n];
			 a[n]=a[n+1];
			 a[n+1]=t;
		 	}
		 	else continue;
		 }
 	}
	 
	for(n=0,c=0;n<20;n++)
	{
		printf("%d\t",a[n]);
		c++;
		if(c%5==0)
		printf("\n");
	}
	
	return 0;
}
