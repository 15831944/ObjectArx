//
#include "pch.h"
#include "CustEntities.h"
#include "rxboiler.h"
#include "dbproxy.h"
#include "dbapserv.h"
#include "acestext.h"
#include "tchar.h"

ACRX_DXF_DEFINE_MEMBERS(CusEntityByBlkRef, AcDbEntity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kTransformAllowed |
	AcDbProxyEntity::kColorChangeAllowed |
	AcDbProxyEntity::kLayerChangeAllowed,
	CusEntityByBlkRef, CUSTENT
);
CusEntityByBlkRef::CusEntityByBlkRef() {}
CusEntityByBlkRef::CusEntityByBlkRef(AcDbObjectId id)
	:m_blockId(id)
{
	//AcDbDatabase *pDb = new AcDbDatabase(/*false, true*/);
	//AcDbBlockTable* pBT = NULL;
	////acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBT, AcDb::kForWrite);
	//Acad::ErrorStatus es;
	//TCHAR* szBlockPath = _T("D:\\DDDD\\SysComponentLib_9.dwg");
	//es = pDb->readDwgFile(szBlockPath);
	//acutPrintf(_T("\nes = %s"), acadErrorStatusText(es));
	//pDb->getBlockTable(pBT, AcDb::kForWrite);

	//pBT->getAt(_T("3$3$1$3@0"), m_blockId);
	//pBT->close();
}
Adesk::Boolean CusEntityByBlkRef::subWorldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();    // Its purpose is to make sure that the object is open AcDb::kForRead.

	AcDbLine* pLine = new AcDbLine(AcGePoint3d(0, 0, 0), AcGePoint3d(1000, 1000, 0));
	pLine->worldDraw(wd);

	AcDbBlockReference* pBlkRef = new AcDbBlockReference;
	pBlkRef->setBlockTableRecord(m_blockId);
	pBlkRef->setLayer(this->layer());
	pBlkRef->worldDraw(wd);

	//pBlkRef->close();

	return Adesk::kTrue;
}