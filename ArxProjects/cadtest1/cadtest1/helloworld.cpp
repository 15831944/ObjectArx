#include "stdafx.h"
#include "CADUtils.h"

#include "dbapserv.h"
#include "migrtion.h"
#include "acestext.h"

#ifdef ARX 
#include "acedCmdNF.h"
#undef  acedCommand
#undef  ads_command
#define acedCommand acedCommandS
#define ads_command acedCommandS
#endif

#define printEs(val){acutPrintf(_T("\n%s = %s"),_T(#val),acadErrorStatusText(val));}

ARXCMD3(HelloWorld)
{
	AA();
	AAINFO(_T("\nHello world!"));
	acutPrintf(_T("\nHello world!"));
}
#include "dbapserv.h"
#include "migrtion.h"
#include "acestext.h"
ARXCMD3(insertDwgTest)
{
	AcDbDatabase *pDb = new AcDbDatabase(Adesk::kFalse);
	Acad::ErrorStatus es = pDb->readDwgFile(_T("D:\\test_p.dwg"));
	acutPrintf(_T("\nes = %s"), acadErrorStatusText(es));

	AcGeMatrix3d matrix;
	AcGePoint3d insertpointDwg(100, 100, 0);
	matrix.setTranslation(insertpointDwg.asVector());
	Acad::ErrorStatus es1 = acdbCurDwg()->insert(matrix, pDb);
	acutPrintf(_T("\nes1 = %s"), acadErrorStatusText(es1));

	delete pDb;
}
ARXCMD3(readDwg)
{
	AcDbDatabase *pDb = new AcDbDatabase(Adesk::kFalse);
	Acad::ErrorStatus es = pDb->readDwgFile(_T("D:\\DDDD\\LB_Insertͼֽ����ʵ�岻��ʾ\\test.dwg"));
	printEs(es);

	es = pDb->saveAs(_T("D:\\DDDD\\LB_Insertͼֽ����ʵ�岻��ʾ\\save.dwg"));
	printEs(es);

	delete pDb;
}
#include "rxmfcapi.h"
#include "core_rxmfcapi.h"
void WatchWinMsg(const MSG* msg)
{
	HWND g_hMDIHwnd = acedGetAcadFrame()->m_hWndMDIClient;
	if (msg->message == WM_LBUTTONDOWN)
	{
		CPoint cpt(msg->lParam);
		ClientToScreen(g_hMDIHwnd, &cpt);
		acutPrintf(_T("\nMouse point (%d, %d)"), cpt.x, cpt.y);
	}
}

ARXCMD3(testDeleteHatch)
{
	Acad::ErrorStatus es;
	AcDbBlockTable *pBT = NULL;
	AcDbBlockTableRecord *pBTR = NULL;
	//acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBT, AcDb::kForRead);

	AcDbDatabase *pDb = new AcDbDatabase(false);
	es = pDb->readDwgFile(_T("D:\\TestDeleteHatch.dwg"));
	acdbHostApplicationServices()->setWorkingDatabase(pDb);

	pDb->getBlockTable(pBT, AcDb::kForRead);

	pBT->getAt(ACDB_MODEL_SPACE, pBTR, AcDb::kForRead);
	AcDbBlockTableRecordIterator *iter = NULL;
	pBTR->newIterator(iter);

	int count = 0;
	for (iter->start(); !iter->done(); iter->step())
	{
		count++;
		AcDbEntity *pEnt = NULL;
		es = iter->getEntity(pEnt, AcDb::kForRead);

		CString szEntClass = pEnt->isA()->name();

		if (szEntClass == _T("AcDbHatch"))
		{
			if (Acad::eOk == pEnt->upgradeOpen())
			{
				pEnt->erase();
			}
		}
		es = pEnt->close();
	}
	acutPrintf(_T("\nSuccess! count = %d"), count);

	delete iter;
	iter = nullptr;

	pBT->close();
	pBTR->close();
}

ARXCMD3(addMsg)
{
	acedRegisterWatchWinMsg(WatchWinMsg);
}

ARXCMD3(removeMsg)
{
	acedRemoveWatchWinMsg(WatchWinMsg);
}

ARXCMD3(test111)
{
	CMDIFrameWnd* pAcadFrame = acedGetAcadFrame();
	//pAcadFrame->RecalcLayout();
	pAcadFrame->UpdateWindow();

	//((CFrameWnd*)AfxGetMainWnd())->RecalcLayout();
	//((CFrameWnd*)AfxGetMainWnd())->UpdateWindow();
}
ARXCMD3(test112)
{
	//CMDIFrameWnd* pAcadFrame = acedGetAcadFrame();
	//pAcadFrame->SetActiveWindow();
	//pAcadFrame->SetFocus();

}

#include <vector>
ARXCMD3(testVector)
{
	std::vector<int> vec;
}

#include "acedads.h"
#include "adscodes.h"
#include "aced.h"
#include "acadi.h"

//#include "D:\DDDD\cadtest1\Out\tmp\cadtest1_AR2020_x64\acax23chs.tlh"
//#import "C:\\Program Files\\Common Files\\Autodesk Shared\\acax23chs.tlb" raw_interfaces_only no_namespace
ARXCMD3(testsendStringToExecute)
{
	CString cmd = _T("zoom w 0,0 500,500 ");
	Acad::ErrorStatus es(Acad::eOk);

	AcApDocumentIterator* iter = acDocManager->newAcApDocumentIterator();
	AcApDocument* pDoc = NULL;

	//for (; !iter->done(); iter->step())
	//{
	//	pDoc = iter->document();
		//es = acDocManager->sendStringToExecute(pDoc, cmd, false, true, false);
		//acutPrintf(_T("es = %s\n"), acadErrorStatusText(es));

		//int nRet = acedCommand(RTSTR, L"zoom", RTNORM, L"w", RTSTR, L"0,0", RTSTR, L"500,500", RTNONE);
		//acutPrintf(_T("nRet = %d\n"), nRet);

		CComPtr <IAcadApplication>pAcad = NULL;
		IDispatch* pDispatch = acedGetAcadWinApp()->GetIDispatch(TRUE);
		if (SUCCEEDED(pDispatch->QueryInterface(__uuidof(pAcad), (void**)&pAcad)))
		{
			/*CComPtr<IAcadDocument> pDoc = NULL;*/
			//pAcad->get_ActiveDocument(&pDoc);
			CComPtr<IAcadDocuments> pDocs = NULL;
			pAcad->get_Documents(&pDocs);
			long lCount = 0;
			pDocs->get_Count(&lCount);
			for (int i = 0; i < lCount; i++)
			{
				VARIANT index;
				VariantInit(&index);
				V_VT(&index) = VT_I4;
				V_I4(&index) = i;
				CComPtr<IAcadDocument> pDoc = NULL;
				pDocs->Item(index, &pDoc);
				pDoc->SendCommand(cmd.GetBuffer());
			}
		}
	//}
	if (iter)
	{
		delete iter;
		iter = NULL;
	}
}

ARXCMD3(testacdbAngToF)
{
	double dAng = 0.0;
	acdbAngToF(_T("180"), 0, &dAng);
	acutPrintf(_T("\ndAng = %g"), dAng);
}
#include "adsdef.h"

struct resbuf *get_resbuf(struct resbuf* p, int code)
{
	struct resbuf *head2;
	for (head2 = p; (head2 != NULL) && (head2->restype != code); head2 = head2->rbnext);
	return (head2);
}

