#include "slib.h"

void _start(void) {
    char *args[3] = {"ls", "-l"};
    int pid = slib_exec("/bin/ls", &args, 0);
    slib_exit(0);
}

