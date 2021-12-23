/*
* Jeff Tibbetts
* CSC 284-H1
* December 14, 2021
* Main.cpp in Tibbetts_Final_Proj
* Generates graph representing Muddycity diagram
* and prints the edges to the screen for user verification.
* Generates minimum spanning tree using class method
* getRoadMap and prints the edges to the screen with
* the system's total unit cost
*/
#include"Graph.h"
#include<iostream>

int main() {
	const int N_PROPERTIES = 10;		//number of vetices to be added to graph
	Graph cityMap(N_PROPERTIES);

	//manually loaded edges from muddy city diagram, vertices are 
	//represented A-J, from top->bottom, left->right
	cityMap.addEdge(0, 1, 4);
	cityMap.addEdge(0, 3, 3);
	cityMap.addEdge(0, 5, 5);
	cityMap.addEdge(1, 2, 2);
	cityMap.addEdge(1, 3, 5);
	cityMap.addEdge(1, 4, 4);
	cityMap.addEdge(2, 4, 3);
	cityMap.addEdge(2, 7, 3);
	cityMap.addEdge(3, 4, 4);
	cityMap.addEdge(3, 5, 3);
	cityMap.addEdge(3, 6, 3);
	cityMap.addEdge(4, 7, 2);
	cityMap.addEdge(4, 6, 5);
	cityMap.addEdge(5, 6, 2);
	cityMap.addEdge(5, 8, 3);
	cityMap.addEdge(5, 9, 4);
	cityMap.addEdge(6, 7, 3);
	cityMap.addEdge(6, 9, 3);
	cityMap.addEdge(7, 9, 4);
	cityMap.addEdge(8, 9, 2);

	//default print statement of cityMap instance
	std::cout << "Given set of possible routes:\n";
	cityMap.print();
	
	//cost inclusive print statement of the graph returned
	//from the getRoadMap Graph function
	std::cout << "\nCheapest possible paving plan is:\n";
	cityMap.getRoadMap().print(true);

	std::cout << "\nPress enter to exit...";
	std::cin.get();

	return 0;
}
