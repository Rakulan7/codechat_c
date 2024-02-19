CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=-lmysqlclient -lssl -lcrypto
TARGET=codechat
SRCS=database/database.c compte/signup.c main.c
OBJS=$(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
