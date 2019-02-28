#pragma once
#include "Behavior.h"

//=======================================================================================================================
class cseek_steering : public CBehavior
{
public:
	cseek_steering(const ofVec2f& InTarget);
	~cseek_steering();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	const ofVec2f& Target;

	float TargetRadius;
	float SlowRadius;
	float TimeToTarget;
};
