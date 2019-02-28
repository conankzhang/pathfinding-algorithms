#pragma once

#include <vector>

//=======================================================================================================================
class CDirectedWeightedEdge
{

public:
	inline float GetCost() { return Cost; }

	inline int GetSource() { return Source; }
	inline int GetSink() { return Sink; }

private:
	float Cost;

	int Source;
	int Sink;
};

//=======================================================================================================================
class CDirectedWeightedGraph
{
public:
	CDirectedWeightedGraph();
	~CDirectedWeightedGraph();

	bool GetOutgoingEdges(int InNode, std::vector<CDirectedWeightedEdge*>& OutOutgoingEdges);

private:
	std::vector<CDirectedWeightedEdge> Edges;
};
