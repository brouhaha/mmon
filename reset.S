#include "mips.h"
	.text
	.globl	start
start:
	li	t0, 0xbfc00000
	jr	t0