ARXCMD3(CmdLayer)
{
	TCHAR* tblName = _T("LAYER");
	TCHAR* filter = _T("*");
	TCHAR* name;
	int flag = 1;
	CStringArray arrLayer;
	while (1)
	{  // a font
		resbuf *ebuf = ads_tblnext(tblName, flag);
		if (!ebuf) break;
		resbuf * tabs = get_resbuf(ebuf, 2);
		if (tabs)
		{
			name = tabs->resval.rstring;
			{
				_tcsupr(name);
				if (ads_wcmatch(name, filter) == RTNORM)
					arrLayer.Add(name);
			}
		}
		flag = 0;
	}
	CString sLockLay;
	LPCTSTR sCmd = _T("_LO");
	for (int i = 0; i < arrLayer.GetCount(); i++)
	{
		if (!sLockLay.IsEmpty())
			sLockLay += _T(",");
		sLockLay += arrLayer[i];
	}
	
	ads_command(RTSTR, _T("_-LAYER"), RTSTR, sCmd, RTSTR, (LPCTSTR)sLockLay, RTSTR, _T(""), NULL);
	//acutPrintf(_T("\nlen:%d"), wcslen(sLockLay));
}

ARXCMD3(CmdLayer3)
{
	TCHAR* tblName = _T("LAYER");
	TCHAR* filter = _T("*");
	TCHAR* name;
	int flag = 1;
	CStringArray arrLayer;
	while (1)
	{  // a font
		resbuf *ebuf = ads_tblnext(tblName, flag);
		if (!ebuf) break;
		resbuf * tabs = get_resbuf(ebuf, 2);
		if (tabs)
		{
			name = tabs->resval.rstring;
			{
				_tcsupr(name);
				if (ads_wcmatch(name, filter) == RTNORM)
					arrLayer.Add(name);
			}
		}
		flag = 0;
	}
	CString sLockLay;
	LPCTSTR sCmd = _T("_LO");
#if 0
	for (int i = 0; i < arrLayer.GetCount(); i++)
	{
		if (!sLockLay.IsEmpty())
			sLockLay += _T(",");
		sLockLay += arrLayer[i];
	}
#endif

	sLockLay += _T("b00a");
	//for (int i = 0; i < 500; i++)
	//{
	//	//if (!sLockLay.IsEmpty())
	//	//	sLockLay += _T(",");
	//	CString szTemp;
	//	szTemp.Format(_T("ͼL%d%d%d"), i / 100, i / 10 % 10, i % 10);
	//	sLockLay += szTemp;
	//}
	//sLockLay += _T(",0");
	ads_command(RTSTR, _T("_-LAYER"), RTSTR, sCmd, RTSTR, (LPCTSTR)sLockLay, RTSTR, _T(""), NULL);
}

ARXCMD3(CurrentViewPortCenterTest)
{
	//Returns the object ID of the viewport that is currently active in the editor.
	//In tilemode, it returns the ID is of a viewport table record. In layout mode, returns the object ID of a viewport entity . 
	//Returns a null object ID if no document is open.
	AcDbObjectId curVId = acedActiveViewportId();
	AcDbObject *pCurVP = nullptr;
	if (Acad::eOk == acdbOpenObject(pCurVP, curVId, AcDb::kForRead))
	{
		//���ֿռ䷵�ص��Ǽ�����ӿڻ���Ĭ�ϵĵ�һ��AcDbViewport
		if(pCurVP->isA() == AcDbViewport::desc())
		acutPrintf(_T("\nCenPt(%g, %g)"), ((AcDbViewport*)pCurVP)->centerPoint().x, ((AcDbViewport*)pCurVP)->centerPoint().y);
		else if (pCurVP->isA() == AcDbViewportTableRecord::desc())
			acutPrintf(_T("\nCenPt(%g, %g)"), ((AcDbViewportTableRecord*)pCurVP)->centerPoint().x, ((AcDbViewportTableRecord*)pCurVP)->centerPoint().y);
		pCurVP->close();
		pCurVP = nullptr;
	}
}

//ͨ��zrx�ӿڶ���lisp�����lisp�����Լ���η��ؽ��
ADSFUNC(lispFuncTest)
{
	acutPrintf(_T("\n1111"));
	//acdbFail("Argument should be positive.");
	//return RTERROR;
	acedRetVoid();
	return RTNORM;
}
int printLispTest(resbuf* rb)
{
	acutPrintf(_T("\n1111"));
	//acdbFail("Argument should be positive.");
	//return RTERROR;
	acedRetVoid();
	return RTNORM;
}
ADSCMD(lispFuncTest, printLispTest)


//the implementation of the actual external factorial function 
static ads_real rfact(int n)
{
	ads_real ans = 1.0;

	while (n)
		ans *= n--;

	return ans;
}
ADSFUNC(factorial)
{
	int x;
	if (rb == NULL)
		return RTERROR;

	// Save in local variable 
	if (rb->restype == RTSHORT)     
	{
		x = rb->resval.rint;         
	}
	else 
	{
		acdbFail(_T("Argument should be an integer."));
		return RTERROR;
	}
	// Check argument range 
	if (x < 0)            
	{                     
		acdbFail(_T("Argument should be positive."));
		return RTERROR;
	}
	// Avoid floating-point overflow 
	else if (x > 170)     
	{             
		acdbFail(_T("Argument should be 170 or less."));
		return RTERROR;
	}

	acedRetReal(rfact(x));            //Call the function itself, and return the value to AutoLISP
	return RTNORM;
}

#include "dbhatch.h"
//�߽��ɴ����ڲ�Բ�ο׵��ⲿ���λ���ɡ����ͼ���Ǿ��е�ǰAutoCADĬ����ɫ��ANSI31Ԥ�������͡�
//�´�����ͼ������ǹ����ģ������������и���Դ�߽缸����״�Ը���ͼ����䡣

ARXCMD3(acqHatch2)
{
	AcDbHatch* pHatch = new AcDbHatch();

	//Set hatch plane
	AcGeVector3d normal(0.0, 0.0, 1.0);
	pHatch->setNormal(normal);

	pHatch->setElevation(0.0);

	//Set hatch pattern to ANSI31 predefined type 
	pHatch->setPattern(AcDbHatch::kPreDefined, _T("ANSI31"));

	//Set Associativity
	pHatch->setAssociative(Adesk::kTrue);

	//Construct database AcDbLines

	AcGePoint3d vertexPts[4];
	AcDbObjectId lineId, cirId, hatchId;
	AcDbObjectIdArray dbObjIds;

	AcDbLine *line = nullptr;
	vertexPts[0].set(2.0, 2.0, 0.0);
	vertexPts[1].set(8.0, 2.0, 0.0);
	vertexPts[2].set(8.0, 8.0, 0.0);
	vertexPts[3].set(2.0, 8.0, 0.0);

	for (int i = 0; i < 4; i++)
	{
		line = new AcDbLine();
		line->setStartPoint(vertexPts[i]);
		line->setEndPoint(vertexPts[(i == 3) ? 0 : i + 1]);

		CADUtils::AppendToModalSpace(line, lineId);
		line->close();

		dbObjIds.append(lineId);
	}

	//Append an external rectangular loop to hatch boundary
	pHatch->appendLoop(AcDbHatch::kExternal, dbObjIds);

	// Create a AcDbCircle and post it to database 
	AcGePoint3d cenPt(5.0, 5.0, 0.0);
	normal.set(0.0, 0.0, 1.0);
	AcDbCircle *circle = new AcDbCircle();
	circle->setNormal(normal);
	circle->setCenter(cenPt);
	circle->setRadius(1.0);
	CADUtils::AppendToModalSpace(circle, cirId);
	circle->close();

	dbObjIds.setLogicalLength(0);
	dbObjIds.append(cirId);

	// Append an internal loop (circle) to hatch boundary
	pHatch->appendLoop(AcDbHatch::kDefault, dbObjIds);

	// Elaborate hatch lines
	pHatch->evaluateHatch();

	// Get all associative source boundary object Ids for later use.
	dbObjIds.setLogicalLength(0);

	pHatch->getAssocObjIds(dbObjIds);
	// Post hatch entity to database
	CADUtils::AppendToModalSpace(pHatch, hatchId);

	// Attach hatchId to all source boundary objects for notification.

	AcDbEntity *pEnt = nullptr;
	int numObjs = dbObjIds.length();
	for (int i = 0; i < numObjs; i++)
	{
		if (acdbOpenAcDbEntity(pEnt, dbObjIds[i],AcDb::kForWrite) == Acad::eOk)
		{
			pEnt->addPersistentReactor(hatchId);
			pEnt->close();
		}
	}
}

