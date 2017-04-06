/*
 * Copyright (c) 2014, STMicroelectronics International N.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* From user_ta_header.c, built within TA */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "compiler.h"
#include "syscalls.h"
#include "elf_note.h"

extern uint8_t ta_heap[];
extern const size_t ta_heap_size;

struct app_header {
    uint64_t entry;
};

struct app_params {
    uint64_t param0;
    uint64_t param1;
    uint64_t param2;
    uint64_t param3;
};

void do_log(const char *str)
{
	app_log(str, strlen(str));
}

void __noreturn __app_entry(unsigned long func,
			    struct app_params *up)
{
	int res = 0;
	/* do_log("Hello from EL0 app!"); */
	/* do_log("Trying to return something..."); */
	app_return(res);
}


const struct app_header app_header __section(".app_head") = {
    .entry = (uint64_t) &__app_entry,
};

ELFNOTE64("Xen", XEN_ELFNOTE_GUEST_OS,        "app");
ELFNOTE64("Xen", XEN_ELFNOTE_GUEST_VERSION,   "0.1");
ELFNOTE64("Xen", XEN_ELFNOTE_XEN_VERSION,     "xen-3.0");
ELFNOTE64("Xen", XEN_ELFNOTE_ENTRY,            &__app_entry);
ELFNOTE64("Xen", XEN_ELFNOTE_FEATURES,        "writable_descriptor_tables|auto_translated_physmap|supervisor_mode_kernel|hvm_callback_vector");
ELFNOTE64("Xen", XEN_ELFNOTE_PAE_MODE,        "yes");
ELFNOTE64("Xen", XEN_ELFNOTE_LOADER,          "generic");
ELFNOTE64("Xen", XEN_ELFNOTE_SUSPEND_CANCEL,  0);
