#pragma once

#include "types.h"

typedef struct Unk021a91cc {
    /* 00 */ u8 mUnk_00[0x50];
    /* 50 */ s32 mUnk_50;
    /* 54 */ u8 mUnk_54[6];
    /* 5a */ u8 mUnk_5a;
    /* 5b */ u8 mUnk_5b;
} Unk021a91cc;

void CPSi_SslCleanup(void);
void CPSi_SslPeriodical(s32 now);
