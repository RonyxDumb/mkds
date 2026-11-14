#pragma once

#include "types.h"
#include "code_02134398.h"
#include "output_effect.h" // CallbackInfo

void srand(u32 seed);

// ScanSpec.mArgKind: the length modifier of a scan conversion.
enum {
    SCAN_ARG_DEFAULT,
    SCAN_ARG_CHAR,
    SCAN_ARG_SHORT,
    SCAN_ARG_LONG,
    SCAN_ARG_INTMAX,
    SCAN_ARG_SIZE,
    SCAN_ARG_PTRDIFF,
    SCAN_ARG_LONG_LONG,
    SCAN_ARG_DOUBLE,
    SCAN_ARG_LONG_DOUBLE,
    SCAN_ARG_WIDE
};

// ScanSpec.mSpecChar value for a conversion that cannot be scanned.
#define SCAN_SPEC_INVALID 0xff

// 0x28 bytes. Filled by ScanParseSpec from the text at its first argument, starting from a local copy with every
// byte zero and mMaxLength = 0x7fffffff; ScanWithSourceFunc reads mCharSet one bit per byte value.
typedef struct ScanSpec {
    /* 00 */ u8 mStar;
    /* 01 */ u8 mHasMaxLength;
    /* 02 */ u8 mArgKind;
    /* 03 */ u8 mSpecChar;
    /* 04 */ s32 mMaxLength;
    /* 08 */ u8 mCharSet[32];
} ScanSpec;

u32 rand(void);
int sscanf(const char *text, const char *format, ...);
int vsscanf(const char *text, const char *format, char *args);

#include "code_0213a460.h"

typedef struct ScanStringSource ScanStringSource;

int ScanStringSourceOp(void *context, int character, int operation);
int ScanWithSourceFunc(ScanReadCharFunc f, ScanStringSource *source, const char *format, char *b);
const char *ScanParseSpec(const char *format, ScanSpec *outSpec);

extern u32 gRandValue;
