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

pa5: pa5.cpp main.o event.o
	$(CXX) $(CXXFLAGS) pa5.cpp main.o event.o $(LDLIBS) -o pa5

main.o: main.h main.cpp Event.h
	g++ -g -Wall -c main.cpp -o main.o 

event.o: Event.h Event.cpp
	g++ -g -Wall -c Event.cpp -o event.o

	


clean:
	rm -f pa5
	rm -f main.o
	