// 5 6 -1 5 4 -7
// 7 0 6 -1 1 -6 7 -5
// 14 1 4
// 7 1 6

// a[1...n]
// fun(n) = max(fun(n-1), fun(n-1) + a[n])



//�߽��ɴ����ڲ�Բ�ο׵��ⲿ���λ���ɡ����ͼ��ΪSOLID����ǰʹ��AutoCADĬ����ɫ���´�����ͼ�����û�й�����
ARXCMD3(acqHatch1)
{
	AcDbHatch* pHatch = new AcDbHatch();
	// Set hatch plane
	AcGeVector3d normal(0.0, 0.0, 1.0);
	pHatch->setNormal(normal);
	pHatch->setElevation(0.0);

	// Set non associative hatch
	pHatch->setAssociative(Adesk::kFalse);

	// Set hatch pattern to SolidFill type
	pHatch->setPattern(AcDbHatch::kPreDefined, _T("SOLID"));

	// Set hatch style to kNormal
	pHatch->setHatchStyle(AcDbHatch::kNormal);

	// Construct hatch external boundary
	AcGePoint2dArray vertexPts;
	AcGeDoubleArray vertexBulges;
	vertexPts.setPhysicalLength(0).setLogicalLength(5);
	vertexPts[0].set(2.0, 2.0);
	vertexPts[1].set(8.0, 2.0);
	vertexPts[2].set(8.0, 8.0);
	vertexPts[3].set(2.0, 8.0);
	vertexPts[4].set(2.0, 2.0);
	vertexBulges.setPhysicalLength(0).setLogicalLength(5);
	for (int i = 0; i < 5; i++)
		vertexBulges[i] = 0.0;

	// Append an external loop (rectangle) to hatch boundary
	pHatch->appendLoop(AcDbHatch::kExternal, vertexPts, vertexBulges);

	// Construct a circle
	AcGePoint2d cenPt(5.0, 5.0);
	double TWOPI = 2.0 * 3.1415926535897932;
	AcGeCircArc2d *cirArc = new AcGeCircArc2d();
	cirArc->setCenter(cenPt);
	cirArc->setRadius(1.0);
	cirArc->setAngles(0.0, TWOPI);

	// Append an internal circular loop to hatch boundary
	AcGeIntArray edgeTypes;
	AcGeVoidPointerArray edgePtrs;
	edgeTypes.append(AcDbHatch::kCirArc);
	edgePtrs.append((void*)cirArc);
	pHatch->appendLoop(AcDbHatch::kDefault, edgePtrs, edgeTypes);

	// Elaborate solid fill
	pHatch->evaluateHatch();

	// Post hatch entity to database
	AcDbObjectId newId;
	CADUtils::AppendToModalSpace(pHatch, newId);
	pHatch->close();
}

ARXCMD3(hatch_1)
{
	AcDbHatch *pHatch = new AcDbHatch();
	AcGeVoidPointerArray vptrArr;

	AcDbCircle *pCircle1 = new AcDbCircle(AcGePoint3d(0, 0, 0), AcGeVector3d::kZAxis, 100.0);
	AcDbObjectId circleId1;
	CADUtils::AppendToModalSpace(pCircle1, circleId1);
	pCircle1->close();

	AcDbCircle *pCircle2 = new AcDbCircle(AcGePoint3d(0, 0, 0), AcGeVector3d::kZAxis, 150.0);
	AcDbObjectId circleId2;
	CADUtils::AppendToModalSpace(pCircle2, circleId2);
	pCircle2->close();

	AcDbCircle *pCircle3 = new AcDbCircle(AcGePoint3d(0, 0, 0), AcGeVector3d::kZAxis, 200.0);
	AcDbObjectId circleId3;
	CADUtils::AppendToModalSpace(pCircle3, circleId3);
	pCircle3->close();

	pHatch->setNormal(AcGeVector3d::kZAxis);
	pHatch->setElevation(0.0);
	pHatch->setAssociative(Adesk::kTrue);
	pHatch->setPattern(AcDbHatch::kPreDefined, _T("SOLID"));
	//pHatch->setPattern(AcDbHatch::kPreDefined, _T("ANSI31"));
	//pHatch->setHatchStyle(AcDbHatch::kNormal);
	//pHatch->setHatchStyle(AcDbHatch::kOuter);
	//pHatch->setHatchStyle(AcDbHatch::kIgnore);

#if 0
	vptrArr.append((void*)circleId1);
	vptrArr.append((void*)circleId2);
	vptrArr.append((void*)circleId3);
	AcGeIntArray edgeTypes;
	edgeTypes.append(AcDbHatch::kCirArc);
	edgeTypes.append(AcDbHatch::kCirArc);
	edgeTypes.append(AcDbHatch::kCirArc);
	pHatch->appendLoop(7, vptrArr, edgeTypes);
#else
	AcDbObjectIdArray ids1,ids2,ids3;
#if 1  //normal
	ids1.append(circleId1);
	ids2.append(circleId2);
	ids3.append(circleId3);
	pHatch->appendLoop(AcDbHatch::kDefault, ids1);
	pHatch->appendLoop(AcDbHatch::kOutermost, ids2);
	pHatch->appendLoop(AcDbHatch::kExternal, ids3);
#endif
#endif
	pHatch->evaluateHatch();
	AcDbObjectId newId;
	CADUtils::AppendToModalSpace(pHatch, newId);
	pHatch->close();
}

int SelectEntities(AcDbObjectIdArray & entIdArray)
{
	ads_name ss;
	int ret = acedSSGet(NULL, NULL, NULL, NULL, ss);
	if (ret == RTNORM)
	{
#if ARX>2013 || ZRX > 2020
		Adesk::Int32 len = 0;
#else
		long len = 0;
#endif
		acedSSLength(ss, &len);
		for (int i = 0; i < len; i++)
		{
			ads_name ent;
			AcDbObjectId entId;
			acedSSName(ss, i, ent);
			acdbGetObjectId(entId, ent);
			if (entId.isValid())
			{
				entIdArray.append(entId);
			}
		}
		acedSSFree(ss);
	}
	return ret;
}

