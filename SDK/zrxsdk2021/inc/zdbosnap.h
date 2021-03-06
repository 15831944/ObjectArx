

#ifndef _ZDBOSNAP_H
#define _ZDBOSNAP_H

#include "zadesk.h"

#pragma warning (disable: 4786)

#pragma pack (push, 8)

class ZCDB_PORT ZcDbCustomOsnapInfo : public ZcRxObject {
public:
    ZCRX_DECLARE_MEMBERS(ZcDbCustomOsnapInfo);

virtual Zcad::ErrorStatus   getOsnapInfo(
                           ZcDbEntity*           pickedObject,
                           ZSoft::GsMarker       gsSelectionMark,
                           const ZcGePoint3d&    pickPoint,
                           const ZcGePoint3d&    lastPoint,
                           const ZcGeMatrix3d&   viewXform,
                           ZcArray<ZcGePoint3d>& snapPoints,
                           ZcDbIntArray &     geomIdsForPts,
                           ZcArray<ZcGeCurve3d*>& snapCurves,
                           ZcDbIntArray &     geomIdsForLines) = 0;
};

class ZCDB_PORT ZcGiGlyph : public ZcGiDrawable
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiGlyph);

    virtual Zcad::ErrorStatus setLocation(const ZcGePoint3d& dcsPoint) = 0;

	virtual ZSoft::Boolean  isPersistent() const override {return ZSoft::kFalse;}
	virtual ZcDbObjectId    id() const override {return 0;}

	 virtual void            setGsNode(ZcGsNode* pNode) { ZcGiDrawable::setGsNode(pNode); } 
     virtual ZcGsNode*       gsNode() const				{ return ZcGiDrawable::gsNode(); }	

protected:
	
	     virtual ZSoft::UInt32   subSetAttributes(ZcGiDrawableTraits*) override { return 0; }
	     virtual ZSoft::Boolean  subWorldDraw(ZcGiWorldDraw*) override {return ZSoft::kFalse;};
	     virtual void            subViewportDraw(ZcGiViewportDraw* vportDrawContext) override = 0;
	
};

class ZcDbCustomOsnapMode {
  public:

    virtual const ZTCHAR * localModeString() const = 0;
    virtual const ZTCHAR * globalModeString() const = 0;

    virtual const ZcRxClass* entityOsnapClass() const = 0;

    virtual ZcGiGlyph* glyph() const = 0;

    virtual const ZTCHAR *               tooltipString() const = 0;
    virtual ~ZcDbCustomOsnapMode() {}
};

class ZcDbCustomOsnapManager {
public:
	virtual ~ZcDbCustomOsnapManager(){}

    virtual Zcad::ErrorStatus addCustomOsnapMode(ZcDbCustomOsnapMode* pMode) = 0;

    virtual Zcad::ErrorStatus removeCustomOsnapMode(ZcDbCustomOsnapMode* pMode) = 0;

    virtual Zcad::ErrorStatus activateOsnapMode(const ZTCHAR * modeStr) = 0;

    virtual Zcad::ErrorStatus deactivateOsnapMode(const ZTCHAR * modeStr) = 0;

    virtual ZSoft::Boolean modeIsActive(const ZTCHAR * modeStr) = 0;

    virtual int osnapGlyphSize() const = 0;
};

ZcDbCustomOsnapManager* zcdbCustomOsnapManager();

extern "C" __declspec (dllexport)
bool zcedIsOsnapOverride();

#pragma pack (pop)

#endif  

