#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<Windows.h>
#include<time.h>
#define HEIGHT 25
#define WIDE 45
   typedef struct
   {
      int x;
      int y;
      
  }Point;
  
  char direction='w';//���� 
  int point=0;//���� 
  
  void init(Point*snake,int bodyNum);//��ʼ�����趨��������� 
  void move(Point*snake,int *bodyNum);//
 void printSnake(Point * snake,int bodyNum);//��ӡ�� 
  char controlMove();//�����ƶ� 
  
  void change(Point*snake,int bodyNum);//�ı��ߵ����� 
 void clean(Point*snake,int bodyNum);//����Ļ�����֮ǰ���� 
  
  void printWall();//��ӡǽ�� 
  int isDead(Point*snake,int bodyNum);//�ж����Ƿ����� �Ƿ���1 �Ƿ���0 
  void food(Point*snake,int bodyNum);//�������ʳ�� 
  int eatFood(Point*snake,int *bodyNum);//�ж��Ƿ�Ե�ʳ�� �Ƿ���1 �Ƿ���0 
  
  void HideCursor();//���ع�� 
  void gotoxy (int x,int y);//���λ���ƶ���ָ�������� 
  
  void HideCursor()
  {
       CONSOLE_CURSOR_INFO cursor_info = {1, 0};
       SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
  }
  void gotoxy (int x,int y)
  {  
     HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos;
     pos.X=x;
     pos.Y=y;
     SetConsoleCursorPosition(handle,pos);
  }
  
  int main()
  {
      Point snake[64];//��ʾ��
      int bodyNum=6;//����ĸ���,��ʼ��6�� 
      srand(time(NULL));//����������� 
       
      HideCursor();
      init(snake,bodyNum);
      printWall();
      food(snake,bodyNum);
      printSnake(snake,bodyNum);
      
      while(1)
      {    
          move(snake,&bodyNum);
          Sleep(200-point);//����Խ���ٶ�Խ�� 
      }
          
  }
  
  void init(Point*snake,int bodyNum)
  {
      int i;
      snake[0].x=HEIGHT/2;
      snake[0].y=WIDE/2;
      for(i=1;i<bodyNum;i++)
      {        //����һ��ʼ�ڻ����м� 
              snake[i].x=HEIGHT/2+i;
              snake[i].y=WIDE/2;
      }    
  }
  
  void move(Point*snake,int *bodyNum)
  {    
      char dir=controlMove();//��ȡ�û�����İ��� 
      clean(snake,*bodyNum);//���֮ǰ���� 
      change(snake,*bodyNum);//ÿ���ƶ�ʱ���ı�����
      //�ı���ͷ������ 
      switch(dir)
      {
          case 'w':
              snake[0].y--;
              break;
          case 's':
              snake[0].y++;
              break;
          case 'a':
              snake[0].x--;
              break;
          case 'd':
              snake[0].x++;
              break;
         default:
             break;    
     }
     
     if(eatFood(snake,bodyNum))//����Ե�ʳ�� 
     {    
     
         if(point>100)
             point+=5; 
         else
             point+=10;
              
         food(snake,*bodyNum);//��������µ�ʳ�� 
     }
         
     printSnake(snake,*bodyNum);//��ӡ�µ��� 
     if(isDead(snake,*bodyNum))//������� 
     {
         gotoxy(WIDE,HEIGHT);
         printf("\n\n\nGAVE OVER");
         exit(0);//�˳���Ϸ 
     } 
 } 
 
 void printSnake(Point * snake,int bodyNum)
 {    
     int i;
     gotoxy(snake[0].x,snake[0].y);//��ͷλ�� 
     printf("@"); //��ͷ 
     for(i=1;i<bodyNum;i++)
     {    
         
         gotoxy(snake[i].x,snake[i].y);
         printf("*");//����    
     } 
 }
 
 char controlMove()//�����ƶ� 
 {    
     char input; 
      if(kbhit())//����Ƿ������� �з���1 û�з���0 (����������) 
     {
         input=getch();//���ذ��µļ�
         if(input=='w'||input=='s'||input=='a'||input=='d')
             direction=input;
     }
   return direction;
 }
 
 void change(Point*snake,int bodyNum)
 {
     int i;
     //�ƶ� ԭ������ͷ�����Ϊ��һ�����������������ƣ�
     for(i=bodyNum-1;i>0;i--)
         snake[i]=snake[i-1];
 }
 
 
 
 void clean(Point*snake,int bodyNum)
 {
     int i;
     for(i=0;i<bodyNum;i++)
     {
         gotoxy(snake[i].x,snake[i].y);
         printf(" ");
     
     }
 }
 void printWall()
 {
     int i;
     for(i=0;i<WIDE;i++)
     {    
         gotoxy(i,0);
         printf("#");
         gotoxy(i,HEIGHT);
         printf("#");
     }
     for(i=0;i<HEIGHT;i++)
     {    
         gotoxy(0,i);
         printf("#");
         gotoxy(WIDE,i);
         printf("#");
     }
 }
 
 int isDead(Point*snake,int bodyNum)
 {    
     int i;
     if(snake[0].x==WIDE||snake[0].x==0)
         return 1;
     if(snake[0].y==HEIGHT||snake[0].y==0)
         return 1;
     for(i=1;i<bodyNum;i++)
     {
         if(snake[0].x==snake[i].x&&snake[0].y==snake[i].y)
             return 1;
     }
     return 0;
 }
 
 void food(Point*snake,int bodyNum)
 {
     int x,y;
     x=rand()%(WIDE-1);
     y=rand()%(HEIGHT-1);
     gotoxy(x,y);
     printf("o");
     //��ʳ���������������� 
     snake[bodyNum].x=x;
     snake[bodyNum].y=y;
 }
 
 int eatFood(Point*snake,int *bodyNum)
 {    
     
     if(snake[0].x==snake[*bodyNum].x&&snake[0].y==snake[*bodyNum].y)
     {    
         gotoxy(snake[*bodyNum].x,snake[*bodyNum].y);
         printf(" ");
         snake[*bodyNum]=snake[*bodyNum-1];
         snake[*bodyNum].x++;
         (*bodyNum)++;
         return 1;
     }
     return 0;
 }
