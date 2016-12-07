#include"source\AVLTree.h"
#include"source\InputReader.h"
#include"source\Node.h"
#include"source\Heap.h"
#include"source\Graph.h"
#include"Prototype.h"

#include"GraphW.h"
using namespace std;
//

// ex2 

bool isPrime(int number) {
	if (number <= 1) return 0;
	for (int i = 1; i < sqrt(number); i++)
		if (number%i == 0)return 0;
	return 1;
}
void reverseAVLtree(Node*root, int&evenNumber, int&oddNumber, int&primeNumber) {
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





/*
height == 0 return root->data
*/

//ex7
// root =1;
int heightTree(Node* root) {
	if (!root)
		return 0;
	int lheight = heightTree(root->left) + 1;
	int rheight = heightTree(root->right) + 1;
	return (lheight > rheight) ? lheight : rheight;
}

int printwithHeight(Node* root, int height) {
	if (!root || height == -1)
		return 0;
	if (height == 0)
		return root->data;
	int lHeight = printwithHeight(root->left, height - 1);
	int rHeight = printwithHeight(root->right, height - 1);
	return lHeight + rHeight;
}
//ex9
void AVLtoGrap(Node *root, Graph* graph) {
	if (root == NULL)
		return;
	if (root->left != NULL)
		graph->InsertEdge(root->data, root->left->data);
	if (root->right != NULL)
		graph->InsertEdge(root->data, root->right->data);
	AVLtoGrap(root->left, graph);
	AVLtoGrap(root->right, graph);
}


//ex10
// chuyển Heap sang Grap
void HeaptoGrap(Heap heap, Graph* graph, int i = 0) {
	if (i * 2 + 1 > (heap.GetSize() - 1))
		return;
	graph->InsertEdge(heap[i], heap[i * 2 + 1]);
	graph->InsertEdge(heap[i * 2 + 1], heap[i]);
	if (i * 2 + 2 > (heap.GetSize() - 1))
		return;
	graph->InsertEdge(heap[i], heap[i * 2 + 2]);
	graph->InsertEdge(heap[i * 2 + 2], heap[i]);
	HeaptoGrap(heap, graph, ++i);
}

//ex11
// create adjacent MAtrix
int** createMatrix(int size) {
	int** adjacencyMatrix = new int*[size];
	for (int i = 0; i < size; i++) {
		adjacencyMatrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			adjacencyMatrix[i][j] = 0;
	}
	return adjacencyMatrix;
}
void printMatrix(int** adjMatrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << adjMatrix[i][j] << "\t";
		cout << endl;
	}
}
void freeMatrix(int ** adjacencyMatrix, int size) {
	for (int i = 0; i < size; i++)
		delete adjacencyMatrix[i];
	delete adjacencyMatrix;
}

// Ex12

int AVLtreetoMatrix(Node* root, int**& adjMatrix, int mark = 1) {
	if (!root)
		return mark;
	if (mark == 1) {
		adjMatrix[0][1] = root->data;
		adjMatrix[1][0] = root->data;
	}
	int i;//find position of root
	for (i = 1; i <= mark; i++) {
		if (adjMatrix[0][i] == root->data)
			break;
	}
	if (root->left) {
		adjMatrix[0][++mark] = root->left->data;
		adjMatrix[mark][0] = root->left->data;
		adjMatrix[i][mark] = 1;
	}
	if (root->right) {
		adjMatrix[0][++mark] = root->right->data;
		adjMatrix[mark][0] = root->right->data;
		adjMatrix[i][mark] = 1;
	}
	mark = AVLtreetoMatrix(root->left, adjMatrix, mark);
	mark = AVLtreetoMatrix(root->right, adjMatrix, mark);
	return mark;
}

// Ex14

int getCycle(Vertex* vertex, const int data, int i = 0) {
	Edge* etemp = vertex->firstEdge;
	if (vertex->processed == false)
		vertex->processed = true;
	while (etemp) {
		if (etemp->destination->processed == false) {
			etemp->destination->processed = true;
			i = getCycle(etemp->destination, data, i);
		}
		else {
			if (etemp->destination->data == data)
				i++;
		}
		etemp = etemp->nextEdge;
	}
	return i;
}

