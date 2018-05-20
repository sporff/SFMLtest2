#include "stdafx.h"
#include "Rack.h"



Rack::Rack() {
	_nextEdgeKey = 1;
}

Rack::~Rack() {
	_nextEdgeKey = 1;
	_nodeList.clear();
	_edgeList.clear();
}


// Adds a new node to node list
// Returns key of added node or NODE_INVALID for failure
RackNodePairKey Rack::AddNode(RackNodePairKey nodeKey) {
	auto ret = _nodeList.insert(std::make_pair(nodeKey, RackNode(nodeKey, this)));

	// check insert return value.  if bool return is true for success, return key.
	return ((ret.second == true) ? ret.first->first : NODE_INVALID);
}

uint64_t Rack::NodeListSize() {
	return (RackNodeKeyComponent)_nodeList.size();
}


// Get pointer to a node in the list
// Returns pointer on success and 'nullptr' on failure
RackNode* Rack::GetNode(RackNodePairKey nodeKey) {
	auto iter = _nodeList.find(nodeKey);

	if (iter != _nodeList.end())
		return &(iter->second);		// if this key was found, return pointer to RackNode

	return nullptr;					// if not found, return nullptr
}






// Adds a new edge to edge list
// Returns key of added edge or EDGE_INVALID for failure
// Full rollback for any error
RackEdgeKey Rack::AddEdge(RackNodePairKey nodeKeyA, RackNodePairKey nodeKeyB) {
	// Validate and locate nodes
	RackNode *pNodeA, *pNodeB;
	pNodeA = GetNode(nodeKeyA);
	pNodeB = GetNode(nodeKeyB);

	if (!pNodeA || !pNodeB) {		// If nodes don't exist, return error and do nothing
		// Log error
		std::cout << "Error adding" << std::endl;
		return EDGE_INVALID;
	}

	// Add new edge to rack's edge list
	RackEdgeKey newEdgeKey = NextEdgeKey();
	RackEdge newEdge(newEdgeKey, this, nodeKeyA, nodeKeyB, 1.0f);
	auto ret = _edgeList.insert( std::make_pair(newEdgeKey, newEdge) );

	// TODO: Error check insert to make sure it was inserted.  Full rollback if failed.

	// Add new edge to each node's list
	RackEdgeKey addedKeyA = pNodeA->AddEdge(newEdgeKey);
	RackEdgeKey addedKeyB = pNodeB->AddEdge(newEdgeKey);

	// TODO: Error check edges keys added to nodes. Full rollback if failed.

	std::cout << "Added new edge: " << newEdgeKey << std::endl;
	return newEdgeKey;
}


uint64_t Rack::EdgeListSize() {
	return _edgeList.size();
}


RackEdge* Rack::GetEdge(RackEdgeKey edgeKey) {
	auto iter = _edgeList.find(edgeKey);

	if (iter != _edgeList.end()) {
		return &(iter->second);
	}

	return nullptr;
}


// Returns the next edge key and then increments key
RackEdgeKey Rack::NextEdgeKey() {
	RackEdgeKey retKey = _nextEdgeKey;

	_nextEdgeKey++;
	if (_nextEdgeKey == 0)	_nextEdgeKey = 1;	// If wrapped (HOW?), make sure it's not allowed to be equal to 0

	// TODO: Add some error checking for collisions.  Not priority right now.

	return retKey;
}


