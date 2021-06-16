//
//  Copyright 2004 by Autodesk, Inc.
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
// AcDMMEPlotProperties.h
// the proxy EPlotProperties object
//
#ifndef AcDMMEPlotProperties_h
#define AcDMMEPlotProperties_h

#include "AcDMMEPlotProperty.h"
#include "AcDMMUtils.h"

/////////////////////////////////////////////////////////////////////
// class AcDMMEPlotProperties
/////////////////////////////////////////////////////////////////////

/// <summary>
/// This class is a lighweight proxy for the DWF EPlotProperties class which is
/// used by the DMM (DWF Metadata Manager) API to allow clients to
/// associate entity properties with DWF geometry without linking to
/// the DWF toolkit. This class contains the data but not the behavior
/// of the corresponding DWF toolkit object. 
/// </summary>
///
/// <remarks>
/// Note that all strings are Unicode. XML encoding will be done by the
/// DMM when the proxy object is converted to the corresponding DWF
/// toolkit object.
/// </remarks>
///
class AcDMMEPlotProperties
{
public:

    /// <summary>
    /// Default constructor
    /// </summary>
    ///
    /// <remarks>
    /// Constructs an empty AcDMMEPlotProperties object.
    /// </remarks>
    ///
    AcDMMEPlotProperties()
        : m_id(NULL),
          m_namespaceUrl(NULL),
          m_namespaceLocation(NULL)
    {

    }

    /// <summary>
    /// Copy constructor
    /// </summary>
    ///
    /// <param name="src">
    /// the object to be copied
    /// </param>
    ///
    AcDMMEPlotProperties(const AcDMMEPlotProperties &src)
        : m_id(NULL),
          m_namespaceUrl(NULL),
          m_namespaceLocation(NULL)
    { 
        *this = src;
    }

    /// <summary>
    /// Destructor
    /// </summary>
    ///
    ~AcDMMEPlotProperties()
    {
        m_properties.clear();
        m_refs.clear();
        if (NULL != m_id)
            delete m_id;
        if (NULL != m_namespaceUrl)
            delete m_namespaceUrl;
        if (NULL != m_namespaceLocation)
            delete m_namespaceLocation;
    }


    /// <summary>
    /// Adds a new AcDMMEPlotProperty object to the internal vector of 
    /// properties
    /// </summary>
    ///
    /// <param name="property">
    /// the property to be added to this Properties list
    /// </param>
    ///
    void AddProperty(const AcDMMEPlotProperty * property)
    {
        if (NULL == property)
            return;
        m_properties.push_back(*property);
    }

    /// <summary>
    /// Creates and adds a new AcDMMEPlotProperty object to the internal 
    /// vector of properties.
    /// </summary>
    ///
    /// <param name="name">
    /// the new property's name
    /// </param>
    ///
    /// <param name="value">
    /// the new property's value
    /// </param>
    ///
    void AddProperty(wchar_t * name, wchar_t *value)
    {
        AcDMMEPlotProperty newProp(name, value);
        m_properties.push_back(newProp);
    }

    /// <summary>
    /// accessor for the internal vector of AcDMMEPlotProperty objects
    /// contained by this object
    /// </summary>
    ///
    /// <returns>
    /// Returns a const reference to the internal Vector of 
    /// AcDMMEPlotProperty objects contained by this object
    /// </returns>
    const AcDMMEPlotPropertyVec& GetProperties() const
    {
        return m_properties;
    }

    /// <summary>
    /// accessor for individual properties in the internal vector of
    /// AcDMMEPlotProperties contained in this object
    /// </summary>
    ///
    /// <param name="index">
    /// the one based index of the desired property
    /// </param>
    ///
    /// <returns>
    /// Returns a const pointer to the EPlotProperty object at the given 
    /// 1-based index.
    /// </returns>
    ///
    /// <remarks>
    /// warning - May overflow the internal Vector array.  Clients should 
    /// check GetProperties().size() before calling this method.
    /// </remarks>
    /// 
    const AcDMMEPlotProperty * GetProperty(unsigned long index) const
    {
        if (m_properties.size() < index)
            return NULL;
        return &m_properties[index];
    }

    /// <summary>
    /// mutator for the Id attribute of this object
    /// </summary>
    ///
    /// <param name="id">
    /// the Unicode unique identifier the client assigns to this object.
    /// </param>
    ///
    /// <remarks>
    /// The unique identifier for this EPlotProperties element (can be 
    /// a name, a GUID, etc.). It is preferred for this string to be
    /// prefixed with the client application name to distinguish its
    /// properties from those of other clients
    /// The EPlotProperties element, when used in an ObjectDefinition resource,
    /// can be referenced by other "child" EPlotProperties elements, thereby 
    /// creating an efficient hierarchy of properties.
    /// WARNING - these Ids are processed in a space delimited list. Your
    /// properties will not behave as expected if the Id contains spaces.
    /// </remarks>
    void AcDMMEPlotProperties::SetId(const wchar_t * id)
    {
        if (NULL != m_id)
            delete m_id;
        if (NULL != id) {
            m_id = new wchar_t[::wcslen(id) + 1];
            ::wcscpy(m_id, id);
        } else
            m_id = NULL;
    }

