#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/MapObjects/attractor.h" // MapObject

// Object with the MapObject base: two halfwords at 0xa0 and 0xa2, then two words (UpdateChandelier,
// InitChandelierObjects, DrawChandelier).
typedef struct Chandelier {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mFrameIndex;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mState;
} Chandelier;

// Object with the MapObject base and the frame index at 0xa0 (UpdateRainStar, DrawRainStar).
typedef struct RainStar {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mFrameIndex;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mState;
} RainStar;

extern char gRainStarNsbmdName[];
extern char gRainStarNsbtaName[];

void *CreateRainStarUpdateList(void);
void *CreateRainStarDrawList(void);
void UpdateRainStar(void *mapObjectList,
                    RainStar *rainStar); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawRainStar(void *mapObjectList, RainStar *rainStar);
void CreateRainStar(void *mapObjectList);
void *CreateChandelierUpdateList(void);
void *CreateChandelierDrawList(void);
void UpdateChandelier(void *mapObjectList,
                      Chandelier *chandelier); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitChandelierObjects(MapObjectList *objectList);
