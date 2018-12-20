CXX := g++
CXXFLAGS := -std=c++11 -Wall

all: TSP

run: TSP
	./TSP <graph-1000-03.txt> output.txt

runall: TSP
	./TSP <graph-1000-01.txt> output1.txt
	./TSP <graph-1000-02.txt> output2.txt
	./TSP <graph-1000-03.txt> output3.txt
	./TSP <graph-1000-04.txt> output4.txt
	./TSP <graph-1000-05.txt> output5.txt
	./TSP <graph-1000-06.txt> output6.txt
	./TSP <graph-1000-07.txt> output7.txt
	./TSP <graph-1000-08.txt> output8.txt
	./TSP <graph-1000-09.txt> output9.txt
	./TSP <graph-1000-10.txt> output10.txt

TSP: main.o graph.o
	$(CXX) $(CXXFLAGS) -o TSP main.o graph.o
	
main.o: main.cpp graph.h 
	$(CXX) $(CXXFLAGS) -c main.cpp
	
graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -c graph.cpp
	
clean:
	-rm -f TSP
	-rm -f *.o
	-rm -f *~
	-rm -f output*