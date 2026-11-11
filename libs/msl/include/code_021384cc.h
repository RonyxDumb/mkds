#pragma once

#include "types.h"

void srand(u32 seed);

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
