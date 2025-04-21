#include "slib.h"
#include "io.h"
#include "string.h"

int read_line(const int fd, char *l) {
	char * c = l;
	int status;
	while ((status = slib_read(fd, c, 1)) == 1) {
		if (*c == '\n') {
			*c = 0;
			status = 0;
			break;
		}
		c += 1;
	}
	if (status) {
		return status;
	}
	return c - l;
}

int read_word(const int fd, char *w) {
	char * c = w;
	int status;
	while ((status = slib_read(fd, c, 1)) == 1) {
		if (*c == ' ' || *c == '\n') {
			*c = 0;
			status = 0;
			break;
		}
		c += 1;
	}
	if (status) {
		return status;
	}
	return c - w;
}

/*
 * TODO:
 *	We only support the numbers without sign
 */
int read_int(const int fd, int *num) {
	char word[64]= {0};
	int status = read_word(fd, word);
	if (status < 0) {
		return status;
	}
	return stoi(word, num);
}

int write_int(const int fd, const int num) {
	char word[64] = {0};
	int status = itos(num, word);
	if (status < 0) {
		return status;
	}
	return slib_write (fd, word, strlen(word));
}

