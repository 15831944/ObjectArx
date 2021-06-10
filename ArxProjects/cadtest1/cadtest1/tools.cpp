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
