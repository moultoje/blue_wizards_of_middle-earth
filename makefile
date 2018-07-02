################################################################################
## Program Name: makefile
## Author: Jeffrey Moulton (https://github.com/moultoje)
## Version: 1.0
## Description: Makefile for the Blue Wizards of Middle-earth console game.
################################################################################


CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = clearScreen.o
OBJS += main.o
OBJS += validate.o
OBJS += game.o
OBJS += wizard.o
OBJS += space.o
OBJS += startingRoom.o
OBJS += mainRoom.o
OBJS += swordRoom.o
OBJS += hatRoom.o
OBJS += pathRoom.o
OBJS += romestamoRoom.o

HEADERS = clearScreen.hpp
HEADERS += validate.hpp
HEADERS += game.hpp
HEADERS += wizard.hpp
HEADERS += space.hpp
HEADERS += startingRoom.hpp
HEADERS += mainRoom.hpp
HEADERS += swordRoom.hpp
HEADERS += hatRoom.hpp
HEADERS += pathRoom.hpp
HEADERS += romestamoRoom.hpp

EXECUTABLE = main

${EXECUTABLE}: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o ${EXECUTABLE}

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clearScreen.o: clearScreen.cpp
	${CXX} ${CXXFLAGS} -c clearScreen.cpp

validate.o: validate.cpp
	${CXX} ${CXXFLAGS} -c validate.cpp

game.o: game.cpp
	${CXX} ${CXXFLAGS} -c game.cpp

wizard.o: wizard.cpp
	${CXX} ${CXXFLAGS} -c wizard.cpp

space.o: space.cpp
	${CXX} ${CXXFLAGS} -c space.cpp

startingRoom.o: startingRoom.cpp
	${CXX} ${CXXFLAGS} -c startingRoom.cpp

mainRoom.o: mainRoom.cpp
	${CXX} ${CXXFLAGS} -c mainRoom.cpp

swordRoom.o: swordRoom.cpp
	${CXX} ${CXXFLAGS} -c swordRoom.cpp

hatRoom.o: hatRoom.cpp
	${CXX} ${CXXFLAGS} -c hatRoom.cpp

pathRoom.o: pathRoom.cpp
	${CXX} ${CXXFLAGS} -c pathRoom.cpp

romestamoRoom.o: romestamoRoom.cpp
	${CXX} ${CXXFLAGS} -c romestamoRoom.cpp

zip:
	zip -D Project3_Moulton_Jeffrey.zip ${SRCS} ${HEADERS} makefile *.pdf

clean:
	rm ${OBJS} ${EXECUTABLE} *.zip
