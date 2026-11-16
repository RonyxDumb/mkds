#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectKindData
#include "01/MapObjects/map_object_model.h"
#include "Main/MapObjects/airship_draw.h" // Airship

// Values of TownMonte.mSoundId that InitTownMonteObjects picks from the animation frame.
#define TOWN_MONTE_SOUND_FIRST 0x1a7
#define TOWN_MONTE_SOUND_SECOND 0x1a8

// A Town Monte map object: its animation frame, sound id and the bounce it makes.
typedef struct TownMonte {
    /* 00 */ MapObject mMapObject;
// Frame of the .nsbtp animation chosen at random by InitTownMonteObjects; frames 0 and 1 also set mSoundId to the first
// and the second sound.
    /* a0 */ u16 mNsbtpFrameIndex;
    /* a2 */ u16 mSoundId;
    /* a4 */ s32 mBounceOffset;
    /* a8 */ s32 mBounceSpeed;
    /* ac */ s32 mMirror;
} TownMonte;


void LoadChandelierMapObject(void *mapObjectList);
MapObjectList *CreateTownMonteUpdateList(void);
MapObjectList *CreateTownMonteDrawList(void);
void UpdateTownMonte(void *mapObjectList,
                     TownMonte *townMonte); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitTownMonteObjects(MapObjectList *mapObjectList);
void DrawTownMonte(void *mapObjectList, TownMonte *townMonte);
// The parameter is the draw group (typed MapObjectModel here); its +0x14 is the callback that runs after the group's
// draw.
void LoadTownMonteMapObject(
    MapObjectList *mapObjectList); /* also stores the hook ResetViewRotatedMatrixAxis1Wrapper in the list */
void ResetViewRotatedMatrixAxis1Wrapper(MapObjectList *mapObjectList);
MapObjectKindData *CreateCourseMapRowKindData(void);
void InitCourseMapRowKindData(MapObject *mapObject);
MapObjectList *CreateAirshipUpdateList(void);
MapObjectList *CreateAirshipDrawList(void);
void UpdateAirship(void *mapObjectList,
                   Airship *airship); /* skipped for objects with mFlags & 4 (parked pool objects) */

extern MapObjectModel *gChandelier;
