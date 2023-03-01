#include<stdio.h>
#include<conio.h>
#include<dos.h>
main()
{
char c1;
struct date d;
clrscr();
getdate(&d);
printf("\t\t%d/%d/%d",d.da_year,d.da_mon,d.da_day);
printf("\n*************\n");  
printf("*Menu*\n");
printf("*1.Input*\n");
printf("*2.Output*\n");
printf("*3.End*\n");
printf("*************\n");
printf("Enter Number=>\n");
printf("Ch=---------->");
gotoxy(20,8);
c1=getch();
gotoxy(20,8);
putchar(c1);
gotoxy(9,9);
putchar(c1);
gotoxy(20,9);
printf("%d",c1);
} 