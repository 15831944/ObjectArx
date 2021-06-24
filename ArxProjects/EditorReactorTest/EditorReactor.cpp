//
#include "stdafx.h"
#include "EditorReactor.h"

ACRX_NO_CONS_DEFINE_MEMBERS(EditorReactor, AcEditorReactor);

EditorReactor::EditorReactor()
{
}

EditorReactor::~EditorReactor()
{
}


// Command Events
//
void EditorReactor::unknownCommand(const ACHAR* cmdStr, AcDbVoidPtrArray *al){}

void EditorReactor::commandWillStart(const ACHAR* cmdStr){}

void EditorReactor::commandEnded(const ACHAR* cmdStr)
{
	acutPrintf(_T("\n%s ended!"), cmdStr);
}

void EditorReactor::commandCancelled(const ACHAR* cmdStr){}

void EditorReactor::commandFailed(const ACHAR* cmdStr){}

// Lisp Events
//
void EditorReactor::lispWillStart(const ACHAR* firstLine) {}
void EditorReactor::lispEnded() {}
void EditorReactor::lispCancelled() {}

#if (defined(ARX) || ((defined(ZRX) && ZRX > 2020)))
void EditorReactor::beginDwgOpen(const ACHAR* filename)
#else
void EditorReactor::beginDwgOpen(ACHAR* filename)
#endif
{
	::OutputDebugString(_T(__FUNCTION__));
}

void EditorReactor::endDwgOpen(const ACHAR* filename, AcDbDatabase* pDb)
{
	::OutputDebugString(_T(__FUNCTION__));
}

void EditorReactor::initialDwgFileOpenComplete(AcDbDatabase* pDwg)
{
	::OutputDebugString(_T(__FUNCTION__));
}

#if (defined(ARX) || ((defined(ZRX) && ZRX > 2020)))
void EditorReactor::dwgFileOpened(AcDbDatabase*, const ACHAR * /*fileName*/)
#else
void EditorReactor::dwgFileOpened(AcDbDatabase*, ACHAR* fileName)
#endif
{
	::OutputDebugString(_T(__FUNCTION__));
}

void EditorReactor::databaseConstructed(AcDbDatabase*)
{
	::OutputDebugString(_T(__FUNCTION__));
}

void EditorReactor::databaseToBeDestroyed(AcDbDatabase*)
{
	::OutputDebugString(_T(__FUNCTION__));
}




