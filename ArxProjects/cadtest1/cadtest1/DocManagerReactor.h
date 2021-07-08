#pragma once
#include "stdafx.h"
#include "acdocman.h"

class DocManagerReactor : public AcApDocManagerReactor
{
public:
	ACRX_DECLARE_MEMBERS(DocManagerReactor);

	DocManagerReactor();
	~DocManagerReactor();

	virtual void              documentCreateStarted(AcApDocument* pDocCreating);

	virtual void              documentCreated(AcApDocument* pDocCreating);

	virtual void              documentToBeDestroyed(AcApDocument* pDocToDestroy);

	virtual void              documentDestroyed(const ACHAR* fileName);

	virtual void              documentCreateCanceled(AcApDocument* pDocCreateCancelled);

	virtual void              documentLockModeWillChange(AcApDocument*,
														AcAp::DocLockMode myCurrentMode,
														AcAp::DocLockMode myNewMode,
														AcAp::DocLockMode currentMode,
														const ACHAR* pGlobalCmdName);
	virtual void              documentLockModeChangeVetoed(AcApDocument*,
														const ACHAR* pGlobalCmdName);
	virtual void              documentLockModeChanged(AcApDocument*,
														AcAp::DocLockMode myPreviousMode,
														AcAp::DocLockMode myCurrentMode,
														AcAp::DocLockMode currentMode,
														const ACHAR* pGlobalCmdName);

	virtual void              documentBecameCurrent(AcApDocument*);

	virtual void              documentToBeActivated(AcApDocument* pActivatingDoc);

	virtual void              documentToBeDeactivated(AcApDocument* pDeActivatedDoc);

	virtual void              documentActivationModified(bool bActivation);

	virtual void              documentActivated(AcApDocument* pActivatedDoc);
protected:
private:
};