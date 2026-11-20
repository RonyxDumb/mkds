#pragma once
#include "types.h"

// One row of the mission file: the mission table value and kind, course, engine, two characters and karts, message
// index, flags and run stem.
typedef struct MissionFileRow {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mMissionTableValue;
    /* 07 */ u8 mMissionKind[0x1];
    /* 08 */ u8 mCourseId;
    /* 09 */ u8 mEngineIndex;
    /* 0a */ u8 mCharacterIndex0;
    /* 0b */ u8 mKartIndex0;
    /* 0c */ u16 mMessageIndex;
    /* 0e */ u8 mUnk_0e[0xe];
    /* 1c */ u16 mFlags;
    /* 1e */ u8 mCharacterIndex1;
    /* 1f */ u8 mKartIndex1;
    /* 20 */ u8 mMissionRunStem[0xc];
} MissionFileRow;

// MissionFileRow.mFlags bit: the mission runs mirrored. A mission has no second kart when
// MissionFileRow.mCharacterIndex1 or mKartIndex1 holds MISSION_FILE_ROW_NO_SECOND_KART.
#define MISSION_FILE_ROW_FLAG_MIRROR 0x10
#define MISSION_FILE_ROW_NO_SECOND_KART 0xff
