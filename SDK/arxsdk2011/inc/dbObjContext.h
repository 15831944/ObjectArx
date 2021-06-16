//
//
// (C) Copyright 2006-2007 by Autodesk, Inc. 
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

#pragma once
#pragma pack(push, 8)

#include "dbmain.h"


////////////////////////////////////////////////////////////////////////
// class AcDbObjectContext
////////////////////////////////////////////////////////////////////////

/// <summary>
/// Abstract base class for representing a particular context which
/// may affect the properties and/or behavior of one or more types
/// of objects.Classes that are derived from this base class are used
/// to represent a particular type of context such as annotation scale.
/// </summary>
///
///
class AcDbObjectContext : public AcRxObject
{
public:

    ACRX_DECLARE_MEMBERS(AcDbObjectContext);

    /// <summary>
    /// Default constructor.
    /// </summary>
    /// 
    AcDbObjectContext ();

    /// <summary>
    /// Destructor.  Performs any necessary cleanup of the context data.
    /// </summary>
    /// 
    virtual ~AcDbObjectContext ();

    /// <summary>
    /// The name of the object context.
    /// </summary>
    /// 
    /// <param name="name">
    /// Output parameter containing the name of the object context.
    /// </param>
    /// 
    /// <returns>
    /// Returns Acad::eOk if succssful.
    /// </returns>
    /// 
    /// <remarks>
    /// The name of an object context may appear in user interface components
    /// visile to the user, and may change if the context supports renaming.
    /// Applications should not identify contexts by name internally but should
    /// use the context ID, which is guaranteed to be unique and invariant over
    /// time. 
    /// </remarks>
    ///
    virtual Acad::ErrorStatus getName ( AcString& name) const = 0;

    /// <summary>
    /// Sets the name of the object context.
    /// </summary>
    /// 
    /// <param name="name">
    /// New name of the object context.
    /// </param>
    /// 
    /// <returns>
    /// Returns Acad::eOk if succssful, returns Acad::eNotImplemented if
    /// the context object does not support renaming. 
    /// </returns>
    ///
    /// <remarks>
    /// Custom object contexts implement this method to support renaming
    /// context object instances.
    /// </remarks>
    virtual Acad::ErrorStatus setName ( const AcString& name ) = 0;

    /// <summary>
    /// The unique context identifier
    /// </summary>
    ///
    /// <returns>
    /// Returns the object context identifier.
    /// </returns>
    /// 
    /// <remarks>
    /// The unique identifier should be invariant for the lifetime of this
    /// object and is unique amongst all instances of the context object type
    /// within an AcDbObjectContextCollection. If an AcDbObjectContext is not
    /// currently resident within a collection then the returned identifier may
    /// not be unique.  Although this property is represented as an
    /// Adesk::LongPtr, it does not have to be a memory or other address and
    /// will not be used as a memory address by core AutoCAD.
    /// </remarks>
    ///
    virtual Adesk::LongPtr uniqueIdentifier () const = 0;

    /// <summary>
    /// The name of the containing collection.
    /// </summary>
    ///
    /// <returns>
    /// Returns the name of the containing collection. 
    /// </returns>
    ///
    /// <remarks>
    /// Context objects should returns a non-null string even if the context
    /// object is not currently residing in a collection. The purpose of this
    /// method is to allow clients to identify the context type via a
    /// collection name, and to allow clients (including collection objects) to
    /// determine whether a context object is allowed in a collection instance. 
    /// </remarks>
    ///
    virtual AcString collectionName () const = 0;
};

#pragma pack(pop)
