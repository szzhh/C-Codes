#include<stdio.h>
#include<time.h>
#include<conio.h>
main()
{
clock_t start,end;
start=clock();

int a,b,c,x,y,n; 
n=0;
for(a=0;a<33;a++)
{
  for(b=0;b<50;b++)
  {
  	for(c=0;c<100;c+=2)
	  {
  		x=a+b+c;y=3*a+2*b+c/2;
		  if(x==100&&y==100)
		  n++,printf("a=%d,b=%d,c=%d\n",a,b,c);	   
  	}  
  }	 
}
printf("The num of method1 is:%d\n",n);

end=clock();
printf("and the time is:%5.1ftime\n",difftime(end,start));
}
