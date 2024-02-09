CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=-lmysqlclient -lssl -lcrypto
TARGET=codechat
SRCS=compte/compte.c database/database.c
OBJS=$(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
