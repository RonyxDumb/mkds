#include "Main/Race/grand_prix_record.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Net/race_mp_state16.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Save/backup_mission_records.h"
#include "Main/Save/backup_records_write.h"
#include "Main/Save/mission_record.h"
#include "Main/Save/grand_prix_record_get.h"
#include "Main/Unknown/code_02056b08.h"
#include "Main/Net/mp.h"
#include "Main/Race/cup_records.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/race_entries.h"
#include "Main/Net/pending_files.h"
#include "Main/Race/kart.h"

void SumTimes(TimeRecord *firstTime, MinuteSecondMillisecondTime *secondTime, TimeRecord *sum) {
    u16 milliseconds = firstTime->mMillisecond + secondTime->mMillisecond;
    u16 minutes = firstTime->mMinute + secondTime->mMinute;
    u16 seconds = firstTime->mSecond + secondTime->mSecond;
    u16 carry = milliseconds / 1000;
    if (carry != 0) {
        seconds += carry;
        milliseconds -= carry * 1000;
    }
    carry = seconds / 60;
    if (carry != 0) {
        minutes += carry;
        seconds -= carry * 60;
    }
    if (minutes > 99) {
        minutes = 99;
    }
    sum->mMinute = minutes;
    sum->mSecond = seconds;
    sum->mMillisecond = milliseconds;
}

void FillGrandPrixRecord(TimeRecord *record) {
    u8 courseIndex;
    record->mMinute = 0;
    record->mSecond = 0;
    record->mMillisecond = 0;
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, record->mName, 0x14);
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        SumTimes(record, &gMenuShared->mCourseTimes[courseIndex], record);
    }
    record->mCharacterIndex = gMenuShared->mCharacterIndex;
    record->mKartIndex = gMenuShared->mKartIndex;
    record->mUnk_1b = 0;
    record->mCupRank = gCupRankTable[gMenuShared->mCupRankIndex];
    record->mTotalPoints = gMenuShared->mTotalPoints;
    record->mGrade = gMenuShared->mGrade;
    record->mFilled = 1;
}

BOOL ShouldSetGrandPrixRecord(TimeRecord *storedRecord, TimeRecord *newRecord) {
    s32 storedTimeMs;
    s32 newTimeMs;
    if (newRecord->mCupRank == 3) {
        return FALSE;
    }
    if (storedRecord->mFilled == 0) {
        return TRUE;
    }
    if (storedRecord->mCupRank > newRecord->mCupRank) {
        return TRUE;
    }
    if (storedRecord->mCupRank < newRecord->mCupRank) {
        return FALSE;
    }
    if (storedRecord->mGrade < newRecord->mGrade) {
        return TRUE;
    }
    if (storedRecord->mGrade > newRecord->mGrade) {
        return FALSE;
    }
    if (storedRecord->mTotalPoints < newRecord->mTotalPoints) {
        return TRUE;
    }
    if (storedRecord->mTotalPoints > newRecord->mTotalPoints) {
        return FALSE;
    }
    storedTimeMs = storedRecord->mSecond * 1000 + storedRecord->mMinute * 60000 + storedRecord->mMillisecond;
    newTimeMs = newRecord->mSecond * 1000 + newRecord->mMinute * 60000 + newRecord->mMillisecond;
    return storedTimeMs > newTimeMs;
}

BOOL TrySetGrandPrixRecord(void) {
    TimeRecord storedRecord;
    TimeRecord newRecord;
    BOOL stored = FALSE;
    s32 engineClass;
    MenuShared *menuShared = gMenuShared;
    switch (menuShared->mEngineIndex) {
        case 0:
            engineClass = stored;
            break;
        case 1:
            engineClass = 1;
            break;
        case 2:
            engineClass = (menuShared->mMirrorMode != 0) ? 3 : 2;
            break;
    }
    GetGrandPrixRecord(menuShared->mCupIndex, engineClass, &storedRecord);
    FillGrandPrixRecord(&newRecord);
    if (ShouldSetGrandPrixRecord(&storedRecord, &newRecord) != FALSE) {
        SetGrandPrixRecord(gMenuShared->mCupIndex, engineClass, &newRecord);
        WriteBackupGrandPrixRecords();
        stored = TRUE;
    }
    return stored;
}

u32 TrySetMissionRecord(void) {
    UnpackedMissionRecord storedRecord;
    UnpackedMissionRecord newRecord;
    u32 stored = 0;
    s32 missionRow;
    s32 missionColumn;
    s32 endKind;
    BOOL shouldStore;
    missionRow = (gRaceSetup->mMode == MODE_MISSION_RUN) ? gRaceSetup->mMissionTableRow : -1;
    missionColumn = (gRaceSetup->mMode == MODE_MISSION_RUN) ? gRaceSetup->mMissionTableColumn : -1;
    endKind = IsKartEnded((u16) gRaceSetup->mEntryIndex);
    endKind = (endKind != 0) ? gRaceProgress->mEntryEndKind : 6;
    if (endKind != 0) {
        return 0;
    }
    GetMissionRecord((u16) missionRow, (u16) missionColumn, &storedRecord);
    newRecord.mFilled = 1;
    newRecord.mValue = ComputeMissionRecordValue();
    if (storedRecord.mFilled == 0) {
        shouldStore = TRUE;
    } else {
        shouldStore = storedRecord.mValue < newRecord.mValue;
    }
    if (shouldStore != FALSE) {
        SetMissionRecord((u16) missionRow, (u16) missionColumn, &newRecord);
        WriteBackupMissionRecords();
        stored = 1;
    }
    return stored;
}

void InitWLMenuRequestMPState16(void *heap) {
    if (gBootInfo->mBootType == 2) {
        InitBlockEntries(heap, 1);
    }
    RequestMPState16ForNextRace();
}

void InitWLMenuRequestMPState18(void *heap) {
    if (gBootInfo->mBootType == 2) {
        InitBlockEntries(heap, 1);
    }
    RequestMPState18();
}

void InitWLMenuRequestMPState21(void *heap) {
    if (gBootInfo->mBootType == 2) {
        InitBlockEntries(heap, 1);
    }
    RequestMPState21();
}

void InitWLMenuResetRaceSetup(void *heap) {
    void *bannerFile = NULL;
    s32 connectionKind;
    u32 kindIsOneOrTwo;
    if (gBootInfo->mBootType == 2) {
        InitBlockEntries(heap, 1);
    } else {
        bannerFile = FindSceneFile(data_usa_0216478c);
    }
    connectionKind = gStartupWork->mConnectionKind;
    kindIsOneOrTwo = 1;
    if (connectionKind != 1 && connectionKind != 2) {
        kindIsOneOrTwo = 0;
    }
    if (kindIsOneOrTwo != 0) {
        AllocConnectionBuffers(heap, connectionKind == 1, bannerFile);
        InitMPChunkBuffers(heap);
    }
    ResetRaceSetup();
}

BOOL IsDateEarlier(const DateBytes *firstDate, const DateBytes *secondDate) {
    if (firstDate->mYear < secondDate->mYear) {
        return TRUE;
    }
    if (firstDate->mYear > secondDate->mYear) {
        return FALSE;
    }
    if (firstDate->mMonth < secondDate->mMonth) {
        return TRUE;
    }
    if (firstDate->mMonth > secondDate->mMonth) {
        return FALSE;
    }
    return firstDate->mDay < secondDate->mDay;
}
