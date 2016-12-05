#include"source\AVLTree.h"
#include"source\InputReader.h"
#include"source\Node.h"
#include"source\Heap.h"
#include"source\Graph.h"
#include"Prototype.h"

// free memory to avltree 
void freeRoot(Node* root){
	if (!root)
		return;
	Node* temp1 = root->left;
	Node* temp2 = root->right;
	delete root;
	root = NULL;
	freeRoot(temp1);
	freeRoot(temp2);
}
// free memory Graph
void freeGraph(Graph* graph){
	Vertex* vertex = graph->gHead;
	while (vertex){
		Vertex* temp = vertex->nextVertex;
		graph->RemoveVertex(vertex);
		vertex = temp;
	}
}


// implement function Print() in Class Graph
void Graph::Print(){
	if (!gHead)
		return;
	Vertex* vtemp = gHead;
	while (vtemp){
		cout << vtemp->data<<" -> ";
		Edge* etemp = vtemp->firstEdge;
		while (etemp){
			int a = etemp->destination->data;
			cout << etemp->destination->data<<" -> ";
			etemp = etemp->nextEdge;
		}
		cout <<"NULL"<< endl<<"|"<<endl;
		vtemp = vtemp->nextVertex;
	}
	cout << "NULL"<<endl;
}

// Implement function RemoveVertex(Vertex*)
// code again !
bool Graph::RemoveVertex(int data){
	Vertex* vertex = this->GetVertex(data);
	return RemoveVertex(vertex);
}
bool Graph::RemoveEdge(Vertex* from, Vertex* to){
	if (!from || !to)
		return false;
	Vertex* vtemp = gHead;
	while (vtemp){
		if (vtemp == from){
			Edge* etemp = vtemp->firstEdge;
			if (etemp->destination == to)
			{
				Edge* eetemp = etemp;
				vtemp->firstEdge = etemp->nextEdge;
				delete eetemp;
				return true;
			}
			else{
				Edge* eetemp = etemp->nextEdge;
				while (eetemp){
					if (eetemp->destination == to)
					{
						etemp->nextEdge = eetemp->nextEdge;
						delete eetemp;
						return true;
					}
					etemp = eetemp;
					eetemp = eetemp->nextEdge;
				}
			}
		}
		vtemp = vtemp->nextVertex;
	}
	return false;
}
bool Graph::RemoveEdge(int from, int to){
	Vertex *_from = GetVertex(from);
	Vertex *_to = GetVertex(to);
	return RemoveEdge(_from, _to);
}