#pragma once

#include "AutoAAD.h"
#include "acutads.h"
#include "adscodes.h"
#include "AcString.h"
#include "dbid.h"
#include "acutmem.h"
#include "acedads.h"

class AutoAAD2 : public AutoAAD
{
public:
    AutoAAD2(const TCHAR* pszFuncName) // 1
        : AutoAAD(pszFuncName)
    {

    }

    AutoAAD2(const TCHAR* pszFuncName, bool bAuto) // 2
        : AutoAAD(pszFuncName, bAuto)
    {

    }

    AutoAAD2(const TCHAR* pszFuncName, bool bAuto, bool bTime) // 3
        : AutoAAD(pszFuncName, bAuto, bTime)
    {

    }

    virtual ~AutoAAD2()
    {

    }

public:
    virtual void InfoResbuf(const resbuf* pRb)
    {
        AcString msg(_T("resbuf = "));
        AcString tmpStr = ResbufToStr(pRb);
        msg += tmpStr;
        AutoAAD::Info(msg.kTCharPtr());
    }

    virtual void InfoPoint(double* val)
    {
        AutoAAD::InfoFmt(_T("ads_point = %s"), PointToStr(val).kTCharPtr());
    }

    virtual void InfoObjectId(const AcDbObjectId& oid)
    {
        AutoAAD::InfoFmt(_T("oid: %s"), ObjectIdToStr(oid).kTCharPtr());
    }

    virtual void DumpDbObj(const AcDbObjectId& oid)
    {
        ads_name ent;
        acdbGetAdsName(ent, oid);

        // get entity data the ADS way (as DXF codes)
        resbuf* apps = acutNewRb(RTSTR);
        acutNewString(_T("*"), apps->resval.rstring);
        resbuf* entdata = acdbEntGetX(ent, apps);
        acutRelRb(apps);
        if (entdata)
        {
            AutoAAD::PushString(_T("Dump Db Object: \n"));
            AcString dxfCodeStr, valueStr;
            try
            {
                resbuf* tmp = entdata;
                int row = 0;
                while (tmp) {
                    dxfToStr(tmp, dxfCodeStr, valueStr);
                    AutoAAD::PushString(_T("%5s, %s\n"), dxfCodeStr.kTCharPtr(), valueStr.kTCharPtr());
                    tmp = tmp->rbnext;
                }
            }
            catch (CMemoryException* e)
            {
                AutoAAD::PushString(_T("CMemoryException occured!"));
            }
            catch (CFileException* e)
            {
                AutoAAD::PushString(_T("CFileException occured!"));
            }
            catch (CException* e)
            {
                AutoAAD::PushString(_T("CException occured!"));
            }
            catch (...)
            {
                AutoAAD::PushString(_T("Other exception occured!"));
            }
            AutoAAD::FlushString();
            acutRelRb(entdata);
        }
    }

    virtual void DumpDbObj(const AcDbObject* pObj)
    {
        if (!pObj)
            return;
        DumpDbObj(pObj->objectId());
    }

public:
    virtual AcString ResbufToStr(const resbuf* pRb, bool one = false)
    {
        AcString str;
        AcString dxfCodeStr, valueStr, tmpStr;
        const resbuf* tmp = pRb;
        if (tmp)
        {
            while (tmp)
            {
                dxfToStr(tmp, dxfCodeStr, valueStr);
                tmpStr.format(_T("(%s . %s)"), dxfCodeStr.kTCharPtr(), valueStr.kTCharPtr());
                str += tmpStr;
                if (one)
                    break;
                tmp = tmp->rbnext;
            }
        }
        else
        {
            str += _T("null");
        }
        return str;
    }

    virtual AcString ObjectIdToStr(const AcDbObjectId& oid)
    {
        ACHAR hand[16] = { 0 };
        oid.handle().getIntoAsciiBuffer(hand);
        AcString str;
        str.format(_T("<handle: %s>"), hand);
        return str;
    }

    virtual AcString PointToStr(double* val)
    {
        AcString str;
        str.format(_T("(%g, %g, %g)"), val[0], val[1], val[2]);
        return str;
    }

private:
    int dxfCodeToDataType(int resType)
    {
        // which data type is this value
        if ((resType >= 0) && (resType <= 9))
            return RTSTR;
        else if ((resType >= 10) && (resType <= 17))
            return RT3DPOINT;
        else if ((resType >= 38) && (resType <= 59))
            return RTREAL;
        else if ((resType >= 60) && (resType <= 79))
            return RTSHORT;
        else if ((resType >= 90) && (resType <= 99))
            return RTLONG;
        else if ((resType == 100) || (resType == 101) || (resType == 102) || (resType == 105))
            return RTSTR;
        else if ((resType >= 110) && (resType <= 119))
            return RT3DPOINT;
        else if ((resType >= 140) && (resType <= 149))
            return RTREAL;
        else if ((resType >= 170) && (resType <= 179))
            return RTSHORT;
        else if ((resType >= 210) && (resType <= 219))
            return RT3DPOINT;
        else if ((resType >= 270) && (resType <= 299))
            return RTSHORT;
        else if ((resType >= 300) && (resType <= 309))
            return RTSTR;
        else if ((resType >= 310) && (resType <= 369))
            return RTENAME;
        else if ((resType >= 370) && (resType <= 379))
            return RTSHORT;
        else if ((resType >= 380) && (resType <= 389))
            return RTSHORT;
        else if ((resType >= 390) && (resType <= 399))
            return RTENAME;
        else if ((resType >= 400) && (resType <= 409))
            return RTSHORT;
        else if ((resType >= 410) && (resType <= 419))
            return RTSTR;
        else if (resType == 1004)
            return resType;        // binary chunk
        else if ((resType >= 999) && (resType <= 1009))
            return RTSTR;
        else if ((resType >= 1010) && (resType <= 1013))
            return RT3DPOINT;
        else if ((resType >= 1038) && (resType <= 1059))
            return RTREAL;
        else if ((resType >= 1060) && (resType <= 1070))
            return RTSHORT;
        else if ((resType == 1071))
            return RTLONG;
        else if ((resType < 0) || (resType > 4999))
            return resType;
        else
            return RTNONE;
    }

