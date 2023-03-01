#include<stdio.h>
#include<conio.h>
int main()
{
	int n=0;
   char a[20];
   char ch='y';
   while(ch=='y'||ch=='Y')
   {
	printf("请输入字符:\n");
   scanf("%c",&a[n]);
   if(a[n]>='a'&&a[n]<='z')
   		printf("这是一个小写字母\n");
   		else if(a[n]>='A'&&a[n]<='Z')
   			printf("这是一个大写字母\n");
   				else if(a[n]>='0'&&a[n]<='9') 
   					printf("这是一个数字\n");
   						else printf("其他\n");
   n++;
   printf("continue (Y OR N)?\n");
   getchar(); 
   scanf("%c",&ch);
   getchar(); 
   }
   return 0;
}
