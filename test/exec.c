#include "slib.h"

/*
 * TODO:
 *	argc, argv & envp should be tested
 *	how to get argc, argv & envp
 */
void _start(void) {
    char *args[3] = {"ls", "-l"};
    int pid = slib_exec("/bin/ls", &args, 0);
    slib_exit(0);
}

