#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
void def(float a,float b,int n)
{
 int i;
 float d,s=0;
 d=(b-a)/n;
 for(i=0;i<n;i++)
  s+=(sin(a+d*i)+sin(a+d*(i+1)))*d/2.0;
  printf("所求函数的数值定积分为: "); 
 printf("%f",s);
}
int main()
{
 float x,y;
 int z;
 printf("请输入定积分的起点: "); 
 scanf("%f",&x);
 printf("请输入定积分的终点: "); 
 scanf("%f",&y);
 printf("请输入所分段数: "); 
 scanf("%d",&z);
 def(x,y,z);
 return 0;
}
