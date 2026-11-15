#pragma once

#include "types.h"
#include "00/Lib/DWC/access_point_state.h"
#include "wireless_link_control.h"

// Three words: a function called with (name, size) that returns a block, a function called with (name, block, 0) that
// releases it, and a word.
typedef struct DWCNetcheckParam {
    /* 00 */ void *(*mAlloc)();
    /* 04 */ void (*mFree)();
    /* 08 */ u32 mBmworkarea;
} DWCNetcheckParam;

extern const s8 *gBase64Alphabet;

void DWCi_Netcheck_StartThread(void);
void DWC_Netcheck_Destroy(void);
u32 DWC_Netcheck_Create(DWCNetcheckParam *param);
s32 DWC_Auth_Base64Decode(const s8 *src, u32 srcLength, char *dst, u32 dstLength);
s32 DWC_Auth_Base64Encode(const u8 *src, u32 srcLength, char *dst, u32 dstLength);
s32 CheckDuplicate(void);
void FreeDisused(void);
