#ifndef APP_SYSCALLS_H
#define APP_SYSCALLS_H

#include "compiler.h"
#include <stddef.h>
#include <stdint.h>

void app_return(unsigned long ret) __noreturn;
void app_log(const void *buf, size_t len);

#endif
