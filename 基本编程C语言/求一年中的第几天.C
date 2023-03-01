#include<stdio.h>
int leap(int a)										
{
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)				
        return 1;									
    else
        return 0;							
}
int days(int year, int m, int d) 
{
    int sum = 0, i, a[12] =
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};									
    int b[12] =
    {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };											
    if (leap(year) == 1)			
        for (i = 0; i < m - 1; i++)
            sum += b[i];		
    else
        for (i = 0; i < m - 1; i++)
            sum += a[i];					
    sum += d;										
    return sum;							
}
int main()
{
    int year, month, day, n;						
    printf("请输入年月日\n");
    scanf("%d%d%d", &year, &month, &day);
    n = days(year, month, day);							
    printf("第%d天\n",n);
}

