#include "Message.h"

#include <sstream>
// using namespace std;


MessageType::MessageType(){

}

string MessageType::getType(){
	return type_;
}

auto MessageType::getNumber(){
	return number_;
}
string MessageType::getMessageid(){
	return msgid_;
}
auto MessageType::getLocation(){
	return location_;
}
string MessageType::getNodeId(){
	return nodeid_;
}
auto MessageType::getTimeout(){
	return timeout_;
}
auto MessageType::getTtl(){
	return ttl_;
}
auto MessageType::getLength(){
	return length_;
}
auto MessageType::getReason(){
	return reason_;
}

void MessageType::setNumber(auto number){
	number_ = number;
}
void MessageType::setMsgId(string id){
	msgid_ = id;
}
void MessageType::setLocation(auto location){
	location_ = location;
}
void MessageType::setNodeId(string id){
	nodeid_ = id;
}
void MessageType::setTimeout(auto timeout){
	timeout_ = timeout;
}
void MessageType::setTtl(auto ttl){
	ttl_ = ttl;
}
void MessageType::setLength(auto length){
	length_ = length;
}
void MessageType::setReason(auto reason){
	reason_ = reason;
}

void MessageType::setType(string type){
	type_ = type;
}

//DISCOREQ
DISCOREQ::DISCOREQ(){}

string DISCOREQ::getString(){
	return stringForm_;
}


//Should only happen after the parameters have been set 
void DISCOREQ::setString(){
	string message ="";
	message += "\tDISCOREQ 353NET/1.0 NONE/1.0\r\n";
	message += "\tTTL:";
	//Convert the number to string
	message += std::to_string(number_);
	message += "\r\n";
	//Flood part 
	message += "Flood: 1\r\n";
	//Message ID
	message += std::to_string(msgid_);
	message += "\r\n";
	//Content length
	message += "Content-Length: 0\r\n";
	message += "\r\n";

}

//DISCORSP 
DISCORSP::DISCORSP(){

}

string DISCORSP::getString(){
	return stringForm_;
}

void DISCORSP::setString(){
	string message ="";
	//First line
	message += "\tDISCORSP 353NET/1.0 NONE/1.0\r\n";

	//TTL line
	message +="\tTTL:";
	message += std::to_string(number_);
	message += "\r\n";
	// Flood line
	message += "\tFlood: 1\r\n";
	// Respond - to line
	message += "\tRespond-To:";
	// From line 
	message += "\tFrom:";

	// Content length
	message += "\tContent-Length: 0\r\n";
	message += "\t\r\n";
}

SAYHELLO::SAYHELO(){}

string SAYHELLO::getString(){
	return stringForm_;
}

void SAYHELLO::setString(){
	string msg = "";

	//Top line
	msg += "SAYHELLO 353NET/1.0 NONE/1.0\r\n";

	// ttl
	msg += "TTL:1\r\n";
	// flood 
	msg += "Flood:";
	// message id
	msg += "MessageID:";
	// from 
	msg += "From:";
	// keep alive 
	msg += "KeepAlive-Timeout:";
	// content length
	msg += "Content-Length:";


	msg += "\r\n";



}

KEEPALIV::KEEPALIV(){}

KEEPALIV::getString(){
	return stringForm_;
}

KEEPALIV::setString(){
	string msg += "";

	//Top line 
	msg += "KEEPALIV 353NET/1.0 NONE/1.0\r\n";

	// TTl
	msg += "TTL: 1\r\n";
	// flood
	msg += "Flood: 0\r\n";
	// Content length 
	msg += "Content-Length: 0\r\n";
	// last
	msg += "\r\n";

}

CHECKREQ::CHECKREQ(){}

CHECKREQ::getString(){
	return stringForm_;
}

CHECKREQ::setString(){
	string msg = "";


	// top
	msg += "CHECKREQ 353NET/1.0 NONE/1.0\r\n";
	// ttl 
	msg += "TTL:";
	msg += std::to_string(number_);
	msg += "\r\n";
	// Flood
	msg += "Flood:1\r\n";
	// message id 
	msg += "MessageID:";
	// content length 
	msg += "Content-Length: 0\r\n";
	// last

	msg += "\r\n";

	stringForm_ = msg;
}

CHECKRSP::CHECKRSP(){}

CHECKRSP::getString(){
	return stringForm_;
}

CHECKRSP::setString(){
	string msg = "";

	// Top
	msg += "CHECKRSP 353NET/1.0 NONE/1.0\r\n";
	// ttl
	msg += "TTL:";
	msg += std::to_string(number_);
	msg += "\r\n";
	// flood 
	msg += "Flood: 0\r\n";
	// respond to 

	// content length
	msg += "Content-Length: 0\r\n";
	//Last 
	msg += "\r\n";

	stringForm_ = msg;
}

SGOODBYE::SGOODBYE(){}

SGOODBYE::getString(){
	return stringForm_;
}

SGOODBYE::setString(){
	string msg = "";

	// Top
	msg += "SGOODBYE 353NET/1.0 NONE/1.0\r\n";
	// ttl
	msg += "TTL:1\r\n";
	// flood
	msg += "Flood: 0\r\n";
	// reason 
	msg += "Reason:";
	msg += std::to_string(reason_);
	msg += "\r\n";
	// content length
	msg += "Content-Length: 0\r\n";	
	// last
	msg += "\r\n";

	stringForm_ = msg;

}


LINKSREQ::LINKSREQ(){}

LINKSREQ::getString(){
	return stringForm_;

}

LINKSREQ::setString(){

	string msg = "";

	// top
	msg += "LINKSREQ 353NET/1.0 NONE/1.0\r\n";
	// ttl
	msg += "TTL:";
	msg += std::to_string(number_);
	msg += "\r\n";

	// flood 
	msg += "Flood:1\r\n";

	// msgid

	msg += "MessageID:";

	// from 
	msg += "From:";

	// contentlength

	msg += "Content-Length:";

	// lst
	msg += "\r\n";

	stringForm_ = msg;
}

LINKSRSP::LINKSRSP(){}

LINKSRSP::getString(){
	return stringForm_;
}
LINKSRSP::setString(){
	string msg = "";

	// top
	msg += "LINKSRSP 353NET/1.0 NONE/1.0\r\n";

	// ttl
	msg += "TTL:";
	msg += std::to_string(number_);
	msg += "\r\n";


	// flood
	msg += "Flood:0\r\n";

	// respond to 
	msg += "Respond-To:";
	// from 
	msg += "From:";

	// content legn

	msg += "Content-Length:"; 

	// last
	msg += "\r\n";

	stringForm_ = msg;
}

LINKSUPD::LINKSUPD(){}

LINKSUPD::getString(){
	return stringForm_;
}
LINKSUPD::setString(){
	string msg = "";

	// top

	msg += "LINKSUPD 353NET/1.0 NONE/1.0\r\n";
	// ttl 
	msg += "TTL:";
	msg += std::to_string(number_);
	msg += "\r\n";


	// flood
	msg += "Flood:1\r\n";	
	// msg id

	msg += "MessageID:";

	// from

	msg += "Flood:";

	// content

	msg += "Content-Length:";

	// last
	msg += "\r\n";

	stringForm_ = msg;
}



Message::Message()
	{}


// void Event::setSockk(int socket){
// 	socket_ = socket;
// }


































