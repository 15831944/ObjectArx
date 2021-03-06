

#ifndef   _ZCDBLMGR_H
#define   _ZCDBLMGR_H

#include "zadesk.h"
#include "zdbid.h"
#include "zdblayout.h"
#include "zdblaymgrrctr.h"
#pragma pack (push, 8)

#define  MAX_PSPACE_LAYOUTS     256

class ZcDbObjectId;

class ZcDbLayoutManager: public ZcRxObject  {
  public:
    virtual Zcad::ErrorStatus
        setCurrentLayout        (const ZTCHAR * newname, ZcDbDatabase* pDb = NULL) = 0;
    virtual Zcad::ErrorStatus
        setCurrentLayoutId      (ZcDbObjectId layoutId) = 0;
    
    virtual Zcad::ErrorStatus   
		getActiveLayoutName(ZcString & sName, bool allowModel, const ZcDbDatabase* pDb = nullptr) = 0;  

	ZCDBCORE2D_PORT virtual const ZTCHAR *
		findActiveLayout(bool allowModel, const ZcDbDatabase* pDb = nullptr) final;
	
	virtual ZcDbObjectId
		getActiveLayoutBTRId    (const ZcDbDatabase* pDb = NULL) = 0;

	virtual ZcDbObjectId
		findLayoutNamed         (const ZTCHAR* name,
		const ZcDbDatabase* pDb = NULL) = 0;

	ZCDBCORE2D_PORT Zcad::ErrorStatus
        getLayoutNamed          (const ZTCHAR* name,
                                 ZcDbLayout*& pLayout,
                                 ZcDb::OpenMode mode = ZcDb::kForRead,
                                 const ZcDbDatabase* pDb = nullptr);
	ZCDBCORE2D_PORT bool
        layoutExists            (const ZTCHAR* name,
                                 const ZcDbDatabase* pDb = nullptr);

	virtual Zcad::ErrorStatus
		copyLayout              (const ZTCHAR * copyname,
								 const ZTCHAR * newname,
                                 ZcDbDatabase* pDb = NULL) = 0;

	virtual Zcad::ErrorStatus
		deleteLayout            (const ZTCHAR * delname,
                                 ZcDbDatabase* pDb = NULL) = 0;

    virtual Zcad::ErrorStatus
        createLayout            (const ZTCHAR *newname,
                                 ZcDbObjectId& layoutId,
                                 ZcDbObjectId& blockTableRecId,
                                 ZcDbDatabase* pDatabase = NULL) = 0;

	virtual Zcad::ErrorStatus
        renameLayout            (const ZTCHAR * oldname,
                                 const ZTCHAR * newname,
                                 ZcDbDatabase* pDb = NULL) = 0;

	virtual Zcad::ErrorStatus
		cloneLayout             (ZcDbLayout* pLBTR,
								const ZTCHAR * newname,
								int newTabOrder = 0,
                                 ZcDbDatabase* pDb = NULL) = 0;

    virtual ZcDbObjectId
        getNonRectVPIdFromClipId (ZcDbObjectId clipId) = 0;

    virtual bool
        isVpnumClipped          (int index, const ZcDbDatabase* pDb = NULL) = 0;

    virtual int
        countLayouts            (ZcDbDatabase *useDb = NULL) = 0;

    virtual void
        addReactor              (ZcDbLayoutManagerReactor * newObj) = 0;

    virtual void
        removeReactor           (ZcDbLayoutManagerReactor * delObj) = 0;
};

Zcad::ErrorStatus zcdbDoSetupForLayouts(ZcDbDatabase* pDatabase,
                                        ZSoft::ULongPtr& contextHandle);

Zcad::ErrorStatus zcdbClearSetupForLayouts(ZSoft::ULongPtr contextHandle);

#pragma pack (pop)
#endif 