// ���һ�����
// ����ͬһ���߽�����������Ӵ�С������Ȼ�����depthȷ��style��0--kExternal�� 1--kOutermost��other--kDefault
#include <map>
#include <vector>
#include <algorithm>
ARXCMD3(hatch_2)
{
	AcDbObjectIdArray ids, idsRet;
	if (RTNORM != SelectEntities(ids) || ids.length() == 0)
		return;

	std::map<AcDbObjectId, double> idsMap;
	for (int i = 0; i < ids.length(); i++)
	{
		AcDbEntity *pEnt = nullptr;
		double dArea = 0.0;
		Acad::ErrorStatus es = acdbOpenAcDbEntity(pEnt, ids[i], AcDb::kForRead);
		((AcDbCurve*)pEnt)->getArea(dArea);

		idsMap.insert(std::pair<AcDbObjectId, double>(ids[i], dArea));
		pEnt->close();
	}
	
	std::vector<std::pair<AcDbObjectId, double>> vec;
	for (std::map<AcDbObjectId, double>::iterator iter = idsMap.begin(); iter != idsMap.end(); iter++)
		vec.push_back(std::pair<AcDbObjectId, double>(iter->first, iter->second));
	// ͬһ���� �߽簴�������
	//sort(vec.begin(), vec.end(), [](std::pair<AcDbObjectId, double>&a, std::pair<AcDbObjectId, double>&b) {return a.second > b.second; });

	AcDbHatch *pHatch = new AcDbHatch();
	pHatch->setNormal(AcGeVector3d::kZAxis);
	pHatch->setElevation(0.0);
	pHatch->setAssociative(Adesk::kTrue);
	pHatch->setPattern(AcDbHatch::kPreDefined, _T("SOLID"));
	acedInitGet(NULL, _T("N O I"));
	TCHAR szRet[32] = { 0 };
	acedGetKword(_T("Style type:"), szRet);
	if (_tcscmp(_T("N"), szRet) == 0)
		pHatch->setHatchStyle(AcDbHatch::kNormal);
	else if (_tcscmp(_T("O"), szRet) == 0)
		pHatch->setHatchStyle(AcDbHatch::kOuter);
	else if (_tcscmp(_T("I"), szRet) == 0)
		pHatch->setHatchStyle(AcDbHatch::kIgnore);
		
	int nDep = 0;
	std::vector<std::pair<AcDbObjectId, double>>::iterator iter = vec.begin();
	for(; iter != vec.end(); iter++)
	{
		if (nDep == vec.size() -1)
		{
			AcDbObjectIdArray arrExternalId;
			arrExternalId.append(iter->first);
			pHatch->appendLoop(AcDbHatch::kExternal, arrExternalId);
		}
		else if (nDep == vec.size() - 2)
		{
			AcDbObjectIdArray arrOutermostId;
			arrOutermostId.append(iter->first);
			pHatch->appendLoop(AcDbHatch::kOutermost, arrOutermostId);
		}
		else
		{
			AcDbObjectIdArray arrDefaultId;
			arrDefaultId.append(iter->first);
			pHatch->appendLoop(AcDbHatch::kDefault, arrDefaultId);
		}
		nDep++;
	}

	pHatch->evaluateHatch();
	AcDbObjectId newId;
	CADUtils::AppendToModalSpace(pHatch, newId);
	pHatch->close();
}
//acedSSGetѡ��ʵ�尴����������У�AcDbSortentsTable��������
// ��ʵ��ֽ�ɶ�����Բ(��)��ֱ�� -> �ϲ��ص�����(���ߡ��ص�) -> �µ�ʵ����ݽ����ٷֽ�ɶ�����ʵ��� -> �������յ���Щʵ��δ������� -> �ҵ�Ŀ����������򴴽�hatch -> ɾ������
ARXCMD3(hatch_3)
{
	AcDbObjectIdArray ids;
	if (RTNORM != SelectEntities(ids) || ids.length() == 0)
		return;
	bool bRet = ids[0] < ids[1] ? true : false;
	acutPrintf(_T("\nbRet = %d"), bRet);
}

AcGsView* GetCurrentGsView()
{
	struct resbuf rb;
	int rt = acedGetVar(_T("CVPORT"), &rb);
	if (rt != RTNORM)
	{
		acutPrintf(_T("\nError!"));
		return nullptr;
	}
	int vportNum = rb.resval.rint;
	//Get GsView associated with the viewport
#if ARX >= 2019 || ZRX >= 2021
	AcGsView* pGsView = acgsGetCurrentAcGsView(vportNum);
#else
	AcGsView* pGsView = acgsGetGsView(vportNum, false);
#endif
	if (pGsView)
		acutPrintf(_T("\nThe current is in shaded mode..."));
	else
		acutPrintf(_T("\nThe current is in 2d wireframe mode..."));
	return pGsView;
}
extern void refreshView(AcGsView *pView);
void GetAllEntity(AcDbObjectIdArray& ids)
{
	Acad::ErrorStatus es = Acad::eOk;
	AcDbBlockTable *pBlkTbl;
	acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlkTbl, AcDb::kForRead);

	AcDbBlockTableRecord *pBlkTblRcd;
	es = pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRcd, AcDb::kForRead);
	pBlkTbl->close();

	AcDbBlockTableRecordIterator *pItr;
	es = pBlkTblRcd->newIterator(pItr);
	pBlkTblRcd->close();
	AcDbEntity *pEnt = NULL;
	for (pItr->start(); !pItr->done(); pItr->step())
	{
		es = pItr->getEntity(pEnt, AcDb::kForRead); //kForWrite����������db������ eLockViolation 
		ids.append(pEnt->objectId());
		pEnt->close();
	}
	delete pItr;
	pItr = nullptr;
}
AcDbExtents GetAllExtents(const AcDbObjectIdArray& idArrSel)
{
	AcDbExtents extRet;
	int iLen = idArrSel.length();
	if (iLen < 1)
	{
		return extRet;
	}

	AcAxDocLock DbLock(idArrSel.first().database());

	AcDbEntity* pCurEnt = NULL;
	for (int i = 0; i < iLen; ++i)
	{
		AcDbObjectId idCur = idArrSel.at(i);
		Acad::ErrorStatus esOpen = acdbOpenAcDbEntity(pCurEnt, idCur, AcDb::kForRead);
		if (esOpen != Acad::eOk)
		{
			continue;
		}
		pCurEnt->close();

		AcDbExtents extCur;
		if (pCurEnt->getGeomExtents(extCur) != Acad::eOk)
		{
			continue;
		}

		extRet.addExt(extCur);
	}

	return extRet;
}
BOOL SetViewInfo(AcGePoint3d ptTarget, AcGeVector3d viewDirection, const AcDbExtents& ext, BOOL bUpdateScreen)
{
	BOOL bOk = FALSE;
	AcDbObjectId idViewRecord;

	Acad::ErrorStatus es = Acad::eOk;
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbViewportTable* pVportTable = NULL;
	es = pDb->getViewportTable(pVportTable, AcDb::kForRead);
	//if (GetCurrentViewId(CUR_DB, idViewRecord))
	if (es == Acad::eOk)
	{
		//TPmAcDbOpenAction<AcDbViewportTableRecord> act;
		AcDbViewportTableRecord* pVportTableRec = NULL;
		es = pVportTable->getAt(ACRX_T("*Active"), pVportTableRec, AcDb::kForWrite);
		//if(Acad::eOk == act.OpenObject(pVT, idViewRecord, AcDb::kForWrite))
		if (es == Acad::eOk)
		{
			pVportTableRec->setTarget(ptTarget);
			pVportTableRec->setViewDirection(viewDirection);

			pVportTableRec->viewTwist();
			//act.CloseAction();
			pVportTable->close();
			pVportTableRec->close();
		}

		//���¼�����Ļ��������
		es = pVportTable->getAt(ACRX_T("*Active"), pVportTableRec, AcDb::kForWrite);
		//if(Acad::eOk == act.OpenObject(pVT, idViewRecord, AcDb::kForWrite))
		AcGePoint3d ptMin, ptMax;
		if (es == Acad::eOk)
		{
			ptMin = ext.minPoint();
			ptMax = ext.maxPoint();

			//set the viewport to extents along the current view dir
			//PmFun::cad::fSetViewportToExtents(pVT, ptMax, ptMin);

			AcGsView* pGsView = GetCurrentGsView();
			AcGePoint3d position = ptTarget + viewDirection;
			AcGeVector3d upVecter = viewDirection.crossProduct(viewDirection.perpVector().normal());
			//AcGePoint3d boxCenter = ext.minPoint() + 0.5 * (ext.maxPoint() - ext.minPoint());
			//ptTarget = boxCenter;
			double xMax = fabs(ext.maxPoint().x - ext.minPoint().x);
			double yMax = fabs(ext.maxPoint().y - ext.minPoint().y);
			pGsView->setView(position, ptTarget, upVecter, xMax, yMax);

			//act.CloseAction();
			pVportTable->close();
			pVportTableRec->close();
		}

		//ˢ�½���
		if (bUpdateScreen)
			acedVportTableRecords2Vports();

		bOk = TRUE;
	}
	return bOk;
}
BOOL SetCurrentVisualStyle(AcDbDatabase* pDb, CString visualStyleName)
{
	BOOL bOk = FALSE;
	Acad::ErrorStatus es = Acad::eOk;

	AcDbViewportTable* pVportTable = NULL;
	es = pDb->getViewportTable(pVportTable, AcDb::kForRead);
	if (es == Acad::eOk)
	{
		//��ȡ��ʽ��
		AcDbDictionary* pVisualStyleDic;
		es = pDb->getVisualStyleDictionary(pVisualStyleDic, AcDb::kForRead);
		//��ȡ�ӿ���ʽ
		AcDbObjectId idVisualStyle;
		es = pVisualStyleDic->getAt(visualStyleName, idVisualStyle);
		pVisualStyleDic->close();

		AcDbViewportTableRecord* pVportTableRec = NULL;
		es = pVportTable->getAt(ACRX_T("*Active"), pVportTableRec, AcDb::kForWrite);
		//if(Acad::eOk == act.OpenObject(pVT, idViewRecord, AcDb::kForWrite))
		if (es == Acad::eOk)
		{
			if (visualStyleName == _T("Realistic"))
			{
#if !(defined ARX) || (ARX < 23) 
				pVportTableRec->setRenderMode(AcDbAbstractViewTableRecord::kGouraudShaded);
#endif
			}
			pVportTableRec->setVisualStyle(idVisualStyle);
			//act.CloseAction();
			pVportTable->close();
			pVportTableRec->close();

			acedVportTableRecords2Vports();
			bOk = TRUE;
		}
	}
	return bOk;
}

