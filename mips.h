/*
   mips.h: MIPS VR4300 mini-monitor
   Copyright 1996, 2003 Eric Smith <eric@brouhaha.com>
   http://www.brouhaha.com/~eric/software/mmon/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 2 as published
   by the Free Software Foundation.  Note that permission is not granted
   to redistribute this program under the terms of any other version of the
   General Public License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#define K0BASE          0x80000000
#define K0SIZE          0x20000000
#define K1BASE          0xa0000000
#define K1SIZE          0x20000000
#define K2BASE          0xc0000000


#define KSEG0_BASE      K0BASE
#define KSEG1_BASE      K1BASE

#define jr j
#define jalr jal

/* aliases for general registers */
#define zero            $0
#define AT              $1              /* assembler temporaries */
#define v0              $2              /* value holders */
#define v1              $3
#define a0              $4              /* arguments */
#define a1              $5
#define a2              $6
#define a3              $7
#define t0              $8              /* temporaries */
#define t1              $9
#define t2              $10
#define t3              $11
#define t4              $12
#define t5              $13
#define t6              $14
#define t7              $15
#define s0              $16             /* saved registers */
#define s1              $17
#define s2              $18
#define s3              $19
#define s4              $20
#define s5              $21
#define s6              $22
#define s7              $23
#define t8              $24             /* temporaries */
#define t9              $25
#define k0              $26             /* kernel registers */
#define k1              $27
#define gp              $28             /* global pointer */
#define sp              $29             /* stack pointer */
#define s8              $30             /* saved register */
#define fp              $30             /* frame pointer (old usage) */
#define ra              $31             /* return address */

/* System Control Coprocessor (CP0) registers */
#define C0_SR           $12             /* Processor Status */
#define C0_STATUS       $12             /* Processor Status */
#define C0_CAUSE        $13             /* Exception Cause */
#define C0_EPC          $14             /* Exception PC */
#define C0_BADADDR      $8              /* Bad Address */
#define C0_BADVADDR     $8              /* Bad Virtual Address */
#define C0_PRID         $15             /* Processor Revision Indentifier */

#define C0_CTEXT        $4              /* Context */
#define C0_TLBHI        $10             /* TLB EntryHi */
#define C0_TLBLO        $2              /* TLB EntryLo */
#define C0_INX          $0              /* TLB Index */
#define C0_RAND         $1              /* TLB Random */
#define C0_TLBLO0       $2              /* TLB EntryLo0 */
#define C0_TLBLO1       $3              /* TLB EntryLo1 */
#define C0_PGMASK       $5              /* TLB PageMask */
#define C0_WIRED        $6              /* TLB Wired */
#define C0_COUNT        $9              /* Count */
#define C0_COMPARE      $11             /* Compare */
#define C0_CONFIG       $16             /* Config */
#define C0_LLADDR       $17             /* LLAddr */
#define C0_WATCHLO      $18             /* WatchpointLo */
#define C0_WATCHHI      $19             /* WatchpointHi */
#define C0_XCTEXT       $20             /* XContext */
#define C0_ECC          $26             /* ECC */
#define C0_CACHEERR     $27             /* CacheErr */
#define C0_TAGLO        $28             /* TagLo */
#define C0_TAGHI        $29             /* TagHi */
#define C0_ERREPC       $30             /* ErrorEPC */

/* Floating-Point Control registers */
#define FPA_CSR         $31             /* Control/Status register */
#define FPA_IRR         $0              /* Implementation/Revision register */



#define END(name) \
        .size name,.-name; \
        .end    name



/* Status Register */
#define SR_CUMASK       0xf0000000      /* Coprocessor usable bits */
#define SR_CU3          0x80000000      /* Coprocessor 3 usable */
#define SR_CU2          0x40000000      /* coprocessor 2 usable */
#define SR_CU1          0x20000000      /* Coprocessor 1 usable */
#define SR_CU0          0x10000000      /* Coprocessor 0 usable */

#define SR_RE           0x02000000      /* Reverse Endian in user mode */
#define SR_BEV          0x00400000      /* Bootstrap Exception Vector */
#define SR_TS           0x00200000      /* TLB shutdown */

