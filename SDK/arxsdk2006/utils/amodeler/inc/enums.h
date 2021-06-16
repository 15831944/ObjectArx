#ifndef AMODELER_INC_ENUMS_H
#define AMODELER_INC_ENUMS_H


///////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright 2002 by Autodesk, Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//
// DESCRIPTION:
//
// Some popular enums.
//
///////////////////////////////////////////////////////////////////////////////

#include "global.h"

AMODELER_NAMESPACE_BEGIN

enum BoolOperType
{
    kBoolOperUnite,
    kBoolOperSubtract,
    kBoolOperIntersect
};

enum BodyInterferenceType
{
    kBodiesDoNotInterfere,
    kBodiesTouch,
    kBodiesInterfere
};

enum PointInBodyLocation
{
    kPointOutsideBody,
    kPointAtVertex,
    kPointOnEdge,
    kPointInFace,
    kPointInsideBody
};

enum HiddenLinesDisplay
{
    kHiddenLinesInvisible,
    kHiddenLinesDashed,
    kHiddenLinesVisible
};

enum HiddenLineDrawingImprove
{
    kNoDrawingImprove,
    kConnectDrawingImprove,
    kArcReconstructDrawingImprove
};

enum TriangulationType
{
    kGenerateTriangles,
    kGenerateQuadrilaterals,
    kGenerateTriStrips,
    kGenerateTriStripsPerSurface
};

enum RayBodyIntersection
{
    kRayDoesNotIntersect,
    kRayPointAtVertex,
    kRayPointOnEdge,
    kRayPointInFace,
    kRayIntersectsVertex,
    kRayIntersectsEdge,
    kRayIntersectsFace
};


AMODELER_NAMESPACE_END
#endif

