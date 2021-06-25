#include "StdAfx.h"
#include "CSlb.h"
#include "Graph.h"
#include <qpoint.h>
#include <qpen.h>

//extern unsigned char rgb[];

unsigned char rgb[]={
	0,  0,  0,255,  0,  0,255,255,  0,  0,255,  0,  0,255,255,
		0,  0,255,255,  0,255,255,255,255,255,255,255,255,255,255,
		255,  0,  0,255,127,127,165,  0,  0,165, 82, 82,127,  0,  0,
		127, 63, 63, 76,  0,  0, 76, 38, 38, 38,  0,  0, 38, 19, 19,
		255, 63,  0,255,159,127,165, 41,  0,165,103, 82,127, 31,  0,
		127, 79, 63, 76, 19,  0, 76, 47, 38, 38,  9,  0, 38, 23, 19,
		255,127,  0,255,191,127,165, 82,  0,165,124, 82,127, 63,  0,
		127, 95, 63, 76, 38,  0, 76, 57, 38, 38, 19,  0, 38, 28, 19,
		255,191,  0,255,223,127,165,124,  0,165,145, 82,127, 95,  0,
		127,111, 63, 76, 57,  0, 76, 66, 38, 38, 28,  0, 38, 33, 19,
		255,255,  0,255,255,127,165,165,  0,165,165, 82,127,127,  0,
		127,127, 63, 76, 76,  0, 76, 76, 38, 38, 38,  0, 38, 38, 19,
		191,255,  0,223,255,127,124,165,  0,145,165, 82, 95,127,  0,
		111,127, 63, 57, 76,  0, 66, 76, 38, 28, 38,  0, 33, 38, 19,
		127,255,  0,191,255,127, 82,165,  0,124,165, 82, 63,127,  0,
		95,127, 63, 38, 76,  0, 57, 76, 38, 19, 38,  0, 28, 38, 19,
		63,255,  0,159,255,127, 41,165,  0,103,165, 82, 31,127,  0,
		79,127, 63, 19, 76,  0, 47, 76, 38,  9, 38,  0, 23, 38, 19,
		0,255,  0,127,255,127,  0,165,  0, 82,165, 82,  0,127,  0,
		63,127, 63,  0, 76,  0, 38, 76, 38,  0, 38,  0, 19, 38, 19,
		0,255, 63,127,255,159,  0,165, 41, 82,165,103,  0,127, 31,
		63,127, 79,  0, 76, 19, 38, 76, 47,  0, 38,  9, 19, 38, 23,
		0,255,127,127,255,191,  0,165, 82, 82,165,124,  0,127, 63,
		63,127, 95,  0, 76, 38, 38, 76, 57,  0, 38, 19, 19, 38, 28,
		0,255,191,127,255,223,  0,165,124, 82,165,145,  0,127, 95,
		63,127,111,  0, 76, 57, 38, 76, 66,  0, 38, 28, 19, 38, 33,
		0,255,255,127,255,255,  0,165,165, 82,165,165,  0,127,127,
		63,127,127,  0, 76, 76, 38, 76, 76,  0, 38, 38, 19, 38, 38,
		0,191,255,127,223,255,  0,124,165, 82,145,165,  0, 95,127,
		63,111,127,  0, 57, 76, 38, 66, 76,  0, 28, 38, 19, 33, 38,
		0,127,255,127,191,255,  0, 82,165, 82,124,165,  0, 63,127,
		63, 95,127,  0, 38, 76, 38, 57, 76,  0, 19, 38, 19, 28, 38,
		0, 63,255,127,159,255,  0, 41,165, 82,103,165,  0, 31,127,
		63, 79,127,  0, 19, 76, 38, 47, 76,  0,  9, 38, 19, 23, 38,
		0,  0,255,127,127,255,  0,  0,165, 82, 82,165,  0,  0,127,
		63, 63,127,  0,  0, 76, 38, 38, 76,  0,  0, 38, 19, 19, 38,
		63,  0,255,159,127,255, 41,  0,165,103, 82,165, 31,  0,127,
		79, 63,127, 19,  0, 76, 47, 38, 76,  9,  0, 38, 23, 19, 38,
		127,  0,255,191,127,255, 82,  0,165,124, 82,165, 63,  0,127,
		95, 63,127, 38,  0, 76, 57, 38, 76, 19,  0, 38, 28, 19, 38,
		191,  0,255,223,127,255,124,  0,165,145, 82,165, 95,  0,127,
		111, 63,127, 57,  0, 76, 66, 38, 76, 28,  0, 38, 33, 19, 38,
		255,  0,255,255,127,255,165,  0,165,165, 82,165,127,  0,127,
		127, 63,127, 76,  0, 76, 76, 38, 76, 38,  0, 38, 38, 19, 38,
		255,  0,191,255,127,223,165,  0,124,165, 82,145,127,  0, 95,
		127, 63,111, 76,  0, 57, 76, 38, 66, 38,  0, 28, 38, 19, 33,
		255,  0,127,255,127,191,165,  0, 82,165, 82,124,127,  0, 63,
		127, 63, 95, 76,  0, 38, 76, 38, 57, 38,  0, 19, 38, 19, 28,
		255,  0, 63,255,127,159,165,  0, 41,165, 82,103,127,  0, 31,
		127, 63, 79, 76,  0, 19, 76, 38, 47, 38,  0,  9, 38, 19, 23,
		84, 84, 84,118,118,118,152,152,152,186,186,186,220,220,220
};

