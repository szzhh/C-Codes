// Tool.h: interface for the Tool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOL_H__78CBFDFF_25A4_48DD_AE16_684B90AD7D63__INCLUDED_)
#define AFX_TOOL_H__78CBFDFF_25A4_48DD_AE16_684B90AD7D63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Tool
{
public:
	void writeRs(char *data);
	void writeLog(char *log);
	Tool();
	virtual ~Tool();

};

#endif // !defined(AFX_TOOL_H__78CBFDFF_25A4_48DD_AE16_684B90AD7D63__INCLUDED_)
