#pragma once

#include <vector>

class CDirectedWeightedEdge;
class CDirectedWeightedGraph;

class CHeuristic;

//=======================================================================================================================
namespace Pathfinding
{
	struct SNodeRecord
	{
		SNodeRecord();
		SNodeRecord(int InNode, const CDirectedWeightedEdge* InEdge, float InCost, float InEstimatedCost);

		int Node;

		const CDirectedWeightedEdge* IncomingEdge;

		float CostSoFar;
		float EstimatedTotalCost;
	};

	bool FindPath(int StartNode, int GoalNode, const CDirectedWeightedGraph* const Graph, const CHeuristic* const Heuristic, std::vector<const CDirectedWeightedEdge*>& OutPath);
};
