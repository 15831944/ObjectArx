

#ifndef ZD_DBCOLOR_H
#define ZD_DBCOLOR_H 1

#include "zadesk.h"
#include "zacadstrc.h"
#include "zrxobject.h"
#include "zAcDbCore2dDefs.h"

#pragma pack (push, 8)

class ZcCmEntityColor;

class ZCDBCORE2D_PORT ZcCmEntityColor
{
public:
    enum Color { kRed,
                 kGreen,
                 kBlue
    };

    enum ColorMethod {   kByLayer =0xC0, 
                         kByBlock,
                         kByColor,
                         kByACI,
                         kByPen,
                         kForeground,
                         kLayerOff,
                         
                         kLayerFrozen,
                         kNone
    };

    enum ACIcolorMethod {kACIbyBlock    = 0,
                         kACIforeground = 7,
                         kACIbyLayer    = 256,
                         
                         kACIclear      = 0,    
                         kACIstandard   = 7,
                         kACImaximum    = 255,
                         kACInone       = 257,
                         kACIminimum    = -255,
                         kACIfrozenLayer= -32700
    };

public:
    union RGBM {
        ZSoft::UInt32    whole;
        ZSoft::Int16     indirect;
        struct {
            ZSoft::UInt8 blue, 
                         green, 
                         red, 
                         colorMethod;
        }mdata;
		
		ZSoft::Int32    mnIndirect32;
		ZSoft::Int32    indirect24() const;
		
    };

public:
    ZcCmEntityColor     ();
    ZcCmEntityColor     (const ZcCmEntityColor & color);	
    ZcCmEntityColor     (ColorMethod eColorMethod);
    ZcCmEntityColor     (ZSoft::UInt8 red, 
						 ZSoft::UInt8 green, 
						 ZSoft::UInt8 blue);	
    ZcCmEntityColor&    operator =  (const ZcCmEntityColor& color);
    bool                operator == (const ZcCmEntityColor& color) const;
    bool                operator != (const ZcCmEntityColor& color) const;

    Zcad::ErrorStatus   setColorMethod  (ColorMethod eColorMethod);
    ColorMethod         colorMethod     () const;

    Zcad::ErrorStatus   setColor        ( ZSoft::UInt32 color);
    ZSoft::UInt32       color           () const;   

    Zcad::ErrorStatus   setColorIndex   (ZSoft::Int16 colorIndex);
    ZSoft::Int16        colorIndex      () const;

    Zcad::ErrorStatus   setLayerIndex   (ZSoft::Int32 layerIndex);
    ZSoft::Int32        layerIndex      () const;   

    Zcad::ErrorStatus   setPenIndex     (ZSoft::UInt16 penIndex);
    ZSoft::UInt16       penIndex        () const;

    Zcad::ErrorStatus   setRGB  (ZSoft::UInt8 red, 
                                 ZSoft::UInt8 green, 
                                 ZSoft::UInt8 blue);
    Zcad::ErrorStatus   setRed  (ZSoft::UInt8 red);
    Zcad::ErrorStatus   setGreen(ZSoft::UInt8 green);
    Zcad::ErrorStatus   setBlue (ZSoft::UInt8 blue);
    ZSoft::UInt8        red     () const;
    ZSoft::UInt8        green   () const;
    ZSoft::UInt8        blue    () const;

    bool                isByColor   () const;
    bool                isByLayer   () const;
    bool                isByBlock   () const;
    bool                isByACI     ()   const;
    bool                isByPen     ()  const;
    bool                isForeground() const;
    bool                isLayerOff  () const;
    
    bool                isLayerFrozen() const;
    bool                isNone      ()   const;
    bool                isLayerFrozenOrOff() const;

    ZSoft::UInt32       trueColor () const;
    ZSoft::UInt8        trueColorMethod () const;
    Zcad::ErrorStatus   setTrueColor ();
    Zcad::ErrorStatus   setTrueColorMethod ();

    static  Zcad::ErrorStatus   setColorMethod(RGBM* rgbm, ColorMethod eColorMethod);
    static  ColorMethod         colorMethod   (const RGBM* rgbm);

