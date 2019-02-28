#pragma once
#include "Behavior.h"

#include "seek-steering.h"

//=======================================================================================================================
class CDynamicPathFollow : public CBehavior
{
public:
	CDynamicPathFollow();
	~CDynamicPathFollow();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	cseek_steering SeekSteering;
};
