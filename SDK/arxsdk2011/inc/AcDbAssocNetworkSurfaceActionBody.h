
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
// CREATED BY: Tom Ball                                 August 2009
//
// DESCRIPTION:
//
//////////////////////////////////////////////////////////////////////////////

#pragma once
#include "AcDbAssocPathBasedSurfaceActionBody.h"
#include "AcDbAssocLoftedSurfaceActionBody.h"
#pragma pack (push, 8)


/// <summary>
/// Action that sets the contents of AcDbLoftedSurface entity created by surface network operation 
/// </summary>
///
class ACDB_PORT AcDbAssocNetworkSurfaceActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocNetworkSurfaceActionBody);

    /// <summary> Default constructor. </summary>
    /// <param name="createImpObject"> See AcDbAssocCreateImpObject explanation. </param>
    ///
    explicit AcDbAssocNetworkSurfaceActionBody(AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

    /// <summary> 
    /// Get continuity of a specified profile that used to create the resulting network surface
    /// </summary>
    /// <param name="type">  Specify which profile to get continuity. </param>
    /// <param name="continuity">  Returned continuity, can be 0(G0), 1(G1), 2(G2). </param>
    /// <param name="expression">  Expression of the parameter, empty string if no expression is being used. </param>
    /// <param name="evaluatorId"> The id of the expression evaluator that is used to parse the expression, empty string if no expression is being used </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    Acad::ErrorStatus getContinuity( AcDbAssocLoftedSurfaceActionBody::ProfileType type, 
        int &continuity, AcString& expression = dummyString(), 
        AcString& evaluatorId = dummyString() ) const;

    /// <summary> 
    /// Set continuity of a specified profile that used to create the resulting network surface
    /// </summary>
    /// <param name="type">  Specify which profile to set continuity. </param>
    /// <param name="continuity">  New continuity value, can be 0(G0), 1(G1), 2(G2). </param>
    /// <param name="expression">  Expression of the parameter, if the value is controlled by other parameters</param>
    /// <param name="evaluatorId"> The id of the expression evaluator that is used to parse the expression, if an expression is used. </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    Acad::ErrorStatus setContinuity( AcDbAssocLoftedSurfaceActionBody::ProfileType type, 
        int continuity, const AcString& expression = AcString(), 
        const AcString& evaluatorId = AcString() );

    /// <summary> 
    /// Get bulge of a specified profile that used to create the resulting network surface
    /// </summary>
    /// <param name="type">  Specify which profile to get bulge. </param>
    /// <param name="bulge">  Returned bulge. </param>
    /// <param name="expression">  Expression of the parameter, empty string if no expression is being used. </param>
    /// <param name="evaluatorId"> The id of the expression evaluator that is used to parse the expression, empty string if no expression is being used </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    Acad::ErrorStatus getBulge( AcDbAssocLoftedSurfaceActionBody::ProfileType type, 
        double &bulge, AcString& expression = dummyString(), 
        AcString& evaluatorId = dummyString() ) const;

    /// <summary> 
    /// Set bulge of a specified profile that used to create the resulting network surface
    /// </summary>
    /// <param name="type">  Specify which profile to set bulge. </param>
    /// <param name="bulge">  New bulge value. </param>
    /// <param name="expression">  Expression of the parameter, if the value is controlled by other parameters</param>
    /// <param name="evaluatorId"> The id of the expression evaluator that is used to parse the expression, if an expression is used. </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    Acad::ErrorStatus setBulge( AcDbAssocLoftedSurfaceActionBody::ProfileType type, 
        double bulge, const AcString& expression = AcString(), 
        const AcString& evaluatorId = AcString() );

    /// <summary> 
    /// Create an instance of AcDbAssocNetworkSurfaceActionBody
    /// </summary>
    /// <param name="resultingSurfaceId">  Resulting network surface id. </param>
    /// <param name="crossSections">  Array of cross sections that used to create the resulting network surface. </param>
    /// <param name="guideCurves"> Array of guide curves that used to create the resulting network surface. </param>
    /// <param name="continuityArray">  Array of continuity for each cross section and guide curve, the order is the same as the order in cross section array following the order of guide curve array. </param>
    /// <param name="bulgeArray">  Array of bulge for each cross section and guide curve, the order is the same as the order in cross section array following the order of guide curve array. </param>
    /// <param name="bEnabled">  Specify if the action is fully associative. </param>
    /// <param name="createdActionId"> Id of created action. </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    static Acad::ErrorStatus createInstance( const AcDbObjectId& resultingSurfaceId, 
                                             const AcArray<AcDbPathRef>& crossSections,
                                             const AcArray<AcDbPathRef>& guideCurves,
                                             const AcArray<int>& continuityArray,
                                             const AcArray<double>& bulgeArray,
                                             bool bEnabled,
                                             AcDbObjectId& createdActionId);


}; // class AcDbAssocNetworkSurfaceActionBody

#pragma pack (pop)
