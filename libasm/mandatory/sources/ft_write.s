bits	64

extern	__errno_location

global	ft_write

; ssize_t ft_write(int fd, const void *buf, size_t count)
ft_write:
; {
	push	rbp
	mov	rbp, rsp
; 	ssize_t ret = syscall(SYS_write, fd, buf, count);
	mov	rax, 1
	syscall
; 	if (ret >= 0)
	cmp	rax, 0
; 		return 0;
	jge	.return
; 	// properly set errno
	neg	rax
	mov	r10d, eax
	call	__errno_location
	mov	[rax], r10d
; 	return -1;
	mov	rax, -1
; }
.return:
	pop	rbp
	ret
