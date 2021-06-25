/////////////////////////////////////////////////////////////////////////////
// SlbMan.cpp

#include "StdAfx.h"
#include "CSlb.h"


struct SlbHeadStruct
{
	char pszName[32];

	DWORD dwOffset;
	int nSize;
	
	BOOL bInMem;
	BOOL bDelete;
};

/////////////////////////////////////////////////////////////////////////////
// Constructor and Destructor

CSlb::CSlb()
{
	slbHeadSize = 128;
	slbDataSize = 4 * 1024;
	
	hSlbHead = GlobalAlloc(GMEM_MOVEABLE, sizeof(SlbHeadStruct)*slbHeadSize);
	hSlbData = GlobalAlloc(GMEM_MOVEABLE, slbDataSize);
	nTotalSlides = 0;
	dwDataBufTail = 0;
	pszSlbPathName[0] = '\0';
	bModified = FALSE;
}

CSlb::~CSlb()
{	
	GlobalFree (hSlbHead);
	GlobalFree (hSlbData);

	pszSlbPathName[0] = '\0';
}

/////////////////////////////////////////////////////////////////////////////
// File load and save proc
BOOL CSlb::OnNewDocument ()
{
	DeleteContents ();
	SetPathName (_T(""));
	SetModifiedFlag (FALSE);
	return TRUE;
}

BOOL CSlb::OnOpenDocument(const TCHAR *pszFileName)
{
	DWORD dwBytesRead;
	TCHAR pszTempFileName[MAX_PATH];
	DWORD dwFileSize;
	HANDLE hFileSlb;

	DeleteContents();

	lstrcpy (pszTempFileName,pszFileName);
 	SetPathName (pszTempFileName);

	hFileSlb=CreateFile(
		pszTempFileName,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
		);

 	if (hFileSlb == INVALID_HANDLE_VALUE)
	{
		MessageBox(GetActiveWindow (),_T("Slide File open error!"),_T("ERROR"),MB_OK);
		return FALSE;
	} 

	dwFileSize=GetFileSize(hFileSlb,NULL);

	if ( dwFileSize < 68 ) 
	{
		TCHAR buffer[MAX_PATH];

		CloseHandle(hFileSlb);
		wsprintf(buffer,_T("%s is not a valid .slb file."),pszFileName);//modify by UNICODE 2013 10 18
		MessageBox(GetActiveWindow (),buffer,_T("ERROR"),MB_OK|MB_ICONSTOP);
		return 0;
	}

	SlbHeadStruct *pSlbHead = (SlbHeadStruct *)/*GlobalLock*/ (hSlbHead);

	SetFilePointer(hFileSlb,32,NULL,FILE_BEGIN);
	int nSldsInSlb=0;

	do{

		if ( ! ReadFile(hFileSlb,&(pSlbHead[nSldsInSlb].pszName),
			sizeof(char [32]),&dwBytesRead,NULL))
		{
			MessageBox(GetActiveWindow (),pszTempFileName,_T("ERROR"),MB_OK);
			CloseHandle(hFileSlb);
			GlobalUnlock(hSlbHead);
			GlobalFree (hSlbHead);
			return FALSE;
		}
		
		if (dwBytesRead!=sizeof(char[32])) 
		{
			TCHAR buffer[MAX_PATH];
			wsprintf(buffer,_T("%s is not a valid .slb file."),pszFileName);
			MessageBox(GetActiveWindow (),buffer,_T("ERROR"),MB_OK|MB_ICONSTOP);
			CloseHandle(hFileSlb);
			GlobalUnlock(hSlbHead);
			GlobalFree (hSlbHead);
			return FALSE;
		}
		
		if ( ! ReadFile(hFileSlb,&(pSlbHead[nSldsInSlb].dwOffset),
			sizeof(DWORD),&dwBytesRead,NULL))
		{
			MessageBox(GetActiveWindow (),pszTempFileName,_T("ERROR"),MB_OK);
			CloseHandle(hFileSlb);
			GlobalUnlock(hSlbHead);
			GlobalFree (hSlbHead);
			return FALSE;
		}

		if (dwBytesRead!=sizeof(DWORD))
		{

			TCHAR buffer[MAX_PATH];
//modify by UNICODE 2013 1018
			wsprintf(buffer,_T("%s is not a valid .slb file."),pszTempFileName);//modify by UNICODE 2013 10 18
			MessageBox(GetActiveWindow (),buffer,_T("ERROR"),MB_OK|MB_ICONSTOP);
			CloseHandle(hFileSlb);
			GlobalUnlock(hSlbHead);
			GlobalFree (hSlbHead);
			return FALSE;
		}

		pSlbHead[nSldsInSlb].bInMem = FALSE;
		pSlbHead[nSldsInSlb].bDelete = FALSE;

		if (pSlbHead[nSldsInSlb].dwOffset == 0)
			break;

		nSldsInSlb++;

		if (nSldsInSlb >= /*(int)( GlobalSize (hSlbHead) / sizeof (SlbHeadStruct))*/slbHeadSize)
		{
			GlobalUnlock ( hSlbHead);
			hSlbHead = GlobalReAlloc (hSlbHead, 
				/*GlobalSize (hSlbHead)*/(slbHeadSize + 128) * sizeof (SlbHeadStruct),
				GMEM_MOVEABLE);
			pSlbHead = (SlbHeadStruct *) /*GlobalLock*/(hSlbHead);
			slbHeadSize += 128; 
		}

	} while (TRUE);
	nTotalSlides = nSldsInSlb;

	int i = 0;
	for (i = 0; i < nTotalSlides - 1; i++)
	{
		pSlbHead[i].nSize = pSlbHead[i+1].dwOffset - pSlbHead[i].dwOffset;
	}
	pSlbHead[i].nSize = dwFileSize - pSlbHead[i].dwOffset;

	CloseHandle (hFileSlb);
	GlobalUnlock (hSlbHead);

	return TRUE;
}


