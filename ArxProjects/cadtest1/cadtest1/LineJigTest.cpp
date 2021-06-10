//
#include "stdafx.h"
#include"PmDbLinetmpJig.h"
#include "acedads.h"
#include "adscodes.h"

void AsObjectIdArray(const ads_name ss, AcDbObjectIdArray& objids)
{
	Adesk::Int32 len = 0;
	if(acedSSLength(ss, &len) != RTNORM)
		return;

	int ret;
	AcDbObjectId objId;
	ads_name ent;

	for (long i = 0; i<len; ++i) 
	{
		ret = acedSSName(ss, i, ent);
		if ( RTNORM != ret )
			continue;

		if (acdbGetObjectId(objId, ent) == Acad::eOk)
			objids.append(objId);
	}
}


ARXCMD3(TestJig)
{
	ads_name adssetSingle;
	int result = acedSSGet( NULL , NULL, NULL, NULL, adssetSingle);
	if (result != RTNORM)
		return;

	AcDbObjectIdArray idArrSel;
	AsObjectIdArray(adssetSingle, idArrSel);
	acedSSFree(adssetSingle);

	if (idArrSel.length() < 1)
	{
		return;
	}
	AcDbObjectId idSel = idArrSel.first();


	CPmDbLinetmpJig jigTest;
	jigTest.doIt(idSel);
}
