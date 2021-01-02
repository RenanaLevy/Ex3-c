CC = gcc -Wall
all: isort txtfind

isort: insertionSort.o
	$(CC) insertionSort.o -o isort

insertionSort.o: insertionSort.c
	$(CC) -c insertionSort.c -o insertionSort.o

txtfind: find.o
	$(CC) find.o -o txtfind

find.o: find.c
	$(CC) -c find.c -o find.o

.PHONY: clean all

clean:
	rm *.o isort txtfind