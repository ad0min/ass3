/***************************************************
DO NOT MODIFY THIS FILE
Data Structure & Algorithm Assignment 3
Graph.cpp
Purpose: Implementation of Graph related classes

@author Kien Huynh
@version 1.1 05-10-2016
***************************************************/

#include "GraphW.h"
#include "source\Heap.h"


//***************************//
//Vertex class implementation//
//***************************//

VertexW::VertexW() {
	data = 0;
	nextVertex = NULL;
	inDegree = 0;
	outDegree = 0;
	processed = false;
	firstEdge = NULL;
}

VertexW::VertexW(int _data) {
	data = _data;
	nextVertex = NULL;
	inDegree = 0;
	outDegree = 0;
	processed = false;
	firstEdge = NULL;
}

//*************************//
//Edge class implementation//
//*************************//

EdgeW::EdgeW(VertexW* _destination, int _weight) {
	destination = _destination;
	weight = _weight;
	nextEdge = NULL;
}

//**************************//
//Graph class implementation//
//**************************//

GraphW::GraphW() {
	gHead = NULL;
	size = 0;
}

GraphW::GraphW(VertexW* _gHead) {
	gHead = _gHead;
	size = 1;
}

bool GraphW::InsertVertex(VertexW* v) {
	if (gHead == NULL) {
		gHead = v;
		size++;
		return true;
	}

	VertexW* pTemp = gHead;
	VertexW* pTail = NULL;
	while (pTemp != NULL) {
		//To avoid confusion, we do not allow Nodes with same data in our graph
		if (pTemp->data == v->data) {
			cout << "\nDifferent Vertices in a Graph should have different data\n";
			cout << "Vertex insertion with data = " << pTemp->data << " failed\n";
			return false;
		}
		pTail = pTemp;
		pTemp = pTemp->nextVertex;
	}

	size++;
	pTail->nextVertex = v;
	return true;
}

bool GraphW::InsertVertex(int vData) {
	VertexW* newVertex = new VertexW(vData);
	if (gHead == NULL) {
		gHead = newVertex;
		size++;
		return true;
	}

	VertexW* pTemp = gHead;
	VertexW* pTail = NULL;
	while (pTemp != NULL) {
		//To avoid confusion, we do not allow Nodes with same data in our graph
		if (pTemp->data == vData) {
			cout << "\nDifferent Vertices in a Graph should have different data\n";
			cout << "Vertex insertion with data = " << pTemp->data << " failed\n";
			return false;
		}
		pTail = pTemp;
		pTemp = pTemp->nextVertex;
	}

	size++;
	pTail->nextVertex = newVertex;
	return true;
}


bool GraphW::VertexExist(VertexW* v) {
	VertexW* tmp = gHead;
	while (tmp != NULL) {
		if (tmp->data == v->data) {
			return true;
		}
		tmp = tmp->nextVertex;
	}
	return false;
}

bool GraphW::VertexExist(int vData) {
	VertexW* tmp = gHead;
	while (tmp != NULL) {
		if (tmp->data == vData) {
			return true;
		}
		tmp = tmp->nextVertex;
	}
	return false;
}

VertexW* GraphW::GetVertex(int vData) {
	VertexW* tmp = gHead;
	while (tmp != NULL) {
		if (tmp->data == vData) {
			return tmp;
		}
		tmp = tmp->nextVertex;
	}
	return NULL;
}

bool GraphW::InsertEdgeFromVertices(VertexW* from, VertexW* to, int weight) {
	if (from->firstEdge == NULL) {
		if (from->data == to->data) {
			return false;
		}
		from->outDegree++;
		to->inDegree++;
		from->firstEdge = new EdgeW(to, weight);
		return true;
	}
	else {
		//Check if an Edge already exists
		EdgeW* eTmp = from->firstEdge;
		EdgeW* edgeTail = eTmp;

		if (from->data == to->data) {
			//We do not allow a Vertex to point to itself
			//(It would be difficult for students to manage)
			cout << "\nA vertex should not point to itself\n";
			cout << "Edge insertion failed\n";
			return false;
		}

		while (eTmp != NULL) {
			if (eTmp->destination->data == to->data) {
				//This edge already exists, nothing to do here
				cout << "\nEdge already exists\n";
				cout << "Edge insertion failed\n";
				return false;
			}
			edgeTail = eTmp;
			eTmp = eTmp->nextEdge;
		}
		EdgeW* newEdge = new EdgeW(to, weight);
		from->outDegree++;
		to->inDegree++;
		edgeTail->nextEdge = newEdge;
	}
	return true;
}

