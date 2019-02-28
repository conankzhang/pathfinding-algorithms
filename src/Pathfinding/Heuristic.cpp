#include "Heuristic.h"

#include "DivisionScheme.h"

//=======================================================================================================================
float CZeroEstimate::GetEstimate(int CurrentNode, int GoalNode) const
{
	return 0;
}

//=======================================================================================================================
float CRandomEstimate::GetEstimate(int CurrentNode, int GoalNode) const
{
	return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/16));
}

//=======================================================================================================================
float CEuclideanDistance::GetEstimate(int CurrentNode, int GoalNode) const
{
	if (!DivisionScheme)
	{
		return 0;
	}

	ofVec2f CurrentPosition = DivisionScheme->Localize(CurrentNode);
	ofVec2f GoalPosition = DivisionScheme->Localize(GoalNode);

	return (CurrentPosition - GoalPosition).length();
}
