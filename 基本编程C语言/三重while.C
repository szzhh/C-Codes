#include<stdio.h>
#include<time.h>
#include<conio.h>
main()
{
clock_t start,end;
start=clock();

int a,b,c,x,y,n; 
a=1,b=1,c=2,n=0;
while(a<33)
{
  while(b<50)
  {
  	while(c<100)
	  {
  		x=a+b+c;y=3*a+2*b+c/2;
		  if(x==100&&y==100)
		  n++,printf("a=%d,b=%d,c=%d\n",a,b,c),c+=2;
		  else c+=2;	   
  	} 
  	b++;c=2; 
  }	 
  a++;b=1;
}
printf("The num of method1 is:%d\n",n);

end=clock();
printf("and the time is:%5.1ftime\n",difftime(end,start));
}