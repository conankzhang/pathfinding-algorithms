#pragma once

//=======================================================================================================================
class CHeuristic
{
public:
	virtual float GetEstimate(int InNode) const = 0;
};

//=======================================================================================================================
class CZeroHeuristic : public CHeuristic
{
public:
	virtual float GetEstimate(int InNode) const override;
};

//=======================================================================================================================
class CEuclideanHeuristic : public CHeuristic
{
public:
	virtual float GetEstimate(int InNode) const override;
};
