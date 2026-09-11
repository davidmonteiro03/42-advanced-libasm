bits	64

extern	free

global	ft_list_remove_if

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
ft_list_remove_if:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 64
	mov	qword [rbp - 8],rdi
	mov	qword [rbp - 16], rsi
	mov	qword [rbp - 24], rdx
	mov	qword [rbp - 32], rcx
; 	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
	cmp	qword [rbp - 8], 0
	je	.return_without_removing
	mov	rax, qword [rbp - 8]
	cmp	qword [rax], 0
	je	.return_without_removing
	cmp	qword [rbp - 24], 0
	jne	.read_list
; 		return;
.return_without_removing:
	jmp	.return
; 	for (t_list *prev = NULL, *curr = *begin_list, *next = NULL; curr != NULL; curr = next)
.read_list:
	mov	qword [rbp - 40], 0
	mov	rax, qword [rbp - 8]
	mov	rax, qword [rax]
	mov	qword [rbp - 48], rax
	mov	qword [rbp - 56], 0
.read_list_loop:
	cmp	qword [rbp - 48], 0
	je	.return
; 	{
; 		next = curr->next;
	mov	rax, qword [rbp - 48]
	mov	rax, qword [rax + 8]
	mov	qword [rbp - 56], rax
; 		if ((*cmp)(curr->data, data_ref) == 0)
	mov	rcx, qword [rbp - 24]
	mov	rax, qword [rbp - 48]
	mov	rdi, qword [rax]
	mov	rsi, qword [rbp - 16]
	mov	al, 0
	call	rcx
	cmp	eax, 0
	jne	.update_aux_prev_node_pointer
; 		{
; 			if (prev == NULL)
	cmp	qword [rbp - 40], 0
	jne	.update_list
; 				*begin_list = curr->next;
	mov	rax, qword [rbp - 48]
	mov	rcx, qword [rax + 8]
	mov	rax, qword [rbp - 8]
	mov	qword [rax], rcx
	jmp	.check_free_fct_pointer
; 			else
; 				prev->next = curr->next;
.update_list:
	mov	rax, qword [rbp - 48]
	mov	rcx, qword [rax + 8]
	mov	rax, qword [rbp - 40]
	mov	qword [rax + 8], rcx
; 			if (free_fct != NULL)
.check_free_fct_pointer:
	cmp	qword [rbp - 32], 0
	je	.free_node
; 				(*free_fct)(curr->data);
	mov	rax, qword [rbp - 32]
	mov	rcx, qword [rbp - 48]
	mov	rdi, qword [rcx]
	call	rax
; 			free(curr);
.free_node:
	mov	rdi, qword [rbp - 48]
	call	free
; 		}
	jmp	.continue_reading_list_jmp
; 		else
; 			prev = curr;
.update_aux_prev_node_pointer:
	mov	rax, qword [rbp - 48]
	mov	qword [rbp - 40], rax
; 	}
.continue_reading_list_jmp:
	jmp	.continue_reading_list
.continue_reading_list:
	mov	rax, qword [rbp - 56]
	mov	qword [rbp - 48], rax
	jmp	.read_list_loop
; }
.return:
	add	rsp, 64
	pop	rbp
	ret
