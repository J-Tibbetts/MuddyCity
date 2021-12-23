/*
* Jeff Tibbetts
* CSC 284-H1
* December 14, 2021
* Graph.cpp
* Implementation Sheet for Graph Class
*/
#include "Graph.h"

//constructs graph based on number of Vertices
Graph::Graph(const int nVerts) {

	this->vertices = std::vector<Vertex>(nVerts);
	this->edgeMatrix = std::vector<std::vector<int>>(nVerts, std::vector<int>(nVerts, 0));

	//vertices are automatically labeled A to z to avoid confusion
	//with numeric cost of associated edges
	for (int i = 0; i < this->vertices.size(); i++) {
		vertices[i].label = 'a' + i;

	}
}

//Updates adjacency matrix to reflect inputted edge
void Graph::addEdge(int v1, int v2, int cost) {
	if (v1 >= this->vertices.size() || v2 >= this->vertices.size()) {
	}
	edgeMatrix[v1][v2] = cost;
	edgeMatrix[v2][v1] = cost;
}

//returns label element of associated vertex
char Graph::getVertex(int index) {
	return vertices[index].label;
}

//prints graph edges to console
void Graph::print(bool displayCost) {
	
	int total = 0;
	for (int i = 0; i < this->vertices.size(); i++) {
		if (!displayCost) std::cout << "Vertex: " << getVertex(i) << "\n";
		for (int j = 0; j < this->vertices.size(); j++) {
			if (edgeMatrix[i][j] > 0 && 
				(i < j || !displayCost)) {
				std::cout <<"\t" << getVertex(i) << " -> " << getVertex(j) <<
					"=" << edgeMatrix[i][j] << "\n";
					total += edgeMatrix[i][j];		
			}
		}
	}
	if(displayCost) std::cout << "Total Cost:" << total<<"\n";
}

//returns graph with lowest cost roadmap
Graph Graph::getRoadMap() {
	Graph temp(this->vertices.size());
	for (Edge e : this->getRoute()) {
		temp.addEdge(e.v1, e.v2, e.cost);
	}
	return temp;
}

//Returns a vector of Edges for most costeffective means of connecting
//all vertices
std::vector<Graph::Edge> Graph::getRoute() {
	std::stack<int> verts;
	std::vector<Edge> edges;
	verts.push(0);
	while (!verts.empty()) {
		std::stack<int> verts_copy(verts);
		std::vector<Edge> possibleEdges;
		Edge e = getNextEdge(verts_copy, possibleEdges);
		if (e.cost != -1) {
			verts.push(e.v2);
			this->vertices[e.v2].visited = true;
			edges.push_back(e);
		}
		else {
			for (int i = 0; i < this->vertices.size(); i++) {
				this->vertices[i].visited = false;
			}
			return edges;
		}
	}
}

//Recursive function which will be passed the stack and edge containers, will continue to pop elements off the stack and add to the vector
//until there are no elements on stack, then returns the first element of the sorted vector
Graph::Edge Graph::getNextEdge(std::stack<int>& connected_vertices, std::vector<Edge> &possibleEdges) {
	std::stack<int> st(connected_vertices);
	if (st.empty())										//control statement for recursive loop
	{
		//If the stack passed is empty...
		if (!possibleEdges.empty()) {
			//if theres are elements in possible edges, they are sorted based on cost
			std::sort(possibleEdges.begin(), possibleEdges.end(), [](Edge e1, Edge e2)->bool {return e2.cost > e1.cost; });
			return possibleEdges[0];
		}
		else {
			//if the stack is empty and there are no possible edges, will return an edge with the sentenal value -1 to trigger
			//the upperlevel algorthm 
		Edge e;
		e.cost = -1;
		return e;
		}
	}
	else{
		//if the stack contains elements...
		int v = st.top();				//copy the top element
		st.pop();						//then remove it from the stack
		for (int i = 0; i < this->vertices.size(); i++) {
			if (edgeMatrix[v][i] > 0
				&& !vertices[i].visited)
				{
				Edge e;
				e.cost = edgeMatrix[v][i];
				e.v1 = v;
				e.v2 = i;
				possibleEdges.push_back(e);
				}
		}
		return getNextEdge(st, possibleEdges);						//recursive function call
	}
}
