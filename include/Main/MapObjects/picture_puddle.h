#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "01/MapObjects/map_object_model.h"

// Values of Picture.mState: IDLE does nothing and nothing leaves it; WAIT counts mWaitFrames down, then PLAY; PLAY
// steps the animation, plays its sounds and goes back to WAIT with a new mWaitFrames when the frame index is 0 again.
enum {
    PICTURE_STATE_IDLE,
    PICTURE_STATE_WAIT,
    PICTURE_STATE_PLAY,
};

// A picture map object: its animation frame, picture index, wait frames and state.
typedef struct Picture {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mNsbcaFrameIndex;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mPictureIndex;
    /* a8 */ s32 mWaitFrames;
    /* ac */ s32 mState;
} Picture;

/* kind 0xd objects are MapObject-sized (0xa0) */
void DrawPuddle(void *mapObjectList, MapObject *mapObject);
void SetupDrawPuddle(void *mapObjectList);
void CreatePuddle(void *mapObjectList);
MapObjectList *CreatePictureUpdateList(void);
MapObjectList *CreatePictureDrawList(void);
void UpdatePicture(void *mapObjectList,
                   Picture *picture); /* skipped for objects with MAP_OBJECT_FLAG_NO_UPDATE set (parked ones) */
void DrawPicture(void *mapObjectList, Picture *picture);
void CreatePicture1AndPicture2(void *mapObjectList);

extern struct MapObjectModel *gPuddle;
