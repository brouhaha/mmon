/*
   uart.h: MIPS VR4300 mini-monitor
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

#define UART_BASE       0xB40003f8
#define UART_DATA       0x0
#define UART_DLL        0x0
#define UART_DLM        0x1
#define UART_IER        0x1
#define UART_IIR        0x2
#define UART_FCR        0x2
#define UART_LCR        0x3
#define UART_MCR        0x4
#define UART_LSR        0x5
#define UART_MSR        0x6
#define UART_SCR        0x7


#define UART_LCR_W      0x07    # Set UART to 8,N,2 & DLAB = 0
#define UART_LCR_DLAB   0x87    # Set UART to 8,N,2 & DLAB = 1
#define UART_DLL_96     0x78    # Sel UART Divisor latch LSB to 120 Dec
#define UART_DLM_96     0x00    # Sel UART Divisor latch MSB to 0
#define UART_MCR_ON     0x0f    # Turn on LEDS, DTR and DSR
#define UART_MCR_OFF    0x03    # Turn off LEDS, turn on DTR and DSR

#define UART_FCR_FIFO_EN 0x01	# FIFO enable

#define UART_LSR_DR     0x01    # UART received data present
#define UART_LSR_TE     0x40    # UART transmitter empty

#define UART_MCR_ON_1   0x04
#define UART_MCR_ON_2	0x08

