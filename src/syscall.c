#include "slib.h"
#include "errno.h"
#include "sysno.h"

/* 0x00 */
int slib_read(const int fd, void *buf, const int size) {
	return slib_syscall(fd, buf, size, 0, 0, 0, SYS_READ);
}
int slib_write(const int fd, void *buf, const int size) {
	return slib_syscall(fd, buf, size, 0, 0, 0, SYS_WRITE);
}
int slib_open(const char * pathname, const int flag, const int mode) {
	return ENOSUPPORT;
}
int slib_close(const int fd) {
	return ENOSUPPORT;
}

/*
 * XXX: **envp is supported by kernel, for the process?
 *	where it is getting saved and how to retrive that?
 */
int slib_exec(const char *filename, const char * const *argv, const char *const *envp) {
	return slib_syscall(filename, argv, envp, 0, 0, 0, SYS_EXEC);
}
int slib_exit(const int error_code) {
	return slib_syscall(error_code, 0, 0, 0, 0, 0, SYS_EXIT);
}

