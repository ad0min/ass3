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

void ex1() {
	int n = 0;
	while (1) {
		cout << "How many element would you like to sort? ";
		cin >> n;
		if (n >= 0 && n <= 9)// check number again 
			break;
		cout << "Invalid number! Please try again";
	}
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Input element " << i << " :";
		cin >> arr[i];
	}
	AVLTree* tree = new AVLTree(AVLTree::ArrayToAVL(arr, n).root);
	tree->PrintAVL();
	freeRoot(tree->root);
	delete tree;
}

void ex2() {
	int n = 0;
	int *arr;
	ReadArrayInput("input/E2.txt", arr, n);
	AVLTree* tree = new AVLTree(AVLTree::ArrayToAVL(arr, n).root);
	tree->PrintAVL();
	int input = 0;
	while (1) {
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

void ex3() {
	int n = 0;
	int *arr;
	ReadArrayInput("input/E2.txt", arr, n);
	AVLTree* tree = new AVLTree(AVLTree::ArrayToAVL(arr, n).root);
	int evenNumber = 0, oddNumber = 0, primeNumber = 0;
	tree->PrintAVL();
	reverseAVLtree(tree->root, evenNumber, oddNumber, primeNumber);
	cout << "Total of even number in AVLTree: " << evenNumber << endl;
	cout << "Total of odd number in AVLTree: " << oddNumber << endl;
	cout << "Total of prime number in AVlTree: " << primeNumber << endl;
	freeRoot(tree->root);
	delete tree;
}

void ex4() {
	int n = 0;
	while (1) {
		cout << "How many element would you like to sort? ";
		cin >> n;// more check input
		if (n > 0)
			break;
		cout << "Invalid number! Please try again";
	}
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Input element " << i << " :";
		cin >> arr[i];
	}
	Heap* heap = new Heap(Heap::ArrayToHeap(arr, n));
	heap->PrintHeapTree();
}

void ex5() {
	int *vertexDataArr;    //chứa data của từng Vertex,
	int vertexCount;       //số Vertex
	int **edgeDataArr;     //là mảng có kích thước [edgeCount x 2] chứa từng cặp các giá trị trong file input.
	int edgeCount;         //số Edge
	ReadArrayInputOfGraph("input/E5.txt", vertexDataArr, vertexCount, edgeDataArr, edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < vertexCount; i++)
		graph->InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++) {
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}

	graph->Print();
	for (int i = 0; i < edgeCount; i++)
		delete edgeDataArr[i];
	delete vertexDataArr;
	delete edgeDataArr;
	delete graph;
}

void ex6() {
	int *vertexDataArr;    //chứa data của từng Vertex,
	int vertexCount;       //số Vertex
	int **edgeDataArr;     //là mảng có kích thước [edgeCount x 2] chứa từng cặp các giá trị trong file input.
	int edgeCount;         //số Edge
	ReadArrayInputOfGraph("input/E6.txt", vertexDataArr, vertexCount, edgeDataArr, edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < vertexCount; i++)
		graph->InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++) {
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	int input;
	while (1) {
		Vertex* temp = graph->gHead;
		if (!temp) {
			cout << "deleted all vertex !"; 
			break;
		}
		cout << "Input number of node needed to remove: ";
		cin >> input;
		if (input == -1) //input =-1 stop
			break;
		while (temp != NULL) {
			graph->RemoveEdge(temp->data, input);   //delete edge
			temp = temp->nextVertex;
		}
		graph->RemoveVertex(input);            //delete vertex 
		graph->Print();
	}
	for (int i = 0; i < edgeCount; i++)
		delete edgeDataArr[i];
	delete vertexDataArr;
	delete edgeDataArr;
	delete graph;
}

void ex7() {//done
	int n = 0;
	int *arr;
	ReadArrayInput("input/E7.txt", arr, n);
	AVLTree* tree = new AVLTree(AVLTree::ArrayToAVL(arr, n).root);
	tree->PrintAVL();
	int height = heightTree(tree->root);
	for (int i = 0; i< height; i++) {
		int sum = printwithHeight(tree->root, i);
		cout << sum << endl;
	}
	freeRoot(tree->root);
	delete tree;
}

