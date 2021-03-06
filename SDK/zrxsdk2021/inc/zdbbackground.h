
#pragma once

#include "zdbmain.h"
#include "zAcGiEnvironment.h"
#include "zdbcolor.h"
#include "zAdAChar.h"

#pragma pack(push, 8)

#pragma warning( disable: 4275 4251 )

#ifdef SCENEDLLIMPEXP
#undef SCENEDLLIMPEXP
#endif
#ifdef SCENEOE
#define SCENEDLLIMPEXP __declspec( dllexport )
#else
#define SCENEDLLIMPEXP
#endif

const ZTCHAR ZCDB_BACKGROUND_DICTIONARY[]  = ZCRX_T("ACAD_BACKGROUND");

Zcad::ErrorStatus SCENEDLLIMPEXP getBackgroundDictionary   (ZcDbDatabase* pDb, ZcDbDictionary*& pDict,
                                             ZcDb::OpenMode mode, bool createIfNonExist);
Zcad::ErrorStatus SCENEDLLIMPEXP getBackgroundDictionary   (ZcDbDatabase* pDb, ZcDbDictionary*& pDict,
                                             ZcDb::OpenMode mode);

class ZcDbImpBackground;

class SCENEDLLIMPEXP ZcDbBackground : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbBackground);
    virtual ~ZcDbBackground();
    virtual ZcGiDrawable*  drawable () override;

protected:
    ZcDbBackground(ZcDbImpBackground* pImp);
    ZcDbImpBackground* imp() const;

private:
    friend class ZcDbImpBackground;
    ZcDbImpBackground* mpImp;
};

class SCENEDLLIMPEXP ZcDbSolidBackground : public ZcDbBackground
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSolidBackground);
    ZcDbSolidBackground();
    virtual ~ZcDbSolidBackground();
    void            setColorSolid   (const ZcCmEntityColor & color);
    ZcCmEntityColor colorSolid      (void) const;
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus copyFrom     (const ZcRxObject* other) override;
    virtual ZcGiDrawable::DrawableType    drawableType() const override;

protected:
	virtual ZSoft::UInt32  subSetAttributes (ZcGiDrawableTraits* pTraits) override;   
private:
    friend class ZcDbImpSolidBackground;
};

class SCENEDLLIMPEXP ZcDbGradientBackground : public ZcDbBackground
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbGradientBackground);
    ZcDbGradientBackground();
    virtual ~ZcDbGradientBackground();
    void            setColorTop    (const ZcCmEntityColor & color);
    ZcCmEntityColor colorTop       (void) const;
    void            setColorMiddle (const ZcCmEntityColor & color);
    ZcCmEntityColor colorMiddle    (void) const;
    void            setColorBottom (const ZcCmEntityColor & color);
    ZcCmEntityColor colorBottom    (void) const;
    void            setHorizon     (double horizon);
    double          horizon        (void) const;
    void            setHeight      (double height);
    double          height         (void) const ;
    void            setRotation    (double rotation);
    double          rotation       (void) const;
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus copyFrom     (const ZcRxObject* other) override;
    virtual ZcGiDrawable::DrawableType    drawableType() const override;

protected:
	virtual ZSoft::UInt32  subSetAttributes (ZcGiDrawableTraits* pTraits) override;	 

private:
    friend class ZcDbImpGradientBackground;
};

class SCENEDLLIMPEXP ZcDbImageBackground : public ZcDbBackground
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbImageBackground);
    ZcDbImageBackground();
    virtual ~ZcDbImageBackground();
    void            setImageFilename        (const ZTCHAR* filename);
    const ZTCHAR *   imageFilename           (void) const;
    void            setFitToScreen          (bool bFitToScreen);
    bool            fitToScreen             (void) const;
    void            setMaintainAspectRatio  (bool bMaintainAspectRatio);
    bool            maintainAspectRatio     (void) const;
    void            setUseTiling            (bool bUseTiling);
    bool            useTiling               (void) const;
    void            setXOffset              (double xOffset);
    double          xOffset                 (void) const;
    void            setYOffset              (double yOffset);
    double          yOffset                 (void) const;
    void            setXScale               (double xScale);
    double          xScale                  (void) const;
    void            setYScale               (double yScale);
    double          yScale                  (void) const;
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus copyFrom     (const ZcRxObject* other) override;
    virtual ZcGiDrawable::DrawableType    drawableType() const override;
