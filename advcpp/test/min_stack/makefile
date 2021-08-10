TARGET= main

CXX=g++
CC=$(CXX)

CFLAGS= -g3 -pedantic
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall -Werror
CXXFLAGS += -g3

CPPFLAGS = -I../inc 
CPPFLAGS += -I../../inc 

SRC_DIR = ../../src
INC_DIR = ../../inc

check: $(TARGET)
	./$(TARGET)

main: main.cpp $(INC_DIR)/min_stack.hpp ../inc/ball.hpp ../src/ball.cpp

clean:
	$(RM) $(TARGET)

.PHONY: clean check