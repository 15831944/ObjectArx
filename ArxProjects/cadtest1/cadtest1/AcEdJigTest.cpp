//
#include "stdafx.h"
#include "AcEdJigTest.h"

#include "dbelipse.h"

EllipseJig::EllipseJig(const AcGePoint3d& pt, const AcGeVector3d& normal)
	: m_ptCenter(pt),
	m_normal(normal),
	m_radiusRatio(0.00001),
	m_promptCounter(0)
{
	// Calculate a proper initial offset for the major axis from the current view extents.
	struct resbuf rb;
	memset(&rb, 0, sizeof(struct resbuf));
	acedGetVar(_T("VIEWSIZE"), &rb);
	double majorAxisInitialOffset = rb.resval.rreal / 1000.0;

	// Offset the major axis a bit from the center point.
	m_majorAxis = AcGeVector3d(majorAxisInitialOffset, 0, 0);
}

// This function creates an AcDbEllipse object and gets the jig started acquiring the necessary info to properly fill it in.
void EllipseJig::doIt()
{
	m_pEllipse = new AcDbEllipse();
	m_pEllipse->set(m_ptCenter, m_normal, m_majorAxis, m_radiusRatio); 

	// Get the major axis vector from the user, m_promptCounter == 0
	setDispPrompt(_T("\nEllipse major axis: "));
	AcEdJig::DragStatus stat = drag();

	// Get the ellipse's radius ratio, m_promptCounter == 1
	m_promptCounter++;   
	setDispPrompt(_T("\nEllipse minor axis: "));
	stat = drag();

	// Add the ellipse to the database's current space.
	append();
}

// This function is called by the drag function to acquire a sample input.
AcEdJig::DragStatus EllipseJig::sampler()
{
	DragStatus stat;

	setUserInputControls((UserInputControls)(
		AcEdJig::kAccept3dCoordinates |
		AcEdJig::kNoNegativeResponseAccepted |
		AcEdJig::kNoZeroResponseAccepted));

	if (m_promptCounter == 0)
	{
		// Acquire the major axis endpoint.
		static AcGePoint3d axisPointTemp;
		stat = acquirePoint(m_ptAxis, m_ptCenter);

		// If the newly acquired point is the same as it was in the last sample, 
		// then we return kNoChange so the EllipseJig::update() function will not be called and the last update call will be able to finish, 
		// thus allowing the ellipse to fully elaborate.
		if (axisPointTemp != m_ptAxis)
			axisPointTemp = m_ptAxis;
		else if (stat == AcEdJig::kNormal)
			return AcEdJig::kNoChange;
	}
	else if (m_promptCounter == 1) 
	{
		// Acquire the distance from ellipse center to minor axis endpoint. This will be used to calculate the radius ratio.
		static double radiusRatioTemp = -1;
		stat = acquireDist(m_radiusRatio, m_ptCenter);

		// If the newly acquired distance is the same as it was in the last sample, 
		// then we return kNoChange so the EllipseJig::update() function will not be called and the last update call will be able to finish, 
		// thus allowing the ellipse to fully elaborate.
		if (radiusRatioTemp != m_radiusRatio)
			radiusRatioTemp = m_radiusRatio;
		else if (stat == AcEdJig::kNormal)
			return AcEdJig::kNoChange;
	}

	return stat;
}

// This function is called to update the entity based on the input values.
Adesk::Boolean EllipseJig::update()
{
	switch (m_promptCounter)
	{
	case 0:

		// At this time, mAxis contains the value of one endpoint of the desired major axis.  
		// The AcDbEllipse class stores the major axis as the vector from the center point to 
		// where the axis intersects the ellipse path (such as half of the true major axis), so we already have what we need.

		m_majorAxis = m_ptAxis - m_ptCenter;
		break;
	case 1:

		// Calculate the radius ratio. 
		// m_radiusRatio currently contains the distance from the ellipse center to the current pointer position. 
		// This is half of the actual minor axis length. 
		// Since AcDbEllipse stores the major axis vector as the vector from the center point to the ellipse curve(half the major axis),
		// to get the radius ratio we simply divide the value currently in m_radiusRatio by the length of the stored major axis vector.

		m_radiusRatio = m_radiusRatio / m_majorAxis.length();
		break;
	}

	// Update the ellipse with the latest setting.
	m_pEllipse->set(m_ptCenter, m_normal, m_majorAxis, m_radiusRatio);

	return Adesk::kTrue;
}

// This function must be implemented to return a pointer to the entity being manipulated by the jig.
AcDbEntity* EllipseJig::entity() const
{
	return m_pEllipse;
}

// This function uses the AcEdJig mechanism to create and drag an ellipse entity. 
// The creation criteria are slightly different from the AutoCAD command.  
// In this case, the user selects an ellipse center point and then,
// drags to visually select the major and minor axes lengths. 
// This sample is somewhat limited; 
// if the minor axis ends up longer than the major axis, then the ellipse will just be round 
// because the radius ratio cannot be greater than 1.0.
ARXCMD3(createEllipse)
{
	// First, have the user select the ellipse center point.
	// We don't use the jig for this because there is nothing to see yet.
	AcGePoint3d tempPt;
	struct resbuf rbFrom, rbTo;

	acedGetPoint(NULL, _T("\nEllipse center point: "), asDblArray(tempPt));

	// The point we just got is in UCS coordinates, but AcDbEllipse works in WCS, so convert the point.
	rbFrom.restype = RTSHORT;
	rbFrom.resval.rint = 1;  // from UCS
	rbTo.restype = RTSHORT;
	rbTo.resval.rint = 0;    // to WCS

	acedTrans(asDblArray(tempPt), &rbFrom, &rbTo,Adesk::kFalse, asDblArray(tempPt));

	// Now you need to get the current UCS z-Axis to be used as the normal vector for the ellipse.
	AcGeVector3d x = acdbHostApplicationServices()->workingDatabase()->ucsxdir();
	AcGeVector3d y = acdbHostApplicationServices()->workingDatabase()->ucsydir();
	AcGeVector3d normalVec = x.crossProduct(y);
	normalVec.normalize();

	// Create an EllipseJig object passing in the center point just selected by the user and the normal vector just calculated.
	EllipseJig *pJig = new EllipseJig(tempPt, normalVec);

	// Now start up the jig to interactively get the major and minor axes lengths.
	pJig->doIt();

	// Now delete the jig object, since it is no longer needed.
	delete pJig;
	pJig = nullptr;
}