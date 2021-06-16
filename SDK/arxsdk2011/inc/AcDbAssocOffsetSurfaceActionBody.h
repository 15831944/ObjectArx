
//////////////////////////////////////////////////////////////////////////////
//
// Copyright � 2009-2010 by Autodesk, Inc. 
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
// CREATED BY: Pei Zhan                                 March 2009
//
// DESCRIPTION:
//
//////////////////////////////////////////////////////////////////////////////

#pragma once
#include "AcDbAssocSurfaceActionBody.h"
#pragma pack (push, 8)


/// <summary>
/// Action that sets the contents of AcDbSurface entity create by surface offset operation.
/// The action can be fully associative or semi-associative. If fully associative, the resulting 
/// surface will always automatically regenerate when any input data is changed. If semi-associative, 
/// when the geometry of input surfaces is changed, this action will be erased and 
/// the resulting surface will not regenerate and become a generic surface.
/// </summary>
///
class ACDB_PORT AcDbAssocOffsetSurfaceActionBody : public AcDbAssocSurfaceActionBody
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocOffsetSurfaceActionBody);

    /// <summary> Default constructor. </summary>
    /// <param name="createImpObject"> See AcDbAssocCreateImpObject explanation. </param>
    ///
    explicit AcDbAssocOffsetSurfaceActionBody(AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

    /// <summary><para> 
    /// Set offset distance
    /// </para><para>
    /// the same parameter can be set through class AcDbAssocParamBasedActionBody by calling method 
    /// setValueParam with name "kOffsetDistanceParamName". 
    /// <param name="distance">  New value of the extension distance, must be non-zero. </param>
    /// <param name="expression">  Expression of the parameter, if the value is controlled by other parameters</param>
    /// <param name="evaluatorId"> The id of the expression evaluator that is used to parse the expression, if an expression is used. </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    Acad::ErrorStatus setDistance(double distance, const AcString& expression = AcString(), 
        const AcString& evaluatorId = AcString());

    /// <summary><para> 
    /// Get offset distance and its possible expression
    /// </para><para>
    /// the same parameter can be accessed through class AcDbAssocParamBasedActionBody by calling method 
    /// getValueParam with name "kOffsetDistanceParamName". 
    /// </para></summary>
    /// <param name="expression">  Expression of the parameter, empty string if no expression is being used. </param>
    /// <param name="evaluatorId"> The id of the expression evaluator that is used to parse the expression, empty string if no expression is being used </param>
    /// <returns> Offset distance. </returns>
    ///
    double distance(AcString& expression = dummyString(), AcString& evaluatorId = dummyString()) const;

    /// <summary> 
    /// Create an instance of AcDbAssocOffsetSurfaceActionBody
    /// </summary>
    /// <param name="resultingSurfaceId">  Resulting offset surface id. </param>
    /// <param name="inputSurfaceId1">  Id of input surface that used to create the new offset surface. </param>
    /// <param name="distance">  Offset distance that used to create the new offset surface. </param>
    /// <param name="createdActionId"> Id of created action. </param>
    /// <param name="bEnabled">  Specify if the action is fully associative. if True, the resulting surface will
    /// always automatically regenerate itself when input data is changed. If false, it will be 
    /// semi-associative, which means when the geometry input surface is changed, this 
    /// action will be erased and the resulting surface will not regenerate and become a generic surface. </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    static Acad::ErrorStatus createInstance( const AcDbObjectId& resultingSurfaceId,
                                             const AcDbObjectId& inputSurfaceId,
                                             double distance,
                                             bool bEnabled,
                                             AcDbObjectId& createdActionId);


}; // class AcDbAssocOffsetSurfaceActionBody

#pragma pack (pop)
