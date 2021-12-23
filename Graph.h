/*
* Jeff Tibbetts
* CSC 284-H1
* December 14, 2021
* Graph.h
* Headder file for Graph Class
* Creates vertex list based upon number
* of vertices passed to it, edge map constructed
* and will select least costly method of connecting all
* vertices based on a minimum spanning tree
*/
#pragma once
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>

class Graph
{
	struct Vertex;									//structure prototypes
	struct Edge;									//
private:
	struct Vertex {									//used to represent properties
		char label;									//in city and track whether they
		bool visited = false;						//are included in project
	};
	struct Edge {
		int cost, v1, v2;							//used to refer to specific
	};												//relations in EdgeMatrix

	std::vector<Vertex> vertices;					//stores vertices
	std::vector<std::vector<int>> edgeMatrix;		//used to store all possible paths in city

public:

	Graph(const int nVerts);
	void addEdge(int v1, int v2, int cost);
	char getVertex(int index);

	void print(bool displayCost=false);

	Graph getRoadMap();
	std::vector<Edge> getRoute();
	Edge getNextEdge(std::stack<int>& connected_vertices, std::vector<Edge> &possibleEdges);	//Recursive take on Krusgal's algorithm
																								//O(E^2) preformance (containers are passed
																								//by refrence but must iterate through rows in
																								//adjacency matrix multiple times
};