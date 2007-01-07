#include "mips.h"
	.text
	.globl	start
start:
	li	a0,0			# test YAMON API
	la	a1,print
	lw	t9,0xbfc00534
	jal	t9
	nop

	li	a0,0
	la	a1,prc
	li	a2,24
	lw	t9,0xbfc00504
	jal	t9
	nop

	li	t9, 0xbfc00000
	jr	t9

	
print:	.ascii  "YAMON API: PRINT"
	.byte	13,10,0
prc:	.ascii	"YAMON API: PRINT_COUNT"
	.byte   13,10,0
