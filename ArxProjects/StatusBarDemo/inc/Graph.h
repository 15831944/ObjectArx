//#include "StdAfx.h"

#ifndef _STRUCT_NEW_SUB_HEAD
#define _STRUCT_NEW_SUB_HEAD
typedef struct {
	unsigned short highx;
	unsigned short highy;
	unsigned long aspect_ratio;
	unsigned short hard_fill;
	unsigned short test_no;
} NEW_SUB_HEAD ;
#endif

#ifndef HEADFILE_GRAPH
#define HEADFILE_GRAPH

class Graph{
public:
	void draw(HDC hDC,char*mem,	DWORD size_of_mem,int width,int height,int=0,int=0,int=0,int=0);
private:
	int lastx;
	int lasty;
	int xoffset;
	int yoffset;
	int height;
	int width;
	double xfact;
	double yfact;
	DWORD size;
	char* mem;
	DWORD point;
	HDC hDC;
	HGDIOBJ hOld;
	unsigned short *fcode;
	
	void draw_line();
	void draw_solid();
	void draw_offset();
	void draw_common_pt();
	void chg_color();
};

#endif