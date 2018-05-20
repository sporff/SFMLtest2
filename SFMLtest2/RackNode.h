#pragma once

class RackNode
{
public:
	RackNode();
	RackNode(RackNodeKey thisKey, Rack *pParentRack);
	RackNode(const RackNode& copyFrom);

	const RackNodeKey GetKey();

	RackEdgeKey AddEdge(RackNodeKey nodeKey);
	RackNodeKey RemoveEdge(RackEdgeKey edgeKey);
	

	// STATIC MEMBERS METHODS
	static RackNodeKey MakeKey(RackNodeKeyComponent row, RackNodeKeyComponent column);		// Make a 64 bit node key from 32 bit position components
	static RackNodeKeyComponent UnpackKeyRow(RackNodeKey nodeKey);							// Extract 32 bit row from 64 bit node key
	static RackNodeKeyComponent UnpackKeyColumn(RackNodeKey nodeKey);						// Extract 32 bit column from 64 bit node key

private:
	RackNodeKey _thisKey;						// Key for this node
	Rack * _pParentRack;							// Parent rack
	std::unordered_set<RackEdgeKey> _edgeList;		// List of connected edges

	// Inventory (DB identifier?)
	// Occupied cart
};

