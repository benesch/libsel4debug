/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <stdint.h>
#include <stdlib.h>
#include <utils/util.h>

/* Defs clagged from libsel4platsupport. */
#define REG_PTR(base, offset)  ((volatile uint32_t *)((char*)(base) + (offset)))
#define USR2 0x98
#define UART_SR2_TXFIFO_EMPTY 14
#define UTXD  0x40 /* UART Transmitter Register */

static void *base;

int debug_plat_serial_init(void *data)
{
    base = data;
    return 0;
}

int debug_plat_putchar(int c)
{
    if (base == NULL) {
        return -1;
    }

    /* Wait for the device to be ready. */
    while (!(*REG_PTR(base, USR2) & BIT(UART_SR2_TXFIFO_EMPTY)));

    /* Write the character. */
    *REG_PTR(base, UTXD) = c;

    return 0;
}
