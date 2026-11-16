#pragma once

#include "types.h"

typedef struct MissionRecord MissionRecord;

// Two bytes: a flag and a value.
typedef struct UnpackedMissionRecord {
    /* 00 */ u8 mFilled;
    /* 01 */ u8 mValue;
} UnpackedMissionRecord;

// Two bytes and a halfword that GetPlayerTotalTime and MaybeGetPlayerLapTime fill.
typedef struct KartTime {
    /* 00 */ u8 mMinute;
    /* 01 */ u8 mSecond;
    /* 02 */ u16 mMillisecond;
} KartTime;

void ReadCourseGhostRecord(u32 courseId);
void FillPersonalGhostData_from_thumb(s32 courseId, u16 entryIndex);
void SetEmblemRecordAndWriteBackup(void *emblemData);
s32 GetMissionLevelStageInfoByIds_from_thumb(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord);
void SetMissionLevelStageInfoFromIds_from_thumb(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord);
void GetMissionLevelStageInfo_from_thumb(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord);
void SetMissionLevelStageInfo_from_thumb(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord);
