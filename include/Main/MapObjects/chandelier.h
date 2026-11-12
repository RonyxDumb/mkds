#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectKindData
#include "01/MapObjects/data_0209bc74.h"
#include "Main/MapObjects/airship_draw.h" // Airship

// Object of kind 0x157 (TownMonte) with the MapObject base: two halfwords at 0xa0 and 0xa2, then three words
// (UpdateTownMonte, InitTownMonteObjects, DrawTownMonte).
typedef struct TownMonte {
    /* 00 */ MapObject mMapObject;
// Frame of the .nsbtp animation chosen at random by InitTownMonteObjects; frames 0 and 1 also set mUnk_a2 to 0x1a7
// and 0x1a8.
    /* a0 */ u16 mNsbtpFrameIndex;
    /* a2 */ u16 mSoundId;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mMirror;
} TownMonte;

extern char gChandelierNsbmdName[];
extern char gChandelierNsbcaName[];
extern char gTownMonteNsbmdName[];
extern char gTownMonteNsbtpName[];
extern void *gTownMonte;
extern MapObjectKindData *gCourseMapRowKindData[19];

void CreateChandelier(void *mapObjectList);
void *CreateTownMonteUpdateList(void);
void *CreateTownMonteDrawList(void);
void UpdateTownMonte(void *mapObjectList,
                     TownMonte *townMonte); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitTownMonteObjects(MapObjectList *mapObjectList);
void DrawTownMonte(void *mapObjectList, TownMonte *townMonte);
// The parameter is the draw group (typed MapObjectModel here); its +0x14 is the callback that runs after the group's
// draw.
void CreateTownMonte(
    MapObjectList *mapObjectList); /* also stores the hook ResetViewRotatedMatrixAxis1Wrapper in the list */
void ResetViewRotatedMatrixAxis1Wrapper(MapObjectList *mapObjectList);
void CreateCourseMapRowKindData(void);
void InitCourseMapRowKindData(MapObject *mapObject);
void *CreateAirshipUpdateList(void);
void *CreateAirshipDrawList(void);
void UpdateAirship(void *mapObjectList,
                   Airship *airship); /* skipped for objects with mFlags & 4 (parked pool objects) */