//modify by UNICODE 2013 10 18

BOOL CSlb::OnSaveDocument(const TCHAR *lpszPathName)
{
	DWORD dwBytesRead, dwBytesWritten;
	HANDLE hFileSrc = CreateFile(pszSlbPathName, GENERIC_READ,
		0,NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFileSrc==INVALID_HANDLE_VALUE) 
		return FALSE;

	TCHAR pszPath[MAX_PATH];
	TCHAR pszTempFileName[MAX_PATH];

	lstrcpy (pszPath, lpszPathName);
	DockPathName (pszPath);
	GetTempFileName (pszPath, _T("temp"), 0, pszTempFileName); 
	HANDLE hFileDes = CreateFile(pszTempFileName, GENERIC_WRITE,
		0,NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFileDes == INVALID_HANDLE_VALUE) 
	{
		CloseHandle (hFileSrc);
		return FALSE;
	}

	SlbHeadStruct *pSlbHead = (SlbHeadStruct *)/*GlobalLock*/ (hSlbHead);
	BYTE *pSlbData = (BYTE *)/*GlobalLock*/ (hSlbData);

	char pszHeadTitle[] = "AutoCAD Slide Library 1.0\13\10\26\0\0\0\0";
	WriteFile (hFileDes, pszHeadTitle, 32, &dwBytesWritten, NULL);

	int nTotalSlidesNew = 0;
	for (int i = 0; i < nTotalSlides; i ++)
		if (! pSlbHead[i].bDelete) nTotalSlidesNew ++;

	DWORD dwCurrentOffset = 32 + 36 + 36 * nTotalSlidesNew;
	for (int i = 0; i < nTotalSlides; i ++)
	{
		if (pSlbHead[i].bDelete) continue;
		WriteFile (hFileDes, pSlbHead[i].pszName, 32, &dwBytesWritten, NULL);
		WriteFile (hFileDes, &dwCurrentOffset, 4, &dwBytesWritten, NULL);
		dwCurrentOffset += pSlbHead[i].nSize;
	}

	BYTE pZeroBuffer[36];
	memset (pZeroBuffer, 0, 36);
	WriteFile (hFileDes, pZeroBuffer, 36, &dwBytesWritten, NULL);

	int bufferSize = 4 * 1024;
	HANDLE hBuffer = GlobalAlloc(GMEM_MOVEABLE, bufferSize);
	BYTE *pBuffer = (BYTE *)/*GlobalLock*/ (hBuffer);
	for (int i = 0; i<nTotalSlides; i++)
	{
		if (pSlbHead[i].bDelete) continue;
		if (pSlbHead[i].bInMem)
		{
			WriteFile (hFileDes,pSlbData + pSlbHead[i].dwOffset, pSlbHead[i].nSize,
				&dwBytesWritten, NULL);
		}
		else
		{
			if (pSlbHead[i].nSize > /*(int) GlobalSize (hBuffer)*/ bufferSize)
			{
				GlobalUnlock (hBuffer);
				hBuffer = GlobalReAlloc (hBuffer, pSlbHead[i].nSize, GMEM_MOVEABLE);
				pBuffer = (BYTE *)/*GlobalLock*/ (hBuffer);
				bufferSize = pSlbHead[i].nSize;
			}
			SetFilePointer (hFileSrc, pSlbHead[i].dwOffset, NULL, FILE_BEGIN);
			ReadFile (hFileSrc, pBuffer, pSlbHead[i].nSize, &dwBytesRead, NULL);
			WriteFile (hFileDes, pBuffer, pSlbHead[i].nSize, &dwBytesWritten, NULL);
		}
	}
	CloseHandle (hFileSrc);
	CloseHandle (hFileDes);
	DeleteFile (lpszPathName);
#ifdef _ZW_WINDOWS
	MoveFile (pszTempFileName, lpszPathName);
#endif 

	int j = 0;
	dwCurrentOffset = 32 + 36 + 36 * nTotalSlidesNew;
	for (int i = 0; i < nTotalSlides; i++)
	{
		if (pSlbHead[i].bDelete) continue;

		pSlbHead[j].dwOffset = dwCurrentOffset;
		pSlbHead[j].bDelete = FALSE;
		pSlbHead[j].bInMem = FALSE;
		pSlbHead[j].nSize = pSlbHead[i].nSize;
		strcpy (pSlbHead[j].pszName, pSlbHead[i].pszName);
		dwCurrentOffset += pSlbHead[i].nSize;
		j ++;
	}
	nTotalSlides = j;
	bModified = FALSE;


	dwDataBufTail = 0;
	hSlbData = GlobalReAlloc (hSlbData, 4 * 1024, GMEM_MOVEABLE);
	slbDataSize = 4 * 1024;

	return TRUE;
}
 //modify by UNICODE 2013 10 18
