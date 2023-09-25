##
## EPITECH PROJECT, 2023
## B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq copie
## File description:
## Makefile
##

# Variables
CC=gcc
CFLAGS=-I. -Wall
DEPS = $(shell find ./src -name "*.h")
SRC = $(shell find ./src -name "*.c")
OBJ = $(SRC:.c=.o)
EXECUTABLE = serverJ2T3

# Default Rule
all: $(EXECUTABLE)

# Rule for building the final executable
$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# General Rule for compiling source files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

# Rule for cleaning up object files and executable
clean:
	rm -f $(OBJ) $(EXECUTABLE)