int sumCycle(Vertex* ghead) {
	int circuit = 0, i = 0;
	Vertex *vtemp = ghead;
	while (vtemp) {
		Vertex* vvtemp = ghead;
		while (vvtemp) {
			vvtemp->processed = false;
			vvtemp = vvtemp->nextVertex;
		}
		circuit += getCycle(vtemp, vtemp->data, i);
		vtemp = vtemp->nextVertex;
	}
	return circuit;
}


//ex17

// check Matrix cant to change a tree


bool GraphtoTree(Vertex *vertex, Node *&root) {
	while (vertex) {
		if (vertex->processed == false) {
			Edge *etemp = vertex->firstEdge;
			vertex->processed = true;
			bool result_insert = true;
			if (etemp != NULL) {// first node 
				Vertex *vtemp1 = etemp->destination;
				result_insert = insert(root, vertex->data, vtemp1->data);
				if (result_insert == false)
					return false;
				etemp = etemp->nextEdge;
				if (etemp) {// second node  
					Vertex *vtemp2 = etemp->destination;
					int v1 = vtemp1->data;
					int v2 = vtemp2->data;
					int v = vertex->data;
					if (etemp->nextEdge || (v1 < v&& v2<v) || (v1>v&&v2>v)) {
						return false;
					}
					else {
						result_insert = insert(root, v, v2);
						if (result_insert == false)
							return false;
						return GraphtoTree(vtemp2, root);
					}
				}
				else {
					return GraphtoTree(vtemp1, root);
				}
			}
		}
		vertex = vertex->nextVertex;
	}
}
bool GraphtoAVL(Graph *graph) {
	if (sumCycle(graph->gHead)) {
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
	else {
		cout << "Can't change this graph to avl\n";
	}
	return true;
}

// ex18
bool findPath(int _from, int _to, GraphW * graph) {
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
bool findPath_variant(int _from, int _to, GraphW *graph, list<int>*arr) {
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


// ex20
//chuyển qua matrix và lưu vào matrix
void GraphtoMatrix(Graph* graph, string input, int **&matrix, int &vertex_count, int &edge_count) {
	int *vertexDataArr;    //chứa data của từng Vertex,
	int vertexCount;       //số Vertex
	int **edgeDataArr;     //là mảng có kích thước [edgeCount x 2] chứa từng cặp các giá trị trong file input.
	int edgeCount;         //số Edge
	ReadArrayInputOfGraph(input, vertexDataArr, vertexCount, edgeDataArr, edgeCount);
	vertex_count = vertexCount;
	edge_count = edgeCount;
	for (int i = 0; i < vertexCount; i++)
		graph->InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++) {
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	//xuất va lưu vào matrix
	matrix = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		matrix[i] = new int[vertexCount];
	}
	cout << "\nGraph to matrix: " << endl;
	cout << "0\t";
	for (int i = 0; i < vertexCount; i++)
		cout << vertexDataArr[i] << "\t";
	cout << endl;
	for (int i = 0; i < vertexCount; i++) {
		cout << vertexDataArr[i];
		for (int j = 0; j < vertexCount; j++) {
			//Lấy đỉnh có giá trị vertexDataArr[i]
			Vertex *tempVertex = graph->GetVertex(vertexDataArr[i]);
			//Lấy cạnh
			Edge *tempEdge = tempVertex->firstEdge;

			if (tempEdge != NULL && tempEdge->destination->data == vertexDataArr[j])
			{
				cout << "\t" << 1;
				matrix[i][j] = 1;
			}
			else
			{
				cout << "\t" << 0;
				matrix[i][j] = 0;
			}
		}
		cout << endl << endl;
	}
}


// Ham Isomorphic check isomorphic
// với n= vertexCount
bool Isomorphic(int **matrixa, int **matrixb, int *x, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (matrixa[i][j] != matrixb[x[i]][x[j]])
				return false;
		}
	}
	return true;
}

/*turned backward algorithm used to generate permutation */
void Permutation_check(int **matrixa, int **matrixb, int dieukien[100], int *x, int n, int i, bool &result)
{
	// Back track create permutations of n elements .
	//  ex : n = 3 --->  {1 2 3} {1 3 2} {3 1 2} ......
	for (int j = 0; j < n; j++)
	{
		if (dieukien[j] == 0) {
			x[i] = j;
			dieukien[j] = 1;
			if (i == n - 1) {
				if (Isomorphic(matrixa, matrixb, x, n) == true) {
					result = true;
				}
			}
			else {
				Permutation_check(matrixa, matrixb, dieukien, x, n, i + 1, result);
			}
			dieukien[j] = 0;
		}
	}
}