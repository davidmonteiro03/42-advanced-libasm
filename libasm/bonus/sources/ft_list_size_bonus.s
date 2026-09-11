bits	64

global	ft_list_size

; unsigned int ft_list_size(t_list *begin_list)
ft_list_size:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 16
	mov	qword [rbp - 16], rdi
; 	if (begin_list == NULL)
	cmp	qword [rbp - 16], 0
	jne	.recursion
; 		return 0;
	mov	dword [rbp - 4], 0
	jmp	.return
; 	return 1 + ft_list_size(begin_list->next);
.recursion:
	mov	rax, qword [rbp - 16]
	mov	rdi, qword [rax + 8]
	call	ft_list_size
	add	eax, 1
	mov	dword [rbp - 4], eax
; }
.return:
	mov	eax, dword [rbp - 4]
	add	rsp, 16
	pop	rbp
	ret
