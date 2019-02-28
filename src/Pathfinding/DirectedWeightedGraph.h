#pragma once

#include <vector>

//=======================================================================================================================
class DirectedWeightedEdge
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
struct NodeRecord
{
	int Node;

	DirectedWeightedEdge IncomingEdge;

	float CostSoFar;
	float EstimatedTotalCost;
};

//=======================================================================================================================
class DirectedWeightedGraph
{
public:
	DirectedWeightedGraph();
	~DirectedWeightedGraph();

	void GetOutgoingEdges(int InNode);

private:
	std::vector<DirectedWeightedEdge> Edges;
};

