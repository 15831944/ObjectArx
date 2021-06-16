//////////////////////////////////////////////////////////////////////////////
// LbAzPolyLine2 custom object, created by  [2005-10-14], , 

#include "StdAfx.h"
//#include "StdArx.h"
#include "dbproxy.h"
#include "LbAzPolyLine.h"
//#include "LinkInfos.h"
//#include "LbCadTool/LbCommonTool.h"

#include "rxboiler.h"
#include "dbproxy.h"

__declspec(dllexport) bool g_bQuYuXiaoYan = false;//标识是否是区域校验

#define VERSION_LBAZPOLYLINE2 1

ACRX_DXF_DEFINE_MEMBERS(LbAzPolyLine2, AcDbLine,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kNoOperation,
	LBAZPOLYLINE2, LbAzObject);

// Constructor / Destructor

LbAzPolyLine2::LbAzPolyLine2()
{
}

LbAzPolyLine2::~LbAzPolyLine2()
{
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::dwgInFields(AcDbDwgFiler* pFiler)
{
	assertWriteEnabled();
	Acad::ErrorStatus es;

	// Call dwgInFields from LbAzPolyLine
	if ((es = __super::dwgInFields(pFiler)) != Acad::eOk)
	{
		return es;
	}

	// Read version number.
	Adesk::UInt16 version;
	pFiler->readItem(&version);
	if (version > VERSION_LBAZPOLYLINE2)
		return Acad::eMakeMeProxy;

	// Read the data members.
	switch (version)
	{
	case (1):
	{
		Acad::ErrorStatus es1 = m_pPolyline.dwgInFields(pFiler);
	}
	break;
	}

	return pFiler->filerStatus();
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::dwgOutFields(AcDbDwgFiler* pFiler) const
{
	assertReadEnabled();
	Acad::ErrorStatus es;

	// Call dwgOutFields from LbAzPolyLine
	if ((es = __super::dwgOutFields(pFiler)) != Acad::eOk)
	{
		return es;
	}

	// Write version number.
	pFiler->writeItem((Adesk::UInt16) VERSION_LBAZPOLYLINE2);

	// Write the data members.
	///////////////
	Acad::ErrorStatus es1 = m_pPolyline.dwgOutFields(pFiler);

	return pFiler->filerStatus();
}


AcGePoint3d LbAzPolyLine2::startPoint() const
{
	assertReadEnabled();
	//return __super::startPoint();
	AcGePoint3d pnt;
	m_pPolyline.getStartPoint(pnt);
	return pnt;
}

AcGePoint3d LbAzPolyLine2::endPoint() const
{
	assertReadEnabled();
	//return __super::endPoint();
	AcGePoint3d pnt;
	m_pPolyline.getEndPoint(pnt);
	return pnt;
}

Acad::ErrorStatus LbAzPolyLine2::setStartPoint(const AcGePoint3d& pntSt)
{
	assertWriteEnabled();
	//return __super::setStartPoint(pntSt);

	AcGePoint3d pnt0,pnt1;
	AcGeVector3d vecNormal;
	double dBulge(0);
	//CGloblFun::GetPolyPt(&m_pPolyline,pnt0,pnt1,vecNormal,dBulge);	

	//#bug 61057 保证z值精度Bug #80192
	if (fabs(pnt1.z - pntSt.z) < 0.1)
	{
		pnt1.z = pntSt.z;
	}

	//CGloblFun::SetPolyPt(&m_pPolyline,pntSt,pnt1,vecNormal,dBulge);
	m_pPolyline.addVertexAt(0, AcGePoint2d(pntSt.x, pntSt.y));
	return Acad::eOk;
}

Acad::ErrorStatus LbAzPolyLine2::setEndPoint(const AcGePoint3d& pntEnd)
{
	assertWriteEnabled();
	//return __super::setEndPoint(pntEnd);

	AcGePoint3d pnt0,pnt1;
	AcGeVector3d vecNormal;
	double dBulge(0);
	//CGloblFun::GetPolyPt(&m_pPolyline,pnt0,pnt1,vecNormal,dBulge);	

	//#bug 61057 保证z值精度Bug #80192
	if (fabs(pnt0.z - pntEnd.z) < 0.1)
	{
		pnt0.z = pntEnd.z;
	}

	//CGloblFun::SetPolyPt(&m_pPolyline,pnt0,pntEnd,vecNormal,dBulge);	
	m_pPolyline.addVertexAt(1, AcGePoint2d(pntEnd.x, pntEnd.y));
	return Acad::eOk;
}

void LbAzPolyLine2::subList() const
{
	assertReadEnabled();
	__super::subList();

	AcGeVector3d normal = GetNormal();

	acutPrintf(_T( "\n Normal:%.2f,%.2f,%.2f " ), normal.x, normal.y, normal.z);
}

AcGeVector3d LbAzPolyLine2::GetNormal() const
{
	assertReadEnabled();
	//return AcGeVector3d(0, 0, 1);
	return m_pPolyline.normal();
}

void LbAzPolyLine2::SetNormal(AcGeVector3d vecNormal)
{
	assertWriteEnabled();

	double dBulge = GetBulge();
	if(fabs(dBulge)>1e-8)
	{
		m_pPolyline.setNormal(vecNormal);		
	}
}

double LbAzPolyLine2::GetBulge() const
{
	assertReadEnabled();
	//return 0;
	double dBulge(0);
	m_pPolyline.getBulgeAt(0,dBulge);
	return dBulge;
}

void LbAzPolyLine2::SetBulge(double dBulge)
{
	assertWriteEnabled();
	m_pPolyline.setBulgeAt(0,dBulge);
}

 const AcDbPolyline& LbAzPolyLine2::GetPoly() const
 {
 	assertReadEnabled();
 
 	return m_pPolyline;
 }

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getStartPoint(AcGePoint3d& x0) const
{
	assertReadEnabled();

	//return __super::getStartPoint(x0);
	return m_pPolyline.getStartPoint(x0);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getEndPoint(AcGePoint3d& x0) const
{
	assertReadEnabled();
	//return __super::getEndPoint(x0);

	return m_pPolyline.getEndPoint(x0);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getStartParam(double& x0) const
{
	assertReadEnabled();
	//return __super::getStartParam(x0);

	return m_pPolyline.getStartParam(x0);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getEndParam(double& x0) const
{
	assertReadEnabled();
	//return __super::getEndParam(x0);

	return m_pPolyline.getEndParam(x0);
}


//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getPointAtParam(double param,
													 AcGePoint3d& point) const
{
	assertReadEnabled();
	//return __super::getPointAtParam(param, point);

	return m_pPolyline.getPointAtParam(param,point);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getParamAtPoint(const AcGePoint3d& x0,
													 double& x1)const
{
	assertReadEnabled();
	//return __super::getParamAtPoint(x0, x1);

	return m_pPolyline.getParamAtPoint(x0,x1);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getDistAtParam(double param,
													double& dist) const
{
	assertReadEnabled();
	//return __super::getDistAtParam(param, dist);

	return m_pPolyline.getDistAtParam(param,dist);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getParamAtDist(double dist,
													double& param) const
{
	assertReadEnabled();
	//return __super::getParamAtDist(dist, param);

	return m_pPolyline.getParamAtDist(dist,param);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getDistAtPoint(const AcGePoint3d& x0,
													double& x1)const
{
	assertReadEnabled();
	//return __super::getDistAtPoint(x0, x1);

	return m_pPolyline.getDistAtPoint(x0,x1);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getPointAtDist(double x0,
													AcGePoint3d& x1) const
{
	assertReadEnabled();
	//return __super::getPointAtDist(x0, x1);

	return m_pPolyline.getPointAtDist(x0,x1);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::extend(Adesk::Boolean extendStart,
											const AcGePoint3d& toPoint)
{
	assertWriteEnabled();
	//return __super::extend(extendStart, toPoint);

	return m_pPolyline.extend(extendStart,toPoint);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::extend(double newParam)
{
	assertWriteEnabled();
	//return __super::extend(newParam);

	return m_pPolyline.extend(newParam);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getClosestPointTo(const AcGePoint3d& givenPnt,
													   AcGePoint3d& pointOnCurve,
													   Adesk::Boolean extend) const
{
	assertReadEnabled();
	//return __super::getClosestPointTo(givenPnt, pointOnCurve, extend);

	return m_pPolyline.getClosestPointTo(givenPnt,pointOnCurve,extend);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getClosestPointTo(const AcGePoint3d& givenPnt,
													   const AcGeVector3d& direction,
													   AcGePoint3d& pointOnCurve,
													   Adesk::Boolean extend) const
{
	assertReadEnabled();
	//return __super::getClosestPointTo(givenPnt, direction, pointOnCurve, extend);

	return m_pPolyline.getClosestPointTo(givenPnt,direction,pointOnCurve,extend);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getFirstDeriv(const AcGePoint3d& x0,
												   AcGeVector3d& firstDeriv) const
{
	assertReadEnabled();
	//return __super::getFirstDeriv(x0, firstDeriv);

	return m_pPolyline.getFirstDeriv(x0,firstDeriv);
}

Acad::ErrorStatus LbAzPolyLine2::getProjectedCurve(const AcGePlane&    plane,
													   const AcGeVector3d& projDir,
													   AcDbCurve*&       projectedCurve) const
{
	assertReadEnabled();
	//return __super::getProjectedCurve(plane, projDir, projectedCurve);

	return m_pPolyline.getProjectedCurve(plane,projDir,projectedCurve);
}

#if 0
#include "relation.h"
bool g_bUserHighlight = true;
Acad::ErrorStatus LbAzPolyLine2::subHighlight(const AcDbFullSubentPath& subId,
									const Adesk::Boolean highlightAll) const
{
	if(g_bUserHighlight == true)
	{
		if(g_bQuYuXiaoYan == true)
		{
			AcDbObjectIdArray idArray;
			vector<CString> strHandleAry;
			if(CLinkInfos::Instance()->IsEntLinked(this->objectId(),idArray,strHandleAry) == TRUE)
			{
				for(int i = 0; i < idArray.length(); i++)
				{
					Acad::ErrorStatus es;
					LbAzEntity* pEntity = NULL;
					es = acdbOpenObject(pEntity,idArray[i],AcDb::kForWrite,Adesk::kTrue);
					if (es != Acad::eOk)
						continue;
					g_bUserHighlight = false;
					pEntity->highlight();
					g_bUserHighlight = true;
					pEntity->close();

					if (CLinkInfos::Instance()->GetLinkJiaoyan())//连续校验
					{
						CLinkInfos::Instance()->m_removeIds.erase(
							remove(CLinkInfos::Instance()->m_removeIds.begin(),
							CLinkInfos::Instance()->m_removeIds.end(), idArray[i]), 
							CLinkInfos::Instance()->m_removeIds.end());
					}
				}
			}
		}
	}
	return __super::subHighlight(subId,highlightAll);
}

bool g_bUserUnHighlight = true;
Acad::ErrorStatus LbAzPolyLine2::subUnhighlight(const AcDbFullSubentPath& subId,
									  const Adesk::Boolean highlightAll) const
{
	if(g_bUserUnHighlight == true)
	{
		if(g_bQuYuXiaoYan == true)
		{
			AcDbObjectIdArray idArray;
			vector<CString> strHandleAry;
			if(CLinkInfos::Instance()->IsEntLinked(this->objectId(),idArray,strHandleAry) == TRUE)
			{
				for(int i = 0; i < idArray.length(); i++)
				{
					Acad::ErrorStatus es;
					LbAzEntity* pEntity = NULL;
					es = acdbOpenObject(pEntity,idArray[i],AcDb::kForWrite,Adesk::kTrue);
					if (es != Acad::eOk)
						continue;
					g_bUserUnHighlight = false;
					pEntity->unhighlight();
					g_bUserUnHighlight = true;
					pEntity->close();

					if (CLinkInfos::Instance()->GetLinkJiaoyan())//连续校验
					{
						CLinkInfos::Instance()->m_removeIds.push_back(idArray[i]);
					}
				}
			}
		}
	}
	return __super::subUnhighlight(subId,highlightAll);
}
#endif
//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getFirstDeriv(double param,
												   AcGeVector3d& firstDeriv) const
{
	assertReadEnabled();
	//return __super::getFirstDeriv(param, firstDeriv);

	return m_pPolyline.getFirstDeriv(param,firstDeriv);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subGetGeomExtents(AcDbExtents& extents) const
{
	assertReadEnabled();
	//return __super::getGeomExtents(extents);
	
	return m_pPolyline.getGeomExtents(extents);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getOffsetCurves(double offsetDist,
													 AcDbVoidPtrArray& offsetCurves) const
{
	assertReadEnabled();
	//return __super::getOffsetCurves(offsetDist, offsetCurves);

	return m_pPolyline.getOffsetCurves(offsetDist,offsetCurves);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal,
																	 double offsetDist,
																	 AcDbVoidPtrArray& offsetCurves) const
{
	assertReadEnabled();
	//return __super::getOffsetCurvesGivenPlaneNormal(normal, offsetDist, offsetCurves);

	return m_pPolyline.getOffsetCurvesGivenPlaneNormal(normal,offsetDist,offsetCurves);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subExplode(AcDbVoidPtrArray& entitySet) const
{
	assertReadEnabled();
	
	return __super::subExplode(entitySet);
}


//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subGetOsnapPoints(AcDb::OsnapMode osnapMode,
													Adesk::GsMarker gsSelectionMark,
													const AcGePoint3d& pickPoint,
													const AcGePoint3d& lastPoint,
													const AcGeMatrix3d& viewXform,
													AcGePoint3dArray& snapPoints,
													AcDbIntArray& geomIds) const
{
	assertReadEnabled();
	//return __super::subGetOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);

	Acad::ErrorStatus es = m_pPolyline.getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);

	//if(LbCommonTool::IsCur2dShow())//目前是2d图,则返回点的Z坐标为0
	{
		int nLength = snapPoints.length();
		AcGePoint3d snapPoint;
		for(int i=0;i<nLength;i++)
		{
			snapPoint = snapPoints[i];
			snapPoint.z = 0;
			snapPoints.setAt(i,snapPoint);
		}
	}
	return es;
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getSecondDeriv(const AcGePoint3d& x0,
													AcGeVector3d& secDeriv) const
{
	assertReadEnabled();
	//return __super::getSecondDeriv(x0, secDeriv);

	return m_pPolyline.getSecondDeriv(x0, secDeriv);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getSecondDeriv(double param,
													AcGeVector3d& secDeriv) const
{
	assertReadEnabled();
	//return __super::getSecondDeriv(param, secDeriv);

	return m_pPolyline.getSecondDeriv(param, secDeriv);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getSplitCurves(const AcGeDoubleArray& params,
													AcDbVoidPtrArray& curveSegments) const
{
	assertReadEnabled();
	//return __super::getSplitCurves(params, curveSegments);

	Acad::ErrorStatus es = m_pPolyline.getSplitCurves(params, curveSegments);

	AcGePoint3d pnt0,pnt1;
	AcGeVector3d vecNormal;
	double dBulge(0);
	AcDbPolyline* pPoly = NULL;

	AcDbVoidPtrArray newSegments;
	int nLength = curveSegments.length();
	for(int i=0;i<nLength;i++)
	{
		pPoly = AcDbPolyline::cast((AcDbEntity*)curveSegments[i]);
		if(pPoly==NULL)
			continue;
		//CGloblFun::GetPolyPt(pPoly,pnt0,pnt1,vecNormal,dBulge);	

		LbAzPolyLine2* pNew  = (LbAzPolyLine2*)(clone());
		if(pNew==NULL)
			continue;
		//CGloblFun::SetPolyPt(&pNew->m_pPolyline,pnt0,pnt1,vecNormal,dBulge);	
		newSegments.append(pNew);
	}

	//LBToolKit::ReleaseVoidArray(curveSegments);
	curveSegments.append(newSegments);

	return es;
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::getSplitCurves(const AcGePoint3dArray& points,
													AcDbVoidPtrArray& curveSegments) const
{
	assertReadEnabled();
	
	AcGeDoubleArray params;
	params.setLogicalLength(points.length());
	for (int i = 0; i < points.length(); i++) 
	{
		getParamAtPoint(points[i], params[i]);
	}

	return getSplitCurves(params, curveSegments);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subIntersectWith(const AcDbEntity* pEnt,
												   AcDb::Intersect intType,
												   AcGePoint3dArray& points,
												   Adesk::GsMarker thisGsMarker,
												   Adesk::GsMarker otherGsMarker) const
{
	assertReadEnabled();
	//return __super::subIntersectWith(pEnt, intType, points, thisGsMarker, otherGsMarker);

	return m_pPolyline.intersectWith(pEnt, intType, points, thisGsMarker, otherGsMarker);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subIntersectWith(const AcDbEntity* pEnt,
												   AcDb::Intersect intType,
												   const AcGePlane& projPlane,
												   AcGePoint3dArray& points,
												   Adesk::GsMarker thisGsMarker,
												   Adesk::GsMarker otherGsMarker) const
{
	assertReadEnabled();
	//return __super::subIntersectWith(pEnt, intType, projPlane, points, thisGsMarker, otherGsMarker);

	acutPrintf(_T("\n pEnt2.name: %s"), pEnt->isA()->name());

	Acad::ErrorStatus es = m_pPolyline.intersectWith(pEnt, intType, projPlane, points, thisGsMarker, otherGsMarker);
	return es;
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subGetStretchPoints(AcGePoint3dArray& stretchPoints) const
{
	assertReadEnabled();
	//return __super::subGetStretchPoints(stretchPoints);

	Acad::ErrorStatus es = m_pPolyline.getStretchPoints(stretchPoints);
	return es;
}

Adesk::Boolean LbAzPolyLine2::subWorldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();    // Its purpose is to make sure that the object is open AcDb::kForRead.

	m_pPolyline.worldDraw(wd);

	return Adesk::kTrue;
}

 Acad::ErrorStatus   LbAzPolyLine2::getAzPolyGripPoints_2d(AcGePoint3dArray&  gripPoints)const
 {
	 AcGePoint3d startPt, endPt;
	 m_pPolyline.getStartPoint(startPt);
	 m_pPolyline.getEndPoint(endPt);
	// AcGePoint3d midPoint = CGloblFun::GetPolyMovePt(&m_pPolyline);

	 gripPoints.append(startPt);
	 gripPoints.append(endPt);
	// gripPoints.append(midPoint);

 	return Acad::eOk;
 }


//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subGetGripPoints(AcGePoint3dArray& gripPoints,
												 AcDbIntArray& osnapModes,
												 AcDbIntArray& geomIds) const
{
	assertReadEnabled();

	Acad::ErrorStatus es = m_pPolyline.getGripPoints(gripPoints,osnapModes,geomIds);
	//AcGePoint3d point = CGloblFun::GetPolyMovePt(&m_pPolyline);
	//gripPoints.append(point);
	return es;
	return __super::subGetGripPoints(gripPoints, osnapModes, geomIds);
	//return getAzPolyGripPoints_2d(gripPoints);
}

 Acad::ErrorStatus LbAzPolyLine2::moveGripPointsAt_2d(const AcDbIntArray& indices, const AcGeVector3d& offset)
 {
 	if (indices.length() < 1)
 	{
 		return Acad::eInvalidIndex;
 	}
 
 	int nd = indices.at(0);
 	if (nd >= 2)
 	{
 		return Acad::eInvalidIndex;
 	}
 
 	AcGePoint3d startPt, endPt;
 	m_pPolyline.getStartPoint(startPt);
 	m_pPolyline.getEndPoint(endPt);
 
 	//trans
 	if (nd == 0)
 	{
 		AcGePoint3d newStartPt = startPt + offset;
 		//if (LbCommonTool::IsCur2dShow()) // 二维状态下，z不变
 		{
 			newStartPt.z = startPt.z;
 		}
 		setStartPoint(newStartPt);
 	}
 	else if (nd == 1)
 	{
 		AcGePoint3d newEndPt = endPt + offset;
 		//if (LbCommonTool::IsCur2dShow()) // 二维状态下，z不变
 		{
 			newEndPt.z = endPt.z;
 		}
 		setEndPoint(newEndPt);
 	}
 
 	return Acad::eOk;
 }

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subMoveGripPointsAt(const AcDbIntArray& indices,
													  const AcGeVector3d& offset)
{
	assertWriteEnabled();

	//return __super::subMoveGripPointsAt(indices, offset);
	if(__super::subMoveGripPointsAt(indices, offset)==Acad::eOk)
	{
		return Acad::eOk;
	}

	int indiceslen=indices.length();
	if (indiceslen== 0 || offset.isZeroLength())
	{
		return Acad::eOk;
	}

	AcGePoint3dArray gripPoints;
	//AcDbIntArray osnapModes; 
	//AcDbIntArray geomIds;
	//m_pPolyline.getGripPoints(gripPoints,osnapModes,geomIds);
	getAzPolyGripPoints_2d(gripPoints);

	int nd = indices.at(0);
	if(nd == 2)//夹点为poly线后面的夹点,表明整体移动
	{
		AcGeMatrix3d  xform;
		xform.setTranslation(offset);
		subTransformBy(xform);	
		return Acad::eOk;
	}

	return moveGripPointsAt_2d(indices, offset);
	//return m_pPolyline.moveGripPointsAt(indices, offset);
}

//-----------------------------------------------------------------------------
Acad::ErrorStatus LbAzPolyLine2::subMoveStretchPointsAt(const AcDbIntArray& indices,
														 const AcGeVector3d& offset)
{
	assertWriteEnabled();
	return m_pPolyline.moveStretchPointsAt(indices, offset);
}

REGISTER_OBJECT(LbAzPolyLine2)
ARXCMD3(LBAzPlineTest)
{
	LbAzPolyLine2 *pEnt = new LbAzPolyLine2;
	pEnt->setStartPoint(AcGePoint3d(0, 0, 0));
	pEnt->setEndPoint(AcGePoint3d(100, 100, 0));

	AcDbObjectId id;
	CADUtils::AppendToModalSpace(pEnt, id);
	pEnt->close();
}