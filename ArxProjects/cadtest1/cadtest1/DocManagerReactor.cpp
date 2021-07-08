//
#include "stdafx.h"
#include "DocManagerReactor.h"
#include "acutads.h"

ACRX_NO_CONS_DEFINE_MEMBERS(DocManagerReactor, AcApDocManagerReactor);

DocManagerReactor::DocManagerReactor()
{
}

DocManagerReactor::~DocManagerReactor()
{
}

void DocManagerReactor::documentCreateStarted(AcApDocument * pDocCreating)
{
	//acutPrintf(_T("\ndocumentCreateStarted"));
}

void DocManagerReactor::documentCreated(AcApDocument * pDocCreating)
{
	//acutPrintf(_T("\ndocumentCreated"));
}

void DocManagerReactor::documentToBeDestroyed(AcApDocument * pDocToDestroy)
{
	//acutPrintf(_T("\ndocumentToBeDestroyed"));
}

void DocManagerReactor::documentDestroyed(const ACHAR * fileName)
{
	//acutPrintf(_T("\ndocumentDestroyed"));
}

void DocManagerReactor::documentCreateCanceled(AcApDocument * pDocCreateCancelled)
{
	//acutPrintf(_T("\ndocumentCreateCanceled"));
}

void DocManagerReactor::documentLockModeWillChange(AcApDocument *, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode myNewMode, AcAp::DocLockMode currentMode, const ACHAR * pGlobalCmdName)
{
	//acutPrintf(_T("\ndocumentLockModeWillChange"));
}

void DocManagerReactor::documentLockModeChangeVetoed(AcApDocument *, const ACHAR * pGlobalCmdName)
{
	//acutPrintf(_T("\ndocumentLockModeChangeVetoed"));
}

void DocManagerReactor::documentLockModeChanged(
	AcApDocument* acapDoc,
	AcAp::DocLockMode myPreviousMode,
	AcAp::DocLockMode myCurrentMode,
	AcAp::DocLockMode currentMode,
	const ACHAR* pGlobalCmdName)
{
	CString szCmd = pGlobalCmdName;

	if (szCmd.CompareNoCase(_T("close")) == 0 || szCmd.CompareNoCase(_T("_close")) == 0)
	{
		acutPrintf(_T("\n½ûÖ¹¹Ø±ÕÍ¼Ö½£¡"));
		Acad::ErrorStatus es = veto();
	}

	//acutPrintf(_T("\ndocumentLockModeChanged"));
}

void DocManagerReactor::documentBecameCurrent(AcApDocument *)
{
	//acutPrintf(_T("\ndocumentBecameCurrent"));
}

void DocManagerReactor::documentToBeActivated(AcApDocument * pActivatingDoc)
{
	//acutPrintf(_T("\ndocumentToBeActivated"));
}

void DocManagerReactor::documentToBeDeactivated(AcApDocument * pDeActivatedDoc)
{
	//acutPrintf(_T("\ndocumentToBeDeactivated"));
}

void DocManagerReactor::documentActivationModified(bool bActivation)
{
	//acutPrintf(_T("\ndocumentActivationModified"));
}

void DocManagerReactor::documentActivated(AcApDocument * pActivatedDoc)
{
	//acutPrintf(_T("\ndocumentActivated"));
}

REGISTER_OBJECT(DocManagerReactor);
DocManagerReactor* g_pDocManagerReactor = NULL;
ARXCMD3(AddDocManagerReactor)
{
	if (g_pDocManagerReactor == NULL)
	{
		g_pDocManagerReactor = new DocManagerReactor();
		acDocManager->addReactor(g_pDocManagerReactor);
	}
	else
	{
		acDocManager->addReactor(g_pDocManagerReactor);
	}
}

ARXCMD3(RemoveDocManagerReactor)
{
	if (g_pDocManagerReactor != NULL)
	{
		acDocManager->removeReactor(g_pDocManagerReactor);
	}
}