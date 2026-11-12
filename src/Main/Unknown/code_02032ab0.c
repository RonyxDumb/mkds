#include "Main/Unknown/code_02032ab0.h"
#include "Main/Unknown/code_020487fc.h" // SceneNumbers
#include "Main/Unknown/code_0202578c.h"

#include "00/code_021832d8.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_020336ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02033d9c.h"
#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0210f714.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bc8.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_020a23a0.h"
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
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "00/code_0219b580.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02033000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "01/code_021804e0.h"
#include "Main/Unknown/code_0201ea30.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

#pragma thumb on

// Fills with 0 using a volatile halfword.
static inline void ResultsBattleMI_CpuClear16(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    MIi_CpuClear16(fillValue, buffer, byteCount);
}

static inline CourseTeamResult *ResultsBattleGetCourseTeamResult(s32 teamIndex) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[teamIndex];
}

static inline CourseTeamResults *GetCourseTeamResults(void) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()];
}

void InitResultsBattle(void *heap, void *mainOam, void *subOam) {
    DisplaySettings *displaySettings;
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    ResultsBattle *results;
    ScreenMapFileSet *screenMapFileSet;
    LayoutEntryTable *cellLayout;
    u32 remainingObjSize;
    s32 firstTeamScore;
    s32 value;
    s32 orderIndex;
    u16 itemIndex;
    u16 entryIndex;
    u16 entryName[11];
    SceneTextInitParams sceneTextInitParams;
    s32 orderUsed[8];

    gResultsBattle = HeapAlloc(heap, 0x154);
    MemFillWordsByBlock_inline(gResultsBattle, 0x154);
    gResultsBattle->mOamLists[0] = mainOam;
    gResultsBattle->mOamLists[1] = subOam;
    gResultsBattle->mMode = gStartupWork->mConnectionKind;
    if (gResultsBattle->mMode == 3) {
        SetupWiFiSession(3);
    }
    Init3dEngine();
    displaySettings = CreateDisplaySettings(heap, data_021547f0);
    SetBg0Record(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 0xd, 2, 0);
    SetBg1Record(&displaySettings->mMainBgRecords, 0, 0, 0, 0, 0xc, 0, 0);
    SetBg2RecordParams(&displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x1e, 6);
    SetBg3RecordParams(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 0x1d, 6);
    SetBg3RecordParams(&displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    InitDisplayFromSettings(displaySettings);
    sceneTextInitParams.mUseTxtSystem = 0;
    sceneTextInitParams.mTxtSystemFont = NULL;
    sceneTextInitParams.mUseCanvas1 = 0;
    sceneTextInitParams.mUseCanvas2 = 0;
    sceneTextInitParams.mUseCanvas3 = 0;
    sceneTextInitParams.mUseSelectChoises = 1;
    sceneTextInitParams.mSelectChoisesFont = GetFontByIndex(2);
    sceneTextInitParams.mUseSelectReturn = 0;
    sceneTextInitParams.mUseBackScreen = 0;
    sceneTextInitParams.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &sceneTextInitParams);
    InitFrmVramManagers();
    gResultsBattle->mCommonMessages = FindFileInLoadedArchives(gCommonBmgName);
    switch (gResultsBattle->mMode) {
        case 0:
            gResultsBattle->mOwnEntryIndex = 0;
            gResultsBattle->mKartCount = gRaceSetup->mKartCount;
            gResultsBattle->mState = 2;
            break;
        case 1:
        case 2:
            SetSelectChoisesSoundId(1, 0xf);
            gResultsBattle->mOwnEntryIndex =
                GetParticipantPosByIndex(gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0)
                    ->mEntryIndex;
            gResultsBattle->mKartCount = gRaceSetup->mKartCount;
            gResultsBattle->mState = 0;
            break;
        case 3:
            gResultsBattle->mOwnEntryIndex = GetPackedIndex(DWC_GetMyAID());
            gResultsBattle->mKartCount = gWiFiSession->mKartCount;
            gResultsBattle->mUseTimer = TRUE;
            gResultsBattle->mTimer = 0x384;
            gResultsBattle->mState = 2;
            break;
    }
    FillResultsBattleEntries();
    if (gRaceSetup->mUseTeams != 0) {
        firstTeamScore = 0;
        value = 0;
        switch (gRaceSetup->mRuleKind) {
            case 1:
                firstTeamScore = ResultsBattleGetCourseTeamResult(0)->mWinCount;
                value = ResultsBattleGetCourseTeamResult(1)->mWinCount;
                break;
            case 2:
                firstTeamScore = GetCourseTeamResults()->mTeams[0].mTotalPoints;
                value = GetCourseTeamResults()->mTeams[1].mTotalPoints;
                break;
        }
        if (firstTeamScore == value) {
            gResultsBattle->mIconKartCount = gResultsBattle->mKartCount;
            gResultsBattle->mFileSetKind = 2;
        } else if (firstTeamScore > value) {
            gResultsBattle->mIconKartCount = gRaceSetup->mTeamKartCounts[0];
            gResultsBattle->mFileSetKind = 3;
        } else if (value > firstTeamScore) {
            gResultsBattle->mIconKartCount = gRaceSetup->mTeamKartCounts[1];
            gResultsBattle->mFileSetKind = 4;
        }
    } else if (AreResultsBattleRanksAllZero() != 0) {
        gResultsBattle->mIconKartCount = gResultsBattle->mKartCount;
        gResultsBattle->mFileSetKind = 2;
    } else if (gResultsBattle->mEntries[gResultsBattle->mOwnEntryIndex].mRank == 0) {
        gResultsBattle->mFileSetKind = 0;
    } else {
        gResultsBattle->mFileSetKind = 1;
    }
    SetPlayerCharacterCellFileSet(1, &gResultsBattle->mCellFileSets[2]);
    SetPlayerCharacterCellFileSet(0, &gResultsBattle->mCellFileSets[3]);
    gResultsBattle->mCellFileSet2ShyguyPalette = GetPlayerCharacterShyguyNclr(1);
    gResultsBattle->mCellFileSet3ShyguyPalette = GetPlayerCharacterShyguyNclr(0);
    screenMapFileSet = &gResultsBattle->mScreenMapFileSets[0];
    LoadScreenMapFileSet(screenMapFileSet, gResultsBattleVictoryMBNcgrName[gResultsBattle->mFileSetKind][0],
                         gResultsBattleVictoryMBNclrName[gResultsBattle->mFileSetKind][0],
                         gResultsBattleVictoryMLowerNscrName[gResultsBattle->mFileSetKind][0], 3, FindSceneFile);
    LoadNscrData(&screenMapFileSet->mScreenMaps[2],
                 FindSceneFile(gResultsBattleVictoryMUpperNscrName[gResultsBattle->mFileSetKind][0]));
    GX_LoadBG3Char(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    GX_LoadBGPltt(screenMapFileSet->mPalette->mData, 0, 0x140);
    GX_LoadBG2Scr(screenMapFileSet->mScreenMaps[2]->mData, 0, screenMapFileSet->mScreenMaps[2]->mDataSize);
    GX_LoadBG3Scr(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    LoadCellFileSet(mainCellFileSet, gResultsBattleVictoryMNcgrName[gResultsBattle->mFileSetKind][0],
                    gResultsBattleVictoryMNcerName[gResultsBattle->mFileSetKind][0],
                    gResultsBattleVictoryMONclrName[gResultsBattle->mFileSetKind][0],
                    gResultsBattleVictoryMBnclName[gResultsBattle->mFileSetKind][0],
                    gResultsBattleVictoryMBnllName[gResultsBattle->mFileSetKind][0], NULL, FindSceneFile);
    SetupCellFileSet(0, heap, mainCellFileSet);
    switch (gResultsBattle->mFileSetKind) {
        case 0:
            SetupResultsBattleOwnEntry(heap);
            break;
        case 1:
            SetupResultsBattleRankZeroNames(heap);
            break;
        case 2:
            SetupResultsBattleKartIcons(heap);
            break;
        case 3:
        case 4:
            SetupResultsBattleTeamIcons(heap);
            break;
    }
    cellLayout = mainCellFileSet->mCellLayout;
    for (itemIndex = 0; itemIndex < cellLayout->mCount; itemIndex++) {
        GetCellLayoutEntry(mainCellFileSet->mCellLayout, itemIndex);
    }
    screenMapFileSet = &gResultsBattle->mScreenMapFileSets[1];
    LoadScreenMapFileSet(screenMapFileSet, gResultsBattleSBNcgrName, gResultsBattleSBNclrName,
                         gResultsBattleSBgNscrName, 3, FindSceneFile);
    GXS_LoadBG3Char(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    GXS_LoadBGPltt(screenMapFileSet->mPalette->mData, 0, 0x140);
    GXS_LoadBG3Scr(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    remainingObjSize = GX_GetSizeOfSubOBJ();
    results = gResultsBattle;
    subCellFileSet = &results->mCellFileSets[1];
    LoadCellFileSet(subCellFileSet, gResultsBattleSNcgrName, gResultsBattleSNcerName, gResultsBattleSONclrName,
                    gResultsBattleSBnclName, gResultsBattleSBnllName, NULL, FindSceneFile);
    InitLayoutTable(heap, subCellFileSet->mCellLayout, subCellFileSet->mLabelLayout, &subCellFileSet->mCellTable);
    GXS_LoadOBJ(results->mCellFileSets[1].mChars->mData, 0, results->mCellFileSets[1].mChars->mDataSize);
    GXS_LoadOBJPltt(subCellFileSet->mPalette->mData, 0, subCellFileSet->mPalette->mDataSize);
    for (itemIndex = 0; itemIndex < subCellFileSet->mLabelLayout->mCount; itemIndex++) {
        remainingObjSize -= SetupLabelCanvas(1, heap, subCellFileSet, data_02153f00[itemIndex], remainingObjSize);
    }
    for (itemIndex = 0; itemIndex < subCellFileSet->mCellLayout->mCount; itemIndex++) {
        SetCellPriority(itemIndex, 2, subCellFileSet->mCells, subCellFileSet->mCellLayout);
    }
    for (itemIndex = 0; itemIndex < 8; itemIndex++) {
        orderUsed[itemIndex] = 0;
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        orderIndex = gResultsBattle->mEntries[entryIndex].mOrderIndex;
        value = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if ((value == PLAYER_KIND_HUMAN || value == PLAYER_KIND_CPU || value == PLAYER_KIND_PEER) &&
            (gResultsBattle->mMode != 3 || gResultsBattle->mEntries[entryIndex].mScore != 0)) {
            QueueResultsBattleCharacterIcon(1, entryIndex, orderIndex + 0x30, 1);
            ResultsBattleMI_CpuClear16(entryName, 0x16);
            CopyKartEntryName(entryIndex, entryName, 0);
            PrintLabelLayoutTextNoFixedAdvance(1, orderIndex, subCellFileSet->mLabelLayout, entryName,
                                               subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
            PrintResultsBattleScoreAndShowRank(entryIndex);
            SetResultsBattleEntryCellsVisible(entryIndex);
            orderUsed[orderIndex] = 1;
        }
    }
    for (itemIndex = 0; itemIndex < 8; itemIndex++) {
        if (orderUsed[itemIndex] == 0) {
            subCellFileSet->mCellTable[itemIndex + 0x48].mVisible = 0;
            subCellFileSet->mCellTable[itemIndex + 0x30].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x48].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x38].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x30].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x28].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x38].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x20].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x28].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x18].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x20].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x10].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x18].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x08].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x10].mVisible;
            subCellFileSet->mCellTable[itemIndex].mVisible = subCellFileSet->mCellTable[itemIndex + 0x08].mVisible;
        }
    }
    switch (gResultsBattle->mFileSetKind) {
        case 3:
            if (GetCurrentEntry(gResultsBattle->mOwnEntryIndex)->mPlayer.mTeamIndex == 0) {
                value = 0;
            } else {
                value = 7;
            }
            break;
        case 4:
            if (GetCurrentEntry(gResultsBattle->mOwnEntryIndex)->mPlayer.mTeamIndex == 1) {
                value = 0;
            } else {
                value = 7;
            }
            break;
        case 0:
            value = 0;
            break;
        default:
            value = 7;
            break;
    }
    InitTrophy(8, (u16) value);
}

