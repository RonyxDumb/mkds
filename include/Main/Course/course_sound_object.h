#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Sound/data_0210b000.h" // SoundStartParams
#include "player.h"

// 0x28-byte part at 0xa0 and 0xc8 of CourseSoundObject: the four words at 0x00 go to StartSndHandleSoundUnchecked or
// StartSndHandleSound with the value at 0x1c, 0x0c holds GetHorizontalCameraDistanceSquared's result for the vector at
// 0x10, 0x24 is set to 0, 1 or 2 (UpdateCourseSoundObject); PlaceCourseSoundObjectPartSource writes the vector at 0x10
// and the word at 0x20.
typedef struct CourseSoundObjectPart {
    /* 00 */ SoundStartParams mStartParams;
    /* 10 */ Vec3 mSourcePos;
    /* 1c */ NNSSndSeqPlayer **mSndHandleSlot;
    /* 20 */ BOOL mUnk_20;
    /* 24 */ s32 mInRangeUpdateCount;
} CourseSoundObjectPart;

// Object of UpdateCourseSoundObject: the shared MapObject part, two CourseSoundObjectPart and a value at 0xf0 (0 to 6)
// that selects what UpdateCourseSoundObject does.
typedef struct CourseSoundObject {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ CourseSoundObjectPart mFirstPart;
    /* 0c8 */ CourseSoundObjectPart mSecondPart;
    /* 0f0 */ s32 mState;
} CourseSoundObject;

void UpdateCourseSoundObject(void *mapObjectList, CourseSoundObject *courseSoundObject);

void InitCourseSoundObjects(MapObjectList *mapObjectList);
