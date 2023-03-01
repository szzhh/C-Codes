#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void def(float a, float b)
{
     int i,n;
     float d=0.00001,s=0;          
     n=(b-a)/d;               
     for(i=0; i<n; i++)              
     s+=(((a+d*i)*(a+d*i)+2*(a+d*i)+1)+((a+d*(i+1))*(a+d*(i+1))+2*(a+d*(i+1))+1))*d/2.0;
     printf("定积分的值即图形的面积为：\n");
     printf("%f\n",s);
}
int main()
{
    def(0,3);
    getchar();
    return 0;
}
      