protected:
	virtual ZSoft::UInt32  subSetAttributes (ZcGiDrawableTraits* pTraits) override;	 

private:
    friend class ZcDbImpImageBackground;
};

class SCENEDLLIMPEXP ZcDbGroundPlaneBackground : public ZcDbBackground
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbGroundPlaneBackground);
    ZcDbGroundPlaneBackground();
    virtual ~ZcDbGroundPlaneBackground();
    void            setColorSkyZenith       (const ZcCmEntityColor & color);
    ZcCmEntityColor colorSkyZenith          (void) const;
    void            setColorSkyHorizon      (const ZcCmEntityColor & color);
    ZcCmEntityColor colorSkyHorizon         (void) const;
    void            setColorUndergroundHorizon  (const ZcCmEntityColor & color);
    ZcCmEntityColor colorUndergroundHorizon     (void) const;
    void            setColorUndergroundAzimuth  (const ZcCmEntityColor & color);
    ZcCmEntityColor colorUndergroundAzimuth     (void) const;
    void            setColorGroundPlaneNear (const ZcCmEntityColor & color);
    ZcCmEntityColor colorGroundPlaneNear    (void) const;
    void            setColorGroundPlaneFar  (const ZcCmEntityColor & color);
    ZcCmEntityColor colorGroundPlaneFar     (void) const;
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler)	override;
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const	override;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler)	override;
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const	override;

    virtual Zcad::ErrorStatus copyFrom     (const ZcRxObject* other)	override;
    virtual ZcGiDrawable::DrawableType    drawableType() const	override;
protected:
	virtual ZSoft::UInt32  subSetAttributes (ZcGiDrawableTraits* pTraits)	override;	 
private:
    friend class ZcDbImpGroundPlaneBackground;
};

class SCENEDLLIMPEXP ZcDbSkyBackground : public ZcDbBackground
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSkyBackground);
    ZcDbSkyBackground();
    virtual ~ZcDbSkyBackground();
    Zcad::ErrorStatus         setSunId     (ZcDbObjectId sunId);
    ZcDbObjectId              sunId        (void) const;
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus copyFrom     (const ZcRxObject* other) override;
    virtual ZcGiDrawable::DrawableType    drawableType() const override;
protected:
	virtual ZSoft::UInt32  subSetAttributes (ZcGiDrawableTraits* pTraits) override;	 
private:
    friend class ZcDbImpSkyBackground;
};


class SCENEDLLIMPEXP ZcDbIBLBackground : public ZcDbBackground
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbIBLBackground);

	ZcDbIBLBackground();

	virtual ~ZcDbIBLBackground();

	virtual ZcGiDrawable* drawable() override;

	virtual Zcad::ErrorStatus setEnable               (const bool bEnable);

	virtual bool              enable                  (void) const;

	virtual Zcad::ErrorStatus setIBLImageName         (const ZcString& name);

	virtual ZcString          IBLImageName            (void) const;

	virtual Zcad::ErrorStatus setRotation             (const double rotation);

	virtual double            rotation                (void) const;

	virtual Zcad::ErrorStatus setDisplayImage         (const bool bdisplay);

	virtual bool              displayImage            (void) const;

	virtual Zcad::ErrorStatus setSecondaryBackground  (const ZcDbObjectId bg);

	virtual ZcDbObjectId      secondaryBackground     (void) const;

	virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler) override;
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
	virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler) override;
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;

	virtual ZcGiDrawable::DrawableType    drawableType() const override;

	virtual bool operator==(const ZcDbIBLBackground& environment);

protected:

	virtual ZSoft::UInt32 subSetAttributes(ZcGiDrawableTraits* pTraits) override;
};


#pragma pack (pop)
