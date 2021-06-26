//
#include "stdafx.h"
#include "dbents.h"
#include "dbproxy.h"

#if ZRX == 2020 || ARX == 2013
#define subGetGripPoints getGripPoints
#define subMoveGripPointsAt moveGripPointsAt
#define subGetOsnapPoints getOsnapPoints
#endif

class CMyLine : public AcDbCurve
{
public:
    ACRX_DECLARE_MEMBERS(CMyLine);
public:
    CMyLine();
    virtual ~CMyLine();

public:
    void setStartPoint(const AcGePoint3d& pt);
    void setEndPoint(const AcGePoint3d& pt);

#if (defined(ARX) && ARX < 2010) || (defined(ZRX) && ZRX < 2021)
public:
    virtual Adesk::Boolean      worldDraw(AcGiWorldDraw* pWd);
    virtual void                viewportDraw(AcGiViewportDraw* pVd);
#endif
public:
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const;
public:
	virtual Acad::ErrorStatus   subGetGripPoints(
		AcGePoint3dArray&  gripPoints,
		AcDbIntArray &     osnapModes,
		AcDbIntArray &  geomIds) const;
	virtual Acad::ErrorStatus   subMoveGripPointsAt(const AcDbIntArray & indices,
		const AcGeVector3d& offset);
public:
	virtual Acad::ErrorStatus subErase(Adesk::Boolean erasing);

protected:
    virtual Adesk::Boolean      subWorldDraw(AcGiWorldDraw* pWd);
    virtual void                subViewportDraw(AcGiViewportDraw* pVd);

private:
    AcGePoint3d m_start;
    AcGePoint3d m_end;

    Adesk::Boolean m_bval;
    int m_nval;
};

ACRX_DXF_DEFINE_MEMBERS(CMyLine,
    AcDbCurve,
    AcDb::kDHL_CURRENT,
    AcDb::kMReleaseCurrent,
    AcDbProxyEntity::kAllAllowedBits,
    MYLINE,
    CADTEST2020);

CMyLine::CMyLine()
{
    m_bval = Adesk::kTrue;
    m_nval = 3;
}

CMyLine::~CMyLine()
{

}

void CMyLine::setStartPoint(const AcGePoint3d& pt)
{
    m_start = pt;
}

void CMyLine::setEndPoint(const AcGePoint3d& pt)
{
    m_end = pt;
}

#if (defined(ARX) && ARX < 2010) || (defined(ZRX) && ZRX < 2021)
Adesk::Boolean CMyLine::worldDraw(AcGiWorldDraw* pWd)
{
    return subWorldDraw(pWd);
}
void CMyLine::viewportDraw(AcGiViewportDraw* pVd)
{
    subViewportDraw(pVd);
}
#endif

Acad::ErrorStatus CMyLine::dwgInFields(AcDbDwgFiler * filer)
{
    assertWriteEnabled();
    AcDbCurve::dwgInFields(filer);
    filer->readItem(&m_start);
    filer->readItem(&m_end);
    filer->readItem(&m_bval);
    //[
#if (defined(ARX) && ARX < 2017) || (defined(ZRX) && ZRX < 2021)
    // acad2017之前这样读写的
    filer->readItem(&m_nval); // 这个在acad2017之前的版本中实际是按照bool从文件中读取的，保存后再打开数据发生了改变。
#else
    // 在acad2017及之后的版本中需要改成这样才能保证打开旧的图纸不会发生数据读取错误。
    Adesk::Boolean b;
    filer->readItem(&b); // 给成这样读取然后再赋值给int变量，可以保证读取文件时不会发生文件偏移错误。
    m_nval = b;
#endif
    //]
    return filer->filerStatus();
}
Acad::ErrorStatus CMyLine::dwgOutFields(AcDbDwgFiler * filer) const
{
    assertReadEnabled();
    if (Acad::eOk != AcDbCurve::dwgOutFields(filer))
        return filer->filerStatus();
    filer->writeItem(m_start);
    filer->writeItem(m_end);
    filer->writeItem(m_bval);
    //[
#if (defined(ARX) && ARX < 2017) || (defined(ZRX) && ZRX < 2021)
    // acad2017之前这样读写的
    filer->writeItem(m_nval); // 这个在acad2017之前的版本中实际是按照bool写到文件中的，保存后再打开数据发生了改变。
#else
    // 在acad2017及之后的版本中需要改成这样才能保证写下去的数据跟旧版本中一致。
    filer->writeItem((Adesk::Boolean)m_nval); // 改成这样可以保证在acad2017及更新的版本中保存后再打开的结果跟之前的版本一致。
#endif
    //]
    return filer->filerStatus();
}

