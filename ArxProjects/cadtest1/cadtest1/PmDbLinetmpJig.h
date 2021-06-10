
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
	AcDbCurve*      m_pEntity; //������ʾ

public:
	CPmDbLinetmpJig();
	virtual ~CPmDbLinetmpJig();

//jig operator:
	//������objId	Ҫ��jig��ʵ�壬 
	//      curpt	��ǰ����λ��
	Adesk::Boolean doIt(const AcDbObjectId &objId);	
    virtual DragStatus sampler();
    virtual Adesk::Boolean update()		{return Adesk::kTrue;}
    virtual AcDbEntity* entity() const	{return m_pEntity;	}

protected:
	//������صĶ˲�
	void ReSetLine(AcGePoint3d curPt);
	BOOL ReSetLine(double dblDis);
};