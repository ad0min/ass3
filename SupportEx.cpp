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
bool checkRootinMatrix(int **adjMatrix,int n, int i){
	for (int j = 0; j < n; j++){
		if (adjMatrix[i][j] == 1)
			return false;
	}
	return true;
}
// check Matrix cant to change a tree
bool checkMatrixisTree(int **adjMatrix, int n){
	bool check = true;
	int sumEdge = 0;
	for (int i = 0; i < n; i++){
		int count = 0;/*
		int arr[2] = { 0, 0 };*/
		for (int j = 0; j < n; j++)
			if (adjMatrix[i][j] == 1){
				count ++;/*
				int temp = (arr[0] == arr[1]) ? 0 : 1;
				if (arr[1] == 0)
					arr[temp] = j;*/
			}
		if (count > 2)
			check = false;
		sumEdge += count;
	}
	if (sumEdge != n - 1)
		check = false;
	return check;
}
int findRootMatrix(int **adjMatrix, int n){
	for (int i = 0; i < n; i++){
		if (checkRootinMatrix(adjMatrix, n, i) == true)
			return i + 1;
	}
	return 0;
}
//bool inserttoAVL(int **adjMatrix, int n, int root, AVLTree* tree){
//	bool* val = new bool[n];
//	for (int i = 0; i < n; i++)
//		val[i] = false;
//	stack* s = new stack();
//	node* temp;
//	if (val[root] == false){
//		s->push(root);
//		val[root] = true;
//		while (s->size != 0){
//			temp = s->pop();
//			tree->AVLInsert(temp->data);
//			for (int j = 0; j < n; j++){
//				if (adjMatrix[temp->data][j] == 1 && val[j] == false){
//					s->push(j);
//					
//					val[j] = true;
//				}
//			}
//		}
//	}
//}
//bool inserttoAVL(int **adjMatrix, int n, int i, AVLTree* tree){
//
//	if (!tree->root)
//		tree->AVLInsert(i);
//	int arr[] = { 0, 0 };
//	for (int j = 0; j < n; j++){
//		if (adjMatrix[i][j] == 1){
//			int temp = (arr[0] == 0) ? 0 : 1;
//			arr[temp] = j;
//		}
//		if (arr[0] != 0){
//			if (arr[1] != 0)
//				if (arr[0]<i&&arr[1]>i){
//					tree->AVLInsert(arr[0]);
//					tree->AVLInsert(arr[1]);
//
//				}
//				else
//					return false;
//			else
//				tree->AVLInsert(arr[0]);
//		}
//
//	}
//}

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