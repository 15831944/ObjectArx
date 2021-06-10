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
	//�ж�sData�Ƿ��һλ
	int iLen = sData.GetLength();


	if (iLen == 1 )
	{
		TCHAR chFirst = sData.GetAt(0) ;

		/// 
		/// ��Ϊ ���� �� ��ʱ��
		/// ʹ�� isdigit ���� ��
		/// 
		if ( chFirst >= _T('0') && chFirst <= _T('9') )
			//if ( isdigit( chFirst ) )
		{
			return TRUE ; 
		}
	}

	//������λ
	int iBegin = 0;
	if ( _T('-') == sData.GetAt(0) )	//��λΪ����
		iBegin = 1;

	//
	int iNumOfDot = 0;
	for (int i = iBegin;i < iLen; ++i )
	{
		TCHAR tch = sData.GetAt(i) ;
		if(i == iBegin)
		{
			if ( tch >= _T('1') && tch <= _T('9'))		//Ϊ����ʱ��ʹ��ok
				continue;
			else if( _T('0')  == tch)		//Ϊ0ʱ����������ű�����.
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
				return FALSE;	//��λ�����Ϲ淶
		}
		else if ( _istdigit(tch) )
			continue;
		else if ( _T('.') == tch && iNumOfDot == 0)
		{
			iNumOfDot++;
			continue;
		}
		else
			return FALSE;	//���඼�ǷǷ����

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

	//�ƶ��յ��λ��
	m_pEntity->getEndPoint(m_CurPt);
	setDispPrompt(_T("\n��������������(��ֵ����):"));
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
	//��AutoCAD�����ĵ���NoNeg��NoZeroֻ�ʺ�acquireDist��acquireAngle, ����ƽ̨��acquirePoint��ҲӦ����NoNeg���Ե����˷Ƿ�����, 
	//����acquirePoint��һ�����õ�2�ο����ӿ�Ӱ��ϴ�, ���Բ���ȫ���Բ��ڴ����޸Ķ����ÿͻ��޸Ĵ���ȥ�����
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
	curPt.z = 0;//���Ʋ�����׽�㲻ȢZֵ	
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
		//�����û����ѡ���ķ�ʽ��
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