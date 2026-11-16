#pragma once

#include "string.h"
#include "types.h"


// Number bases the formatter converts in.
enum {
    PRINTF_RADIX_OCTAL = 8,
    PRINTF_RADIX_DECIMAL = 10,
    PRINTF_RADIX_HEX = 16,
};
// Output cursor of the formatter: room left, next write position, start of the output.
typedef struct dst_string {
    /* 00 */ size_t mLen;  // bytes still free; Util_PrintContext_ApppendChar stores only while this is nonzero
    /* 04 */ char *mCur; // next write position; moves on for every byte, stored or not
    /* 08 */ char *mBase; // start of the output (dst)
} dst_string;

int Util_VSNPrintF(char *dst, size_t len, const char *fmt, char *args);
int Util_SNPrintF(char *dst, size_t len, const char *fmt, ...);
int Util_VSPrintF(char *dst, const char *fmt, char *args);
int MaybeUtil_SPrintF(char *dst, const char *fmt, ...);
void Util_PrintContext_AppendString(dst_string *str, const char *src, int len);
void Util_PrintContext_FillWith(dst_string *str, char character, int len);
void Util_PrintContext_ApppendChar(dst_string *str, char character);
