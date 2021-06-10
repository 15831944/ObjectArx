//
#include "stdafx.h"
#include "DocManReactor.h"
#include "acutads.h"

ACRX_NO_CONS_DEFINE_MEMBERS(DocManReactor, AcApDocManagerReactor);

DocManReactor::DocManReactor()
{
}

DocManReactor::~DocManReactor()
{
}

void DocManReactor::documentCreateStarted(AcApDocument * pDocCreating)
{
	//acutPrintf(_T("\ndocumentCreateStarted"));
}

void DocManReactor::documentCreated(AcApDocument * pDocCreating)
{
	//acutPrintf(_T("\ndocumentCreated"));
}

void DocManReactor::documentToBeDestroyed(AcApDocument * pDocToDestroy)
{
	//acutPrintf(_T("\ndocumentToBeDestroyed"));
}

void DocManReactor::documentDestroyed(const ACHAR * fileName)
{
	//acutPrintf(_T("\ndocumentDestroyed"));
}

void DocManReactor::documentCreateCanceled(AcApDocument * pDocCreateCancelled)
{
	//acutPrintf(_T("\ndocumentCreateCanceled"));
}

void DocManReactor::documentLockModeWillChange(AcApDocument *, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode myNewMode, AcAp::DocLockMode currentMode, const ACHAR * pGlobalCmdName)
{
	//acutPrintf(_T("\ndocumentLockModeWillChange"));
}

void DocManReactor::documentLockModeChangeVetoed(AcApDocument *, const ACHAR * pGlobalCmdName)
{
	//acutPrintf(_T("\ndocumentLockModeChangeVetoed"));
}

void DocManReactor::documentLockModeChanged(AcApDocument *, AcAp::DocLockMode myPreviousMode, AcAp::DocLockMode myCurrentMode, AcAp::DocLockMode currentMode, const ACHAR * pGlobalCmdName)
{
	//acutPrintf(_T("\ndocumentLockModeChanged"));
}

void DocManReactor::documentBecameCurrent(AcApDocument *)
{
	//acutPrintf(_T("\ndocumentBecameCurrent"));
}

void DocManReactor::documentToBeActivated(AcApDocument * pActivatingDoc)
{
	//acutPrintf(_T("\ndocumentToBeActivated"));
}

void DocManReactor::documentToBeDeactivated(AcApDocument * pDeActivatedDoc)
{
	//acutPrintf(_T("\ndocumentToBeDeactivated"));
}

void DocManReactor::documentActivationModified(bool bActivation)
{
	//acutPrintf(_T("\ndocumentActivationModified"));
}

void DocManReactor::documentActivated(AcApDocument * pActivatedDoc)
{
	//acutPrintf(_T("\ndocumentActivated"));
}
