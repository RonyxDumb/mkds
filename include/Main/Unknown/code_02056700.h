#pragma once

#include "types.h"

typedef struct MissionRecord MissionRecord;

// Two bytes: a flag and a value.
typedef struct UnpackedMissionRecord {
    /* 00 */ u8 mFilled;
    /* 01 */ u8 mValue;
} UnpackedMissionRecord;

// Two bytes and a halfword that rstat_getDriverTotalTime and rstat_getDriverLapTime fill.
typedef struct KartTime {
    /* 00 */ u8 mMinute;
    /* 01 */ u8 mSecond;
    /* 02 */ u16 mMillisecond;
} KartTime;

void savd_loadPersonalGhost(u32 courseId);
void savd_storePersonalGhost(s32 courseId, u16 entryIndex);
void savd_setEmblem(void *emblemData);
s32 savd_getNkmrEntry(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord);
void savd_setNkmrEntry(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord);
void savd_unpackNkmrEntry(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord);
void savd_packNkmrEntry(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord);
