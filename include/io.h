#include "slib.h"

int read_int(const int fd, int *num);
int read_long(const int fd, long *num);
int read_line(const int fd, char *l);
int read_char(const int fd, char *c);
int read_word(const int fd, char *w);

int write_int(const int fd, const int num);
int write_long(const int fd, const long num);
int write_line(const int fd, const char * const l);
int write_char(const int fd, const char c);
int write_word(const int fd, const char * const w);
