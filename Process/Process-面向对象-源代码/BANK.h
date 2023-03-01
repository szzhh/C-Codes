// BANK.h: interface for the BANK class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BANK_H__FDDC264E_CDC5_4FB4_B868_0D6253293D66__INCLUDED_)
#define AFX_BANK_H__FDDC264E_CDC5_4FB4_B868_0D6253293D66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class BANK  
{
public:
	BANK();
	virtual ~BANK();
	void doBank();

private:
	void showInfo(int resourceNum, int available[], int processNum, int **maxRequest, int **allocation, int **need);
	void SafeInfo(int *work, int i, int resourceNum, int **allocation, int **need);
	bool isAllZero(int kang, int num, int resourceNum, int **need);
	bool isSafe(int resourceNum, int num, int **need, int **allocation, int safeSeries[], int available[], int processNum, bool Finish[]);
};

#endif // !defined(AFX_BANK_H__FDDC264E_CDC5_4FB4_B868_0D6253293D66__INCLUDED_)
