// HRRF.cpp: implementation of the HRRF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HRRF.h"
#include "Global.h"
#include "Tool.h"

#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HRRF::HRRF()
{

}

HRRF::~HRRF()
{

}

void HRRF::doHRRF(job jobs[], int num)
{
	Tool tool;
	tool.writeRs("-----------------------------------------------------------------------------------HRRF----");
	int i,j;
	double sum1=0; //总的等待时间
	double sum2=0; //总的周转时间
	double sum3=0; //总的带权周转时间
	int pre=1;
	jobs[1].finish_time=0;

    char s[2048]="执行先后  到达时间  服务时间  等待时间  周转时间  带权周转\n";
	char s1[1024]="";
	for(i=1;i<=num;i++){

		int index=findNextHRRF(pre,jobs,num);

		sprintf(s1,"%12d%12d%12d",
            index,
            jobs[index].reach_time,
			jobs[index].need_time);
		strcat(s,s1);

		if(i==1){
			jobs[index].start_time=jobs[index].reach_time;
			jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
			jobs[index].tr_time=jobs[index].need_time;
			jobs[index].wtr_time=1.00;
			jobs[index].wait_time=0;
		}
		else{
		   if(jobs[index].reach_time>jobs[pre].finish_time){
			jobs[index].wait_time=0;
			jobs[index].start_time=jobs[index].reach_time;
	    	}
	    	else{
			jobs[index].start_time=	jobs[pre].finish_time;
			jobs[index].wait_time=	jobs[pre].finish_time-jobs[index].reach_time;
	    	}
	    	jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
		    jobs[index].tr_time=jobs[index].finish_time-jobs[index].reach_time;
		    jobs[index].wtr_time=(double)jobs[index].tr_time/jobs[index].need_time;
		}
		    jobs[index].visited=true;
	        pre=index;
	        sum1+=jobs[index].wait_time;
    	    sum2+=jobs[index].tr_time;
            sum3+=jobs[index].wtr_time;

            sprintf(s1, "%12d%12d%12.2f\n",jobs[index].wait_time,jobs[index].tr_time,jobs[index].wtr_time);
            strcat(s,s1);
	}
    strcat(s,"--------所有作业调度完毕------\n");
	sprintf(s1,"平均等待时间: %.2f 平均周转时间: %.2f 平均带权周转时间: %.2f\n\n",sum1/num,sum2/num,sum3/num);
	strcat(s,s1);
	tool.writeRs(s);
    printf("计算完成,请继续...\n\n");
}

int HRRF::findNextHRRF(int pre, job jobs[], int num)
{
	int current=1,i,j;    //优先权=(等待时间+要求服务时间)/要求服务时间
    for(i=1;i<=num;i++)
    {
    	if(!jobs[i].visited){
        jobs[i].wait_time=	jobs[pre].finish_time-jobs[i].reach_time;    //等待时间=上一个进程的完成时间-到达时间
        jobs[i].excellent=(float)(jobs[i].wait_time+jobs[i].need_time)/jobs[i].need_time;
        }
    }
    for(i=1;i<=num;i++)
    {
        if(!jobs[i].visited)
        {
            current=i;    //找到第一个还没完成的作业
            break;
        }
    }
    for(j=i;j<=num;j++)    //和后面的作业比较
    {
        if(!jobs[j].visited)    //还没完成（运行）
        {
            if(jobs[current].reach_time<jobs[pre].finish_time)    //如果进程在上一个进程完成之前到达
            {
                if(jobs[j].excellent>jobs[current].excellent)
                current=j;    //找出到达时间在上一个进程完成之前，优先权高的进程
            }
            else    //如果进程是在上一个进程完成之后到达
            {
                if(jobs[j].reach_time<jobs[current].reach_time)
                    current=j;    //找出比较早到达的一个
                else if(jobs[j].reach_time==jobs[current].reach_time&&jobs[j].excellent>jobs[current].excellent)    //如果同时到达
                    current=j;    //找出服务时间比较短的一个
            }
        }
    }
    return current;    //返回当前进程
}
