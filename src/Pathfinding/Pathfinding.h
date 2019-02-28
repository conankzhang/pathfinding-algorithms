#pragma once

#include "DirectedWeightedGraph.h"

#include <vector>


class CHeuristic
{
public:
	float GetEstimate(int InNode);
};


class CPathfinding
{
public:
	CPathfinding();
	~CPathfinding();

	std::vector<CDirectedWeightedEdge> FindPath(int StartNode, int GoalNode, CDirectedWeightedGraph* Graph, CHeuristic* Heuristic);
};

