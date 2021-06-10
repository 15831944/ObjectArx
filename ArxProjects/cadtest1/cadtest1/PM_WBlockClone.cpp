// PM_WBlockClone.cpp
#include "stdafx.h"
#include <vector>

#include "dbfilter.h"
#include "dbspfilt.h"
#include "dbindex.h"
#include "dbidmap.h"

#if 0
void MoveEntInModelSpace(AcDbDatabase* pWorkDb, const AcGeMatrix3d& transForm)
{
	if (pWorkDb == NULL)
	{
		return;
	}

	AcAxDocLock DbLock(pWorkDb);
	AcDbBlockTable *pBlkTbl = NULL;
	Acad::ErrorStatus esGet = pWorkDb->getBlockTable(pBlkTbl, AcDb::kForRead);
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

	//遍历模型空间的实体
	AcDbBlockTableRecordIterator *it(NULL);
	pBlkTblRcd->newIterator(it);
	for (it->start(); !it->done(); it->step())
	{
		AcDbEntity *pEntity = NULL;
		esGet = it->getEntity(pEntity, AcDb::kForWrite);
		if (esGet != Acad::eOk)
		{
			continue;
		}

		esGet = pEntity->transformBy(transForm);
		pEntity->close();
	}

	delete it;
	it = nullptr;
	pBlkTblRcd->close();
}

void getMsEnts(AcDbDatabase* pDb, AcDbObjectIdArray& ids)
{
	AcDbBlockTable* pTbl = NULL;
	pDb->getBlockTable(pTbl, AcDb::kForRead);
	if (pTbl)
	{
		AcDbBlockTableRecord* pBtr = NULL;
		pTbl->getAt(ACDB_MODEL_SPACE, pBtr, AcDb::kForRead);
		if (pBtr)
		{
			AcDbBlockTableRecordIterator* pItr = NULL;
			pBtr->newIterator(pItr);
			if (pItr)
			{
				for (pItr->start(); !pItr->done(); pItr->step())
				{
					AcDbObjectId id;
					if (Acad::eOk == pItr->getEntityId(id))
					{
						ids.append(id);
					}
				}
				delete pItr;
				pItr = NULL;
			}
			pBtr->close();
		}
		pTbl->close();
	}
}

bool IsBlkHasAttrib(AcDbBlockReference* blkPtr)
{
	bool bRet = false;
	AcDbObjectIterator * pIter = NULL;
	pIter = blkPtr->attributeIterator();
	if (pIter == NULL)
	{
		return bRet;
	}

	AcDbAttribute* pCurAttr;
	AcDbObjectId uId;
	AcDbEntity* pIterEnt;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		uId = pIter->objectId();
		//if (!ISACADOK(acdbOpenAcDbEntity(pIterEnt, uId, AcDb::kForRead)))
		if (Acad::eOk != acdbOpenAcDbEntity(pIterEnt, uId, AcDb::kForRead))
		{
			continue;
		}

		pCurAttr = AcDbAttribute::cast(pIterEnt);
		if (pCurAttr == NULL)
		{
			pIterEnt->close();
			continue;
		}

		if (pCurAttr->isInvisible() == Adesk::kTrue)
		{
			pIterEnt->close();
			continue;
		}

		TCHAR* pTextstr = pCurAttr->textString();

		if (_tcslen(pTextstr) > 0)
		{
			bRet = true;
			break;
		}

		pIterEnt->close();
	}
	delete pIter;

	return bRet;
}

