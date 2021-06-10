
#pragma once
#include "stdafx.h"
#include "dbjig.h"
#include "dbcurve.h"

class  CPmDbLinetmpJig : public AcEdJig 
{
private:	
	enum EJigtype
	{
		eLinestart = 0,
		eLineend  =  1,
		eArcstart =  2,
		eArcend	  =  3		
	} m_type;

	AcGePoint3d		m_CurPt;
	AcDbCurve*      m_pEntity; //用于显示

public:
	CPmDbLinetmpJig();
	virtual ~CPmDbLinetmpJig();

//jig operator:
	//参数：objId	要做jig的实体， 
	//      curpt	当前鼠标的位置
	Adesk::Boolean doIt(const AcDbObjectId &objId);	
    virtual DragStatus sampler();
    virtual Adesk::Boolean update()		{return Adesk::kTrue;}
    virtual AcDbEntity* entity() const	{return m_pEntity;	}

protected:
	//重置相关的端部
	void ReSetLine(AcGePoint3d curPt);
	BOOL ReSetLine(double dblDis);
};