#include "io.h"
#include "slib.h"

void _statr() {
	char * buf[256] = {0};
	slib_write(1, "Enter a line:", sizeof("Enter a line:"));
	read_line(1, buf);
	slib_write(1, buf, 256);

	int input = -1;
	slib_write(1, "Enter an int:", sizeof("Enter an int:"));
	read_int(1, &input);
	write_int(1, input);
	slib_exit(0);
}