    static  Zcad::ErrorStatus   setColor      (RGBM* rgbm, ZSoft::UInt32 color);
    static  ZSoft::UInt32       color         (const RGBM* rgbm);   
	
    static Zcad::ErrorStatus   setColorIndex (RGBM* rgbm, ZSoft::Int16 colorIndex); 
    static  ZSoft::Int16        colorIndex    (const RGBM* rgbm);

    static Zcad::ErrorStatus   setLayerIndex (RGBM* rgbm, ZSoft::Int32 layerIndex);
    static  ZSoft::Int32       layerIndex    (const RGBM* rgbm);   

    static Zcad::ErrorStatus   setPenIndex   (RGBM* rgbm, ZSoft::UInt16 penIndex); 
    static  ZSoft::UInt16       penIndex      (const RGBM* rgbm);

    static Zcad::ErrorStatus    setRGB  (RGBM* rgbm,
                                          ZSoft::UInt8 red, 
                                          ZSoft::UInt8 green, 
                                          ZSoft::UInt8 blue);
    static Zcad::ErrorStatus    setRed  (RGBM* rgbm,  ZSoft::UInt8 red);
    static Zcad::ErrorStatus    setGreen(RGBM* rgbm,  ZSoft::UInt8 green);
    static Zcad::ErrorStatus    setBlue (RGBM* rgbm,  ZSoft::UInt8 blue);
    static ZSoft::UInt8         red     (const RGBM* rgbm);
    static ZSoft::UInt8         green   (const RGBM* rgbm);
    static ZSoft::UInt8         blue    (const RGBM* rgbm);

    static  bool                isByColor   (const RGBM* rgbm);
    static  bool                isByLayer   (const RGBM* rgbm);
    static  bool                isByBlock   (const RGBM* rgbm);
    static  bool                isByACI     (const RGBM* rgbm);
    static  bool                isByPen     (const RGBM* rgbm);
    static  bool                isForeground(const RGBM* rgbm);
    static  bool                isLayerOff  (const RGBM* rgbm);
    
    static  bool                isLayerFrozen(const RGBM* rgbm);
    static  bool                isNone      (const RGBM* rgbm);

    static ZSoft::UInt32        trueColor       (const RGBM* rgbm);
   static ZSoft::UInt8         trueColorMethod ( ZSoft::Int16);	 
    static Zcad::ErrorStatus    setTrueColor    (RGBM* rgbm);
    static Zcad::ErrorStatus    setTrueColorMethod (RGBM* rgbm);

    static ZSoft::UInt32        lookUpRGB       ( ZSoft::UInt8 colorIndex);
    static ZSoft::UInt8         lookUpACI       ( ZSoft::UInt8 red,
												  ZSoft::UInt8 green,
												  ZSoft::UInt8 blue); 
protected:
    RGBM mRGBM;

public:

    static const ZSoft::UInt8 mLUT[256][3]; 
};

inline 
ZcCmEntityColor::ZcCmEntityColor()
{
    mRGBM.whole = 0;
    mRGBM.mdata.colorMethod = kByColor;
}

inline
ZcCmEntityColor::ZcCmEntityColor(const ZcCmEntityColor & color)
{
    mRGBM.whole = color.mRGBM.whole;
}

inline 
ZcCmEntityColor::ZcCmEntityColor(ColorMethod eColorMethod)
{
    mRGBM.whole = 0;
    mRGBM.mdata.colorMethod = static_cast<ZSoft::UInt8>(eColorMethod);
}

inline  
ZcCmEntityColor::ZcCmEntityColor( ZSoft::UInt8 red, 
                                 ZSoft::UInt8 green, 
                                 ZSoft::UInt8 blue)	
{
    mRGBM.mdata.red   = red;
    mRGBM.mdata.green = green;
    mRGBM.mdata.blue  = blue;
    mRGBM.mdata.colorMethod = kByColor;
}

inline ZcCmEntityColor& 
ZcCmEntityColor::operator= (const ZcCmEntityColor & color)
{
    mRGBM.whole = color.mRGBM.whole;
    return *this;
}

inline bool
ZcCmEntityColor::operator==(const ZcCmEntityColor& color) const
{
    return mRGBM.whole == color.mRGBM.whole;
}

