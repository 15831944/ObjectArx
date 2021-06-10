#pragma once

#define TAG_BUFFER_SIZE 60
#define MSG_BUFFER_SIZE 4096

typedef void(*FNLogEnter)(const TCHAR* tag, const TCHAR* funcname);
typedef void(*FNLogLeave)(const TCHAR* tag, const TCHAR* funcname);
typedef void(*FNLogInfo)(const TCHAR* tag, const TCHAR* message);
typedef void(*FNLogWarning)(const TCHAR* tag, const TCHAR* message);
typedef void(*FNLogError)(const TCHAR* tag, const TCHAR* message);

typedef void(*FNLogInfoFmt)(const TCHAR* tag, const TCHAR* pszFormat, ...);
typedef void(*FNLogWarningFmt)(const TCHAR* tag, const TCHAR* pszFormat, ...);
typedef void(*FNLogErrorFmt)(const TCHAR* tag, const TCHAR* pszFormat, ...);

typedef void(*FNStartTimeCount)(const TCHAR* tag);
typedef void(*FNStopTimeCount)(const TCHAR* tag);

struct LOGFUNCS
{
    DWORD cbSize;
    FNLogEnter mfnLogEnter;
    FNLogLeave mfnLogLeave;
    FNLogInfo mfnLogInfo;
    FNLogWarning mfnLogWarning;
    FNLogError mfnLogError;
    FNLogInfoFmt mfnLogInfoFmt;
    FNLogWarningFmt mfnLogWarningFmt;
    FNLogErrorFmt mfnLogErrorFmt;
    FNStartTimeCount mfnStartTimeCount;
    FNStopTimeCount mfnStopTimeCount;

    LOGFUNCS()
    {
        cbSize = sizeof(LOGFUNCS);
        mfnLogEnter = NULL;
        mfnLogLeave = NULL;
        mfnLogInfo = NULL;
        mfnLogWarning = NULL;
        mfnLogError = NULL;
        mfnLogInfoFmt = NULL;
        mfnLogWarningFmt = NULL;
        mfnLogErrorFmt = NULL;
        mfnStartTimeCount = NULL;
        mfnStopTimeCount = NULL;
    }

    ~LOGFUNCS()
    {
        mfnLogEnter = NULL;
        mfnLogLeave = NULL;
        mfnLogInfo = NULL;
        mfnLogWarning = NULL;
        mfnLogError = NULL;
        mfnLogInfoFmt = NULL;
        mfnLogWarningFmt = NULL;
        mfnLogErrorFmt = NULL;
        mfnStartTimeCount = NULL;
        mfnStopTimeCount = NULL;
    }
};
typedef void(*FNGetLogFuncs)(struct LOGFUNCS* lpLogFuncs);

class AADFuncClass
{
    friend AADFuncClass& AADGetFuncs();

public:
    virtual ~AADFuncClass()
    {
    }

public:
    struct LOGFUNCS mfns;

protected:
    AADFuncClass()
    {
        InitFunctions();
    }

    void InitFunctions()
    {
        TCHAR* pszDllName = _T("AnemoneAdapter.dll");
        HMODULE hInst = ::GetModuleHandle(pszDllName);
        if (hInst == 0)
        {
            hInst = ::LoadLibrary(pszDllName);
            if (hInst == 0)
            {
                DWORD dwError = GetLastError();
                TCHAR str[MSG_BUFFER_SIZE] = { 0 };
                _stprintf(str, _T("LoadLibrary %s failed, error code: %ld"), pszDllName, dwError);
                OutputDebugString((LPCTSTR)str);
                return;
            }
        }

        FNGetLogFuncs fnGetLogFuncs = (FNGetLogFuncs)GetProcAddress(hInst, "GetLogFuncs");
        if (fnGetLogFuncs)
        {
            fnGetLogFuncs(&mfns);
        }
    }
};

inline AADFuncClass& AADGetFuncs()
{
    static AADFuncClass aadfuncs;
    return aadfuncs;
}


class AutoAAD
{
public:
    AutoAAD(const TCHAR* pszFuncName) // 1
    {
        Create(pszFuncName, true);
    }

    AutoAAD(const TCHAR* pszFuncName, bool bAuto) // 2
    {
        Create(pszFuncName, bAuto, false);
    }

    AutoAAD(const TCHAR* pszFuncName, bool bAuto, bool bTime) // 3
    {
        Create(pszFuncName, bAuto, bTime);
    }

    virtual ~AutoAAD()
    {
        Destory();
    }

public:
    virtual void ODS(const TCHAR* msg)
    {
        TCHAR str[MSG_BUFFER_SIZE] = { 0 };
        _stprintf(str, _T("%s, [%s]"), mpszTag, msg);
        OutputDebugString((LPCTSTR)str);
    }

