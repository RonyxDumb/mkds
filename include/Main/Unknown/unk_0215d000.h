#pragma once

#include "types.h"

// Four bytes: two column bounds, then two row bounds (inclusive).
typedef struct ByteRect {
    /* 00 */ u8 mMinX;
    /* 01 */ u8 mMaxX;
    /* 02 */ u8 mMinY;
    /* 03 */ u8 mMaxY;
} ByteRect;

extern s16 gTxtSystemBgOffsets[];
extern u8 gTxtSystemCanvasSizes[][2];
extern u16 gTxtSystemCanvasCharOffsets[];
extern ByteRect gTxtSystemHitRects[];
extern ByteRect gTxtSystemNscrRects[];
extern u8 gSelectChoisesNscrOrigins[][2];
extern ByteRect gSelectChoisesTileRect;
extern ByteRect gSelectChoisesHitRects[];
extern ByteRect gSelectChoisesPaletteRects[];

// Objects whose layout isn't known yet.
extern const s16 gPairsByAngle[];
extern s16 data_0215d6b4[];

extern u16 gTrophyIconNclrStarts[];
extern u16 gTrophyIconBnclIndices[];
extern u8 data_0215d024[];
extern u8 gBackScreenSNclrStarts[];
extern u8 gBackScreenMNclrStarts[];
extern u8 gBackScreenInLoadedArchives[];
extern u8 gBackScreenKindMIndices[];
extern u8 gBackScreenKindSIndices[];
extern s8 gSelectReturnState1Bg2Offsets[];
extern s8 gSelectReturnState4Bg2Offsets[];
extern u8 data_0215d0d8[];
extern u8 data_0215d0dc[][1];
extern u8 gKeyboardTextLimits[];
extern u8 gKeyboardButtonLabelIndices[][2];
extern s8 gSelectReturnState3Bg2Offsets[];
extern u8 gKeyboardLayoutEntryIndices[];
extern u8 data_0215d0f0[];
extern u8 gKeyboardCursorCornerEntryIndices[][4];
extern s16 gKeyboardTextOffsetYTarget[2][2];
extern s16 gKeyboardTextOffsetYInitial[2][2];
extern u8 data_0215d110[];
extern u8 gKeyboardNextLayoutRegion0[];
extern u8 gKeyboardNextLayoutOtherRegion[];
extern u8 gKeyboardButtonEntryIndices[2][2][3];
extern u8 gKeyboardTextCharLabelIndices[][12];
extern u8 gKeyboardTextIndexEntryIndices[][12];
extern u8 gLinkLevelIconSlotCellEntryIndices[];
extern u8 gLinkLevelIconCharCounts[];
extern u8 gLinkLevelIconCharCellEntryIndices[][4];
extern const s16 data_usa_0215d8b4[];
