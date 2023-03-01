// Tool.cpp: implementation of the Tool class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Tool.h"

#include <fstream>
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Tool::Tool()
{

}

Tool::~Tool()
{

}


void Tool::writeRs(char *data)  // 把输出结果保存到文件
{
	// 以写模式打开文件
	ofstream outfile;
	outfile.open("output.txt", ios::app);
	// 向文件写入用户输入的数据
	outfile << data << endl;
    // 关闭打开的文件
	outfile.close();
}
void Tool::writeLog(char *log)  // 保存日志 
{
	// 以写模式打开文件
	ofstream outfile;
	outfile.open("log.txt", ios::app);
	// 向文件写入用户输入的数据
	outfile << log << endl;
    // 关闭打开的文件
	outfile.close();
}

