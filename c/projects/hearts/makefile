SRC_DIR = src
OBJ_DIR_DEBUG = obj/debug
OBJ_DIR_RELEASE = obj/release
LIB_DIR_DEBUG = lib/debug
LIB_DIR_RELEASE = lib/release
TEST_DIR = test

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ_DEBUG = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR_DEBUG)/%.o)
OBJ_RELEASE = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR_RELEASE)/%.o)
LIB_DEBUG = $(LIB_DIR_DEBUG)/libds.so
LIB_RELEASE = $(LIB_DIR_RELEASE)/libds.so

SRC_TEST = $(wildcard $(TEST_DIR)/*.c)
TESTS = $(patsubst $(TEST_DIR)/%.c,%,$(SRC_TEST))

CC = gcc
CPPFLAGS = -I ./header
CFLAGS = -ansi -pedantic-errors -Wall -Wextra
LDFLAGS = -Llib/debug -Wl,-rpath=/home/eliornataf/experis/projects/hearts/lib/debug
LDLIBS = -lds -lm

.PHONY: all debug release test clean

all: debug release
debug: $(LIB_DEBUG)
release: $(LIB_RELEASE)
test: $(TESTS)

$(OBJ_DIR_DEBUG)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -g -fPIC -c $< -o $@

$(OBJ_DIR_RELEASE)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -DNDEBUG -O3 -fPIC -c $< -o $@

$(LIB_DEBUG): $(OBJ_DEBUG)
	$(CC) -shared -o $@ $^

$(LIB_RELEASE): $(OBJ_RELEASE)
	$(CC) -shared -o $@ $^

%: $(TEST_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@

clean:
	$(RM) -rv $(OBJ_DIR_DEBUG)/*.o $(OBJ_DIR_RELEASE)/*.o *_test
