CXXFLAGS=--std=c++11 -Wall
project2: main.cpp Client.o GroupStack.o GroupQueue.o Group.o
	g++ $(CXXFLAGS) $^ -o $@ 

Client.o: Client.cpp GroupStack.o GroupQueue.o Group.o
	g++ -c $(CXXFLAGS) $^ -o $@

GroupStack.o: GroupStack.cpp Group.o
	g++ -c $(CXXFLAGS) $^ -o $@ 

GroupQueue.o: GroupQueue.cpp Group.o
	g++ -c $(CXXFLAGS) $^ -o $@

Group.o: Group.cpp
	g++ -c $(CXXFLAGS) $^ -o $@
clean:
	rm project2 Group.o GroupStack.o GroupQueue.o Client.o
