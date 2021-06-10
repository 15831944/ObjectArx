#pragma once

#include "pch.h"
#include "dbents.h"
#include "gepent3d.h"
#include <vector>

#if ZRX == 20
#define subWorldDraw worldDraw
#define subViewportDraw viewportDraw
#define subList list
#define subGetSubentPathsAtGsMarker getSubentPathsAtGsMarker
#define subGetGripPoints getGripPoints
#define subMoveGripPointsAt moveGripPointsAt
#define subGetOsnapPoints getOsnapPoints
#endif

class CusEntityByBlkRef :public AcDbEntity
{
public:
	CusEntityByBlkRef();
	CusEntityByBlkRef(AcDbObjectId id);
	ACRX_DECLARE_MEMBERS(CusEntityByBlkRef);       //declare desc(),cast(),isA()
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
private:
	AcDbObjectId m_blockId;
};