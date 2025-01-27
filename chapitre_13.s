	.file	"chapitre_13.c"
	.intel_syntax noprefix
	.text
	.globl	a
	.type	a, @function
a:
.LFB6:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r14
	push	r13
	push	r12
	push	rbx
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	mov	QWORD PTR -40[rbp], rdi
	mov	QWORD PTR -48[rbp], rsi
	mov	QWORD PTR -56[rbp], rdx
	mov	rax, QWORD PTR -40[rbp]
	mov	r13d, DWORD PTR [rax]
	mov	rax, QWORD PTR -40[rbp]
	mov	r12d, DWORD PTR [rax]
	mov	r14d, 1
	jmp	.L2
.L5:
	movsx	rax, r14d
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -40[rbp]
	add	rax, rdx
	mov	ebx, DWORD PTR [rax]
	cmp	ebx, r13d
	jge	.L3
	mov	r13d, ebx
.L3:
	cmp	ebx, r12d
	jle	.L4
	mov	r12d, ebx
.L4:
	add	r14d, 1
.L2:
	mov	eax, r14d
	cmp	eax, 1
	jbe	.L5
	mov	rax, QWORD PTR -48[rbp]
	mov	DWORD PTR [rax], r13d
	mov	rax, QWORD PTR -56[rbp]
	mov	DWORD PTR [rax], r12d
	nop
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	a, .-a
	.globl	b
	.type	b, @function
b:
.LFB7:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	mov	QWORD PTR -48[rbp], rdi
	mov	QWORD PTR -56[rbp], rsi
	mov	QWORD PTR -64[rbp], rdx
	mov	rax, QWORD PTR -48[rbp]
	mov	r14d, DWORD PTR [rax]
	mov	rax, QWORD PTR -48[rbp]
	mov	r13d, DWORD PTR [rax]
	mov	r15d, 1
	jmp	.L8
.L13:
	movsx	rax, r15d
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -48[rbp]
	add	rax, rdx
	mov	r12d, DWORD PTR [rax]
	movsx	rax, r15d
	add	rax, 1
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -48[rbp]
	add	rax, rdx
	mov	ebx, DWORD PTR [rax]
	cmp	r12d, ebx
	jge	.L9
	cmp	r12d, r14d
	jge	.L10
	mov	r14d, r12d
.L10:
	cmp	ebx, r13d
	jle	.L11
	mov	r13d, ebx
	jmp	.L11
.L9:
	cmp	ebx, r14d
	jge	.L12
	mov	r14d, ebx
.L12:
	cmp	r12d, r13d
	jle	.L11
	mov	r13d, r12d
.L11:
	add	r15d, 2
.L8:
	mov	eax, r15d
	cmp	eax, 1
	jbe	.L13
	mov	rax, QWORD PTR -56[rbp]
	mov	DWORD PTR [rax], r14d
	mov	rax, QWORD PTR -64[rbp]
	mov	DWORD PTR [rax], r13d
	nop
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	b, .-b
	.globl	compte
	.type	compte, @function
compte:
.LFB8:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -20[rbp], edi
	mov	QWORD PTR -32[rbp], rsi
	mov	DWORD PTR -4[rbp], 0
	nop
	mov	eax, DWORD PTR -4[rbp]
	cmp	eax, DWORD PTR -20[rbp]
	jge	.L20
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	mov	rax, QWORD PTR -32[rbp]
	add	rax, rdx
	mov	eax, DWORD PTR [rax]
	cmp	eax, 49
	jg	.L17
	add	DWORD PTR -8[rbp], 1
.L17:
	mov	eax, DWORD PTR -8[rbp]
	jmp	.L15
.L20:
.L15:
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	compte, .-compte
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR -12[rbp], 10
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	sal	rax, 2
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR -8[rbp], rax
	mov	rdx, QWORD PTR -8[rbp]
	mov	eax, DWORD PTR -12[rbp]
	mov	rsi, rdx
	mov	edi, eax
	call	compte
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
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
