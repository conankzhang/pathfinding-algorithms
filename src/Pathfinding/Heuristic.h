#pragma once

#include <map>

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
class CPalletMapping : public CHeuristic
{
public:
	CPalletMapping();
	~CPalletMapping();

	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;

private:
	std::map<int, float> NodeMapping;
};

//=======================================================================================================================
class CEuclideanDistance : public CHeuristic
{
public:
	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};
