#ifndef NODE_H
#define NODE_H
// #include <iostream>
// #include <set>
#include <pthread.h>
#include <string>
#include <unordered_map>
#include <list>
#include "EventQueue.h"
#include "NodeLogic.h"

using namespace std;

class Node {
public:
	Node();

	//Setters
	void setSocketID(int);
	void setReadThread(pthread_t);
	void setWriteThread(pthread_t);
	void setType(string);
	void setConfigFile(string);
	void setOn(bool);
	void setNeighbors(unordered_map<pthread_t, List<pthread_t> >);
	void setFamousNeighbors(vector<pthread_t> );
	void setRegularNeighbors(vector<pthread_t> );
	void setNodeLogic(NodeLogic);

	//Getters
	pthread_t getReadThread();
	pthread_t getWriteThread();
	int getSocketID();
	string getType();
	unordered_map<pthread_t, List<pthread_t> > getNeighbors();
	vector<pthread_t> getFamousNeighbors();
	vector<pthread_t> getRegularNeighbors();
	bool getOn();
	string getConfigFile();
	NodeLogic getNodeLogic();

	//Message Cache
	void setMessageCache(unordered_map<Node, list<Message> >);
	unordered_map<Node, list<Message> > getMessageCache();

	void setEventQueue(EventQueue);
	EventQueue getEventQueue();

	//functions




private:
	std::string type_;
	int socketID_;
	pthread_t readThread_;
	pthread_t writeThread_;
	unordered_map<pthread_t, List<pthread_t> > neighbors_;
	vector<pthread_t> famousNeighbors_; // will use the thread id to refer to neighbors
	vector<pthread_t> regularNeighbors_;
	bool on_;
	//Event queue
	EventQueue queue_;
	string configFile_;
	NodeLogic nl_;
	//Message cache
	unordered_map<Node, list<Message> > messageCache_;





};













#endif