    // Unicode: Leaving as char type because it is a buffer
    LPCTSTR bytesToHexStr(char* buffer, int len, CString& hexStr)
    {
        // Unicode: Leaving as char type because it is a byte
        unsigned char k;
        int j;
        CString tmpStr;

        hexStr.Empty();    // make sure nothing in it yet since we are concatenating it

        for (j = 0; j<len; j++) {
            k = static_cast<unsigned char>(buffer[j]);
            tmpStr.Format(_T("%02hX"), k);
            hexStr += tmpStr;
        }
        return hexStr;
    }

    void dxfToStr(const resbuf* rb, AcString& dxfCodeStr, AcString& valueStr)
    {
        int dataType = dxfCodeToDataType(rb->restype);
        dxfCodeStr.format(_T("%d"), rb->restype);

        CString tmpStr;

        switch (dataType) {
        case RTSHORT:
            valueStr.format(_T("%d"), rb->resval.rint);
            break;
        case RTLONG:
            valueStr.format(_T("%ld"), rb->resval.rlong);
            break;
        case RTREAL:
            valueStr.format(_T("%g"), rb->resval.rreal);
            break;
        case RTSTR:
            if (rb->resval.rstring == NULL)
                valueStr = _T("(NULL)");
            else
                valueStr.format(_T("\"%s\""), rb->resval.rstring);
            break;
        case RT3DPOINT:
            valueStr.format(_T("(%g, %g, %g)"), rb->resval.rpoint[X],
                rb->resval.rpoint[Y], rb->resval.rpoint[Z]);
            break;
        case RTPOINT:
            valueStr.format(_T("(%g, %g)"), rb->resval.rpoint[X], rb->resval.rpoint[Y]);
            break;
        case 1004:
            valueStr.format(_T("Binary Chunk: \"%s\""),
                bytesToHexStr(rb->resval.rbinary.buf,
                    rb->resval.rbinary.clen, tmpStr));
            break;
        case -6:
            valueStr = _T("Extension Dictionary");
            break;
        case -5:
            valueStr = _T("Persistent Reactors");
            break;
        case -4:
            valueStr.format(_T("Conditional Operator: \"%s\""), rb->resval.rstring);
            break;
        case -3:
            valueStr = _T("Start of Xdata");
            break;
        case -2:
            valueStr.format(_T("<Entity Name Reference: %8lx>"), rb->resval.rlname[0]);
            break;
        case -1:
        case RTENAME:
            if ((rb->restype >= 330) && (rb->restype < 340))
                valueStr.format(_T("<Soft Pointer: %8lx>"), rb->resval.rlname[0]);
            else if ((rb->restype >= 340) && (rb->restype < 350))
                valueStr.format(_T("<Hard Pointer: %8lx>"), rb->resval.rlname[0]);
            else if ((rb->restype >= 350) && (rb->restype < 360))
                valueStr.format(_T("<Soft Ownership: %8lx>"), rb->resval.rlname[0]);
            else if ((rb->restype >= 360) && (rb->restype < 370))
                valueStr.format(_T("<Hard Ownership: %8lx>"), rb->resval.rlname[0]);
            else if ((rb->restype >= 390) && (rb->restype < 399))
                valueStr.format(_T("<Hard Pointer: %8lx>"), rb->resval.rlname[0]);
            else
                valueStr.format(_T("<Entity Name: %8lx>"), rb->resval.rlname[0]);
            break;
        case RTPICKS:
            valueStr.format(_T("<Selection Set: %8lx>"), rb->resval.rlname[0]);
            break;
        case RTLB:
            valueStr = _T("List Begin");
            break;
        case RTLE:
            valueStr = _T("List End");
            break;
        case RTNIL:
            valueStr = _T("NIL");
            break;
        case RTT:
            valueStr = _T("T");
            break;
        default:
            valueStr = _T("*Unknown*");
            break;
        }
    }

};


#ifndef AA2
#define AA2(...) AutoAAD2 aa(_T(__FUNCTION__), __VA_ARGS__)
#endif