/* R4000-specific bits */
#define SR_RP           0x08000000      /* Reduce Power */
#define SR_FR           0x04000000      /* Enable extra floating-point registers */
#define SR_SR           0x00100000      /* Soft Reset */
#define SR_CH           0x00040000      /* Cache Hit */
#define SR_CE           0x00020000      /* Cache ECC register modifies check bits */
#define SR_DE           0x00010000      /* Disable cache errors */

#define SR_KX           0x00000080      /* xtlb in kernel mode */
#define SR_SX           0x00000040      /* mips3 & xtlb in supervisor mode */
#define SR_UX           0x00000020      /* mips3 & xtlb in user mode */

#define SR_KSU_MASK     0x00000018      /* ksu mode mask */
#define SR_KSU_USER     0x00000010      /* user mode */
#define SR_KSU_SUPV     0x00000008      /* supervisor mode */
#define SR_KSU_KERN     0x00000000      /* kernel mode */

#define SR_ERL          0x00000004      /* error level */
#define SR_EXL          0x00000002      /* exception level */
#define SR_IE           0x00000001      /* interrupt enable */

#define SR_IMASK        0x0000ff00      /* Interrupt Mask */
#define SR_IMASK8       0x00000000      /* Interrupt Mask level=8 */
#define SR_IMASK7       0x00008000      /* Interrupt Mask level=7 */
#define SR_IMASK6       0x0000c000      /* Interrupt Mask level=6 */
#define SR_IMASK5       0x0000e000      /* Interrupt Mask level=5 */
#define SR_IMASK4       0x0000f000      /* Interrupt Mask level=4 */
#define SR_IMASK3       0x0000f800      /* Interrupt Mask level=3 */
#define SR_IMASK2       0x0000fc00      /* Interrupt Mask level=2 */
#define SR_IMASK1       0x0000fe00      /* Interrupt Mask level=1 */
#define SR_IMASK0       0x0000ff00      /* Interrupt Mask level=0 */

#define SR_IBIT8        0x00008000      /*  (Intr5) */
#define SR_IBIT7        0x00004000      /*  (Intr4) */
#define SR_IBIT6        0x00002000      /*  (Intr3) */
#define SR_IBIT5        0x00001000      /*  (Intr2) */
#define SR_IBIT4        0x00000800      /*  (Intr1) */
#define SR_IBIT3        0x00000400      /*  (Intr0) */
#define SR_IBIT2        0x00000200      /*  (Software Interrupt 1) */
#define SR_IBIT1        0x00000100      /*  (Software Interrupt 0) */

/* Cause Register */
#define CAUSE_BD                0x80000000      /* Branch Delay */
#define CAUSE_CEMASK            0x30000000      /* Coprocessor Error */
#define CAUSE_CESHIFT           28              /* Right justify CE  */
#define CAUSE_IPMASK            0x0000ff00      /* Interrupt Pending */
#define CAUSE_IPSHIFT           8               /* Right justify IP  */
#define CAUSE_IP8               0x00008000      /*  (Intr5) */
#define CAUSE_IP7               0x00004000      /*  (Intr4) */
#define CAUSE_IP6               0x00002000      /*  (Intr3) */
#define CAUSE_IP5               0x00001000      /*  (Intr2) */
#define CAUSE_IP4               0x00000800      /*  (Intr1) */
#define CAUSE_IP3               0x00000400      /*  (Intr0) */
#define CAUSE_SW2               0x00000200      /*  (Software Interrupt 1) */
#define CAUSE_SW1               0x00000100      /*  (Software Interrupt 0) */
#define CAUSE_EXCMASK           0x0000007c      /* Exception Code */
#define CAUSE_EXCSHIFT          2               /* Right justify EXC */

