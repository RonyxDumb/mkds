#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Sound/sound_distance_squared_change.h" // SoundStartParams
#include "sound_player_control.h"

// Sound ids of the course sound objects: the bank sound, the chain camera sound of the cross course, and the first and
// second part sounds of the cross and mario courses (mFirstPart and mSecondPart).
#define COURSE_SOUND_ID_BANK 0x109
#define COURSE_SOUND_ID_CROSS_CHAIN 0x103
#define COURSE_SOUND_ID_CROSS_FIRST_PART 0x108
#define COURSE_SOUND_ID_CROSS_SECOND_PART 0x107
#define COURSE_SOUND_ID_MARIO_FIRST_PART 0x1a0
#define COURSE_SOUND_ID_MARIO_SECOND_PART 0x19f

// One sound part of a course sound object: its start parameters, source position and camera range state.
typedef struct CourseSoundObjectPart {
    /* 00 */ SoundStartParams mStartParams;
    /* 10 */ Vec3 mSourcePos;
    /* 1c */ NNSSndSeqPlayer **mSndHandleSlot;
    /* 20 */ BOOL mCameraOnOtherSide;
    /* 24 */ s32 mInRangeUpdateCount;
} CourseSoundObjectPart;

// CourseSoundObject.mState values (0 is not used). WAIT_RACE_START to LAST_LAP swap the first part's sound as the race
// starts and on the last lap; the CHAIN states are set while GetRaceUseChainCameras is nonzero.
enum {
    COURSE_SOUND_STATE_WAIT_RACE_START = 1,
    COURSE_SOUND_STATE_RACE,
    COURSE_SOUND_STATE_LAST_LAP,
    COURSE_SOUND_STATE_CHAIN_TWO_PARTS,
    COURSE_SOUND_STATE_CHAIN_ONE_PART,
    COURSE_SOUND_STATE_TWO_PARTS,
};

// Object of UpdateCourseSoundObject: the shared MapObject part, two CourseSoundObjectPart and a state at 0xf0
// that selects what UpdateCourseSoundObject does.
typedef struct CourseSoundObject {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ CourseSoundObjectPart mFirstPart;
    /* 0c8 */ CourseSoundObjectPart mSecondPart;
    /* 0f0 */ s32 mState;
} CourseSoundObject;

void UpdateCourseSoundObject(void *mapObjectList, CourseSoundObject *courseSoundObject);

void InitCourseSoundObjects(MapObjectList *mapObjectList);
