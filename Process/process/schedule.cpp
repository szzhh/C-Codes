#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <process.h>
#include "schedule.h"

#define TIME_SLICE 1000//定义时间片
//就绪队列
pList pReadyList = new readyList;
//缓存区队列
pList pFreeList = new freeList;

pPCB runPCB;

bool firstTime = true;
applyQueue *queue = new applyQueue;

HANDLE hSchedule = NULL;

CRITICAL_SECTION cs_ReadyList;
CRITICAL_SECTION cs_SaveSection;

extern FILE* ouput;
extern volatile bool exiting;
//初始化进程控制块
void initialPCB(pPCB p)
{
	p->id=0;
	strcpy_s(p->name,"");
	p->status=WAIT;
	p->next=NULL;
	p->hThis=NULL;
	p->threadID=0;
	p->count=0;
}
//从缓存区取得空闲进程控制块
pPCB getPcbFromFreeList()
{
	pPCB freePCB =NULL;
	if(pFreeList->head!=NULL&&pFreeList->pcbNum>0)
	{
		freePCB=pFreeList->head;
		pFreeList->head=pFreeList->head->next;
		pFreeList->pcbNum--;
	}
	return freePCB;

}
//释放缓存区
void returnPcbToFreeList(pPCB p)
{
	initialPCB(p);
	if(pFreeList->head==NULL)
	{
		pFreeList->head=p;
		pFreeList->tail;
		pFreeList->pcbNum++;
	}
	else
	{
		pFreeList->tail->next=p;
		pFreeList->tail=p;
		pFreeList->pcbNum++;
	}
}
//模拟进程的线程
static unsigned __stdcall processThread(void* lpParameter)
{
	pPCB currentPcb = (pPCB)lpParameter;
	MSG msg;
	while(true)
	{
		Sleep(1000);

		EnterCriticalSection(&cs_SaveSection);
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if(msg.message==WM_USER){}
		}
		LeaveCriticalSection(&cs_SaveSection);

	}
	return 0;
}
//调度线程
static unsigned __stdcall scheduleThread(void* lpParameter)
{
	pList readyList = (pList)lpParameter;
	while(!exiting)
	{
		scheduleProcess();

	}
	stopAllThreads();
	pPCB tmp,p = pFreeList->head;
	while(p!=NULL)
	{
		tmp=p;
		p=p->next;
		delete tmp;
	}
	return 0;
}
//初始化并写入缓冲区
void init()
{
	if(firstTime)
	{
		pReadyList->head=NULL;
		pReadyList->tail=NULL;
		pReadyList->pcbNum=0;
		
		pFreeList->head=NULL;
		pFreeList->tail=NULL;
		pFreeList->pcbNum=0;
		
		for(int i=0;i<PCB_LIMIT;i++)
		{
			pPCB pTempPCB = new PCB;
			initialPCB(pTempPCB);
			pTempPCB->id=i;
			if(pFreeList->head==NULL)
			{
				pFreeList->head=pTempPCB;
				pFreeList->tail=pTempPCB;
				pFreeList->pcbNum++;
			}
			else
			{
				pFreeList->tail->next=pTempPCB;
				pFreeList->tail=pTempPCB;
				pFreeList->pcbNum++;
			}

		}
		//负责调度的线程
		hSchedule = (HANDLE)_beginthreadex(NULL,0,scheduleThread,pReadyList,0,NULL);
		if(hSchedule==0)
			printf("create thread failed!\n");

		InitializeCriticalSection(&cs_ReadyList);
		InitializeCriticalSection(&cs_SaveSection);
		
		exiting = false;
		firstTime = false;
	}

}
//创建进程
void createProcess(char* name,int count)
{
	EnterCriticalSection(&cs_ReadyList);

	if(pFreeList->pcbNum>0)
	{
		pPCB newPcb = getPcbFromFreeList();
		newPcb->status=READY;
		strcpy_s(newPcb->name,name);
		newPcb->count=count;
		newPcb->next=NULL;

		if(pReadyList->pcbNum==0)
		{
			pReadyList->head=newPcb;
			pReadyList->tail=newPcb;
			pReadyList->pcbNum++;
		}
		else
		{
			pReadyList->tail->next=newPcb;
			pReadyList->tail=newPcb;
			pReadyList->pcbNum++;
		}

		fprintf(ouput,"创建新进程\n进程ID：%d\t进程名称：%s\t进程长度：%d\n",newPcb->id,newPcb->name,newPcb->count);
		fprintf(ouput,"当前就绪队列为：\n");
		fprintReadyList();

		newPcb->hThis=(HANDLE)_beginthreadex(NULL,0,processThread,newPcb,CREATE_SUSPENDED,&(newPcb->threadID));
		
		if(hSchedule==0)
			printf("create thread failed!\n");
	}
	else
	{
		printf("缓存区用完\n");
		fprintf(ouput,"缓存区用完\n\n");
	}

	LeaveCriticalSection(&cs_ReadyList);
}
//进程调度
void scheduleProcess()
{
	EnterCriticalSection(&cs_ReadyList);
	if(pReadyList->pcbNum>0) 
	{
		runPCB =pReadyList->head;
		pReadyList->head=pReadyList->head->next;
		if(pReadyList->head==NULL)
		{
			pReadyList->tail=NULL;
		}
		pReadyList->pcbNum--;
		runPCB->count--;
		fprintf(ouput,"进程%d：%s正在运行\n",runPCB->id,runPCB->name);
		ResumeThread(runPCB->hThis);//唤醒线程
		runPCB->status=RUN;

		Sleep(TIME_SLICE);//运行一个时间片(1S)

		runPCB->status=READY;
		PostThreadMessage(runPCB->threadID,WM_USER,0,0);

		EnterCriticalSection(&cs_SaveSection);
		SuspendThread(runPCB->hThis);//挂起线程
		LeaveCriticalSection(&cs_SaveSection);


		if(runPCB->count<=0&&runPCB!=NULL)
		{
			printf("\n进程%d：%s运行完成\n",runPCB->id,runPCB->name);
			printf("COMMAND>");
			fprintf(ouput,"进程%d：%s运行完成\n\n",runPCB->id,runPCB->name);
			fprintf(ouput,"当前就绪队列为：\n");
			fprintReadyList();
			fflush(ouput);

			if(!TerminateThread(runPCB->hThis,0))
			{
				printf("Terminate thread failed!\n");
				abort();
			}
			CloseHandle(runPCB->hThis);
			returnPcbToFreeList(runPCB);
			runPCB=NULL;

		}
		if(runPCB!=NULL)
		{
			if(pReadyList->pcbNum<=0)
			{
				pReadyList->head=runPCB;
				pReadyList->tail=runPCB;

			}
			else
			{
				pReadyList->tail->next=runPCB;
				pReadyList->tail=runPCB;

			}
			runPCB->next=NULL;
			runPCB=NULL;
			pReadyList->pcbNum++;
		}
	}
	else if(pReadyList!=NULL)
	{
		pReadyList->head=NULL;
		pReadyList->tail=NULL;
		pReadyList->pcbNum=0;
	}

	LeaveCriticalSection(&cs_ReadyList);

	Sleep(100);
}
//请求添加进程
void addApplyProcess(char* name,int time)
{
	applyProcess* newApply=new applyProcess;
	strcpy_s(newApply->name,name);
	newApply->time=time;
	newApply->next=NULL;

	if(queue->applyNum<=0)
	{
		queue->head=newApply;
		queue->tail=newApply;
		queue->applyNum=1;
	}
	else
	{
		queue->tail->next=newApply;
		queue->tail=newApply;
		queue->applyNum++;
	}
	createIfAnyApply();

}
//将进程入队
void createIfAnyApply()
{
	if(queue!=NULL&&queue->applyNum>=1)
	{
		applyProcess* temp = queue->head;

		createProcess(temp->name,temp->time);

		if(queue->applyNum<=1)
		{
			queue->head=NULL;
			queue->tail=NULL;
		}
		else
		{
			queue->head=queue->head->next;
		}
		queue->applyNum--;
		delete temp;
	}
}
//撤销进程
void remove(pPCB removeTarget)
{
	
	printf("进程%d：%s已被撤销\n",removeTarget->id,removeTarget->name);
	fprintf(ouput,"\n进程%d：%s已被撤销\n",removeTarget->id,removeTarget->name);
		
	if(!TerminateThread(removeTarget->hThis,0))
	{
		printf("Terminate thread failed!\n");
		abort();
	}
	CloseHandle(removeTarget->hThis);
	returnPcbToFreeList(removeTarget);
	pReadyList->pcbNum--;
		
	fprintf(ouput,"当前就绪队列为：\n");
	fprintReadyList();
	fflush(ouput);
}

