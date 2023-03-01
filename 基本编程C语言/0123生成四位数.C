#include<stdio.h>
int main()
{
	int a,b,c,d,n=0;
		printf("The number is:\n");
	for(a=1;a<=3;a++)
	for(b=0;b<=3;b++)
	for(c=0;c<=3;c++)
	for(d=0;d<=3;d++)
	if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
		{
	    printf("%d%d%d%d\t",a,b,c,d);
	    n++;
	    if(n%6==0)
    	printf("\n");
     }
     printf("There are %d number\n",n);
   return 0;
}












