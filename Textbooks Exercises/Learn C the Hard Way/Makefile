# specifies the compiler
CC = gcc

# -Wall	turns on most compiler warnings
# -g 	enables debugging info
CFLAGS = -Wall -g

# specifies name of executable
TARGET = ex1

# what the 'make all' command executes when used
# list the dependencies after the colon in the order
# you want them to execute
all: other $(TARGET)

	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

other:

	echo "This is another dependency on which all is based"

# what 'make clean' command executes
clean:

	$(RM) $(TARGET)


