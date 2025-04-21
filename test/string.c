#include "slib.h"

#define N 5

void _start (void) {
	const char *str[] = {
		"",
		"Hello",
		"Hi",
		"12345",
		"Bye\n"
	};
	const int len[] = {
		0,
		5,
		2,
		5,
		4
	};

	for (int i=0; i<N; ++i) {
		if (strlen(str[i]) != len[i]) {
			slib_write(1, "Fail:", 5);
			slib_write(1, str[i], len[i]);
			slib_write(1, "\n", 1);
			slib_exit(0);
		}
	}

	slib_write(1, "Pass\n", strlen("Pass\n"));
	slib_exit(0);
}



			
