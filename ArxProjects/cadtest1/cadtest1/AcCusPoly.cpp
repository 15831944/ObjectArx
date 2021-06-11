// AcCusPoly.cpp
#include "stdafx.h"
#include "AcCusPoly.h"

#include "rxboiler.h"
#include "dbproxy.h"

ACRX_DXF_DEFINE_MEMBERS(AcCusPoly, AcDbCurve,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kAllAllowedBits, ACCUSPOLYSAMPLE,
	"ACCUSPOLYSAMPLE-2021");

AcCusPoly::AcCusPoly()
{
}
AcCusPoly:: ~AcCusPoly()
{
}