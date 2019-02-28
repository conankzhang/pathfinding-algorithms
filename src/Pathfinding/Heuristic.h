#pragma once

class CDivisionScheme;

//=======================================================================================================================
class CHeuristic
{
public:
	virtual float GetEstimate(int CurrentNode, int GoalNode) const { return 0; }

protected:
	CDivisionScheme* DivisionScheme;
};

//=======================================================================================================================
class CZeroEstimate : public CHeuristic
{
public:
	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};

//=======================================================================================================================
class CManhattanDistance : public CHeuristic
{
public:
	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};

//=======================================================================================================================
class CEuclideanDistance : public CHeuristic
{
public:
	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};
