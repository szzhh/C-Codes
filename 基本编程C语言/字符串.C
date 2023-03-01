#include<stdio.h>
int main() 
{
	char a[80];
	char b[80];
	int m=0,n=0,i=0,j=0,t=0,c,d;
	printf("输入第一个字符串:"); 
	gets(a);
	while(a[m]!='\0')
	{
	m++;
	if(a[m]>='a'&&a[m]<='z')
	i++;j=m-i;
	}
	printf("字符串长度为:%d\n",m);
	printf("小写字母个数为:%d\n",i+1);
	printf("大写字母个数为:%d\n",j-1);
	
	printf("输入第二个字符串:");
	gets(b);
    while(a[t]==b[t]&&a[t]!='\0')
	t++; 
    if (a[t]=='\0'&&b[t]=='\0') 
     printf("这两个字符串相同即: %s=%s\n",a,b); 
    else 
	{
      if(a[t]>b[t])
       printf("这两个字符串不同即: %s>%s\n",a,b); 
       else 
       printf("这两个字符串不同即: %s<%s\n",a,b);
    }

	while(b[n]!='\0')
	n++;
	for(c=m,d=0;d<=n+1;c++,d++)
	{
	a[c]=b[d];
	}
	printf("\n两个字符串连在一起为:");
	puts(a);
	return 0; 
}