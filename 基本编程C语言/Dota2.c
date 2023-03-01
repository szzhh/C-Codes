#include<stdio.h>
#include<string.h>
void J1(char* B1)
{
	char C1[]="WWW";
	if(!strcmp(B1,C1))
	printf("EMP\n");
} 
void J2(char* B2)
{
	char C2[]="QWW";
	if(!strcmp(B2,C2))
	printf("Tornado\n");
} 
void J3(char* B3)
{
	char C3[]="WWE";
	if(!strcmp(B3,C3))
	printf("Alacrity\n");
} 
void J4(char* B4)
{
	char C4[]="QQW";
	if(!strcmp(B4,C4))
	printf("Ghost Walk\n");
} 
void J5(char* B5)
{
	char C5[]="QWE";
	if(!strcmp(B5,C5))
	printf("Deafening Blast\n");
} 
void J6(char* B6)
{
	char C6[]="WEE";
	if(!strcmp(B6,C6))
	printf("Chaos Meteor\n");
} 
void J7(char* B7)
{
	char C7[]="QQQ";
	if(!strcmp(B7,C7))
	printf("Cold Snap\n");
} 
void J8(char* B8)
{
	char C8[]="QQE";
	if(!strcmp(B8,C8))
	printf("Ice Wall\n");
} 
void J9(char* B9)
{
	char C9[]="QEE";
	if(!strcmp(B9,C9))
	printf("Forge Spirit\n");
} 
void J10(char* B10)
{
	char C10[]="EEE";
	if(!strcmp(B10,C10))
	printf("Sun Strike\n");
} 
int main()
{
	char A[100],B[4]="";
	int i,L,n=0;
	for(i=0;i<1000000;i++)
	{
		A[i]=getchar();
		getchar();
		L=strlen(B);
		switch(A[i])
		{
			case 'Q': n++;
			if(L==0) B[0]='Q';
			else if(L==1) B[1]='Q';
			else if(L==2) B[2]='Q';
			else if(L==3) {B[(n-1)%3]='Q';}
			break;
			case 'W': n++;
			if(L==0) B[0]='W';
			else if(L==1) B[1]='W';
			else if(L==2) B[2]='W';
			else if(L==3) {B[(n-1)%3]='W';}
			break;
			case 'E': n++;
			if(L==0) B[0]='E';
			else if(L==1) B[1]='E';
			else if(L==2) B[2]='E';
			else if(L==3) {B[(n-1)%3]='E';}
			break;
			case 'R':
			if(L<3) printf("FFFFFFFX\n");
			else if(L==3)
			{
				J1(B); J2(B); J3(B); J4(B); J5(B);
				J6(B); J7(B); J8(B); J9(B); J10(B);
			} 
			break;
		}
	} 
	return 0;
}
