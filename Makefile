# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11 -Iinclude
LDFLAGS = -lm

# Directories
SRC_DIR  = src
OBJ_DIR  = build
BIN_DIR  = bin

# Source files
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/args.c \
      $(SRC_DIR)/banner.c \
      $(SRC_DIR)/colors.c \
      $(SRC_DIR)/errors.c \
      $(SRC_DIR)/input.c \
      $(SRC_DIR)/operations.c \
      $(SRC_DIR)/output.c

# Object files in build/
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Binary output
BIN = $(BIN_DIR)/ccalc

# Default target
all: $(BIN)

# Build the binary
$(BIN): $(OBJ) | $(BIN_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build/ directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create bin/ directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

install: $(BIN)
	mkdir -p $(PREFIX)/bin
	cp $(BIN) $(PREFIX)/bin/

uninstall: 
	rm -f $(PREFIX)/bin/$(BIN)

.PHONY: all clean install uninstall test 

test: 
	@echo "No tests defined" 
