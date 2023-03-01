// LLF.cpp: implementation of the LLF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LLF.h"
#include "Global.h"
#include "Tool.h"

#include <iostream>
#include <string>
#include <string.h>
#include"string"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define EXE_LEN 90  //定义执行总数
/**
 *	1. 该算法主要用于可抢占调度方式中，当一任务的最低松弛度减为0时，它必须立即抢占CPU，以保证按截止时间的要求完成任务。

	2. 计算关键时间点的各进程周期的松弛度，当进程在当前周期截止时间前完成了任务，则在该进程进入下个周期前，无需计算它的松弛度。

	3. 当出现多个进程松弛度相同且为最小时，按照“最近最久未调度”的原则进行进程调度。
 *
 */
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LLF::LLF()
{

}

LLF::~LLF()
{

}

//初始化任务：输入结构体，最坏执行时间WCET、需要时间period、截止时间deadline
void LLF::init_task(task_t *t, string name, int WCET, int period, int deadline, int cycle, int status, int join)
{
	t->name = name;
	t->WCET = WCET;
	t->period = period;
	t->deadline = deadline;
	t->cycle = cycle;
	t->status = status;
	t->join = join;
}

//初始化任务体集合（存储任务的数组），将各个task用数组存储，输入task的数目即数组的长度
void LLF::init_tasks(task_t t[], string name[], int WCET[], int period[], int deadline[], int cycle[], int status[], int join[], int numTasks)
{
    int i;
	for(i = 0; i < numTasks; i++)
	{
		init_task(&(t[i]),name[i], WCET[i],period[i],deadline[i], cycle[i] ,status[i], join[i]);
	}
}

//复制task，将一个task列表复制到另一个task列表中，常用作备用处理，需要传入task数目
void LLF::copy_tasks(task_t tasks_to_be_copied[], task_t place_to_copy[], int numTasks)
{
    int i;
	for(i = 0; i < numTasks; i++)
	{
		place_to_copy[i].name = tasks_to_be_copied[i].name;
		place_to_copy[i].WCET = tasks_to_be_copied[i].WCET;
		place_to_copy[i].period = tasks_to_be_copied[i].period;
		place_to_copy[i].deadline = tasks_to_be_copied[i].deadline;
		place_to_copy[i].cycle = tasks_to_be_copied[i].cycle;
		place_to_copy[i].status = tasks_to_be_copied[i].status;
		place_to_copy[i].join = tasks_to_be_copied[i].join;
	}
}

void LLF::update_task(task_t *t, int WCET, int period, int deadline, int cycle, int join)
{
	t->WCET = WCET;
	t->period = period;
	t->deadline = deadline;
	t->cycle = cycle;
	t->join = join;
}

//打印task
void LLF::print_task(task_t t)
{
    char c[1024];
	cout<<"task:"<<t.name;
	sprintf(c," exe time: %u period: %u deadline: %u \n", t.WCET, t.period, t.deadline);
	strcat(c,"task:");

	char ts[1024];
	sprintf(ts," exe time: %u period: %u deadline: %u \n", t.WCET, t.period, t.deadline);
	strcat(c,ts);
	tool.writeRs(c);
}

//打印task列表
void LLF::print_tasks(task_t t[], int numTasks)
{
    int i;
	for (i = 0; i < numTasks; ++i)
	{
		print_task(t[i]);
	}

}

void LLF::set_schedule(string schedule[], string name, int index)
{
	schedule[index] = name;
}

//LLF算法实现
int LLF::llf(task_t ori_t[], task_t t[], int numTasks,int time)
{//因为是对每个时间点的判断，所以这里传入时自带了当前时间，WCET（最坏完成时）即为运行时间+当前时间
	int least_index = 0;
	int least_laxity = 99999; //初始化最低松弛度（设置为int最大值）
	int current_laxity; //当前松弛度
	int i;
	int flag = 0;
	for (i = 0; i < numTasks; i++)
	{//遍历所有的task
		if(t[i].WCET<=0) {
			t[i].cycle++;
			t[i].WCET = ori_t[i].WCET;
			t[i].period = ori_t[i].period;
			t[i].deadline = ori_t[i].deadline*t[i].cycle;
			t[i].join = time;
			t[i].status = 1;
		}

		if(t[i].status == 0)//task还未执行完
		{
			current_laxity = t[i].deadline - t[i].WCET - time; //计算松弛度=截止时间-剩余需要执行的时间-当前时间
		} else { //已经执行完
			current_laxity = 99999;
			int temp = t[i].deadline - t[i].WCET - time;
			if (temp<=0 && t[i].WCET>0) { //当松弛度减少为0，同时仍未执行完时，才设置零
				//到达0，立马执行y
				t[i].status = 0;
				current_laxity = temp;
			} else {
				flag ++;
			}
		}
			// cout<<time<<"时"<<t[i].name<<t[i].cycle<<"的松弛度="<<current_laxity<<" ";

		if(current_laxity < least_laxity)
		{//交换索引
			least_index = i;
			least_laxity = current_laxity;
		}
	}
	if(flag==numTasks) {
		//代表都进入下一个阶段而未改变temp状态，
		int m = 999;
		int index = 0;
		for(i=0;i<numTasks;i++) {
			//寻找时间点
			if(t[i].join < m) {
				m = t[i].join;
				index = i;
			}
		}
		// cout<<"关键节点，选择->"<<t[index].name<<t[index].cycle;
		if(t[index].WCET<=0) { //直接更新换代
			t[index].cycle++;
			t[index].WCET = ori_t[index].WCET;
			t[index].period = ori_t[index].period;
			t[index].deadline = ori_t[index].deadline*t[index].cycle;
			t[index].join = time;
		}
		t[index].status = 0;
		least_index = index;
	}
	// cout<<endl;
	return least_index;
}

