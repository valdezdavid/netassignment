#include "Timeout.h"

Timeout::Timeout(){

}

//Getters

int Timeout::getCounter(){
	return counter_;
}
string Timeout::getType(){
	return type_;
}

void Timeout::setCounter(int count){
	counter_ = count;
}

void Timeout::setType(string t){
	type_ = t;
}