BOOL CSlb::DeleteContents()
{
	hSlbHead = GlobalReAlloc (hSlbHead, 128 * sizeof (SlbHeadStruct), GMEM_MOVEABLE);
	hSlbData = GlobalReAlloc (hSlbData, 4*1024, GMEM_MOVEABLE);
	slbDataSize = 4 * 1024;
	slbHeadSize = 128;
	
	nTotalSlides = 0;
	dwDataBufTail = 0;
	SetModifiedFlag (TRUE);
	return TRUE;
}

void CSlb::SetPathName(const TCHAR *lpszSlbPathName)
{
	lstrcpy(pszSlbPathName,lpszSlbPathName);
}

void CSlb::GetPathName(TCHAR *lpszSlbPathName)
{
	lstrcpy(lpszSlbPathName,pszSlbPathName);
}

int CSlb::AddSlide( const TCHAR *lpszSlideName,
				   const BYTE *lpSlideData,
				   int nSlideSize)
{
	if (/*GlobalSize (hSlbHead)*/slbHeadSize < /*sizeof(SlbHeadStruct) * */(nTotalSlides + 1))
	{
		hSlbHead = GlobalReAlloc (hSlbHead, /*GlobalSize (hSlbHead)*/(slbHeadSize + 128) * sizeof (SlbHeadStruct), 
			GMEM_MOVEABLE);
		slbHeadSize = slbHeadSize + 128;
	}

	if (/*(GlobalSize (hSlbData))*/slbDataSize <= dwDataBufTail + nSlideSize)
	{
		DWORD dwSize = ((dwDataBufTail + nSlideSize) / (4 * 1024) + 1) * (4*1024);
		hSlbData = GlobalReAlloc (hSlbData, dwSize, GMEM_MOVEABLE);
		slbDataSize = dwSize;
	}
	SlbHeadStruct *pSlbHead = (SlbHeadStruct *) /*GlobalLock*/ (hSlbHead);
	BYTE *pSlbData = (BYTE *) /*GlobalLock*/ (hSlbData);

	int i = 0;
	for (i = 0; i < nTotalSlides; i++)
	{
		ZcString str(pSlbHead[i].pszName);
#ifdef _UNICODE
		//if (!lstrcmpi(lpszSlideName, /*CA2W(pSlbHead[i].pszName)*/str.kwszPtr()))
		if(!_tcscmp(lpszSlideName, str.kwszPtr()))
#else
		if (!lstrcmp (lpszSlideName ,pSlbHead[i].pszName))
#endif
			break;
	}

	ZcString temp(lpszSlideName);
#ifdef _UNICODE
	strcpy (pSlbHead[i].pszName, /*CW2A(lpszSlideName)*/temp.ansiPtr());
#else
	strcpy (pSlbHead[i].pszName, lpszSlideName);
#endif
	pSlbHead[i].dwOffset = dwDataBufTail;
	pSlbHead[i].nSize = nSlideSize;
	pSlbHead[i].bInMem = TRUE;
	pSlbHead[i].bDelete = FALSE;

	if (i == nTotalSlides)
		nTotalSlides ++;

	memcpy (pSlbData + dwDataBufTail, lpSlideData, nSlideSize);
	dwDataBufTail += nSlideSize;

	GlobalUnlock (hSlbHead);
	GlobalUnlock (hSlbData);
	SetModifiedFlag (TRUE);

	return i;
}