inline bool
ZcCmEntityColor::operator!=(const ZcCmEntityColor& color) const
{
    return mRGBM.whole != color.mRGBM.whole;
}

inline ZcCmEntityColor::ColorMethod     
ZcCmEntityColor::colorMethod() const
{
    return (ColorMethod) mRGBM.mdata.colorMethod;
}

inline ZSoft::UInt32    
ZcCmEntityColor::color () const
{
    return mRGBM.whole;
}

inline ZSoft::UInt8    
ZcCmEntityColor::red  () const
{
    return mRGBM.mdata.red;
}

inline ZSoft::UInt8
ZcCmEntityColor::green() const
{
    return mRGBM.mdata.green;
}

inline ZSoft::UInt8    
ZcCmEntityColor::blue () const
{
    return mRGBM.mdata.blue;
}

inline bool
ZcCmEntityColor::isByColor() const
{
    return mRGBM.mdata.colorMethod == kByColor; 
}

inline bool
ZcCmEntityColor::isByLayer() const
{
    return (mRGBM.mdata.colorMethod  == kByLayer ||
            (mRGBM.mdata.colorMethod == kByACI   && 
             mRGBM.indirect    == kACIbyLayer)) ? true : false;    
}

inline bool
ZcCmEntityColor::isByBlock() const
{
    return (mRGBM.mdata.colorMethod  == kByBlock ||
            (mRGBM.mdata.colorMethod == kByACI   && 
             mRGBM.indirect    == kACIbyBlock)) ? true : false;    
}

inline bool
ZcCmEntityColor::isByACI()   const
{
    return mRGBM.mdata.colorMethod == kByACI;
}

inline bool
ZcCmEntityColor::isByPen()   const
{
    return mRGBM.mdata.colorMethod == kByPen;
}

inline bool
ZcCmEntityColor::isForeground()   const
{
    return (mRGBM.mdata.colorMethod  == kForeground ||
            (mRGBM.mdata.colorMethod == kByACI      && 
             mRGBM.indirect    == kACIforeground)) ? true : false;    
}

inline bool
ZcCmEntityColor::isLayerOff() const
{   
    return (mRGBM.mdata.colorMethod  == kLayerOff ||
            (mRGBM.mdata.colorMethod == kByACI && 
             mRGBM.indirect    <  0      && 
             mRGBM.indirect    != kACIfrozenLayer)) ? true : false;    
}

inline bool
ZcCmEntityColor::isLayerFrozen() const
{   
    return (mRGBM.mdata.colorMethod  == kLayerFrozen ||
            (mRGBM.mdata.colorMethod == kByACI       && 
             mRGBM.indirect    == kACIfrozenLayer)) ? true : false;    
}

inline bool
ZcCmEntityColor::isLayerFrozenOrOff() const
{
    return isLayerFrozen() || isLayerOff();
}

inline bool
ZcCmEntityColor::isNone()   const
{
    return (mRGBM.mdata.colorMethod  == kNone ||
            (mRGBM.mdata.colorMethod == kByACI       && 
             mRGBM.indirect    == kACInone)) ? true : false;    
}

class ZCDB_PORT ZSOFT_NO_VTABLE ZcCmColorBase
{
public:

    virtual ~ZcCmColorBase() {}

    virtual ZcCmEntityColor::ColorMethod  colorMethod() const = 0;;
    virtual Zcad::ErrorStatus   setColorMethod(ZcCmEntityColor::ColorMethod eColorMethod) = 0;

    virtual bool                isByColor() const = 0;
    virtual bool                isByLayer() const = 0;
    virtual bool                isByBlock() const = 0;
    virtual bool                isByACI()   const = 0;
    virtual bool                isByPen () const = 0;
    virtual bool                isForeground()   const = 0;

    virtual ZSoft::UInt32       color() const = 0;
    virtual Zcad::ErrorStatus   setColor(ZSoft::UInt32 color) = 0;

