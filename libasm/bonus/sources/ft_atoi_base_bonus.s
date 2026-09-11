bits	64

extern	ft_strlen

global	ft_atoi_base

; static bool ft_iswhtspc(const char c)
ft_iswhtspc:
; {
	push	rbp
	mov	rbp, rsp
	mov	al, dil
	mov	byte [rbp - 1], al
; 	return c == ' ' || (c >= '\t' && c <= '\r');
	movsx	ecx, byte [rbp - 1]
	mov	al, 1
	cmp	ecx, 32
	mov	byte [rbp - 2], al
	je	.return_true
	movsx	ecx, byte [rbp - 1]
	xor	eax, eax
	cmp	ecx, 9
	mov	byte [rbp - 3], al
	jl	.return_false
	movsx	eax, byte [rbp - 1]
	cmp	eax, 13
	setle	al
	mov	byte [rbp - 3], al
.return_false:
	mov	al, byte [rbp - 3]
	mov	byte [rbp - 2], al
.return_true:
	mov	al, byte [rbp - 2]
	and	al, 1
	movzx	eax, al
; }
	pop	rbp
	ret

; static char *ft_strchr(const char *s, int c)
ft_strchr:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	mov	qword [rbp - 16], rdi
	mov	dword [rbp - 20], esi
; 	if ((unsigned char)*s == (unsigned char)c)
	mov	rax, qword [rbp - 16]
	movzx	eax, byte [rax]
	mov	ecx, dword [rbp - 20]
	movzx	ecx, cl
	cmp	eax, ecx
	jne	.check_null_byte
; 		return (char *)s;
	mov	rax, qword [rbp - 16]
	mov	qword [rbp - 8], rax
	jmp	.return
; 	if (*s == '\0')
.check_null_byte:
	mov	rax, qword [rbp - 16]
	movsx	eax, byte [rax]
	cmp	eax, 0
	jne	.recursion
; 		return NULL;
	mov	qword [rbp - 8], 0
	jmp	.return
; 	return ft_strchr(s + 1, c);
.recursion:
	mov	rdi, qword [rbp - 16]
	add	rdi, 1
	mov	esi, dword [rbp - 20]
	call	ft_strchr
	mov	qword [rbp - 8], rax
; }
.return:
	mov	rax, qword [rbp - 8]
	add	rsp, 32
	pop	rbp
	ret

; static bool check_base(const char *const base)
check_base:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	mov	qword [rbp - 16], rdi
; 	if (ft_strlen(base) <= 1)
	mov	rdi, qword [rbp - 16]
	call	ft_strlen
	cmp	rax, 1
	ja	.read_base
; 		return false;
	mov	byte [rbp - 1], 0
	jmp	.return
; 	for (const char *bptr = base; *bptr != '\0'; bptr++)
.read_base:
	mov	rax, qword [rbp - 16]
	mov	qword [rbp - 24], rax
.read_base_loop:
	mov	rax, qword [rbp - 24]
	movsx	eax, byte [rax]
	cmp	eax, 0
	je	.return_true
; 	{
; 		if (*bptr == '+' || *bptr == '-' || ft_iswhtspc(*bptr) == true)
	mov	rax, qword [rbp - 24]
	movsx	eax, byte [rax]
	cmp	eax, 43
	je	.return_false
	mov	rax, qword [rbp - 24]
	movsx	eax, byte [rax]
	cmp	eax, 45
	je	.return_false
	mov	rax, qword [rbp - 24]
	movsx	edi, byte [rax]
	call	ft_iswhtspc
	and	al, 1
	movzx	eax, al
	cmp	eax, 1
	jne	.check_duplicates
; 			return false;
.return_false:
	mov	byte [rbp - 1], 0
	jmp	.return
; 		for (const char *auxptr = base; *auxptr != '\0'; auxptr++)
.check_duplicates:
	mov	rax, qword [rbp - 16]
	mov	qword [rbp - 32], rax
.check_duplicates_loop:
	mov	rax, qword [rbp - 32]
	movsx	eax, byte [rax]
	cmp	eax, 0
	je	.continue_reading_base_loop_jmp
; 			if (bptr != auxptr && *bptr == *auxptr)
	mov	rax, qword [rbp - 24]
	cmp	rax, qword [rbp - 32]
	je	.check_duplicates_done_jmp
	mov	rax, qword [rbp - 24]
	movsx	eax, byte [rax]
	mov	rcx, qword [rbp - 32]
	movsx	ecx, byte [rcx]
	cmp	eax, ecx
	jne	.check_duplicates_done_jmp
; 				return false;
	mov	byte [rbp - 1], 0
	jmp	.return
.check_duplicates_done_jmp:
	jmp	.check_duplicates_done
.check_duplicates_done:
	mov	rax, qword [rbp - 32]
	add	rax, 1
	mov	qword [rbp - 32], rax
	jmp	.check_duplicates_loop
; 	}
.continue_reading_base_loop_jmp:
	jmp	.continue_reading_base_loop
