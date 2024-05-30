CC = gcc
CFLAGS = -Wall -O2
OBJ = main.o consumer.o producer.o sem.o
TARGET = target

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: ./src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all

all: $(TARGET)