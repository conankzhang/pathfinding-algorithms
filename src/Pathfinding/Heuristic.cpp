#include "Heuristic.h"

#include "DivisionScheme.h"

//=======================================================================================================================
float CZeroHeuristic::GetEstimate(int CurrentNode, int GoalNode) const
{
	return 0;
}

//=======================================================================================================================
float CEuclideanHeuristic::GetEstimate(int CurrentNode, int GoalNode) const
{
	if (!DivisionScheme)
	{
		return 0;
	}

	ofVec2f CurrentPosition = DivisionScheme->Localize(CurrentNode);
	ofVec2f GoalPosition = DivisionScheme->Localize(GoalNode);

	return (CurrentPosition - GoalPosition).length();
}
