	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"CSD_City=Dublin"
.LC1:
	.string	"CSD_Name=Cork"
.LC2:
	.string	"fork"
.LC3:
	.string	"./sample"
.LC4:
	.string	"arg1"
.LC5:
	.string	"arg2"
.LC6:
	.string	"arg3"
.LC7:
	.string	"execle"
.LC8:
	.string	"parent continues..."
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movl	%edi, -100(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$.LC0, -80(%rbp)
	movq	$.LC1, -72(%rbp)
	movq	$0, -64(%rbp)
	call	fork
	movl	%eax, -84(%rbp)
	cmpl	$0, -84(%rbp)
	jns	.L2
	movl	$.LC2, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L2:
	movq	$.LC3, -48(%rbp)
	movq	$.LC4, -40(%rbp)
	movq	$.LC5, -32(%rbp)
	movq	$.LC6, -24(%rbp)
	movq	$0, -16(%rbp)
	cmpl	$0, -84(%rbp)
	jne	.L3
	leaq	-80(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	call	execvpe
	testl	%eax, %eax
	jns	.L3
	movl	$.LC7, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	movl	$0, %eax
	movq	%rax, %rdi
	call	wait
	movl	$.LC8, %edi
	call	puts
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
