#include "Heuristic.h"

#include "DivisionScheme.h"

//=======================================================================================================================
float CZeroEstimate::GetEstimate(int CurrentNode, int GoalNode) const
{
	return 0;
}

//=======================================================================================================================
float CManhattanDistance::GetEstimate(int CurrentNode, int GoalNode) const
{
	if (!DivisionScheme)
	{
		return 0;
	}

	ofVec2f CurrentPosition = DivisionScheme->Localize(CurrentNode);
	ofVec2f GoalPosition = DivisionScheme->Localize(GoalNode);

	ofVec2f Hypotenuse = CurrentPosition - GoalPosition;

	return abs(Hypotenuse.x) + abs(Hypotenuse.y);
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
