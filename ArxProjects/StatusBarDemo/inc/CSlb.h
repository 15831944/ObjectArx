#pragma once

//一个幻灯片库操作的类
#include <QPainter>


struct SlbHeadStruct;
class CSlb
{
public:
	BOOL SaveModified ();
	CSlb ();
	~CSlb ();
	
	BOOL OnNewDocument ();
	BOOL OnOpenDocument (const TCHAR *lpszSlbFileName);
	BOOL OnSaveDocument (const TCHAR *lpszSlbFileName);
	BOOL DeleteContents ();

	void SetPathName (const TCHAR *lpszSlbPathName);
	void GetPathName (TCHAR *lpszSlbPathName);

	int  AddSlide (const TCHAR *lpszSlideName,const BYTE *lpSlideData, int dwSlideSize);
	BOOL DelSlide (const TCHAR *lpszSlideName);
	BOOL DelSlide (int nSequenceNo);

	BOOL GetSlideData (const TCHAR *lpszSlideName, BYTE *buffer);
	BOOL GetSlideData (int nSequenceNo, BYTE *buffer);
	int GetSlideSize (const TCHAR *lpszSlideName); 
	int GetSlideSize (int nSequenceNo);

	int GetSlideNo (const TCHAR *lpszSlideName);  
	BOOL GetSlideName (int nSeqNo, TCHAR *lpszSlideName); 

	BOOL SetModifiedFlag(BOOL bModified);
	BOOL GetModifiedFlag();

	BOOL ChangeFileExtName(TCHAR *lpszFileName,const TCHAR *lpszExtName);
	BOOL DockPathName(TCHAR * lpszPathName);
 //modify by UNICODE 2013 10 18
	int GetSildeNum();
	
private:
	TCHAR pszSlbPathName[MAX_PATH];
 //modify by UNICODE 20 13 10 18
	BOOL bModified;
	HGLOBAL hSlbHead;
	HGLOBAL hSlbData;
	int nTotalSlides;
	DWORD dwDataBufTail;
	
	int slbHeadSize;
	int slbDataSize;
};


class CGraph
{
public:
	QPainter* pDC;
public:
	void Draw(char *addr,DWORD size,
		int width1,int height1,
		int xoffset1,int yoffset1,
		int lastx1=0,int lasty1=0
		);

	void DrawGrid(RECT rc,int nXgrids,int nYgrids,int x,int y);
    void HighLightBlock(RECT rc,int nXgrids,int nYgrids,int nPage,int nSel,int ndwgmode);

private:
	int lastx;
	int lasty;
	int xoffset;
	int yoffset;
	int height;
	int width;
	DWORD size;
	double xfact;
	double yfact;
	char* mem;
	DWORD point;
	HGDIOBJ hOld;
	unsigned short *fcode;
	
	void draw_line();
	void draw_solid();
	void draw_offset();
	void draw_common_pt();
	void chg_color();
};

