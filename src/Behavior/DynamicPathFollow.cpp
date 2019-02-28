#include "DynamicPathFollow.h"

#include "../Pathfinding/DirectedWeightedGraph.h"
#include "../Pathfinding/DivisionScheme.h"
#include "../Entity/Boid.h"

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
	if (!Path.empty() && DivisionScheme)
	{
		ofVec2f Target = DivisionScheme->Localize(Path.front()->GetSink());
		SeekSteering.SetTarget(Target);

		float Distance = (InBoid.GetPosition() - Target).length();
		if (Distance < TargetRadius)
		{
			Path.pop();

			Target = DivisionScheme->Localize(Path.front()->GetSink());
			SeekSteering.SetTarget(Target);
		}
	}

	return SeekSteering.GetBehaviorOutput(InBoid);
}
