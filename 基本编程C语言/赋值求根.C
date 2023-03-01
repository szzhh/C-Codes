#include <stdio.h>
#include <math.h>
int main()
{
double a,b,c;                                
double x1,x2,p;                             
printf("intput:a,b,c:");                    
scanf("%lf%lf%lf",&a,&b,&c);                 
printf("\n");                             
p=b*b-4*a*c;                          
x1=(-b+sqrt(p))/(2*a);                        
x2=(-b-sqrt(p))/(2*a);                          
printf("x1=%f,x2=%f\n",x1,x2);                  
}