void GetBlkIdArr(AcDbDatabase* pWorkDb, AcDbObjectIdArray& idArr)
{
	if (pWorkDb == NULL)
	{
		return;
	}

	AcDbBlockTable *pBlkTbl = NULL;
	Acad::ErrorStatus esGet = pWorkDb->getBlockTable(pBlkTbl, AcDb::kForRead);
	if (esGet != Acad::eOk)
	{
		return;
	}
	pBlkTbl->close();

	AcDbBlockTableRecord *pBlkTblRcd = NULL;
	esGet = pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRcd, AcDb::kForRead);
	if (esGet != Acad::eOk || pBlkTblRcd == NULL)
	{
		return;
	}

	//遍历模型空间的实体
	AcDbBlockTableRecordIterator *it(NULL);
	esGet = pBlkTblRcd->newIterator(it);
	if (esGet != Acad::eOk || it == NULL)
	{
		return;
	}

	for (it->start(); !it->done(); it->step())
	{
		AcDbEntity *pEntity = NULL;
		if (it->getEntity(pEntity, AcDb::kForRead) != Acad::eOk)
		{
			continue;
		}
		pEntity->close();

		if (!pEntity->isKindOf(AcDbBlockReference::desc()))
		{
			continue;
		}

		idArr.append(pEntity->objectId());
	}

	delete it;
	it = NULL;
	pBlkTblRcd->close();
}

void OpenBlkEntForRead(std::vector<AcDbBlockReference*>& ptrArr, const AcDbObjectIdArray& ids)
{
	AcDbEntity *pEnt;
	for (int i = 0; i < ids.length(); i++)
	{
		if (!ids[i].isValid())
		{
			continue;
		}

		if (acdbOpenAcDbEntity(pEnt, ids[i], AcDb::kForRead) != Acad::eOk)
		{
			continue;
		}

		AcDbBlockReference* pBlkEnt = AcDbBlockReference::cast(pEnt);
		if (pBlkEnt == NULL)
		{
			continue;
		}

		ptrArr.push_back(pBlkEnt);
	}
}
void CloseMyEntsPtr(std::vector<AcDbBlockReference*>& ptrArr)
{
	for (int i = 0; i < ptrArr.size(); i++)
	{
		ptrArr[i]->close();
	}
}

AcDbBlockTableRecord* openCurrentSpaceBlock(AcDb::OpenMode mode, AcDbDatabase* db)
{
	ASSERT(db != NULL);

	AcDbBlockTableRecord* blkRec;

	Acad::ErrorStatus es = acdbOpenObject(blkRec, db->currentSpaceId(), mode);
	if (es != Acad::eOk)
		return NULL;
	else
		return blkRec;
}

Acad::ErrorStatus addToCurrentSpace(AcDbEntity* newEnt, AcDbDatabase* db, AcDbObjectId &retId)
{
	ASSERT(newEnt != NULL);
	ASSERT(db != NULL);

	AcDbBlockTableRecord* blkRec = openCurrentSpaceBlock(AcDb::kForWrite, db);

	ASSERT(blkRec != NULL);

	if (blkRec == NULL)
		return Acad::eInvalidInput;

	// append new entity to current space block
	Acad::ErrorStatus es = blkRec->appendAcDbEntity(retId, newEnt);
	if (es != Acad::eOk)
	{
		//PmAcutPrintfErrMsg(_T("\nERROR: could not add entity to current space "), ArxDbgUtils::rxErrorStr(es));
	}

	blkRec->close();
	return es;
}

BOOL AddToDb(AcDbEntity * pEntity, AcDbObjectId& id)
{
	try
	{
		BOOL function_return = FALSE;
		//parameter	
		if (pEntity == NULL)
		{
			return FALSE;
		}
		//end parameter
		AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
		if (pDb == NULL) {
			acedAlert(_T("No database!"));
			return Adesk::kFalse;
		}
		Acad::ErrorStatus es = addToCurrentSpace(pEntity, pDb, id);
		if (es == Acad::eOk)
		{
			pEntity->close();
			pEntity = NULL;

			function_return = TRUE;
		}
		else
		{
			//delete pEntity;
			///PMDelete(pEntity);
			///pEntity = NULL;
			pEntity->close();
		}
		return function_return;
	}
	catch (...)
	{
		return FALSE;
	}
}

