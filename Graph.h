//--------------------------------------------------------------------
// Title: Graph.h
// Author: Sabit Gökberk Karaca
// ID: 21401862
// Section: 3
// Assignment: 4
// Description: Header file of Graph class
//--------------------------------------------------------------------

#ifndef GRAPH_H_
#define GRAPH_H_
using namespace std;

class Graph{

public:
	Graph();
	~Graph();

	void findShortestPath();

private:
	int C, M, F;
	bool** connections;
	int** permutationsArray;
	string shortestPath;
	int shortestPathLength;

	void setConnections();
	void printConnections();
	void setPermutations();
	void printPermutations();
	void breadthFirstSearch(int source, int target, int& pathLength, string& path);
};



#endif /* GRAPH_H_ */
