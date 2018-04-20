
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <typeinfo>
/////////////
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <openssl/sha.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <pthread.h>

#include <stdio.h>
// #include <openssl/md5.h>
#include <chrono>
#include <ctime>
#include <vector>
// #include "main.h"
#include "Event.h"



/*
  discovery request
  discovery response
  hello message
  keep alive message
  check request
  check response
  goodbye
  link state request message
  link state response
  link state update message
  debug response
  create one thread to interact with the user and two networking threads to
  handle each connection
    one reads from the socket 
    one for writing to the socket 

    //Create a thread that takes in a function and has a parameter
    {threadFn, 100}
    if youre passing a var by reference, need to write in function declaration
    threadFn, ref(localVar)









  
*/




using namespace std;
 
//bool checkCommandLine(vector<string>&); the one from pa4
bool verifyCommandLineStartUp(vector<string>&);
void GetObjID(
            char node_id[40],
            char obj_category[8],
            char returned_obj_id[SHA_DIGEST_LENGTH],
            char hexstring_of_obj_id[(SHA_DIGEST_LENGTH<<1)+1]);

//Command for command line
// // /void handleCommand(string command);
// typedef struct {
//         string host_;
//         int control_port_;
//         int app_port_;
//         int location_;
//         string root_;
//         string pid_;
//         string log_;
// } ConfigInformation;
// typedef struct{
//         int ttl_;
//         int num_startup_neighbors_;
//         int msg_life_time_;
//         int keep_alive_timeout_;
//         int check_timeout_;
//         int discovery_timeout_;
//         int discovery_retry_interval_;
// } Params;
// typedef struct{
//         int famous_retry_interval_;
//         int count_;
//         vector<string> nodes_;
// } Famous;


//GLOBAL VARIABLES

vector<pthread_t> threads_ = NULL;

//Event queue
EventQueue eq_ = NULL;


//void parseConfigPart(ConfigInformation&);
//void parseConfigFile(string,ConfigInformation&, Params&, Famous&);
void parseConfigFile(string, NodeLogic&);
void parseConfigSection(ifstream&, NodeLogic&); 
void parseParamsSection(ifstream&,NodeLogic&);
void parseFamousSection(ifstream&,NodeLogic&);
bool checkIfFamous(NodeLogic& nl);
void GetObjID(
            char node_id[40];
            char obj_category[8],
            char returned_obj_id[SHA_DIGEST_LENGTH],
            char hexstring_of_obj_id[(SHA_DIGEST_LENGTH<<1)+1])
{ 
  static unsigned long seq_no=0L;
  static struct timeval node_start_time;
  static char hexchar[]="0123456789abcdef";
  char unique_str[128];

  if (seq_no++ == 0L) {
      gettimeofday(&node_start_time, NULL);
  }
  snprintf(unique_str, sizeof(unique_str), "%s_%d_%s_%1ld",
          node_id, (int)(node_start_time.tv_sec), obj_category, (long)seq_no);
  SHA1((unsigned char *)unique_str, strlen(unique_str), (unsigned char *)returned_obj_id);
  for (int i=0; i < SHA_DIGEST_LENGTH; i++) {
      unsigned char ch=(unsigned char)returned_obj_id[i];
      int hi_nibble=(int)(unsigned int)((ch>>4)&0x0f);
      int lo_nibble=(int)(unsigned int)(ch&0x0f);

      hexstring_of_obj_id[i<<1] = hexchar[hi_nibble];
      hexstring_of_obj_id[(i<<1)+1] = hexchar[lo_nibble];
  }
  hexstring_of_obj_id[SHA_DIGEST_LENGTH<<1] = '\0';

}
void *handle_connection(void *arg)
{
  int bytes_received;
  char buf[1024];
  struct sockaddr_in peer;
  socklen_t peer_addr_len = (socklen_t)sizeof(peer);
  int newsockfd = (int)(unsigned long)arg;

  bytes_received = read(newsockfd, buf, sizeof(buf));
   cout << "BUF " << buf << endl;
  getpeername(newsockfd, (struct sockaddr *)(&peer), &peer_addr_len);

  fprintf(stderr,
          "[SERVER] Client is from %s:%1d\n",
          inet_ntoa(peer.sin_addr),
          (int)htons((uint16_t)(peer.sin_port & 0x0ffff)));

  //Create an event object
  // COMMENTING OUT FOR TESTING PURPOSES
  /*
  Event* event = new Event("Message");
  event->setSockk(newsockfd);
  //SET THE MESSAGE
  /ADD THE EVENT OBJECT TO THE WORK QUEUE OF THE EVENT THREAD
  */
  //writes to client
  // write(newsockfd, buf, bytes_received);
  //close(newsockfd);

  return NULL;
}
void *write_socket(void *arg){
  int bytes_received;
  char buf[1024];
  struct sockaddr_in peer;
  socklen_t peer_addr_len = (socklen_t)sizeof(peer);
  int newsockfd = (int)(unsigned long)arg;

  //bytes_received = read(newsockfd, buf, sizeof(buf));
  cout << "INSIDE WRITING" << endl;
  getpeername(newsockfd, (struct sockaddr *)(&peer), &peer_addr_len);

  fprintf(stderr,
          "[SERVER] Client is from %s:%1d\n",
          inet_ntoa(peer.sin_addr),
          (int)htons((uint16_t)(peer.sin_port & 0x0ffff)));

  //writes to client
  write(newsockfd, buf, bytes_received);

  //close(newsockfd);

  return NULL;
}
void *console(void *arg)
{
  char buf[1024];

  printf("(This console echoes whatever you type.)\n");
  printf("> ");
  while (fgets(buf, sizeof(buf), stdin) != NULL) {
      printf("%s", buf);
      cout << "THIS IS BUF " << buf << endl;
      printf("> ");
      cout << "SIZE " << threads.size() << endl;
  }
  printf("The console is closed.  (Should close all connections and shutdown immediately.)\n");

  return NULL;
}
//TODO
void *eventHandler(void *arg)
{
  //Will handle all of the events
  //need to know of the event queue
  //THe event queue will be a global variable
  // while()
  /*  
    will stay in an infinite loop waiting for work(to get added to the event queue
    
  
  while(eq_.size() != 0){
    //Handle the event
  }
  return NULL;
  */

}
//TODO
void *timerThread(void *arg)
{
  /*
    -need to wake up every 0.25 seconds 
    to decrement counters
    -manages a list of timeout objects (counter + event) (this could be a separate struct)

    - no work queue for this thread 

    - if a counter reaches 0, remove the counter and add event to the event queue (fire the event)



  */
}


