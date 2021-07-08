//
#include "stdafx.h"

#include "dbxrecrd.h"

#ifdef ARX 
#include "acedCmdNF.h"
#undef  acedCommand
#undef  ads_command
#define acedCommand acedCommandS
#define ads_command acedCommandS
#endif

#pragma region ExtensionDictionarySample

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
#if ZRX == 2020
	AcDbObject *pTmpObj = nullptr;
	acdbOpenObject(pDict, dictObjId, AcDb::kForWrite);
	pDict->getAt(_T("XRecord"), pTmpObj, AcDb::kForWrite);
	pXRecord = (AcDbXrecord*)pTmpObj;
#else
	acdbOpenObject(pDict, dictObjId, AcDb::kForWrite);
	pDict->getAt(_T("XRecord"), pXRecord, AcDb::kForWrite);
#endif
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

#pragma endregion

#pragma region LinetypeSample
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

#pragma endregion

#pragma region DatabaseSample

void createDwgTest()
{
	//Create an empty database
	AcDbDatabase *pDb = new AcDbDatabase(/*true, false*/);

	//Append some entities
	AcDbBlockTable *pBlockTable = NULL;
	pDb->getBlockTable(pBlockTable, AcDb::kForRead);
	AcDbBlockTableRecord *pBlockTableRec = NULL;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRec, AcDb::kForWrite);
	pBlockTable->close();
	AcDbCircle *pCircle = new AcDbCircle(AcGePoint3d(0, 0, 0), AcGeVector3d(0, 0, 1), 100.0);
	pBlockTableRec->appendAcDbEntity(pCircle);
	pCircle->close();
	pBlockTableRec->close();

	//Save database
	Acad::ErrorStatus es = pDb->saveAs(_T("./testDrawing1.dwg"));   //default file path(‪C:\Users\Admin\Documents\)
	if (es == Acad::eOk)
		acutPrintf(_T("\nDwg was saved successfully!"));
	else
		acutPrintf(_T("\nFailed to save the Dwg! es = %s."), acadErrorStatusText(es));

	delete pDb;
}
void readDwgFileTest()
{
	AcDbDatabase *pDb = new AcDbDatabase(false, true);   //The new database object is completely empty.

	//If there is no flag kForReadAndAllShare , 
	//readDwgFile will return  eFileSharingViolation when the testDrawing1.dwg is opened
	Acad::ErrorStatus es = pDb->readDwgFile(_T("./testDrawing1.dwg"), AcDbDatabase::kForReadAndAllShare);

	if (es == Acad::eOk)
	{
		AcDbBlockTable *pBlockTable = NULL;
		AcDbBlockTableRecord *pBlockTableRec = NULL;
		pDb->getBlockTable(pBlockTable, AcDb::kForRead);
		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRec, AcDb::kForRead);
		pBlockTable->close();

		AcDbBlockTableRecordIterator *pIter = NULL;
		pBlockTableRec->newIterator(pIter);
		for (; !pIter->done(); pIter->step())
		{
			AcDbEntity *pEnt = NULL;
			pIter->getEntity(pEnt, AcDb::kForRead);
			acutPrintf(_T("\nClass name: %s"), pEnt->isA()->name());
			pEnt->close();
		}
		delete pIter;

		pBlockTableRec->close();
	}
	delete pDb;
}
void OpenDocument(void *pData)
{
	AcApDocument* pDoc = acDocManager->curDocument();
	if (acDocManager->isApplicationContext())
	{
		acDocManager->appContextOpenDocument((const TCHAR *)pData);
	}
	else
	{
		acutPrintf(_T("\nError to open document!"));
	}
}
void openDwgFileTest()
{
	TCHAR *pData = _T("./testDrawing1.dwg");
	acDocManager->executeInApplicationContext(OpenDocument, (void*)pData);
}

#pragma  endregion

#pragma region CommandSample

ARXCMD3(acedcommandTest)
{
#if 1
	acedCommand(RTSTR, _T("LINE"), RT3DPOINT, AcGePoint3d(0, 0, 0), RT3DPOINT, AcGePoint3d(100, 100, 0), RTSTR, _T(""), RTNONE);
#else //另一种方法
	acedCommand(RTSTR, _T("LINE"), RTSTR, _T("0, 0"), RTSTR, _T("100, 100"), RTSTR, _T(""), RTNONE);
#endif
	acedCommand(RTSTR, _T("ZOOM"), RTSTR, "E", RTNONE);
}
ARXCMD3(acedcommandPauseTest)
{
	acedCommand(RTSTR, _T("CIRCLE"), RTSTR, _T("0, 0"), RTSTR, PAUSE, RTNONE);
	acedCommand(RTSTR, _T("CIRCLE"), RTSTR, PAUSE, RTSTR, _T("100"), RTNONE);
}

#pragma endregion

#pragma region EntSelSample

ARXCMD3(entSelSampe)
{
	ads_name entName;
	ads_point adsPt;
	int nRet = acedEntSel(_T("\nSelect a Entity:"), entName, adsPt);
	if (nRet == RTNORM)
	{
		AcDbObjectId objId;
		Acad::ErrorStatus es = Acad::eOk;
		if ((es = acdbGetObjectId(objId, entName)) != Acad::eOk)
		{
			acutPrintf(_T("\nErrorStatus = %s"), acadErrorStatusText(es));
			return;
		}

		AcDbEntity* pEnt = nullptr;
		if ((es = acdbOpenAcDbEntity(pEnt, objId, AcDb::kForRead)) != Acad::eOk)
		{
			acutPrintf(_T("\nErrorStatus = %s"), acadErrorStatusText(es));
			return;
		}

		acutPrintf(_T("\nThe Entity you select is %s"), pEnt->isA()->name());
		pEnt->close();
	}
}

#pragma endregion

#pragma region Interacton

ARXCMD3(getKWordTest)
{
	TCHAR keyWord[10] = { 0 };
	// local keywords_global keywords
	//acedInitGet(0, _T("ALL B C D_A B C D"));
	//acedInitGet(0, _T("ALL AN B C D"));  // 如果compare "A"，没有关键词A, 输入A不识别
	acedInitGet(0, _T("ALL AN B C D")); 
	int retVal = acedGetKword(_T("Input KeyWord [Branch A(CLL)/Branch B(B)/Branch C(C)/Branch D(D)]: "), keyWord);
	if (retVal == RTNORM)
	{
		if (_tcscmp(keyWord, _T("ALL")) == 0)
			acutPrintf(_T("\nThis is Branch ALL"));
		else if (_tcscmp(keyWord, _T("AN")) == 0)
			acutPrintf(_T("\nThis is Branch AN"));
		else if (_tcscmp(keyWord, _T("B")) == 0)
			acutPrintf(_T("\nThis is Branch B"));
		else if (_tcscmp(keyWord, _T("CD")) == 0)
			acutPrintf(_T("\nThis is Branch C"));
		else if (_tcscmp(keyWord, _T("D")) == 0)
			acutPrintf(_T("\nThis is Branch D"));
	}
	else if (retVal == RTCAN)
		acutPrintf(_T("\nYou have cancelled!"));
	else if (retVal == RTNONE)
		acutPrintf(_T("\nYou Have not input, and the default is Branch D"));
}

#pragma endregion