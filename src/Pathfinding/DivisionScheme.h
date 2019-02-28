#pragma once

#include "ofVec2f.h"

#include <vector>

class CDirectedWeightedEdge;

class DivisionScheme
{
public:
	virtual int Quantize(ofVec2f InPosition) = 0;
	virtual ofVec2f Localize(int InNode) = 0;

	bool GetWaypointPath(const std::vector<CDirectedWeightedEdge*>& Path, std::vector<ofVec2f>& OutWaypoints);
};