//��Χ������Ϊtarget��camera position = target +��viewDirection
void SetViewTo(AcGsView *pView, AcDbDatabase *pDb, AcGeVector3d viewDirection, AcGeMatrix3d& viewMat, AcGePoint3d extMax, AcGePoint3d extMin)
{
	if (extMin.distanceTo(extMax) > 1e20)
	{
		extMin.set(0, 0, 0);
		extMax.set(100, 100, 100);
	}

	ads_real height = 0.0, width = 0.0, viewTwist = 0.0;

	//AcGeVector3d viewDir = AcGeVector3d(0, 0, 1);
	AcGeVector3d viewDir = viewDirection;

	AcGeVector3d viewXDir = viewDir.perpVector().normal();
	viewXDir = viewXDir.rotateBy(viewTwist, -viewDir);
	AcGeVector3d viewYDir = viewDir.crossProduct(viewXDir);

	AcGePoint3d boxCenter = extMin + 0.5 * (extMax - extMin);

	viewMat = AcGeMatrix3d::alignCoordSys(boxCenter, AcGeVector3d::kXAxis, AcGeVector3d::kYAxis, AcGeVector3d::kZAxis,
		boxCenter, viewXDir, viewYDir, viewDir).inverse();

	AcDbExtents wcsExtents(extMin, extMax);
	AcDbExtents viewExtents = wcsExtents;
	viewExtents.transformBy(viewMat);

	double xMax = fabs(viewExtents.maxPoint().x - viewExtents.minPoint().x);
	double yMax = fabs(viewExtents.maxPoint().y - viewExtents.minPoint().y);

	AcGePoint3d eye = boxCenter + viewDir;

	//viewDrection = position - target
	pView->setView(eye, boxCenter, viewYDir, xMax, yMax);

	//pView->zoomExtents(extMin, extMax);

	//refreshView(pView);
}
ARXCMD3(Test_Viewport)
{
	//�����ӽ�
	//ViewportFun::SetViewInfo(ptTarget, AcGeVector3d(1,-1,1), extAll, FALSE);
	AcDbObjectIdArray ids;
	GetAllEntity(ids);
	AcDbExtents extAll = GetAllExtents(ids);

	AcGePoint3d ptMax = extAll.maxPoint();
	AcGePoint3d ptMin = extAll.minPoint();
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();

	AcGePoint3d ptTarget(0, 0, 0);
	//Get current camara position
	//struct resbuf rb;
	//acedGetVar(_T("TARGET"), &rb);
	//ptTarget = asPnt3d(rb.resval.rpoint);
	SetViewInfo(ptTarget, AcGeVector3d(1, -1, 1), extAll, FALSE);

	//��ʾ�Ӿ���ʽ---3D��ʵ
	//ViewportFun::SetVisibleStyle_3DRealistic();
	SetCurrentVisualStyle(pDb, _T("Realistic"));
	//���ŵ�ָ����Χ
	//CProjectShowModelView::Zoom_Extents(m_idsGiToGal);

	AcGsView* pGsView = GetCurrentGsView();
	pGsView->zoomExtents(extAll.minPoint(), extAll.maxPoint());
	refreshView(pGsView);

#ifdef ARX
	//Acad��refreshδ��Ч���ֶ�ˢ����Ļ�����ţ�
	acedVportTableRecords2Vports();
	acedCommand(RTSTR, L"ZOOM", RTSTR, L"e", RTNONE);
#endif

}

ARXCMD3(test_getInteraction)
{
	AcDbObjectId id1, id2;
	CADUtils::SelectEntity(_T("ent1:"), id1);
	CADUtils::SelectEntity(_T("ent2:"), id2);

	AcDbEntity* ent1 = nullptr, *ent2 = nullptr;
	Acad::ErrorStatus es;
	AcGePoint3dArray points;
	es = acdbOpenAcDbEntity(ent1, id1, AcDb::kForRead);
	es = acdbOpenAcDbEntity(ent2, id2, AcDb::kForRead);
	ent1->intersectWith(ent2, AcDb::kOnBothOperands, points);
	acutPrintf(_T("\npoints1 length: %d"), points.length());
	for (int i = 0; i < points.length(); i++)
	{
		acutPrintf(_T("\nptInc[%d]: (%g, %g, %g)"), i, points[i].x, points[i].y, points[i].z);
	}
	ent1->close();
	ent2->close();
}

ARXCMD3(test_AcCmColor)
{
	AcCmColor color;
	Acad::ErrorStatus es = color.setColorIndex(1);
	acutPrintf(_T("\n111"));
}

ARXCMD3(ads_ssgetX)
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	resbuf *rb = acutBuildList(RTDXF0, _T("LINE,ARC"), 8, _T("AXIS"), RTNONE);
	for (int i = 0; i < 100; i++)
	{
		if (RTNORM == ads_ssget(_T("X"), NULL, NULL, rb, selSet))
		{
			acedSSLength(selSet, &len);
			acutPrintf(_T("\n[%d] The selection set has %d object"), i + 1, len);
		}
		acedSSFree(selSet);
	}
	acutRelRb(rb);
}

ARXCMD3(Test_AcDbVisualStyle)
{
	AcDbDictionary* pVisualStyleDic;
	AcDbDatabase *pDb = curDoc()->database();
	Acad::ErrorStatus es = pDb->getVisualStyleDictionary(pVisualStyleDic, AcDb::kForRead);
	//��ȡ�ӿ���ʽ
	AcDbObjectId idVisualStyle;
	es = pVisualStyleDic->getAt(_T("Hidden"), idVisualStyle);
	pVisualStyleDic->close();

	AcDbViewportTable* pVportTable = NULL;
	es = pDb->getViewportTable(pVportTable, AcDb::kForRead);
	AcDbViewportTableRecord* pVportTableRec = NULL;
	es = pVportTable->getAt(ACRX_T("*Active"), pVportTableRec, AcDb::kForWrite);

	es = pVportTableRec->setVisualStyle(idVisualStyle);
	idVisualStyle  = pVportTableRec->visualStyle();

	pVportTableRec->close();
	pVportTable->close();
}