Acad::ErrorStatus CMyLine::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds) const
{
	assertReadEnabled();
	gripPoints.removeAll();
	gripPoints.append(m_start);
	gripPoints.append(m_end);
	return Acad::eOk;
}

Acad::ErrorStatus CMyLine::subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset)
{
	assertWriteEnabled();
	if (indices.length() > 0)
	{
		AcGeMatrix3d mat;
		mat.setToTranslation(offset);
		switch (indices[0])
		{
		case 0:
			m_start.transformBy(mat);
			break;
		case 1:
			m_end.transformBy(mat);
			break;
		default:
			break;
		}
	}
	return Acad::eOk;
}

Acad::ErrorStatus CMyLine::subErase(Adesk::Boolean erasing)
{
	assertWriteEnabled();
	return Acad::eOk;
}

Adesk::Boolean CMyLine::subWorldDraw(AcGiWorldDraw*)
{
    return Adesk::kFalse;
}

void CMyLine::subViewportDraw(AcGiViewportDraw* pVd)
{
    pVd->subEntityTraits().setFillType(AcGiFillType::kAcGiFillAlways);
    switch (pVd->subEntityTraits().fillType())
    {
    case AcGiFillType::kAcGiFillAlways:
        acutPrintf(_T("\nkAcGiFillAlways in CMyLine::subViewportDraw"));
        break;
    case AcGiFillType::kAcGiFillNever:
    default:
        acutPrintf(_T("\nkAcGiFillNever in CMyLine::subViewportDraw"));
        break;
    }

    AcGePoint2d pt1, pt2;
    AcDbPolyline pline1;
    pt1 = asPnt2d(asDblArray(m_start));
    pt2 = asPnt2d(asDblArray(m_end));
    pline1.addVertexAt(0, pt1);
    pline1.addVertexAt(1, pt2);
    pline1.setConstantWidth(5);
    AcCmColor color1;
    color1.setColorIndex(1);
    pline1.setColor(color1);
    pVd->geometry().pline(pline1); // error 非实线则为空心

    AcDbPolyline pline2;
    pt1 += AcGeVector2d::kYAxis * 10;
    pt2 += AcGeVector2d::kYAxis * 10;
    pline2.addVertexAt(0, pt1);
    pline2.addVertexAt(1, pt2);
    pline2.setConstantWidth(5);
    AcCmColor color2;
    color1.setColorIndex(2);
    pline1.setColor(color2);
    pline2.viewportDraw(pVd); // ok 非实线也是实心

    AcGePoint3d pts[2];
    pts[0] = m_start + AcGeVector3d::kYAxis * 20;
    pts[1] = m_end + AcGeVector3d::kYAxis * 20;
    pVd->subEntityTraits().setColor(m_bval ? 1 : 0);
    pVd->subEntityTraits().setLineWeight(AcDb::kLnWt050);
    pVd->geometry().polyline(2, pts); // 线宽无效？

    pts[0] = m_start + AcGeVector3d::kYAxis * 30;
    pts[1] = m_end + AcGeVector3d::kYAxis * 30;
    pVd->subEntityTraits().setColor(m_nval);
    pVd->subEntityTraits().setLineWeight(AcDb::kLnWt050);
    pVd->geometry().polyline(2, pts); // 线宽无效？

}


REGISTER_OBJECT(CMyLine);


ARXCMD3(CreateMyLine)
{
    CMyLine* line = new CMyLine();
    line->setStartPoint(AcGePoint3d::kOrigin);
    line->setEndPoint(AcGePoint3d(100, 0, 0));
    AcDbObjectId oid;
    if (Acad::eOk == CADUtils::AppendToModalSpace(line, oid))
    {
        line->close();
    }
    else
    {
        delete line;
    }
    line = nullptr;
}