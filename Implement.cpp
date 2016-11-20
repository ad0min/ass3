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
bool Graph::RemoveVertex(Vertex* vertex){// return false or true need be considered
	if (!vertex)
		return false;
	Vertex* temp = gHead;
	if (temp == vertex)// case first 
		gHead = gHead->nextVertex;
	else{
		// delete edge link to vertex
		while (temp->nextVertex){
			if (temp->nextVertex == vertex)
				temp->nextVertex = vertex->nextVertex;// connect linked list
			Edge* etemp = temp->firstEdge;
			if (etemp->destination == vertex){
				temp->firstEdge = etemp->nextEdge;
				delete etemp->destination;
				delete etemp;
			}
			else
				while (etemp){
					if (etemp->destination == vertex){
						Edge* eetemp = etemp;
						etemp = etemp->nextEdge;
						delete eetemp->destination;
						delete eetemp;
					}
				}
		}
	}
	// under is code to delete Edge in middle of linked list gHead 
	Edge* edge = vertex->firstEdge;
	while (edge){
		delete edge->destination;
		Edge* etemp = edge->nextEdge;
		delete edge;
		edge = etemp;
	}
	return true;
}
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
				delete eetemp->destination;
				delete eetemp;
				return true;
			}
			else{
				Edge* eetemp = etemp->nextEdge;
				while (eetemp){
					if (eetemp->destination == to)
					{
						etemp->nextEdge = eetemp->nextEdge;
						delete eetemp->destination;
						delete eetemp;
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