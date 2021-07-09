#include "pch.h"
#include "brface.h"


void loadtest()
{
	acutPrintf(_T("\nload test!"));
}


int showhello(struct resbuf *rb)
{
	ads_printf(_T("hello"));
	ads_retvoid();
	return RTNORM;
}

int showhellocmd(struct resbuf *rb)
{
	ads_printf(_T("hello"));
	ads_retvoid();
	return RTNORM;
}

void BrepCrashTest()
{
	AcBrFace face;
	AcGeExternalBoundedSurface** ppNurbs = NULL;
	Adesk::UInt32 numNurbs = 0;
	AcBr::ErrorStatus es = face.getSurfaceAsTrimmedNurbs(numNurbs, ppNurbs);
	if (es == Acad::eNotImplementedYet)
	{
		acutPrintf(L"eNotImplementedYet\n");
		return;
	}
}