    /// <summary>
    /// accessor for the Id attribute.
    /// </summary>
    /// 
    /// <returns>
    /// returns a const pointer to the Unicode string which is the unique
    /// identifier assigned by the client to this object.
    /// </returns>
    ///
    /// <remarks>
    /// Returns the unique identifier for this AcDMMEPlotProperties element.
    /// </remarks> 
    const wchar_t * GetId() const
    {
        return m_id;
    }

    /// <summary>
    /// mutator for the Xml namespace for this object and its children
    /// </summary>
    ///
    /// <param name="url">
    /// universal resource locator string
    /// </param>
    ///
    /// <param name="location">
    /// a location value, may be an url or a key to lookup the url in a
    /// schema.
    /// </param>
    ///
    /// <remarks>
    /// Sets the Xml namespace for this object and its children.
    /// </remarks>
    ///
    void SetNamespace(wchar_t * url, wchar_t * location)
    {
        if (NULL != m_namespaceUrl)
            delete m_namespaceUrl;
        if (NULL != url) {
            m_namespaceUrl = new wchar_t[::wcslen(url) + 1];
            ::wcscpy(m_namespaceUrl, url);
        } else
            m_namespaceUrl = NULL;

        if (NULL != m_namespaceLocation)
            delete m_namespaceLocation;
        if (NULL != location) {
            m_namespaceLocation = new wchar_t[::wcslen(location) + 1];
            ::wcscpy(m_namespaceLocation, location);
        } else
            m_namespaceLocation = NULL;
    }

    /// <summary>
    /// accessor for the url portion of the namespace attribute
    /// </summary>
    ///
    /// <returns>
    /// a const pointer to the Unicode url string
    /// </returns>
    const wchar_t * GetNamespaceUrl() const
    {
        return m_namespaceUrl;
    }

    /// <summary>
    /// accessor for the location portion of the namespace attribute
    /// </summary>
    ///
    /// <returns>
    /// a const pointer to the Unicode location string
    /// </returns>
    const wchar_t * GetNamespaceLocation() const
    {
        return m_namespaceLocation;
    }

    /// <summary>
    /// Sets the vector of the unique identifiers of the EPlotProperties 
    /// objects referenced (inherited) by this object.
    /// </summary>
    ///
    /// <param name="refs">
    /// a const reference to a vector of Unicode string identifications
    /// of additional AcDMMEPlotProperties objects
    /// </param>
    ///
    /// <remarks>
    /// The properties in the referenced EPlotProperties objects should be 
    /// considered part of this EPlotProperties instance as if they were 
    /// contained directly by this instance.
    /// </remarks>
    void AcDMMEPlotProperties::SetRefs(const AcDMMStringVec& refs)
    {
        m_refs.clear();
        m_refs.assign(refs.begin(), refs.end());
    }

    /// <summary>
    /// accessor for the vector of Unicode string identifications of 
    /// referenced AcDMMEPlotProperties objects
    /// </summary>
    ///
    /// <returns>
    /// a const pointer to the vector of Unicode string identifications of 
    /// referenced AcDMMEPlotProperties objects
    /// </returns>
    const AcDMMStringVec * AcDMMEPlotProperties::GetRefs() const
    {
        return &m_refs;
    }


    /// <summary>
    /// operator= also used by copy constructor
    /// </summary>
    ///
    /// <param name="src">
    /// the object whose values will be copied to this object
    /// </param>
    ///
    /// <returns>
    /// returns this object
    /// </returns>
    AcDMMEPlotProperties& operator= (const AcDMMEPlotProperties &src)
    {
        if (this == &src)
            return *this;

        m_properties.assign(src.m_properties.begin(),
            src.m_properties.end());
        SetId(src.m_id);
        SetNamespace(src.m_namespaceUrl, src.m_namespaceLocation);
        SetRefs(src.m_refs);
        return *this;
    }


private:

    AcDMMEPlotPropertyVec m_properties;
    wchar_t * m_id; /**<  Unique identifier for this object. */
    wchar_t * m_namespaceUrl;
    wchar_t * m_namespaceLocation;
    AcDMMStringVec m_refs; /**< Contains a list of EPlotProperties ID's.*/
};

#endif // AcDMMEPlotProperties_h