void CGraph::Draw(char *addr,DWORD size1,int width1,int height1,int xoffset1,int yoffset1,	int lastx1,int lasty1)
{
	xoffset=xoffset1;
	yoffset=yoffset1;
	lastx=lastx1;
	lasty=lasty1;
	width=width1;
	height=height1;
	size=size1;
	mem=addr;
	hOld=(HGDIOBJ)0;
	NEW_SUB_HEAD* new_sub_head;

	new_sub_head =(NEW_SUB_HEAD*)(mem+19);

	if (new_sub_head->highx != 0&&new_sub_head->highy != 0)
	{
		xfact = (float)width / (float)new_sub_head->highx;
		yfact = (float)height / (float)new_sub_head->highy;

		point = 19 + 12;
		fcode = (unsigned short *)(mem + point);
		point += 2;
		while (point < (size))
		{
			if (HIBYTE(*fcode) >= 0x00&&HIBYTE(*fcode) <= 0x7f) draw_line();
			else if (HIBYTE(*fcode) == 0xfb) draw_offset();
			else if (HIBYTE(*fcode) == 0xfc) break;
			else if (HIBYTE(*fcode) == 0xfd) draw_solid();
			else if (HIBYTE(*fcode) == 0xfe) draw_common_pt();
			else if (HIBYTE(*fcode) == 0xff) chg_color();
			fcode = (unsigned short *)(mem + point);
			point += 2;
		}
	}
	else 
	{
		return;
	}
	
#ifdef _ZW_WINDOWS		
	HGDIOBJ hPen;
	hPen=(HPEN)pDC->SelectObject(hOld);
	DeleteObject(hPen);
#endif
}
//modify by UNICODE 2013 10 18	
void CGraph::draw_line()
{
	int fromx,fromy,tox,toy;
	fromx=lastx=*fcode;
	fromy=lasty=*(short *)(mem+point);
	point+=2;
	//pDC->MoveTo((int)(lastx*xfact+xoffset),(int)(height-lasty*yfact+yoffset));
	int x1 = (int)(lastx*xfact + xoffset);
	int y1 = (int)(height - lasty*yfact + yoffset);
	tox=*(short *)(mem+point);
	point+=2;
	toy=*(short *)(mem+point);
	point+=2;
	int x2 = (int)(tox*xfact + xoffset);
	int y2 = (int)(height - toy*yfact + yoffset);
	//pDC->LineTo((int)(tox*xfact+xoffset),(int)(height-toy*yfact+yoffset));
	pDC->drawLine(x1, y1, x2, y2);
}


