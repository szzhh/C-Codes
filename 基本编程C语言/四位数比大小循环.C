 #include<stdio.h>
#include<conio.h>
int main()
{
float a,b,c,d,max;
char ch='y';
while(ch=='y'||ch=='Y')
{
printf("请输入四位数：\n");
scanf("%f%f%f%f",&a,&b,&c,&d);
max=a;
if(max<b)
max=b;
if(max<c)
max=c;
if(max<d)
max=d;
printf("最大的数值为：%f\n",max);
printf("Do you want to continue(Y/N)\n");
getchar();
scanf("%c",&ch);
}
return 0;
}