    virtual void ODSFmt(const TCHAR* pszFormat, ...)
    {
        va_list argList;
        va_start(argList, pszFormat);
        TCHAR str[MSG_BUFFER_SIZE] = { 0 };
        _vstprintf(str, pszFormat, argList);
        OutputDebugString((LPCTSTR)str);
        va_end(argList);
    }

public:
    virtual void Enter(const TCHAR* funcname = NULL)
    {
        if (AADGetFuncs().mfns.mfnLogEnter)
        {
            if (funcname && funcname[0])
                AADGetFuncs().mfns.mfnLogEnter(mpszTag, funcname);
            else
                AADGetFuncs().mfns.mfnLogEnter(mpszTag, mpszTag);
        }
    }

    virtual void Leave(const TCHAR* funcname = NULL)
    {
        if (AADGetFuncs().mfns.mfnLogLeave)
        {
            if (funcname && funcname[0])
                AADGetFuncs().mfns.mfnLogLeave(mpszTag, funcname);
            else
                AADGetFuncs().mfns.mfnLogLeave(mpszTag, mpszTag);
        }
    }

public:
    virtual void Info(const TCHAR* msg)
    {
        if (AADGetFuncs().mfns.mfnLogInfoFmt)
            AADGetFuncs().mfns.mfnLogInfoFmt(mpszTag, _T("%s"), msg);
    }

    virtual void InfoFmt(const TCHAR* pszFormat, ...)
    {
        va_list argList;
        va_start(argList, pszFormat);
        TCHAR str[MSG_BUFFER_SIZE] = { 0 };
        _vstprintf(str, pszFormat, argList);
        Info((LPCTSTR)str);
        va_end(argList);
    }

    virtual void Warning(const TCHAR* msg)
    {
        if (AADGetFuncs().mfns.mfnLogWarningFmt)
            AADGetFuncs().mfns.mfnLogWarningFmt(mpszTag, _T("%s"), msg);
    }

    virtual void WarningFmt(const TCHAR* pszFormat, ...)
    {
        va_list argList;
        va_start(argList, pszFormat);
        TCHAR str[MSG_BUFFER_SIZE] = { 0 };
        _vstprintf(str, pszFormat, argList);
        Warning((LPCTSTR)str);
        va_end(argList);
    }

    virtual void Error(const TCHAR* msg)
    {
        if (AADGetFuncs().mfns.mfnLogErrorFmt)
            AADGetFuncs().mfns.mfnLogErrorFmt(mpszTag, _T("%s"), msg);
    }

    virtual void ErrorFmt(const TCHAR* pszFormat, ...)
    {
        va_list argList;
        va_start(argList, pszFormat);
        TCHAR str[MSG_BUFFER_SIZE] = { 0 };
        _vstprintf(str, pszFormat, argList);
        Error((LPCTSTR)str);
        va_end(argList);
    }

public:
    virtual void Mark(int mark, const TCHAR* pszFormat = NULL, ...)
    {
        TCHAR str[MSG_BUFFER_SIZE] = { 0 };
        if (pszFormat && pszFormat[0])
        {
            va_list argList;
            va_start(argList, pszFormat);
            _vstprintf(str, pszFormat, argList);
            va_end(argList);
        }

        if (!str[0])
        {
            if (AADGetFuncs().mfns.mfnLogInfoFmt)
                AADGetFuncs().mfns.mfnLogInfoFmt(mpszTag, _T("Mark %d"), mark);
        }
        else
        {
            if (AADGetFuncs().mfns.mfnLogInfoFmt)
                AADGetFuncs().mfns.mfnLogInfoFmt(mpszTag, _T("Mark %d, %s"), mark, (LPCTSTR)str);
        }
    }

    virtual void Mark(int mark, int submark, const TCHAR* pszFormat = NULL, ...)
    {
        TCHAR str[MSG_BUFFER_SIZE] = { 0 };
        if (pszFormat && pszFormat[0])
        {
            va_list argList;
            va_start(argList, pszFormat);
            _vstprintf(str, pszFormat, argList);
            va_end(argList);
        }

        if (submark == -1)
        {
            if (!str[0])
            {
                if (AADGetFuncs().mfns.mfnLogInfoFmt)
                    AADGetFuncs().mfns.mfnLogInfoFmt(mpszTag, _T("Mark %d"), mark);
            }
            else
            {
                if (AADGetFuncs().mfns.mfnLogInfoFmt)
                    AADGetFuncs().mfns.mfnLogInfoFmt(mpszTag, _T("Mark %d, %d"), mark, (LPCTSTR)str);
            }
        }
        else
        {
            if (!str[0])
            {
                if (AADGetFuncs().mfns.mfnLogInfoFmt)
                    AADGetFuncs().mfns.mfnLogInfoFmt(mpszTag, _T("Mark %d.%d"), mark, submark);
            }
            else
            {
                if (AADGetFuncs().mfns.mfnLogInfoFmt)
                    AADGetFuncs().mfns.mfnLogInfoFmt(mpszTag, _T("Mark %d.%d, %s"), mark, submark, (LPCTSTR)str);
            }
        }
    }

