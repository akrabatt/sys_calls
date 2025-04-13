CC = gcc
CFLAGS = -g 
OFLAG = -o
OBJFLAG = -c
OBJS = main.o help_fun.o
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) $(OFLAG) $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) $(OBJFLAG) main.c

help_fun.o: help_fun.c
	$(CC) $(CFLAGS) $(OBJFLAG) help_fun.c

clean:
	rm -rf $(TARGET) $(OBJS) file_1.txt file_2.txt