void LLF::sim_schedule(task_t t[], int numTasks, string schedule[], int schedule_length)
{
    //复制原任务表
	task_t placeholder_task[numTasks];
	copy_tasks(t, placeholder_task, numTasks);

	int current_task;//当前任务索引

	int i;

	for(i = 0; i < schedule_length; i++)
	{//给每一个时间点分配task
		schedule[i] = "None"; //各个时间点初始化

		//决定当前时间点应该llf分配的任务
		int time = i; //时刻
		current_task = llf(t,placeholder_task, numTasks, time); //传入llf算法，修改#1

		//执行最低松弛度对应的任务，执行一次
		if (placeholder_task[current_task].WCET > 0)
			placeholder_task[current_task].WCET -= 1;

		//时间点推移
		int j;
		for (j = 0; j < numTasks; j++)
		{//遍历所有任务

			//到了截止时间以后
			if(placeholder_task[j].deadline <= i)   //到达当前时间
			{//如果任务还没有执行完
				if(placeholder_task[j].WCET > 0)    //而其仍然没有执行完
				{//就在时间表设置一个较大的值占位，方便下次比较
					string loss = "cannot finish: " + placeholder_task[j].name + to_string(placeholder_task[j].cycle);
					set_schedule(schedule, loss, i);
				}
			}

			//执行完之后
			if(placeholder_task[j].status==1 && placeholder_task[j].WCET <= 0) {
				placeholder_task[j].cycle++;
				placeholder_task[j].WCET = t[j].WCET;
				placeholder_task[j].period = t[j].period;
				placeholder_task[j].deadline = t[j].deadline*placeholder_task[j].cycle;
				placeholder_task[j].join = i;
			}

		}
		string task_name = placeholder_task[current_task].name;
		string task_cycle = to_string(placeholder_task[current_task].cycle);
		task_name.append(task_cycle);
		set_schedule(schedule, task_name, i);
	}
}

void LLF::print_schedule(string schedule[], task_t t[], int length)
{//打印时间表
	int i;
	char c[4096];
	for (i = 0; i < length; ++i)
	{//遍历了所有的执行点
		cout<<"time:"<<i<<", current_task:"<<schedule[i]<<endl;
	    strcat(c,"time:");
	    char *ci = new char;
        sprintf(ci,"%d",i);
	    strcat(c,ci);
	    strcat(c,",current_task:");
	    strcat(c,schedule[i].c_str());
	    strcat(c,"\n");
	}
	tool.writeRs(c);
}

/**************************2. **************************************/

void LLF::init_task(task_t *t, string name, int WCET, int period, int deadline, int cycle)
{
	t->name = name;
	t->WCET = WCET;
	t->period = period;
	t->deadline = deadline;
	t->cycle = cycle;
}

void LLF::init_tasks(task_t t[], string name[], int WCET[], int period[], int deadline[], int cycle[], int numTasks)
{
	int i;
	for(i = 0; i < numTasks; i++)
	{
		init_task(&(t[i]),name[i], WCET[i],period[i],deadline[i],cycle[i]);
	}
}

void LLF::copy_tasks2(task_t tasks_to_be_copied[], task_t place_to_copy[], int numTasks)
{
	int i;
	for(i = 0; i < numTasks; i++)
	{
		place_to_copy[i].name = tasks_to_be_copied[i].name;
		place_to_copy[i].WCET = tasks_to_be_copied[i].WCET;
		place_to_copy[i].period = tasks_to_be_copied[i].period;
		place_to_copy[i].deadline = tasks_to_be_copied[i].deadline;
		place_to_copy[i].cycle = tasks_to_be_copied[i].cycle;
	}
}

int LLF::llf2(task_t t[], int numTasks)
{
	int least_index = 0;
	int least_laxity = 99999;
	int current_laxity;
	int i;
	for (i = 0; i < numTasks; i++)
	{
		if(t[i].WCET > 0)
		{
			current_laxity = t[i].deadline - t[i].WCET;
		}

		if(current_laxity < least_laxity)
		{
			least_index = i;
			least_laxity = current_laxity;
		}
	}
	return least_index;
}

void LLF::set_schedule(string schedule[], task_t t[], int index, int time)
{
	string name =  t[index].name;
	name.append(to_string(t[index].cycle));
	schedule[time] = name;
}

