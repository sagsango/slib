#include "slib.h"

void _start() {
	slib_write (1, "Hello World!\n", 13);
  slib_exit(0);
}
