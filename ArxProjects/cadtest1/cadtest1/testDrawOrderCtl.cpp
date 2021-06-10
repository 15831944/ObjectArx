//
#include "stdafx.h"
#include "dbxutil.h"
#include "actrans.h"
#include "rxmfcapi.h"

void GetSelEnt(AcDbDatabase* pWorkDb, AcDbObjectIdArray& idArrOne, AcDbObjectIdArray& idArrTwo)
{
	if (pWorkDb == NULL)
	{
		return;
	}

	AcDbBlockTable* pBlkTab = NULL;
	Acad::ErrorStatus esOpen = pWorkDb->getBlockTable(pBlkTab, AcDb::kForRead);
	if (esOpen != Acad::eOk)
	{
		return;
	}
	pBlkTab->close();

	AcDbBlockTableRecord* pBlkTabRcd = NULL;
	esOpen = pBlkTab->getAt(ACDB_MODEL_SPACE, pBlkTabRcd, AcDb::kForRead);
	if (esOpen != Acad::eOk)
	{
		return;
	}
	pBlkTabRcd->close();

	AcDbBlockTableRecordIterator* pBlkTabRcdIter = NULL;
	esOpen = pBlkTabRcd->newIterator(pBlkTabRcdIter);
	if (esOpen != Acad::eOk)
	{
		return;
	}

	AcDbEntity* pCurEnt = NULL;
	for (pBlkTabRcdIter->start(); !pBlkTabRcdIter->done(); pBlkTabRcdIter->step())
	{
		Acad::ErrorStatus esGet = pBlkTabRcdIter->getEntity(pCurEnt, AcDb::kForRead);
		if (esGet != Acad::eOk)
		{
			continue;
		}
		pCurEnt->close();

		if (!pCurEnt->isKindOf(AcDbPolyline::desc()))
		{
			continue;
		}

		AcDbPolyline* pLine = AcDbPolyline::cast(pCurEnt);
		if (pLine == NULL)
		{
			continue;
		}

		AcDbObjectId idCur = pCurEnt->objectId();

		int iPtNum = pLine->numVerts();
		if (iPtNum == 2)
		{
			idArrOne.append(idCur);
		}
		else
		{
			idArrTwo.append(idCur);
		}
	}

	delete pBlkTabRcdIter;
	pBlkTabRcdIter = NULL;


}

ARXCMD3(TestDrawOpderCtl)
{
	AcDbDatabase* pWorkDb = acdbHostApplicationServices()->workingDatabase();

	AcDbObjectIdArray idArrOne; //要放在前面
	AcDbObjectIdArray idArrTwo;
	GetSelEnt(pWorkDb, idArrOne, idArrTwo);

	//已把DrawOpderCtl系统变量置为0
	// 把DrawOpderCtl系统变量置为0
	resbuf rb;
	rb.restype = RTSHORT;
	rb.resval.rint = 0; /// value
	rb.rbnext = NULL;
	acedSetVar(_T("DRAWORDERCTL"), &rb);

	acdbQueueForRegen(idArrOne.asArrayPtr(), idArrOne.length());

	acedGetAcadFrame()->SetFocus();
	AcApDocument * pDoc = curDoc();
	acDocManager->activateDocument(pDoc);

	actrTransactionManager->flushGraphics();
	acedUpdateDisplay();
}

#pragma region ZWCAD - 23890
extern void AsObjectIdArray(AcDbObjectIdArray& objids, const ads_name ss);
ARXCMD3(TestDrawOrder_ZWCAD23890)
{
	ads_name adsset;
	int result = acedSSGet(NULL, NULL, NULL, NULL, adsset);
	if (result != RTNORM)
		return;

	AcDbObjectIdArray arrObjSel;
	AsObjectIdArray(arrObjSel, adsset);
	acedSSFree(adsset);

	int len = arrObjSel.length();
	if (len < 1)
		return;

	/// 系统变量
	resbuf rb;
	rb.restype = RTSHORT;
	rb.resval.rint = 0; /// value
	rb.rbnext = NULL;
	acedSetVar(_T("DRAWORDERCTL"), &rb);

	acdbQueueForRegen(&arrObjSel[0], 1);
}
#pragma endregion