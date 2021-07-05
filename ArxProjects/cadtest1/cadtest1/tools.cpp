// tools.cpp
#include "stdafx.h"

/**
* @brief 解锁所有图层
*/
ARXCMD3(unlockAllLayer)
{
	AcDbDatabase *pDb = curDoc()->database();
	AcDbLayerTable *pLyrTable;
	AcDbObjectId recId;

	if (Acad::eOk != pDb->getLayerTable(pLyrTable, AcDb::kForRead))
	{
		return;
	}

	AcDbLayerTableIterator * pIterator = NULL;
	pLyrTable->newIterator(pIterator);
	for (; !pIterator->done(); pIterator->step())
	{
		AcDbLayerTableRecord * pRecord = NULL;
		if (Acad::eOk == pIterator->getRecord(pRecord, AcDb::kForRead))
		{
			if (pRecord->isLocked() == true)  
			{
				pRecord->upgradeOpen();
				pRecord->setIsLocked(false);
			}
			pRecord->close();
		}
	}

	delete pIterator;
	pIterator = NULL;

	pLyrTable->close();
}

/**
* @brief 读取注册表获取cad程序版本
*/
CString GetCurrentAccessVersion()
{
	HKEY hKey = 0;
	// Open the "ACCESS CURRENT APPLICATION VERSION KEY"
	// AutoCAD.Application.23 ZWCAD.Application.2021
	if (ERROR_SUCCESS != ::RegOpenKeyEx(HKEY_CLASSES_ROOT, _T("AutoCAD.Application\\CurVer"), 0, KEY_QUERY_VALUE, &hKey))
		return _T("");
	// Read the default value
	DWORD dwType = 0;
	DWORD dwSize = 256;
	BYTE buffer[256];
	VERIFY(ERROR_SUCCESS == ::RegQueryValueEx(hKey, 0, 0, &dwType, buffer, &dwSize));
	// It should be a string
	ASSERT(REG_SZ == dwType);
	// Close the key
	::RegCloseKey(hKey);
	// Return string value of Access current application version
	return CString((TCHAR*)buffer);
}

/**
* 获取实体的包围盒
*/
ARXCMD3(getGeoExtentsOfThisEntity)
{
	ads_name sname;
	ads_point ptRes;
	if (RTNORM == acedEntSel(_T("选择对象："), sname, ptRes))
	{
		AcDbObjectId id;
		acdbGetObjectId(id, sname);

		AcDbEntity *pEnt = nullptr;
		if (Acad::eOk == acdbOpenAcDbEntity(pEnt, id, AcDb::kForRead))
		{
			AcDbExtents ext;
			pEnt->getGeomExtents(ext);
			acutPrintf(_T("\next.minPoint(%g, %g, %g) ext.maxPoint(%g, %g, %g)"),
				ext.minPoint().x, ext.minPoint().y, ext.minPoint().z, ext.maxPoint().x, ext.maxPoint().y, ext.maxPoint().z);

			pEnt->close();
		}
	}
}

/**
* 获取两个实体的交点
*/
ARXCMD3(getIntersectionOfTwoEntities)
{
	AcDbObjectId id1, id2;
	if (RTNORM == CADUtils::SelectEntity(_T("Select entity 1:\n"), id1) && RTNORM == CADUtils::SelectEntity(_T("Select entity 2:\n"), id2))
	{
		AcDbEntity* ent1 = nullptr, *ent2 = nullptr;
		Acad::ErrorStatus es;
		AcGePoint3dArray points;
		es = acdbOpenAcDbEntity(ent1, id1, AcDb::kForRead);
		es = acdbOpenAcDbEntity(ent2, id2, AcDb::kForRead);
		ent1->intersectWith(ent2, AcDb::kOnBothOperands, points);
		acutPrintf(_T("\npoints length: %d"), points.length());
		for (int i = 0; i < points.length(); i++)
		{
			acutPrintf(_T("\nptInsec[%d]: (%g, %g, %g)"), i, points[i].x, points[i].y, points[i].z);
		}
		ent1->close();
		ent2->close();
	}
}