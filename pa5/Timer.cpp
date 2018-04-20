#include "Timer.h"


Timer::Timer(){

}

//getters

Event Timer::getEvent(){
	return event_;
}
int Timer::getCounter(){
	return counter_;
}

void Timer::setEvent(Event e){
	event_ = e;
}
void Timer::setCounter(int c){
	counter_ = c;
}











