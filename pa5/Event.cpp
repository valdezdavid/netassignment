#include "Event.h"

#include <sstream>
// using namespace std;


Event::Event(){}

void Event::setType(string type){
	type_ = type;
}
void Event::setSocket(int socket){
	socket_ = socket;
}
void Event::setMessage(Message message){
	message_ = message;
}
void Event::setTimeout(Timeout timeout){
	timeout_ = timeout;
}


//getters
string Event::getType(){
	return type_;
}
int Event::getSocket(){
	return socket_;
}
Message Event::getMessage(){
	return message_;
}
Timeout Event::getTimeout(){
	return timeout_;
}

