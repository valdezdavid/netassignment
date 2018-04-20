#ifndef TIMER_H
#define TIMER_H

#include "Event.h"

class Timer{
public:
	Timer();

	//Getters
	Event getEvent();
	int getCounter();


	// setters
	void setEvent(Event);
	void setCounter(int);



private:
	Event event_;
	int counter_;
};

#endif












