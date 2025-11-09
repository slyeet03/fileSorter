CC = gcc
CFLAGS = -Wall

all: filesorter

filesorter: main.o file_utils.o sort_algorithms.o
	$(CC) $(CFLAGS) main.o file_utils.o sort_algorithms.o -o filesorter

main.o: main.c file_utils.h sort_algorithms.h
	$(CC) $(CFLAGS) -c main.c

file_utils.o: file_utils.c file_utils.h
	$(CC) $(CFLAGS) -c file_utils.c

sort_algorithms.o: sort_algorithms.c sort_algorithms.h
	$(CC) $(CFLAGS) -c sort_algorithms.c

clean:
	rm -f *.o filesorter

