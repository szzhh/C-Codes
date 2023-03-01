// HRRF.h: interface for the HRRF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HRRF_H__C50F4BA0_E712_4F72_8EB6_C09E57906B19__INCLUDED_)
#define AFX_HRRF_H__C50F4BA0_E712_4F72_8EB6_C09E57906B19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Global.h"

class HRRF  
{
public:
	void doHRRF(job jobs[], int num);
	HRRF();f
	virtual ~HRRF();

private:
	int findNextHRRF(int pre,job jobs[],int num);
};

#endif // !defined(AFX_HRRF_H__C50F4BA0_E712_4F72_8EB6_C09E57906B19__INCLUDED_)