.continue_reading_base_loop:
	mov	rax, qword [rbp - 24]
	add	rax, 1
	mov	qword [rbp - 24], rax
	jmp	.read_base_loop
; 	return true;
.return_true:
	mov	byte [rbp - 1], 1
; }
.return:
	mov	al, byte [rbp - 1]
	and	al, 1
	movzx	eax, al
	add	rsp, 32
	pop	rbp
	ret

; int ft_atoi_base(char *str, char *base)
ft_atoi_base:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 64
	mov	qword [rbp - 16], rdi
	mov	qword [rbp - 24], rsi
; 	if (check_base(base) == false)
	mov	rdi, qword [rbp - 24]
	call	check_base
	and	al, 1
	movzx	eax, al
	cmp	eax, 0
	jne	.start_convertion
; 		return 0;
	mov	dword [rbp - 4], 0
	jmp	.return
; 	int result = 0, sign = 1;
.start_convertion:
	mov	dword [rbp - 28], 0
	mov	dword [rbp - 32], 1
; 	const char *sptr = str;
	mov	rax, qword [rbp - 16]
	mov	qword [rbp - 40], rax
; 	for (; *sptr != '\0' && ft_iswhtspc(*sptr) == true; sptr++)
.skip_whitespaces:
	mov	rax, qword [rbp - 40]
	movsx	ecx, byte [rax]
	xor	eax, eax
	cmp	ecx, 0
	mov	byte [rbp - 57], al
	je	.check_loop_condiction
	mov	rax, qword [rbp - 40]
	movsx	edi, byte [rax]
	call	ft_iswhtspc
	and	al, 1
	movzx	eax, al
	cmp	eax, 1
	sete	al
	mov	byte [rbp - 57], al
.check_loop_condiction:
	mov	al, byte [rbp - 57]
	test	al, 1
	jne	.continue_skipping_whitespaces_jmp
	jmp	.check_sign
.continue_skipping_whitespaces_jmp:
	jmp	.continue_skipping_whitespaces
.continue_skipping_whitespaces:
	mov	rax, qword [rbp - 40]
	add	rax, 1
	mov	qword [rbp - 40], rax
	jmp	.skip_whitespaces
; 		;
; 	if (*sptr == '+' || *sptr == '-')
.check_sign:
	mov	rax, qword [rbp - 40]
	movsx	eax, byte [rax]
	cmp	eax, 43
	je	.check_minus_sign
	mov	rax, qword [rbp - 40]
	movsx	eax, byte [rax]
	cmp	eax, 45
	jne	.read_string
; 		if (*sptr++ == '-')
.check_minus_sign:
	mov	rax, qword [rbp - 40]
	mov	rcx, rax
	add	rcx, 1
	mov	qword [rbp - 40], rcx
	movsx	eax, byte [rax]
	cmp	eax, 45
	jne	.read_string_jmp
; 			sign = -1;
	mov	dword [rbp - 32], -1
.read_string_jmp:
	jmp	.read_string
; 	const size_t base_size = ft_strlen(base);
.read_string:
	mov	rdi, qword [rbp - 24]
	call	ft_strlen
	mov	qword [rbp - 48], rax
; 	for (; *sptr != '\0'; sptr++)
.read_string_loop:
	mov	rax, qword [rbp - 40]
	movsx	eax, byte [rax]
	cmp	eax, 0
	je	.return_result
; 	{
; 		char *addr = ft_strchr(base, *sptr);
	mov	rdi, qword [rbp - 24]
	mov	rax, qword [rbp - 40]
	movsx	esi, byte [rax]
	call	ft_strchr
	mov	qword [rbp - 56], rax
; 		if (addr == NULL)
	cmp	qword [rbp - 56], 0
	jne	.update_result
; 			break;
	jmp	.return_result
; 		result = result * (int)base_size + (int)(addr - base);
.update_result:
	mov	eax, dword [rbp - 28]
	mov	rcx, qword [rbp - 48]
	imul	eax, ecx
	mov	rcx, qword [rbp - 56]
	mov	rdx, qword [rbp - 24]
	sub	rcx, rdx
	add	eax, ecx
	mov	dword [rbp - 28], eax
	mov	rax, qword [rbp - 40]
	add	rax, 1
	mov	qword [rbp - 40], rax
	jmp	.read_string_loop
; 	}
; 	return result * sign;
.return_result:
	mov	eax, dword [rbp - 28]
	imul	eax, dword [rbp - 32]
	mov	dword [rbp - 4], eax
; }
.return:
	mov	eax, dword [rbp - 4]
	add	rsp, 64
	pop	rbp
	ret
