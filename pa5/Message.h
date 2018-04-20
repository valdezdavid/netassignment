#pragma once
// #ifndef MESSAGE_H
// #define MESSAGE_H
// #include <iostream>
// #include <set>
#include <string>
using namespace std;
// enum class EventType{
// 	MESSAGE, TIMEOUT
// };

class MessageType{
public:
	MessageType(string);


	//Getters
	string getType();
	int getNumber();
	string getMessageId();
	int getLocation();
	string getNodeId();
	int getTimeout();
	int getTtl();
	int getLength();
	int getReason();




	//Setters
	void setNumber(int);
	void setMsgId(string);
	void setLocation(int);
	void setNodeId(string);
	void setTimeout(int);
	void setTtl(int);
	void setLength(int);
	void setReason(int);

	
	void setType(string);
private:
	//Variables 
	string type_;
	
	int number_;
	string msgid_; // use the hex
	int location_;
	string nodeid_; // 40 bytes
	int timeout_;
	int ttl_;
	int length_;
	int reason_;


};

class DISCOREQ  : MessageType{
public:
	DISCOREQ();
	
	
	//Setters
	
	// void setNumber(int);
	// void setMsgId(int);

	// //Getters
	// int getNumber();
	// int getMessageId();

	string getString();
	void setString();
private:

	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;


};

struct DISCORSP : MessageType{
	DISCORSP();


	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;


};
struct SAYHELLO : MessageType{
	SAYHELLO();


	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;
};


struct KEEPALIV : MessageType{
	KEEPALIV();

	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;

};

struct CHECKREQ : MessageType{
	CHECKREQ();

	
	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;


};

struct CHECKRSP : MessageType{
	CHECKRSP();


	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;

};

struct SGOODBYE : MessageType{
	SGOODBYE();
	//Setter

	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;

};

struct LINKSREQ : MessageType {
	LINKSREQ();


	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;
};

struct LINKSRSP : MessageType{
	LINKSRSP();


	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;
};


struct LINKSUPD : MessageType{
	LINKSUPD();

	string getString();
	void setString();


	// //Variables 
	// int number_;
	// int msgid_;
	string stringForm_;

};

// struct DEBUGREQ : MessageType {
// 	DEBUGREQ();

// 	//Getter
// 	int getNumber();
// 	int getMsgId();
// 	int getNodeId();
// 	int getLength();


// 	//Setter
// 	void setNumber(int);
// 	void setMsgId(int);
// 	void setNodeId(int);
// 	void setLength(int);

// 	int number_;
// 	int msgid_;
// 	int nodeid_;
// 	int length_;

// };


// struct DEBUGRSP : MessageType{

// 	DEBUGRSP();
// 	//Getter
// 	int getNumber();
// 	int getMsgId();
// 	int getNodeId();
// 	int getLength();


// 	//Setter
// 	void setNumber(int);
// 	void setMsgId(int);
// 	void setNodeId(int);
// 	void setLength(int);

// 	int number_;
// 	int msgid_;
// 	int nodeid_;
// 	int length_;

// };




class Message {
public:
	Message();
	//void setSockk(int);
private:
	// std::string type_;
	// int socket_;
};




// #endif