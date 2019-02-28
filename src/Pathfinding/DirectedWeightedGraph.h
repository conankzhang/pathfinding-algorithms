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
	CDirectedWeightedGraph(EGraph GraphType, int InScreenWidth, int InScreenHeight, int InTileWidth, int InTileHeight);
	~CDirectedWeightedGraph();

	void GetOutgoingEdges(int InNode, std::vector<const CDirectedWeightedEdge*>& OutOutgoingEdges) const;
	int GetNodeAt(int Row, int Col);

private:
	void CreatePalletGraph();
	void GenerateTiledGraph();

private:
	std::vector<CDirectedWeightedEdge> Edges;
	std::vector<std::vector<int>> Nodes;

	int ScreenWidth;
	int ScreenHeight;

	int TileWidth;
	int TileHeight;
};
