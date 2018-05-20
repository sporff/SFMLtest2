#pragma once

// Generic key type. Usable for any key type, but keep separates for readability.
typedef uint64_t RackUID;

// Node key type
typedef RackUID RackNodeKey;
const RackNodeKey NODE_INVALID{ 0 };
typedef uint32_t RackNodeKeyComponent;		// X or Y component of a Node, if used

// Edge key type
typedef RackUID RackEdgeKey;
const RackUID EDGE_INVALID = 0;

// Bot key type
typedef RackUID RackBotKey;
const RackUID BOT_INVALID = 0;

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

	RackNodeKey AddNode(RackNodeKey nodeKey);		// Adds a new node to node list
	uint64_t NodeListSize();								// Gets size of node list
	RackNode* GetNode(RackNodeKey nodeKey);				// Get pointer to a node in the list
	
	RackEdgeKey AddEdge(RackNodeKey nodeKeyA, RackNodeKey nodeKeyB);		// Adds a new edge to edge list
	uint64_t EdgeListSize();														// Gets size of edge list
	RackEdge* GetEdge(RackEdgeKey edgeKey);											// Gets an edge by edge key

private:
	std::unordered_map<RackNodeKey, RackNode>	_nodeList;			// List of all nodes

	std::unordered_map<RackEdgeKey, RackEdge>		_edgeList;			// List of all edges
	RackEdgeKey _nextEdgeKey;
	RackEdgeKey NextEdgeKey();											// Gets the next available edge key and increments for next use

	std::unordered_map<RackBotKey, RackBot>			_botList;
};

