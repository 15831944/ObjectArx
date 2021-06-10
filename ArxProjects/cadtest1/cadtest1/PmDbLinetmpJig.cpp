// PmDbLinetmpJig.cpp: implementation of the CPmDbLinetmpJig class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PmDbLinetmpJig.h"
#include "axlock.h"

#include <dbproxy.h>
#include "acestext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


BOOL IsNumeric(const CString & sData)
{
	if ( sData.IsEmpty() )
	{
		return FALSE ; 
	}
	//判断sData是否仅一位
	int iLen = sData.GetLength();


	if (iLen == 1 )
	{
		TCHAR chFirst = sData.GetAt(0) ;

		/// 
		/// 当为 汉字 根 的时候
		/// 使用 isdigit 不对 。
		/// 
		if ( chFirst >= _T('0') && chFirst <= _T('9') )
			//if ( isdigit( chFirst ) )
		{
			return TRUE ; 
		}
	}

	//至少两位
	int iBegin = 0;
	if ( _T('-') == sData.GetAt(0) )	//首位为负号
		iBegin = 1;

	//
	int iNumOfDot = 0;
	for (int i = iBegin;i < iLen; ++i )
	{
		TCHAR tch = sData.GetAt(i) ;
		if(i == iBegin)
		{
			if ( tch >= _T('1') && tch <= _T('9'))		//为数字时，使终ok
				continue;
			else if( _T('0')  == tch)		//为0时，下面紧接着必须是.
			{
				++i ;
				tch = sData.GetAt(i) ;
				if (i < iLen)
				{
					if ( tch == _T('.'))
					{
						++iNumOfDot ; 
						continue;
					}
					else
					{
						return FALSE;
					}
				}
			}
			else
				return FALSE;	//首位不符合规范
		}
		else if ( _istdigit(tch) )
			continue;
		else if ( _T('.') == tch && iNumOfDot == 0)
		{
			iNumOfDot++;
			continue;
		}
		else
			return FALSE;	//其余都是非法情况

	}

	return TRUE;
}

//////////////////////////////////////////////////////////////////////
// CPmDbLinetmpJig Construction/Destruction
//////////////////////////////////////////////////////////////////////
CPmDbLinetmpJig::CPmDbLinetmpJig()
{	
	m_pEntity = NULL;
}

CPmDbLinetmpJig::~CPmDbLinetmpJig()
{
	if (m_pEntity != NULL)
	{
		m_pEntity->close();
	}
}

Adesk::Boolean CPmDbLinetmpJig::doIt(const AcDbObjectId &objId)
{	
	AcAxDocLock dbLock;
	Adesk::Boolean bRet = Adesk::kFalse;
	AcDbEntity* pSrcEnt = NULL;
	Acad::ErrorStatus esOpen = acdbOpenAcDbEntity(pSrcEnt, objId, AcDb::kForWrite);
	if (esOpen != Acad::eOk)
	{
		return bRet;
	}

	if (pSrcEnt->isKindOf(AcDbCurve::desc()))
	{
		m_pEntity = AcDbCurve::cast(pSrcEnt);
	}
	
	if (m_pEntity == NULL)
	{
		return bRet;
	}

	//移动终点的位置
	m_pEntity->getEndPoint(m_CurPt);
	setDispPrompt(_T("\n请输入伸缩长度(负值缩短):"));
	AcEdJig::DragStatus ds = drag();
	if (ds == kNormal)
	{
		return Adesk::kTrue;
	}
	else
	{
		return Adesk::kFalse;
	}	
}

AcEdJig::DragStatus CPmDbLinetmpJig::sampler()
{
	//在AutoCAD开发文档中NoNeg和NoZero只适合acquireDist和acquireAngle, 我们平台的acquirePoint中也应用了NoNeg所以导致了非法输入, 
	//但是acquirePoint是一个公用的2次开发接口影响较大, 测试不完全所以不在此做修改而是让客户修改代码去除标记
	setUserInputControls((UserInputControls)
        (AcEdJig::kGovernedByOrthoMode
		 |AcEdJig::kAccept3dCoordinates
		 | AcEdJig::kNoNegativeResponseAccepted //
         | AcEdJig::kNoZeroResponseAccepted
		 | AcEdJig::kAnyBlankTerminatesInput
		 )
		 );
	AcGePoint3d curPt;
	AcEdJig::DragStatus ds = acquirePoint(curPt);
	curPt.z = 0;//绘制操作捕捉点不娶Z值	
	if (ds != kNormal)
	{
		return ds;
	}

	if (curPt.distanceTo(m_CurPt) < 1.0)
	{
		return AcEdJig::kNoChange;
	}
	
	TCHAR ch[2049];
	ds = acquireString(ch);
	CString strInput(ch);
	if (IsNumeric(strInput) == TRUE)
	{
		BOOL bRet = FALSE;
		double dDis = _ttof(strInput);
		ReSetLine(dDis);
		
	}	
	else
	{
		//处理用户鼠标选定的方式；
		m_CurPt = curPt;
		ReSetLine(curPt);
	}

	return AcEdJig::kNormal;
}

void CPmDbLinetmpJig::ReSetLine(AcGePoint3d curPt)
{
	//AcGePoint3d ptStart(AcGePoint3d::kOrigin);
	//AcGePoint3d ptEnd(AcGePoint3d::kOrigin);
	//m_pEntity->getStartPoint(ptStart);
	//m_pEntity->getEndPoint(ptEnd);
	//acutPrintf(L"\nst:(%g,%g), en:(%g,%g)",  ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);

	Acad::ErrorStatus es = m_pEntity->extend(Adesk::kFalse, curPt);

	//m_pEntity->getStartPoint(ptStart);
	//m_pEntity->getEndPoint(ptEnd);
	//acutPrintf(L"\nes = %s, curPt:(%g,%g), st:(%g,%g), en:(%g,%g)", acadErrorStatusText(es), curPt.x, curPt.y, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
}

BOOL CPmDbLinetmpJig::ReSetLine(double dblDis)
{
	AcGePoint3d ptStart(AcGePoint3d::kOrigin);
	AcGePoint3d ptEnd(AcGePoint3d::kOrigin);

	m_pEntity->getStartPoint(ptStart);
	m_pEntity->getEndPoint(ptEnd);

	AcGeVector3d vecDir = ptEnd - ptStart;
	vecDir.normalize();

	AcGePoint3d ptNewEnd = ptEnd + vecDir * dblDis;
	ReSetLine(ptNewEnd);

	return TRUE;
}