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

	bool FindPath(int StartNode, int GoalNode, CDirectedWeightedGraph* Graph, CHeuristic* Heuristic, std::vector<CDirectedWeightedEdge*>& OutPath);
};