int main(int argc, char *argv[])
{
  

  char server_name[256];
  int reuse_addr = 1;
  int master_socket_fd;
  //Commented for testing
  struct addrinfo hints;
  struct addrinfo* res;
  pthread_t console_thread_id;

  //Create an instance of the event queue
  EventQueue eq = EventQueue();
  eq_ = eq;

  
    

  int portNumber = 7061;
  string logFile = "pa5.log";
  string pidFile = "pa5.pid";
  string root = "/home/scf-22/csci551b/public/cs353/pa5";
  string mimefile ="";
  int bVal, pVal, maxrVal, dialVal = 0;
  // //Port numbers 7016 to 7051 inclusive 

  //Create section to check command line on startup
  vector<string> v(argv,argv+argc);
  bool commandLineIsGood = verifyCommandLineStartUp(v);
  if(!commandLineIsGood){
    cout << "WRONG " << endl;
    return 1;
  }

  //End of checking for command line on startup

  string filename = argv[1];
  cout << "Printing file name" << filename << endl;
  //Create the config struct that will hold all the information from the config file 
  // ConfigInformation configInfo;
  // Params params;
  // Famous famous;
 
 // parseConfigFile(filename,configInfo, params, famous);

  // string portString = to_string(configInfo.control_port_);
  // const char* c = portString.c_str();
  // cout << "HERE" << endl;
  gethostname(server_name, sizeof(server_name));
  // cout << "CONFIG PORT NUMBER " << configInfo.control_port_ << endl;
  // return 1;
  memset(&hints,0,sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = 0;
  hints.ai_flags = AI_NUMERICSERV|AI_ADDRCONFIG;

  getaddrinfo(server_name, argv[1], &hints, &res);
  master_socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  setsockopt(master_socket_fd, SOL_SOCKET, SO_REUSEADDR, (void*)(&reuse_addr), sizeof(int));
  bind(master_socket_fd, res->ai_addr, res->ai_addrlen);
  listen(master_socket_fd, 1);
  {
      /* the following will show you exactly where your server thinks it's running at */
      struct sockaddr_in server_addr;
      socklen_t server_len = (socklen_t)sizeof(server_addr);

      getsockname(master_socket_fd, (struct sockaddr *)(&server_addr), &server_len);
      fprintf(stderr,
              "[SERVER] Server listening at %s:%1d\n",
              inet_ntoa(server_addr.sin_addr),
              (int)htons((uint16_t)(server_addr.sin_port & 0x0ffff)));
  }
  //This thread creates the console thread
  pthread_create(&console_thread_id, NULL, console, NULL);
//TODO
  //This thread creates the event thread
  pthread_create(&event_thread_id,NULL,eventHandler,NULL);
  //TODO
  //Need to create a timer thread 
  // pthread_create(&timer_thread_id, NULL, timerThread,NULL);

  for (;;) {
      struct sockaddr_in cli_addr;
      unsigned int clilen = sizeof(cli_addr);
      int newsockfd;
      pthread_t thread_id;

      //create new node logi
      NodeLogic nodeLogic = NodeLogic();

      //Parse config file 
      parseConfigFile(nodeLogic);

      //Figure out if youre a famous or regular node
      bool famous = checkIfFamous(nodeLogic);
      //creating new socket 
      newsockfd = accept(master_socket_fd, (struct sockaddr *)(&cli_addr), &clilen);
      pthread_create(&thread_id, NULL, handle_connection, (void*)(unsigned long)newsockfd);
      pthread_create(&thread_id,NULL, write_socket,(void*)(unsigned long)newsockfd);
      threads.emplace_back(thread_id);

      //TODO
      //Create add neighbor event
        //Include newly created socket in event
  }
  close(master_socket_fd);

  return 0;
}

// void handleCommand(string command){
//   //Command should either be neighbors, netgraph, debug, shutdown
//   if(command == "neighbors"){

//   }
//   else if(command == netgraph){

//   }
//   else if(command == debug){

//   }
//   else if(command == shutdown){

//   }
//   else{
//     //Not a valid command 
//   }

// }

bool checkIfFamous(NodeLogic& nl){
  bool famous = false;

  //Depends on host and control port
  string host = nl.getHost();
  int controlPort = nl.getControlPort();
  string controlPortString = std::to_string(controlPort);

  string nodeId = host;
  nodeId += "_";
  nodeId += controlPortString;

  //Set the node id
  nl.setNodeId(nodeId);

  //Get the nodes from nl
  vector<string> nodes = nl.getNodes();
  for(int i = 0; i < nodes.size();i++){
    if(nodeId == nodes[i]){
      famous = true;
    }
  }

  return famous;

}

bool verifyCommandLineStartUp(vector<string>& v){
  bool okay = false;
  // int args = v.size();
  // if(args != 2){
  //   string res = "Malformed command";
  //   v.emplace_back(res);
  //   return okay;
  // }
  // else if(args == 2){

  // }
  return true;
}


// void parseConfigFile(string filename, int& control_port, int&app)
void parseConfigFile(string filename, NodeLogic& nl){


  string type = "";
  // cout << "IN HERE " << endl;
  string line;
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
     
      // cout << "LINE FROM parse " << line << endl;
      //This represents the start of the config section
      if(line == "[config]"){
        // parseConfigPart(myfile,port, logFile, pidFile,root,mimeFile);    
        parseConfigSection(myfile,nl);   
      }
      else if(line == "[params]"){
        // parseTypeSection(myfile, bVal, pVal, maxrVal, dialVal);
        // printValues(filename, bVal, pVal, maxrVal, dialVal, port,logFile,pidFile,root,
        // mimeFile);
        // return;
        parseParamsSection(myfile, nl);

      }
      else if(line == "[famous]"){
        // parseTypeSection(myfile, bVal, pVal, maxrVal, dialVal);
        // printValues(filename, bVal, pVal, maxrVal, dialVal, port,logFile,pidFile,root,
        // mimeFile);
        // return;
        parseFamousSection(myfile, nl);
      }


    }
    myfile.close();
  }

}

