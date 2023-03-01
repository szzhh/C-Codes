// RR.h: interface for the RR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RR_H__0D00AC3F_AE91_4907_A65F_FF5ECB98262B__INCLUDED_)
#define AFX_RR_H__0D00AC3F_AE91_4907_A65F_FF5ECB98262B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Global.h"

class RR  
{
public:
	void doRR(job jobs[], int num);
	RR();
	virtual ~RR();

private:
	void initial_job_List(job jobs[],int num);
	static bool cmp(job a, job b);
};

#endif // !defined(AFX_RR_H__0D00AC3F_AE91_4907_A65F_FF5ECB98262B__INCLUDED_)
