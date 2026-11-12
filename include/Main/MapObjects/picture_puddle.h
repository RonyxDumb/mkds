#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "01/MapObjects/data_0209bc74.h"

// Object of UpdatePicture: after the shared part, a halfword at 0xa0, the phase at 0xa4, a counter at 0xa8 and the
// state at 0xac.
typedef struct Picture {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mNsbcaFrameIndex;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mPictureIndex;
    /* a8 */ s32 mState1Timer;
    /* ac */ s32 mState;
} Picture;

/* kind 0xd objects are MapObject-sized (0xa0) */
void DrawPuddle(void *mapObjectList, MapObject *mapObject);
void SetupDrawPuddle(void *mapObjectList);
void CreatePuddle(void *mapObjectList);
MapObjectList *CreatePictureUpdateList(void);
MapObjectList *CreatePictureDrawList(void);
void UpdatePicture(void *mapObjectList,
                   Picture *picture); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawPicture(void *mapObjectList, Picture *picture);
void CreatePicture1AndPicture2(void *mapObjectList);

extern struct MapObjectModel *gPuddle;
