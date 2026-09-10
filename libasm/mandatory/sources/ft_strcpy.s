bits	64

global	ft_strcpy

; char *ft_strcpy(char *dest, const char *src)
ft_strcpy:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	mov	qword [rbp - 16], rdi
	mov	qword [rbp - 24], rsi
; 	if (*src == '\0')
	mov	rax, qword [rbp - 24]
	movsx	eax, byte [rax]
	cmp	eax, 0
	jne	.copy_char
; 	{
; 		*dest = '\0';
	mov	rax, qword [rbp - 16]
	mov	byte [rax], 0
; 		return dest;
	mov	rax, qword [rbp - 16]
	mov	qword [rbp - 8], rax
	jmp	.return
; 	}
; 	*dest = *src;
.copy_char:
	mov	rax, qword [rbp - 24]
	mov	cl, byte [rax]
	mov	rax, qword [rbp - 16]
	mov	byte [rax], cl
; 	ft_strcpy(dest + 1, src + 1);
	mov	rdi, qword [rbp - 16]
	add	rdi, 1
	mov	rsi, qword [rbp - 24]
	add	rsi, 1
	call	ft_strcpy
; 	return dest;
	mov	rax, qword [rbp - 16]
	mov	qword [rbp - 8], rax
; }
.return:
	mov	rax, qword [rbp - 8]
	add	rsp, 32
	pop	rbp
	ret
