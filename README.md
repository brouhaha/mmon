# mmon: 64-bit MIPS mini-monitor (can operate without RAM)

Copyright 1996, 2003 Eric Smith <eric@brouhaha.com>
SPDX-License-IdentifierGPL-2.0-only

mmon development is hosted at the
[mmon Github repository](https://github.com/brouhaha/mmon).

## Introduction
mmon is a tiny monitor program for the 64-bit MIPS processors.  It can
operate with NO working RAM, using only the processor registers, so it
can be useful for hardware bringup, including testing a RAM controller.

Originally mmon supported the VR4300 MIPS processor. With minor changes,
mmon should be usable on other 64-bit MIPS processors.

Alexander Voropay contributed support to use mmon on QEMU. This is now
the main branch. See also the file README-qemu for details.

The original VR4300 vresion of mmon is tagged as "v0.5" in the git repository.

## Commands

| command                     | description |
| --------------------------- | ----------- |
| `db <addr1> [<addr2>]`      | dump memory bytes from addr1 to addr2 (non-inclusive) |
| `dh <addr1> [<addr2>]`      | dump memory half-words (16-bit) |
| `dw <addr1> [<addr2>]`      | dump memory words (32-bit) |
| `sb <addr> <data>...`       | store one byte of data to address |
| `sh <addr> <data>...`       | store one half-word (16-bit) of data to address |
| `sw <addr> <data>...`       | store one word (32-bit) of data to address |
| `swl <addr> <data>`         | store word left |
| `swr <addr> <data>`         | store word right |
| `fb <addr1> <addr2> <data>` | fill bytes of memory |
| `fh <addr1> <addr2> <data>` | fill half-words |
| `fw <addr1> <addr2> <data>` | fill words |
| `l`                         | load S-records |
| `g <addr>`                  | go (start execution at address) |

Addresses and data must be given in hexadecimal.

Everything (including hex digits 'a'..'f') must be in lower case.

There is no error checking of any kind.

If you give an invalid address you will probably get an exception which
will hang and you will have to press the reset button.

A lengthy dump can be interrupted by sending any character.


## License
This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as published
by the Free Software Foundation.  Note that permission is not granted to
redistribute this program under the terms of any later version of the
General Public License.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
675 Mass Ave, Cambridge, MA 02139, USA.
