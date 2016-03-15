CC = gcc -std=gnu99

SOURCES = driver.c insertion-sort.c merge-sort.c \
          quick-sort.c selection-sort.c counting-sort.c \
		  heap-sort.c radix-sort.c sorting.h

EXECUTABLE = "driver"

build: $(SOURCES)
	$(CC) -g -o $(EXECUTABLE) $(SOURCES)

clean:
	-rm -rf $(EXECUTABLE) *.o
