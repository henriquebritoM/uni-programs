	.file	"rust_asm.5ee0332f929fb394-cgu.0"
	.section	.text._ZN3std2rt10lang_start17h2d676455a1901300E,"ax",@progbits
	.hidden	_ZN3std2rt10lang_start17h2d676455a1901300E
	.globl	_ZN3std2rt10lang_start17h2d676455a1901300E
	.p2align	4
	.type	_ZN3std2rt10lang_start17h2d676455a1901300E,@function
_ZN3std2rt10lang_start17h2d676455a1901300E:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%ecx, %r8d
	movq	%rdx, %rcx
	movq	%rsi, %rdx
	movq	%rdi, (%rsp)
	leaq	.Lanon.defa12abf81eee0281dc4a94bb6f4505.0(%rip), %rsi
	movq	%rsp, %rdi
	callq	*_ZN3std2rt19lang_start_internal17hce2b8b328837374bE@GOTPCREL(%rip)
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	_ZN3std2rt10lang_start17h2d676455a1901300E, .Lfunc_end0-_ZN3std2rt10lang_start17h2d676455a1901300E
	.cfi_endproc

	.section	".text._ZN3std2rt10lang_start28_$u7b$$u7b$closure$u7d$$u7d$17h1257355d9d9bc1c2E","ax",@progbits
	.p2align	4
	.type	_ZN3std2rt10lang_start28_$u7b$$u7b$closure$u7d$$u7d$17h1257355d9d9bc1c2E,@function
_ZN3std2rt10lang_start28_$u7b$$u7b$closure$u7d$$u7d$17h1257355d9d9bc1c2E:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	(%rdi), %rdi
	callq	_ZN3std3sys9backtrace28__rust_begin_short_backtrace17hb18aa0e89475ef46E
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	_ZN3std2rt10lang_start28_$u7b$$u7b$closure$u7d$$u7d$17h1257355d9d9bc1c2E, .Lfunc_end1-_ZN3std2rt10lang_start28_$u7b$$u7b$closure$u7d$$u7d$17h1257355d9d9bc1c2E
	.cfi_endproc

	.section	.text._ZN3std3sys9backtrace28__rust_begin_short_backtrace17hb18aa0e89475ef46E,"ax",@progbits
	.p2align	4
	.type	_ZN3std3sys9backtrace28__rust_begin_short_backtrace17hb18aa0e89475ef46E,@function
_ZN3std3sys9backtrace28__rust_begin_short_backtrace17hb18aa0e89475ef46E:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	*%rdi
	#APP
	#NO_APP
	popq	%rax
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	_ZN3std3sys9backtrace28__rust_begin_short_backtrace17hb18aa0e89475ef46E, .Lfunc_end2-_ZN3std3sys9backtrace28__rust_begin_short_backtrace17hb18aa0e89475ef46E
	.cfi_endproc

	.section	".text._ZN4core3ops8function6FnOnce40call_once$u7b$$u7b$vtable.shim$u7d$$u7d$17h6ca2afa2b225a249E","ax",@progbits
	.p2align	4
	.type	_ZN4core3ops8function6FnOnce40call_once$u7b$$u7b$vtable.shim$u7d$$u7d$17h6ca2afa2b225a249E,@function
_ZN4core3ops8function6FnOnce40call_once$u7b$$u7b$vtable.shim$u7d$$u7d$17h6ca2afa2b225a249E:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	(%rdi), %rdi
	callq	_ZN3std3sys9backtrace28__rust_begin_short_backtrace17hb18aa0e89475ef46E
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end3:
	.size	_ZN4core3ops8function6FnOnce40call_once$u7b$$u7b$vtable.shim$u7d$$u7d$17h6ca2afa2b225a249E, .Lfunc_end3-_ZN4core3ops8function6FnOnce40call_once$u7b$$u7b$vtable.shim$u7d$$u7d$17h6ca2afa2b225a249E
	.cfi_endproc

	.section	.text._ZN8rust_asm4main17h14cd0fac9d8be4d2E,"ax",@progbits
	.hidden	_ZN8rust_asm4main17h14cd0fac9d8be4d2E
	.globl	_ZN8rust_asm4main17h14cd0fac9d8be4d2E
	.p2align	4
	.type	_ZN8rust_asm4main17h14cd0fac9d8be4d2E,@function
