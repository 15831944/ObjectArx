

#ifndef ZC_GELINE3D_H
#define ZC_GELINE3D_H

#include "zgelent3d.h"
#pragma pack (push, 8)

class ZcGeLine2d;

class
ZcGeLine3d : public ZcGeLinearEnt3d
{
public:
    GE_DLLEXPIMPORT ZcGeLine3d();
    GE_DLLEXPIMPORT ZcGeLine3d(const ZcGeLine3d& line);
    GE_DLLEXPIMPORT ZcGeLine3d(const ZcGePoint3d& pnt, const ZcGeVector3d& vec);
    GE_DLLEXPIMPORT ZcGeLine3d(const ZcGePoint3d& pnt1, const ZcGePoint3d& pnt2);

    GE_DLLDATAEXIMP static const ZcGeLine3d kXAxis;
    GE_DLLDATAEXIMP static const ZcGeLine3d kYAxis;
    GE_DLLDATAEXIMP static const ZcGeLine3d kZAxis;

    GE_DLLEXPIMPORT ZcGeLine3d& set(const ZcGePoint3d& pnt, const ZcGeVector3d& vec);
    GE_DLLEXPIMPORT ZcGeLine3d& set(const ZcGePoint3d& pnt1, const ZcGePoint3d& pnt2);

    GE_DLLEXPIMPORT ZcGeLine3d& operator = (const ZcGeLine3d& line);
};

#pragma pack (pop)
#endif
