#pragma once

#include "ofVec2f.h"

#include <vector>

class CDirectedWeightedEdge;

class DivisionScheme
{
public:
	virtual int Quantize(const ofVec2f& InPosition) const = 0;
	virtual ofVec2f Localize(int InNode) const = 0;

	bool GetWaypointPath(const std::vector<CDirectedWeightedEdge*>& Path, std::vector<ofVec2f>& OutWaypoints) const;
};

