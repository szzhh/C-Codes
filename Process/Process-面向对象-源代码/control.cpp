// control.cpp: implementation of the Ccontrol class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Control.h"
#include "Global.h"
#include "Tool.h"
#include "FCFS.h"
#include "HPF.h"
#include "HRRF.h"
#include "LLF.h"
#include "RR.h"
#include "SJF.h"

#include <string>
#include<Windows.h>
#include <iostream>
#include <cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<queue>
#define getpch(type) (type*)malloc(sizeof(type))
#define inf 0x3f3f3f
#include <fstream>
#include<time.h> 

using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CControl::CControl()
{
	
}

CControl::~CControl()
{

}

void CControl::welcome()
{
	int all_block_num = 30;
	for (int i = 0; i<all_block_num; i++)
	{
		if (i<all_block_num-1)
		{
			printf("\r读取中[%.2lf%%]:", i*100.0 / (all_block_num - 1));
		}
		else
		{
			printf("\r读取完成[%.2lf%%]:", i*100.0 / (all_block_num - 1));
		}
		int show_num = i * 20 / all_block_num;
		for (int j = 1; j <= show_num; j++)
		{
			cout << "█";
			Sleep(5);
		}
	}
	cout << endl;
}

void CControl::run()
{
	system("color 5f"); //改变颜色

	initialJobs(); //初始化为0
	num = readJobData(); //读取数据文件,返回作业数目
	
	getUserChoice();
}

//////////////////////////////////////////////////////////以下被内部调用

void CControl::getUserChoice()
{
        printf("\n请选择其中一种调度算法:\n");
		printf("(1)先来先服务FCFS\n");
		printf("(2)短作业优先SJF\n");
		printf("(3)高相应比优先HRRF\n");
		printf("(4)优先权高者优先HPF\n");
		printf("(5)时间片轮转RR\n");
	//	printf("(6)最低松弛度LLF\n");
	//	printf("(7)银行家算法BANK\n");
		printf("(9)自动执行1-6所有算法\n");
		printf("(0)退出\n");
		//实例化
		FCFS fcfs;
		SJF sjf;
		HRRF hrrf;
		HPF hpf;
		RR rr;
	//	LLF llf;
	//  BANK bank;
	enum process{ FCFS=1, SJF=2, HRRF=3, HPF=4, RR=5, LLF=6, ALL=9, EXIT=0 } choice;
	//判断用户选择
	while(choice != 0){
		printf("请输入一个数字：");
		scanf("%d",&choice);
		switch (choice){
		case FCFS:fcfs.doFCFS(jobs,num);addLog("FCFS"); initialJobsAgain(); break;
		case SJF:sjf.doSJF(jobs,num);addLog("SJF");initialJobsAgain(); break;
		case HRRF:hrrf.doHRRF(jobs,num);addLog("HRRF");initialJobsAgain(); break;
		case HPF:hpf.doHPF(jobs,num);addLog("HPF");initialJobsAgain(); break;
		case RR:rr.doRR(jobs,num);addLog("RR");initialJobsAgain(); break;
	//	case LLF:fun_llf();break;
	//	case BANK:bank.doBank();addLog("BANK");break;
		case ALL:
			addLog("ALL Commend");
		    fcfs.doFCFS(jobs,num);
		    sjf.doSJF(jobs,num);
		    hrrf.doHRRF(jobs,num);
		    hpf.doHPF(jobs,num);
		    rr.doRR(jobs,num);
		    printf("执行完成，已自动为您打开输出文件。~~~，，，(^v^)、、、~~~\n\n");
            system("start \"\" \"output.txt");
			system("start \"\" \"log.txt");
            break;
			
		case 0:printf("退出程序\n");break;
		}
	}
}

void CControl::addLog(char *commend)
{
	time_t nowtime;
    struct tm* p;;
    time(&nowtime);
    p = localtime(&nowtime);

    char time[100] = "";
    sprintf(time, "%04d-%02d-%02d %02d:%02d:%02d", p->tm_year+1900, p->tm_mon+1, p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
	
	strcat(time, " 用户执行了 ");
	strcat(time, commend);
	strcat(time, " 操作。\n\n");
	Tool tool;
	tool.writeLog(time);
}


void CControl::initialJobs()
{
    for(int i=0; i<MAX_NUM; i++)
		{
			jobs[i].excellent=0;
			jobs[i].need_time=0;
			jobs[i].number=0;
			jobs[i].privilege=0;
			jobs[i].reach_time=0;
			jobs[i].run_time=0;
			jobs[i].start_time=0;
			jobs[i].tr_time=0;
			jobs[i].visited=false;
			jobs[i].wait_time=0;
			jobs[i].wtr_time=0;
			jobs[i].finish_time=0;
			jobs[i].reached=false;
		}
}

int CControl::readJobData()
{
	int num =1;
    char buffer[150];
    string line;
    // 以读模式打开文件
    ifstream infile("job.txt");
    string title;
    getline(infile, title);
    while (infile.getline(buffer,120))//每一行
    {
        char *p;
        const char *d = " ,\r\n";
        p = strtok(buffer,d);
        int n=0;//列数
        char c;
        while(p) //每个行的每一列
        {
            n=n+1;
            if(n==1)
            {
                if(isdigit(p[0]))//纯数字
                    sscanf(p,"%d",&jobs[num].number);
                else
                    sscanf(p,"%c%d",&c,&jobs[num].number);
            }

            if(n==2)
                jobs[num].reach_time=atoi(p);
            if(n==3)
                jobs[num].need_time=atoi(p);
            if(n==4)
                jobs[num].privilege=atoi(p);
            p=strtok(NULL,d);
        }
        num++;
    }
    num--;
    // 关闭打开的文件
    infile.close();
    printf("read data success!\n");
    printf("作业的数量为: %d\n\n",num);
    cout<<title<<endl;
    for(int j=1; j<=num; j++)
    {
        printf("p%d\t%d\t\t%d\t\t%d\n",jobs[j].number,jobs[j].reach_time,jobs[j].need_time,jobs[j].privilege);
    }
    return num;
}

void CControl::initialJobsAgain()
{
    for(int i=1; i<=num; i++)
		{
			jobs[i].finish_time=0;
			jobs[i].excellent=0;
			jobs[i].tr_time=0;
			jobs[i].wtr_time=0;
			jobs[i].wait_time=0;
			jobs[i].visited=false;
		}
}


