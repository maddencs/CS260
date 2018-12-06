CXXFLAGS=--std=c++11 -Wall
project4: main.cpp BinarySearchTree.o SiteInfo.o
	g++ $(CXXFLAGS) $^ -o $@ 

BinarySearchTree.o: BinarySearchTree.cpp SiteInfo.o
	g++ -c $(CXXFLAGS) $^ -o $@

SiteInfo.o: SiteInfo.cpp
	g++ -c $(CXXFLAGS) $^ -o $@ 

clean:
	rm project4 BinarySearchTree.o SiteInfo.o