void CGraph::draw_offset()
{
	int fromx,fromy,tox,toy;
	char offx1,offx2,offy1,offy2;
	offx1=LOBYTE(*fcode);
	offy1=mem[point++];
	offx2=mem[point++];
	offy2=mem[point++];
	fromx=lastx+offx1;
	fromy=lasty+offy1;
	tox=lastx+offx2;
	toy=lasty+offy2;
	//pDC->MoveTo((int)(fromx*xfact+xoffset),(int)(height-fromy*yfact+yoffset));
	//pDC->LineTo((int)(tox*xfact+xoffset),(int)(height-toy*yfact+yoffset));
	int x1 = (int)(fromx*xfact + xoffset);
	int y1 = (int)(height - fromy*yfact + yoffset);
	int x2 = (int)(tox*xfact + xoffset);
	int y2 = (int)(height - toy*yfact + yoffset);
	pDC->drawLine(x1, y1, x2, y2);
	
	lastx=fromx;
	lasty=fromy;
}


void CGraph::draw_solid()
{
	int i,totpts,x[10],y[10];
	//POINT xy[10];
	QPoint xy[10];
	totpts=*(short *)(mem+point);
	point+=2;
	
	y[0]=*(short *)(mem+point);
	point+=2;
	
	if(y[0]>=0) return;
	
	if(totpts==0) return;
	
	for(i=0;i<totpts;++i)
	{
		fcode=(unsigned short *)(mem+point);
		point+=2;
		x[i]=*(short *)(mem+point);
		point+=2;
		//Luxiang change
		y[i]=abs(*(short *)(mem+point));
		point+=2;
		//xy[i].x=(int)(x[i]*xfact)+xoffset;
		//xy[i].y=height-(int)(y[i]*yfact)+yoffset;
		xy[i].setX((int)(x[i]*xfact) + xoffset);
		xy[i].setY(height - (int)(y[i]*yfact) + yoffset);
	}
	//pDC->Polygon(xy,totpts);
	pDC->drawPolygon(xy, totpts);
}


void CGraph::draw_common_pt()
{
	int fromx,fromy,tox,toy;
	char offx2,offy2;

	fromx=lastx;
	fromy=lasty;
	
	offx2=LOBYTE(*fcode);
	offy2=mem[point++];
	
	tox=lastx+offx2;
	toy=lasty+offy2;
#ifdef _ZW_WINDOWS
	pDC->MoveTo((int)(fromx*xfact+xoffset),(int)(height-fromy*yfact+yoffset));
	pDC->LineTo((int)(tox*xfact+xoffset),(int)(height-toy*yfact+yoffset));
#endif 
	pDC->drawLine((int)(fromx*xfact + xoffset), (int)(height - fromy*yfact + yoffset), (int)(tox*xfact + xoffset), (int)(height - toy*yfact + yoffset));
	lastx=tox;
	lasty=toy;
}

void CGraph::chg_color()
{
#ifdef _ZW_WINDOWS
	HGDIOBJ hPen;
	hPen=pDC->SelectObject(hOld);
	DeleteObject(hPen);
	hPen=CreatePen(PS_SOLID,1,RGB(rgb[3*LOBYTE(*fcode)],
	       rgb[3*LOBYTE(*fcode)+1], rgb[3*LOBYTE(*fcode)+2]));
	hOld=(HPEN)pDC->SelectObject(hPen);
	return;
#endif 
	QPen pen = pDC->pen();
	pen.setColor(QColor(rgb[3*LOBYTE(*fcode)],
	       rgb[3*LOBYTE(*fcode)+1], rgb[3*LOBYTE(*fcode)+2]));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(1);
	pDC->setPen(pen);
}

