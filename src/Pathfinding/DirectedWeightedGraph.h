#pragma once

#include <vector>

//=======================================================================================================================
class CDirectedWeightedEdge
{
public:
	CDirectedWeightedEdge();
	CDirectedWeightedEdge(float InCost, int InSource, int InSink);
	~CDirectedWeightedEdge();

	inline float GetCost() const { return Cost; }

	inline int GetSource() const { return Source; }
	inline int GetSink() const { return Sink; }

private:
	float Cost;

	int Source;
	int Sink;
};

//=======================================================================================================================
enum class EGraph
{
	NONE,
	PALLET,
	TILED
};

//=======================================================================================================================
class CDirectedWeightedGraph
{
public:
	CDirectedWeightedGraph();
	CDirectedWeightedGraph(EGraph GraphType);
	~CDirectedWeightedGraph();

	void GetOutgoingEdges(int InNode, std::vector<const CDirectedWeightedEdge*>& OutOutgoingEdges) const;

private:
	void CreatePalletGraph();
	void GenerateTiledGraph();

private:
	std::vector<CDirectedWeightedEdge> Edges;
};
