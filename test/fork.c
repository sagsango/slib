#include "slib.h"

void _start(void) {
    int pid = slib_fork();
    if (pid == 0) {
        slib_write(1, "Child process\n", 14);
    } else if (pid > 0) {
        slib_write(1, "Parent process\n", 15);
    } else {
        slib_write(1, "Fork failed\n", 12);
    }
    slib_exit(0);
}
