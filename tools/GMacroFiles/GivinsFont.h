/***************************************************************************************************
  *Copyright(C),2017-2020,Sumscope
  *FileName	:  GivinsFont
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/03/22
  *Desc		:  ×ÖÌå
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  Givins.zhu@sumscope.com  
***************************************************************************************************/

#pragma  once
#include <shtypes.h>
#include <tchar.h>
#include <wchar.h>
#include "stdafx.h"
#include <shtypes.h>

namespace GFont{
	class GIVINS_LF :public LOGFONT
	{
	public:
		GIVINS_LF(int nHt = 22, int nWd = 0, int nWgt = FW_BLACK, int nUnd = 0, CString faceName = _T("Î¢ÈíÑÅºÚ")){
			lfHeight = nHt;
			lfWidth = nWd;
			lfWeight = nWgt;
			lfUnderline = nUnd;
			wcscpy_s(lfFaceName, faceName);
		}
		//~GIVINS_LF();
	};


}
/*MACRO_API*/ MACRO_API LOGFONT& GetGivinsFont(int nType = 0);
