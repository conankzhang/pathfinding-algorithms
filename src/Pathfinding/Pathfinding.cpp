#include "Pathfinding.h"
#include "Heuristic.h"
#include "DirectedWeightedGraph.h"

#include <map>
#include <queue>

//=======================================================================================================================
SNodeRecord::SNodeRecord() :
	Node(-1),
	IncomingEdge(nullptr),
	CostSoFar(-1),
	EstimatedTotalCost(-1)
{

}

//=======================================================================================================================
SNodeRecord::SNodeRecord(int InNode, const CDirectedWeightedEdge* InEdge, float InCost, float InEstimatedCost) :
	Node(InNode),
	IncomingEdge(InEdge),
	CostSoFar(InCost),
	EstimatedTotalCost(InEstimatedCost)
{

}

//=======================================================================================================================
CPathfinding::CPathfinding()
{
}

//=======================================================================================================================
CPathfinding::~CPathfinding()
{
}

//=======================================================================================================================
bool CPathfinding::FindPath(int StartNode, int GoalNode, const CDirectedWeightedGraph* const Graph, const CHeuristic* const Heuristic, std::vector<const CDirectedWeightedEdge*>& OutPath) const
{
	if (!Heuristic || !Graph)
	{
		return false;
	}

	SNodeRecord* StartRecord = new SNodeRecord(StartNode, nullptr, 0, Heuristic->GetEstimate(StartNode));

	std::map<int, SNodeRecord*> ClosedList;

	std::map<int, SNodeRecord*> OpenNodes;
	std::priority_queue<SNodeRecord*> OpenList;

	OpenList.push(StartRecord);
	OpenNodes.insert({ StartRecord->Node, StartRecord });

	SNodeRecord* CurrentRecord;
	while (!OpenList.empty())
	{
		CurrentRecord = OpenList.top();
		OpenList.pop();
		OpenNodes.erase(CurrentRecord->Node);

		if (CurrentRecord)
		{
			if (CurrentRecord->Node == GoalNode)
			{
				break;
			}

			std::vector<const CDirectedWeightedEdge*> OutgoingEdges;
			Graph->GetOutgoingEdges(CurrentRecord->Node, OutgoingEdges);

			int EndNode;
			for (const CDirectedWeightedEdge* Edge : OutgoingEdges)
			{
				if (Edge)
				{
					EndNode = Edge->GetSink();

					float CostSoFar = CurrentRecord->CostSoFar + Edge->GetCost();
					float EstimatedCost = Heuristic->GetEstimate(EndNode);

					SNodeRecord* EndNodeRecord;
					if (ClosedList.count(EndNode) > 0)
					{
						EndNodeRecord = ClosedList.at(EndNode);
						if (EndNodeRecord && EndNodeRecord->CostSoFar <= CostSoFar)
						{
							continue;
						}
						ClosedList.erase(EndNode);
					}

					if (OpenNodes.count(EndNode) > 0)
					{
						EndNodeRecord = OpenNodes.at(EndNode);
						if (EndNodeRecord && EndNodeRecord->CostSoFar <= CostSoFar)
						{
							continue;
						}

						EndNodeRecord->CostSoFar = CostSoFar;
						EndNodeRecord->EstimatedTotalCost = CostSoFar + EstimatedCost;
					}
					else
					{
						EndNodeRecord = new SNodeRecord(EndNode, Edge, CostSoFar, CostSoFar + EstimatedCost);
						OpenList.push(EndNodeRecord);
						OpenNodes.insert({ EndNodeRecord->Node, EndNodeRecord});
					}
				}
			}

			ClosedList.insert({ CurrentRecord->Node, CurrentRecord});
		}
	}

	if (CurrentRecord)
	{
		if (CurrentRecord->Node != GoalNode)
		{
			return false;
		}

		while (CurrentRecord->Node != StartNode)
		{
			OutPath.push_back(CurrentRecord->IncomingEdge);
			CurrentRecord = ClosedList.at(CurrentRecord->IncomingEdge->GetSource());
		}

		return true;
	}

	return false;
}