#pragma thumb off

#pragma thumb on

void AdvanceResultsBattle(SceneNumbers *sceneNumbers) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    InputSlotIndex inputSlotIndex;
    s32 shownTimer;
    s32 cellCount;
    void *tensCellLayout;
    void *tensCells;
    void *unitsCellLayout;
    void *unitsCells;
    s32 drawIndex;
    s32 frameLimit;

    subCellFileSet = &gResultsBattle->mCellFileSets[1];
    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    if (gResultsBattle->mUseTimer != FALSE) {
        if (gResultsBattle->mTimer != 0) {
            gResultsBattle->mTimer = gResultsBattle->mTimer - 1;
            shownTimer = (gResultsBattle->mTimer + 0x3c) / 0x3c;
            mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell].mVisible = shownTimer >= 10 ? 1 : 0;
            if (gResultsBattle->mTimer == 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x51);
            } else if ((gResultsBattle->mTimer + 0x3c) % 0x3c == 0 && shownTimer <= 4) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x50);
            }
        } else {
            shownTimer = 0;
        }
        tensCellLayout = mainCellFileSet->mCellLayout;
        tensCells = mainCellFileSet->mCells;
        QueueCellChars(gResultsBattle->mTimerDigitCellBase + (shownTimer / 10) % 10, tensCells, mainCellFileSet->mChars,
                       tensCellLayout, 0, gResultsBattle->mTimerTensCell, tensCells, tensCellLayout);
        unitsCellLayout = mainCellFileSet->mCellLayout;
        unitsCells = mainCellFileSet->mCells;
        QueueCellChars(gResultsBattle->mTimerDigitCellBase + shownTimer % 10, unitsCells, mainCellFileSet->mChars,
                       unitsCellLayout, 0, gResultsBattle->mTimerTensCell + 1, unitsCells, unitsCellLayout);
    } else {
        mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell + 1].mVisible = 0;
        mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell].mVisible =
            mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell + 1].mVisible;
    }
    switch (gResultsBattle->mState) {
        case 0:
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (StartDataSharingSync() == 1) {
                gResultsBattle->mState = 1;
            }
            break;
        case 1:
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (FinishDataSharingSync() == 1) {
                gResultsBattle->mState = 2;
            }
            break;
        case 2:
            frameLimit = GetResultsBattleFrameLimit();
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (gResultsBattle->mState0To2Frames > frameLimit) {
                gResultsBattle->mState0To2Frames = 0;
                gResultsBattle->mState = 3;
            }
            break;
        case 3:
            switch (gResultsBattle->mMode) {
                case 0:
                    if ((u16) (gInputSlots[GetPadInputSlot()].mPressedBits & PAD_KEY_A) != 0) {
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                        if (sceneNumbers != NULL) {
                            sceneNumbers->mNextScene = 1;
                        }
                        gResultsBattle->mState = 7;
                    }
                    break;
                case 1:
                case 2:
                    inputSlotIndex = UNK_02175628_INDEX_8;
                    if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0) {
                        StartResultsBattleChoices();
                        gResultsBattle->mState = 4;
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                    }
                    break;
                case 3:
                    if (IsResultsBattleTimerRunOut() != 0) {
                        SetWiFiSessionOwnContinueChoice(1);
                        gResultsBattle->mState = 5;
                    } else if ((u16) (gInputSlots[GetPadInputSlot()].mPressedBits & PAD_KEY_A) != 0 ||
                               IsResultsBattleTimerBelow300() != 0) {
                        StartResultsBattleChoices();
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                        gResultsBattle->mState = 4;
                    }
                    break;
            }
            break;
        case 4:
            switch (gResultsBattle->mMode) {
                case 1:
                case 2:
                    if (GetSelectChoisesDone() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                if (gStartupWork->mMultiSimple != 0) {
                                    gMenuShared->mWLMenuKind = 3;
                                    gMenuShared->mMenuEntryKind = 4;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mNextScene = 6;
                                    }
                                } else {
                                    gMenuShared->mMenuEntryKind = 4;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mNextScene = 1;
                                    }
                                }
                                gResultsBattle->mState = 7;
                                break;
                            case 1:
                                gConnectionWork->mFlags = gConnectionWork->mFlags | CONNECTION_FLAG_ENDING;
                                gResultsBattle->mState = 6;
                                break;
                            case -1:
                                gResultsBattle->mState = 3;
                                break;
                        }
                        RequestSelectChoisesState0();
                    }
                    break;
                case 3:
                    if (GetSelectChoisesDone() != 0 || IsResultsBattleTimerRunOut() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                gResultsBattle->mState = 5;
                                SetWiFiSessionOwnContinueChoice(1);
                                break;
                            case 1:
                                SetWiFiSessionOwnContinueChoice(0);
                                gMenuShared->mWiFiMenuStartKind = 1;
                                if (sceneNumbers != NULL) {
                                    sceneNumbers->mNextScene = 0xc;
                                }
                                gResultsBattle->mState = 7;
                                break;
                            case -1:
                                gResultsBattle->mState = 3;
                                break;
                        }
                        RequestSelectChoisesState0();
                    }
                    break;
            }
            break;
        case 5:
            if (GetWiFiSessionContinueResult() != 0) {
                switch (GetWiFiSessionContinueResult()) {
                    case 1:
                        gMenuShared->mWiFiMenuStartKind = 2;
                        break;
                    case 2:
                        gMenuShared->mWiFiMenuStartKind = 1;
                        break;
                }
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0xc;
                }
                gResultsBattle->mState = 7;
            }
            break;
        case 6:
            if (AdvanceConnectionEndStopOnError() == 1) {
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0;
                }
                gResultsBattle->mState = 7;
            }
            break;
    }
    AdvanceTrophy();
    DrawTrophy();
    for (drawIndex = 0; drawIndex < 2; drawIndex++) {
        DrawLayoutTable(gResultsBattle->mCellFileSets[drawIndex].mCellLayout,
                        gResultsBattle->mCellFileSets[drawIndex].mCells,
                        gResultsBattle->mCellFileSets[drawIndex].mLabelLayout, gResultsBattle->mOamLists[drawIndex],
                        gResultsBattle->mCellFileSets[drawIndex].mCellTable);
    }
    cellCount = subCellFileSet->mCellLayout->mCount;
    for (drawIndex = 0; drawIndex < 8; drawIndex++) {
        subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY =
            subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY + 1;
        SetLabelPaletteIndex(drawIndex, 0xe, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        DrawLayoutTableEntry(drawIndex + cellCount, subCellFileSet->mCellLayout, subCellFileSet->mCells,
                             subCellFileSet->mLabelLayout, gResultsBattle->mOamLists[1], subCellFileSet->mCellTable);
        SetLabelPaletteIndex(drawIndex, 0xf, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY =
            subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY - 1;
    }
    AdvanceSceneText();
}

void ReleaseResultsBattle(void) {
    gMenuShared->mRaceSetupRequested = 1;
    ReleaseSceneText();
}

#pragma thumb off
