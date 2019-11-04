
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= Node.o Graph.o mainAstarSearch.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o Astar ${OBJS}

clean:
	rm -rf *.o *.txt Astar
