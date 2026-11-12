#pragma once

#include "types.h"

typedef struct DigitRecord DigitRecord;

// 16 bytes. Filled by FormatWideParseSpec from the text after a '%', read by FormatWideWithPutFunc and passed by value
// (one word in r3, three on the stack) to FormatWideDouble, FormatWideInt64 and FormatWideInt32. Byte 0x05 is never
// accessed.
typedef struct FormatWideSpec {
    /* 00 */ u8 mPadKind;
    /* 01 */ u8 mSignKind;
    /* 02 */ u8 mHasDot;
    /* 03 */ u8 mHash;
    /* 04 */ u8 mArgKind;
    /* 06 */ u16 mSpecChar;
    /* 08 */ s32 mMinLength;
    /* 0c */ s32 mUnk_0c;
} FormatWideSpec;

int FormatWideWithPutFunc(void *(*putFunc)(void *, const u16 *, u32), void *putArg, const u16 *format, char *argList);
u16 *FormatWideDouble(double value, u16 *end, FormatWideSpec spec);
void FormatWideRoundDigitChars(DigitRecord *record, int keepCount);
u16 *FormatWideInt64(u64 value, u16 *end, FormatWideSpec spec);
u16 *FormatWideInt32(unsigned long value, u16 *end, FormatWideSpec spec);
const u16 *FormatWideParseSpec(const u16 *format, char **argList, FormatWideSpec *specOut);

// u16 table indexed by characters below 0x80; FormatWideParseSpec tests bit 3, FormatWideDouble bit 9.
extern const u16 gCharFlags[128];
