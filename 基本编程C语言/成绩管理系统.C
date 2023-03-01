#include<stdio.h>
 int main()
{
    float a;
    int b;
    scanf("%f",&a);
    if(a>100||a<0)
    { 
      printf("wrong score!\n");
      return 0; 
      } 
    b=a/10;
    switch(b)
		{
        case 10:  
        case 9:printf("excellent!\n");break; 
        case 8:printf("very good!\n");break;  
        case 7:printf("good!\n");break;  
        case 6:printf("not bad!\n");break;  
        default:printf("bad!\n");  
    }  
   return 0;
} 