#pragma once

#include "types.h"
#include "00/code_021884d8.h"
#include "code_02142eac.h"

// Three words: a function called with (name, size) that returns a block, a function called with (name, block, 0) that
// releases it, and a word.
typedef struct DWCNetcheckParam {
    /* 00 */ void *(*mAlloc)();
    /* 04 */ void (*mFree)();
    /* 08 */ u32 mBmworkarea;
} DWCNetcheckParam;

// Element of the table at 0x300 of an Unk02188408.
typedef struct Unk02188408Entry24 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 pad_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ char mUnk_04[0x20];
} Unk02188408Entry24;

// Element of the table at 0x444 of an Unk02188408.
typedef struct Unk02188408Entry4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mApType;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk02188408Entry4;

// Object behind gAcWork.
typedef struct Unk02188408 {
    /* 000 */ u8 pad_000[0x300];
    /* 300 */ Unk02188408Entry24 mUnk_300[9];
    /* 444 */ Unk02188408Entry4 mUnk_444[11];
    /* 470 */ WMBssDesc mUnk_470[11];
    /* cb0 */ u8 pad_cb0[0x5a];
    /* d0a */ u8 mUnk_d0a;
    /* d0b */ u8 mUnk_d0b_0 : 2;
    /*     */ u8 mAuthMode : 2;
    /*     */ u8 mAroundCount : 4;
    /* d0c */ u8 mUnk_d0c_0 : 4;
    /*     */ u8 mSkipNetCheck : 2;
    /*     */ u8 mDuplicateFlag : 2;
    /* d0d */ u8 mUnk_d0d;
    /* d0e */ u8 pad_d0e;
    /* d0f */ u8 mUnk_d0f;
    /* d10 */ u8 mUnk_d10;
    /* d11 */ s8 mUnk_d11;
    /* d12 */ u8 mUnk_d12;
    /* d13 */ u8 mUnk_d13;
    /* d14 */ u8 mUnk_d14;
    /* d15 */ u8 pad_d15[3];
} Unk02188408;

extern const s8 *gBase64Alphabet;
extern u8 gHttpName[];
extern u8 gNetcheckName[];

void DWCi_Netcheck_StartThread(void);
void DWC_Netcheck_Destroy(void);
u32 DWC_Netcheck_Create(DWCNetcheckParam *param);
s32 DWC_Auth_Base64Decode(const s8 *src, u32 srcLength, u8 *dst, u32 dstLength);
s32 DWC_Auth_Base64Encode(const u8 *src, u32 srcLength, char *dst, u32 dstLength);
s32 CheckDuplicate(void);
void FreeDisused(void);
