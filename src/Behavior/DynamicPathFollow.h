#pragma once
#include "Behavior.h"

#include "seek-steering.h"

#include <queue>

class CDivisionScheme;
class CDirectedWeightedEdge;

//=======================================================================================================================
class CDynamicPathFollow : public CBehavior
{
public:
	CDynamicPathFollow(std::queue<const CDirectedWeightedEdge*>& InPath, CDivisionScheme* InDivisionScheme);
	~CDynamicPathFollow();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	cseek_steering SeekSteering;

	CDivisionScheme* DivisionScheme;
	std::queue<const CDirectedWeightedEdge*>& Path;

	float TargetRadius;
};
