#pragma once

#include "stdafx.h"

class EditorReactor :public AcEditorReactor
{
public:
	ACRX_DECLARE_MEMBERS(EditorReactor);

	EditorReactor();
	virtual ~EditorReactor();
public:

	// Command Events
//
	virtual void unknownCommand(const ACHAR* cmdStr, AcDbVoidPtrArray *al);
	virtual void commandWillStart(const ACHAR* cmdStr);
	virtual void commandEnded(const ACHAR* cmdStr);
	virtual void commandCancelled(const ACHAR* cmdStr);
	virtual void commandFailed(const ACHAR* cmdStr);

	// Lisp Events
	//
	virtual void lispWillStart(const ACHAR* firstLine);
	virtual void lispEnded();
	virtual void lispCancelled();

	// DWG Open Events.
//
#if (defined(ARX) || ((defined(ZRX) && ZRX > 2020)))
	virtual void beginDwgOpen(const ACHAR* filename);
#else
	virtual void beginDwgOpen(ACHAR* filename);
#endif
	virtual void endDwgOpen(const ACHAR* filename, AcDbDatabase* pDb);
	virtual void initialDwgFileOpenComplete(AcDbDatabase* pDwg);

	// DWG/Save Events.
	//
#if (defined(ARX) || ((defined(ZRX) && ZRX > 2020)))
	virtual void dwgFileOpened(AcDbDatabase*, const ACHAR * /*fileName*/);
#else
	virtual void dwgFileOpened(AcDbDatabase*, ACHAR* fileName);
#endif
	virtual void databaseConstructed(AcDbDatabase*);
	virtual void databaseToBeDestroyed(AcDbDatabase*);
};