// �ı���Ⱦģʽ
ARXCMD3(Test_rendermode)
{
	Acad::ErrorStatus es;
	AcDbDatabase *pDb = curDoc()->database();

	AcDbViewportTable* pVportTable = NULL;
	es = pDb->getViewportTable(pVportTable, AcDb::kForRead);
	AcDbViewportTableRecord* pVportTableRec = NULL;
	es = pVportTable->getAt(ACRX_T("*Active"), pVportTableRec, AcDb::kForWrite);

#ifdef ZRX
	AcDbAbstractViewTableRecord::RenderMode rMode = pVportTableRec->renderMode();
	switch (rMode)
	{
	case AcDbAbstractViewTableRecord::k2DOptimized:
		acutPrintf(_T("\nmode: k2DOptimized"));
		break;
	case AcDbAbstractViewTableRecord::kWireframe:
		acutPrintf(_T("\nmode: kWireframe"));
		break;
	case AcDbAbstractViewTableRecord::kHiddenLine:
		acutPrintf(_T("\nmode: kHiddenLine"));
		break;
	case AcDbAbstractViewTableRecord::kFlatShaded:
		acutPrintf(_T("\nmode: kFlatShaded"));
		break;
	case AcDbAbstractViewTableRecord::kGouraudShaded:
		acutPrintf(_T("\nmode: kGouraudShaded"));
		break;
	case AcDbAbstractViewTableRecord::kFlatShadedWithWireframe:
		acutPrintf(_T("\nmode: kFlatSkGouraudShadedhaded"));
		break;
	case AcDbAbstractViewTableRecord::kGouraudShadedWithWireframe:
		acutPrintf(_T("\nmode: kGouraudShadedWithWireframe"));
		break;
	default:
		acutPrintf(_T("\nmode: no"));
		break;
	}
	pVportTableRec->setRenderMode(AcDbAbstractViewTableRecord::kGouraudShadedWithWireframe);
#else
	//VisualStyle;
#endif

	pVportTableRec->close();
	pVportTable->close();
}



Acad::ErrorStatus arxZoom(const AcGePoint2d &ptLow, const AcGePoint2d &ptUp)
{
	AcDbViewTableRecord view;
	//InitView(view);
	AcGePoint2d ptCenter(ptLow.x / 2 + ptUp.x / 2, ptLow.y / 2 + ptUp.y / 2);

	view.setCenterPoint(ptCenter);
	view.setHeight(fabs(ptUp.y - ptLow.y));
	view.setWidth(fabs(ptUp.x - ptLow.x));

	Acad::ErrorStatus es = acedSetCurrentView(&view, NULL);
	return es;
}

ARXCMD3(test_arxZoom)
{
	AcDbExtents ext = CADUtils::GetExtentsInModalSpace();
	AcGePoint3d ptMin = ext.minPoint(), ptMax = ext.maxPoint();
	acutPrintf(_T("\nmin(%g,%g) max(%g,%g)"), ptMin.x, ptMin.y, ptMax.x, ptMax.y);
	double dWidth = fabs(ptMax.x - ptMin.x), dHeight = fabs(ptMax.y - ptMin.y);
	double dXSlice = dWidth / 10, dYSlice = dHeight / 10;
	for (int i = 0; i < 10; i += 2)
	{
		for (int j = 0; j < 10; j += 2)
		{
			AcGePoint2d ptLow(ptMin.x + i * dXSlice, ptMin.y + j * dYSlice), ptUp(ptMin.x + dYSlice * (i + 1), ptMin.y + dYSlice * (j + 1));
			arxZoom(ptLow, ptUp);
			// wѡ��
		}
	}
}

ARXCMD3(Test_Xref)
{
	AcDbDatabase *pDb1 = new AcDbDatabase();
	AcDbDatabase *pDb2 = new AcDbDatabase();

	Acad::ErrorStatus es;
	es = pDb1->readDwgFile(_T("C:\\Users\\Admin\\Documents\\1.dwg"));
	acutPrintf(_T("\nes = %s"), acadErrorStatusText(es));
	es = pDb2->readDwgFile(_T("C:\\Users\\Admin\\Documents\\2.dwg"));
	acutPrintf(_T("\nes = %s"), acadErrorStatusText(es));

	AcDbObjectId id1 = NULL, id2 = NULL;
	id1 = pDb1->xrefBlockId();
	id2 = pDb2->xrefBlockId();
	if (!id1)
		acutPrintf(_T("\nid1 null"));
	if (!id2)
		acutPrintf(_T("\nid2 null"));

	AcDbObjectIdArray ids;
	AcDbBlockTablePointer pBlkTable(pDb1, AcDb::kForRead);
	if (Acad::eOk != pBlkTable.openStatus())
	{
		return;
	}
	AcDbBlockTableIterator* pBlkTableIter = NULL;
	if (pBlkTable->newIterator(pBlkTableIter) == Acad::eOk)
	{
		for (; !pBlkTableIter->done(); pBlkTableIter->step())
		{
			AcDbBlockTableRecord* pBTR = NULL;
			if (Acad::eOk != pBlkTableIter->getRecord(pBTR, AcDb::kForRead))
			{
				continue;
			}
			if (pBTR->isFromExternalReference())
			{
				acutPrintf(_T("\ndb1 has xref"));
				ids.append(pBTR->objectId());
				continue;
			}
		}
	}

	AcAxDocLock dolock(pDb1);
	//����eWrongObjectType��
	es = acdbXBindXrefs(pDb1, ids, true);
	acutPrintf(_T("\nes = %s"), acadErrorStatusText(es));
	if (es == Acad::eOk)
	{
		acutPrintf(_T("\nbind success"));
	}

	AcDbBlockTablePointer pBlkTable2(pDb2, AcDb::kForRead);
	if (Acad::eOk != pBlkTable2.openStatus())
	{
		return;
	}
	pBlkTableIter = NULL;
	if (pBlkTable2->newIterator(pBlkTableIter) == Acad::eOk)
	{
		for (; !pBlkTableIter->done(); pBlkTableIter->step())
		{
			AcDbBlockTableRecord* pBTR = NULL;
			if (Acad::eOk != pBlkTableIter->getRecord(pBTR, AcDb::kForRead))
			{
				continue;
			}
			if (pBTR->isFromExternalReference())
			{
				acutPrintf(_T("\ndb2 has xref"));
				break;
			}
		}
	}
	delete pBlkTableIter;
	pBlkTableIter = NULL;
}

#include "acedxref.h"
ARXCMD3(XrefReload)
{
	AcDbObjectIdArray XrefBTRids;
	AcDbDatabase *pDb = curDoc()->database();
	XrefBTRids.removeAll();
	acedXrefReload(_T("ůͨ��ѵͼֽ"), true, pDb);
}

#if ZRX == 2021
#include "zdbobjptr2.h"
ARXCMD3(entOpen)
{
	ads_name ss;
	AcDbObjectId entId;
	AcDbEntity *pEnt;
	ads_point pt;
	acedEntSel(NULL, ss, pt);
	acdbGetObjectId(entId, ss);

	bool b;
	Acad::ErrorStatus es = accessZcDbObjectForRead(pEnt, entId, b);
	acutPrintf(_T("\nes = %s, %s"), acadErrorStatusText(es), pEnt->isA()->name());
}
#endif

//extern void OPMxemark(Segment **);

ARXCMD3(CusSaveAs)
{
	AcDbDatabase *pDb = curDoc()->database();

	//AcDwgFileHandle * pDwgFile = nullptr;
	Acad::ErrorStatus es;
	//es = pDb->saveAs(pDwgFile);
	es = pDb->saveAs(_T("D:\test.dwg"), false, AcDb::AcDbDwgVersion::kDHL_1021, 0/*, false*/);

	CFile f;
	BOOL b = f.Open(L"C:\\test.txt", CFile::modeReadWrite);
	ULONGLONG nLength = f.GetLength();
	BYTE* buffer = new BYTE[nLength];
	f.Read((void*)buffer, (UINT)nLength);
	f.Close();
	CMemFile memFile;
	memFile.Attach(buffer, (UINT)nLength);
}

