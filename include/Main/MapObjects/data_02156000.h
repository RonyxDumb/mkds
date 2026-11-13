#pragma once
#include "types.h"
#include "Main/Kart/code_0208fd8c.h" // KartAiItemUseEntry

extern const Vec3 gRockMatrixRow0;

extern const Vec3 gRockMatrixRow1;

extern const Vec3 gRockMatrixRow2;

extern const s32 gCharacterBalloonOrShineHeights[16];

// 8-byte entries of the table at gKeyboardCursorTargets.
typedef struct KeyboardCursorTargets {
    /* 00 */ u16 mUpFromRect1;
    /* 02 */ u16 mDownFromRect1;
    /* 04 */ u16 mUpFromRect2;
    /* 06 */ u16 mDownFromRect2;
} KeyboardCursorTargets;

extern const KeyboardCursorTargets gKeyboardCursorTargets[6];

extern const u16 gKeyboardLayoutRectCounts[6];
