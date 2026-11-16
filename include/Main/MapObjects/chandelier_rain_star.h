#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "01/MapObjects/map_object_model.h"

// Chandelier.mState: waiting out mTimer, then playing the animation once.
#define CHANDELIER_STATE_WAIT 0
#define CHANDELIER_STATE_ANIMATE 1

// Chandelier.mFrameIndex values at which a sound starts, and the sound ids (each pair of frames shares one sound).
#define CHANDELIER_FIRST_SOUND_EARLY_FRAME 0
#define CHANDELIER_FIRST_SOUND_LATE_FRAME 0x7d
#define CHANDELIER_SECOND_SOUND_EARLY_FRAME 0x46
#define CHANDELIER_SECOND_SOUND_LATE_FRAME 0xaf
#define CHANDELIER_THIRD_SOUND_FRAME 0xfa
#define CHANDELIER_FIRST_SOUND_ID 0x11a
#define CHANDELIER_SECOND_SOUND_ID 0x11b
#define CHANDELIER_THIRD_SOUND_ID 0x119

// A chandelier map object: its animation frame, timer and state.
typedef struct Chandelier {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mFrameIndex;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mState;
} Chandelier;

// A rain star map object: its animation frame; the object turns by 0x111 each update.
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
                    RainStar *rainStar); /* skipped for objects with MAP_OBJECT_FLAG_NO_UPDATE set (parked ones) */
void DrawRainStar(void *mapObjectList, RainStar *rainStar);
void CreateRainStar(void *mapObjectList);
MapObjectList *CreateChandelierUpdateList(void);
MapObjectList *CreateChandelierDrawList(void);
void UpdateChandelier(
    void *mapObjectList,
    Chandelier *chandelier); /* skipped for objects with MAP_OBJECT_FLAG_NO_UPDATE set (parked ones) */
void InitChandelierObjects(MapObjectList *objectList);

extern struct MapObjectModel *gRainStar;