BOOL SaveDb(AcDbDatabase * pToDataBase)
{
	if (NULL == pToDataBase)
		return FALSE;

	//
	AcAxDocLock lock(pToDataBase);
	CString strToDwgFilePath = pToDataBase->originalFileName();  //获取到模板名保存为模板

	//
	if (Acad::eOk == pToDataBase->saveAs(strToDwgFilePath))
	{
		CString	strTemMsgInfo = _T("保存图纸: ") + strToDwgFilePath;
		////PMERROR::PrintInfo(strTemMsgInfo, 1002);
		acutPrintf(strTemMsgInfo);
		return TRUE;
	}

	//
	return FALSE;
}

void ExplodeNoAttributeBlock(AcDbDatabase* pWorkDb)
{
	AcDbBlockTable* pTable;
	if (pWorkDb->getBlockTable(pTable, AcDb::kForRead) != Acad::eOk)
	{
		return;
	}

	AcDbBlockTableIterator* pIterator = NULL;
	pTable->newIterator(pIterator);
	pTable->close();

	AcDbObjectIdArray hasAttribIds;

	AcDbBlockTableRecord* pRecord;
	for (; !pIterator->done(); pIterator->step())
	{
		if (pIterator->getRecord(pRecord, AcDb::kForRead) != Acad::eOk)
		{
			continue;
		}

		if (pRecord->hasAttributeDefinitions())
		{
			hasAttribIds.append(pRecord->id());
		}

		pRecord->close();
	}
	delete pIterator;

	AcDbObjectIdArray blkIds;
	GetBlkIdArr(pWorkDb, blkIds);

	std::vector<AcDbBlockReference*> blkPtrs;
	OpenBlkEntForRead(blkPtrs, blkIds);

	AcDbObjectId id;
	AcDbEntity* pEnt;

	AcDbExtents exts;

	static double s_dMinLen = 2500.0;
	for (int i = 0; i < blkPtrs.size(); i++)
	{
		if (blkPtrs[i]->visibility() == AcDb::kInvisible)
		{
			continue;
		}

		AcDbFilter* pFilter = NULL;
		Acad::ErrorStatus esGet = AcDbIndexFilterManager::getFilter(blkPtrs.at(i), AcDbSpatialFilter::desc(), AcDb::kForRead, pFilter);
		if (esGet == Acad::eOk && pFilter != NULL)
		{
			///此块被裁剪，若炸开会得到很多裁剪边框之外的实体
			pFilter->close();
			continue;
		}

		if (hasAttribIds.contains(blkPtrs[i]->blockTableRecord()))
		{
			continue;
		}

		////if (ISACADOK(blkPtrs[i]->getGeomExtents(exts)))
		if (Acad::eOk == blkPtrs[i]->getGeomExtents(exts))

		{
			if (((exts.maxPoint().x - exts.minPoint().x) < s_dMinLen)
				&& ((exts.maxPoint().y - exts.minPoint().y) < s_dMinLen))
			{
				continue;
			}
		}

		if (IsBlkHasAttrib(blkPtrs[i]))
		{
			continue;
		}

		///和下面的炸开效果相同，也会报错
		//AcDbBlockReference* pCurBlk = blkPtrs.at(i);
		//AcGePoint3d ptPos = pCurBlk->position();
		//AcDbExtents extCurBlk;
		//pCurBlk->getGeomExtents(extCurBlk);
		//Acad::ErrorStatus esExplode = pCurBlk->explodeToOwnerSpace();
		//if (esExplode == Acad::eOk)
		//{
		//	int iTest = 0;
		//	++iTest;
		//}

		AcDbVoidPtrArray subs;
		bool bExploeSuccess = false;
		Acad::ErrorStatus esExplode = blkPtrs[i]->explode(subs);
		////if (ISACADOK(esExplode))
		if (Acad::eOk == esExplode)
		{
			bExploeSuccess = true;
			for (int j = 0; j < subs.length(); j++)
			{
				pEnt = (AcDbEntity*)subs[j];

				if (!AddToDb(pEnt, id))
				{
					acutPrintf(_T("AddToDb Not Successfully.\n"));
				}
				pEnt->close();
			}
		}

		if (bExploeSuccess && /*ISACADOK*/Acad::eOk == (blkPtrs[i]->upgradeOpen()))
		{
			blkPtrs[i]->erase();
		}
	}

	CloseMyEntsPtr(blkPtrs);
}