    virtual void StartTimeCount(const TCHAR* tag)
    {
        if (AADGetFuncs().mfns.mfnStartTimeCount)
            AADGetFuncs().mfns.mfnStartTimeCount(tag);
    }

    virtual void StopTimeCount(const TCHAR* tag)
    {
        if (AADGetFuncs().mfns.mfnStopTimeCount)
            AADGetFuncs().mfns.mfnStopTimeCount(tag);
    }

    virtual void PushString(const TCHAR* pszFormat, ...)
    {
        va_list argList;
        va_start(argList, pszFormat);
        TCHAR str[MSG_BUFFER_SIZE] = {0};
        _vstprintf(str, pszFormat, argList);
        if (str[0])
        {
            if (_tcslen(msMsg) >= (MSG_BUFFER_SIZE - 1))
            {
                if (_tcslen(str) > 0)
                {
                    msMsg[MSG_BUFFER_SIZE - 4] = _T('.');
                    msMsg[MSG_BUFFER_SIZE - 3] = _T('.');
                    msMsg[MSG_BUFFER_SIZE - 2] = _T('.');
                }
                msMsg[MSG_BUFFER_SIZE - 1] = _T('\0');
            }
            else if ((_tcslen(msMsg) + _tcslen(str)) > (MSG_BUFFER_SIZE - 1))
            {
                str[(MSG_BUFFER_SIZE - 1) - _tcslen(msMsg)] = _T('\0');
                _tcscat(msMsg, str);
            }
            else
            {
                _tcscat(msMsg, str);
            }
        }
        va_end(argList);
    }

    virtual void FlushString()
    {
        Info(msMsg);
        msMsg[0] = 0;
    }

protected:
    virtual void Create(const TCHAR* tag = NULL, bool bAuto = true, bool bTime = false)
    {
        mpszTag = msTag;
        memset(mpszTag, 0, TAG_BUFFER_SIZE * sizeof(TCHAR));

        if (tag && tag[0])
            _tcscpy_s(mpszTag, TAG_BUFFER_SIZE-1, tag);
        mbAuto = bAuto;
        mbTime = bTime;
        msMsg[0] = 0;

        if (mbAuto)
        {
            if (AADGetFuncs().mfns.mfnLogEnter)
                AADGetFuncs().mfns.mfnLogEnter(mpszTag, mpszTag);
        }

        if (mbTime && mpszTag && mpszTag[0])
        {
            if (AADGetFuncs().mfns.mfnStartTimeCount)
                AADGetFuncs().mfns.mfnStartTimeCount(mpszTag);
        }
    }

    virtual void Destory()
    {
        if (mbTime && mpszTag && mpszTag[0])
        {
            if (AADGetFuncs().mfns.mfnStopTimeCount)
                AADGetFuncs().mfns.mfnStopTimeCount(mpszTag);
        }

        if (mbAuto)
        {
            if (AADGetFuncs().mfns.mfnLogLeave)
                AADGetFuncs().mfns.mfnLogLeave(mpszTag, mpszTag);
        }
    }

protected:
    TCHAR msTag[TAG_BUFFER_SIZE];
    TCHAR* mpszTag;
    bool mbAuto;
    bool mbTime;
    TCHAR msMsg[MSG_BUFFER_SIZE];
};


#define AADGETSTR(p, func) (p ? p->func() : _T("(null)"))
#define AADYESNOSTR(b) (b ? _T("YES") : _T("NO"))
#define AADTRUEFALSESTR(b) (b ? _T("TRUE") : _T("FALSE"))

#ifndef AA
#define AA(...) AutoAAD aa(_T(__FUNCTION__), __VA_ARGS__)
#endif

#ifndef AAINFO
#define AAINFO(fmt, ...) aa.InfoFmt(fmt, __VA_ARGS__)
#endif

#ifndef AAWARNING
#define AAWARNING(fmt, ...) aa.WarningFmt(fmt, __VA_ARGS__)
#endif

#ifndef AAERROR
#define AAERROR(fmt, ...) aa.ErrorFmt(fmt, __VA_ARGS__)
#endif

class AutoTimeCount
{
public:
    AutoTimeCount(LPCTSTR tag)
        : aa(_T("ATC"), false)
    {
        if (tag && tag[0])
            _tcscpy_s(msTag, TAG_BUFFER_SIZE-1, tag);
        else
            _tcscpy_s(msTag, TAG_BUFFER_SIZE-1, _T("notag"));
        aa.StartTimeCount(msTag);
    }
    virtual ~AutoTimeCount()
    {
        aa.StopTimeCount(msTag);
    }
private:
    AutoAAD aa;
    TCHAR msTag[TAG_BUFFER_SIZE];
};


#ifndef ATC
#define ATC(x) AutoTimeCount atc(x)
#endif



