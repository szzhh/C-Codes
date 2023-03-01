#include <stdio.h>
#include <stdlib.h>

int main()
{
char a,b,c,d;
for(;d!='n';)
{
printf("please input a char:\n");
scanf("%s",&a);
switch(a)
{
case 'J':
{
printf("Jan,Jun or Jul\nplease input second char:\n");
scanf("%s",&b);
if(b=='a')printf("Jan");
if(b=='u')
{
printf("Jun or Jul\nplease input third char:\n");
scanf("%s",&c); if(c=='n')printf("Jun");
if(c=='l')printf("Jul");
}
break;
}
case 'F':printf("Feb");break;
case 'M':
{printf("Mar or May\nbecause the second chars are same\nplease input third char:\n");
scanf("%s",&b);
if(b=='r')printf("Mar");
if(b=='y')printf("May");
break;}
case 'A':
{
printf("Apr or Aug\nplease input second char:\n");
scanf("%s",&b);
if(b=='p')printf("Apr");
if(b=='u')printf("Aug");
break;
}
case 'S':printf("Sep");break;
case 'D':printf("Dec");break;
case 'O':printf("Oct");break;
case 'N':printf("Nov");break;
default:printf("error");
}
printf("\ncontinue yes or no:\n");
scanf("%s",&d);

}
}
