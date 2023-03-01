#include<stdio.h>
void NN(int *p,int n)
{
int i,j,sum1=0,sum2=0;
int a[n][n];
printf("矩阵为:\n");
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
 a[i][j]=*p++;
 printf("%d  ",a[i][j]);
 }
 printf("\n");
}
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 {
if(i==j)
sum1+=a[i][j];
if(i+j==n-1)
sum2+=a[i][j];
 }
printf("主对角线元素和为:%d\n副对角线元素和为:%d\n",sum1,sum2);
}
int main()
{
int b[3][3]={1,7,3,6,5,2,4,8,5};
int *q;
q=&b[0][0];
 NN(q,3);
return 0;
}
