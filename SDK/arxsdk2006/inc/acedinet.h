//
//                 (C) Copyright 1988-1999 by Autodesk, Inc.
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
//////////////////////////////////////////////////////////////////////////////
//
// Name:    acedInet.h
//
// Remarks:	Miscellaneous functions to create and resolve Windows shell links
//          and MS Internet Explorer shortcuts.
//
// Author:  Samir Bajaj
//
//////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACEDINET_H__2357B7CE_20CE_11d2_A981_0060B0CD39AD__INCLUDED_)
#define AFX_ACEDINET_H__2357B7CE_20CE_11d2_A981_0060B0CD39AD__INCLUDED_
#pragma pack (push, 8)


// FUNCTION       acedCreateShortcut()
//
// ARGUMENTS      pvHwndParent -- pointer to a window handle (of type HWND)
//                                that will be used as the parent window in
//                                case we need to display a message box or
//                                an animation dialog; this value should not
//                                be NULL
//                szLinkPath   -- full path to the .lnk file that will be
//                                created as the Windows-style shortcut;
//                                note that the ".lnk" extension is required
//                szObjectPath -- full path to the filesystem object which
//                                the shortcut will point to
//                szDesc       -- a descriptive string for the shortcut; can
//                                have any arbitrary value except NULL
//
// RETURN VALUE   Adesk::kTrue on success; Adesk::kFalse on failure
//
extern Adesk::Boolean
acedCreateShortcut(/*[in]*/void* pvHwndParent, /*[in]*/const char* szLinkPath, 
				   /*[in]*/const char* szObjectPath, /*[in]*/const char* szDesc);


// FUNCTION       acedResolveShortcut()
//
// ARGUMENTS      pvHwndParent -- pointer to a window handle (of type HWND)
//                                that will be used as the parent window in
//                                case we need to display a message box or
//                                an animation dialog; this value should not
//                                be NULL
//                szLinkPath   -- full path to the .lnk file that will be
//                                created as the Windows-style shortcut;
//                                note that the ".lnk" extension is required
//                szObjectPath -- a char buffer that receives the full path
//                                of the filesystem object which the shortcut
//                                points; it is the caller's responsibility
//                                to provide a sufficiently large buffer
//
// RETURN VALUE   Adesk::kTrue on success; Adesk::kFalse on failure
//
extern Adesk::Boolean
acedResolveShortcut(/*[in]*/void* pvHwndParent, /*[in]*/const char* szLinkPath, 
					/*[out]*/char* szObjectPath);


//
// FUNCTION       acedGetUserFavoritesDir()
//
// ARGUMENTS      szFavoritesDir -- a char buffer that receives the full path
//                                  to the Windows Favorites folder of the
//                                  currently logged-in user; it is the caller's
//                                  responsibility to provide a sufficiently
//                                  large buffer
//
// RETURN VALUE   Adesk::kTrue on success; Adesk::kFalse on failure
//
extern Adesk::Boolean
acedGetUserFavoritesDir(/*[out]*/char* szFavoritesDir);


// 'acedCreateInternetShortcut()' creates an MSIE-compatible Internet shortcut
// using the arguments passed to it. 'szURL' is the URL that the shortcut will
// "wrap" (point to), and 'szShortcutPath' is the filesystem path to the resulting
// shortcut.
//
// Note that 'szShortcutPath' should specify a path to a file that has the ".url"
// extension. In the absence of such an extension, the specified path will be
// considered invalid and Adesk::kFalse will be returned.
//
// RETURN VALUE   Adesk::kTrue on success; Adesk::kFalse on failure
//
extern Adesk::Boolean
acedCreateInternetShortcut(/*[in]*/const char* szURL, /*[in]*/const char* szShortcutPath);


// 'acedResolveInternetShortcut()' is the inverse of 'acedCreateInternetShortcut().'
// This function accepts a path to an (MSIE-compatible) Internet shortcut file and
// extracts the URL from it. The retrieved URL is returned via the parameter 'szURL.'
// It is the caller's responsibility to ensure that 'szURL' points to a sufficiently
// large buffer.
//
// RETURN VALUE   Adesk::kTrue on success; Adesk::kFalse on failure
//
extern Adesk::Boolean
acedResolveInternetShortcut(/*[in]*/const char* szLinkFile, /*[out]*/char* szUrl);



#pragma pack (pop)
#endif	// #define AFX_ACEDINET_H__2357B7CE_20CE_11d2_A981_0060B0CD39AD__INCLUDED_
