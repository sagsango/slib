.globl slib_syscall
.globl slib_fork
slib_syscall:
	push %rbp
	movq %rsp, %rbp
	movq %rcx, %r10 # XXX: kernel arg passing in syscall is diff
	movq 16(%rbp), %rax
	syscall
	popq %rbp
	ret

slib_fork:
  push %rbp
	movq %rsp, %rbp
	movq 8(%rbp), %rdi # return address
	movq $0x39, %rax # fork syscall number
	syscall
	cmp $0x0, %rax
	je child
	popq %rbp
	ret
child:
  push %rdi
	ret

	
