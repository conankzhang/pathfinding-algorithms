#include "DynamicPathFollow.h"



CDynamicPathFollow::CDynamicPathFollow()
{
}


CDynamicPathFollow::~CDynamicPathFollow()
{
}

SBehaviorOutput CDynamicPathFollow::GetBehaviorOutput(const CBoid& InBoid)
{
	SeekSteering.SetTarget(ofVec2f::zero());
	return SeekSteering.GetBehaviorOutput(InBoid);
}
