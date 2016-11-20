#include<iostream>
#include"source\AVLTree.h"
#include"source\InputReader.h"
#include"source\Node.h"
#include"source\Heap.h"
#include"source\Graph.h"
#include"Prototype.h"
using namespace std;
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

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
	//  need free phead (protected)
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
	freeGraph(graph);
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
		graph->InsertEdge(edgeDataArr[i][1], edgeDataArr[i][2]);
	}
	graph->Print();
	
	int input = 0;
	while (1){
		cout << "Input number of node needed to remove: ";
		cin >> input;
		//more function to check input to valid 
		if (input == -1)
			break;
		graph->RemoveVertex(input);
		graph->Print();
	}
	for (int i = 0; i < edgeCount; i++)
		delete edgeDataArr[i];
	delete vertexDataArr;
	delete edgeDataArr;
	freeGraph(graph);
	delete graph;
}
void ex7(){
	int n = 0;
	int *arr;
	ReadArrayInput("input/E7.txt", arr, n);
	AVLTree* tree = new AVLTree(AVLTree::ArrayToAVL(arr, n).root);
	tree->PrintAVL();

	// ??????????????????????????????

	freeRoot(tree->root);
	delete tree;
}
void ex8(){
	int n = 0;
	int*arr;
	ReadArrayInput("input/E8.txt", arr, n);
	Heap heap = Heap::ArrayToHeap(arr, n);
	heap.PrintHeapTree();
	int size = heap.GetSize();//size
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
	ReadArrayInput("input/E7.txt", arr, n);
	AVLTree tree = AVLTree::ArrayToAVL(arr, n).root;
	tree.PrintAVL();
	Heap heap = Heap();
	AVLtoHeap(tree.root, heap);
	heap.PrintHeapTree();
	freeRoot(tree.root);
	// free heap
}
void ex10(){

}