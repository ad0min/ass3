#include<iostream>
#include"source\AVLTree.h"
#include"source\InputReader.h"
#include"source\Node.h"
#include"source\Heap.h"
#include"source\Graph.h"
#include"Prototype.h"
#include"GraphW.h"
using namespace std;
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>

void ex1(){
	int n = 0;
	while (1){
		cout << "How many element would you like to sort? ";
		cin >> n;
		if (n >= '0x48'&& n<='0x57')// check number again 
			break;
		cout << "Invalid number! Please try again";
	}
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cout << "Input element " << i << " :";
		cin >> arr[i];
	}
	AVLTree* tree =new AVLTree(AVLTree::ArrayToAVL(arr, n).root);
	tree->PrintAVL();
	freeRoot(tree->root);
	delete tree;
}
void ex2(){
	int n = 0;
	int *arr;
	ReadArrayInput("input/E2.txt", arr, n);
	AVLTree* tree =new AVLTree( AVLTree::ArrayToAVL(arr, n).root);
	tree->PrintAVL();
	int input = 0;
	while (1){
		cout << "Input number of node needed to remove: ";// PAY ATTENTION: how is going if end tree?
		cin >> input;
		//more function to check input to valid 
		if (input == -1)
			break;
		tree->AVLDelete(input);
		tree->PrintAVL();
	}
	freeRoot(tree->root);
	delete tree;
}
void ex3(){
	int n = 0;
	int *arr;
	ReadArrayInput("input/E2.txt", arr, n);
	AVLTree* tree = new AVLTree(AVLTree::ArrayToAVL(arr, n).root);
	int evenNumber = 0, oddNumber = 0, primeNumber = 0;
	tree->PrintAVL();
	reverseAVLtree(tree->root, evenNumber, oddNumber, primeNumber);
	cout << "Total of even number in AVLTree: " << evenNumber<<endl;
	cout << "Total of odd number in AVLTree: " << oddNumber << endl;
	cout << "Total of prime number in AVlTree: " << primeNumber << endl;
	freeRoot(tree->root);
	delete tree;
}
void ex4(){
	int n = 0;
	while (1){
		cout << "How many element would you like to sort? ";
		cin >> n;// more check input
		if (n > 0)
			break;
		cout << "Invalid number! Please try again";
	}
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cout << "Input element " << i << " :";
		cin >> arr[i];
	}
	Heap* heap =new Heap( Heap::ArrayToHeap(arr, n));
	heap->PrintHeapTree();
	//  need free head (protected)
}
void freeGraph(Graph*);
void ex5(){
	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	ReadArrayInputOfGraph("input/E5.txt", vertexDataArr, vertexCount, edgeDataArr,
		edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < edgeCount; i++){
		int a1=edgeDataArr[i][0];
		int a2=edgeDataArr[i][1];
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}

	graph->Print();
	for (int i = 0; i < edgeCount ; i++)
		delete edgeDataArr[i];
	delete vertexDataArr;
	delete edgeDataArr;
	//freeGraph(graph);// Wrong
	delete graph;
}
void ex6(){
	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	ReadArrayInputOfGraph("input/E6.txt", vertexDataArr, vertexCount, edgeDataArr,
		edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < edgeCount; i++){
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	Vertex * from = graph->GetVertex(131);
	Vertex *to = graph->GetVertex(648);
	graph->RemoveEdge(from, to);
	graph->Print();


	//
	//int input = 0;
	//while (1){
	//	cout << "Input number of node needed to remove: ";
	//	cin >> input;
	//	//more function to check input to valid 
	//	if (input == -1)
	//		break;
	//	graph->RemoveVertex(input);
	//	graph->Print();
	//}
	//for (int i = 0; i < edgeCount; i++)
	//	delete edgeDataArr[i];
	//delete vertexDataArr;
	//delete edgeDataArr;
	//freeGraph(graph);
	//delete graph;
}
void ex7(){//done
	int n = 0;
	int *arr;
	ReadArrayInput("input/E7.txt", arr, n);
	AVLTree* tree = new AVLTree(AVLTree::ArrayToAVL(arr, n).root);
	tree->PrintAVL();
	int height = heightTree(tree->root);
	for (int i = 0;i< height; i++){
		int sum = printwithHeight(tree->root, i);
		cout << sum<<endl;
	}
	freeRoot(tree->root);
	delete tree;
}
void ex8(){//done
	int n = 0;
	int*arr;
	ReadArrayInput("input/E8.txt", arr, n);
	Heap heap = Heap::ArrayToHeap(arr, n);
	heap.PrintHeapTree();

	for (int i = 0; i< n; i = 2 * i + 1){
		int sum = 0;
		for (int j = i; j < 2 * i + 1 && j<n; j++)
		{
			sum += heap[j];
		}
		cout << sum << endl;
	}
	//free heap
}
void ex9(){
	int n = 0;
	int *arr;
	ReadArrayInput("input/E9.txt", arr, n);
	AVLTree tree = AVLTree::ArrayToAVL(arr, n).root;
	tree.PrintAVL();
	Heap heap = Heap();
	AVLtoHeap(tree.root, heap);
	cout << " AVL to Heap :" << endl;
	heap.PrintHeapTree();
	freeRoot(tree.root);
	// free heap
}

//void HeaptoGraph(Heap heap, Graph* graph, int i=0);
//ex10
void HeaptoGrap(Heap heap, Graph* graph, int i=0){
	if (i * 2 + 1 > heap.GetSize())
		return;
	graph->InsertEdge(heap[i], heap[i * 2 + 1]);
	graph->InsertEdge(heap[i * 2 + 1], heap[i]);
	if (i * 2 + 2 > heap.GetSize())
		return;
	graph->InsertEdge(heap[i], heap[i * 2 + 2]);
	graph->InsertEdge(heap[i * 2 + 2], heap[i]);
	HeaptoGrap(heap, graph, ++i);
}
void ex10(){
	int n = 0;
	int*arr;
	ReadArrayInput("input/E10.txt", arr, n);
	Heap heap = Heap::ArrayToHeap(arr, n);
	heap.PrintHeapTree();
	Graph* graph = new Graph();
	HeaptoGrap(heap, graph);
	cout << endl;
	graph->Print();
	// free graph
	//free heap
}
void ex11(){
	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	ReadArrayInputOfGraph("input/E11.txt", vertexDataArr, vertexCount, edgeDataArr,
		edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < edgeCount; i++){
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	int size = graph->size + 1;
	int ** adjMatrix = createMatrix(size);

	Vertex* vtemp = graph->gHead;
	for (int i = 1; i < size; i++){
		adjMatrix[i][0] = vtemp->data;
		adjMatrix[0][i] = vtemp->data;
		vtemp = vtemp->nextVertex;
	}
	vtemp = graph->gHead;
	for (int i = 1; i < size; i++){
		Edge* etemp = vtemp->firstEdge;
		while (etemp){
			for (int j = 1; j < size; j++){
				if (adjMatrix[0][j] == etemp->destination->data)
					adjMatrix[i][j] = 1;
			}
			etemp = etemp->nextEdge;
		}
		vtemp = vtemp->nextVertex; 
	}
	printMatrix(adjMatrix, size);

	freeMatrix(adjMatrix, size);
	//free graph
}
//void AVLtreetoMatrix(Node*, int**&,int matrix=1);
int AVLtreetoMatrix(Node* root, int**& adjMatrix, int mark = 1){
	if (!root)
		return mark;
	if (mark == 1){
		adjMatrix[0][1] = root->data;
		adjMatrix[1][0] = root->data;
	}
	int i;//find position of root
	for (i = 1; i <= mark; i++){
		if (adjMatrix[0][i] == root->data)
			break;
	}
	if (root->left){
		adjMatrix[0][++mark] = root->left->data;
		adjMatrix[mark][0] = root->left->data;
		adjMatrix[i][mark] = 1;
	}
	if (root->right){
		adjMatrix[0][++mark] = root->right->data;
		adjMatrix[mark][0] = root->right->data;
		adjMatrix[i][mark] = 1;
	}
	mark =AVLtreetoMatrix(root->left, adjMatrix, mark);
	mark =AVLtreetoMatrix(root->right, adjMatrix, mark);
	return mark;
}
void ex12(){
	int n = 0;
	int *arr;
	ReadArrayInput("input/E12.txt", arr, n);
	AVLTree tree = AVLTree::ArrayToAVL(arr, n).root;
	tree.PrintAVL();
	int** adjMatrix = createMatrix(n+1);
	AVLtreetoMatrix(tree.root, adjMatrix);
	printMatrix(adjMatrix, n + 1);
	freeMatrix(adjMatrix,n+1);
	freeRoot(tree.root);
}
void ex13(){
	int n = 0;
	int*arr;
	ReadArrayInput("input/E13.txt", arr, n);
	Heap heap = Heap::ArrayToHeap(arr, n);
	heap.PrintHeapTree();
	int size = n + 1;
	int** adjMatrix = createMatrix(size);
	for (int i = 1; i < size; i++){
		adjMatrix[0][i] = heap[i-1];
		adjMatrix[i][0] = heap[i-1];
	}
	for (int i = 1; i <= (size-1) / 2; i++){
		adjMatrix[i][2 * i ] = 1;
		adjMatrix[2 * i ][i] = 1;
		if (i * 2 + 1 <= n){
			adjMatrix[i][2 * i + 1] = 1;
			adjMatrix[2 * i + 1][i] = 1;
		}
	}
	printMatrix(adjMatrix, size);
	freeMatrix(adjMatrix,size);
	//free Heap
}
int getCycle(Vertex* vertex, const int data, int i = 0){
	Edge* etemp = vertex->firstEdge;
	if (vertex->processed == false)
		vertex->processed = true;
	while (etemp){
		if (etemp->destination->processed == false){
			etemp->destination->processed == true;
			i = getCycle(etemp->destination, data, i);
		}
		else{
			if (etemp->destination->data == data)
				i++;
		}
		etemp = etemp->nextEdge;
	}
	return i;
}
void ex14(){
	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	ReadArrayInputOfGraph("input/E14.txt", vertexDataArr, vertexCount, edgeDataArr,
		edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < edgeCount; i++){
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	Vertex* vtemp = graph->gHead;
	int circuit = 0;
	while (vtemp){
		Vertex* vvtemp = graph->gHead;
		while (vvtemp){
			vvtemp->processed = false;
			vvtemp = vvtemp->nextVertex;
		}
		circuit += getCycle(vtemp, vtemp->data);
		vtemp = vtemp->nextVertex;
	}
	cout <<"\nAll of circuit in graph is: "<< circuit;
}
void ex15(){
	int n = 0;
	int ** adjMatrix;
	ReadAdjacencyMat("input/E15.txt", adjMatrix, n);
	printMatrix(adjMatrix, n);
	Graph* graph = new Graph();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (adjMatrix[i][j] == 1)
				graph->InsertEdge(i+1, j+1);
		}
	graph->Print();
	freeMatrix(adjMatrix, n);
	//free graph
}
void ex16(){
	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	ReadArrayInputOfGraph("input/E16.txt", vertexDataArr, vertexCount, edgeDataArr,
		edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < edgeCount; i++){
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	bool check = checkSConnected(graph);
	if (check == false)
		cout << endl << "This graph isn't strong connected\n";
	else
		cout << endl << "This graph is strong connected\n";
	//free Graph
	// free
}
void ex17(){
	int n = 0;
	int ** adjMatrix;
	ReadAdjacencyMat("input/E17.txt", adjMatrix, n);
	printMatrix(adjMatrix, n);
	//check matrix is tree avl
	Graph* graph = new Graph();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (adjMatrix[i][j] == 1)
				graph->InsertEdge(i + 1, j + 1);
	
	graph->Print();
	GraphtoAVL(graph);
	freeMatrix(adjMatrix, n);
}
void ex18(){
	int n = 0;
	int ** adjMatrix;
	ReadAdjacencyMat("input/E18.txt", adjMatrix, n);
	printMatrix(adjMatrix, n);
	GraphW* graph = new GraphW();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (adjMatrix[i][j] != 0)
				graph->InsertEdge(i + 1, j + 1, adjMatrix[i][j]);
	graph->Print();
	// input two vertex
	int from, to;
	cout << "Input first Vertex: ";
	cin >> from;
	cout << "Input second Vertex: ";
	cin >> to;
	//check
	findPath(from, to, graph);
	// more check 
}
void ex19(){
	int n = 0;
	int ** adjMatrix;
	ReadAdjacencyMat("input/E18.txt", adjMatrix, n);
	printMatrix(adjMatrix, n);
	GraphW* graph = new GraphW();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (adjMatrix[i][j] != 0)
				graph->InsertEdge(i + 1, j + 1, adjMatrix[i][j]);
	graph->Print();
	// input two vertex
	int from, to, k;
	list<int> arr;
	cout << "\nInput first Vertex: ";
	cin >> from;
	cout << "\nInput second Vertex: ";
	cin >> to;
	findPath(from, to, graph);
	cout << "\nInput -1 to exit\n";
	while (1){
		while (1){
			cout << "\nInput k Vertex: ";
			cin >> k;
			if (k == -1)
				break;
			arr.push_back(k);
		}
		findPath_variant(from, to, graph,&arr);
		cout << "\nDo you want to continue? 0= true, -1=false: ";
		cin >> k;
		if (k == -1)
			break;
	}
}