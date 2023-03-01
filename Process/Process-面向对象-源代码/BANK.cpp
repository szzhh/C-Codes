// BANK.cpp: implementation of the BANK class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BANK.h"
#include<stdio.h>
#include <iostream>

using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BANK::BANK()
{

}

BANK::~BANK()
{

}


void BANK::showInfo(int resourceNum, int available[], int processNum, int **maxRequest, int **allocation, int **need)
{
    int i,j;
	cout<<endl;
	cout<<"---------------------------------------bank algorithm---------------------------------------"<<endl;
	cout<<"当前系统各类资源剩余：";
    for(j = 0; j < resourceNum; j++)
	{
        cout<<available[j]<<" ";
    }
    cout<<endl;
    cout<<"当前系统资源情况:"<<endl;
    cout<<"ID"<<"\tMax\t\tAllocation\tNeed"<<endl;
    for(i = 0; i < processNum; i++)
	{
        cout<<" P"<<i<<"\t";
        for(j = 0; j < resourceNum; j++)
		{
		    //格式化输出，用c
            printf("%2d",maxRequest[i][j]);
        }
        cout<<"\t\t";
        for(j = 0; j < resourceNum; j++)
		{
            printf("%2d",allocation[i][j]);
        }
        cout<<"\t\t";
        for(j = 0; j < resourceNum; j++)
		{
            printf("%2d",need[i][j]);
        }
        cout<<endl;
    }
}

//打印安全检查信息
void BANK::SafeInfo(int *work, int i, int resourceNum, int **allocation, int **need)
{
    int j;
    cout<<" P"<<i<<"\t";
    for(j = 0; j < resourceNum; j++)
	{
        printf("%2d",work[j]);
    }
    cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        printf("%2d",allocation[i][j]);
    }
    cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        printf("%2d",need[i][j]);
    }
    cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        printf("%2d",allocation[i][j]+work[j]);
    }
    cout<<endl;
}

