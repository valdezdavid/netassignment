#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
// #include <set>
#include <string>
#include <list>
#include <unordered_map>
#include "Node.h"
#include <pthread_t>
// #include "Message.h"
// #include "Timeout.h"

// enum class EventType{
// 	MESSAGE, TIMEOUT
// };
using namespace std;

class Network {
public:
	Network();

	// //Setters
	void setNodes(unordered_map<Node, list<Node> >);
	void setFamousNodes(unordered_map<Node, list<Node> >);
	void setRegularNodes(unordered_map<Node, list<Node> >);
	
	// //Getters
	unordered_map<Node, list<Node> > getNodes();
	unordered_map<Node, list<Node> > getFamousNodes();
	unordered_map<Node, list<Node> > getRegularNodes();




	//Functions

	//print neighbors of current node
	void printNeighbors(pthread_t);

	//print the adjacency list of the network
	void printNetgraph(pthread_t);

	Node getNode(pthread_t);



	//shutdown
private:
	// std::string type_;
	// int socket_;
	// Message message_;
	// Timeout timeout_;
	unordered_map<Node, list<Node> > nodes_;
	unordered_map<Node, list<Node> > famousNodes_;
	unordered_map<Node, list<Node> > regularNodes_;
};




























#endif