ARXCMD3(CMemFileTest)
{
	//��һ���ļ������� �ڴ�buffer��
	CFile file;
	file.Open(_T("D:\\test.txt"), CFile::modeReadWrite, NULL);
	ULONGLONG ulLen = file.GetLength();
	BYTE* buffer = (BYTE*)malloc(file.GetLength());
	file.Read(buffer, (UINT)file.GetLength());

	//��buffer�� memfile��������
	CMemFile memfile;
	memfile.Attach(buffer, (UINT)file.GetLength(), 1024);
	memfile.SetLength(file.GetLength());

	//��ͷ200������ �����ĩβ���ظ�100��
	byte tempbuffer[200];
	for (int i = 0; i < 1; i++)
	{
		memfile.Seek(0, CFile::begin);
		memfile.Read(tempbuffer, 5);
		memfile.Seek(0, CFile::end);
		memfile.Write(tempbuffer, 5);
	}
	// testover

	//����ļ�
	UINT size = (UINT)memfile.GetLength();
	//memfile.Detach();
	file.Seek(0, CFile::begin);

	//WORD unicode = 0xFEFF;  
	//file.Write(&unicode, 2);  

	file.Write(buffer, size);
	file.Close();
	free(buffer);
}

ARXCMD3(readDwgTest)
{
	AcDbDatabase *pDb = new AcDbDatabase;
	pDb->readDwgFile(_T("D:\\test.dwg"));
	delete pDb;
}

ARXCMD3(testGetExtents)
{
	AcDbExtents ext = CADUtils::GetExtentsInModalSpace();
	AcGePoint3d ptMin = ext.minPoint(), ptMax = ext.maxPoint();
	acutPrintf(_T("\nmin(%g,%g) max(%g,%g)"), ptMin.x, ptMin.y, ptMax.x, ptMax.y);
}

ARXCMD3(test_insertDwgWithXref)
{
	resbuf* rb = acutNewRb(RTSTR);
	if (RTNORM != acedGetFileNavDialog(_T("ѡ��DWG�ļ�"), NULL, _T("dwg"), NULL, 0, &rb))
		return;
	ACHAR result[MAX_PATH];
	if (RTNORM != acedFindFile(rb->resval.rstring, result))
		return;
	acutRelRb(rb);

	AcDbDatabase *pDb = new AcDbDatabase(Adesk::kFalse);
	Acad::ErrorStatus es = pDb->readDwgFile(result);
	acutPrintf(_T("\nes = %s"), acadErrorStatusText(es));

	AcGeMatrix3d matrix;
	Acad::ErrorStatus es1 = acdbCurDwg()->insert(matrix, pDb);
	acutPrintf(_T("\nes1 = %s"), acadErrorStatusText(es1));
	//acedXrefReload(_T("Drawing1"), true, curDoc()->database());
	delete pDb;

	//AcDbObjectIdArray ids;
	//AcDbBlockTable* pBlkTab = NULL;
	//Acad::ErrorStatus esGet = acdbCurDwg()->getBlockTable(pBlkTab, AcDb::kForRead);
	//if (esGet != Acad::eOk || pBlkTab == NULL)
	//{
	//	return;
	//}
	//pBlkTab->close();
	//AcDbBlockTableIterator* pBlkTabIter = NULL;
	//esGet = pBlkTab->newIterator(pBlkTabIter);
	//if (esGet != Acad::eOk || pBlkTabIter == NULL)
	//{
	//	return;
	//}
	//for (pBlkTabIter->start(); !pBlkTabIter->done(); pBlkTabIter->step())
	//{
	//	AcDbBlockTableRecord* pBlkTabRcd = NULL;
	//	esGet = pBlkTabIter->getRecord(pBlkTabRcd, AcDb::kForRead);
	//	if (esGet != Acad::eOk || pBlkTabRcd == NULL)
	//	{
	//		continue;
	//	}
	//	// ����Ƿ����ⲿ���յĿ���¼
	//	if (!pBlkTabRcd->isFromExternalReference())
	//	{
	//		pBlkTabRcd->close();
	//		continue;
	//	}
	//	ids.append(pBlkTabRcd->objectId());
	//	pBlkTabRcd->close();
	//}
	//delete pBlkTabIter;
	//pBlkTabIter = NULL;

	// test name
	//acedXrefReload(_T("Drawing1"), true, curDoc()->database());
	// test ids
	//acedXrefReload(ids);
}

ARXCMD3(delExtensionDicOfLineType)
{
	Acad::ErrorStatus es;
	AcDbDatabase *pDadabase = acdbHostApplicationServices()->workingDatabase();
	AcDbLinetypeTable* pLineTypeTable = NULL;
	if (Acad::eOk != pDadabase->getLinetypeTable(pLineTypeTable, AcDb::kForWrite))
		return;

	AcDbLinetypeTableRecord *pLineTypeRec = nullptr;
	if (Acad::eOk == pLineTypeTable->getAt(_T("EXT-P771 -PH 9-FP01-30%$0${ Offset Lines }"), pLineTypeRec, AcDb::kForWrite))
	{
		AcDbObjectId dictObjId = pLineTypeRec->extensionDictionary();
		pLineTypeRec->close();
		if (dictObjId == NULL)
		{
			acutPrintf(_T("\n��ʵ�岻������չ�ʵ�"));
			return;
		}

		AcDbDictionary* pDict = nullptr;
		acdbOpenObject(pDict, dictObjId, AcDb::kForWrite);
		if (pDict)
		{
			if (pDict->has(_T("DGNLSDEF")))
			{
				pDict->remove(_T("DGNLSDEF"));
				acutPrintf(_T("\n��ɾ����չ�ʵ�DGNLSDEF"));
			}
			else
			{
				acutPrintf(_T("\n��������չ�ʵ�DGNLSDEF"));
			}
		}
		pDict->close();
		pLineTypeTable->close();
	}
}

ARXCMD3(CusFilter)
{
	Adesk::Int32 len = 0;
	ads_name selSet;
	resbuf *rb = acutBuildList(RTDXF0, _T("LINE,ARC"), 8, _T("ͼ��1"), 62, 1, -3, 1001, _T("XData"), -3, 1000, _T("ASCII"), RTNONE);

	if (RTNORM == ads_ssget(_T("A"), NULL, NULL, rb, selSet))
	{
		acedSSLength(selSet, &len);
		acutPrintf(_T("\nLen: %d"), len);
	}
	acedSSFree(selSet);
	acutRelRb(rb);
}

ARXCMD3(transformTest)
{
	resbuf* rb = acutNewRb(RTSTR);

	if (RTNORM != acedGetFileNavDialog(_T("ѡ��DWG�ļ�"), NULL, _T("dwg"), NULL, 0, &rb))
		//if (RTNORM != acedGetFileD(_T("ѡ��DWG�ļ�"), NULL, _T("dwg"), 0, rb))
	{
		return;
	}
	ACHAR result[MAX_PATH];
	AcDbDatabase* pDb = new AcDbDatabase(Adesk::kFalse, Adesk::kTrue);
	if (RTNORM == acedFindFile(rb->resval.rstring, result))
	{
		pDb->readDwgFile(result);
	}

	AcGePoint3d ptCurDbMin = curDoc()->database()->extmin();
	AcGePoint3d ptCurDbMax = curDoc()->database()->extmax();

	AcGePoint3d ptOrigin(AcGePoint3d::kOrigin);
	//if (iWBlockCount != 0)
	//{
	//	double dXMove = 9999;
	//	ptOrigin = AcGePoint3d(acdbCurDwg()->extmax().x + dXMove, acdbCurDwg()->extmin().y, 0.0);
	//}

	AcGePoint3d ptExtMin = pDb->extmin();
	AcGeVector3d vecMove = ptOrigin - ptExtMin;

	AcGeMatrix3d xform;
	xform.setToTranslation(vecMove);

	AcAxDocLock DbLock(pDb);
	AcDbBlockTable *pBlkTbl = NULL;
	Acad::ErrorStatus esGet = pDb->getBlockTable(pBlkTbl, AcDb::kForRead);
	if (esGet != Acad::eOk)
	{
		return;
	}
	pBlkTbl->close();

	AcDbBlockTableRecord *pBlkTblRcd = NULL;
	esGet = pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRcd, AcDb::kForRead);
	if (esGet != Acad::eOk)
	{
		return;
	}

	//����ģ�Ϳռ��ʵ��
	AcDbBlockTableRecordIterator *it(NULL);
	pBlkTblRcd->newIterator(it);
	for (it->start(); !it->done(); it->step())
	{
		AcDbEntity *pEntity = NULL;
		if (it->getEntity(pEntity, AcDb::kForWrite) != Acad::eOk)
		{
			continue;
		}

		pEntity->transformBy(xform);
		pEntity->close();
	}

	delete it;
	pBlkTblRcd->close();

	delete pDb;
	acutRelRb(rb);
}

