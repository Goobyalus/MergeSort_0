CC = gcc
CFLAGS = -c -Wall
SOURCES = mergesort.c
OBJS = $(SOURCES:.cpp = .o)
EXECUTABLE = mergesort.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	\rm *.out *.o