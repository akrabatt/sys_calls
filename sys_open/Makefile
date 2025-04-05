CC = gcc
CFLAGS = -Wall
LDFLAGS= -lm
SRC = open.c
OBJS = $(SRC:.c=.o)
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
