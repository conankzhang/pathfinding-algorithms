#include "TiledDivisionScheme.h"

//=======================================================================================================================
CTiledDivisionScheme::CTiledDivisionScheme(float InWidth, float InHeight) :
	Width(InWidth),
	Height(InHeight)
{
}


//=======================================================================================================================
CTiledDivisionScheme::~CTiledDivisionScheme()
{
}

//=======================================================================================================================
int CTiledDivisionScheme::Quantize(const ofVec2f& InPosition) const
{
	return 0;
}

//=======================================================================================================================
ofVec2f CTiledDivisionScheme::Localize(int InNode) const
{
	return ofVec2f::zero();
}
