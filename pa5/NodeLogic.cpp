#include "NodeLogic.h"


NodeLogic::NodeLogic();

//Setters
//config
void NodeLogic::setHost(string host){
	host_ = host;
}
void NodeLogic::setControlPort(int cp){
	control_port_ = cp;
}
void NodeLogic::setAppPort(int ap){
	app_port_ = ap;
}
void NodeLogic::setLocation(int location){
	location_ = location;
}
void NodeLogic::setRoot(string root){
	root_ = root;
}
void NodeLogic::setPid(string pid){
	pid_ = pid;
}
void NodeLogic::setLog(string log){
	log_ = log;
}

//params

void NodeLogic::setTtl(int ttl){
	ttl_ = ttl;
}
void NodeLogic::setNumStartupNeighbors(int num){
	num_startup_neighbors_ = num;
}
void NodeLogic::setMsgLifeTime(int msg){
	msg_life_time_ = msg;
}
void NodeLogic::setKeepAliveTimeout(int num){
	keep_alive_timeout_ = num;
}
void NodeLogic::setCheckTimeout(int num){
	check_timeout_ = num;
}
void NodeLogic::setDiscoveryTimeout(int num){
	discovery_timeout_ = num;
}
void NodeLogic::setDiscoveryRetryInterval(int num){
	discovery_retry_interval_ = num;
}

//Famous
void NodeLogic::setFamousRetryInterval(int num){
	famous_retry_interval_ = num;
}
void NodeLogic::setCount(int num){
	count_ = num;
}
void NodeLogic::setNodes(vector<string> vec){
	nodes_ = vec;
}

void NodeLogic::setNodeId(string id){
	nodeId_ = id;
}

string NodeLogic::getNodeId(){
	return nodeId_;
}

//Getters
string NodeLogic::getHost(){
	return host_;
}
int NodeLogic::getControlPort(){
	return control_port_;
}
int NodeLogic::getAppPort(){
	return app_port_;
}
int NodeLogic::getLocation(){
	return location_;
}
string NodeLogic::getRoot(){
	return root_;
}
string NodeLogic::getPid(){
	return pid_;
}
string NodeLogic::getLog(){
	return log_;
}

//Params
int NodeLogic::getTtl(){
	return ttl_;
}
int NodeLogic::getNumStartupNeighbors(){
	return num_startup_neighbors_;
}
int NodeLogic::getMsgLifeTime(){
	return msg_life_time_;
}
int NodeLogic::getKeepAliveTimout(){
	return keep_alive_timeout_;
}
int NodeLogic::getCheckTime(){
	return check_timeout_;
}
int NodeLogic::getDiscoveryTimeout(){
	return discovery_timeout_;
}
int NodeLogic::getDiscoveryRetryInterval(){
	return discovery_retry_interval_;
}


//Famous 
int NodeLogic::getFamousRetryInterval(){
	return famous_retry_interval_;
}
int NodeLogic::getCount(){
	return count_;
}
vector<string> NodeLogic::getNodes(){
	return nodes_;
}

























