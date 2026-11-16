#pragma once

#include "types.h"

// Bits of OamEntry.mAttr01 (the object attribute 0 half is the low 16 bits, attribute 1 the high 16 bits).
#define OAM_ATTR01_Y_MASK 0xff
#define OAM_ATTR01_X_MASK 0x1ff0000
#define OAM_ATTR01_NOT_POSITION_MASK 0xfe00ff00
#define OAM_ATTR01_NOT_EFFECT_MASK 0xc1fffcff
#define OAM_ATTR01_NOT_MODE_MASK 0xfffff3ff
#define OAM_ATTR01_EFFECT_AFFINE 0x100
#define OAM_ATTR01_EFFECT_HIDDEN 0x200
#define OAM_ATTR01_EFFECT_DOUBLE_AFFINE 0x300

// Bits of OamEntry.mAttr2.
#define OAM_ATTR2_TILE_MASK 0x3ff
#define OAM_ATTR2_NOT_PRIORITY_MASK 0xfffff3ff
#define OAM_ATTR2_NOT_PALETTE_MASK 0xffff0fff

// 8-byte object at index i of OamRange.mUnk_08: GetOamRangeEntryPosition reads bits 16-24 and bits 0-7 of its word
// at 0x00.
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
