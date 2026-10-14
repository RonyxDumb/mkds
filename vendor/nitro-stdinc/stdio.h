/* Standard declaration subset for Nitro SDK headers; no I/O implementation. */
#ifndef MKDS_NITRO_STDIO_H
#define MKDS_NITRO_STDIO_H
#include <ansi_params.h>
#include <stddef.h>
#include <stdarg.h>
int printf(const char *, ...);
int sprintf(char *, const char *, ...);
int snprintf(char *, size_t, const char *, ...);
int vprintf(const char *, va_list);
int vsprintf(char *, const char *, va_list);
int vsnprintf(char *, size_t, const char *, va_list);
#endif
