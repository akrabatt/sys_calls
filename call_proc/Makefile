CC = gcc
CFLAGS = -g
OFLAG = -o
OBJFLAG = -c
OBJS = main.o
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) $(OFLAG) $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) $(OBJFLAG) main.c

clean:
	rm -rf $(TARGET) $(OBJS)
