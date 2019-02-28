#pragma once

//=======================================================================================================================
class CHeuristic
{
public:
	virtual float GetEstimate(int InNode) = 0;
};

//=======================================================================================================================
class CZeroHeuristic : public CHeuristic
{
public:
	virtual float GetEstimate(int InNode) override;
};

//=======================================================================================================================
class CEuclideanHeuristic : public CHeuristic
{
public:
	virtual float GetEstimate(int InNode) override;
};
