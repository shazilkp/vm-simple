# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude -g

# Directories
SRC_DIR = src
OBJ_DIR = build

# Source and object files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/vm.c $(SRC_DIR)/stack.c $(SRC_DIR)/instr.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output binary
TARGET = vm-simple

# Default target
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile each source file into object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if missing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Run the VM (optional shortcut)
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets (non-file)
.PHONY: all clean run

