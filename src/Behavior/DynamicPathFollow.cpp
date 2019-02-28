#include "DynamicPathFollow.h"

#include "../Pathfinding/DirectedWeightedGraph.h"
#include "../Pathfinding/DivisionScheme.h"

#include <queue>

//=======================================================================================================================
CDynamicPathFollow::CDynamicPathFollow(std::queue<const CDirectedWeightedEdge*>& InPath, CDivisionScheme* InDivisionScheme) :
	Path(InPath),
	TargetRadius(10.0f),
	DivisionScheme(InDivisionScheme)

{
}

//=======================================================================================================================
CDynamicPathFollow::~CDynamicPathFollow()
{
}

//=======================================================================================================================
SBehaviorOutput CDynamicPathFollow::GetBehaviorOutput(const CBoid& InBoid)
{
	SeekSteering.SetTarget(ofVec2f::zero());
	return SeekSteering.GetBehaviorOutput(InBoid);
}
