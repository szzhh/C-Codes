#include <cstdio>
#include <cstring>
#include <iostream>
 
using namespace std;
 
class student       // student 类为管理系统的一个节点
{
    friend class studentMessage;
    student      *next;
    char         name[30];
    char         num[30];
    double       score[6];
public:
    student()
    {
        strcpy(name, "null");
        strcpy(num, "null");
        for (int i = 0; i < 6; ++i) score[i] = 0;
    }
    student(const student &a)
    {
        strcpy(name, a.name);
        strcpy(num, a.num);
        for (int i = 0; i < 6; ++i)
            score[i] = a.score[i];
    }
    student &input()
    {
        cout << "姓名：";  cin >> name;
        cout << "学号：";  cin >> num;
        for (int i = 0; i < 5; ++i)
        {
            cout << "输入第" << (i + 1) << "门成绩:";
            cin >> score[i];
            score[5] += score[i];
        }
        return *this;
    }
    student* get_next()
    {
        return next;
    }
    void print()
    {
        printf("%8s %10s ", name, num);
        for (int i = 0; i < 6; ++i) printf(" %6.2f ", score[i]);
        printf("\n");
    }
    void Swap() // 交换当前结点和下一个
    {
        char temp[30];
        strcpy(temp, name);
        strcpy(name, next->name);
        strcpy(next->name, temp);
 
        strcpy(temp, num);
        strcpy(num, next->num);
        strcpy(next->num, temp);
 
        for (int i = 0; i < 6; ++i)
        {
            int tmp = score[i];
            score[i] = next->score[i];
            next->score[i] = tmp;
        }
    }
};
 
class studentMessage
{
protected:
    student *first;
    student *last;
public:
    studentMessage()
    {
        first = last = new student;
    }
    ~studentMessage()
    {
        Clear();
        delete first;
    }
    studentMessage &Append();           // 在链表尾部插入节点
    student *Find(const char *x);       // 查找
    void Query();                       // 查询
    studentMessage &Delete();           // 删除查找结点
    studentMessage &Clear();            // 删除所有结点
    studentMessage &Sort();             // 按第i门课排序
    void print();                       // 显示所有节点
    int menu();                         // 显示菜单
};
 
studentMessage &studentMessage::Append()
{
    student x;
    x.input();
    student *ptr = last;
    *ptr = x;
    last = new student;
    ptr->next = last;
    return *this;
}
 
studentMessage &studentMessage::Delete()
{
    char x[30];
    cout << "输入要删除的信息（学号或姓名）\n";
    cin >> x;
    student *ptr = Find(x);
 
    if (ptr == last)
    {
        cout << "未找到相关信息\n";
        return *this;
    }
    ptr->print();
    cout << "是否删除此信息？（是输入1，否输入0）";
    cin >> x;
    if (*x == '1')
    {
        if (ptr == first)
        {
            first = first->next;
            delete first;
        }
        else
        {
            student *temp = first;
            while (temp->next != ptr) temp = temp->next;
            temp->next = ptr->next;
            delete ptr;
        }
        cout << "已删除\n";
    }
    else
    {
        cout << "已取消\n";
    }
    return *this;
}
 
studentMessage &studentMessage::Clear()
{
    char ch[30];
    cout << "将删除所有信息。确认请按Y";
    cin >> ch;
    if (*ch != 'Y' && *ch != 'y')
    {
        cout << "已取消\n";
        return *this;
    }
    student *ptr = first;
    while (ptr != last)
    {
        student *next = ptr->next;
        delete ptr;
        ptr = next;
    }
    first = last;
    return *this;
}
 
void studentMessage::print()
{
    if (first == last)
    {
        cout << "暂无信息\n";
        return ;
    }
    cout << "---------------------------------成绩列表------------------------------" << endl;
    cout << "序号  姓名      学号      成绩1   成绩2   成绩3   成绩4   成绩5  总成绩" << endl;
    int no = 1;
    student *ptr = first;
    while (ptr != last)
    {
        printf("%3d:", no++);
        ptr->print();
        ptr = ptr->next;
    }
}
 
student *studentMessage::Find(const char *x)
{
    student *ptr = first;
    while (ptr != last)
    {
        if (strcmp(ptr->name, x) == 0 || strcmp(ptr->num, x) == 0)
            break;
        ptr = ptr->next;
    }
    return ptr;
}
 
void studentMessage::Query()
{
    char x[30];
    cout << "输入你要查询的信息(学号或姓名)";
    cin >> x;
    student *ptr = Find(x);
    if (ptr == last)
    {
        cout << "没有查询到相关信息\n";
    }
    else
    {
        ptr->print();
    }
}
 
// 冒泡排序
studentMessage &studentMessage::Sort()
{
    int x;
    cout << "输入你想按照哪门课的成绩来排序?((1-5)总成绩输入6):";
    cin >> x;
    x--;
    student *ptr, *cnt = last;
    while (cnt != first)
    {
        ptr = first;
        while (ptr->next != cnt)
        {
            if (ptr->next->score[x] > ptr->score[x])
            {
                ptr->Swap();
            }
            ptr = ptr->next;
        }
        cnt = ptr;
    }
    return *this;
}
 
int studentMessage::menu()
{
    cout << "===============================\n";
    cout << "      学生成绩管理系统\n\n";
    cout << "      1.显示所有学生成绩\n";
    cout << "      2.添加信息\n";
    cout << "      3.查询信息\n";
    cout << "      4.删除信息\n";
    cout << "      5.成绩排序\n";
    cout << "      6.删除所有信息\n";
    cout << "      0.退出\n";
    cout << "===============================\n";
 
    int ch;
    cin >> ch;
    return ch;
}
 
int main()
{
    studentMessage ls;
    int ch;
    while (ch = ls.menu())
    {
        switch(ch)
        {
            case 1: ls.print(); break;
            case 2: ls.Append(); break;
            case 3: ls.Query(); break;
            case 4: ls.Delete(); break;
            case 5: ls.Sort(); break;
            case 6: ls.Clear(); break;
        }
    }
 
 
    return 0;
}
