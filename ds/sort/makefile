# makefile sample

TARGET= sort.out
CC= gcc
CFLAGS= -ansi -g -pedantic
OBJS= sort.o dynamicVector.o stack.o sort_test.o
VEC_PATH= ../dynamicVector/
STACK_PATH= ../stack/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
	
sort.o: sort.c sort.h ADTError.h
	$(CC) $(CFLAGS) -I$(VEC_PATH) -I$(STACK_PATH) -c sort.c
	
sort_test.o: sort_test.c sort.h
	$(CC) $(CFLAGS) -I$(VEC_PATH) -c sort_test.c
		
dynamicVector.o: $(VEC_PATH)dynamicVector.c $(VEC_PATH)ADTError.h
	$(CC) $(CFLAGS) -I$(VEC_PATH) $(VEC_PATH) -c dynamicVector.c
	
stack.o: $(STACK_PATH)stack.c $(VEC_PATH)dynamicVector.c $(STACK_PATH)ADTError.h
	$(CC) $(CFLAGS) -c $(STACK_PATH)stack.c -I$(VEC_PATH) -I$(STACK_PATH)
		
clean:
	rm -f $(TARGET) $(OBJS)
