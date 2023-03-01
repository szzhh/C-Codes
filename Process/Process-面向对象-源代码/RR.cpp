// RR.cpp: implementation of the RR class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RR.h"
#include "Global.h"
#include "Tool.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//按照先来先服务并使用时间片轮转

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RR::RR()
{

}

RR::~RR()
{

}


void RR::doRR(job jobs[], int num)
{
	Tool tool;
	tool.writeRs("--------------------------------------------------------------------------RR---");



	double sum1=0; //总的等待时间
	double sum2=0; //总的周转时间
	double sum3=0; //总的带权周转时间

	vector<job> jobList;     //jobList向量
	int time_unit = 10;//时间片长度
	for(int i=1;i<=num;i++)
	{
		jobList.push_back(jobs[i]);
	}

	queue<job>Ready;     //就绪队列
	sort(jobList.begin(),jobList.end(),cmp);
	int begin =(*jobList.begin()).reach_time;
	Ready.push(*jobList.begin());
	jobList.erase(jobList.begin());
	char s[2048]="";
	char s1[1024]="";
    while(!jobList.empty()||!Ready.empty()){
	      while(!jobList.empty()&&begin>=(*jobList.begin()).reach_time){ 	//有新作业到达，加入就绪队列
			 	Ready.push(*jobList.begin());
        	    jobList.erase(jobList.begin());
		   }
		if(Ready.front().finish_time + time_unit < Ready.front().need_time){ 	//时间片用完没运行完,加入队尾

			sprintf(s1,"%d 号作业执行了 %d\n",Ready.front().number,time_unit);
			strcat(s,s1);

			Ready.front().finish_time += time_unit;
			begin += time_unit;
			while(!jobList.empty()&&begin>=(*jobList.begin()).reach_time){ 	//有新作业到达，加入就绪队列
			 	Ready.push(*jobList.begin());
        	    jobList.erase(jobList.begin());
		    }

			Ready.push(Ready.front());
			Ready.pop();
		}
		else{ //作业运行完
			if(Ready.front().need_time - Ready.front().finish_time<time_unit){
				time_unit-=Ready.front().need_time - Ready.front().finish_time;
			}
			else{
				time_unit=10;
			}

			sprintf(s1,"%d 号作业执行了 %d\n",Ready.front().number,time_unit);
			strcat(s,s1);

			begin += time_unit;
			Ready.front().finish_time = begin;
			Ready.front().wait_time = Ready.front().finish_time-Ready.front().reach_time-Ready.front().need_time;
			Ready.front().tr_time = Ready.front().finish_time - Ready.front().reach_time;
			Ready.front().wtr_time = (double)Ready.front().tr_time / Ready.front().need_time;
			sum1+=Ready.front().wait_time;
			sum2+=Ready.front().tr_time;
			sum3+=Ready.front().wtr_time;

            sprintf(s1, "执行完的作业是 %d 号作业，等待时间是 %d ,周转时间是 %d ,带权周转时间是 %.2f\n",Ready.front().number,Ready.front().wait_time
			,Ready.front().tr_time,Ready.front().wtr_time);
			strcat(s,s1);

			//从就绪队列中移除作业
			Ready.pop();

			if(Ready.empty()&&!jobList.empty()){
				sort(jobList.begin(),jobList.end(),cmp);

				sprintf(s1,"找到当前最早的作业是: %d\n",(*jobList.begin()).number);
				strcat(s,s1);

				begin = (*jobList.begin()).reach_time;

			}
			if(time_unit<10){
				time_unit=10;
			}
		}
	}
		strcat(s, "--------所有作业调度完毕------\n");
	    sprintf(s1,"平均等待时间: %.2f 平均周转时间: %.2f 平均带权周转时间: %.2f\n\n\n",sum1/num,sum2/num,sum3/num);
	    strcat(s,s1);
	    tool.writeRs(s);
	    printf("计算完成,请继续...\n\n");
}

bool RR::cmp(job a, job b)
{
	return a.reach_time<b.reach_time;
}

