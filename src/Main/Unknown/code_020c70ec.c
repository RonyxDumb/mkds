#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_0203c5f8.h"

void UpdateRaceHudSubScreenItemBoxCells(void) {
    s32 objectIndex;
    s32 cellIndex;
    s32 cellCount;
    s32 subScreenScale;
    MapObject *mapObject;
    Vec3 *position;

    cellCount = 0;
    subScreenScale = GetRaceHudSubScreenScale();
    cellIndex = 0;
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenItemBoxCells->mObjectCount; objectIndex++) {
        if (data_0217b3f8 == 0 ||
            IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenItemBoxCells->mUnk_0c[objectIndex]) != FALSE) {
            mapObject = gRaceHudSubScreenItemBoxCells->mObjects[objectIndex];
            if ((mapObject->mFlags & 1) == 0) {
                position = &mapObject->mPos;
                if (ComputeRaceHudSubScreenPosition(position,
                                                    &gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mDrawPos,
                                                    subScreenScale, 0, 0) != FALSE) {
                    gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mCell = GetRaceSNcerEntry(0x4e);
                    gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mPriority = IsPositionOutsideBox(position) != 0
                                                                                     ? RACE_HUD_PRIORITY_OUTSIDE_BOX
                                                                                     : RACE_HUD_PRIORITY_INSIDE_BOX;
                    gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mUnk_0e = mapObject->mFlags & 0x20;
                    cellCount++;
                    cellIndex++;
                }
            }
        }
    }
    gRaceHudSubScreenItemBoxCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenItemBoxCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenItemBoxCells, 0);
}

void RefreshRaceNewRecordTaRecordFlags(void) {
    u8 minute;
    u8 second;
    u16 millisecond;
    u8 bestMinute;
    u8 bestSecond;
    u16 bestMillisecond;
    s32 recordIndex;
    s32 finishMs;
    TimeRecord *record;
    TimeRecord *records;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceNewRecordTa == NULL) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        gRaceNewRecordTa->mFinishTimeIsRecord = TryStoreRaceNewRecordTaFinishTime(0);
        gRaceNewRecordTa->mBestLapIsRecord = TryStoreRaceNewRecordTaBestLap(0);
        return;
    }
    GetKartFinishTime(GetFollowedKartOrEntryIndex(), &minute, &second, &millisecond);
    records = gRaceNewRecordTa->mRecords;
    finishMs = second * 1000 + minute * 60000 + millisecond;
    for (recordIndex = 4; recordIndex >= 0; recordIndex--) {
        record = &records[recordIndex];
        if (record->mFilled != 0 &&
            finishMs == record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
            recordIndex = 1;
            goto found;
        }
    }
    recordIndex = 0;
found:
    gRaceNewRecordTa->mFinishTimeIsRecord = recordIndex;
    record = &gRaceNewRecordTa->mRecords[TIME_RECORD_BEST_LAP];
    gRaceNewRecordTa->mBestLapNumber =
        GetKartBestLapTime(GetFollowedKartOrEntryIndex(), &bestMinute, &bestSecond, &bestMillisecond);
    gRaceNewRecordTa->mBestLapIsRecord =
        (bestMinute == record->mMinute && bestSecond == record->mSecond && bestMillisecond == record->mMillisecond) ? 1
                                                                                                                    : 0;
}

s32 IsRaceNewRecordTaFinishRecord(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mFinishTimeIsRecord : 0;
}

BOOL IsRaceNewRecordTaFinishRecordFirst(void) {
    if (gRaceNewRecordTa != NULL) {
        if (gRaceNewRecordTa->mFinishTimeIsRecord != 0) {
            if (gRaceNewRecordTa->mFinishRecordIndex == 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return FALSE;
}

s32 IsRaceNewRecordTaBestLapRecord(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mBestLapIsRecord : 0;
}
