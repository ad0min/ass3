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
//void freeGraph(Graph* graph){
//	Vertex* vertex = graph->gHead;
//	while (vertex){
//		Vertex* temp = vertex->nextVertex;
//		graph->RemoveVertex(vertex);
//		vertex = temp;
//	}
//}


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
//bool Graph::RemoveVertex(int data){
//	Vertex* vertex = this->GetVertex(data);
//	return RemoveVertex(vertex);
//}
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


// ex17 use for insert search NOde tree

Node* search(Node* root, int data){
	if (!root)
		return NULL;
	if (root->data == data)
		return root;
	if (root->data > data)
		return search(root->left, data);
	else
		return search(root->right, data);
}
Node *getNodeInsert(Node* root, int to){
	if (!root)
		return NULL;
	if (root->data > to)
	{
		if (!root->left)
			return root;
		getNodeInsert(root->left, to);
	}
	else if (root->data < to){
		if (!root->right)
			return root;
		return getNodeInsert(root->right, to);
	}
	return NULL;
}
bool insert(Node*& root, int from, int to){//fail
	if (!root)
		return false;
	Node *temp = search(root, from), *ptemp;
	if (!temp){
		if (to == root->data){
			temp = new Node(from);
			ptemp = root;
			if (temp->data > to){
				while (ptemp->right)
					ptemp = ptemp->right;
				if (ptemp->data >= from)
					return false;
				temp->left = root;
			}
			if (temp->data < to){
				while (ptemp->left)
					ptemp = ptemp->left;
				temp->left = root;
				if (ptemp->data <= from)
					return false;
				temp->right = root;
			}
			root = temp;
			return true;
		}
		return false;
	}
	else{
		ptemp = getNodeInsert(root, to);
		if (ptemp == temp){
			if (temp->data > to){
				temp->left = new Node(to);
			}
			if (temp->data < to)
				temp->right = new Node(to);
			return true;
		}
		else
			return false;
	}
}
bool checkAVl(Node* root){
	if (!root)
		return true;
	int left = heightTree(root->left);
	int right = heightTree(root->right);
	int sub = (int)abs(left - right);
	if (sub <= 1){
		bool l = checkAVl(root->left);
		bool r = checkAVl(root->right);
		return (l || r);
	}
	else
		return false;
}

void resetVertex(Graph* graph){
	Vertex* vtemp = graph->gHead;
	while (vtemp){
		vtemp->processed = false;
		vtemp = vtemp->nextVertex;
	}
}