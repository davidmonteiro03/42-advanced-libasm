bits	64

global	ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)())
ft_list_sort:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 48
	mov	qword [rbp - 8], rdi
	mov	qword [rbp - 16], rsi
; 	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
	cmp	qword [rbp - 8], 0
	je	.return_without_sorting
	mov	rax, qword [rbp - 8]
	cmp	qword [rax], 0
	je	.return_without_sorting
	cmp	qword [rbp - 16], 0
	jne	.sort_list
; 		return;
.return_without_sorting:
	jmp	.return
; 	for (t_list *node = *begin_list; node != NULL && node->next != NULL;)
.sort_list:
	mov	rax, qword [rbp - 8]
	mov	rax, qword [rax]
	mov	qword [rbp - 24], rax
.sort_list_loop:
	xor	eax, eax
	cmp	qword [rbp - 24], 0
	mov	byte [rbp - 33], al
	je	.check_loop_condiction
	mov	rax, qword [rbp - 24]
	cmp	qword [rax + 8], 0
	setne	al
	mov	byte [rbp - 33], al
.check_loop_condiction:
	mov	al, byte [rbp - 33]
	test	al, 1
	jne	.check_if_data_is_sorted
	jmp	.return
; 	{
; 		if ((*cmp)(node->data, node->next->data) > 0)
.check_if_data_is_sorted:
	mov	rcx, qword [rbp - 16]
	mov	rax, qword [rbp - 24]
	mov	rdi, qword [rax]
	mov	rax, qword [rbp - 24]
	mov	rax, qword [rax + 8]
	mov	rsi, qword [rax]
	mov	al, 0
	call	rcx
	cmp	eax, 0
	jle	.continue_to_next_node
; 		{
; 			void *tmp = node->data;
	mov	rax, qword [rbp - 24]
	mov	rax, qword [rax]
	mov	qword [rbp - 32], rax
; 			node->data = node->next->data;
	mov	rax, qword [rbp - 24]
	mov	rax, qword [rax + 8]
	mov	rcx, qword [rax]
	mov	rax, qword [rbp - 24]
	mov	qword [rax], rcx
; 			node->next->data = tmp;
	mov	rcx, qword [rbp - 32]
	mov	rax, qword [rbp - 24]
	mov	rax, qword [rax + 8]
	mov	qword [rax], rcx
; 			node = *begin_list;
	mov	rax, qword [rbp - 8]
	mov	rax, qword [rax]
	mov	qword [rbp - 24], rax
; 		}
	jmp	.sort_list_loop_jmp
; 		else
; 			node = node->next;
.continue_to_next_node:
	mov	rax, qword [rbp - 24]
	mov	rax, qword [rax + 8]
	mov	qword [rbp - 24], rax
.sort_list_loop_jmp:
	jmp	.sort_list_loop
; 	}
; }
.return:
	add	rsp, 48
	pop	rbp
	ret
