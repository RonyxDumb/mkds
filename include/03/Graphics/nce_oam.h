#pragma once

#include "types.h"

// Bits of OamEntry.mAttr01 (the object attribute 0 half is the low 16 bits, attribute 1 the high 16 bits).
#define OAM_ENTRY_Y_POSITION_MASK 0xff
#define OAM_ENTRY_X_POSITION_MASK 0x1ff0000
#define OAM_ENTRY_NOT_POSITION_MASK 0xfe00ff00
#define OAM_ATTR01_NOT_EFFECT_MASK 0xc1fffcff
#define OAM_ENTRY_NOT_MODE_MASK 0xfffff3ff
#define OAM_ENTRY_EFFECT_TAKES_AFFINE_INDEX 0x100
#define OAM_ENTRY_EFFECT_HIDDEN 0x200
#define OAM_ENTRY_EFFECT_TAKES_AFFINE_INDEX_BOTH_BITS 0x300

// Bits of OamEntry.mAttr2.
#define OAM_ATTR2_TILE_MASK 0x3ff
#define OAM_ENTRY_NOT_PRIORITY_MASK 0xfffff3ff
#define OAM_ENTRY_NOT_PALETTE_MASK 0xffff0fff

// One OAM entry: the attribute 0 and 1 word and the attribute 2 halfword of a sprite.
typedef struct OamEntry {
    /* 00 */ u32 mAttr01;
    /* 04 */ u16 mAttr2;
    /* 06 */ u16 mUnk_06;
} OamEntry;

// A run of OamEntry objects (mEntries, mEntryCount), linked into a list by mPrev and mNext.
typedef struct OamRange {
    /* 00 */ struct OamRange *mPrev;
    /* 04 */ struct OamRange *mNext;
    /* 08 */ OamEntry *mEntries;
    /* 0c */ u8 mEntryCount;
} OamRange;

void GetOamRangeEntryPosition(OamRange *range, int index, s32 *xPos, s32 *yPos);

extern struct OamRanges *gOamRanges;
extern struct NceImage *gNceFiles[2];
