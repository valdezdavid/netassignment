#include "Node.h"



Node::Node(){

}

void Node::setSocketID(int socketID){
	socketID_ = socketID;
}

void Node::setReadThread(pthread_t readThread){
	readThread_ = readThread;
}
void Node::setWriteThread(pthread_t writeThread){
	writeThread_ = writeThread;
}
void Node::setType(string type){
	type_ = type;
}

void Node::setOn(bool on){
	on_ = on;
}
void Node::setNeighbors(unordered_map<pthread_t, List<pthread_t> > neighbors){
	neighbors_ = neighbors;
}
void Node::setFamousNeighbors(vector<pthread_t> famousNeighbors){
	famousNeighbors_ = famousNeighbors;
}
void Node::setRegularNeighbors(vector<pthread_t> regulars){
	regularNeighbors_ = regulars;
}
void Node::setNodeLogic(NodeLogic nl){
	nl_ = nl;
}
void Node::setMessageCache(unordered_map<Node, list<Message> > cache){
	messageCache_ = cache;
}
unordered_map<Node, list<Message> > Node::getMessageCache(){
	return messageCache_;
}

void Node::setEventQueue(EventQueue eq){
	queue_ = eq;
}
EventQueue Node::getEventQueue(){
	return queue_;
}



pthread_t Node::getReadThread(){
	return readThread_;
}
pthread_t Node::getWriteThread(){
	return writeThread_;
}
int Node::getSocketID(){
	return socketID_;
}

string Node::getType(){
	return type_;
}
unordered_map<pthread_t, List<pthread_t> > Node::getNeighbors(){
	return neighbors_;
}
vector<pthread_t> Node::getFamousNeighbors(){
	return famousNeighbors_;
}
vector<pthread_t> Node::getRegularNeighbors(){
	return regularNeighbors_;
}
string Node::getConfigFile(){
	return configFile_;
}
NodeLogic Node::getNodeLogic(){
	return nl_;
}

bool Node::getOn(){
	return on_;
}