void ex8() {//done
	int n = 0;
	int*arr;
	ReadArrayInput("input/E8.txt", arr, n);
	Heap heap = Heap::ArrayToHeap(arr, n);
	heap.PrintHeapTree();

	for (int i = 0; i< n; i = 2 * i + 1) {
		int sum = 0;
		for (int j = i; j < 2 * i + 1 && j<n; j++)
		{
			sum += heap[j];
		}
		cout << sum << endl;
	}
}

void ex9() {
	int n = 0;
	int *arr;
	ReadArrayInput("input/E9.txt", arr, n);
	AVLTree tree = AVLTree::ArrayToAVL(arr, n).root;
	tree.PrintAVL();
	Graph* graph = new Graph();
	//chuyển
	AVLtoGrap(tree.root,graph);
	cout << endl;
	graph->Print();
	freeRoot(tree.root);
}

void ex10() {
	int n = 0, i = 0;
	int*arr;
	ReadArrayInput("input/E10.txt", arr, n);
	Heap heap = Heap::ArrayToHeap(arr, n);
	heap.PrintHeapTree();
	Graph* graph = new Graph();
	HeaptoGrap(heap, graph,i);
	cout << endl;
	graph->Print();
}

void ex11() {
	int *vertexDataArr;    //chứa data của từng Vertex,
	int vertexCount;       //số Vertex
	int **edgeDataArr;     //là mảng có kích thước [edgeCount x 2] chứa từng cặp các giá trị trong file input.
	int edgeCount;         //số Edge
	ReadArrayInputOfGraph("input/E11.txt", vertexDataArr, vertexCount, edgeDataArr,
		edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < vertexCount; i++)
		graph->InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++) {
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	int size = graph->size + 1;
	int ** adjMatrix = createMatrix(size);

	Vertex* vtemp = graph->gHead;
	for (int i = 1; i < size; i++) {
		adjMatrix[i][0] = vtemp->data;
		adjMatrix[0][i] = vtemp->data;
		vtemp = vtemp->nextVertex;
	}
	vtemp = graph->gHead;
	for (int i = 1; i < size; i++) {
		Edge* etemp = vtemp->firstEdge;
		while (etemp) {
			for (int j = 1; j < size; j++) {
				if (adjMatrix[0][j] == etemp->destination->data)
					adjMatrix[i][j] = 1;
			}
			etemp = etemp->nextEdge;
		}
		vtemp = vtemp->nextVertex;
	}
	printMatrix(adjMatrix, size);

	freeMatrix(adjMatrix, size);
}

void ex12() {
	int n = 0, i = 1;
	int *arr;
	ReadArrayInput("input/E12.txt", arr, n);
	AVLTree tree = AVLTree::ArrayToAVL(arr, n).root;
	tree.PrintAVL();
	int** adjMatrix = createMatrix(n + 1);
	AVLtreetoMatrix(tree.root, adjMatrix, i);
	printMatrix(adjMatrix, n + 1);
	freeMatrix(adjMatrix, n + 1);
	freeRoot(tree.root);
}

void ex13() {
	int n = 0;
	int*arr;
	ReadArrayInput("input/E13.txt", arr, n);
	Heap heap = Heap::ArrayToHeap(arr, n);
	heap.PrintHeapTree();
	int size = n + 1;
	int** adjMatrix = createMatrix(size);
	for (int i = 1; i < size; i++) {
		adjMatrix[0][i] = heap[i - 1];
		adjMatrix[i][0] = heap[i - 1];
	}
	for (int i = 1; i <= (size - 1) / 2; i++) {
		adjMatrix[i][2 * i] = 1;
		adjMatrix[2 * i][i] = 1;
		if (i * 2 + 1 <= n) {
			adjMatrix[i][2 * i + 1] = 1;
			adjMatrix[2 * i + 1][i] = 1;
		}
	}
	printMatrix(adjMatrix, size);
	freeMatrix(adjMatrix, size);
}

