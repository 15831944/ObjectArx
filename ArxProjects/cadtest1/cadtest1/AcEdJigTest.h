//
#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _ACEDJIGTEST_H_
#define _ACEDJIGTEST_H_

#include "dbjig.h"
#include "gevec3d.h"

class EllipseJig : public AcEdJig
{
public:
	EllipseJig(const AcGePoint3d&, const AcGeVector3d&);
	void doIt();
	virtual DragStatus sampler();
	virtual Adesk::Boolean update();
	virtual AcDbEntity* entity() const;

private:
	AcDbEllipse *m_pEllipse;
	AcGePoint3d m_ptCenter, m_ptAxis;
	AcGeVector3d m_majorAxis, m_normal;
	double m_radiusRatio;
	int m_promptCounter;
};




#endif