void parseConfigSection(ifstream& myfile, NodeLogic& config){
  string line = "";
  //Read in for a total of 7 times
  for(int i = 0; i < 7;i++){
    //Get the line from the file
    //& store it in line
    getline(myfile,line);

    //Get the parameter we are setting
    size_t equalSign = line.find("=");
    if(equalSign != string::npos)
    {
      string key = line.substr(0,equalSign);
      cout << "KEY " << key << endl;
      string valueString = line.substr(line.find("=")+1);
      
      cout << "AFTER VALUE IN PARSE" << endl;
      if(key == "host"){
        config.setHost(valueString);
      }
      else if(key == "control_port"){
        int value = std::stoi(valueString);
        config.setControlPort(value);
      }
      else if(key == "app_port"){
        int value = std::stoi(valueString);
        config.setAppPort(value);
      }
      else if(key == "location"){
        int value = std::stoi(valueString);
        config.setLocation(value);
      }
      else if(key == "root"){
        config.setRoot(valueString);
      }
      else if(key == "pid"){
        config.setPid(valueString);
      }
      else if(key == "log"){
        config.setLog(valueString);
      }
    }
  }
}
void parseParamsSection(ifstream& myfile, NodeLogic& params){
  string line ="";
  getline(myfile,line);
  for(int i = 0;i < 7;i++){
    size_t equalsSign = line.find("=");
    if(equalsSign != string::npos){
      string key = line.substr(0,equalsSign);
      cout << "KEY " << key << endl;
      string valueString = line.substr(line.find("=")+1);
      int value = std::stoi(valueString);
      cout << "AFTER VALUE IN PARSE parms" << endl;
      cout << "params 1" << endl;
      if(key == "ttl"){
        params.setTtl(value)
      }
      else if(key == "num_startup_neighbors"){
        params.setNumStartupNeighbors(value)
      }
      else if(key == "msg_life_time"){
        params.setMsgLifeTime(value)
      }
      else if(key == "keep_alive_timeout"){
        params.setKeepAliveTimeout(value)
      }
      else if(key == "check_timeout"){
        params.setCheckTimeout(value)
      }
      else if(key == "discovery_timeout"){
        params.setDiscoveryTimeout(value)
      }
      else if(key == "discovery_retry_interval"){
        params.setDiscoveryRetryInterval(value)
      }
    }
  }
  cout << "END of params" << endl;
}
void parseFamousSection(ifstream& myfile, NodeLogic& famous){
  string line="";
  cout << "famous 1" << endl;
  int count = -1;
  getline(myfile,line);
  cout << "famous" << endl;
  for(int i = 0;i < 2;i++){
    size_t equalSign = line.find("=");
    if(equalSign != string::npos){
      string key = line.substr(0,equalSign);
      if(key == "famous_retry_interval"){
        string number = line.substr(line.find("=") +1);
        famous.setFamousRetryInterval(std::stoi(number));
        cout << "famous 1" << endl;
      }
      else if(key == "count"){
        string countString = line.substr(line.find("=")+1);
        famous.setCount(std::stoi(countString));
        count = famous.getCount();
        cout << "famous 2" << endl;
      }

    }
  }
  //Need to initialize vector to store in famous
  vector<string> newVector;

  //Count has been intialized
  //Need to still read in the line
  for(int i = 0; i < count; i++){
    // newVector.emplace_back()N
    getline(myfile,line);
    //extra checking; make sure line starts with
    //current i value
    int firstChar = (int)line[0];
    if(firstChar == i){
      //Get the second portion after the equals sign
      string data = line.substr(line.find("=")+1);
      newVector.emplace_back(data);
    }

  }
  cout << "END OF FAMOUS" << endl;
  //Set the vector to famous' vector nodes
  //Will need to 
  famous.setNodes(newVector);
}

// bool checkCommandLine(vector<string>& v){
//   int numArgs = v.size();
//   bool okay = false;
//   vector<string> response;
//   //If num args is greater than 2
//   if(numArgs != 2){
    
//     string res = "Malformed command";
//     response.push_back(res);
//     v = response;
//     return okay;
//   }
  
//   if(numArgs == 2){
//     //If argument 2 has a - at the beginning
//     //Get second argument in line
//     string arg2 = v[1];
//     if(arg2[0] == '-'){
//       string res = "Malformed command";
//       response.push_back(res);
//       v = response;
//       return okay;
//     }

//     //Check if the input file is present
//     string filename = v[1];

//     //Check if filename has /
//     size_t forwardSlash = filename.find("/");
//     //Make sure we actually found the = sign
//     if(forwardSlash != string::npos){
//       string res = "cannot open " + filename;
//       response.push_back(res);
//       v = response;
//       return okay;
//     }
//     else{
//       ifstream myfile (filename);
//       if(!myfile.is_open()){
//         string res = "Cannot open [" + filename + "]";
//         response.push_back(res);
//         v = response;
//         return okay;
//       }
//     }

   
//     //cout <<"CHECKING " << endl;


//   }


//   okay = true;
//   return okay;
// }