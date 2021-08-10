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

main: main.cpp $(SRC_DIR)/barrier.cpp $(SRC_DIR)/latch.cpp $(SRC_DIR)/lock_guard.cpp $(SRC_DIR)/mutex.cpp $(SRC_DIR)/semaphore.cpp $(SRC_DIR)/thread_pool.cpp $(SRC_DIR)/thread_pool_task_executer.cpp $(SRC_DIR)/thread_pool_infinty_task.cpp $(SRC_DIR)/thread_pool_empty_task.cpp

clean:
	$(RM) $(TARGET)

.PHONY: clean check 