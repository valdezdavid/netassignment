#include "Event.h"

#include <sstream>
// using namespace std;


Event::Event(std::string type)
	:type_(type){}


void Event::setSockk(int socket){
	socket_ = socket;
}


