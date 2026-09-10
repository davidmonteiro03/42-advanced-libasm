bits	64

global	ft_strlen

; size_t ft_strlen(const char *s)
ft_strlen:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 16
	mov	qword [rbp - 16], rdi
; 	if (*s == '\0')
	mov	rax, qword [rbp - 16]
	movsx	eax, byte [rax]
	cmp	eax, 0
	jne	.recursion
; 		return 0;
	mov	qword [rbp - 8], 0
	jmp	.return
; 	return 1 + ft_strlen(s + 1);
.recursion:
	mov	rdi, qword [rbp - 16]
	add	rdi, 1
	call	ft_strlen
	add	rax, 1
	mov	qword [rbp - 8], rax
; }
.return:
	mov	rax, qword [rbp - 8]
	add	rsp, 16
	pop	rbp
	ret
