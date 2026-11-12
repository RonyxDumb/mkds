#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "01/MapObjects/data_0209bc74.h"

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


MapObjectList *CreateRainStarUpdateList(void);
MapObjectList *CreateRainStarDrawList(void);
void UpdateRainStar(void *mapObjectList,
                    RainStar *rainStar); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawRainStar(void *mapObjectList, RainStar *rainStar);
void CreateRainStar(void *mapObjectList);
MapObjectList *CreateChandelierUpdateList(void);
MapObjectList *CreateChandelierDrawList(void);
void UpdateChandelier(void *mapObjectList,
                      Chandelier *chandelier); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitChandelierObjects(MapObjectList *objectList);

extern struct MapObjectModel *gRainStar;
