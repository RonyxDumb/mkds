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
#include "Main/Kart/KartTimes.h"

void mpicn_updateItemboxIcon(void) {
    s32 i;
    s32 k;
    s32 n;
    s32 c;
    Unk0217b498_00 *p;
    Vec3 *v;

    n = 0;
    c = mpicn_20C0DB0();
    k = 0;
    for (i = 0; i < mpicn_sItemboxIcon->mObjectCount; i++) {
        if (data_0217b3f8 == 0 ||
            IsRaceHudSubScreenPairNearCenter(&mpicn_sItemboxIcon->fieldC[i]) != FALSE) {
            p = mpicn_sItemboxIcon->mObjects[i];
            if ((p->mFlags & 1) == 0) {
                v = &p->mPos;
                if (lmap_20B5AE8(v, &mpicn_sItemboxIcon->mCells[k].mDrawPos, c, 0, 0) !=
                    FALSE) {
                    mpicn_sItemboxIcon->mCells[k].mCell = r2d_getRaceSCell(0x4e);
                    mpicn_sItemboxIcon->mCells[k].fieldC = m2d_isPointOnLowerMap(v) != 0 ? 2 : 3;
                    mpicn_sItemboxIcon->mCells[k].fieldE = p->mFlags & 0x20;
                    n++;
                    k++;
                }
            }
        }
    }
    mpicn_sItemboxIcon->mCellCount = n;
}

void mpicn_renderItemboxIcon(RaceHudOamBuffer *a) {
    mpicn_renderMObjIcon(a, mpicn_sItemboxIcon, 0);
}

void r2dtar_20C7164(void) {
    u8 minute;
    u8 second;
    u16 millisecond;
    u8 bestMinute;
    u8 bestSecond;
    u16 bestMillisecond;
    s32 j;
    s32 finishMs;
    TimeRecord *record;
    TimeRecord *records;

    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (r2dtar_sStatus == NULL) {
        return;
    }
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
        r2dtar_sStatus->mFinishTimeIsRecord = r2dtar_20C657C(0);
        r2dtar_sStatus->mBestLapIsRecord = r2dtar_20C6428(0);
        return;
    }
    rstat_getDriverTotalTime(Race_GetPlayerId(), &minute, &second, &millisecond);
    records = r2dtar_sStatus->mRecords;
    finishMs = second * 1000 + minute * 60000 + millisecond;
    for (j = 4; j >= 0; j--) {
        record = &records[j];
        if (record->mFilled != 0 &&
            finishMs == record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
            j = 1;
            goto found;
        }
    }
    j = 0;
found:
    r2dtar_sStatus->mFinishTimeIsRecord = j;
    record = &r2dtar_sStatus->mRecords[TIME_RECORD_BEST_LAP];
    r2dtar_sStatus->mBestLapNumber =
        rstat_getDriverBestLapTime(Race_GetPlayerId(), &bestMinute, &bestSecond, &bestMillisecond);
    r2dtar_sStatus->mBestLapIsRecord =
        (bestMinute == record->mMinute && bestSecond == record->mSecond && bestMillisecond == record->mMillisecond) ? 1
                                                                                                                    : 0;
}

s32 IsRaceNewRecordTaFinishRecord(void) {
    return r2dtar_sStatus != NULL ? r2dtar_sStatus->mFinishTimeIsRecord : 0;
}

BOOL IsRaceNewRecordTaFinishRecordFirst(void) {
    if (r2dtar_sStatus != NULL) {
        if (r2dtar_sStatus->mFinishTimeIsRecord != 0) {
            if (r2dtar_sStatus->mFinishRecordIndex == 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return FALSE;
}

s32 IsRaceNewRecordTaBestLapRecord(void) {
    return r2dtar_sStatus != NULL ? r2dtar_sStatus->mBestLapIsRecord : 0;
}