/* Exception Code */
#define EXC_INT         (0 << 2)        /* External interrupt */
#define EXC_MOD         (1 << 2)        /* TLB modification */
#define EXC_TLBL        (2 << 2)        /* TLB miss (Load or Ifetch) */
#define EXC_TLBS        (3 << 2)        /* TLB miss (Save) */
#define EXC_ADEL        (4 << 2)        /* Address error (Load or Ifetch) */
#define EXC_ADES        (5 << 2)        /* Address error (Save) */
#define EXC_IBE         (6 << 2)        /* Bus error (Ifetch) */
#define EXC_DBE         (7 << 2)        /* Bus error (data load or store) */
#define EXC_SYS         (8 << 2)        /* System call */
#define EXC_BP          (9 << 2)        /* Break point */
#define EXC_RI          (10 << 2)       /* Reserved instruction */
#define EXC_CPU         (11 << 2)       /* Coprocessor unusable */
#define EXC_OVF         (12 << 2)       /* Arithmetic overflow */
#define EXC_TRAP        (13 << 2)       /* Trap exception */
#define EXC_VCEI        (14 << 2)       /* Virtual Coherency Exception (I) */
#define EXC_FPE         (15 << 2)       /* Floating Point Exception */
#define EXC_CP2         (16 << 2)       /* Cp2 Exception */
#define EXC_WATCH       (23 << 2)       /* Watchpoint exception */
#define EXC_VCED        (31 << 2)       /* Virtual Coherency Exception (D) */


#define NTLBENTRIES     48

#define HI_HALF(x)      ((x) >> 16)
#define LO_HALF(x)      ((x) & 0xffff)


/* FPU stuff */
#define C1_CSR          $31
#define CSR_EMASK       (0x3f<<12)
#define CSR_TMASK       (0x1f<<7)
#define CSR_SMASK       (0x1f<<2)
#define C1_FRID         $0


/*
 * R4000 Config Register 
 */
#define CFG_CM          0x80000000      /* Master-Checker mode */
#define CFG_ECMASK      0x70000000      /* System Clock Ratio */
#define CFG_ECBY2       0x00000000      /* divide by 2 */
#define CFG_ECBY3       0x00000000      /* divide by 3 */
#define CFG_ECBY4       0x00000000      /* divide by 4 */
#define CFG_EPMASK      0x0f000000      /* Transmit data pattern */
#define CFG_EPD         0x00000000      /* D */
#define CFG_EPDDX       0x01000000      /* DDX */
#define CFG_EPDDXX      0x02000000      /* DDXX */
#define CFG_EPDXDX      0x03000000      /* DXDX */
#define CFG_EPDDXXX     0x04000000      /* DDXXX */
#define CFG_EPDDXXXX    0x05000000      /* DDXXXX */
#define CFG_EPDXXDXX    0x06000000      /* DXXDXX */
#define CFG_EPDDXXXXX   0x07000000      /* DDXXXXX */
#define CFG_EPDXXXDXXX  0x08000000      /* DXXXDXXX */
#define CFG_SBMASK      0x00c00000      /* Secondary cache block size */
#define CFG_SBSHIFT     22
#define CFG_SB4         0x00000000      /* 4 words */
#define CFG_SB8         0x00400000      /* 8 words */
#define CFG_SB16        0x00800000      /* 16 words */
#define CFG_SB32        0x00c00000      /* 32 words */
#define CFG_SS          0x00200000      /* Split secondary cache */
#define CFG_SW          0x00100000      /* Secondary cache port width */
#define CFG_EWMASK      0x000c0000      /* System port width */
#define CFG_EWSHIFT     18
#define CFG_EW64        0x00000000      /* 64 bit */
#define CFG_EW32        0x00010000      /* 32 bit */
#define CFG_SC          0x00020000      /* Secondary cache absent */
#define CFG_SM          0x00010000      /* Dirty Shared mode disabled */
#define CFG_BE          0x00008000      /* Big Endian */
#define CFG_EM          0x00004000      /* ECC mode enable */
#define CFG_EB          0x00002000      /* Block ordering */
#define CFG_ICMASK      0x00000e00      /* Instruction cache size */
#define CFG_ICSHIFT     9
#define CFG_DCMASK      0x000001c0      /* Data cache size */
#define CFG_DCSHIFT     6
#define CFG_IB          0x00000020      /* Instruction cache block size */
#define CFG_DB          0x00000010      /* Data cache block size */
#define CFG_CU          0x00000008      /* Update on Store Conditional */
#define CFG_K0MASK      0x00000007      /* KSEG0 coherency algorithm */

/*
 * Primary cache mode
 */