BOOL CSlb::DelSlide (const TCHAR *lpszSlideName)
{
	int n = GetSlideNo (lpszSlideName);
	if (n < 0 || n >= nTotalSlides) return FALSE;
	return DelSlide (n);
}
 //modify by UNICODE 2013 10 18
BOOL CSlb::DelSlide(int nSequenceNo)
{
	ASSERT (nSequenceNo >= 0 && nSequenceNo < nTotalSlides);

	SlbHeadStruct *pSlbHead = (SlbHeadStruct *)/*GlobalLock*/ (hSlbHead);
	pSlbHead[nSequenceNo].bDelete = TRUE;
	GlobalUnlock (hSlbHead);
	SetModifiedFlag (TRUE);

	return TRUE;
}


BOOL CSlb::GetSlideName (int n, TCHAR *lpszSlideName)
{
	ASSERT (n >= 0 && n < nTotalSlides);
	SlbHeadStruct * pSlbHead = (SlbHeadStruct *)/*GlobalLock*/ (hSlbHead);
	ZcString str(pSlbHead[n].pszName);
#ifdef _UNICODE
	lstrcpy (lpszSlideName, /*CA2W(pSlbHead[n].pszName)*/str.kwszPtr());
#else
	lstrcpy (lpszSlideName, pSlbHead[n].pszName);
#endif
	GlobalUnlock (hSlbHead);
	return TRUE;
}

int CSlb::GetSlideNo (const TCHAR *lpszSlideName)
{
	SlbHeadStruct *pSlbHead = (SlbHeadStruct *)/*GlobalLock*/ (hSlbHead);

	int i = 0;
	for (i = 0; i < nTotalSlides; i++)
	{
		ZcString str(pSlbHead[i].pszName);
#ifdef _UNICODE
		if (!lstrcmpi(/*CA2W(pSlbHead[i].pszName)*/str.kwszPtr(), lpszSlideName))//modify by UNICODE 2013 10 18
#else
		if (!lstrcmpi (pSlbHead[i].pszName, lpszSlideName))//modify by UNICODE 2013 10 18
#endif
			break;
	}

	GlobalUnlock (hSlbHead);

	if (i == nTotalSlides) return -1;
	else return i;
}

