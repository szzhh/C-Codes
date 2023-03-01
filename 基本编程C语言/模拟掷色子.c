#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int number,n,a=0,b=0,c=0,d=0,e=0;
float a1,b1,c1,d1,e1;
for(n=1;n<=10000000;n++)
{
	number=rand()%5+1;
	switch(number)
	{
	case 1:a++;break;
	case 2:b++;break;
	case 3:c++;break;
	case 4:d++;break;
	case 5:e++;break;
	}
}
a1=(float)a/n;
b1=(float)b/n;
c1=(float)c/n;
d1=(float)d/n;
e1=(float)e/n;
printf("%f\n%f\n%f\n%f\n%f\n",a1,b1,c1,d1,e1);
return 0;
}
