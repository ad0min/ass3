#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_
#include"source\Heap.h"
#include"source\Graph.h"

//Start.cpp
bool start(int&);

//Exercise prototype

void ex1();

void ex2();

void ex3();

void ex4();

void ex5();
 
void ex6();

void ex7();

void ex8();

void ex9();

void ex10();

void ex11();

void ex12();

void ex13();

void ex14();

void ex15();

void ex16();

void ex17();

void ex18();

void ex19();

void ex20();

// Implement.cpp

void freeRoot(Node*);

//void freeGraph(Graph*);









// SuportEx.cpp

// Ex2

bool isPrime(int);

void reverseAVLtree(Node* , int& , int& , int& );


// Ex7
int printwithHeight(Node*, int);

// Ex9
void AVLtoHeap(Node*, Heap&);

//Ex10



// Ex11

int** createMatrix(int size);

void freeMatrix(int**, int);

void printMatrix(int**, int);
#endif