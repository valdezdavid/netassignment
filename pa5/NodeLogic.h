#ifndef NODELOGIC_H
#define NODELOGIC_H
// #include <iostream>
// #include <set>
// #include <pthread.h>
#include <string>
// #include <unordered_map>
// #include <list>
// #include "EventQueue.h"

using namespace std;

class NodeLogic {
public:
	// Node();


	// //Setters
	// void setSocketID(int);
	// void setReadThread(pthread_t);
	// void setWriteThread(pthread_t);
	// void setType(string);
	// void setConfigFile(string);

	// //Getters
	// pthread_t getReadThread();
	// pthread_t getWriteThread();
	// int getSocketID();
	// string getType();
	// unordered_map<pthread_t, List<pthread_t> > getNeighbors();
	// vector<pthread_t> getFamousNeighbors();
	// vector<pthread_t> getRegularNeighbors();
	// string getConfigFile();

	//functions

	NodeLogic();

	// Setters
	//Config
	void setHost(string);
	void setControlPort(int);
	void setAppPort(int);
	void setLocation(int);
	void setRoot(string);
	void setPid(string);
	void setLog(string);

	//Params
	void setTtl(int);
	void setNumStartupNeighbors(int);
	void setMsgLifeTime(int);
	void setKeepAliveTimeout(int);
	void setCheckTimeout(int);
	void setDiscoveryTimeout(int);
	void setDiscoveryRetryInterval(int);

	//Famous

	void setFamousRetryInterval(int);
	void setCount(int);
	void setNodes(vector<string>);



	// Getters

	//Config
	string getHost();
	int getControlPort();
	int getAppPort();
	int getLocation();
	string getRoot();
	string getPid();
	string getLog();

	//Params
	int getTtl();
	int getNumStartupNeighbors();
	int getMsgLifeTime();
	int getKeepAliveTimout();
	int getCheckTime();
	int getDiscoveryTimeout();
	int getDiscoveryRetryInterval();


	//Famous 
	int getFamousRetryInterval();
	int getCount();
	vector<string> getNodes();



	// Functions
	string getNodeId();
	void setNodeId(string);




private:

	//Config section
	string host_;
    int control_port_;
    int app_port_;
    int location_;
    string root_;
    string pid_;
    string log_;

    //Params section
    int ttl_;
    int num_startup_neighbors_;
    int msg_life_time_;
    int keep_alive_timeout_;
    int check_timeout_;
    int discovery_timeout_;
    int discovery_retry_interval_;

    //Famous 
    int famous_retry_interval_;
    int count_;
    vector<string> nodes_;

    //Logic 


    string nodeId_;

};













#endif