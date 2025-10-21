# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Targets
TARGET1 = Task1
TARGET2 = Task2

# Source files
SRC1 = Task1.c
SRC2 = Task2.c

# Default target: build both programs
all: $(TARGET1) $(TARGET2)

# Compile Task 1
$(TARGET1): $(SRC1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SRC1)

# Compile Task 2
$(TARGET2): $(SRC2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SRC2)

# Run Task 1
run1: $(TARGET1)
	./$(TARGET1)

# Run Task 2
run2: $(TARGET2)
	./$(TARGET2)

# Clean compiled binaries
clean:
	rm -f $(TARGET1) $(TARGET2)

# Prevent conflicts with files named 'all', 'clean', etc.
.PHONY: all clean run1 run2