void LLF::sim_schedule2(task_t t[], int numTasks, string schedule[], int schedule_length)
{
	task_t placeholder_task[numTasks];
	copy_tasks2(t, placeholder_task, numTasks);

	int current_task;
	int i;
	for(i = 0; i < schedule_length; i++)
	{
		schedule[i] = "None";

		current_task = llf2(placeholder_task, numTasks);

		placeholder_task[current_task].WCET -= 1;

		int j;
		for (j = 0; j < numTasks; j++)
		{
			placeholder_task[j].period -= 1;
			placeholder_task[j].deadline -= 1;

			if(placeholder_task[j].deadline <= 0)
			{
				if(placeholder_task[j].WCET > 0)
				{
					//不合法设置
					string loss = "cannot finish: " + placeholder_task[j].name + to_string(placeholder_task[j].cycle);
					set_schedule(schedule, loss, i);
				}
			}

			if(placeholder_task[j].period <= 0)
			{
				placeholder_task[j].WCET = t[j].WCET;
				placeholder_task[j].period = t[j].period;
				placeholder_task[j].deadline = t[j].deadline;
				placeholder_task[j].cycle ++;
			}

		}

		//设置
		set_schedule(schedule, placeholder_task, current_task, i);
	}
}
void LLF::tip(){
    char c[1024];
    cout<<"---------------LLF----------------\n";
    cout<<"(1)A、B两任务周期性执行;\n";
    cout<<"(2)A、B、C、D四任务周期性执行;\n";
    cout<<"请输入您的选择：\n";
    strcat(c,"---------------LLF----------------\n");
    strcat(c,"(1)A、B两任务周期性执行;\n");
    strcat(c,"(2)A、B、C、D四任务周期性执行;\n");
    strcat(c,"请输入您的选择：\n");
    tool.writeRs(c);

}
void LLF::doLLF()
{
	/**
	 * 1. 无间隔时间，在一个输入以后直接进入（测试中）
	 * 2. 有间隔时间period
	 */
    cout<<"tesk";
    tip();
	int choose;
	cin>>choose;
    int NUM_TASKS = 3;

	if(1==choose) {
		/**1. 初始化参数**/
		//>>>>>>>>>>>>>>从文件中读取参数，修改格式<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		NUM_TASKS = 2;								//任务个数
		string name[NUM_TASKS] = {"A","B"};			//task标识符
		int WCET[NUM_TASKS] = {10,25};     //定义任务执行需要的时间
		int deadline[NUM_TASKS] = {20,50}; //定义第一次任务截止时间
		int period[NUM_TASKS] = {20,50};            //定义经过多长时间以后又会有新的任务加入
		int cycle[NUM_TASKS] = {1,1};				//初始值都为1，1
		int status[NUM_TASKS] = {0,0};				//初始值状态为1，1
		int join[NUM_TASKS] = {0,0};				//加入时间均为0，0
		//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		task_t tasks[NUM_TASKS];
		init_tasks(tasks, name, WCET, deadline, period, cycle, status, join, NUM_TASKS); //初始化任务表

		print_tasks(tasks, NUM_TASKS);
		printf("\nexecution length: %u\n", EXE_LEN);
		char s[1024];
		sprintf(s,"\nexecution length: %u\n", EXE_LEN);
		tool.writeRs(s);

		/**2. 求各个时间点根据算法应该执行的task**/
		string schedule[EXE_LEN];                             //时间序列（执行长度的每一个单位构成时间序列）
		sim_schedule(tasks, NUM_TASKS, schedule, EXE_LEN);
		/**3. 打印完整的时间序列表和缺失值**/
		print_schedule(schedule, tasks, EXE_LEN);//打印最终安排的时间表
	} else if (2==choose){
		//>>>>>>>>>>>>>从文件中读取参数，修改数组长度NUM_TASK，读入各个值
		NUM_TASKS = 4;										//任务个数
		string name[NUM_TASKS] = {"A","B","C","D"};			//任务长度
		int WCET[NUM_TASKS] = {1,2,4,6};			//任务执行时间
		int deadline[NUM_TASKS] = {6,8,12,24};		//任务截止时间
		int period[NUM_TASKS] = {6,8,12,24};		//经过多久进入新的任务
		int cycle[NUM_TASKS] = {1,1,1,1};			//执行周期
		//不变的值统一初始化<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		task_t tasks[NUM_TASKS];
		init_tasks(tasks, name, WCET, period, deadline, cycle, NUM_TASKS);

		print_tasks(tasks, NUM_TASKS);

		char s[1024];
		printf("task %u: idle\n", NUM_TASKS);
		printf("\nexecution length: %u\n", EXE_LEN);

        sprintf(s,"task %u: idle\n", NUM_TASKS);
        tool.writeRs(s);

		sprintf(s,"\nexecution length: %u\n", EXE_LEN);
		write(s);

		string schedule[EXE_LEN];
		sim_schedule2(tasks, NUM_TASKS, schedule, EXE_LEN);
		print_schedule(schedule, tasks, EXE_LEN);
	} else {
		cout<<"输入错误"<<endl;
	}
}
