CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = main.o Die.o Menu.o checkInput.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Game.o CharQueue.o

SRCS = main.cpp Die.cpp Menu.cpp checkInput.cpp Character.cpp Barbarian.cpp Vampire.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp Game.cpp CharQueue.cpp

HEADERS = 

project4: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	-rm ${OBJS} project4