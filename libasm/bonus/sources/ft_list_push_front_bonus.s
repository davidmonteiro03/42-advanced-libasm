bits	64

extern	malloc

global	ft_list_push_front

; void ft_list_push_front(t_list **begin_list, void *data)
ft_list_push_front:
; {
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	mov	qword [rbp - 8], rdi
	mov	qword [rbp - 16], rsi
; 	if (begin_list == NULL)
	cmp	qword [rbp - 8], 0
	jne	.alloc_new_node
; 		return;
	jmp	.return
; 	t_list *new_node = (t_list *)malloc(sizeof(t_list));
.alloc_new_node:
	mov	edi, 16
	call	malloc
	mov	qword [rbp - 24], rax
; 	if (new_node == NULL)
	cmp	qword [rbp - 24], 0
	jne	.copy_data
; 		return;
	jmp	.return
; 	new_node->data = data;
.copy_data:
	mov	rcx, qword [rbp - 16]
	mov	rax, qword [rbp - 24]
	mov	qword [rax], rcx
; 	new_node->next = *begin_list;
	mov	rax, qword [rbp - 8]
	mov	rcx, qword [rax]
	mov	rax, qword [rbp - 24]
	mov	qword [rax + 8], rcx
; 	*begin_list = new_node;
	mov	rcx, qword [rbp - 24]
	mov	rax, qword [rbp - 8]
	mov	qword [rax], rcx
; }
.return:
	add	rsp, 32
	pop	rbp
	ret
