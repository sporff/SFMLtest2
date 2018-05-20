




/*

class RackTote {
public:
private:
};

class RackBot {
public:

private:

};


class RackEdge {
public:
RackEdge() {
};
RackEdge(RackEdgeKey thisKey, Rack *pParentRack, RackNodePairKey nodeKeyA, RackNodePairKey nodeKeyB, double length) {
_thisKey = thisKey;
_pParentRack = pParentRack;

_endNodes[0] = nodeKeyA;
_endNodes[1] = nodeKeyB;

_length = length;
}
RackEdge(RackEdge &copyFrom) {

}

//RackNodePairKey GetOtherNode() {
//}

private:
RackEdgeKey _thisKey;				// Key for this edge
Rack * _pParentRack;				// Parent rack
RackNodePairKey _endNodes[2];		// The keys for the 2 nodes this edge connects
double _length;						// Length of this edge
};



class RackNode {
public:
RackNode() {
};
RackNode(RackNodePairKey thisKey, Rack *pParentRack) {
_thisKey = thisKey;
_pParentRack = pParentRack;
}
RackNode(RackNode& copyFrom) {
_thisKey = copyFrom._thisKey;
_pParentRack = copyFrom._pParentRack;
}

RackEdgeKey AddNeighbor(RackNodePairKey nodeKey) {
// Let rack do all of this when called
//if (_pParentRack)
//	_pParentRack->AddEdge(_thisKey, nodeKey);

return EDGE_INVALID;
}

RackNodePairKey RemoveEdge(RackEdgeKey edgeKey) {
// Worry about this later
return NODE_INVALID;
}


static RackNodePairKey MakeKey(RackNodeKeyComponent col, RackNodeKeyComponent row) {
RackNodePairKey retVal = ((uint64_t)col) << 32 | ((uint64_t)row);
}

static RackNodeKeyComponent UnpackKeyRow(RackNodePairKey nodeKey) {
return static_cast<RackNodeKeyComponent>(0x0000ffff & nodeKey);
}

static RackNodeKeyComponent UnpackKeyColumn(RackNodePairKey nodeKey) {
return static_cast<RackNodeKeyComponent>((0xffff0000 & nodeKey) >> 32);
}

private:
RackNodePairKey _thisKey;						// Key for this node
Rack * _pParentRack;							// Parent rack
//std::unordered_set<RackEdgeKey> _edgeList;		// List of connected edges



// Inventory (DB identifier?)
// Occupied cart
};



class Rack {
public:

// Adds a new node to node list
// Returns key of added node or NODE_INVALID for failure
RackNodePairKey AddNode(RackNodePairKey nodeKey) {
auto ret = _nodeList.insert(
std::pair<RackNodePairKey, RackNode>(nodeKey, RackNode(nodeKey, this))
//std::make_pair(nodeKey, RackNode(nodeKey, this))
);

// check insert return value.  if bool return is true for success, return key.
return ( (ret.second==true) ? ret.first->first : NODE_INVALID );
return NODE_INVALID;
}

// Adds a new edge to edge list
// Returns key of added edge or EDGE_INVALID for failure
RackEdgeKey AddEdge(RackNodePairKey nodeKeyA, RackNodePairKey nodeKeyB) {
// Validate and locate nodes

// Add new edge to rack

// Add new edge to each node's list

return EDGE_INVALID;
}

private:
std::unordered_map<RackNodePairKey, RackNode>	_nodeList;			// Some kind of map/list of all nodes
//std::unordered_map<RackEdgeKey, RackEdge>		_edgeList;			// Some kind of map/list of all edges

// Get pointer to a node in the list
// Returns pointer on success and 'nullptr' on failure
RackNode* GetNode(RackNodePairKey nodeKey) {
/*auto iter = _nodeList.find(nodeKey);

if (iter != _nodeList.end())
return &(iter->second);		// if this key was found, return pointer to RackNode

return nullptr;					// if not found, return nullptr
}
};*/