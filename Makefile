CXX=g++
CXXFLAGS=-Wall -g
SRCS = space.cpp player.cpp bank.cpp card.cpp gameboard.cpp action.cpp community.cpp chance.cpp monopoly.cpp
OBJ = $(SRCS:.cpp=.o)

all: monopoly

monopoly: $(OBJ)
	$(CXX) $(CXXFLAGS) -o monopoly $(OBJ)
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

bank.o: bank.h

player.o: player.h

action.o: action.h

card.o: card.h action.h

space.o: space.h action.h

community.o: community.h card.h action.h

chance.o: chance.h card.h action.h

gameboard.o: gameboard.h space.h player.h action.h bank.h

monopoly.o: space.h player.h bank.h card.h gameboard.h action.h community.h chance.h

clean:
	rm -f *.o *~