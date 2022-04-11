all: dynamicMemory

dynamicMemory: dynamicMemory.o utils.o
	gcc dynamicMemory.o utils.o -o dynamicMemory
dynamicMemory.o: dynamicMemory.c
	gcc -c dynamicMemory.c
utils.o: utils.c
	gcc -c utils.c
clean:
	rm *.o dynamicMemory