void removeProcess(char* name)
{
	pPCB removeTarget = NULL;
	pPCB preTemp = NULL;

	EnterCriticalSection(&cs_ReadyList);

	if(runPCB!=NULL&&strcmp(name,runPCB->name)==0)
	{

		remove(runPCB);
		runPCB=NULL;
		pReadyList->pcbNum++;
		LeaveCriticalSection(&cs_ReadyList);

		return;
	}
	else if(pReadyList->head!=NULL)
	{
		for(removeTarget=pReadyList->head,preTemp=pReadyList->head;removeTarget!=NULL;removeTarget=removeTarget->next)
		{
			if(removeTarget==pReadyList->head&&strcmp(name,removeTarget->name)==0)
			{
				pReadyList->head=pReadyList->head->next;
				if(pReadyList->head==NULL)
				{
					pReadyList->tail=NULL;
				}

				remove(removeTarget);

				LeaveCriticalSection(&cs_ReadyList);
				return;
			}
			else if(removeTarget!=pReadyList->head&&strcmp(name,removeTarget->name)==0)
			{
				preTemp->next=removeTarget->next;
				if(removeTarget==pReadyList->tail)
				{
					pReadyList->tail=preTemp;
				}
				remove(removeTarget);

				LeaveCriticalSection(&cs_ReadyList);
				return;
			}
			else if(removeTarget!=pReadyList->head)
			{
				preTemp = preTemp->next;
			}
		}
	}
	printf("进程%s不存在\n",name);
	LeaveCriticalSection(&cs_ReadyList);
	return;
}
//向文件中打印就绪队列
void fprintReadyList()
{
	pPCB tmp=NULL;
	tmp=pReadyList->head;
	//printf("进程序号：名称\n");
	if(tmp!=NULL)
	{
		for(int i=0;i<pReadyList->pcbNum;i++)
		{
			fprintf(ouput,"--%d：%s--\n",tmp->id,tmp->name);
			tmp=tmp->next;
		}
	}
	else
	{
		fprintf(ouput,"NULL");

	}
	fprintf(ouput,"\n\n");
}
//向标准输出打印就绪队列
void printReadyList()
{
	pPCB tmp=NULL;
	tmp=pReadyList->head;
	if(tmp!=NULL)
	{
		printf("进程序号：名称\n");
		for(int i=0;i<pReadyList->pcbNum;i++)
		{

			printf("-------%d：%s-------\n",tmp->id,tmp->name);
			tmp=tmp->next;
		}
	}
	else
	{
		printf("NULL");

	}
	printf("\n\n");
}
//打印当前运行情况
void printCurrent()
{
	if(runPCB!=NULL)
	{
		printf("进程%s正在运行\n",runPCB->name);

	}
	else
	{
		printf("没有进程正在运行\n");

	}
	printf("当前就绪队列为：\n");
	printReadyList();
}
//结束所有线程
void stopAllThreads()
{
	if(runPCB!=NULL)
	{
		TerminateThread(runPCB->hThis,0);
		CloseHandle(runPCB->hThis);
	}

	pPCB p = pReadyList->head;
	while(p!=NULL)
	{
		if(!TerminateThread(p->hThis,0))
		{
			printf("Terminate thread failed!\n");
			abort();
		}
		CloseHandle(p->hThis);
		returnPcbToFreeList(p);
		p=p->next;
	}
}