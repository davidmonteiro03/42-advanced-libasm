bits	64

extern	malloc
extern	ft_strlen
extern	ft_strcpy

global	ft_strdup

; char *ft_strdup(const char *s)
ft_strdup:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	mov	qword [rbp - 16], rdi
; 	const size_t s_size = ft_strlen(s);
	mov	rdi, qword [rbp - 16]
	call	ft_strlen
	mov	qword [rbp - 24], rax
; 	char *result = (char *)malloc(sizeof(char) * (s_size + 1));
	mov	rdi, qword [rbp - 24]
	add	rdi, 1
	shl	rdi, 0
	call	malloc
	mov	qword [rbp - 32], rax
; 	if (result == NULL)
	cmp	qword [rbp - 32], 0
	jne	.copy_string
; 		return NULL;
	mov	qword [rbp - 8], 0
	jmp	.return
; 	ft_strcpy(result, s);
.copy_string:
	mov	rdi, qword [rbp - 32]
	mov	rsi, qword [rbp - 16]
	call	ft_strcpy
; 	return result;
	mov	rax, qword [rbp - 32]
	mov	qword [rbp - 8], rax
; }
.return:
	mov	rax, qword [rbp - 8]
	add	rsp, 32
	pop	rbp
	ret