    virtual Zcad::ErrorStatus   setRGB  (ZSoft::UInt8 red, 
                                         ZSoft::UInt8 green, 
                                         ZSoft::UInt8 blue) = 0;
    virtual Zcad::ErrorStatus   setRed  (ZSoft::UInt8 red) = 0;
    virtual Zcad::ErrorStatus   setGreen(ZSoft::UInt8 green) = 0;
    virtual Zcad::ErrorStatus   setBlue (ZSoft::UInt8 blue) = 0;
    virtual ZSoft::UInt8        red  () const = 0;
    virtual ZSoft::UInt8        green() const = 0;
    virtual ZSoft::UInt8        blue () const = 0;

    virtual ZSoft::UInt16       colorIndex() const = 0;
    virtual Zcad::ErrorStatus   setColorIndex(ZSoft::UInt16 colorIndex) = 0;
    virtual ZSoft::UInt16       penIndex() const = 0;
    virtual Zcad::ErrorStatus   setPenIndex (ZSoft::UInt16 penIndex) = 0;

    virtual Zcad::ErrorStatus   setNames(const ZTCHAR *colorName,
                                         const ZTCHAR *bookName = NULL) = 0;
    virtual const ZTCHAR *       colorName(void) const = 0;
    virtual const ZTCHAR *       bookName(void) const = 0;
    virtual const ZTCHAR *       colorNameForDisplay(void) = 0;
    virtual bool                hasColorName(void) const = 0;
    virtual bool                hasBookName(void) const = 0;

};

class ZCDB_PORT ZcCmTransparency {
public:

    enum transparencyMethod {
                kByLayer = 0,
                kByBlock,
                kByAlpha,

                kErrorValue     
            };

    enum {  kTransparencyByLayer    = (unsigned long)kByLayer,
            kTransparencyByBlock    = (unsigned long)kByBlock,
            kTransparencySolid      = ((unsigned long)(kByAlpha | (0xff << 24))),
            kTransparencyClear      = (unsigned long)kByAlpha
    };

    ZcCmTransparency() { mAM.whole = kTransparencyByLayer; }
	
	ZcCmTransparency(ZSoft::UInt8 alpha);
	ZcCmTransparency(double alphaPercent);
	
    ZcCmTransparency(const ZcCmTransparency& other) { mAM.whole = other.mAM.whole; }
    ~ZcCmTransparency() {}

    ZcCmTransparency& operator=(const ZcCmTransparency& other);
    bool operator==(const ZcCmTransparency& other) const;
    bool operator!=(const ZcCmTransparency& other) const;

    void setAlpha(ZSoft::UInt8 alpha);
	void setAlphaPercent(double alphaPercent);	

    void setMethod(transparencyMethod method);

    ZSoft::UInt8 alpha(void) const;
	double alphaPercent(void) const;	

    bool isByAlpha(void) const { return (mAM.mdata.method == kByAlpha); }
    bool isByBlock(void) const { return (mAM.mdata.method == kByBlock); }
    bool isByLayer(void) const { return (mAM.mdata.method == kByLayer); }
	bool isInvalid(void) const { return (mAM.mdata.method == kErrorValue); }
    bool isClear(void) const;
    bool isSolid(void) const;

    ZSoft::UInt32   serializeOut(void) const { return mAM.whole; }
    void            serializeIn(ZSoft::UInt32);

private: 

    union AM {
        struct {
            ZSoft::UInt8    alpha;          
            ZSoft::UInt8    reserved1;    
            ZSoft::UInt8    reserved2;
            ZSoft::UInt8    method;         
        }mdata;
        ZSoft::UInt32       whole;
    };

    AM mAM;
};

namespace ZcCm
{
    enum DialogTabs
    {   
        
        kACITab = 1,
        kTrueColorTab = 2,
        kColorBookTab = 4,
    };

    enum ACIColors
    {
        kACIByBlock     = 0,
        kACIRed         = 1,
        kACIYellow      = 2,
        kACIGreen       = 3,
        kACICyan        = 4,
        kACIBlue        = 5,
        kACIMagenta     = 6,
        kACIForeground  = 7,
        kACIByLayer     = 256,
    };
}

#pragma pack (pop)
#define ZSOFT_ZCCMENTITYCOLOR_DEFINED
#include "zacarrayhelper.h"

#endif 
