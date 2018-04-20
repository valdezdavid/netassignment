# echo-server: pa4.cpp
# # 	# (1) if you are using g++, you can just replace "gcc" with "g++"
# # 	# (2) on nunki, use the next line and comment out the line after
# # 	#
# # 	# gcc -g -Wall -o echo-server echo-server.c -lsocket -lnsl
# 	# CC=g++
# 	#FLAGS = -g -std=c++11 -Wall
# 	#EXTRA = -lnsl -lcrytpo -lpthread
# 	g++ -g -std=c++11 -Wall -o pa4 pa4.cpp -lnsl -lcrypto -lpthread 




# run:
# # 	./pa4 12345

CXX=g++
CXXFLAGS=-g -std=c++11 -Wall
LDLIBS = -lnsl -lcrypto -lpthread


all: pa5

pa5: pa5.cpp main.o event.o network.o node.o famousnode.o regularnode.o message.o eventqueue.o timerqueue.o timer.o nodelogic.o timeout.o
	$(CXX) $(CXXFLAGS) pa5.cpp main.o event.o $(LDLIBS) -o pa5

main.o: main.h main.cpp Event.h Network.h Node.h FamousNode.h RegularNode.h Message.h EventQueue.h TimerQueue.h Timer.h NodeLogic.h Timeout.h
	g++ -g -Wall -c main.cpp -o main.o 

network.o: Network.h Network.cpp Node.h
	g++ -g -Wall -c Network.cpp -o network.o

node.o: Node.h Node.cpp EventQueue.h NodeLogic.h
	g++ -g -Wall -c Node.cpp -o node.o

famousnode.o: FamousNode.h FamousNode.cpp  Node.h Node.cpp
	g++ -g -Wall -c FamousNode.cpp -o famousnode.o

regularnode.o: RegularNode.h RegularNode.cpp  Node.h
	g++ -g -Wall -c RegularNode.cpp -o regularnode.o

message.o: Message.h Message.cpp  
	g++ -g -Wall -c Message.cpp -o message.o

eventqueue.o: EventQueue.h EventQueue.cpp Event.h
	g++ -g -Wall -c EventQueue.cpp -o eventqueue.o

timerqueue.o: TimerQueue.h TimerQueue.cpp Timer.h
	g++ -g -Wall -c TimerQueue.cpp -o timerqueue.o

timer.o: Timer.h Timer.cpp Event.h
	g++ -g -Wall -c Timer.cpp -o timer.o

event.o: Event.h Event.cpp
	g++ -g -Wall -c Event.cpp -o event.o

nodelogic.o: NodeLogic.h NodeLogic.cpp
	g++ -g -Wall -c NodeLogic.cpp -o nodelogic.o

timeout.o: Timeout.h Timeout.cpp
	g++ -g -Wall -c Timeout.cpp -o timeout.o



	


clean:
	rm -f pa5
	rm -f main.o
	
