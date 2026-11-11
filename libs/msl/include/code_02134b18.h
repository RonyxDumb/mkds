#pragma once

#include "types.h"

// The two conversion functions called through CharConversion.mFunctions.
typedef struct CharConversionFunctions {
    /* 00 */ int (*mMbtowc)(u16 *dst, const char *src, u32 n);
    /* 04 */ int (*mWctomb)(char *dst, u16 c);
} CharConversionFunctions;

// wctomb and mbtowc read the pointer at 0x08.
typedef struct CharConversion {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ CharConversionFunctions *mFunctions;
} CharConversion;

extern CharConversion data_0216eccc;

int wcstombs(char *dst, const u16 *src, u32 count);
int mbstowcs(u16 *dst, const char *src, u32 count);
int wctomb(char *dst, u16 wideChar);
int WctombSingleByte(char *dst, u16 wideChar);
int MbtowcSingleByte(u16 *dst, const char *src, u32 maxBytes);
int mbtowc(u16 *dst, const char *src, u32 maxBytes);
