CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm

TARGET = house_price
SRC = house_price.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
