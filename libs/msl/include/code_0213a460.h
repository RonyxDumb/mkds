#pragma once

#include "types.h"

// Read by ScanStringSourceOp: a pointer to the next byte, and a flag word.
typedef struct ScanStringSource {
    /* 00 */ const char *mNextChar;
    /* 04 */ int mAtEnd;
} ScanStringSource;

// Values of the operation argument of ScanReadCharFunc: read the next character (-1 at the end), give a character
// back, and ask whether the end was reached.
#define SCAN_OP_READ 0
#define SCAN_OP_UNREAD 1
#define SCAN_OP_AT_END 2

// States of ScanInt32 and ScanInt64. READ_SIGN skips spaces and a sign, AFTER_SIGN looks for a leading 0, AFTER_ZERO
// for an x, FIRST_DIGIT needs a digit, DIGITS has read at least one. ENDED stops after the digits, FAILED stops on a
// bad start. STOPPED and VALID group them.
#define SCAN_INT_STATE_READ_SIGN 0x1
#define SCAN_INT_STATE_AFTER_SIGN 0x2
#define SCAN_INT_STATE_CHECK_RADIX_MARK 0x4
#define SCAN_INT_STATE_FIRST_DIGIT 0x8
#define SCAN_INT_STATE_DIGITS 0x10
#define SCAN_INT_STATE_ENDED 0x20
#define SCAN_INT_STATE_FAILED 0x40
#define SCAN_INT_STATES_STOPPED 0x60
#define SCAN_INT_STATES_VALID 0x34

// States of ScanDouble. The decimal ones follow the text: spaces and sign, the digits before the point, the point and
// the digits after it, E and the exponent sign and digits. DONE and FAILED end the loop, VALID_END groups the states
// in which the text read so far is a number. INFINITY and NAN read the rest of those words.
#define SCAN_DOUBLE_STATE_READ_SIGN 0x1
#define SCAN_DOUBLE_STATE_START_NUMBER 0x2
#define SCAN_DOUBLE_STATE_LEADING_ZEROS 0x4
#define SCAN_DOUBLE_STATE_INT_DIGITS 0x8
#define SCAN_DOUBLE_STATE_POINT_FIRST 0x10
#define SCAN_DOUBLE_STATE_FRACTION_DIGITS 0x20
#define SCAN_DOUBLE_STATE_EXPONENT_MARK 0x40
#define SCAN_DOUBLE_STATE_EXPONENT_SIGN 0x80
#define SCAN_DOUBLE_STATE_EXPONENT_FIRST 0x100
#define SCAN_DOUBLE_STATE_EXPONENT_ZEROS 0x200
#define SCAN_DOUBLE_STATE_EXPONENT_DIGITS 0x400
#define SCAN_DOUBLE_STATE_DONE 0x800
#define SCAN_DOUBLE_STATE_FAILED 0x1000
#define SCAN_DOUBLE_STATE_NAN 0x2000
#define SCAN_DOUBLE_STATE_INFINITY 0x4000
#define SCAN_DOUBLE_STATE_HEX 0x8000
#define SCAN_DOUBLE_STATES_STOPPED 0x1800
#define SCAN_DOUBLE_STATES_VALID_END 0xe2c

// Hexadecimal float states of ScanDouble (0x1p3 style): the mantissa digits, P, the exponent sign and digits.
#define SCAN_HEX_STATE_START 0x1
#define SCAN_HEX_STATE_LEADING_ZEROS 0x2
#define SCAN_HEX_STATE_INT_DIGITS 0x4
#define SCAN_HEX_STATE_FRACTION_DIGITS 0x8
#define SCAN_HEX_STATE_EXPONENT_MARK 0x10
#define SCAN_HEX_STATE_EXPONENT_SIGN 0x20
#define SCAN_HEX_STATE_EXPONENT_FIRST 0x40
#define SCAN_HEX_STATE_EXPONENT_ZEROS 0x80
#define SCAN_HEX_STATE_EXPONENT_DIGITS 0x100
#define SCAN_HEX_STATES_VALID_END 0x18e

// Digits ScanDouble keeps of a decimal number; further digits only move the exponent.
#define SCAN_DOUBLE_MAX_DIGITS 20

// Called through a pointer by ScanWithSourceFunc and ScanDouble: (their second argument, value, 0/1/2).
typedef int (*ScanReadCharFunc)(void *source, int character, int operation);

// Read by ScanDouble.
extern double gDoubleInfinity;

double strtod(const char *string, const char **end);
long StrtolBase10(const char *string);
long strtol(const char *string, const char **end, int base);
u32 strtoul(const char *string, const char **end, int base);
double ScanDouble(int maxChars, ScanReadCharFunc readChar, void *source, int *usedCount, int *overflow);
u64 ScanInt64(int base, int maxChars, ScanReadCharFunc readChar, void *source, int *usedCount, int *negative,
              int *overflow);
u32 ScanInt32(int base, int maxChars, ScanReadCharFunc readChar, ScanStringSource *source, int *usedCount,
              int *negative, int *overflow);

// 0x80 entries, indexed by byte values 0x00-0x7f by ScanDouble.
extern const u8 gUpperCaseMap[128];
// Byte table indexed by bytes below 0x80; read by StrcmpMapped.
extern const u8 gLowerCaseMap[128];
// u16 per byte value 0x00-0x7f; FormatParseSpec tests bit 3. Also read by ScanParseSpec.
extern const u16 gCharClassFlags[128];
