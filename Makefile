CC = gcc
CFLAGS = -std=gnu11 -Wall -Wextra

SRC = arena.c
OBJ = $(SRC:.c=.o)
TARGET = libarena.a

all: $(TARGET)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

$(TARGET): $(OBJ)
	ar rcs $@ $(OBJ)

clean:
	rm $(TARGET) $(OBJ)

.PHONY: all clean
