	.text
	.file	"<stdin>"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %entry
	subl	$12, %esp
.Ltmp0:
	.cfi_def_cfa_offset 16
	movl	$0, 4(%esp)
	movl	$1, (%esp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB0_2
# BB#1:                                 # %then
	movl	(%esp), %eax
	addl	$1, %eax
	adcl	$0, 4(%esp)
	movl	%eax, (%esp)
	jmp	.LBB0_3
.LBB0_2:                                # %else
	movl	(%esp), %eax
	movl	4(%esp), %ecx
	addl	%eax, %eax
	adcl	%ecx, %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
.LBB0_3:                                # %ifcont
	xorl	%eax, %eax
	addl	$12, %esp
	retl
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
