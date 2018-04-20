#ifndef TIMEOUT_H
#define TIMEOUT_H
// #include <iostream>
// #include <set>
#include <string>
//#include "Message.h"
//#include "Timeout.h"

// enum class EventType{
// 	MESSAGE, TIMEOUT
// };


using namespace std;


class Timeout {
public:
	Timeout();

	// Gettres
	int getCounter();
	string getType();

	// Setters
	void setCounter(int);
	void setType(string);

	// functions type stuff





	//Functions
private:

	int counter_;
	string type_;
	
};




























#endif