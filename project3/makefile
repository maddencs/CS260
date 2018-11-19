CXXFLAGS=--std=c++11 -Wall
project3: main.cpp SiteTable.o SiteInfo.o
	g++ $(CXXFLAGS) $^ -o $@ 

SiteTable.o: SiteTable.cpp SiteInfo.o
	g++ -c $(CXXFLAGS) $^ -o $@

SiteInfo.o: SiteInfo.cpp
	g++ -c $(CXXFLAGS) $^ -o $@ 

clean:
	rm project3 SiteTable.o SiteInfo.o
