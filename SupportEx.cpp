#include"source\AVLTree.h"
#include"source\InputReader.h"
#include"source\Node.h"
#include"source\Heap.h"
#include"source\Graph.h"
#include"Prototype.h"
#include"Stack.h"
#include"GraphW.h"
#include<list>
using namespace std;
//

// ex2 

bool isPrime(int number){
	if (number <= 1) return 0;
	for (int i = 1; i < sqrt(number); i++)
		if (number%i == 0)return 0;
	return 1;
}
void reverseAVLtree(Node*root, int&evenNumber, int&oddNumber, int&primeNumber){
	if (!root)
		return;
	if (root->data % 2 == 0)
		evenNumber++;
	else
		oddNumber++;
	if (isPrime(root->data))
		primeNumber++;
	reverseAVLtree(root->left, evenNumber, oddNumber, primeNumber);
	reverseAVLtree(root->right, evenNumber, oddNumber, primeNumber);
}

//ex6
int getHeight(Node* root){
	if (!root)
		return 0;
	int lHeight = getHeight(root->left);
	int rHeight = getHeight(root->right);
	return 1 + (lHeight > rHeight) ? lHeight : rHeight;
}
/*
height == 0 return root->data
*/

//ex7
// root =1;
int heightTree(Node* root){
	if (!root)
		return 0;
	int lheight = heightTree(root->left) + 1;
	int rheight = heightTree(root->right) + 1;
	return (lheight > rheight) ? lheight : rheight;
}
int printwithHeight(Node* root,int height){
	if (!root || height ==-1)
		return 0;
	if (height == 0)
		return root->data;
	int lHeight = printwithHeight(root->left, height - 1);
	int rHeight = printwithHeight(root->right, height - 1);
	return lHeight + rHeight;
}
//ex9
void AVLtoHeap(Node*root, Heap& heap){
	if (root == NULL)
		return;
	heap.InsertHeap(root->data);
	AVLtoHeap(root->left, heap);
	AVLtoHeap(root->right, heap);
}
//ex11
// create adjacent MAtrix
int** createMatrix(int size){
	int** adjacencyMatrix = new int*[size];
	for (int i = 0; i < size; i++){
		adjacencyMatrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			adjacencyMatrix[i][j] = 0;
	}
	return adjacencyMatrix;
}
void printMatrix(int** adjMatrix, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++)
			cout << adjMatrix[i][j] << "\t";
		cout << endl;
	}
}
void freeMatrix(int ** adjacencyMatrix,int size){
	for (int i = 0; i < size; i++)
		delete adjacencyMatrix[i];
	delete adjacencyMatrix;
}
// Ex12


// ex14


// ex16
int getIndex(list<int>* stack, int data){
	list<int>::iterator it = stack->begin();
	for (int i = 0; it!=stack->end(); i++, it++){
		if (*it == data)
			return i;
	}
	return -1;
}


void Tarjan_variant(Vertex *vertex, int *low, int *num, list<int>* stack, int& count){
	if (vertex->processed == true)
		return;
	int vertexIndex= count;
	low[vertexIndex] = num[vertexIndex] = count;
	count++;        
	vertex->processed = true;
	stack->push_back(vertex->data);
	Edge* etemp = vertex->firstEdge;
	while (etemp){
		Vertex* vtemp = etemp->destination;
		if (vtemp->processed == false)
			Tarjan_variant(vtemp, low, num, stack, count);
		int vtempIndex = getIndex(stack, vtemp->data);
		vtempIndex = vtempIndex < low[vtempIndex] ? vtempIndex : low[vtempIndex];
		low[vertexIndex] = vtempIndex < low[vertexIndex] ? vtempIndex : low[vertexIndex];
		etemp = etemp->nextEdge;
	}
	if (low[vertexIndex] == num[vertexIndex])
		return ;
}

void print(int * arr, int n){
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
}
bool checkSConnected(Graph *graph){
	Vertex *vtemp = graph->gHead;
	int size = graph->size;
	int *low = new int[size];
	int *num = new int[size];
	list<int> stack;
	for (int i = 0; i < size; i++){
		low[i] = 0;
		num[i] = 0;
	}
	int count = 0;
	Tarjan_variant(vtemp, low, num, &stack,count);
	for (int i = 1; i < size; i++){
		if (low[i] >= num[i]){
			delete[]low;
			delete []num;
			return false;
		}
	}
	delete[]low;
	delete[]num;
	return true;
}

//ex17

// check Matrix cant to change a tree

//bool checkCycle(Vertex* vertex){
//	if (!vertex)
//		return true;
//	bool result=true;
//	while (vertex){
//		if (vertex->processed == false){
//			vertex->processed = true;
//			Edge* etemp = vertex->firstEdge;
//			while (etemp){
//				if (etemp->destination->processed == true)
//					return false;
//				result = checkCycle(etemp->destination);
//				etemp = etemp->nextEdge;
//			}
//		}
//		vertex = vertex->nextVertex;
//	}
//	return result;
//}

bool GraphtoTree(Vertex *vertex, Node *&root){
	while (vertex){
		if (vertex->processed == false){
			Edge *etemp = vertex->firstEdge;
			vertex->processed = true;
			bool result_insert = true;
			if (etemp != NULL){// first node 
				Vertex *vtemp1 = etemp->destination;
				result_insert = insert(root, vertex->data, vtemp1->data);
				if (result_insert == false)
					return false;
				etemp = etemp->nextEdge;
				if (etemp){// second node  
					Vertex *vtemp2 = etemp->destination;
					int v1 = vtemp1->data;
					int v2 = vtemp2->data;
					int v = vertex->data;
					if (etemp->nextEdge || (v1 < v&& v2<v) || (v1>v&&v2>v)){
						return false;
					}
					else{
						result_insert = insert(root, v, v2);
						if (result_insert == false)
							return false;
						return GraphtoTree(vtemp2, root);
					}
				}
				else{
					return GraphtoTree(vtemp1, root);
				}
			}
		}
		vertex = vertex->nextVertex;
	}
}
bool GraphtoAVL(Graph *graph){
	if (sumCycle(graph->gHead)){
		cout << "Can't change this graph to avl\n";
		return false;
	}
	resetVertex(graph);
	Node *root = new Node(graph->gHead->data);
	bool result = GraphtoTree(graph->gHead, root);
	if (result)
	{
		if (checkAVl(root))
			root->PrintNode();
		else
			cout << "Can't change to avl\n";
	}
	else{
		cout << "Can't change this graph to avl\n";
	}
	return true;
}


// ex18
bool findPath(int _from, int _to, GraphW * graph){
	VertexW* from = graph->GetVertex(_from);
	VertexW* to = graph->GetVertex(_to);
	if (!from || !to)
		return false;
	graph->resetVertex();
	int minPath = graph->Dijktra(from, to);
	if (minPath == MAX_INT)
	{
		cout << "\nDon't have path connect from " << _from << " to " << _to << endl;
		return false;
	}
	cout << "\nMin path is : " << minPath << endl;
	return true;
}
//ex19
bool findPath_variant(int _from, int _to, GraphW *graph, list<int>*arr){
	VertexW* from = graph->GetVertex(_from);
	VertexW* to = graph->GetVertex(_to);
	if (!from || !to)
		return false;
	graph->resetVertex();
	int minPath = graph->Dijktra_variant(from, to, arr);
	if (minPath == MAX_INT)
	{
		cout << "\nDon't have path connect from " << _from << " to " << _to << endl;
		return false;
	}
	cout << "\nMin path is : " << minPath << endl;
	return true;

}