void CGraph::DrawGrid(RECT rc,int nXgrids,int nYgrids,int x,int y)
{
	int i;
	HPEN hPen,hHold;
	int uWidth,uHeight;

	uWidth=(rc.right-rc.left)/ nXgrids;
	uHeight=(rc.bottom-rc.top)/ nYgrids;
	//hPen=CreatePen(PS_SOLID,1,RGB(255,0,0));
	//hHold=(HPEN)pDC->SelectObject(hPen);
	QPen pen = pDC->pen();
	pen.setColor(QColor(255, 0, 0));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(1);
	pDC->setPen(pen);

	for(i=0; i<=nYgrids; i++)
	{
		//pDC->MoveTo(x,y+i*uHeight);
		//pDC->LineTo(x+nXgrids*uWidth,y+i*uHeight);
		pDC->drawLine(x, y + i*uHeight, x + nXgrids*uWidth, y + i*uHeight);
	}

	for(i=0;i<=nXgrids;++i)
	{
		//pDC->MoveTo(x+i*uWidth,y);
		//pDC->LineTo(x+i * uWidth , y+nYgrids * uHeight);
		pDC->drawLine(x + i*uWidth, y, x + i * uWidth, y + nYgrids * uHeight);
	}
	//pDC->SelectObject(hHold);
	//DeleteObject(hPen);
 
}

void CGraph::HighLightBlock(RECT rc,int nXgrids,int nYgrids,int nPage,int nSel,int ndwgmode)
{
	int nPageBlocks=nXgrids * nYgrids;
	if ( nSel<nPage * nPageBlocks || nSel >= nPageBlocks * (nPage+1 )) 
		return;
	int left,top,width,height;
	switch(ndwgmode)
	{
	case 1:
		left=rc.left+(rc.right-rc.left)/nXgrids * (nSel % nXgrids);
		top=rc.top+(rc.bottom-rc.top)/nYgrids * (nSel / nXgrids - 
			nPage * nYgrids);
		width=(rc.right-rc.left)/nXgrids/2;
		height=(rc.bottom-rc.top)/nYgrids/2;
		break;
	case 2:
		left=rc.left+(rc.right-rc.left)/nXgrids * (nSel % nXgrids)+
			(rc.right-rc.left)/nXgrids/2;
		top=rc.top+(rc.bottom-rc.top)/nYgrids * (nSel / nXgrids - 
			nPage * nYgrids);
		width=(rc.right-rc.left)/nXgrids/2;
		height=(rc.bottom-rc.top)/nYgrids/2;
		break;
	case 3:
		left=rc.left+(rc.right-rc.left)/nXgrids * (nSel % nXgrids);
		top=rc.top+(rc.bottom-rc.top)/nYgrids * (nSel / nXgrids - 
			nPage * nYgrids)+(rc.bottom-rc.top)/nYgrids/2;
		width=(rc.right-rc.left)/nXgrids/2;
		height=(rc.bottom-rc.top)/nYgrids/2;
		break;
	case 4:
		left=rc.left+(rc.right-rc.left)/nXgrids * (nSel % nXgrids)+
			(rc.right-rc.left)/nXgrids/2;
		top=rc.top+(rc.bottom-rc.top)/nYgrids * (nSel / nXgrids - 
			nPage * nYgrids)+(rc.bottom-rc.top)/nYgrids/2;
		width=(rc.right-rc.left)/nXgrids/2;
		height=(rc.bottom-rc.top)/nYgrids/2;
		break;
	default:
		left=rc.left+(rc.right-rc.left)/nXgrids * (nSel % nXgrids);
		top=rc.top+(rc.bottom-rc.top)/nYgrids * (nSel / nXgrids - nPage * nYgrids);
		width=(rc.right-rc.left)/nXgrids;
		height=(rc.bottom-rc.top)/nYgrids;
	}
#ifdef _ZW_WINDOWS
	pDC->BitBlt(left,top,width,height,NULL,0,0,DSTINVERT);
#endif 
	//pDC->setCompositionMode(QPainter::CompositionMode_Xor);
	//pDC->drawPixmap(left, top, width, height, NULL, 0, 0, width, height);
}
