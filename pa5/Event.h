#ifndef EVENT_H
#define EVENT_H
// #include <iostream>
// #include <set>
#include <string>

// enum class EventType{
// 	MESSAGE, TIMEOUT
// };


class Event {
public:
	Event(std::string);
	void setSockk(int);
private:
	std::string type_;
	int socket_;
};




























#endif