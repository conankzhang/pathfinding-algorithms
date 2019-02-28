#include "DivisionScheme.h"

#include "DirectedWeightedGraph.h"

bool DivisionScheme::GetWaypointPath(const std::vector<CDirectedWeightedEdge*>& Path, std::vector<ofVec2f>& OutWaypoints)
{
	for (std::vector<CDirectedWeightedEdge*>::const_reverse_iterator Edge = Path.rbegin(); Edge != Path.rend(); ++Edge )
	{
		if (!(*Edge))
		{
			return false;
		}

		OutWaypoints.push_back(Localize((*Edge)->GetSource()));
	}

	return true;
}
