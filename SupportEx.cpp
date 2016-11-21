#include"source\AVLTree.h"
#include"source\InputReader.h"
#include"source\Node.h"
#include"source\Heap.h"
#include"source\Graph.h"
#include"Prototype.h"
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