#include "TiledDivisionScheme.h"

#include "DirectedWeightedGraph.h"

//=======================================================================================================================
CTiledDivisionScheme::CTiledDivisionScheme(float InWidth, float InHeight, CDirectedWeightedGraph* InGraph) :
	Width(InWidth),
	Height(InHeight),
	Graph(InGraph)
{
}

//=======================================================================================================================
CTiledDivisionScheme::~CTiledDivisionScheme()
{
}

//=======================================================================================================================
int CTiledDivisionScheme::Quantize(const ofVec2f& InPosition) const
{
	if (!Graph)
	{
		return 0;
	}

	return Graph->GetNodeAt(floor(InPosition.y / Width), floor(InPosition.x / Height));
}

//=======================================================================================================================
ofVec2f CTiledDivisionScheme::Localize(int InNode) const
{
	return ofVec2f::zero();
}
