# Makefile for mmon: MIPS VR4300 mini-monitor
# Copyright 1996, 2003 Eric Smith <eric@brouhaha.com>
# http://www.brouhaha.com/~eric/software/mmon/
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as published
# by the Free Software Foundation.  Note that permission is not granted
# to redistribute this program under the terms of any later version of the
# General Public License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

BASE=/usr/local/sde/bin
CC=$(BASE)/sde-gcc
LD=$(BASE)/sde-ld
CONV=$(BASE)/sde-conv
DUMP=$(BASE)/sde-objdump

# for real hardware
CFLAGS=-EB -G 0 -mcpu=r4k -mips3 -DR4000 -nostdinc
LDFLAGS=-n  -Ttext bfc00000 -Tdata a0000010
# Note - on our target hardware, the same DRAM is aliased between a0000000 and
#        bfc00000.  Data section starts at a0000010 to allow room for the
#        four instructions of the reset exception handler.  Data section must
#        end before a0000200, so size of data section must be <= 496 bytes

# for simulator
#CFLAGS=-EB -G 0 -mcpu=r4k -mips3 -DR4000 -nostdinc -DSIM
#LDFLAGS= -Ttext 9fc00000 -Tdata 80000000

IMA=-vp  -f sbin
SRC=-vp  -f srec

DUMPFLAGS=-d

SRECS = mmon0.sr mmon1.sr mmon2.sr mmon3.sr
PROTSRECS = mmon0.pr mmon1.pr mmon2.pr mmon3.pr

all:	mmon $(SRECS) $(PROTSRECS) mmon.dmp
.PHONY:	all

clean:
	rm -f mmon mmon.dmp *.sr *.pr *.o
.PHONY:	clean

floppy:	README $(PROTSRECS)
	mount /fd0
	cp README $(PROTSRECS) /fd0
	umount /fd0
.PHONY:	floppy

mmon:	main.o
	$(LD) -o mmon $(LDFLAGS) main.o

%.sr:	%
	$(CONV) $(SRC) -o $@ $*

%0.sr %1.sr %2.sr %3.sr: %.sr
	splits $*.sr $*0.sr $*1.sr $*2.sr $*3.sr

%.dmp:	%
	$(DUMP) $(DUMPFLAGS) $* > $*.dmp

%.o:	%.S
	$(CC) -c $(CFLAGS) $*.S


# use awk to insert an S3 record near the end to program the sector protect
# on sector 0 of the AMD 29F040 (when using Data I/O programmer)
%.pr:	%.sr
	awk '/^S7/ { print "S30D000800000100000000000000E9" } { print }' $*.sr >$*.pr

