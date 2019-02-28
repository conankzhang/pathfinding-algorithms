#pragma once

#include <vector>

class CDirectedWeightedEdge;
class CDirectedWeightedGraph;

class CHeuristic;

//=======================================================================================================================
struct SNodeRecord
{
	SNodeRecord();
	SNodeRecord(int InNode, CDirectedWeightedEdge* InEdge, float InCost, float InEstimatedCost);

	int Node;

	CDirectedWeightedEdge* IncomingEdge;

	float CostSoFar;
	float EstimatedTotalCost;
};

//=======================================================================================================================
class CPathfinding
{
public:
	CPathfinding();
	~CPathfinding();

	bool FindPath(int StartNode, int GoalNode, const CDirectedWeightedGraph* const Graph, const CHeuristic* const Heuristic, std::vector<CDirectedWeightedEdge*>& OutPath) const;
};
