//
#include "stdafx.h"

#include "dbxrecrd.h"

// 添加实体扩展词典
ARXCMD3(AddXRecord)
{
	ads_name en;
	ads_point pt;
	if (acedEntSel(_T("\n选择实体："), en, pt) != RTNORM)
	{
		return;
	}
	AcDbObjectId entId;
	Acad::ErrorStatus es = acdbGetObjectId(entId, en);

	AcDbObjectId xRecordId;
	AcDbDictionary* pDict = NULL;
	AcDbXrecord* pXRecord = new AcDbXrecord();
	AcDbObject* pObj = NULL;
	acdbOpenObject(pObj, entId, AcDb::kForWrite);
	AcDbObjectId dictObjId = pObj->extensionDictionary();
	if (dictObjId == NULL)
	{
		pObj->createExtensionDictionary();
	}
	pObj->close();

	acdbOpenObject(pDict, dictObjId, AcDb::kForWrite);
	pDict->setAt(_T("XRecord"), pXRecord, xRecordId);
	pDict->close();

	struct resbuf* pRb;
	pRb = acutBuildList(AcDb::kDxfText, _T("hello"),
		AcDb::kDxfInt32, 2,
		AcDb::kDxfReal, 3.14,
		RTNONE);
	pXRecord->setFromRbChain(*pRb);
	pXRecord->close();
	acutRelRb(pRb);
}
ARXCMD3(ModXRecord)
{
	ads_name en;
	ads_point pt;
	if (acedEntSel(_T("\n选择实体："), en, pt) != RTNORM)
	{
		return;
	}
	AcDbObjectId entId;
	Acad::ErrorStatus es = acdbGetObjectId(entId, en);

	AcDbObject* pObj = NULL;
	acdbOpenObject(pObj, entId, AcDb::kForWrite);
	AcDbObjectId dictObjId = pObj->extensionDictionary();
	pObj->close();
	if (dictObjId == NULL)
	{
		acutPrintf(_T("\n该实体不存在扩展词典"));
		return;
	}
	AcDbDictionary* pDict = NULL;
	AcDbXrecord* pXRecord = NULL;
	acdbOpenObject(pDict, dictObjId, AcDb::kForWrite);
	pDict->getAt(_T("XRecord"), pXRecord, AcDb::kForWrite);
	pDict->close();
	if (pXRecord)
	{
		struct resbuf* pRb;
		pRb = acutBuildList(AcDb::kDxfText, _T("Mod"),
			AcDb::kDxfInt32, 1,
			AcDb::kDxfReal, 6.28,
			RTNONE);
		pXRecord->setFromRbChain(*pRb);
	}
	else
	{
		acutPrintf(_T("\n该实体无扩展数据"));
	}
	pXRecord->close();
}

ARXCMD3(DelXRecord)
{
	ads_name en;
	ads_point pt;
	if (acedEntSel(_T("\n选择实体："), en, pt) != RTNORM)
	{
		return;
	}
	AcDbObjectId entId;
	Acad::ErrorStatus es = acdbGetObjectId(entId, en);

	AcDbObject* pObj = NULL;
	acdbOpenObject(pObj, entId, AcDb::kForWrite);
	AcDbObjectId dictObjId = pObj->extensionDictionary();
	pObj->close();
	if (dictObjId == NULL)
	{
		acutPrintf(_T("\n该实体不存在扩展词典"));
		return;
	}

	AcDbDictionary* pDict = NULL;
	acdbOpenObject(pDict, dictObjId, AcDb::kForWrite);
	if (pDict)
	{
		if (pDict->has(_T("XRecord")))
		{
			pDict->remove(_T("XRecord"));
			acutPrintf(_T("\n已删除扩展词典XRecord"));
		}
		else
		{
			acutPrintf(_T("\n不存在扩展词典XRecord"));
		}
	}
	pDict->close();
}

