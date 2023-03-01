// Control.h: interface for the CControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROL_H__42632E0C_2344_4647_B925_BD34D1D8BED2__INCLUDED_)
#define AFX_CONTROL_H__42632E0C_2344_4647_B925_BD34D1D8BED2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "global.h"
class CControl  
{
private:
	job jobs[MAX_NUM];  //储存作业
	int num;     //作业的个数
	void initialJobs();
	int readJobData();
	void getUserChoice();
	void addLog(char *commend);
	void initialJobsAgain();
public:
	void welcome();
	void run();
	CControl();
	virtual ~CControl();

};

#endif // !defined(AFX_CONTROL_H__42632E0C_2344_4647_B925_BD34D1D8BED2__INCLUDED_)
