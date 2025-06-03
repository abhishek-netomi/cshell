CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g -O0

LDFLAGS =

SRCS = $(wildcard *.c)

EXEC = hello

.PHONY = all clean run

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC) $(LDFLAGS)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC) *.o
