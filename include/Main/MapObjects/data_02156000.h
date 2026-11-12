#pragma once
#include "types.h"
#include "Main/Kart/code_0208fd8c.h" // KartAiItemUseEntry

// Objects whose layout isn't known yet.
extern u8 gMenuDisplaySettingsDesc[];

extern u16 data_02156598;

extern u32 data_usa_021568f8;

extern u16 gCollisionSlotDisabledFlag;

extern u16 gCollisionSlotRadiusFlag;

extern const u32 data_02156904;

extern const u32 data_02156908;

extern const u32 data_0215690c;

extern const u32 data_02156910;

extern const Vec3 gRockMatrixRow0;

extern const Vec3 gRockMatrixRow1;

extern const Vec3 gRockMatrixRow2;

extern struct MapObjectKindData gRockKindData;

extern s32 gCharacterBalloonOrShineHeights[];

// 8-byte entries of the table at gKeyboardCursorTargets.
typedef struct KeyboardCursorTargets {
    /* 00 */ u16 mUpFromRect1;
    /* 02 */ u16 mDownFromRect1;
    /* 04 */ u16 mUpFromRect2;
    /* 06 */ u16 mDownFromRect2;
} KeyboardCursorTargets;

extern const KeyboardCursorTargets gKeyboardCursorTargets[6];

extern const u16 gKeyboardLayoutRectCounts[6];

extern const u16 data_usa_02156584;

extern u32 data_usa_02156588;

extern u16 data_usa_0215658c;
