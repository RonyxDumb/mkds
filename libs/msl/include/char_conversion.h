#pragma once

#include "types.h"

// The two conversion functions called through CharConversion.mFunctions.
typedef struct CharConversionFunctions {
    /* 00 */ int (*mMbtowc)(u16 *dst, const char *src, u32 maxBytes);
    /* 04 */ int (*mWctomb)(char *dst, u16 wideChar);
} CharConversionFunctions;

// The character conversion tables: time strings, a second table and the conversion functions (mFunctions).
typedef struct CharConversion {
    /* 00 */ const char **mTimeStrings;
    /* 04 */ void **mUnk_04;
    /* 08 */ CharConversionFunctions *mFunctions;
} CharConversion;

extern CharConversion gCharConversion;

int wcstombs(char *dst, const u16 *src, u32 count);
int mbstowcs(u16 *dst, const char *src, u32 count);
int wctomb(char *dst, u16 wideChar);
int WctombSingleByte(char *dst, u16 wideChar);
int MbtowcSingleByte(u16 *dst, const char *src, u32 maxBytes);
int mbtowc(u16 *dst, const char *src, u32 maxBytes);
