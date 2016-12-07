/***************************************************
DO NOT MODIFY THIS FILE
Data Structure & Algorithm Assignment 3
Graph.h
Purpose: Header file for the Graph class
@author Kien Huynh
@version 1.1 05-10-2016
***************************************************/

/**
*\file Graph.h
*/

#ifdef __GNUC__
#pragma message("g++ used")
#define DEPRECATED(func, message) func __attribute__ ((deprecated(message)))
#elif defined(_MSC_VER)
#define DEPRECATED(func, message) __declspec(deprecated(message)) func
#else
#pragma message("WARNING: UNKNOWN COMPILER")
#define DEPRECATED(func) func
#endif

#ifndef GRAPHW_H
#define GRAPHW_H
#include <cassert>
#include <iostream>
#include<list>

#define MAX_INT 32767

using namespace std;

//For circular usage
/**
* \class Edge
* \brief Class Edge for Graph structure
*
* This is implemented accordingly to the book Data Structures: A Pseudocode Approach with C. \n
* We don't allow duplicate edges in this assignment since there is no weight. \n
* Each Edge instance has two member: \c destination and \c nextEdge. \n
* \c destination is the Vertex that this Edge will point to. \n
* \c nextEdge is another Edge came from the same source of this Edge. \n
*/
class EdgeW;

/**
* \class Vertex
* \brief Class Vertex for Graph structure
*
* This is implemented accordingly to the book Data Structures: A Pseudocode Approach with C. \n
* This ADT is actually just a linked list. \n
* <b>Note that two vertices connected by nextVertex DOESN'T MEAN that they are connected in the graph G.</b> \n
* <b>Vertex A actually connects to Vertex B only if and only if there is an Edge in \c firstEdge linked list that point to B.</b> \n
*/

class VertexW {
public:
	/**
	* \var data
	* \brief Vertex data
	*/
	int data;

	/**
	* \var inDegree
	* \brief Number of edges that point to this Vertex
	*/
	int inDegree;


	/**
	* \var outDegree
	* \brief Number of edges that point out from this Vertex
	*/
	int outDegree;

	/**
	* \var nextVertex
	* \brief Linked list, point to the next Vertex added into the Graph (or NULL). \n
	* This does not mean that they are connected by an edge in the Graph. \n
	*/
	VertexW* nextVertex;

	/**
	* \var firstEdge
	* \brief Linked list, point to the first Edge of this Vertex (or NULL). \n
	* In this linked list, if there is an Edge that point to another Vertex then this Vertex and that Vertex are connected in Graph G. \n
	*/
	EdgeW* firstEdge;

	/**
	* \var processed
	* \brief For traversal purpose, tell us if a node has been visited or not. \n
	*/
	bool processed;

	/**
	* \brief Default constructor. \n Create a Vertex with data=0
	*/
	VertexW();

	/**
	* \brief Create a Vertex with \c data.
	*/
	VertexW(int data);
};

//Linked list that contains Edges from a Vertex to other Vertices
//This class helps we to connect Vertices in a graph
class EdgeW {
public:
	/**
	* \var destination
	* \brief The Vertex that this Edge will point to.
	*/
	VertexW* destination;

	int weight;

	/**
	* \var nextEdge
	* \brief Another Edge came from the same source Vertex with this Edge.
	*/
	EdgeW* nextEdge;

	/**
	* \brief Default constructor. \n
	* This is illegal because an Edge should always come with a destination. \n
	* Use the other constructor instead. \n
	*/
	DEPRECATED(EdgeW(), "Constructor error, an Edge should always come with a destination (Vertex), try the other constructor instead");

	/**
	* \brief Create an Edge that point to \c destination.
	*/
	EdgeW(VertexW*, int);
};

/**
* \class Graph
* \brief Class Graph data structure
*
* This is implemented accordingly to the book Data Structures: A Pseudocode Approach with C. \n
* Note that in this implementation, we do not allow data duplication.\n
* Although data duplication is common in real-life applications, it is avoided here to ease the workload of this assignment.\n
*/
class GraphW {
public:
	/**
	* \var gHead
	* \brief Store the first Vertex inserted into this Graph. \N
	* Brought gHead back to public to allow easier coding for students
	*/
	VertexW* gHead;

	/**
	* \var size
	* \brief Number of Vertices in the Graph
	*/
	int size;

	/**
	* \brief Helper function created to remove duplicate codes
	*/
	bool InsertEdgeFromVertices(VertexW* from, VertexW* to, int weight);

	/**
	* \brief Default constructor.
	*/
	GraphW();

	/**
	* \brief Constructor that takes a Vertex as the first Vertex to this Graph
	*/
	GraphW(VertexW* gHead);

	/**
	* \brief Insert new Vertex into the graph
	*/
	bool InsertVertex(VertexW*);

	/**
	* \brief Create a new Vertex with \c data and insert it into the Graph.
	*/
	bool InsertVertex(int data);

	/**
	* \brief Remove Vertex from the Graph.
	*/
	bool RemoveVertex(VertexW*);

	/**
	* \brief Remove Vertex with \c data=reData from the Graph.
	*/
	bool RemoveVertex(int reData);

	/**
	* \brief Check if a Vertex exists in the Graph
	*/
	bool VertexExist(VertexW* v);

	/**
	* \brief Check if a Vertex exists in the graph using the Vertex data
	*/
	bool VertexExist(int vData);

	/**
	* \brief Return Vettex* given \c data
	*/
	VertexW* GetVertex(int);

	/**
	* \brief Insert new Edge into the graph using 2 Vertex
	*/
	bool InsertEdge(VertexW* from, VertexW* to, int weight);

	/**
	* \brief Create an Edge betweem two nodes with \c fromData and \c toData
	*/
	bool InsertEdge(int fromData, int toData, int weight);

	/**
	* \brief Insert new Edge into the graph using a Vertex and an Edge
	*/
	bool InsertEdge(VertexW* from, EdgeW* from_to);

	/**
	* \brief Remove an Edge from the graph using 2 Vertex
	*/
	bool RemoveEdge(VertexW* from, VertexW* to);

	/**
	* \brief Remove the Edge betweem two nodes with \c fromData and \c toData
	*/
	bool RemoveEdge(int fromData, int toData);

	/**
	* \brief Remove an Edge using a Vertex and an Edge
	*/
	bool RemoveEdge(VertexW* from, EdgeW* from_to);

	/**
	* \brief Print the graph
	*/
	void Print();

	/*
	algothims hallowed djiktra
	*/
	void resetVertex();

	bool allProcessIsTrue();

	void DijktraUtil(VertexW *from, VertexW *to, int weight[], int B[]);

	int Dijktra(VertexW* from, VertexW* to);
	/*
	algothims hallowed djiktra variant use for ex19
	*/
	void Dijktra_variantUtil(VertexW*from, VertexW *to, int weight[], int B[], std::list<int>* arr);

	int Dijktra_variant(VertexW*from, VertexW* to, list<int>* arr);
};

#endif