#include "stdlib.h"
#include "stdio.h"
#define LEN sizeof(struct student)

struct student
{
    int num;              //学号
    float score;          //分数，其他信息可以继续在下面增加字段
    struct student *next;        //指向下一节点的指针
};
int n;    //节点总数
/*
==========================
功能：创建n个节点的链表
返回：指向链表表头的指针
==========================
*/
struct student *Create()
{
    struct student *head;        //头节点
    struct student *p1 = NULL;    //p1保存创建的新节点的地址
    struct student *p2 = NULL;    //p2保存原链表最后一个节点的地址

    n=0;            //创建前链表的节点总数为0：空链表
    p1 = (struct student *) malloc (LEN);    //开辟一个新节点
    p2 = p1;            //如果节点开辟成功，则p2先把它的指针保存下来以备后用

    if(p1==NULL)        //节点开辟不成功
    {
        printf ("\nCann't create it, try it again in a moment!\n");
        return NULL;
    }
    else                //节点开辟成功
    {
        head = NULL;        //开始head指向NULL
        printf ("Please input %d node -- num,score: ",n+1);
        scanf ("%d %f", &(p1->num), &(p1->score));    //录入数据
    }
    while(n<2)        //只要n小于指定的数，就继续录入下一个节点
    {
        n++;            //节点总数增加1个
        if(n==1)        //如果节点总数是1，则head指向刚创建的节点p1
        {
            head = p1;
            p2->next = NULL;  //此时的p2就是p1,也就是p1->next指向NULL。
        }

        p1 = (struct student *) malloc (LEN);
        printf ("Please input %d node -- num,score: ",n+1);
        scanf ("%d %f",&(p1->num),&(p1->score));
         p2->next = p1;    //指向上次下面刚刚开辟的新节点
         p2 = p1;           //把p1的地址给p2保留，然后p1产生新的节点
    }
    p2->next = NULL;        //此句就是根据单向链表的最后一个节点要指向NULL

    free(p1);            //p1->num为0的时候跳出了while循环，并且释放p1
    p1 = NULL;            //特别不要忘记把释放的变量清空置为NULL,否则就变成"野指针"，即地址不确定的指针
    return head;        //返回创建链表的头指针
}


/*
===========================
 功能：输出节点
 返回： void
===========================
*/
void Print(struct student *head)
{
    struct student *p;
    printf ("\nNow , These %d records are:\n",n+1);
    p = head;
    if(head != NULL)        //只要不是空链表，就输出链表中所有节点
    {
        printf("head is %o\n", head);     //输出头指针指向的地址
        do
        {
            /*
            输出相应的值：当前节点地址、各字段值、当前节点的下一节点地址。
            这样输出便于读者形象看到一个单向链表在计算机中的存储结构，和我们
            设计的图示是一模一样的。
            */
            printf ("%o   %d   %5.1f   %o\n", p, p->num, p->score, p->next);
            p = p->next;        //移到下一个节点
        }while(p!=NULL);
    }
}
int main()
{
	struct student stu;
	struct student *t;
	t=Create();
	Print(t);
	return 0;	
} 
