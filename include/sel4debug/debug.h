/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef _LIBSEL4DEBUG_DEBUG_H_
#define _LIBSEL4DEBUG_DEBUG_H_

#include <autoconf.h>

#include <sel4/sel4.h>
#include <sel4/types.h>

/* An implementation of printf that you can safely call from within syscall
 * stubs.
 */
int
debug_safe_printf(const char *format, ...)
__attribute__((format(printf, 1, 2)))
__attribute__((no_instrument_function));

void debug_cap_identify(seL4_CPtr cap);

#ifdef CONFIG_USER_DEBUG_BUILD
void debug_print_bootinfo(seL4_BootInfo *info);
#else
#define debug_print_bootinfo(x)
#endif /* CONFIG_USER_DEBUG_BUILD */

#endif /* !_LIBSEL4DEBUG_DEBUG_H_ */
