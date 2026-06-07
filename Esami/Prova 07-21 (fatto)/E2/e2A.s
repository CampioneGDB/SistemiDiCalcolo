	.file	"e2A.c"
	.text
	.section	.rodata
.LC0:
	.string	" "
	.text
	.globl	wordWithMaxCount
	.type	wordWithMaxCount, @function
wordWithMaxCount:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, %eax
	movq	%rdx, -56(%rbp)
	movb	%al, -44(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strdup@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -16(%rbp)
	movl	$64, %esi
	movl	$1, %edi
	call	calloc@PLT
	movq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$0, -32(%rbp)
	jmp	.L2
.L7:
	movl	$0, -28(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -20(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L3
.L5:
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L4
	addl	$1, -28(%rbp)
.L4:
	addl	$1, -24(%rbp)
.L3:
	movl	-24(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L5
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jle	.L6
	movl	-28(%rbp), %eax
	movl	%eax, -32(%rbp)
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
.L6:
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -16(%rbp)
.L2:
	cmpq	$0, -16(%rbp)
	jne	.L7
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	-32(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	wordWithMaxCount, .-wordWithMaxCount
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
