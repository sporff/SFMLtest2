#include "stdafx.h"
#include "Rack.h"


RackEdge::RackEdge() {
};


RackEdge::RackEdge(RackEdgeKey thisKey, Rack *pParentRack, RackNodePairKey nodeKeyA, RackNodePairKey nodeKeyB, double length) {
	_thisKey = thisKey;
	_pParentRack = pParentRack;

	_endNodes[0] = nodeKeyA;
	_endNodes[1] = nodeKeyB;

	_length = length;
}
RackEdge::RackEdge(const RackEdge &copyFrom) {
	_thisKey = copyFrom._thisKey;
	_pParentRack = copyFrom._pParentRack;
	_endNodes[0] = copyFrom._endNodes[0];
	_endNodes[1] = copyFrom._endNodes[1];
	_length = copyFrom._length;
}

RackEdgeKey RackEdge::GetKey() {
	return _thisKey;
}


RackNodePairKey RackEdge::GetNode(int index) {
	if (index == 0 || index == 1) {
		return this->_endNodes[index];
	}

	return NODE_INVALID;
}

RackNodePairKey RackEdge::GetOtherNodeKey(RackNodePairKey nodeKey) {
	if (nodeKey == _endNodes[0])
		return _endNodes[1];
	else if (nodeKey == _endNodes[1])
		return _endNodes[0];

	return NODE_INVALID;
}