#define CFG_C_UNCACHED          2
#define CFG_C_NONCOHERENT       3
#define CFG_C_COHERENTXCL       4
#define CFG_C_COHERENTXCLW      5
#define CFG_C_COHERENTUPD       6


/* 
 * Primary Cache TagLo 
 */
#define TAG_PTAG_MASK           0xffffff00      /* Primary Tag */
#define TAG_PTAG_SHIFT          8
#define TAG_PSTATE_MASK         0x000000c0      /* Primary Cache State */
#define TAG_PSTATE_SHIFT        6
#define TAG_PARITY_MASK         0x0000000f      /* Primary Tag Parity */
#define TAG_PARITY_SHIFT        0

#define PSTATE_INVAL            0
#define PSTATE_SHARED           1
#define PSTATE_CLEAN_EXCL       2
#define PSTATE_DIRTY_EXCL       3



/*
 * R4000 CacheErr register
 */
#define CACHEERR_TYPE           0x80000000      /* reference type: 
                                                   0=Instr, 1=Data */
#define CACHEERR_LEVEL          0x40000000      /* cache level:
                                                   0=Primary, 1=Secondary */
#define CACHEERR_DATA           0x20000000      /* data field:
                                                   0=No error, 1=Error */
#define CACHEERR_TAG            0x10000000      /* tag field:
                                                   0=No error, 1=Error */
#define CACHEERR_REQ            0x08000000      /* request type:
                                                   0=Internal, 1=External */
#define CACHEERR_BUS            0x04000000      /* error on bus:
                                                   0=No, 1=Yes */
#define CACHEERR_BOTH           0x02000000      /* Data & Instruction error:
                                                   0=No, 1=Yes */
#define CACHEERR_REFILL         0x01000000      /* Error on Refill:
                                                   0=No, 1=Yes */
#define CACHEERR_SIDX_MASK      0x003ffff8      /* PADDR(21..3) */
#define CACHEERR_SIDX_SHIFT              0
#define CACHEERR_PIDX_MASK      0x00000007      /* VADDR(14..12) */
#define CACHEERR_PIDX_SHIFT             12


/*
 * R4000 Cache operations
 */
#define Index_Invalidate_I               0x0         /* 0       0 */
#define Index_Writeback_Inv_D            0x1         /* 0       1 */
#define Index_Invalidate_SI              0x2         /* 0       2 */
#define Index_Writeback_Inv_SD           0x3         /* 0       3 */
#define Index_Load_Tag_I                 0x4         /* 1       0 */
#define Index_Load_Tag_D                 0x5         /* 1       1 */
#define Index_Load_Tag_SI                0x6         /* 1       2 */
#define Index_Load_Tag_SD                0x7         /* 1       3 */
#define Index_Store_Tag_I                0x8         /* 2       0 */
#define Index_Store_Tag_D                0x9         /* 2       1 */
#define Index_Store_Tag_SI               0xA         /* 2       2 */
#define Index_Store_Tag_SD               0xB         /* 2       3 */
#define Create_Dirty_Exc_D               0xD         /* 3       1 */
#define Create_Dirty_Exc_SD              0xF         /* 3       3 */
#define Hit_Invalidate_I                 0x10        /* 4       0 */
#define Hit_Invalidate_D                 0x11        /* 4       1 */
#define Hit_Invalidate_SI                0x12        /* 4       2 */
#define Hit_Invalidate_SD                0x13        /* 4       3 */
#define Fill_I                           0x14        /* 5       0 */
#define Hit_Writeback_Inv_D              0x15        /* 5       1 */
#define Hit_Writeback_Inv_SD             0x17        /* 5       3 */
#define Hit_Writeback_I                  0x18        /* 6       0 */
#define Hit_Writeback_D                  0x19        /* 6       1 */
#define Hit_Writeback_SD                 0x1B        /* 6       3 */
#define Hit_Set_Virtual_SI               0x1E        /* 7       2 */
#define Hit_Set_Virtual_SD               0x1F        /* 7       3 */

/* Watchpoint Register */
#define WATCH_PA        0xfffffff8
#define WATCH_R         0x00000002
#define WATCH_W         0x00000001


