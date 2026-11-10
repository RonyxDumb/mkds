#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/unk_02174000.h"
#include "00/code_02181f98.h"

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
