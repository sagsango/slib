# Paths to your library and source files
LIB_DIR := ../build
INCLUDE_DIR := ../include
OBJ_DIR := ../build
TEST_DIR := $(OBJ_DIR)/test

CC := gcc
CFLAGS := -Wall -Wextra -nostdlib -ffreestanding -fno-builtin -I$(INCLUDE_DIR)
LDFLAGS := -L$(LIB_DIR) -lslib -Wl,-rpath=$(abspath $(LIB_DIR))

# Test-specific source files
TEST_SRCS := write.c fork.c
TEST_OBJS := $(patsubst %.c,$(TEST_DIR)/test_%.o,$(TEST_SRCS))
TEST_EXECS := $(patsubst %.c,$(TEST_DIR)/%_test,$(TEST_SRCS))

# Ensure test directory exists
$(shell mkdir -p $(TEST_DIR))

# Targets
all: $(TEST_EXECS)

$(TEST_DIR)/%_test: $(TEST_DIR)/test_%.o $(LIB_DIR)/libslib.so
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

$(TEST_DIR)/test_%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule for tests
clean:
	rm -rf $(TEST_DIR)

.PHONY: all clean
