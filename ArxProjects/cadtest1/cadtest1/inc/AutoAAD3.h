#pragma once

#include "AutoAAD2.h"
#include "acedads.h"

class AutoAAD3 : public AutoAAD2
{
public:
    AutoAAD3(const TCHAR* pszFuncName) // 1
        : AutoAAD2(pszFuncName)
    {

    }

    AutoAAD3(const TCHAR* pszFuncName, bool bAuto) // 2
        £º AutoAAD2(pszFuncName, bAuto)
    {

    }

    AutoAAD3(const TCHAR* pszFuncName, bool bAuto, bool bTime) // 3
        : AutoAAD2(pszFuncName, bAuto, bTime)
    {

    }

    virtual ~AutoAAD3()
    {

    }

public:
    virtual void InfoSysVar(LPCTSTR pVarName)
    {
        resbuf* rb = acutNewRb(RTT);
        if (rb)
        {
            memset(rb, 0, sizeof(resbuf));
            if (RTNORM == acedGetVar(pVarName, rb))
            {
                AcString dxfCodeStr, valueStr;
                dxfToStr(rb, dxfCodeStr, valueStr);
                AutoAAD::InfoFmt(_T("SYSVAR %s: (%s . %s)"), dxfCodeStr.kTCharPtr(), valueStr.kTCharPtr());
            }
            acutRelRb(rb);
            rb = NULL;
        }
    }

};



#ifndef AA3
#define AA3(...) AutoAAD3 aa(_T(__FUNCTION__), __VA_ARGS__)
#endif


