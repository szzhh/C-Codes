#include<stdio.h>
int main()
{
	int a,n=0;
	for(a=0;a<20;)
	{
		n++;
		a+=3;
		if(a>=20)
		break;
		a-=1;
	}
	printf("%d",n);
	return 0;
}


   