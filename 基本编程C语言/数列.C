#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
main()
{
int a[5][5],i,j,temp[1][5],max,x,y;
srand((unsigned)time(NULL));
for(i=0;i<5;i++)
{ 
    for(j=0;j<5;j++)
    a[i][j]=rand()%100;
} 
for(i=0;i<5;i++)
{
     for(j=0;j<5;j++)
     { 
      printf("%d\t",a[i][j]);
     } 
    printf("\n");
}
for(j=0;j<5;j++)
{
temp[0][j]=a[0][j];
a[0][j]=a[4][j];
a[4][j]=temp[0][j];
}
printf("\n");
for(i=0;i<5;i++)
{
     for(j=0;j<5;j++)
     { 
      printf("%d\t",a[i][j]);
     } 
printf("\n");
}
for(i=0;i<5;i++)
{
	max=a[i][0];
    for(j=0;j<5;j++)
   {
    if(a[i][j]>max)
    max=a[i][j];
   }
     for(j=0;j<5;j++)
     {
      if(max==a[i][j])
      printf("\n换行后第%d行最大值为该行第%d列的：a[%d][%d]=%d\n",i+1,j+1,i,j,max);
     }
}
}







	