// 自定义线型
//CreateLineTypeTest-->ApplyCusLineTypeTest, make sure the linetype exists.
ARXCMD3(createLineTypeTest)
{
	Acad::ErrorStatus es;
	AcDbDatabase *pDadabase = acdbHostApplicationServices()->workingDatabase();
	AcDbLinetypeTable* pLineTypeTable = NULL;
	if (Acad::eOk != pDadabase->getLinetypeTable(pLineTypeTable, AcDb::kForWrite))
		return;

	//CustomLinetype1
	if (!pLineTypeTable->has(_T("CustomLinetype1")))
	{
		AcDbLinetypeTableRecord *pLineTypeTableRec1 = new AcDbLinetypeTableRecord();
		pLineTypeTableRec1->setName(_T("CustomLinetype1"));
		es = pLineTypeTableRec1->setComments(_T("TextLineType"));  //description

		//短划线(Dash)：实线(+)，空格(-)，点(0)
		pLineTypeTableRec1->setNumDashes(2);
		pLineTypeTableRec1->setDashLengthAt(0, 1);
		pLineTypeTableRec1->setDashLengthAt(1, -2.25);

		//Dash(1) 设置为文字
		pLineTypeTableRec1->setShapeStyleAt(1, pDadabase->textstyle());
		pLineTypeTableRec1->setTextAt(1, _T("TextLineType"));                  //文字内容
		pLineTypeTableRec1->setShapeScaleAt(1, 0.25);                          //文字比例
		pLineTypeTableRec1->setShapeOffsetAt(1, AcGeVector2d(-2.2, -0.125));   //文字偏移,默认为下一个dash的起点

		pLineTypeTableRec1->setPatternLength(3);       //DashLength

		es = pLineTypeTable->add(pLineTypeTableRec1);
		pLineTypeTableRec1->close();
	}

	//CustomLinetype2
	if (!pLineTypeTable->has(_T("CustomLinetype2")))
	{
		AcDbLinetypeTableRecord *pLineTypeTableRec2 = new AcDbLinetypeTableRecord();
		pLineTypeTableRec2->setName(_T("CustomLinetype2"));
		es = pLineTypeTableRec2->setComments(_T("PointLineType"));  //description

		//短划线(Dash)：实线(+)，空格(-)，点(0)
		pLineTypeTableRec2->setNumDashes(4);
		pLineTypeTableRec2->setDashLengthAt(0, 0.5);
		pLineTypeTableRec2->setDashLengthAt(1, -0.25);
		pLineTypeTableRec2->setDashLengthAt(2, 0);
		pLineTypeTableRec2->setDashLengthAt(3, -0.25);

		pLineTypeTableRec2->setPatternLength(1);       //DashLength

		es = pLineTypeTable->add(pLineTypeTableRec2);
		pLineTypeTableRec2->close();
	}

	pLineTypeTable->close();
}
ARXCMD3(applyCusLineTypeTest)
{
	Acad::ErrorStatus es;
	AcDbDatabase *pDatabase = acdbHostApplicationServices()->workingDatabase();
	AcDbBlockTable *pBlockTable = NULL;
	AcDbBlockTableRecord *pMSBlkRec = NULL;
	pDatabase->getBlockTable(pBlockTable, AcDb::kForRead);
	if (Acad::eOk != pBlockTable->getAt(ACDB_MODEL_SPACE, pMSBlkRec, AcDb::kForWrite))
		return;

	AcDbLine *pLine1 = new AcDbLine(AcGePoint3d(0, 100, 0), AcGePoint3d(100, 100, 0));
	pLine1->setLinetype(_T("CustomLinetype1"));
	pLine1->setLinetypeScale(10);  //设置线型比例
	pMSBlkRec->appendAcDbEntity(pLine1);
	pLine1->close();

	AcDbLine *pLine2 = new AcDbLine(AcGePoint3d(100, 100, 0), AcGePoint3d(200, 100, 0));
	pLine2->setLinetype(_T("CustomLinetype2"));
	pLine1->setLinetypeScale(10);
	pMSBlkRec->appendAcDbEntity(pLine2);
	pLine2->close();

	pMSBlkRec->close();
	pBlockTable->close();
}