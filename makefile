CC		= gcc
CXX		= g++
CFLAGS	= -O2 -Wall
CXXFLAGS = -O2 -Wall -std=c++11

TARGET	= TSP.out
CSOURCES := $(shell ls *.c)
CXXSOURCES := $(shell ls *.cpp)
HEADER	:= $(shell ls *.h)
OBJS	:= $(CSOURCES:.c=.o) $(CXXSOURCES:.cpp=.o)
LDFLAGS	=
INCLUDES =
LIBS	=# -lglut -lGLU -lGL -lm

$(TARGET): $(OBJS) $(LIBS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<

main.o: resources.h
Nodes.o: Nodes.h
Fisher_Yates.o: Fisher_Yates.h
TSP.o: TSP.h
