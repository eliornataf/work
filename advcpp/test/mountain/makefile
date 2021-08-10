TARGET= main

CXX=g++
CC=$(CXX)

CFLAGS= -g3 -pedantic
CXXFLAGS = -std=c++17
CXXFLAGS += -pedantic -Wall -Werror
CXXFLAGS += -g3

CPPFLAGS = -I../inc 

check: $(TARGET)
	./$(TARGET)

main: main.cpp

clean:
	$(RM) $(TARGET)

.PHONY: clean check 