// FCFS.cpp: implementation of the FCFS class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FCFS.h"
#include "Global.h"
#include "Tool.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FCFS::FCFS()
{

}

FCFS::~FCFS()
{

}

void FCFS::doFCFS(job jobs[], int num)
{
	Tool tool;
	tool.writeRs("--------------------------------------------------------------------FCFS------");
	int i,j,temp;
	double sum1=0; //总的等待时间
	double sum2=0; //总的周转时间
	double sum3=0; //总的带权周转时间
	for(i = 1;i <= num; i++){
		order[i] = jobs[i].reach_time;
		ready[i] = i;
	}
	//冒泡排序
	for(i = 1; i <= num; i++){//按照到达时间大小排序
		for(j = 1; j <= num-i; j++){
			if(order[j] > order[j+1]){
				temp = order[j];
				order[j] = order[j+1];
				order[j+1] = temp;
				temp = ready[j];
				ready[j] = ready[j+1];
				ready[j+1] = temp;
			}
		}
	}
	char s[2048]="执行先后  到达时间  服务时间  等待时间  周转时间  带权周转\n";
	char s1[1024]="";
	for(i = 1; i <= num; i++){
		sprintf(s1,"%12d%12d%12d",
            ready[i],
            jobs[ready[i]].reach_time,
            jobs[ready[i]].need_time);
		strcat(s,s1);
		if(i==1){
				jobs[ready[i]].finish_time=jobs[ready[i]].reach_time+jobs[ready[i]].need_time;
	            jobs[ready[i]].wait_time=0;
		}
		else{
			if(jobs[ready[i-1]].finish_time>jobs[ready[i]].reach_time){  //如果上一个作业的完成时间大于下一个作业的到达时间，则下一个作业的开始时间从上一个的完成时间开始
	    	jobs[ready[i]].finish_time=jobs[ready[i-1]].finish_time+jobs[ready[i]].need_time;
	    	jobs[ready[i]].wait_time=jobs[ready[i-1]].finish_time-jobs[ready[i]].reach_time;
		    }
		    else{
			jobs[ready[i]].finish_time=jobs[ready[i]].need_time+jobs[ready[i]].reach_time;
			jobs[ready[i]].wait_time=0;
		    }
		}
		jobs[ready[i]].tr_time=jobs[ready[i]].finish_time-jobs[ready[i]].reach_time;
	    jobs[ready[i]].wtr_time=double(jobs[ready[i]].tr_time)/jobs[ready[i]].need_time;
		sprintf(s1, "%12d%12d%12.2f\n",jobs[ready[i]].wait_time,jobs[ready[i]].tr_time,jobs[ready[i]].wtr_time);
		strcat(s,s1);

		sum1+=jobs[ready[i]].wait_time;
    	sum2+=jobs[ready[i]].tr_time;
    	sum3+=jobs[ready[i]].wtr_time;
	}
	strcat(s,"--------所有作业调度完毕------\n");
	sprintf(s1,"平均等待时间: %.2f 平均周转时间: %.2f 平均带权周转时间: %.2f\n\n",sum1/num,sum2/num,sum3/num);
	strcat(s,s1);
	tool.writeRs(s);
    printf("计算完成,请继续...\n\n");
}
