#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02036000.h"

#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202a820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b47d8.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02025ebc.h"
#include "registers.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma thumb on

void ReleasePlayerEntryList(void) {
    HeapDestroy(gPlayerEntryList->mHeap);
    *&gPlayerEntryList = NULL;
}

#pragma thumb off

#pragma thumb on

void WritePlayerEntryListRegisters(void) {
    u32 displayBits = 0x19;
    BOOL bg0As;
    s16 interpolatedValue;

    interpolatedValue = GetInterpolatedValue(&gPlayerEntryList->mInterpolations[2]);
    if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_RACE_RULE) {
        bg0As = FALSE;
        displayBits |= 2;
        reg_G2_BG0OFS = interpolatedValue & 0x1ff;
        reg_G2_BG1OFS = -interpolatedValue & 0x1ff;
        reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
        reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    } else {
        bg0As = TRUE;
    }
    if (gPlayerEntryList->mMode == 2) {
        displayBits |= 2;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    GX_SetGraphicsMode(1, 0, bg0As);
    if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_RACE_RULE) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x6000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1d) | 0x20;
        reg_G2_WININ = (u32) ((reg_G2_WININ & 0xffffc0ff) | 0x1e00) | 0x2000;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0x1c) | 0x20;
        reg_G2_WIN0H = 0x80;
        reg_G2_WIN0V = 0xc0;
        reg_G2_WIN1H = 0x8000;
        reg_G2_WIN1V = 0xc0;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    }
}

void LoadPlayerEntryListFiles(void) {
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMap;

    if (gBootInfo->mBootType == 2) {
        LoadNcgrData(&chars, FindSceneFile(gSelectMenuEtcDownloadMBNcgrName));
        LoadNcgrData2(&chars, FindSceneFile(gSelectMenuEtcDownloadMNcgrName));
        LoadNcerData(&cells, FindSceneFile(gSelectMenuEtcDownloadMNcerName));
        LoadNclrData(&palette, FindSceneFile(gSelectMenuEtcDownloadMONclrName));
        LoadNclrData(&palette, FindSceneFile(gSelectMenuEtcDownloadMBNclrName));
        LoadNscrData(&screenMap, FindSceneFile(gSelectMenuEtcDownloadMBg00NscrName));
        LoadNscrData(&screenMap, FindSceneFile(gSelectMenuEtcDownloadMBg01NscrName));
    } else {
        LoadNcgrData(&chars, FindFileInLoadedArchives(gSelectMenuEtcMBNcgrName));
        LoadNcgrData2(&chars, FindFileInLoadedArchives(gSelectMenuEtcMNcgrName));
        LoadNcgrData2(&chars, FindFileInLoadedArchives(gSelectMenuEtcTitleMNcgrName));
        LoadNcerData(&cells, FindFileInLoadedArchives(gSelectMenuEtcMNcerName));
        LoadNcerData(&cells, FindFileInLoadedArchives(gSelectMenuEtcTitleMNcerName));
        LoadNclrData(&palette, FindFileInLoadedArchives(gSelectMenuEtcMONclrName));
        LoadNclrData(&palette, FindFileInLoadedArchives(gSelectMenuEtcMBNclrName));
        LoadNscrData(&screenMap, FindFileInLoadedArchives(gSelectMenuEtcMBg00NscrName));
        LoadNscrData(&screenMap, FindFileInLoadedArchives(gSelectMenuEtcMBg01NscrName));
    }
}

#pragma thumb off

#pragma thumb on

u32 IsPlayerEntryListTimerZero(void) {
    if (gPlayerEntryList->mTimer == 0) {
        return 1;
    }
    return 0;
}

u32 IsEveryPlayerKartStored(void) {
    u32 allKartsStored;
    int index;
    int offset;
    RaceSetupCopy *setupCopy;
    allKartsStored = 1;
    index = 0;
    if (0 < gPlayerEntryList->mPlayerCount) {
        offset = 0;
        do {
            setupCopy = GetRaceSetupCopy();
            allKartsStored = allKartsStored & setupCopy->mEntries[index].mKartStored;
            offset = offset + 0x18;
            index = index + 1;
        } while (index < gPlayerEntryList->mPlayerCount);
    }
    return allKartsStored;
}

#pragma thumb off

#pragma thumb on

void StartPlayerEntryListKind(s32 kind) {
    s32 entryIndex;

    SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[0], 2);
    SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[3], 2);
    SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[2], 2);
    switch (kind) {
        case 0:
        case 1:
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                if (entryIndex < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mShowAllEntries != 0) {
                    SetEntryTargetSlot(entryIndex, 1);
                }
            }
            break;
        case 2:
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[1], 2);
            break;
        case 3:
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                SetEntryTargetOuterSlot(entryIndex);
            }
            gPlayerEntryList->mMoveInnerPending = TRUE;
            break;
    }
}

void SetPlayerEntryListUseTeams(s32 useTeams) {
    s32 entryIndex;
    s32 slot;

    if (gPlayerEntryList->mUseTeams != useTeams) {
        if (useTeams != 0) {
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                if (entryIndex < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mShowAllEntries != 0) {
                    if (gPlayerEntryList->mEntries[entryIndex].mTeamIndex == 0) {
                        slot = 1;
                    } else if (gPlayerEntryList->mEntries[entryIndex].mTeamIndex == 1) {
                        slot = 2;
                    }
                    SetEntryTargetSlot(entryIndex, slot);
                }
            }
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[2], 0);
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[0], 2);
        } else {
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                if (entryIndex < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mShowAllEntries != 0) {
                    SetEntryTargetSlot(entryIndex, 1);
                }
            }
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[2], 2);
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[0], 0);
        }
    }
    gPlayerEntryList->mUseTeams = useTeams;
}

#pragma thumb off

#pragma thumb on

void SetEntryTeamIndex(int entryIndex, int teamIndex) {
    u32 slot;
    if ((gPlayerEntryList->mUseTeams != 0) && (teamIndex != gPlayerEntryList->mEntries[entryIndex].mTeamIndex)) {
        if (teamIndex == 1) {
            slot = 2;
        } else {
            slot = 1;
        }
        SetEntryTargetSlot(entryIndex, slot);
    }
    gPlayerEntryList->mEntries[entryIndex].mTeamIndex = teamIndex;
}

#pragma thumb off

#pragma thumb on

void SetPlayerEntryListShowAllEntries(s32 showAll) {
    s32 entryIndex;
    s32 slot;
    if (gPlayerEntryList->mShowAllEntries != showAll) {
        if (showAll != 0) {
            for (entryIndex = gPlayerEntryList->mPlayerCount; entryIndex < 8; entryIndex++) {
                if (gPlayerEntryList->mUseTeams != 0) {
                    if (gPlayerEntryList->mEntries[entryIndex].mTeamIndex == 1) {
                        slot = 3;
                    } else {
                        slot = 0;
                    }
                } else {
                    slot = 0;
                }
                SetEntrySlot(entryIndex, slot);
                SetEntryTargetInnerSlot(entryIndex);
            }
        } else {
            for (entryIndex = gPlayerEntryList->mPlayerCount; entryIndex < 8; entryIndex++) {
                SetEntryTargetOuterSlot(entryIndex);
            }
        }
    }
    gPlayerEntryList->mShowAllEntries = showAll;
}

#pragma thumb off

#pragma thumb on
void RequestPlayerEntryListSetup(void) {
    gPlayerEntryList->mSetupRequested = TRUE;
}
#pragma thumb off
