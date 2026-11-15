#include "Main/Race/grand_prix_record.h"
#include "Main/Race/race_end_condition.h"
#include "cpu_copy_fill.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/results_gp.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Save/backup_mission_records.h"
#include "Main/Save/backup_records_write.h"
#include "Main/Save/mission_record.h"
#include "Main/Save/grand_prix_record_get.h"
#include "Main/Net/mp.h"
#include "Main/Race/cup_records.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Net/pending_files.h"
#include "Main/Race/kart.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u8 gCupRankTable[8] = {0, 1, 2, 3, 3, 3, 3, 3};

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
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, record->mName, sizeof(record->mName));
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
    if (newRecord->mCupRank == CUP_RANK_NO_TROPHY) {
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
    storedTimeMs = TIME_TO_MS(storedRecord->mMinute, storedRecord->mSecond, storedRecord->mMillisecond);
    newTimeMs = TIME_TO_MS(newRecord->mMinute, newRecord->mSecond, newRecord->mMillisecond);
    return storedTimeMs > newTimeMs;
}

BOOL TrySetGrandPrixRecord(void) {
    TimeRecord storedRecord;
    TimeRecord newRecord;
    BOOL stored = FALSE;
    s32 engineClass;
    MenuShared *menuShared = gMenuShared;
    switch (menuShared->mEngineIndex) {
        case ENGINE_CLASS_SLOW:
            engineClass = stored;
            break;
        case ENGINE_CLASS_MEDIUM:
            engineClass = 1;
            break;
        case ENGINE_CLASS_FAST:
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
    endKind = (endKind != 0) ? gRaceProgress->mEntryEndKind : RACE_END_KIND_NOT_ENDED;
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

void InitWLMenuRequestMPWaitRaceArchives(void *heap) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        InitBlockEntries(heap, 1);
    }
    RequestMPWaitRaceArchivesForNextRace();
}

void InitWLMenuRequestMPWaitResultArchives(void *heap) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        InitBlockEntries(heap, 1);
    }
    RequestMPWaitResultArchives();
}

void InitWLMenuRequestMPWaitMenuArchives(void *heap) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        InitBlockEntries(heap, 1);
    }
    RequestMPWaitMenuArchives();
}

void InitWLMenuResetRaceSetup(void *heap) {
    void *bannerFile = NULL;
    s32 connectionKind;
    u32 kindIsOneOrTwo;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        InitBlockEntries(heap, 1);
    } else {
        bannerFile = FindSceneFile("/banner.bmg");
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
