	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	print_int
	.type	print_int, @function
print_int:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	print_int, .-print_int
	.section	.rodata
.LC1:
	.string	"\n--- LIST ---"
.LC2:
	.string	"pop: %d\n"
	.text
	.globl	test_dynamic_list
	.type	test_dynamic_list, @function
test_dynamic_list:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$4, %edi
	call	dlist_new@PLT
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	dlist_print@PLT
	movl	$0, -36(%rbp)
	jmp	.L3
.L4:
	leaq	-36(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	dlist_append@PLT
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
.L3:
	movl	-36(%rbp), %eax
	cmpl	$29, %eax
	jle	.L4
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	dlist_print@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	dlist_pop@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	dlist_print@PLT
	movl	$0, -32(%rbp)
	jmp	.L5
.L6:
	movq	-24(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	dlist_remove@PLT
	addl	$1, -32(%rbp)
.L5:
	cmpl	$24, -32(%rbp)
	jle	.L6
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	dlist_print@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	dlist_reverse@PLT
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	dlist_print@PLT
	movq	-24(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	dlist_get@PLT
	movl	(%rax), %eax
	movl	%eax, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	dlist_kill@PLT
	movl	$10, %edi
	call	putchar@PLT
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	test_dynamic_list, .-test_dynamic_list
	.section	.rodata
.LC3:
	.string	"\n--- LINKED LIST ---"
.LC4:
	.string	"Empty List"
.LC5:
	.string	"Inserting at End"
.LC6:
	.string	"Inserting at Start"
.LC7:
	.string	"Poppinng Value"
.LC8:
	.string	"%d\n"
.LC9:
	.string	"Reversed"
.LC10:
	.string	"Freeing memory"
	.text
	.globl	test_linked_list
	.type	test_linked_list, @function
test_linked_list:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$4, %edi
	call	llist_new@PLT
	movq	%rax, -24(%rbp)
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	llist_print@PLT
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -28(%rbp)
	jmp	.L9
.L10:
	leaq	-28(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	llist_insert_end@PLT
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
.L9:
	movl	-28(%rbp), %eax
	cmpl	$14, %eax
	jle	.L10
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	llist_print@PLT
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$16, -28(%rbp)
	jmp	.L11
.L12:
	leaq	-28(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	llist_insert_start@PLT
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
.L11:
	movl	-28(%rbp), %eax
	cmpl	$29, %eax
	jle	.L12
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	llist_print@PLT
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	llist_pop@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	llist_print@PLT
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	llist_reverse@PLT
	movq	-24(%rbp), %rax
	leaq	print_int(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	llist_print@PLT
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	llist_kill@PLT
	movl	$10, %edi
	call	putchar@PLT
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	test_linked_list, .-test_linked_list
	.section	.rodata
.LC11:
	.string	"\n--- Binary Tree ---"
.LC12:
	.string	"True"
.LC13:
	.string	"False"
.LC14:
	.string	"Is letter: %c in TREE ?: %s\n"
	.text
	.globl	test_binary_tree
	.type	test_binary_tree, @function
test_binary_tree:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	call	btree_new@PLT
	movq	%rax, -80(%rbp)
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movb	$97, 16(%rax)
	movq	-72(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-72(%rbp), %rax
	movq	$0, (%rax)
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movb	$98, 16(%rax)
	movq	-64(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-64(%rbp), %rax
	movq	$0, (%rax)
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movb	$99, 16(%rax)
	movq	-56(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-56(%rbp), %rax
	movq	$0, (%rax)
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movb	$100, 16(%rax)
	movq	-48(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-48(%rbp), %rax
	movq	$0, (%rax)
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movb	$101, 16(%rax)
	movq	-40(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-40(%rbp), %rax
	movq	$0, (%rax)
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movb	$102, 16(%rax)
	movq	-32(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-32(%rbp), %rax
	movq	$0, (%rax)
	movq	-72(%rbp), %rax
	movq	-64(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-72(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-64(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-64(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-56(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-80(%rbp), %rax
	movq	-72(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	btree_depth_first@PLT
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	print_binary_node@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	dlist_print@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	dlist_kill@PLT
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	btree_depth_first_recursive@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	print_binary_node@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	llist_print@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	llist_kill@PLT
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	btree_bredth_first@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	print_binary_node@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	dlist_print@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	dlist_kill@PLT
	movb	$97, -83(%rbp)
	movsbl	-83(%rbp), %edx
	movq	-80(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	btree_includes@PLT
	movb	%al, -82(%rbp)
	cmpb	$0, -82(%rbp)
	je	.L15
	leaq	.LC12(%rip), %rax
	jmp	.L16
.L15:
	leaq	.LC13(%rip), %rax
.L16:
	movsbl	-83(%rbp), %ecx
	movq	%rax, %rdx
	movl	%ecx, %esi
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movsbl	-83(%rbp), %edx
	movq	-80(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	btree_include_recursive@PLT
	movb	%al, -81(%rbp)
	cmpb	$0, -82(%rbp)
	je	.L17
	leaq	.LC12(%rip), %rax
	jmp	.L18
.L17:
	leaq	.LC13(%rip), %rax
.L18:
	movsbl	-83(%rbp), %ecx
	movq	%rax, %rdx
	movl	%ecx, %esi
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	btree_kill@PLT
	movl	$10, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	test_binary_tree, .-test_binary_tree
	.globl	main
	.type	main, @function
main:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, %eax
	call	test_dynamic_list
	movl	$0, %eax
	call	test_linked_list
	movl	$0, %eax
	call	test_binary_tree
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits
