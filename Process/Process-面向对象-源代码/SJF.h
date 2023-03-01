// SJF.h: interface for the SJF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SJF_H__988E2FC2_910F_4B7B_813B_ECDF185E1DC9__INCLUDED_)
#define AFX_SJF_H__988E2FC2_910F_4B7B_813B_ECDF185E1DC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Global.h"

class SJF  
{
public:
	void doSJF(job jobs[],int num);
	SJF();
	virtual ~SJF();

private:
	int findNextSJF(job j[MAX_NUM], int length,int time );
};

#endif // !defined(AFX_SJF_H__988E2FC2_910F_4B7B_813B_ECDF185E1DC9__INCLUDED_)
