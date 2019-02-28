#pragma once

#include <vector>

//=======================================================================================================================
class CDirectedWeightedEdge
{

public:
	float GetCost();

	int GetSource();
	int GetSink();

private:
	float Cost;

	int Source;
	int Sink;

};

//=======================================================================================================================
struct SNodeRecord
{
	int Node;

	CDirectedWeightedEdge IncomingEdge;

	float CostSoFar;
	float EstimatedTotalCost;
};

//=======================================================================================================================
class CDirectedWeightedGraph
{
public:
	CDirectedWeightedGraph();
	~CDirectedWeightedGraph();

	void GetOutgoingEdges(int InNode);

private:
	std::vector<CDirectedWeightedEdge> Edges;
};

