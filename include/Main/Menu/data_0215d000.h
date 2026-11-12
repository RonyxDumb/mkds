#pragma once
#include "types.h"

// Four bytes: two column bounds, then two row bounds (inclusive).
typedef struct ByteRect {
    /* 00 */ u8 mMinX;
    /* 01 */ u8 mMaxX;
    /* 02 */ u8 mMinY;
    /* 03 */ u8 mMaxY;
} ByteRect;

// Objects whose layout isn't known yet.
extern s16 data_0215d6b4[];

extern u8 gBackScreenSNclrStarts[];

extern u8 gBackScreenMNclrStarts[];

extern u8 gBackScreenInLoadedArchives[];

extern u8 gBackScreenKindMIndices[];

extern u8 gBackScreenKindSIndices[];

extern u8 gKeyboardNextLayoutRegion0[6];

extern u8 gKeyboardNextLayoutOtherRegion[6];

extern u8 gKeyboardButtonEntryIndices[2][2][3];

extern u8 gKeyboardTextCharLabelIndices[][12];

extern u8 gKeyboardTextIndexEntryIndices[][12];

extern const s16 data_usa_0215d8b4[];
