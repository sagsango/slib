SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := build

CC := gcc
AS := as
CFLAGS := -g3 -Wall -Wextra -nostdlib -ffreestanding -fno-builtin -fPIC -I$(INCLUDE_DIR)
ASFLAGS := 
LDFLAGS := -shared

# Ensure OBJ_DIR exists
$(shell mkdir -p $(OBJ_DIR))

# Source files
OBJS := $(OBJ_DIR)/syscall.o $(OBJ_DIR)/ams.o $(OBJ_DIR)/string.o $(OBJ_DIR)/io.o

# Targets
all: $(OBJ_DIR)/libslib.so

$(OBJ_DIR)/syscall.o: $(SRC_DIR)/syscall.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/ams.o: $(SRC_DIR)/asm.s
	$(AS) $(ASFLAGS) $< -o $@

$(OBJ_DIR)/string.o: $(SRC_DIR)/string.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/io.o: $(SRC_DIR)/io.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/libslib.so: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

# Clean rule
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/libslib.so

.PHONY: all clean
