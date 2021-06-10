#ifndef _DRAGMULTIENTITIES_H_
#define _DRAGMULTIENTITIES_H_

#if ZRX == 2020 || ARX == 2013
#define subWorldDraw worldDraw
#define subViewportDraw viewportDraw
#define subList list
#define subGetSubentPathsAtGsMarker getSubentPathsAtGsMarker
#define subGetGripPoints getGripPoints
#define subMoveGripPointsAt moveGripPointsAt
#define subGetOsnapPoints getOsnapPoints
#define subIntersectWith intersectWith
#define subExplode explode
#endif

#include <afxwin.h>
#include "dbents.h"
#include "dbjig.h"

// ����ʵ����
// �������϶����ݿ����Ѿ����ڵ�ʵ�壬ͨ����һ��ѡ��ѡ���ʵ�弯
class CDatabaseJigEntity : public AcDbEntity
{
public:
	CDatabaseJigEntity(const AcDbObjectIdArray &ids) : m_Ids(ids) { }
	~CDatabaseJigEntity() {}
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw *mode);
	inline void setXform(const AcGeMatrix3d &xform) { m_Xform = xform; }
	BOOL transform();
	BOOL transformedCopy();
private:
	AcDbObjectIdArray	m_Ids;	 // ���������϶������ID
	AcGeMatrix3d		m_Xform; // �任����
};

// �ƶ�ʵ����϶���
class CMoveJig : public AcEdJig
{
public:
	CMoveJig(const AcGePoint3d &fromPoint) : m_pEnt(NULL), m_FromPoint(fromPoint), m_ToPoint(fromPoint) {};
	~CMoveJig();
	void	doIt(const AcDbObjectIdArray &ids, bool bCopy = false);
	virtual DragStatus sampler();
	virtual Adesk::Boolean update();
	virtual AcDbEntity* entity() const;
private:
	CDatabaseJigEntity	*m_pEnt;
	AcGePoint3d			m_FromPoint;
	AcGePoint3d			m_ToPoint;
	AcGeMatrix3d		m_Xform;
};
#endif
