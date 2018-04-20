#include "Network.h"
/*
	All the nodes together 
	only regular
	only famous


	famous 
		if it is turned off, all other famous nodes will keep trying to make connection
		continuously 
		your node must sleep for a famous retry interval before it tries to connect again


	Regular 
		add itself to the network 
		

*/

Network::Network(){

}

void Network::setNodes(unordered_map<Node, list<Node> > nodes){
	nodes_ = nodes;
}
void Network::setFamousNodes(unordered_map<Node, list<Node> > famous){
	famousNodes_ = famous;
}
void Network::setRegularNodes(unordered_map<Node, list<Node> > regulars){
	regularNodes_ = regulars;
}

unordered_map<Node, list<Node> > Network::getNodes(){
	return nodes_;
}
unordered_map<Node, list<Node> > Network::getFamousNodes(){
	return famousNodes_;

}

unordered_map<Node, list<Node> > Network::getRegularNodes(){
	return regularNodes_;
}


void Network::printNeighbors(pthread_t thread){
	//First find the node that has the thread
	Node node = NULL;
	for(auto it = nodes_.begin(); it != nodes.end(); it++){
		if((it->first).getReadThread() == thread){
			node = it*;
		}
	}

	//Find it 
	auto got = nodes_.find(node);

	if(got != nodes_.end()){
		list<Node> neighbors = got->second;
		if(neighbors.size() > 0){
			for(auto listIt = neighbors.begin(); listIt != neighbors.end(); listIt++){
			cout << "\t";
			cout << (listIt*).getNodeLogic().getNodeId() << endl;
			}
		}
		else {
			cout << "SELF has no neighbors" << endl;
		}
		
	}
}

void Network::printNetgraph(pthread_t thread){
	Node node = NULL;

	for(auto it = nodes_.begin(); it != nodes.end(); it++){
		if((it->first).getReadThread() == thread){
			node = it*;
		}
	}

	//unordered_map<pthread_t, List<pthread_t> >
	auto neighbors = node.getNeighbors();
	if(neighbors.size() > 0){
		for(auto it = neighbors.begin();it != neighbors.end();it++){
			//get the node
			Node node = getNode(it->first);
			//Print the node id
			cout << node.getNodeLogic().getNodeId() << ":";

			auto friends = it->second;
			for(auto friendIt = friends.begin(); friendIt != friends.end();friendIt++){
				cout << getNode((friendIt*)).getNodeLogic().getNodeId() << ", ";
			}
			cout << endl;

		}
		
	}
	else if(neighbors.size() == 0){
		cout << "SELF has no neighbors" << endl;
	}
	else if(node.getDiscovery()){
		//Its in discovery mode
		cout << "SELF is in discover mode" << endl;
	}
	

}

Node Network::getNode(pthread_t thread){
	Node node = NULL;

	for(auto it = nodes_.begin(); it != nodes.end(); it++){
		if((it->first).getReadThread() == thread){
			node = it*;
		}
	}

	return node;
}











