#pragma once

class CDivisionScheme;

//=======================================================================================================================
class CHeuristic
{
public:
	virtual float GetEstimate(int CurrentNode, int GoalNode) const = 0;

protected:
	CDivisionScheme* DivisionScheme;
};

//=======================================================================================================================
class CZeroHeuristic : public CHeuristic
{
public:
	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};

//=======================================================================================================================
class CEuclideanHeuristic : public CHeuristic
{
public:
	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};
