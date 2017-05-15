//--------------------------------------------------------------------
// Title: Graph.cpp
// Author: Sabit Gökberk Karaca
// ID: 21401862
// Section: 3
// Assignment: 4
// Description: Implementation of Graph class
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <climits>
#include "Graph.h"
#include "Queue.h"
using namespace std;

// Constructor
Graph::Graph(){

	// Initialise the data members
	C = 0;
	M = 0;
	F = 0;
	connections = NULL;
	permutationsArray = NULL;

	// Initialise the arrays
	setConnections();
	setPermutations();
}


// Destructor
Graph::~Graph(){


	// Delete connections array
	if (connections != NULL){
		for (int i = 0; i < C; i++)
			if (connections[i] != NULL)
				delete[] connections[i];

		delete[] connections;
	}

	// Delete permutations array

	// Calculate # of permutations of middle vertices (except 0)
	if (permutationsArray != NULL){
		int factorial = 1;
		for (int i = M-1; i > 1; i--)
			factorial *= i;

		// Delete each permutation
		for (int i = 0; i < factorial; i++)
			if (permutationsArray[i] != NULL)
				delete[] permutationsArray[i];

		// Delete whole array
		delete[] permutationsArray;
	}
}

void Graph::setConnections(){
	ifstream inputStream("input.txt");

	// Open the input stream
	if (inputStream.is_open()){

		// Read the first line and separate the variables
		string firstLine;
		getline(inputStream, firstLine);
		istringstream strStream(firstLine);
		strStream >> C >> M >> F;

		// Create a CxC matrix to store the graph
		connections = new bool*[C];
		for (int i = 0; i < C; i++){
			connections[i] = new bool[C];
			for (int j = 0; j < C; j++)
				connections[i][j] = false;
		}

		// Fill the graph by reading the edges from text file
		string line;
		while ( getline(inputStream,line)){
			istringstream strStream2(line);
			int a, b;
			strStream2 >> a >> b;
			connections[a][b] = true;
		}
	}
}

// Print the adjacency matrix that shows the connections
void Graph::printConnections(){

	// Print the row numbers
	cout << "\t";
	for (int i = 0; i < C; i++)
		cout << i << " ";

	cout << endl << endl;

	for (int i = 0; i < C; i++){
		// Print the column numbers
		cout << i << "\t";
		for (int j = 0; j < C; j++)
			//Print the connections
			cout << connections[i][j] << " ";
		cout << endl;
	}
}

void Graph::printPermutations(){
	// Calculate # of permutations of middle vertices (except 0)
	int factorial = 1;
	for (int i = M-1; i > 1; i--)
		factorial *= i;

	// Report the possible paths
	for (int i = 0; i < factorial; i++){
		for (int j = 0; j < M + 1; j++)
			cout << permutationsArray[i][j] << " ";
		cout << endl;
	}
}

void Graph::setPermutations(){
	if (M <= 0)
		return;

	// 0 vertex is not included, so size is M-1
	int arr[M-1];
	for (int i = 1; i <= M-1; i++)
		arr[i-1] = i;

	// Calculate # of permutations of middle vertices (except 0)
	int factorial = 1;
	for (int i = M-1; i > 1; i--)
		factorial *= i;

	// Create the permutations array
	permutationsArray = new int*[factorial];
	for (int i = 0; i < factorial; i++)
		permutationsArray[i] = new int[M+1];

	// Fill the permutations array
	for (int i = 0; i < factorial; i++){
		for (int j = 0; j < M + 1; j++){
			if (j == 0 || j == M)
				permutationsArray[i][j] = 0;
			else
				permutationsArray[i][j] = arr[j - 1];
		}
		next_permutation(arr, arr + M - 1);
	}
}
void Graph::breadthFirstSearch(int source, int target, int& pathLength, string& path){

	// Create necessary arrays
	bool visited[C];
	int previous[C];

	// Initialize those arrays
	for (int i = 0; i < C; i++){
		visited[i] = false;
		previous[i] = -1;
	}

	// Perform a breadth
	Queue queue;
	visited[source] = true;
	queue.enqueue(source);
	while(!queue.isEmpty()){

		// If the shortest path for target is already obtained, stop
		int current;
		queue.dequeue(current);
		if (current == target)
			break;

		// Else, continue to search
		for (int i = 0; i < C; i++){
			if (connections[current][i] != 0){
				if (visited[i] == false){
					visited[i] = true;
					previous[i] = current;
					queue.enqueue(i);
				}
			}
		}
	}

	// If the path does not exist, return -1
	if (previous[target] == -1){
		pathLength = -1;
		path = "";
		return;
	}
	else{
		// Backtrack the array to find the path
		int current = target;
		while( current != source){
			stringstream ss;
			ss << current;
			path = ss.str() + path;
			pathLength++;
			current = previous[current];
		}
			// Add it to the path
			stringstream ss;
			ss << source;
			path = ss.str() + path;
	}
}

void Graph::findShortestPath(){

	// Check if the M value is valid or not
	if (M == 0 || M== 1){
		cout << "Jack will not travel!" << endl;
		return;
	}

	// Calculate # of permutations of middle vertices (except 0)
	int factorial = 1;
	for (int i = M-1; i > 1; i--)
		factorial *= i;


	// Calculate the length of all paths and choose the smallest one
	int minPathLength = INT_MAX;
	string minPath = "";

	// Calculate the length of paths
	for (int i = 0; i < factorial; i++){

		// Total length of a path
		int totalPathLength = 0;
		string totalPath = "";

		// Calculate the length of inner travels
		for (int j = 0; j < M; j++){

			// Length of a inner path
			int pathLength = 0;
			string path = "";

			// Call the search algorithm to find the path
			breadthFirstSearch(permutationsArray[i][j], permutationsArray[i][j+1], pathLength, path);

			// If the path doesn't exist, set it to -1
			if (pathLength == -1){
				totalPathLength = -1;
				break;
			}

			// If it exists, add it to total path
			totalPathLength += pathLength;
			totalPath += path + " ";
		}

		// Choose the smallest path
		if ( totalPathLength > 0 && totalPathLength < minPathLength){
			minPathLength = totalPathLength;
			minPath = totalPath;
		}
	}

	// Report the shortest path
	cout << minPathLength << endl;
	for ( unsigned int i = 0; i < minPath.length(); i++){
		// Last node of an inner path and first node of next inner path are same
		if (minPath[i] == ' ')
			i++;
		else{
			// If it is not the last node, put an arrow between them
			if (i != minPath.length() - 2)
				cout << minPath[i] << "->";
			else
				cout << minPath[i];
		}
	}

	cout << endl;
}
