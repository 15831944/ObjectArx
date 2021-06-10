#pragma once
#include "drawable.h"
#include "dbents.h"


class AddBlockReference :
	public AcGiDrawable
{
public:

	AddBlockReference() {}
	~AddBlockReference() {}

	virtual Adesk::UInt32 subsetAttributes(ZcGiDrawableTraits * traits)
	{
	}
	virtual Adesk::Boolean isPersistent(void) const = 0;
	virtual AcDbObjectId    id(void) const = 0;

	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pW)
	{
		AcDbBlockReference cBlockref;
		cBlockref.setBlockTableRecord(m_refBlockId);
		cBlockref.setBlockTransform(m_cMat);
		Adesk::Boolean bRet = cBlockref.worldDraw(pW);
		return bRet;
	}
	void setBlockRef(const AcDbObjectId& refBlockId)
	{
		m_refBlockId = refBlockId;
	}
private:
	AcDbObjectId m_refBlockId;
	AcGeMatrix3d m_cMat;
};

