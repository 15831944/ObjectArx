// tools.cpp
#include "stdafx.h"

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