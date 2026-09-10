bits	64

global	ft_calloc

extern	malloc

; void *ft_calloc(size_t nmemb, size_t size)
ft_calloc:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 48
	mov	qword [rbp - 16], rdi
	mov	qword [rbp - 24], rsi
; 	if (size != 0 && nmemb > LLONG_MAX / size)
	cmp	qword [rbp - 24], 0
	je	.alloc_buf
	mov	rax, qword [rbp - 16]
	mov	qword [rbp - 48], rax
	mov	rax, 9223372036854775807
	xor	ecx, ecx
	mov	edx, ecx
	div	qword [rbp - 24]
	mov	rcx, rax
	mov	rax, qword [rbp - 48]
	cmp	rax, rcx
	jbe	.alloc_buf
; 		return NULL;
	mov	qword [rbp - 8], 0
	jmp	.return
; 	void *buf = malloc(nmemb * size);
.alloc_buf:
	mov	rdi, qword [rbp - 16]
	imul	rdi, qword [rbp - 24]
	call	malloc
	mov	qword [rbp - 32], rax
; 	if (buf == NULL)
	cmp	qword [rbp - 32], 0
	jne	.fill_buf
; 		return NULL;
	mov	qword [rbp - 8], 0
	jmp	.return
; 	for (size_t i = 0; i < nmemb * size; i++)
.fill_buf:
	mov	qword [rbp - 40], 0
.fill_buf_loop:
	mov	rax, qword [rbp - 40]
	mov	rcx, qword [rbp - 16]
	imul	rcx, qword [rbp - 24]
	cmp	rax, rcx
	jae	.return_buf
; 		*((unsigned char *)(buf + i)) = '\0';
	mov	rax, qword [rbp - 32]
	mov	rcx, qword [rbp - 40]
	mov	byte [rax + rcx * 1], 0
	mov	rax, qword [rbp - 40]
	add	rax, 1
	mov	qword [rbp - 40], rax
	jmp	.fill_buf_loop
; 	return buf;
.return_buf:
	mov	rax, qword [rbp - 32]
	mov	qword [rbp - 8], rax
; }
.return:
	mov	rax, qword [rbp - 8]
	add	rsp, 48
	pop	rbp
	ret
