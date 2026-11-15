#pragma once
#include "types.h"

// Four bytes: two column bounds, then two row bounds (inclusive).
typedef struct ByteRect {
    /* 00 */ u8 mMinX;
    /* 01 */ u8 mMaxX;
    /* 02 */ u8 mMinY;
    /* 03 */ u8 mMaxY;
} ByteRect;

extern const u8 gBackScreenSNclrStarts[];

extern const u8 gBackScreenMNclrStarts[];

extern const u8 gBackScreenInLoadedArchives[];

// Pairs of indices per kind: the M index, then the S index.
extern const u8 gBackScreenKindIndices[];

extern const u8 gKeyboardNextLayouts[2][6];

extern const u8 gKeyboardButtonEntryIndices[2][2][3];

extern const u8 gKeyboardTextCharLabelIndices[2][12];

extern const u8 gKeyboardTextIndexEntryIndices[2][12];
