#ifndef SLIB_H
#define SLIB_H

long slib_syscall(long a1, long a2, long a3, long a4, long a5, long a6, long n);

/*
 * XXX: syscalls
 */
/* 0x00 */
int slib_read(const int fd, void *buf, const int size);
int slib_write(const int fd, void *buf, const int size);
int slib_open(const char * pathname, const int flag, const int mode);
int slib_close(const int fd);

/* 0x39 */
int slib_fork();

/* 0x3b */
int slib_exec(const char *filename, const char * const *argv, const char *const *envp);
int slib_exit(const int error_code);

/*
 * XXX: thread support
 */
/*
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*thread_function)(void *), void * arg);
*/

/*
 * XXX: memory allocation
 */
/*
void * malloc(int size);
int free(void * addr);
*/

#endif /* SLIB_H */
