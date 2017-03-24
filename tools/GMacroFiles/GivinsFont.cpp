
#include "stdafx.h"
#include "GivinsFont.h"
#include <wchar.h>

using namespace GFont;

LOGFONT& GetGivinsFont(int nType)
{
	switch (nType)
	{
		case 0:
		{
			static GIVINS_LF m_staticlf0;
			return m_staticlf0;
		}
		default:
		{
			static GIVINS_LF m_staticlfDef;
			return m_staticlfDef;
		}
	}

}
//
