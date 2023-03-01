// SJF.cpp: implementation of the SJF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SJF.h"
#include "Global.h"
#include "Tool.h"

#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
#define min(a,b) ((a)<(b))?(a):(b)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SJF::SJF()
{

}

SJF::~SJF()
{

}

void SJF::doSJF(job jobs[],int num)
{
	Tool tool;
	tool.writeRs("-----------------------------------------------------------------------------------SJF------");
	int i,j;
	double sum1=0; //总的等待时间
	double sum2=0; //总的周转时间
	double sum3=0; //总的带权周转时间
	int finish=inf; //当前完成时间
	for(i=1;i<=num;i++){
		finish=min(finish,jobs[i].reach_time);
	}
	char s[2048]="执行先后  到达时间  服务时间  等待时间  周转时间  带权周转\n";
	char s1[1024]="";
	for(i=1;i<=num;i++){
		int index=findNextSJF(jobs,num,finish);
		sprintf(s1,"%12d%12d%12d",
            index,
            jobs[index].reach_time,
			jobs[index].need_time);
		strcat(s,s1);

		if(jobs[index].reach_time<=finish){
			jobs[index].wait_time=finish-jobs[index].reach_time;
			jobs[index].start_time=finish;
		}
		else{
			jobs[index].start_time=jobs[index].reach_time;
			jobs[index].wait_time=0;
		}
		jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
		jobs[index].tr_time=jobs[index].finish_time-jobs[index].reach_time;
		jobs[index].wtr_time=(double)jobs[index].tr_time/jobs[index].need_time;
	    jobs[index].visited=true;
	    sum1+=jobs[index].wait_time;
    	sum2+=jobs[index].tr_time;
        sum3+=jobs[index].wtr_time;
        finish=jobs[index].finish_time;

        sprintf(s1, "%12d%12d%12.2f\n",jobs[index].wait_time,jobs[index].tr_time,jobs[index].wtr_time);
		strcat(s,s1);
	}

  	strcat(s,"--------所有作业调度完毕------\n");
	sprintf(s1,"平均等待时间: %.2f 平均周转时间: %.2f 平均带权周转时间: %.2f\n\n",sum1/num,sum2/num,sum3/num);
	strcat(s,s1);
	tool.writeRs(s);

    printf("计算完成,请继续...\n\n");
}

int SJF::findNextSJF(job j[], int length, int time)
{
	// p是已经到达且拥有最短运行时间的进程的下标
    // q是没有到达的进程中拥有最早到达时间的进程的下标
    int i, p, q;
    int minNeedTime, minReachTime,minTime;
    p = q = -1; minTime = minNeedTime = minReachTime = inf;
    for( i = 1; i <= length; i++ ) {
    	if(!j[i].visited){
            // 第一情况
            if( j[i].reach_time<=time && j[i].need_time<=minNeedTime )
                { p = i; minNeedTime = j[i].need_time; }
            // 第二种情况
            else if( j[i].reach_time>time && j[i].reach_time<=minReachTime  ){
                if(j[i].need_time<minTime)
                { q = i; minReachTime = j[i].reach_time; minTime = j[i].need_time; }
            }
        }
    }
    // p为-1时,代表在lastTime时刻还没进程到达,此时选择下一个最早到达的进程q
    if( p != -1 ) return p;
    return q;
}
