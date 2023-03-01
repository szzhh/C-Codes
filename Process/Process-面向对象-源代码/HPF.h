// HPF.h: interface for the HPF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HPF_H__AAFF35A6_8904_493A_955A_3F543CA9D1B5__INCLUDED_)
#define AFX_HPF_H__AAFF35A6_8904_493A_955A_3F543CA9D1B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Global.h"

class HPF  
{
private:
	int findNextHPF(job j[MAX_NUM], int length, int time, job jobs[], int num);
public:
	void doHPF(job jobs[],int num);	
	HPF();
	virtual ~HPF();

};

#endif // !defined(AFX_HPF_H__AAFF35A6_8904_493A_955A_3F543CA9D1B5__INCLUDED_)
