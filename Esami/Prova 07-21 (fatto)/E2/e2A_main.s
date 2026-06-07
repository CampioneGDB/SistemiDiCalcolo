	.file	"e2A_main.c"
	.text
	.globl	score
	.bss
	.align 4
	.type	score, @object
	.size	score, 4
score:
	.zero	4
	.globl	trials
	.align 4
	.type	trials, @object
	.size	trials, 4
trials:
	.zero	4
	.section	.rodata
.LC0:
	.string	"Test %d: \""
.LC1:
	.string	"%d | %s"
.LC2:
	.string	"%d | "
.LC3:
	.string	"\" [corretto: \"%d | %s\"]\n"
	.text
	.type	test, @function
test:
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
	movl	%edx, -48(%rbp)
	movq	%rcx, -56(%rbp)
	movb	%al, -44(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	trials(%rip), %eax
	addl	$1, %eax
	movl	%eax, trials(%rip)
	movq	$0, -16(%rbp)
	movsbl	-44(%rbp), %ecx
	leaq	-16(%rbp), %rdx
	movq	-40(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	wordWithMaxCount@PLT
	movl	%eax, -24(%rbp)
	movl	trials(%rip), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpl	$0, -24(%rbp)
	jle	.L2
	movq	-16(%rbp), %rdx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L2:
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L3:
	movq	-56(%rbp), %rdx
	movl	-48(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-24(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jne	.L4
	cmpl	$0, -48(%rbp)
	jne	.L4
	movq	-16(%rbp), %rax
	testq	%rax, %rax
	je	.L5
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L6
.L5:
	movl	$1, %eax
	jmp	.L8
.L6:
	movl	$0, %eax
	jmp	.L8
.L4:
	movq	-16(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
.L8:
	movl	%eax, -20(%rbp)
	movq	-16(%rbp), %rax
	testq	%rax, %rax
	je	.L9
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
.L9:
	movl	score(%rip), %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, score(%rip)
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	test, .-test
	.section	.rodata
.LC4:
	.string	""
.LC5:
	.string	"thought"
	.align 8
.LC6:
	.ascii	"Hey brother, happy returns,"
	.string	" it's been a while now I bet you thought that I was dead. But I'm still here, nothing has changed. Hey brother, I'd love to tell you I've been busy, but that would be a lie. Cos the truth is the years just past like trains, I wave but they don't slow down."
.LC7:
	.string	"happy"
.LC8:
	.string	"raccoonnooks"
	.align 8
.LC9:
	.string	"Some people raise raccoons for their pelts. A raccoon's home is called a nook. The person who cleans and tidies up the raccoonnooks is called the raccoonnookkeeper. Real word!"
.LC10:
	.string	"Risultato: %d/%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	movl	$0, %edx
	movl	$120, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	test
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$116, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	test
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	movl	$1, %edx
	movl	$97, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	test
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	movl	$4, %edx
	movl	$111, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	test
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	movl	$0, %edx
	movl	$106, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	test
	movl	trials(%rip), %edx
	movl	score(%rip), %eax
	movl	%eax, %esi
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
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
