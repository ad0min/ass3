#include<iostream>
#include"source\AVLTree.h"
#include"source\InputReader.h"
#include"source\Node.h"
using namespace std;

bool start(int& n){
	while (1){
	cout << "To stop input 0, or Continue input 1 :";
	cin >> n;
	if (n == 0 || n == 1)
		break;
	cout << "Invalid number. Please try again!\n";
	}
	if (n == 0)
		return false;
	while (1){
		cout << "Please input Exercise to demo below. \nWith ex<i> input number i(0<i<21) : ";
		cin >> n;
		if (n > 0 && n < 21)
			return true;
		cout << "Invalid number. Please try again!\n";
	}

}
void ex1(){
	int n = 0;
	while (1){
		cout << "How many element would you like to sort? ";
		cin >> n;
		if (n > 0)
			break;
		cout << "Invalid number! Please try again";
	}
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cout << "Input element " << i << " :";
		cin >> arr[i];
	}
	AVLTree tree = AVLTree::ArrayToAVL(arr, n);
	tree.PrintAVL();
	//need function to free memory!!!!!!!
}
void ex2(){
	int n = 0;
	int *arr;
	ReadArrayInput("E2.txt", arr, n);
	AVLTree tree = AVLTree::ArrayToAVL(arr, n);
	tree.PrintAVL();
	int input = 0;
	while (1){
		cout << "Input number of node needed to remove: ";
		cin >> input;
		if (input == -1)
			break;
		tree.AVLDelete(input);
		tree.PrintAVL();
	}
	//need function to free memory!!!!!!!
}
bool isPrime(int number){
	if (number <= 1) return 0;
	for (int i = 0; i < sqrt(number); i++)
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
void ex3(){
	int n = 0;
	int *arr;
	ReadArrayInput("E2.txt", arr, n);
	AVLTree tree = AVLTree::ArrayToAVL(arr, n);
	int evenNumber = 0, oddNumber = 0, primeNumber = 0;
	reverseAVLtree(tree.root, evenNumber, oddNumber, primeNumber);
	cout << "Total of even number in AVLTree: " << evenNumber<<endl;
	cout << "Total of odd number in AVLTree: " << oddNumber << endl;
	cout << "Total of prime number in AVlTree: " << primeNumber << endl;
}
