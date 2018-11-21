
#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"

using namespace std;


typedef GraphArc<std::string, int> Arc;
typedef GraphNode<std::string, int> Node;

void visit(Node * node) {
	cout << "Visiting: " << node->data() << endl;
}

void previous(Node * node) {
	cout << "Previous: " << node->previous() << endl;
}

int main(int argc, char *argv[]) {

	Graph<std::string, int> graph(25);

	std::string nodeLabel;
	int i = 0;
	ifstream myfile;
	myfile.open("nodes.txt");

	while (myfile >> nodeLabel) {
		graph.addNode(nodeLabel, i++);
	}

	myfile.close();
	myfile.open("arcs.txt");

	int from, to, weight;
	while (myfile >> from >> to >> weight) {
		graph.addArc(from, to, weight);
	}
	myfile.close();

	// Now traverse the graph.
	graph.breadthFirst(graph.nodeIndex(0), visit);
	
	system("PAUSE");

	//Q1 Implementation
	Graph<std::string, int> graphQ1(13);

	std::string nodeLabelQ1;
	int k = 0;
	myfile.open("Q1Nodes.txt");

	while (myfile >> nodeLabelQ1) {
		graphQ1.addNode(nodeLabelQ1, k++);
	}

	myfile.close();
	myfile.open("Q1Arcs.txt");

	int fromQ1, toQ1, weightQ1;
	while (myfile >> fromQ1 >> toQ1 >> weightQ1) {
		graphQ1.addArc(fromQ1, toQ1, weightQ1);
	}
	myfile.close();

	// Now traverse the graph.
	graphQ1.breadthFirst(graphQ1.nodeIndex(0), visit);

	system("PAUSE");

	//Q2 Implementation

	Graph<std::string, int> graphQ2(25);

	std::string nodeLabelQ2;
	int j = 0;
	myfile.open("Q2Nodes.txt");

	while (myfile >> nodeLabelQ2) {
		graphQ2.addNode(nodeLabelQ2, j++);
	}

	myfile.close();
	myfile.open("Q2Arcs.txt");

	int fromQ2, toQ2, weightQ2;
	while (myfile >> fromQ2 >> toQ2 >> weightQ2) {
		graphQ2.addArc(fromQ2, toQ2, weightQ2);
	}
	myfile.close();

	// Now traverse the graph.
	graphQ2.adaptedBreadthFirst(graphQ2.nodeIndex(0), graphQ2.nodeIndex(15));
	for (int i = 0; i < 16; i++)
	{
		previous(graphQ2.nodeIndex(i));
	}
	
	system("PAUSE");

}
