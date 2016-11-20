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

void printwithHeight(Node* root){

}
//ex9
void AVLtoHeap(Node*root, Heap& heap){
	if (root == NULL)
		return;
	heap.InsertHeap(root->data);
	AVLtoHeap(root->left, heap);
	AVLtoHeap(root->right, heap);
}