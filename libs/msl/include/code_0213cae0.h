#pragma once

#include "types.h"

typedef struct DigitRecord DigitRecord;

// FormatWideSpec.mArgKind: the length modifier of a format conversion.
enum {
    FORMAT_WIDE_ARG_DEFAULT,
    FORMAT_WIDE_ARG_CHAR,
    FORMAT_WIDE_ARG_SHORT,
    FORMAT_WIDE_ARG_LONG,
    FORMAT_WIDE_ARG_LONG_LONG,
    FORMAT_WIDE_ARG_LONG_DOUBLE,
    FORMAT_WIDE_ARG_WIDE
};

// FormatWideSpec.mPadKind: how the converted text is padded to mMinLength.
enum {
    FORMAT_WIDE_PAD_LEFT_ALIGN,
    FORMAT_WIDE_PAD_SPACES,
    FORMAT_WIDE_PAD_ZEROS,
};

// FormatWideSpec.mSpecChar when the conversion is not valid.
#define FORMAT_WIDE_SPEC_INVALID 0xffff

// FormatWideSpec.mPrecision when the format gives none, for the floating point and pointer conversions.
#define FORMAT_WIDE_FLOAT_DEFAULT_PRECISION 6
#define FORMAT_WIDE_POINTER_DIGITS 8

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
    /* 0c */ s32 mPrecision;
} FormatWideSpec;

int FormatWideWithPutFunc(void *(*putFunc)(void *, const u16 *, u32), void *putArg, const u16 *format, char *argList);
u16 *FormatWideDouble(double value, u16 *end, FormatWideSpec spec);
void FormatWideRoundDigitChars(DigitRecord *record, int keepCount);
u16 *FormatWideInt64(u64 value, u16 *end, FormatWideSpec spec);
u16 *FormatWideInt32(unsigned long value, u16 *end, FormatWideSpec spec);
const u16 *FormatWideParseSpec(const u16 *format, char **argList, FormatWideSpec *specOut);

// u16 table indexed by characters below 0x80; FormatWideParseSpec tests bit 3, FormatWideDouble bit 9.
extern const u16 gCharFlags[128];