_ZN8rust_asm4main17h14cd0fac9d8be4d2E:
	.cfi_startproc
	subq	$56, %rsp
	.cfi_def_cfa_offset 64
	leaq	.Lanon.defa12abf81eee0281dc4a94bb6f4505.2(%rip), %rax
	movq	%rax, 8(%rsp)
	movq	$1, 16(%rsp)
	movq	$8, 24(%rsp)
	xorps	%xmm0, %xmm0
	movups	%xmm0, 32(%rsp)
	leaq	8(%rsp), %rdi
	callq	*_ZN3std2io5stdio6_print17h02b5be036b2109f4E@GOTPCREL(%rip)
	addq	$56, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end4:
	.size	_ZN8rust_asm4main17h14cd0fac9d8be4d2E, .Lfunc_end4-_ZN8rust_asm4main17h14cd0fac9d8be4d2E
	.cfi_endproc

	.section	.text.main,"ax",@progbits
	.globl	main
	.p2align	4
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	%rsi, %rcx
	movslq	%edi, %rdx
	leaq	_ZN8rust_asm4main17h14cd0fac9d8be4d2E(%rip), %rax
	movq	%rax, (%rsp)
	leaq	.Lanon.defa12abf81eee0281dc4a94bb6f4505.0(%rip), %rsi
	movq	%rsp, %rdi
	xorl	%r8d, %r8d
	callq	*_ZN3std2rt19lang_start_internal17hce2b8b328837374bE@GOTPCREL(%rip)
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end5:
	.size	main, .Lfunc_end5-main
	.cfi_endproc

	.type	.Lanon.defa12abf81eee0281dc4a94bb6f4505.0,@object
	.section	.data.rel.ro..Lanon.defa12abf81eee0281dc4a94bb6f4505.0,"aw",@progbits
	.p2align	3, 0x0
.Lanon.defa12abf81eee0281dc4a94bb6f4505.0:
	.asciz	"\000\000\000\000\000\000\000\000\b\000\000\000\000\000\000\000\b\000\000\000\000\000\000"
	.quad	_ZN4core3ops8function6FnOnce40call_once$u7b$$u7b$vtable.shim$u7d$$u7d$17h6ca2afa2b225a249E
	.quad	_ZN3std2rt10lang_start28_$u7b$$u7b$closure$u7d$$u7d$17h1257355d9d9bc1c2E
	.quad	_ZN3std2rt10lang_start28_$u7b$$u7b$closure$u7d$$u7d$17h1257355d9d9bc1c2E
	.size	.Lanon.defa12abf81eee0281dc4a94bb6f4505.0, 48

	.type	.Lanon.defa12abf81eee0281dc4a94bb6f4505.1,@object
	.section	.rodata..Lanon.defa12abf81eee0281dc4a94bb6f4505.1,"a",@progbits
.Lanon.defa12abf81eee0281dc4a94bb6f4505.1:
	.ascii	"Hello, world!\n"
	.size	.Lanon.defa12abf81eee0281dc4a94bb6f4505.1, 14

	.type	.Lanon.defa12abf81eee0281dc4a94bb6f4505.2,@object
	.section	.data.rel.ro..Lanon.defa12abf81eee0281dc4a94bb6f4505.2,"aw",@progbits
	.p2align	3, 0x0
.Lanon.defa12abf81eee0281dc4a94bb6f4505.2:
	.quad	.Lanon.defa12abf81eee0281dc4a94bb6f4505.1
	.asciz	"\016\000\000\000\000\000\000"
	.size	.Lanon.defa12abf81eee0281dc4a94bb6f4505.2, 16

	.ident	"rustc version 1.91.0 (f8297e351 2025-10-28)"
	.section	".note.GNU-stack","",@progbits
