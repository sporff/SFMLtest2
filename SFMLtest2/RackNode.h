#pragma once

class RackNode
{
public:
	RackNode();
	RackNode(RackNodePairKey thisKey, Rack *pParentRack);
	RackNode(const RackNode& copyFrom);

	const RackNodePairKey GetKey();

	RackEdgeKey AddEdge(RackNodePairKey nodeKey);
	RackNodePairKey RemoveEdge(RackEdgeKey edgeKey);
	

	// STATIC MEMBERS METHODS
	static RackNodePairKey MakeKey(RackNodeKeyComponent row, RackNodeKeyComponent column);		// Make a 64 bit node key from 32 bit position components
	static RackNodeKeyComponent UnpackKeyRow(RackNodePairKey nodeKey);							// Extract 32 bit row from 64 bit node key
	static RackNodeKeyComponent UnpackKeyColumn(RackNodePairKey nodeKey);						// Extract 32 bit column from 64 bit node key

private:
	RackNodePairKey _thisKey;						// Key for this node
	Rack * _pParentRack;							// Parent rack
	std::unordered_set<RackEdgeKey> _edgeList;		// List of connected edges

	// Inventory (DB identifier?)
	// Occupied cart
};

