-include config.mk

CC = gcc
CFLAGS = -g
SRC = main.c
TARGET = main

ifeq ($(FTRUNCATE), y)
	CFLAGS += -DFTRUNCATE
endif

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
