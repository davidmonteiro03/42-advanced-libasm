bits	64

global	ft_strcmp

; int ft_strcmp(const char *s1, const char *s2)
ft_strcmp:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	mov	qword [rbp - 16], rdi
	mov	qword [rbp - 24], rsi
; 	if (*s1 == '\0' && *s2 == '\0')
	mov	rax, qword [rbp - 16]
	movsx	eax, byte [rax]
	cmp	eax, 0
	jne	.compare_chars
	mov	rax, qword [rbp - 24]
	movsx	eax, byte [rax]
	cmp	eax, 0
	jne	.compare_chars
; 		return 0;
	mov	dword [rbp - 4], 0
	jmp	.return
; 	if ((unsigned char)*s1 != (unsigned char)*s2)
.compare_chars:
	mov	rax, qword [rbp - 16]
	movzx	eax, byte [rax]
	mov	rcx, qword [rbp - 24]
	movzx	ecx, byte [rcx]
	cmp	eax, ecx
	je	.recursion
; 		return (unsigned char)*s1 - (unsigned char)*s2;
	mov	rax, qword [rbp - 16]
	movzx	eax, byte [rax]
	mov	rcx, qword [rbp - 24]
	movzx	ecx, byte [rcx]
	sub	eax, ecx
	mov	dword [rbp - 4], eax
	jmp	.return
; 	return ft_strcmp(s1 + 1, s2 + 1);
.recursion:
	mov	rdi, qword [rbp - 16]
	add	rdi, 1
	mov	rsi, qword [rbp - 24]
	add	rsi, 1
	call	ft_strcmp
	mov	dword [rbp - 4], eax
; }
.return:
	mov	eax, dword [rbp - 4]
	add	rsp, 32
	pop	rbp
	ret
