#pragma once

#include "types.h"

// Read by ScanStringSourceOp: a pointer to the next byte, and a flag word.
typedef struct ScanStringSource {
    /* 00 */ const char *mNextChar;
    /* 04 */ int mAtEnd;
} ScanStringSource;

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
