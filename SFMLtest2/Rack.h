#pragma once

//typedef std::pair<int, int> RackNodePairKey;
/*typedef union  RNPK {
uint64_t int64;
uint32_t int32pair[2];
} RackNodePairKey;*/

// Node key type
typedef uint64_t RackNodeKeyComponent;
typedef uint64_t RackNodePairKey;
const RackNodePairKey NODE_INVALID{ 0 };

// Edge key type
typedef uint64_t RackEdgeKey;
const RackEdgeKey EDGE_INVALID = 0;

// Bot key type
typedef uint64_t RackBotKey;
const RackBotKey BOT_INVALID = 0;

// Forward declares since these all need to know about each other
class Rack;
class RackTote;
class RackBot;
class RackEdge;
class RackNode;
class RackBot;



#include "RackTote.h"
#include "RackBot.h"
#include "RackEdge.h"
#include "RackNode.h"





class Rack
{
public:
	Rack();
	~Rack();

	RackNodePairKey AddNode(RackNodePairKey nodeKey);		// Adds a new node to node list
	uint64_t NodeListSize();								// Gets size of node list
	RackNode* GetNode(RackNodePairKey nodeKey);				// Get pointer to a node in the list
	
	RackEdgeKey AddEdge(RackNodePairKey nodeKeyA, RackNodePairKey nodeKeyB);		// Adds a new edge to edge list
	uint64_t EdgeListSize();														// Gets size of edge list
	RackEdge* GetEdge(RackEdgeKey edgeKey);											// Gets an edge by edge key

private:
	std::unordered_map<RackNodePairKey, RackNode>	_nodeList;			// List of all nodes

	std::unordered_map<RackEdgeKey, RackEdge>		_edgeList;			// List of all edges
	RackEdgeKey _nextEdgeKey;
	RackEdgeKey NextEdgeKey();											// Gets the next available edge key and increments for next use

	std::unordered_map<RackBotKey, RackBot>			_botList;
};

