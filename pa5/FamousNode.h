#ifndef FAMOUSNODE_H
#define FAMOUSNODE_H

#include "Node.h"
#include <vector>



class FamousNode : Node {
public:
	FamousNode();

	//Getters
	bool getParticipating();
	bool getDiscovery();

	//Setters
	void setParticipating(bool);
	void setDiscovery(bool);
	

	// Regular Functions


private:

	bool participating;
	bool discovery;
	
};









#endif