void ex14() {
	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	ReadArrayInputOfGraph("input/E14.txt", vertexDataArr, vertexCount, edgeDataArr,
		edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < edgeCount; i++) {
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	int circuit = sumCycle(graph->gHead);
	cout << "\nAll of circuit in graph is: " << circuit << "\n";
}

void ex15() {
	int n = 0;
	int ** adjMatrix;
	ReadAdjacencyMat("input/E15.txt", adjMatrix, n);
	printMatrix(adjMatrix, n);
	Graph* graph = new Graph();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (adjMatrix[i][j] == 1)
				graph->InsertEdge(i + 1, j + 1);
		}
	graph->Print();
	freeMatrix(adjMatrix, n);
}

void ex16() {
	int *vertexDataArr;    //chứa data của từng Vertex,
	int vertexCount;       //số Vertex
	int **edgeDataArr;     //là mảng có kích thước [edgeCount x 2] chứa từng cặp các giá trị trong file input.
	int edgeCount;         //số Edge
	ReadArrayInputOfGraph("input/E16.txt", vertexDataArr, vertexCount, edgeDataArr,
		edgeCount);
	Graph* graph = new Graph();
	for (int i = 0; i < vertexCount; i++)
		graph->InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++) {
		graph->InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	graph->Print();
	int size = graph->size + 1;
	int ** adjMatrix = createMatrix(size);

	Vertex* vtemp = graph->gHead;
	for (int i = 1; i < size; i++) {
		adjMatrix[i][0] = vtemp->data;
		adjMatrix[0][i] = vtemp->data;
		vtemp = vtemp->nextVertex;
	}
	vtemp = graph->gHead;
	for (int i = 1; i < size; i++) {
		Edge* etemp = vtemp->firstEdge;
		while (etemp) {
			for (int j = 1; j < size; j++) {
				if (adjMatrix[0][j] == etemp->destination->data)
					adjMatrix[i][j] = 1;
			}
			etemp = etemp->nextEdge;
		}
		vtemp = vtemp->nextVertex;
	}
	printMatrix(adjMatrix, size);
	// check strong connected
	bool check = true;
	for (int i = 1; i < size; i++)
		for (int j = 1; j < size && j != i; j++)
			if (adjMatrix[i][j] != 1)
			{
				check = false;
				break;
			}
	if (check == false)
		cout << endl << "This graph isn't strong connected\n";
	else
		cout << endl << "This graph is strong connected\n";
	freeMatrix(adjMatrix, size);
}

void ex17() {
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

void ex18() {
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

void ex19() {
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
	while (1) {
		while (1) {
			cout << "\nInput k Vertex: ";
			cin >> k;
			if (k == -1)
				break;
			arr.push_back(k);
		}
		findPath_variant(from, to, graph, &arr);
		cout << "\nDo you want to continue? 0= true, -1=false: ";
		cin >> k;
		if (k == -1)
			break;
	}
}

void ex20() {
	Graph* grapha = new Graph();
	int **matrixa;
	int vertex_counta = 0; int edge_counta = 0;
	GraphtoMatrix(grapha, "input/E20a.txt", matrixa, vertex_counta, edge_counta);
	Graph* graphb = new Graph();
	int **matrixb;
	int vertex_countb = 0; int edge_countb = 0;
	GraphtoMatrix(graphb, "input/E20b.txt", matrixb, vertex_countb, edge_countb);
	//So sánh hai ma trận đẳng cấu
	bool result = false;
	int dieukien[100] = { 0 };
	int *x = new int[100];
	// if vertex(adge) of matrixa and matrixb different => No ismorphic 
	if (vertex_counta != vertex_countb || edge_counta != edge_countb)
	{
		cout << " Two graph are not ismorphic! " << endl;
	}
	else {
		// permutation and check
		Permutation_check(matrixa, matrixb, dieukien, x, vertex_counta, 0, result);
		if (result == false)
			cout << " Two graph are not ismorphic! " << endl;
		else
			cout << " Two graph are isomorphic! " << endl;
	}
}
