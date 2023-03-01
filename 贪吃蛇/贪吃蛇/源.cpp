#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<Windows.h>
#include<time.h>
//游戏画面大小 
#define HEIGHT 25//高 
#define WIDE 45//宽 
typedef struct
{
    int x;//x坐标 
    int y;//y坐标 

}Point;

char direction = 'w';//方向 
int point = 0;//分数 

void init(Point* snake, int bodyNum);//初始化，设定蛇身的坐标 
void move(Point* snake, int* bodyNum);//
void printSnake(Point* snake, int bodyNum);//打印蛇 
char controlMove();//控制移动 

void change(Point* snake, int bodyNum);//改变蛇的坐标 
void clean(Point* snake, int bodyNum);//在屏幕上清除之前的蛇 

void printWall();//打印墙壁 
int isDead(Point* snake, int bodyNum);//判断蛇是否死亡 是返回1 非返回0 
void food(Point* snake, int bodyNum);//随机产生食物 
int eatFood(Point* snake, int* bodyNum);//判断是否吃到食物 是返回1 非返回0 

void HideCursor();//隐藏光标 
void gotoxy(int x, int y);//光标位置移动到指定的坐标 

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

int main()
{
    Point snake[64];//表示蛇
    int bodyNum = 6;//蛇身的个数,初始化6个 
    srand(time(NULL));//设置随机种子 

    HideCursor();
    init(snake, bodyNum);
    printWall();
    food(snake, bodyNum);
    printSnake(snake, bodyNum);

    while (1)
    {
        move(snake, &bodyNum);
        Sleep(200 - point);//分数越高速度越快 
    }

}

void init(Point* snake, int bodyNum)
{
    int i;
    snake[0].x = HEIGHT / 2;
    snake[0].y = WIDE / 2;
    for (i = 1;i < bodyNum;i++)
    {        //让蛇一开始在画面中间 
        snake[i].x = HEIGHT / 2 + i;
        snake[i].y = WIDE / 2;
    }
}

void move(Point* snake, int* bodyNum)
{
    char dir = controlMove();//获取用户输入的按键 
    clean(snake, *bodyNum);//清除之前的蛇 
    change(snake, *bodyNum);//每次移动时都改变坐标
    //改变蛇头的坐标 
    switch (dir)
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

    if (eatFood(snake, bodyNum))//如果吃到食物 
    {

        if (point > 100)
            point += 5;
        else
            point += 10;

        food(snake, *bodyNum);//随机产生新的食物 
    }

    printSnake(snake, *bodyNum);//打印新的蛇 
    if (isDead(snake, *bodyNum))//如果死亡 
    {
        gotoxy(WIDE, HEIGHT);
        printf("\n\n\nGAVE OVER");
        exit(0);//退出游戏 
    }
}

void printSnake(Point* snake, int bodyNum)
{
    int i;
    gotoxy(snake[0].x, snake[0].y);//蛇头位置 
    printf("@"); //蛇头 
    for (i = 1;i < bodyNum;i++)
    {

        gotoxy(snake[i].x, snake[i].y);
        printf("*");//蛇身    
    }
}

char controlMove()//控制移动 
{
    char input;
    if (_kbhit())//检测是否有输入 有返回1 没有返回0 (非阻塞函数) 
    {
        input = _getch();//返回按下的键
        if (input == 'w' || input == 's' || input == 'a' || input == 'd')
            direction = input;
    }
    return direction;
}

void change(Point* snake, int bodyNum)
{
    int i;
    //移动 原来的蛇头坐标变为第一节蛇身，其余依此类推，
    for (i = bodyNum - 1;i > 0;i--)
        snake[i] = snake[i - 1];
}



void clean(Point* snake, int bodyNum)
{
    int i;
    for (i = 0;i < bodyNum;i++)
    {
        gotoxy(snake[i].x, snake[i].y);
        printf(" ");

    }
}
void printWall()
{
    int i;
    for (i = 0;i < WIDE;i++)
    {
        gotoxy(i, 0);
        printf("#");
        gotoxy(i, HEIGHT);
        printf("#");
    }
    for (i = 0;i < HEIGHT;i++)
    {
        gotoxy(0, i);
        printf("#");
        gotoxy(WIDE, i);
        printf("#");
    }
}

int isDead(Point* snake, int bodyNum)
{
    int i;
    if (snake[0].x == WIDE || snake[0].x == 0)
        return 1;
    if (snake[0].y == HEIGHT || snake[0].y == 0)
        return 1;
    for (i = 1;i < bodyNum;i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return 1;
    }
    return 0;
}

void food(Point* snake, int bodyNum)
{
    int x, y;
    x = rand() % (WIDE - 1);
    y = rand() % (HEIGHT - 1);
    gotoxy(x, y);
    printf("o");
    //将食物的坐标存在数组中 
    snake[bodyNum].x = x;
    snake[bodyNum].y = y;
}

int eatFood(Point* snake, int* bodyNum)
{

    if (snake[0].x == snake[*bodyNum].x && snake[0].y == snake[*bodyNum].y)
    {
        gotoxy(snake[*bodyNum].x, snake[*bodyNum].y);
        printf(" ");
        snake[*bodyNum] = snake[*bodyNum - 1];
        snake[*bodyNum].x++;
        (*bodyNum)++;
        return 1;
    }
    return 0;
}
