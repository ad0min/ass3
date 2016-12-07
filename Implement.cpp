#include"source\AVLTree.h"
#include"source\InputReader.h"
#include"source\Node.h"
#include"source\Heap.h"
#include"source\Graph.h"
#include"Prototype.h"

// free memory to avltree 
void freeRoot(Node* root) {
	if (!root)
		return;
	Node* temp1 = root->left;
	Node* temp2 = root->right;
	delete root;
	root = NULL;
	freeRoot(temp1);
	freeRoot(temp2);
}


// implement function Print() in Class Graph
void Graph::Print() {
	if (!gHead)
		return;
	Vertex* vtemp = gHead;
	while (vtemp) {
		cout << vtemp->data << " -> ";
		Edge* etemp = vtemp->firstEdge;
		while (etemp) {
			int a = etemp->destination->data;
			cout << etemp->destination->data << " -> ";
			etemp = etemp->nextEdge;
		}
		cout << "NULL" << endl << "|" << endl;
		vtemp = vtemp->nextVertex;
	}
	cout << "NULL" << endl;
}

//Ex6
//removevertex
bool Graph::RemoveVertex(int reData) {
	if (!VertexExist(reData))
	{
		return false;
	}
	if (gHead == NULL)
		return false;
	if (gHead->data == reData) {
		Vertex* temp = gHead;
		gHead = gHead->nextVertex;
		delete temp;
		size--;
		return true;
	}
	Vertex* etemp = gHead;
	for (Vertex* vtemp = gHead; vtemp != NULL; vtemp = vtemp->nextVertex) {
		if (vtemp->data == reData) {
			etemp->nextVertex = vtemp->nextVertex;
			delete vtemp;
			size--;
			return true;
		}
		etemp = vtemp;
	}
	return false;
}
//removeedge
bool Graph::RemoveEdge(int fromData, int toData) {
	Vertex* temp = gHead;
	while (temp != NULL) {
		if (temp->data == fromData) {
			Edge* tempp = temp->firstEdge;
			if (tempp == NULL)
				return false;
			if (tempp->destination->data == toData) {
				Edge* Del = tempp;
				temp->firstEdge = temp->firstEdge->nextEdge;
				delete Del;
				return true;

			}
			Edge* etemp = NULL;
			for (Edge* vtemp = temp->firstEdge; vtemp != NULL; vtemp = vtemp->nextEdge) {
				if (vtemp->destination->data == toData) {

					etemp->nextEdge = vtemp->nextEdge;
					delete vtemp;
					return true;
				}
				etemp = vtemp;
			}

		}
		temp = temp->nextVertex;
	}
	return false;
}


// ex17 use for insert search NOde tree

Node* search(Node* root, int data) {
	if (!root)
		return NULL;
	if (root->data == data)
		return root;
	if (root->data > data)
		return search(root->left, data);
	else
		return search(root->right, data);
}
Node *getNodeInsert(Node* root, int to) {
	if (!root)
		return NULL;
	if (root->data > to)
	{
		if (!root->left)
			return root;
		getNodeInsert(root->left, to);
	}
	else if (root->data < to) {
		if (!root->right)
			return root;
		return getNodeInsert(root->right, to);
	}
	return NULL;
}
bool insert(Node*& root, int from, int to) {//fail
	if (!root)
		return false;
	Node *temp = search(root, from), *ptemp;
	if (!temp) {
		if (to == root->data) {
			temp = new Node(from);
			ptemp = root;
			if (temp->data > to) {
				while (ptemp->right)
					ptemp = ptemp->right;
				if (ptemp->data >= from)
					return false;
				temp->left = root;
			}
			if (temp->data < to) {
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
	else {
		ptemp = getNodeInsert(root, to);
		if (ptemp == temp) {
			if (temp->data > to) {
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
bool checkAVl(Node* root) {
	if (!root)
		return true;
	int left = heightTree(root->left);
	int right = heightTree(root->right);
	int sub = (int)abs(left - right);
	if (sub <= 1) {
		bool l = checkAVl(root->left);
		bool r = checkAVl(root->right);
		return (l || r);
	}
	else
		return false;
}

void resetVertex(Graph* graph) {
	Vertex* vtemp = graph->gHead;
	while (vtemp) {
		vtemp->processed = false;
		vtemp = vtemp->nextVertex;
	}
}