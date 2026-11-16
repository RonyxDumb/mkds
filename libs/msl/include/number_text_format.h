#pragma once

#include "types.h"
#include "double_digits_math_functions.h" // DigitRecord

// FormatSpec.mArgKind: the length modifier of a format conversion.
enum {
    FORMAT_ARG_DEFAULT,
    FORMAT_ARG_CHAR,
    FORMAT_ARG_SHORT,
    FORMAT_ARG_LONG,
    FORMAT_ARG_INTMAX,
    FORMAT_ARG_SIZE,
    FORMAT_ARG_PTRDIFF,
    FORMAT_ARG_LONG_LONG,
    FORMAT_ARG_LONG_DOUBLE,
    FORMAT_ARG_WIDE
};

// FormatSpec.mSignKind: no sign flag, the + flag (a sign on every signed number), the space flag (a space for positive
// numbers; the + flag wins when both are given).
enum {
    FORMAT_SIGN_NONE,
    FORMAT_SIGN_PLUS,
    FORMAT_SIGN_SPACE,
};

// Most characters a field width or precision may be, and the limit on the characters of a converted number (its end 0
// counted).
#define FORMAT_MAX_LENGTH 0x1fd

// FormatSpec.mPadKind: how the converted text is padded to mMinLength.
enum {
    FORMAT_PAD_LEFT_ALIGN,
    FORMAT_PAD_SPACES,
    FORMAT_PAD_ZEROS,
};

// FormatSpec.mSpecChar when the conversion is not valid.
#define FORMAT_SPEC_INVALID 0xff

// FormatSpec.mPrecision when the format gives none, for the floating point, hex floating point and pointer conversions.
#define FORMAT_FLOAT_DEFAULT_PRECISION 6
#define FORMAT_HEX_FLOAT_DEFAULT_PRECISION 0xd
#define FORMAT_POINTER_DIGITS 8

// A parsed format conversion: padding, sign, dot and hash flags, argument kind, spec character, width and precision.
typedef struct FormatSpec {
    /* 00 */ u8 mPadKind;
    /* 01 */ u8 mSignKind;
    /* 02 */ u8 mHasDot;
    /* 03 */ u8 mHash;
    /* 04 */ u8 mArgKind;
    /* 05 */ u8 mSpecChar;
    /* 08 */ s32 mMinLength;
    /* 0c */ s32 mPrecision;
} FormatSpec;

// Strings passed to strcpy by FormatDouble and FormatDoubleHex.
extern char gFormatMinusInfUpper[];
extern char gFormatMinusInfLower[];
extern char gFormatInfUpper[];
extern char gFormatInfLower[];
extern char gFormatMinusNanUpper[];
extern char gFormatMinusNanLower[];
extern char gFormatNanUpper[];
extern char gFormatNanLower[];
// String passed to strcpy by FormatDoubleHex.
extern char gFormatHexZero[];

int FormatWithPutFunc(void *(*putFunc)(void *, const char *, u32), void *putArg, const char *format, char *argList);
char *FormatDouble(double value, char *end, FormatSpec spec);
void FormatRoundDigitChars(DigitRecord *record, int keepCount);
char *FormatDoubleHex(double value, char *end, FormatSpec spec);
char *FormatInt64(u64 value, char *end, FormatSpec spec);
char *FormatInt32(unsigned long value, char *end, FormatSpec spec);
const char *FormatParseSpec(const char *format, char **argList, FormatSpec *buf);

extern char gLocaleEmptyString[];
extern char gLocaleTimeFormatHMS[];
extern char gLocaleAmPmNames[];
extern char gLocaleDateFormat[];
extern char gLocaleTime12Format[];
extern char gLocaleDateTimeFormat[];
extern char gLocaleDayNames[];
extern char gLocaleMonthNames[];
extern u16 gLocaleNameOffsets[58];
extern void *gLocaleCharInfo[4];
extern const char *gLocaleTimeStrings[8];