BOOL CSlb::GetSlideData (const TCHAR *lpszSlideName, BYTE *buffer)
{
	int n = GetSlideNo (lpszSlideName);
	if (n < 0 || n >= nTotalSlides) return FALSE;

	return GetSlideData (n, buffer);
}
 //modify by UNICODE 2013 10 18

BOOL CSlb::GetSlideData (int nSequenceNo, BYTE *buffer)
{
	ASSERT (nSequenceNo >= 0 && nSequenceNo < nTotalSlides);

	SlbHeadStruct *pSlbHead = (SlbHeadStruct *)/*GlobalLock*/ (hSlbHead);
	BYTE *pSlbData = (BYTE *)/*GlobalLock*/ (hSlbData);

	if (pSlbHead[nSequenceNo].bInMem)
	{
		memcpy (buffer, pSlbData + pSlbHead[nSequenceNo].dwOffset, pSlbHead[nSequenceNo].nSize);
	}
	else 
	{
		ASSERT (_lstrcmpi(pszSlbPathName, _T("")));
		HANDLE hFile = CreateFile (pszSlbPathName, GENERIC_READ, FILE_SHARE_READ, NULL,
			OPEN_EXISTING, NULL, NULL);
		DWORD dwBytesRead;
		
		if (hFile == INVALID_HANDLE_VALUE) 
		{
			GlobalUnlock (hSlbHead);
			GlobalUnlock (hSlbData);
			return FALSE;
		}
		
		SetFilePointer (hFile, pSlbHead[nSequenceNo].dwOffset, NULL, FILE_BEGIN);
		ReadFile (hFile, buffer,pSlbHead[nSequenceNo].nSize, &dwBytesRead, NULL);
		
		CloseHandle (hFile);
	}
	GlobalUnlock (hSlbHead);
	GlobalUnlock (hSlbData);

	return TRUE;
}
int CSlb::GetSlideSize (const TCHAR *lpszSlideName) // -1 means no such slide.
{
	int n = GetSlideNo (lpszSlideName);
	if (n < 0 || n >= nTotalSlides) return -1;

	return GetSlideSize (n);
}
 //modify by UNICODE 2013 10 18
int CSlb::GetSlideSize (int nSequenceNo)
{
	ASSERT (nSequenceNo >= 0 && nSequenceNo < nTotalSlides);

	SlbHeadStruct *pSlbHead = (SlbHeadStruct *)/*GlobalLock*/ (hSlbHead);
	int nSize = pSlbHead[nSequenceNo].nSize;
	GlobalUnlock (hSlbHead);
	return nSize;
}

BOOL CSlb::SetModifiedFlag(BOOL bMod)
{
	BOOL bOld = bModified;
	bModified = bMod;
	return bOld;
}

BOOL CSlb::GetModifiedFlag()
{
	return bModified;
}

BOOL CSlb::SaveModified ()
{
	TCHAR path [MAX_PATH];
 //modify by UNICODE 2013 10 18
	GetPathName (path);
	if (bModified == TRUE) return OnSaveDocument (path);
	return TRUE;
}

BOOL CSlb::ChangeFileExtName(TCHAR *lpszFileName,const TCHAR *lpszExtName)
{
	int i;
	for (i=lstrlen(lpszFileName); i>=0; i--)
	{
		if (lpszFileName[i]=='\\') break;
		if (lpszFileName[i]=='.')
		{
			lpszFileName[i]='\0';
			break;
		}
	}
	return TRUE;
}

BOOL CSlb::DockPathName(TCHAR * lpszPathName) 
{
	int i;
	for (i=lstrlen(lpszPathName)-2; i>=0; i--)
	{
		if (lpszPathName[i]=='\\') break;
	}
	if (i<0) 
	{
		lpszPathName[0]='\0';
		return TRUE;
	}
	else
		lpszPathName[i+1]='\0';

	return TRUE;
}
 //modify by UNICODE 2013 1018
int CSlb::GetSildeNum()
{
	return nTotalSlides;
}