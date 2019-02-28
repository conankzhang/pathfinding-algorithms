#include "DirectedWeightedGraph.h"

//=======================================================================================================================
CDirectedWeightedEdge::CDirectedWeightedEdge() :
	Cost(-1),
	Source(-1),
	Sink(-1)
{

}

//=======================================================================================================================
CDirectedWeightedEdge::CDirectedWeightedEdge(float InCost, int InSource, int InSink) :
	Cost(InCost),
	Source(InSource),
	Sink(InSink)
{

}

//=======================================================================================================================
CDirectedWeightedEdge::~CDirectedWeightedEdge()
{

}

//=======================================================================================================================
CDirectedWeightedGraph::CDirectedWeightedGraph()
{
}

//=======================================================================================================================
CDirectedWeightedGraph::CDirectedWeightedGraph(EGraph GraphType)
{
	switch (GraphType)
	{
	case EGraph::PALLET:
		CreatePalletGraph();
		break;
	case EGraph::TILED:
		GenerateTiledGraph();
		break;
	}
}

//=======================================================================================================================
CDirectedWeightedGraph::~CDirectedWeightedGraph()
{
	Edges.clear();
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

//=======================================================================================================================
void CDirectedWeightedGraph::CreatePalletGraph()
{
	CDirectedWeightedEdge EdgeAB(5, 1, 2);
	Edges.push_back(EdgeAB);
	CDirectedWeightedEdge EdgeBA(5, 2, 1);
	Edges.push_back(EdgeBA);
	CDirectedWeightedEdge EdgeBC(5, 2, 3);
	Edges.push_back(EdgeBC);
	CDirectedWeightedEdge EdgeCB(5, 3, 2);
	Edges.push_back(EdgeCB);

	CDirectedWeightedEdge EdgeAD(4, 1, 4);
	Edges.push_back(EdgeAD);
	CDirectedWeightedEdge EdgeDA(4, 4, 1);
	Edges.push_back(EdgeDA);
	CDirectedWeightedEdge EdgeBF(4, 2, 6);
	Edges.push_back(EdgeBF);
	CDirectedWeightedEdge EdgeFB(4, 6, 2);
	Edges.push_back(EdgeFB);
	CDirectedWeightedEdge EdgeCH(4, 3, 8);
	Edges.push_back(EdgeCH);
	CDirectedWeightedEdge EdgeHC(4, 8, 3);
	Edges.push_back(EdgeHC);

	CDirectedWeightedEdge EdgeDE(2, 4, 5);
	Edges.push_back(EdgeDE);
	CDirectedWeightedEdge EdgeED(2, 5, 4);
	Edges.push_back(EdgeED);
	CDirectedWeightedEdge EdgeEF(3, 5, 6);
	Edges.push_back(EdgeEF);
	CDirectedWeightedEdge EdgeFE(3, 6, 5);
	Edges.push_back(EdgeFE);
	CDirectedWeightedEdge EdgeFG(2, 6, 7);
	Edges.push_back(EdgeFG);
	CDirectedWeightedEdge EdgeGF(2, 7, 6);
	Edges.push_back(EdgeGF);
	CDirectedWeightedEdge EdgeGH(3, 7, 8);
	Edges.push_back(EdgeGH);
	CDirectedWeightedEdge EdgeHG(3, 8, 7);
	Edges.push_back(EdgeHG);

	CDirectedWeightedEdge EdgeDL(5, 4, 12);
	Edges.push_back(EdgeDL);
	CDirectedWeightedEdge EdgeLD(5, 12, 4);
	Edges.push_back(EdgeLD);
	CDirectedWeightedEdge EdgeFI(4, 6, 9);
	Edges.push_back(EdgeFI);
	CDirectedWeightedEdge EdgeIF(4, 9, 6);
	Edges.push_back(EdgeIF);
	CDirectedWeightedEdge EdgeHK(4, 8, 11);
	Edges.push_back(EdgeHK);
	CDirectedWeightedEdge EdgeKH(4, 11, 8);
	Edges.push_back(EdgeKH);

	CDirectedWeightedEdge EdgeIJ(3, 9, 10);
	Edges.push_back(EdgeIJ);
	CDirectedWeightedEdge EdgeJI(3, 10, 9);
	Edges.push_back(EdgeJI);
	CDirectedWeightedEdge EdgeJK(2, 10, 11);
	Edges.push_back(EdgeJK);
	CDirectedWeightedEdge EdgeKJ(2, 11, 10);
	Edges.push_back(EdgeKJ);

	CDirectedWeightedEdge EdgeIM(1, 9, 13);
	Edges.push_back(EdgeIM);
	CDirectedWeightedEdge EdgeMI(1, 13, 9);
	Edges.push_back(EdgeMI);
	CDirectedWeightedEdge EdgeKP(2, 11, 16);
	Edges.push_back(EdgeKP);
	CDirectedWeightedEdge EdgePK(2, 16, 11);
	Edges.push_back(EdgePK);

	CDirectedWeightedEdge EdgeLM(5, 12, 13);
	Edges.push_back(EdgeLM);
	CDirectedWeightedEdge EdgeML(5, 13, 12);
	Edges.push_back(EdgeML);

	CDirectedWeightedEdge EdgeMN(1, 13, 14);
	Edges.push_back(EdgeMN);
	CDirectedWeightedEdge EdgeNM(1, 14, 13);
	Edges.push_back(EdgeNM);

	CDirectedWeightedEdge EdgeNO(3, 14, 15);
	Edges.push_back(EdgeNO);
	CDirectedWeightedEdge EdgeON(3, 15, 14);
	Edges.push_back(EdgeON);
	CDirectedWeightedEdge EdgeOP(2, 15, 16);
	Edges.push_back(EdgeOP);
	CDirectedWeightedEdge EdgePO(2, 16, 15);
	Edges.push_back(EdgePO);
}

//=======================================================================================================================
void CDirectedWeightedGraph::GenerateTiledGraph()
{
	int Length = 1000;
	Edges.reserve(Length * Length);

	for (int Row = 0; Row < Length; Row++)
	{
		for (int Column = 0; Column < Length; Column++)
		{
			int CurrentNode = (Row * Length) + Column;

			if (Row > 0)
			{
				CDirectedWeightedEdge NorthEdge(1, CurrentNode, CurrentNode - Length);
				Edges.push_back(NorthEdge);
			}

			if (Column < Length - 1)
			{
				CDirectedWeightedEdge EastEdge(1, CurrentNode, CurrentNode + 1);
				Edges.push_back(EastEdge);
			}

			if (Row < Length - 1)
			{
				CDirectedWeightedEdge SouthEdge(1, CurrentNode, CurrentNode + Length);
				Edges.push_back(SouthEdge);
			}

			if (Column > 0)
			{
				CDirectedWeightedEdge WestEdge(1, CurrentNode, CurrentNode - 1);
				Edges.push_back(WestEdge);
			}
		}
	}
}
