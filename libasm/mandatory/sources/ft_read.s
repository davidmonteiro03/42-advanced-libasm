bits	64

extern	__errno_location

global	ft_read

; ssize_t ft_read(int fd, void *buf, size_t count)
ft_read:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
; 	ssize_t ret = syscall(SYS_read, fd, buf, count);
	mov	rax, 0
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
	add	rsp, 32
	pop	rbp
	ret
