#pragma once
class RackEdge
{
public:
	RackEdge();
	RackEdge(RackEdgeKey thisKey, Rack *pParentRack, RackNodePairKey nodeKeyA, RackNodePairKey nodeKeyB, double length);
	RackEdge(const RackEdge &copyFrom);

	RackEdgeKey GetKey();

	RackNodePairKey GetNode(int index);
	RackNodePairKey GetOtherNodeKey(RackNodePairKey nodeKey);		// Given a node on this edge, finds the opposite node on this edge

private:
	RackEdgeKey _thisKey;				// Key for this edge
	Rack * _pParentRack;				// Parent rack
	RackNodePairKey _endNodes[2];		// The keys for the 2 nodes this edge connects
	double _length;						// Length of this edge

	// Occupied cart
};