//判断一个进程的资源是否全为零
bool BANK::isAllZero(int kang, int num, int resourceNum, int **need)
{
	num = 0;
	for(int i = 0; i < resourceNum; i++ )
	{
		if(need[kang][i] == 0)
		{
			num ++;
		}
	}
	if(num == resourceNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//安全检查
bool BANK::isSafe(int resourceNum, int num, int **need, int **allocation, int safeSeries[], int available[], int processNum, bool Finish[])
{
	//int resourceNumFinish = 0;
	int i;
	int safeIndex = 0;
	int allFinish = 0;
    int work[resourceNum] = {0};
	int r = 0;
	int temp = 0;
	int pNum = 0;
	//预分配为了保护available[]
    for(i = 0; i < resourceNum; i++)
	{
        work[i] = available[i];
    }
	//把未完成进程置为false
    for(i = 0; i < processNum; i++)
	{
		bool result = isAllZero(i,num,resourceNum,need);
		if(result == true)
		{
			Finish[i] = true;
			allFinish++;
		}
		else
		{
			Finish[i] = false;
		}

    }
	//预分配开始
    while(allFinish != processNum)
	{
		num = 0;
        for(i = 0; i < resourceNum; i++)
		{
			if(need[r][i] <= work[i] && Finish[r] == false)
			{
				num ++;
			}
		}
		if(num == resourceNum)
		{
			for(i = 0; i < resourceNum; i++ )
			{
				work[i] = work[i] + allocation[r][i];
			}
			allFinish ++;
			SafeInfo(work,r,resourceNum,allocation,need);
			safeSeries[safeIndex] = r;
			safeIndex ++;
			Finish[r] = true;
		}
		r ++;//该式必须在此处
		if(r >= processNum)
		{
			r = r % processNum;
			if(temp == allFinish)
			{
				break;
			}
			temp = allFinish;
		}
		pNum = allFinish;
    }
	//判断系统是否安全
	for(i = 0; i < processNum; i++)
	{
		if(Finish[i] == false)
		{
			cout<<"无法找到安全序列，系统状态不安全"<<endl;
			return false;
		}
	}
	//打印安全序列
	cout<<"系统安全！"<<endl;
	cout<<"找到安全序列:";
	for(i = 0; i < processNum; i++)
	{
		bool result = isAllZero(i,num,resourceNum,need);
		if(result == true)
		{
			pNum --;
		}
    }
	for(i = 0; i < pNum; i++)
	{
		printf("%d ",safeSeries[i]);
	}
    return true;
}

//主函数
void BANK::doBank()
{
    //>>>>>>>>>>>>初始化参数>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int resourceNum = 3;
    int processNum = 5;
    //系统可用（剩余）资源
    int available[resourceNum]={3,3,2};
    //进程的最大需求
    int list_maxrequest[]={7,5,3,3,2,2,9,0,2,2,2,2,4,3,3};
    int **maxRequest;
    maxRequest = new int *[processNum];
    int t = 0;
    for(int i=0;i<processNum;i++) {
        maxRequest[i] = new int[resourceNum];
        for(int j=0;j<resourceNum;j++) {
            maxRequest[i][j] = list_maxrequest[t];
            t++;
        }
    }
    //进程已经占有（分配）资源
    int list_allocation[] = {0,1,0,2,0,0,3,0,2,2,1,1,0,0,2};
    int **allocation;
    allocation = new int *[processNum];
    t = 0;
    for(int i=0;i<processNum;i++) {
        allocation[i] = new int[resourceNum];
        for(int j=0;j<resourceNum;j++) {
            allocation[i][j] = list_allocation[t];
            t++;
        }
    }
    //进程还需要资源
    int list_need[] = {7,4,3,1,2,2,6,0,0,0,1,1,4,3,1};
    int **need;
    need = new int *[processNum];
    t = 0;
    for(int i=0;i<processNum;i++) {
        need[i] = new int[resourceNum];
        for(int j=0;j<resourceNum;j++) {
            need[i][j] = list_need[t];
            t++;
        }
    }
    //是否安全
    bool Finish[processNum];
    //安全序列号
    int safeSeries[processNum]={0,0,0,0,0};
    //进程请求资源量
    int request[resourceNum];
    //资源数量计数
    int num = 0;
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    int i,j;
    int curProcess = 0;
	int a = -1;
    showInfo(resourceNum,available,processNum,maxRequest,allocation,need);
	cout<<" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation"<<endl;
	bool isStart = isSafe(resourceNum,num,need,allocation,safeSeries,available,processNum,Finish);
	//用户输入或者预设系统资源分配合理才能继续进行进程分配工作
    while(isStart)
	{
		//限制用户输入，以防用户输入大于进程数量的数字，以及输入其他字符（乱输是不允许的）
      	do
		{
			if(curProcess >= processNum || a == 0)
			{
				cout<<"输出格式有误！或输入值范围不合法";
				while(getchar() != '\n'){};//清空缓冲区
				a = -1;
			}
			cout<<endl;
			cout<<"---------------------------------------bank algorithm---------------------------------------"<<endl;
			cout<<"分配的进程：";
			cin>>curProcess;
			a = curProcess;
			cout<<endl;

		}while(curProcess >= processNum || a == 0);

		//限制用户输入，此处只接受数字，以防用户输入其他字符（乱输是不允许的）
		for(i = 0; i < resourceNum; i++)
		{
			do
			{
				if(a == 0)
				{
                    cout<<"输出格式有误！或输入值范围不合法";
					while(getchar() != '\n'){};//清空缓冲区
					a = -1;
				}
                    printf("请输入要分配ID:%d 的%d 类资源：",curProcess,i+1);
                    cin>>request[i];
				a = request[i];
			}while( a == 0);
		}

		//判断用户输入的分配是否合理，如果合理，开始进行预分配
		num  = 0;
        for(i = 0; i < resourceNum; i++)
		{
            if(request[i] <= need[curProcess][i] && request[i] <= available[i])
			{
				num ++;
			}
            else
			{
				cout<<"系统出现可预估错误："<<endl;;
				cout<<"1. 请求分配的资源可能大于该进程的某些资源的最大需要！"<<endl;
				cout<<"2. 系统所剩的资源已经不足"<<endl;
				break;
			}
        }
        if(num == resourceNum)
		{
			num = 0;
            for(j = 0; j < resourceNum; j++)
			{
				//分配资源
                available[j] = available[j] - request[j];
                allocation[curProcess][j] = allocation[curProcess][j] + request[j];
                need[curProcess][j] = need[curProcess][j] - request[j];
				//记录分配以后，是否该进程需要值为0了
				if(need[curProcess][j] == 0)
				{
					num ++;
				}
            }
			//如果分配以后出现该进程对所有资源的需求为0了，即刻释放该进程占用资源（视为完成）
			if(num == resourceNum)
			{
				//释放已完成资源
				for(i = 0; i < resourceNum; i++ )
				{
					available[i] = available[i] + allocation[curProcess][i];
				}
				cout<<endl;
				cout<<"本次分配进程ID"<<curProcess<<"完成，进程的资源已经释放"<<endl;
			}
			else
			{
				//资源分配可以不用一次性满足进程需求
				cout<<endl;
				cout<<"本次分配进程ID"<<curProcess<<"失败"<<endl;
			}

			showInfo(resourceNum,available,processNum,maxRequest,allocation,need);
           	cout<<"安全性分析"<<endl;
			cout<<" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation"<<endl;

			//预分配完成以后，判断该系统是否安全，若安全，则可继续进行分配，若不安全，将已经分配的资源换回来
            if(!isSafe(resourceNum,num,need,allocation,safeSeries,available,processNum,Finish))
			{
				for(j = 0; j < resourceNum; j++)
				{
					available[j] = available[j] + request[j];
					allocation[curProcess][j] = allocation[curProcess][j] - request[j];
					need[curProcess][j] = need[curProcess][j] +request[j];
				}
				cout<<"系统资源不足，分配失败"<<endl;
				cout<<endl;
            }
        }
    }
}
