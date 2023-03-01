// FCFS.h: interface for the FCFS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FCFS_H__264CC14A_493D_446D_9CBF_B172BD40A8E9__INCLUDED_)
#define AFX_FCFS_H__264CC14A_493D_446D_9CBF_B172BD40A8E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Global.h"
class FCFS  
{
private:
	int ready[MAX_NUM];
	//记录排序使用哪个数值作为排序对象
	int order[MAX_NUM];
public:
	FCFS();
	virtual ~FCFS();
	void doFCFS(job jobs[],  int num);
};

#endif // !defined(AFX_FCFS_H__264CC14A_493D_446D_9CBF_B172BD40A8E9__INCLUDED_)
