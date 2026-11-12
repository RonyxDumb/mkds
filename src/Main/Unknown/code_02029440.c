#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0202993c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122794.h"
#include "00/code_02181f98.h"

#pragma thumb on

void CreateRaceSetupCopy(void *heap) {
    u32 setupCopyAddress;
    setupCopyAddress = ((u32) HeapAlloc(heap, (0x00000110u)));
    *(u32 *) &gRaceSetupCopy = setupCopyAddress;
    ResetRaceSetupCopy();
}

#pragma thumb off

void RaceSetupCopyMI_CpuFillFast(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void RaceSetupCopyMI_CpuClearFast(void *destination, u32 size) {
    RaceSetupCopyMI_CpuFillFast(destination, 0, size);
}

u32 RaceSetupCopyGetConnectionKind(void) {
    return (gStartupWork->mConnectionKind);
}

#pragma optimize_for_size on
u16 *RaceSetupCopyMB_GetMultiBootParam(void) {
    return &gBootInfo->mBootType;
}

u32 RaceSetupCopyMB_IsMultiBootChild(void) {
    if (*RaceSetupCopyMB_GetMultiBootParam() == 2) {
        return 1;
    }
    return 0;
}

u32 RaceSetupCopyMB_IsMultiBootChildWrapper(void) {
    return RaceSetupCopyMB_IsMultiBootChild();
}

#pragma thumb on

void ResetRaceSetupCopy(void) {
    s32 entryIndex;
    RaceSetupCopyMI_CpuClearFast(gRaceSetupCopy, 0x110);
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        gRaceSetupCopy->mEntries[entryIndex].mCharacterIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mKartIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mPlayerKind = 4;
        gRaceSetupCopy->mEntries[entryIndex].mTeamIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mListedCpuSlot = 3;
    }
    gRaceSetupCopy->mMissionTableRow = 1;
    gRaceSetupCopy->mMissionTableColumn = 1;
    if (RaceSetupCopyGetConnectionKind() == 0) {
        if (RaceSetupCopyMB_IsMultiBootChildWrapper() == 0) {
            gRaceSetupCopy->mMissionFile = FindSceneFile(gMissionMrName);
        } else {
            gRaceSetupCopy->mMissionFile = NULL;
        }
        if (gRaceSetupCopy->mMissionFile != NULL) {
            gRaceSetupCopy->mMissionFileRows = (MissionFileRow *) (gRaceSetupCopy->mMissionFile + 8);
        } else {
            gRaceSetupCopy->mMissionFileRows = NULL;
        }
    }
}
#pragma thumb off

#pragma thumb on

RaceSetupCopy *GetRaceSetupCopy(void) {
    return gRaceSetupCopy;
}

#pragma thumb off

void WiFiSetNextCpuDifficulty(u32 cpuDifficulty) {
    gRaceSetup->mNextHeader.mCpuDifficulty = cpuDifficulty;
}

void WiFiSetNextMode(u32 mode) {
    gRaceSetup->mNextHeader.mMode = mode;
}

void WiFiSetNextCourseId(u32 courseId) {
    gRaceSetup->mNextHeader.mCourseId = courseId;
}

void WiFiSetNextEngineIndex(u32 engineIndex) {
    gRaceSetup->mNextHeader.mEngineIndex = engineIndex;
}

void WiFiSetNextMirrorMode(u32 mirrorMode) {
    gRaceSetup->mNextHeader.mMirrorMode = (u8) mirrorMode;
}

void WiFiSetNextUseTeams(u32 useTeams) {
    gRaceSetup->mNextHeader.mUseTeams = useTeams;
}

void WiFiSetNextRuleKind(u32 ruleKind) {
    gRaceSetup->mNextHeader.mRuleKind = ruleKind;
}

void WiFiSetNextCourseListMode(u32 courseListMode) {
    gRaceSetup->mNextHeader.mCourseListMode = courseListMode;
}

#pragma optimize_for_size on

#pragma thumb on

