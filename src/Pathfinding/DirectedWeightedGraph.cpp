#include "DirectedWeightedGraph.h"

//=======================================================================================================================
CDirectedWeightedGraph::CDirectedWeightedGraph()
{
}

//=======================================================================================================================
CDirectedWeightedGraph::~CDirectedWeightedGraph()
{
}

//=======================================================================================================================
void CDirectedWeightedGraph::GetOutgoingEdges(int InNode, std::vector<const CDirectedWeightedEdge*>& OutOutgoingEdges) const
{
	for (const CDirectedWeightedEdge Edge : Edges)
	{
		if (Edge.GetSource() == InNode)
		{
			OutOutgoingEdges.push_back(&Edge);
		}
	}
}
