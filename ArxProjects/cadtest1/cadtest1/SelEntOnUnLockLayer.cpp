//PM
#include "stdafx.h"

BOOL GetLayersLocked(AcDbDatabase * pDb, CStringArray & layerNames)
{
	AcDbLayerTable *pLyrTable;
	AcDbObjectId recId;

	BOOL bOk = FALSE;
	if (pDb == NULL) 
	{
		acedAlert(_T("No database!"));
		return Adesk::kFalse;
	}

	//
	if (Acad::eOk != pDb->getLayerTable(pLyrTable, AcDb::kForRead))
	{
		return FALSE;
	}

	AcDbLayerTableIterator * pIterator = NULL;
	pLyrTable->newIterator(pIterator);

	for (; !pIterator->done(); pIterator->step())
	{
		AcDbLayerTableRecord * pRecord = NULL;
		if (Acad::eOk == pIterator->getRecord(pRecord, AcDb::kForRead))
		{
			//获取层名
			//if (pRecord->isLocked() == true)  //00
			if (pRecord->isLocked() == false)
			{
				TCHAR * pName = NULL;
				pRecord->getName(pName);
				CString strName(pName);
				delete pName;
				pName = NULL;
				strName.Replace(_T("#"), _T("`#"));
				layerNames.Add(strName);
			}
			pRecord->close();
		}
	}
	//
	delete pIterator;
	pIterator = NULL;
	//
	pLyrTable->close();
	return bOk;
}

ARXCMD3(TestSelEntOnUnLockLayer)
{
	AcDbDatabase* pWorkDb = acdbHostApplicationServices()->workingDatabase();

	CString strLayerLocked;
	CStringArray arrLocked;
	GetLayersLocked(pWorkDb, arrLocked);
	for (int i = 0; i < arrLocked.GetSize(); i++)
	{
		if (i == 0)
		{
			strLayerLocked = arrLocked[0];
		}
		else
		{
			strLayerLocked += _T(",") + arrLocked[i];
		}
	}

	//resbuf * pBuf = acutBuildList(-4, _T("<not")						//AcDb::kDxfOperator=-4,但 06下没有这一项
	//	, AcDb::kDxfLayerName, strLayerLocked	//表示图层							
	//	, -4, _T("not>")
	//	, RTNONE);
#if 1
	//resbuf *pBuf = acutBuildList(RTDXF0, _T("LINE,ARC,BLOCK"), RTNONE);
	resbuf *pBuf = acutBuildList(8, strLayerLocked, RTNONE);
	//resbuf *pBuf = acutBuildList(-4, _T("<not"), 8, strLayerLocked, -4, _T("not>"), RTNONE);
#endif

	//选择物体
	ads_name ss;
	int rc = 0;
	rc = acedSSGet(NULL, NULL, NULL, pBuf, ss);
	acutRelRb(pBuf);
	if (rc == RTNORM)
	{
		acutPrintf(_T("\nrc == RTNORM"));
		acedSSFree(ss);
	}
	else
	{
		acutPrintf(_T("\nrc == %d"), rc);
	}
}


ARXCMD3(Test_ZWCAD23718)
{
	int err;
	Adesk::Int32 nss;
	resbuf *rbFilt;
	ads_name ss;

	ads_point p1, p2;

	p1[X] = 136.5271;
	p1[Y] = 0.3213;
	p1[Z] = 0.0;

	p2[X] = 138.6718;
	p2[Y] = 0.1194;
	p2[Z] = 0.0;

	ads_grdraw(p1, p2, 1, 0);

	rbFilt = ads_buildlist(
		-4, ACRX_T("<and"),
		8, ACRX_T("[PM]####_##*"),
		-4, ACRX_T("<or"),
		RTDXF0, ACRX_T("LINE"),
		RTDXF0, ACRX_T("*POLYLINE"),
		RTDXF0, ACRX_T("SPLINE"),
		-4, ACRX_T("or>"),
		-4, ACRX_T("and>"),
		0);

	err = ads_ssget(ACRX_T("_C"), p1, p2, rbFilt, ss);
	acutRelRb(rbFilt);
	if (err != RTNORM)
	{
		acutPrintf(ACRX_T("ads_ssget() error (%d)\n"), err);
		return;
	}

	err = acedSSLength(ss, &nss);
	if (err != RTNORM)
	{
		acedSSFree(ss);
		acutPrintf(ACRX_T("acedSSLength() error (%d)\n"), err);
		return;
	}

	acutPrintf(ACRX_T("nss=%ld"), nss);

	acedSSFree(ss);
}

ARXCMD3(test_acutWcMatch)
{
	int nRet1 = acutWcMatch(_T("1Line"), _T("#Line"));   //# Matches any single numeric digit.
	int nRet = acutWcMatch(_T("#Line"), _T("`#Line"));
	acutPrintf(_T("\nnRet = %d"), nRet);
}