void SetNextRaceSetupFromKartMask(void) {
    u16 packedIndex;
    u16 nextEntryIndex = 0;
    u8 kartMask;
    u8 index;
    WiFiSetNextCpuDifficulty(0);
    for (packedIndex = 0; packedIndex < 4; packedIndex++) {
        if (GetKartMaskBitOfPackedIndex(packedIndex) != 0) {
            SetNextRaceEntry(nextEntryIndex, gRaceSetupCopy->mEntries[packedIndex].mCharacterIndex,
                             gRaceSetupCopy->mEntries[packedIndex].mKartIndex,
                             gRaceSetupCopy->mEntries[packedIndex].mPlayerKind, -1, 3);
            nextEntryIndex++;
        }
    }
    for (; nextEntryIndex < 8; nextEntryIndex++) {
        SetNextRaceEntry(nextEntryIndex, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
    WiFiSetNextMode(5);
    WiFiSetNextCourseId(gRaceSetupCopy->mCourseId);
    WiFiSetNextEngineIndex(1);
    WiFiSetNextMirrorMode(0);
    WiFiSetNextUseTeams(0);
    WiFiSetNextRuleKind(0);
    WiFiSetNextCourseListMode(0);
    kartMask = 0;
    for (index = 0; index < 4; index++) {
        if (GetKartMaskBit(index) != 0) {
            kartMask |= 1 << index;
        }
    }
    SetParticipantKartMapFromMask(kartMask);
}

void CopyRaceSetupCopyToEntries(void) {
    u8 packedIndex;
    s32 index;
    for (packedIndex = 0; packedIndex < 4; packedIndex++) {
        if (GetKartMaskBitOfPackedIndex(packedIndex) != 0) {
            index = GetIndexOfPackedIndex(packedIndex);
            gMenuShared->mEntries[index].mCharacterIndex = gRaceSetupCopy->mEntries[packedIndex].mCharacterIndex;
            gMenuShared->mEntries[index].mKartIndex = gRaceSetupCopy->mEntries[packedIndex].mKartIndex;
            gMenuShared->mEntries[index].mPlayerKind = gRaceSetupCopy->mEntries[packedIndex].mPlayerKind;
        }
    }
}

void CopyEntriesToRaceSetupCopy(void) {
    u8 index;
    s32 packedIndex;
    for (index = 0; index < 4; index++) {
        if (GetKartMaskBit(index) != 0) {
            packedIndex = GetPackedIndex(index);
            gRaceSetupCopy->mEntries[packedIndex].mCharacterIndex = gMenuShared->mEntries[index].mCharacterIndex;
            gRaceSetupCopy->mEntries[packedIndex].mKartIndex = gMenuShared->mEntries[index].mKartIndex;
            gRaceSetupCopy->mEntries[packedIndex].mPlayerKind = gMenuShared->mEntries[index].mPlayerKind;
        }
    }
}

#pragma thumb off

#pragma thumb on

u32 GetCourseId(void) {
    return (gRaceSetupCopy->mCourseId);
}

u32 GetCharacterIndex(u16 entryIndex) {
    return (gRaceSetupCopy->mEntries[entryIndex].mCharacterIndex);
}

u32 GetKartIndex(u16 entryIndex) {
    return (gRaceSetupCopy->mEntries[entryIndex].mKartIndex);
}

u32 GetPlayerKind(u16 entryIndex) {
    return (gRaceSetupCopy->mEntries[entryIndex].mPlayerKind);
}

u32 GetEngineIndex(void) {
    return (gRaceSetupCopy->mEngineIndex);
}

u32 GetCupIndex(void) {
    return (gRaceSetupCopy->mCupIndex);
}

u32 GetMirrorMode(void) {
    return (gRaceSetupCopy->mMirrorMode);
}

u32 GetCpuDifficulty(void) {
    return (gRaceSetupCopy->mCpuDifficulty);
}

u32 GetCourseListMode(void) {
    return (gRaceSetupCopy->mCourseListMode);
}

u32 GetRaceSetupCopyCourseCount(void) {
    return (gRaceSetupCopy->mCourseCount);
}

u32 GetRuleKind(void) {
    return (gRaceSetupCopy->mRuleKind);
}

u32 GetUseTeams(void) {
    return (gRaceSetupCopy->mUseTeams);
}

u32 GetTeamIndex(u16 entryIndex) {
    return (gRaceSetupCopy->mEntries[entryIndex].mTeamIndex);
}

u32 GetMissionTableRow(void) {
    return (gRaceSetupCopy->mMissionTableRow);
}

u32 GetMissionTableColumn(void) {
    return (gRaceSetupCopy->mMissionTableColumn);
}

u32 GetRaceSetupCopyEntryIndex(void) {
    return (gRaceSetupCopy->mEntryIndex);
}

u32 GetSessionKartCount(void) {
    return (gRaceSetupCopy->mSessionKartCount);
}

void SetEngineIndex(u32 engineIndex) {
    gRaceSetupCopy->mEngineIndex = engineIndex;
}

void SetMirrorMode(void) {
    gRaceSetupCopy->mMirrorMode = 1;
}

void ClearMirrorMode(void) {
    gRaceSetupCopy->mMirrorMode = 0;
}

void SetCupIndex(u32 cupIndex) {
    gRaceSetupCopy->mCupIndex = cupIndex;
}

void SetCourseId(u32 courseId) {
    gRaceSetupCopy->mCourseId = courseId;
}

void SetCpuDifficulty(u32 cpuDifficulty) {
    gRaceSetupCopy->mCpuDifficulty = cpuDifficulty;
}

void SetCourseListMode(u32 courseListMode) {
    gRaceSetupCopy->mCourseListMode = courseListMode;
}

void SetRaceSetupCopyCourseCount(u16 courseCount) {
    gRaceSetupCopy->mCourseCount = courseCount;
}

void SetRuleKind(u32 ruleKind) {
    gRaceSetupCopy->mRuleKind = ruleKind;
}

void SetUseTeams(void) {
    gRaceSetupCopy->mUseTeams = 1;
}

void ClearUseTeams(void) {
    gRaceSetupCopy->mUseTeams = 0;
}

#pragma thumb off

#pragma thumb on

void SetTeamIndex(u16 entryIndex, u32 teamIndex) {
    gRaceSetupCopy->mEntries[entryIndex].mTeamIndex = teamIndex;
}

void SetCharacterIndex(u16 entryIndex, u32 characterIndex) {
    gRaceSetupCopy->mEntries[entryIndex].mCharacterIndex = characterIndex;
}

void SetKartIndex(u16 entryIndex, u32 kartIndex) {
    gRaceSetupCopy->mEntries[entryIndex].mKartIndex = kartIndex;
}

void SetPlayerKind(u16 entryIndex, u32 playerKind) {
    gRaceSetupCopy->mEntries[entryIndex].mPlayerKind = playerKind;
}

void SetListedCpuSlot(u16 entryIndex, u32 cpuSlot) {
    gRaceSetupCopy->mEntries[entryIndex].mListedCpuSlot = cpuSlot;
}

void SetKartStored(u16 entryIndex, u32 kartStored) {
    gRaceSetupCopy->mEntries[entryIndex].mKartStored = kartStored;
}

#pragma thumb off

#pragma thumb on

void SetRaceSetupCopyGhostRecordIndex(u32 ghostRecordIndex) {
    gRaceSetupCopy->mGhostRecordIndex = ghostRecordIndex;
}

void SetMissionTableRow(u32 missionTableRow) {
    gRaceSetupCopy->mMissionTableRow = (u8) missionTableRow;
}

void SetMissionTableColumn(u32 missionTableColumn) {
    gRaceSetupCopy->mMissionTableColumn = (u8) missionTableColumn;
}

void SetMissionFileRowIndex(u32 missionFileRowIndex) {
    gRaceSetupCopy->mMissionFileRowIndex = missionFileRowIndex;
}

void SetRaceSetupCopyEntryIndex(u32 entryIndex) {
    gRaceSetupCopy->mEntryIndex = entryIndex;
}

void SetSessionKartCount(u32 sessionKartCount) {
    gRaceSetupCopy->mSessionKartCount = sessionKartCount;
}

#pragma thumb off
