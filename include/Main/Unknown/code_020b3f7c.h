#pragma once

#include "types.h"

// Section header: two words; setupBmg adds the second to the section address to move on.
typedef struct BmgSectionHeader {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
} BmgSectionHeader;

// Object setupBmg walks: the number of sections at 0x0c, the first section at 0x20.
typedef struct Bmg {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u32 mSectionCount;
    /* 10 */ u8 mUnk_10[0x10];
    /* 20 */ BmgSectionHeader mFirstSection;
} Bmg;

// Section of setupBmg whose first word is 0x494e4631 (BMG_INF1_Pointer): words from 0x10.
typedef struct Unk0217b340 {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ u32 mEntryOffsets[1];
} Unk0217b340;

// Section of setupBmg whose first word is 0x44415431 (BMG_DAT1_Pointer): bytes from 8.
typedef struct BmgBodySection {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
    /* 08 */ u8 mBody[1];
} BmgBodySection;

void setupBmg(Bmg *bmg);
void *jn_msg_getMessage(Bmg *bmg, s32 index);
