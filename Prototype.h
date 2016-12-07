#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_
#include"source\Heap.h"
#include"source\Graph.h"
#include"GraphW.h"

//Start.cpp


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

void reverseAVLtree(Node*, int&, int&, int&);


// Ex7
int printwithHeight(Node*, int);

int heightTree(Node*);

// Ex9
void AVLtoGrap(Node*, Graph*);

//Ex10

void HeaptoGrap(Heap, Graph*, int);

// Ex11

int** createMatrix(int size);

void freeMatrix(int**, int);

void printMatrix(int**, int);

// ex12

int AVLtreetoMatrix(Node*, int**&, int);

// ex14

int getCycle(Vertex* vertex, const int data, int i);

int sumCycle(Vertex* ghead);

// ex17

bool GraphtoTree(Vertex *vertex, Node *&root);

bool insert(Node*& root, int from, int to);

bool checkAVl(Node* root);

bool checkGraphDFS(Vertex *vertex, Node *root);

void resetVertex(Graph* graph);

bool GraphtoAVL(Graph *graph);


// Vertex* root to point a element of graph; if wrong => fail


// ex18
bool findPath(int, int, GraphW*);

// ex19
bool findPath_variant(int _from, int _to, GraphW *graph, list<int>*arr);

//ex20

void GraphtoMatrix(Graph* graph, string input, int **&matrix, int &vertex_count, int &edge_count);

bool Isomorphic(int **matrixa, int **matrixb, int *x, int n);

void Permutation_check(int **matrixa, int **matrixb, int dieukien[100], int *x, int n, int i, bool &result);

#endif#pragma once
