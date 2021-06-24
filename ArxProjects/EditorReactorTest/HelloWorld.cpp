// HelloWorld.cpp : 
//

#include "stdafx.h"
#include "aced.h"
#include "rxregsvc.h"
#include "EditorReactor.h"

void initApp();
void unloadApp();

void HelloWorld();
#ifdef ARX
#define zcrxEntryPoint acrxEntryPoint
#endif

EditorReactor* m_editorreactor = NULL;
void AddEditorReactor();
void RemoveEditorReactor();

void initApp()
{
	EditorReactor::rxInit();
	acrxBuildClassHierarchy();
	// register a command with the AutoCAD command mechanism
	acedRegCmds->addCommand(_T("HELLOWORLD_COMMANDS"), _T("HelloWorld"), _T("HelloWorld"), ACRX_CMD_MODAL, HelloWorld);
	acedRegCmds->addCommand(_T("HELLOWORLD_COMMANDS"), _T("AddEditorReactor"), _T("AddEditorReactor"), ACRX_CMD_MODAL, AddEditorReactor);
	acedRegCmds->addCommand(_T("HELLOWORLD_COMMANDS"), _T("RemoveEditorReactor"), _T("RemoveEditorReactor"), ACRX_CMD_MODAL, RemoveEditorReactor);
}
void unloadApp()
{ 
	deleteAcRxClass(EditorReactor::desc());
	acedRegCmds->removeGroup(_T("HELLOWORLD_COMMANDS"));
}

void HelloWorld()
{
	acutPrintf(_T("\nHello World!"));
}

void AddEditorReactor()
{
	if (!m_editorreactor)
	{
		m_editorreactor = new EditorReactor();
	}
	acedEditor->addReactor(m_editorreactor);
}

void RemoveEditorReactor()
{
	if (m_editorreactor)
	{
		acedEditor->removeReactor(m_editorreactor);
		delete m_editorreactor;
		m_editorreactor = NULL;
	}
}

extern "C" AcRx::AppRetCode
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		initApp();
		break;
	case AcRx::kUnloadAppMsg:
		unloadApp();
		break;
	default:
		break;
	}

	return AcRx::kRetOK;
}


