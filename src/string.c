#include "string.h"

int strlen(const char * str) {
	if (str == 0) {
		return 0;
	}
	char * ptr = str;
	while (*ptr) {
		ptr += 1;
	}
	return ptr - str;
}

int reverse(char *str) {
	int l = 0, r = strlen(str) - 1;
	char c;
	while (l<r) {
		c = str[l];
		str[l] = str[r];
		str[r] = c;
		l += 1;
		r -= 1;
	}
	return 0;
}

int itos(int num, char * buf) {
	if (num == 0) {
		buf[0] = '0';
		return 1;
	}
	int i = 0;
	while (num) {
		buf[i] = (num % 10) + '0';
		i += 1;
		num /= 10;
	}
	reverse(buf);
	return i;
}

int stoi(const char * const str, int *num) {
	*num = 0;
	if (str == 0) {
		return 0;
	}
	char * c = str;
	while (*c) {
		*num = (*num) * 10 + (*c - '0');
		c += 1;
	}
	return c - str;
}
