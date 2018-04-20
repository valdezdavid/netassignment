#ifndef REGULARNODE_H
#define REGULARNODE_H

#include "Node.h"
#include <vector>
#include <string>


class RegularNode : Node {
public:
	RegularNode();

	// Getters
	bool getDiscovery();
	bool getParticipating();
	string getStartUpNeighbors();


	// Setters
	void setDiscovery(bool);
	void setParticipating(bool);
	void setStartUpNeighbors(string);



	// Functions
	// void makeTemporaryConnection();

	

private:

	bool participating;
	bool discovery;
	string startUpNeighbors;
	
};









#endif