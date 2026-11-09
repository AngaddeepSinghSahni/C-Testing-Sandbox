# Variables for compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# The final executable name
TARGET = tester

# Default rule when you type 'make'
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): string_function.o test_string_function.o
	$(CC) $(CFLAGS) -o $(TARGET) string_function.o test_string_function.o

# Compile string_function.c to string_function.o
string_function.o: string_function.c string_function.h
	$(CC) $(CFLAGS) -c string_function.c

# Compile test_string_function.c to test_string_function.o
test_string_function.o: test_string_function.c string_function.h
	$(CC) $(CFLAGS) -c test_string_function.c

# Clean rule to wipe binary and object files
clean:
	rm -f *.o $(TARGET)