ARXCMD3(Wblock_ExplodeBlk)
{
	Acad::ErrorStatus es = Acad::eOk;
	static int iWBlockCount = 0;
	AcDbBlockTable* pTbl = NULL;
	curDoc()->database()->getBlockTable(pTbl, AcDb::kForRead);
	if (pTbl)
	{
		AcDbObjectId msId;
		pTbl->getAt(ACDB_MODEL_SPACE, msId);
		pTbl->close();

		resbuf* rb = acutNewRb(RTSTR);
		if (RTNORM != acedGetFileD(_T("选择DWG文件"), NULL, _T("dwg"), 0, rb))
		{
			return;
		}
		ACHAR result[MAX_PATH];
		if (RTNORM == acedFindFile(rb->resval.rstring, result))
		{
			AcDbDatabase* pDb = new AcDbDatabase(Adesk::kFalse, Adesk::kTrue);
			es = pDb->readDwgFile(result);
			AcDbObjectIdArray ids;

			//AcGePoint3d ptCurDbMin = curDoc()->database()->extmin();
			//AcGePoint3d ptCurDbMax = curDoc()->database()->extmax();

			AcGePoint3d ptOrigin(AcGePoint3d::kOrigin);
			//if (iWBlockCount != 0)
			//{
			//	double dXMove = 9999;
			//	ptOrigin = AcGePoint3d(acdbCurDwg()->extmax().x + dXMove, acdbCurDwg()->extmin().y, 0.0);
			//}

			AcGePoint3d ptExtMin = pDb->extmin();
			AcGeVector3d vecMove = ptOrigin - ptExtMin;

			AcGeMatrix3d xform(AcGeVector3d::kIdentity);
			xform.setToTranslation(vecMove);
			MoveEntInModelSpace(pDb, xform);

			getMsEnts(pDb, ids);

			AcDbIdMapping idMap;

			/** SUP-30957 附件图纸调用wblockcloneobjects后saveas保存失败
				TDbWall经过wblockclone后载调用saveAs接口会触发对象反应器，objectModified中有获取天正自定义对象全局数据，
				但是这个全局数据不确定是否在wblockclone后是否都转换成本地数据库数据，当删除临时数据库后造成全局数据中存在野数据。这是个内存问题不是很容易定位。
				两种解决方案：
				1.将wblockCloneObjects中的克隆策略由kDrcReplace->kDrcIgnore
				2.wblockCloneObjects和saveAs不在同一个命令里调用
			*/

			Acad::ErrorStatus es = curDoc()->database()->wblockCloneObjects(ids, msId, idMap, AcDb::kDrcIgnore, FALSE);
			//Acad::ErrorStatus es = curDoc()->database()->wblockCloneObjects(ids, msId, idMap, AcDb::kDrcReplace);
			if (es == Acad::eOk)
			{
				acutPrintf(_T("\n%d entities are imported."), ids.length());
				++iWBlockCount;
			}
			else
			{
				acutPrintf(_T("\nError: %s"), acadErrorStatusText(es));
			}

			delete pDb;
			pDb = NULL;
		}
		acutRelRb(rb);
	}

	//SaveDb(curDoc()->database());
	es = acDocManager->sendStringToExecute(curDoc(), _T("zoom e "));

#if 0
	ExplodeNoAttributeBlock(curDoc()->database());
#endif

	return;
}
#endif