#pragma once

#include <vector>

//=======================================================================================================================
class CDirectedWeightedEdge
{

public:
	inline float GetCost() const { return Cost; }

	inline int GetSource() const { return Source; }
	inline int GetSink() const { return Sink; }

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

	bool GetOutgoingEdges(int InNode, std::vector<CDirectedWeightedEdge*>& OutOutgoingEdges) const;

private:
	std::vector<CDirectedWeightedEdge> Edges;
};
