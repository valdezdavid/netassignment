#ifndef EVENT_H
#define EVENT_H
// #include <iostream>
// #include <set>
#include <string>
#include "Message.h"
#include "Timeout.h"

// enum class EventType{
// 	MESSAGE, TIMEOUT
// };


class Event {
public:
	Event();

	//Setters
	void setType(string);
	void setSocket(int);
	void setMessage(Message);
	void setTimeout(Timeout);
	//Getters

	string getType();
	int getSocket();
	Message getMessage();
	Timeout getTimeout();

	//Functions
private:
	std::string type_;
	int socket_;
	Message message_;
	Timeout timeout_;
};




























#endif