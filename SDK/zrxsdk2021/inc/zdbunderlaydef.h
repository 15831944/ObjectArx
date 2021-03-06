
#ifndef ZCDB_DBUNDERLAYDEF_H
#define ZCDB_DBUNDERLAYDEF_H

#pragma once

#include "zdbmain.h"
#include "zacstring.h"

#pragma pack (push, 8)

class ZcDbUnderlayItem;
class ZcDbUnderlayHost;
class IZcReadStream;

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbUnderlayDefinition: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbUnderlayDefinition);

    ZcDbUnderlayDefinition();

    virtual ~ZcDbUnderlayDefinition() = 0;
    Zcad::ErrorStatus setSourceFileName(const ZTCHAR* file);
    const ZTCHAR* getSourceFileName() const;
    IZcReadStream* getReadStream() const;
    Zcad::ErrorStatus getActiveFileName(const ZTCHAR*& file) const;
    Zcad::ErrorStatus getActiveFileName(ZcString& file) const;
    Zcad::ErrorStatus setItemName(const ZTCHAR* item);
    const ZTCHAR* getItemName() const;
    Zcad::ErrorStatus setUnderlayItem(const ZTCHAR* sourceFileName, const ZTCHAR* activeFileName, ZcDbUnderlayItem* pItem);
    const ZcDbUnderlayItem* getUnderlayItem() const;
    Zcad::ErrorStatus load(const wchar_t* password);
    void unload();
    bool isLoaded() const;
    static ZcString dictionaryKey(const ZcRxClass* underlayDefinitionType);
private:
    virtual const ZcDbUnderlayHost* getUnderlayHost() const = 0;
};

class ZCDBCORE2D_PORT ZcDbDwfDefinition: public ZcDbUnderlayDefinition
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDwfDefinition);

    ZcDbDwfDefinition();

    virtual ~ZcDbDwfDefinition();
    
    ZSoft::Boolean isDWFx(void) const;
private:
    virtual  const ZcDbUnderlayHost* getUnderlayHost() const override;
};

class ZcDbDgnDefinition: public ZcDbUnderlayDefinition
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDgnDefinition);

    ZcDbDgnDefinition();

    virtual ~ZcDbDgnDefinition();
    bool useMasterUnits() const;
    void setUseMasterUnits(bool useMaster);
    int xrefDepth() const;
    void setXrefDepth(int depth);
    bool showRasterRef() const;
    void setShowRasterRef(bool bShow);
private:
    virtual const ZcDbUnderlayHost* getUnderlayHost() const override;

};

class ZCDBCORE2D_PORT ZcDbPdfDefinition: public ZcDbUnderlayDefinition
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbPdfDefinition);

	ZcDbPdfDefinition();

	virtual ~ZcDbPdfDefinition();
private:
    virtual  const ZcDbUnderlayHost* getUnderlayHost() const override;
};

#pragma pack (pop)

#endif
