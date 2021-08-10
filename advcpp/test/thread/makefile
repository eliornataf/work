TARGET= main

CXX=g++
CC=$(CXX)

CFLAGS= -g3 -pedantic
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall -Werror
CXXFLAGS += -g3

LDLIBS = -lpthread

CPPFLAGS = -I../inc 
CPPFLAGS += -I../../inc

SRC_DIR = ../../src
INC_DIR = ../../inc

check: $(TARGET)
	./$(TARGET)

main: main.cpp $(SRC_DIR)/barrier.cpp

clean:
	$(RM) $(TARGET)

.PHONY: clean check 