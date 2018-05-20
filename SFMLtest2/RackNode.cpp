#include "stdafx.h"
#include "Rack.h"


RackNode::RackNode() {
};


RackNode::RackNode(RackNodeKey thisKey, Rack *pParentRack) {
	_thisKey = thisKey;
	_pParentRack = pParentRack;
}


const RackNodeKey RackNode::GetKey() {
	return _thisKey;
}

RackNode::RackNode(const RackNode& copyFrom) {
	_thisKey = copyFrom._thisKey;
	_pParentRack = copyFrom._pParentRack;
}

// To be called by Rack ONLY
// Adds edge to edgeList with no error checking to see if edge or other node exist
RackEdgeKey RackNode::AddEdge(RackEdgeKey edgeKey) {
	auto ret = _edgeList.insert(edgeKey);
	return (ret.second ? *(ret.first) : EDGE_INVALID);		// return key from added element or EDGE_INVALID
}

RackNodeKey RackNode::RemoveEdge(RackEdgeKey edgeKey) {
	// Worry about this later
	return NODE_INVALID;
}






///// STATIC MEMBERS

// Make a 64 bit node key from 32 bit position components
RackNodeKey RackNode::MakeKey(RackNodeKeyComponent row, RackNodeKeyComponent column) {
	return (static_cast<RackNodeKey>(column) << 32) | static_cast<RackNodeKey>(row);
}

// Extract 32 bit row from 64 bit node key
RackNodeKeyComponent RackNode::UnpackKeyRow(RackNodeKey nodeKey) {
	return static_cast<RackNodeKeyComponent>(0x00000000FFFFFFFF & nodeKey);
}

// Extract 32 bit column from 64 bit node key
RackNodeKeyComponent RackNode::UnpackKeyColumn(RackNodeKey nodeKey) {
	return static_cast<RackNodeKeyComponent>((0xFFFFFFFF00000000 & nodeKey) >> 32);
}