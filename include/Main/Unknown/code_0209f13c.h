#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object with the MapObject base: two halfwords at 0xa0 and 0xa2, then two words (UpdateChandelier,
// InitChandelierObjects, DrawChandelier).
typedef struct Unk0209f338 {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mFrameIndex;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mState;
} Unk0209f338;

// Object with the MapObject base and the frame index at 0xa0 (UpdateRainStar, DrawRainStar).
typedef struct Unk0209f1c8 {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mFrameIndex;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mState;
} Unk0209f1c8;

// Array of object pointers: pointer to the array and the number of entries (InitChandelierObjects).
typedef struct Unk0209f514 {
    /* 00 */ Unk0209f338 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209f514;

extern char gRainStarNsbmdName[];
extern char gRainStarNsbtaName[];

void *CreateRainStarUpdateList(void);
void *CreateRainStarDrawList(void);
void UpdateRainStar(void *mapObjectList, Unk0209f1c8 *rainStar); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawRainStar(void *mapObjectList, Unk0209f1c8 *rainStar);
void CreateRainStar(void *mapObjectList);
void *CreateChandelierUpdateList(void);
void *CreateChandelierDrawList(void);
void UpdateChandelier(void *mapObjectList, Unk0209f338 *chandelier); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitChandelierObjects(Unk0209f514 *objectList);