#include "geplin2d.h"
/*
	���� ptOutΪext��һ��,
	����: ptSide�������(0,0,0)
*/
ARXCMD3(GePLine2dClosestPointTo)
{
	AcGePoint2d ptOut(50, 150);
	AcDbExtents ext(AcGePoint3d(0, 0, 0), AcGePoint3d(100, 100, 0));
	AcGePoint2dArray ptArry;
	ptArry.append(AcGePoint2d(ext.minPoint().x, ext.minPoint().y));
	ptArry.append(AcGePoint2d(ext.maxPoint().x, ext.minPoint().y));
	ptArry.append(AcGePoint2d(ext.maxPoint().x, ext.maxPoint().y));
	ptArry.append(AcGePoint2d(ext.minPoint().x, ext.maxPoint().y));
	ptArry.append(AcGePoint2d(ext.minPoint().x, ext.minPoint().y));

	AcGePolyline2d pl(ptArry);
	AcGePoint2d ptSide = pl.closestPointTo(ptOut);
	acutPrintf(_T("\nptSide(%g, %g)"), ptSide.x, ptSide.y);
}

ARXCMD3(Arc3dDistanceTo)
{
	AcGeCircArc3d circArc1(AcGePoint3d(190.81547751101971, 407.06703093969554, 0.00000000000000000), AcGeVector3d::kZAxis, 43512.922060250123);
	AcGeCircArc3d circArc2(AcGePoint3d(190.81507521302410, 407.06710967360141, 0.00000000000000000), AcGeVector3d::kZAxis, 43512.921650317447);
	double dis = circArc1.distanceTo(circArc2);
	acutPrintf(_T("dis = %g"), dis);
}

#include "AcPlPlotEngine.h"
#include "dbplotsettings.h"
#include "dbplotsetval.h"
#include "AcPlPlotFactory.h"
#include "dblayout.h"
#include "AcPlPlotInfo.h"
#include "AcDbLMgr.h"
#include "AcPlPlotInfoValidator.h"
void Test_plot()
{
	AcPlPlotEngine* PlotEngine = NULL;
	AcDbPlotSettingsValidator* PlotSettingsValidator = NULL;
	Acad::ErrorStatus es = Acad::eOk;
	AcDbObjectId ObjectId = AcDbObjectId::kNull;
	//������ӡ����
	es = AcPlPlotFactory::createPublishEngine(PlotEngine);
	if (es == Acad::eOk)
	{
		//��ȡ��ǰ���Layout�ʹ�ӡ����
		AcPlPlotPageInfo PlotPageInfo;
		AcPlPlotInfo PlotInfo;
		AcDbLayout* Layout = NULL;
		AcDbPlotSettings* PlotSettings = NULL;
		AcDbLayoutManager* LayoutManager = acdbHostApplicationServices()->layoutManager();
		AcDbObjectId ObjectId = LayoutManager->getActiveLayoutBTRId();
		AcDbBlockTableRecord* BlockTableRecord;
		es = acdbOpenObject(BlockTableRecord, ObjectId, AcDb::kForRead);
		ObjectId = BlockTableRecord->getLayoutId();
		es = acdbOpenObject(Layout, ObjectId, AcDb::kForWrite);
		PlotSettings = new AcDbPlotSettings(Layout->modelType());
		PlotSettings->copyFrom(Layout);
		Layout->close();
		BlockTableRecord->close();
		//��ȡ��ӡ����֤������
		PlotSettingsValidator = (AcDbPlotSettingsValidator*)acdbHostApplicationServices()->plotSettingsValidator();
		//���ô�ӡ��(�����ӡ��Ϊzwcad���ŵĸ�DPI�Ĵ�ӡ��)
		PlotSettingsValidator->setPlotCfgName(PlotSettings, _T("ZWCAD PDF(High Quality Print).pc5"));
		PlotSettingsValidator->refreshLists(PlotSettings);
		//����ֽ��
		es = PlotSettingsValidator->setCanonicalMediaName(PlotSettings, _T("ISO_A4(210.00_x_297.00_MM)"));
		//���ô�ӡ����Ϊ��׼����
		es = PlotSettingsValidator->setUseStandardScale(PlotSettings, Adesk::kTrue);
		es = PlotSettingsValidator->setStdScaleType(PlotSettings, AcDbPlotSettings::kScaleToFit);
		//��ӡ����Ϊ����ʾ��Χ(��ǰ��Ļ��ʾ��Χ)
		PlotSettingsValidator->setPlotType(PlotSettings, AcDbPlotSettings::kDisplay);
		//���д�ӡ
		PlotSettingsValidator->setPlotCentered(PlotSettings, true);
		//ȡ����ӡ�߿�����ͼֽ����ľ������⣬��ӡ�߿�ᵼ�¾����ϵ���ʧ���Ե�ʮ��ģ����
		PlotSettings->setPrintLineweights(false);
		//��ʼ��ӡ
		PlotInfo.setLayout(ObjectId);
		PlotInfo.setOverrideSettings(PlotSettings);
		AcPlPlotInfoValidator validator;
		validator.setMediaMatchingPolicy(AcPlPlotInfoValidator::kMatchEnabled);
		es = validator.validate(PlotInfo);
		if (es == Acad::eOk)
		{
			const ACHAR* filename = acDocManager->curDocument()->fileName();
			PlotEngine->beginPlot(NULL);
			PlotEngine->beginDocument(PlotInfo, filename, NULL, 1, true, _T("D:\\Drawing1.pdf"));
			PlotEngine->beginPage(PlotPageInfo, PlotInfo, true);
			PlotEngine->beginGenerateGraphics();
			PlotEngine->endGenerateGraphics();
			PlotEngine->endPage();
			PlotEngine->endDocument();
			PlotEngine->endPlot();
		}
		PlotEngine->destroy();
		PlotEngine = NULL;

	}
	else
		acutPrintf(_T("fail"));

}
ARXCMD3(createProcessTest)
{
	// ������Ϣ�ṹ
	PROCESS_INFORMATION ProInfo;    

	STARTUPINFO    StartInfo;
	ZeroMemory(&StartInfo, sizeof(StartInfo));

	// �������������
	//LPTSTR   szPrameter = TEXT("\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\" www.baidu.com");
	LPTSTR   szPrameter = TEXT("\"C:\\Program Files\\ZWSOFT\\ZWCAD 2020\\zwcad.exe\" /p default /nologo");
	TCHAR szCmdLine[2048] = { 0 };
	CopyMemory(szCmdLine, szPrameter, 2 * _tcslen(szPrameter));

	ZeroMemory(&ProInfo, sizeof(ProInfo));

	if (!CreateProcess(
		NULL,                    // ִ�еĳ�����
		szCmdLine,               // ������ָ��
		NULL,                    // ���̰�ȫ����, NULLʱʹ��Ĭ�ϰ�ȫ����
		NULL,                    // �̰߳�ȫ����, NULLʱʹ��Ĭ�ϰ�ȫ����
		FALSE,                   // ���̳о��
		0,                       // ���̴�����־
		NULL,                    // ����������, NULLʱʹ�ø����̻�������
		NULL,                    // �½���Ŀ¼
		&StartInfo,              // ������Ϣ�ṹ
		&ProInfo)                // ������Ϣ�ṹ
		) 
	{
		acutPrintf(TEXT("CreateProcess failed : %d\n"), GetLastError());
		return ;
	}

	// �ȴ��ӽ��̽���
	WaitForSingleObject(ProInfo.hProcess, INFINITE);

	CloseHandle(ProInfo.hProcess);
	CloseHandle(ProInfo.hThread);
}