bool GraphW::InsertEdge(VertexW* from, VertexW* to,int weight) {
	//Perform checking if [from] and [to] exist in the graph yet
	if (!VertexExist(from)) {
		InsertVertex(from);
	}

	if (!VertexExist(to)) {
		InsertVertex(to);
	}

	return InsertEdgeFromVertices(from, to, weight);
}

bool GraphW::InsertEdge(int fromData, int toData, int weight) {
	//Perform checking if [from] and [to] exist in the graph yet
	if (!VertexExist(fromData)) {
		InsertVertex(fromData);
	}

	if (!VertexExist(toData)) {
		InsertVertex(toData);
	}

	VertexW* from = GetVertex(fromData);
	VertexW* to = GetVertex(toData);

	return InsertEdgeFromVertices(from, to, weight);
}

bool GraphW::InsertEdge(VertexW* from, EdgeW* from_to){
	if (!VertexExist(from)) {
		InsertVertex(from);
	}

	VertexW* to = from_to->destination;

	if (!VertexExist(to)) {
		InsertVertex(to);
	}

	if (from->firstEdge == NULL) {
		if (from->data == to->data) {
			return false;
		}
		from->outDegree++;
		to->inDegree++;
		from->firstEdge = from_to;
		return true;
	}
	else {
		//Check if an Edge already exists
		EdgeW* eTmp = from->firstEdge;
		EdgeW* edgeTail = eTmp;

		if (from->data == to->data) {
			//We do not allow a Vertex to point to itself
			//(It would be difficult for students to manage)
			cout << "\nA vertex should not point to itself\n";
			cout << "Edge insertion failed\n";
			return false;
		}

		while (eTmp != NULL) {
			if (eTmp->destination->data == to->data) {
				//This edge already exists, nothing to do here
				cout << "\nEdge already exists\n";
				cout << "Edge insertion failed\n";
				return false;
			}
			edgeTail = eTmp;
			eTmp = eTmp->nextEdge;
		}
		from->outDegree++;
		to->inDegree++;
		edgeTail->nextEdge = from_to;
	}
	return true;
}
void GraphW::Print(){
	if (!gHead)
		return;
	VertexW* vtemp = gHead;
	while (vtemp){
		cout << vtemp->data << " -> ";
		EdgeW* etemp = vtemp->firstEdge;
		while (etemp){
			int a = etemp->destination->data;
			cout << etemp->destination->data <<"-("<<etemp->weight<<")"<< " -> ";
			etemp = etemp->nextEdge;
		}
		cout << "NULL" << endl << "|" << endl;
		vtemp = vtemp->nextVertex;
	}
	cout << "NULL" << endl;
}
void GraphW::resetVertex(){
	VertexW* vtemp = gHead;
	while (vtemp){
		vtemp->processed = false;
		vtemp = vtemp->nextVertex;
	}
}
// return true if all process == true; other return false
bool GraphW::allProcessIsTrue(){
	VertexW* vtemp = gHead;
	while (vtemp){
		if (vtemp->processed == false)
			return false;
		vtemp = vtemp->nextVertex;
	}
	return true;
}

void GraphW::DijktraUtil(VertexW *from, VertexW *to, int weight[], int S[]){
	if (from == to)
		return;
	
	EdgeW* etemp = from->firstEdge;
	S[from->data - 1] = 1;
	VertexW *destinationV;
	while (etemp){
		destinationV = etemp->destination;
		if (weight[destinationV->data - 1] > weight[from->data - 1] + etemp->weight)
			weight[destinationV->data - 1] = weight[from->data - 1] + etemp->weight;
		etemp = etemp->nextEdge;
	}
	int j = 0;
	for (; j < size; j++)
		if (!S[j] && weight[j] != MAX_INT && weight[j]!=0)
			break;
	if (j == size)
		return;
	for (int i = 0; i < size; i++)
		if (!S[i] && weight[i]<weight[j]&& weight[i]!=0)
			j=i;
	VertexW *_from = GetVertex(j+1);
	DijktraUtil(_from, to, weight, S);
}
int GraphW::Dijktra(VertexW* from, VertexW* to){
	int* weight = new int[size];
	int* S = new int[size];
	for (int i = 0; i < size; i++){
		weight[i] = MAX_INT;
		S[i] = 0;
	}
	weight[from->data-1] = 0;
	DijktraUtil(from, to, weight, S);
	return weight[to->data-1];
}
