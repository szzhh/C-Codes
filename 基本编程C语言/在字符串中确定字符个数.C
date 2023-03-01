#include<stdio.h>
#include<stdlib.h> 
main()
{   int compare(char a[],char b,int *q);
	char str[10],xch;int *p,c,a[10]={},b='Y';p=&a[0];
	do
	{printf("请输入字符串:"); 
	scanf("%s",str);
	printf("请输入想查找的字母:");
	getchar();
	scanf("%c",&xch);
	c=compare(str,xch,p);
	if(c==0)printf("\n该字符串没有与%c相同的字母\n",xch);
	else
	 {
	 printf("该字符串中与%c相同的地方有%d处\n分别为:",xch,c);
	for(int i=1;i<=c;i++)
	printf("第%d处\t",*p),p++;
	}
    printf("\n是否继续,Y or N?\n");
    getchar();
	scanf("%c",&b);
	system("cls");}while(b=='Y'||b=='y');
} 
int compare(char a[],char b,int *q)
{   int n=0;
    for(int i=0;a[i]!='\0';i++)
    if(b==a[i])n++,*q=(i+1),q++;
    return n;
}
