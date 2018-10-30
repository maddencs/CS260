CXXFLAGS=--std=c++11 -Wall
app: main.cpp LinkedList.o Node.o Artist.o Song.o RecordLabel.o
	g++ $(CXXFLAGS) $^ -o $@ 

RecordLabel.o: RecordLabel.cpp Artist.o Song.o
	g++ -c $(CXXFLAGS) $^ -o $@ 

Artist.o: Artist.cpp LinkedList.o Node.o
	g++ -c $(CXXFLAGS) $^ -o $@ 

Song.o: Song.cpp LinkedList.o Node.o
	g++ -c $(CXXFLAGS) $^ -o $@ 

Node.o: Node.cpp
	g++ -c $(CXXFLAGS) $^ -o $@ 

LinkedList.o: LinkedList.cpp Node.o
	g++ -c $(CXXFLAGS) $^ -o $@ 

clean:
	rm LinkedList.o Node.o Song.o Artist.o RecordLabel.o app
