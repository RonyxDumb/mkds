#include "Main/Race/results_gp.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "01/code_021804e0.h"
#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/Graphics/message_index.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Race/course_time_text.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Scene/display_settings.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/race.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/System/thread_function_queue.h"
#include "Main/MapObjects/trophy.h"
#include "Main/Race/results_gp_frame_limit.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Menu/txt_system.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Graphics/scene_text.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "gfd_VramTransferManager.h"
#include "code_0212df7c.h"
#include "code_0214a390.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_021458c4.h"
#include "Main/Race/course_list.h"
#include "Main/Race/gp_records_killer.h"

#pragma thumb on

// Sets up the Grand Prix results screen: loads its files and lays out the cup, course and time texts.
void InitResultsGp(void *heap, void *firstOamList, void *secondOamList) {
    s16 timeText[10];
    SceneTextInitParams config;
    ScreenMapFileSet mainScreenMapFileSet;
    u16 playerName[11];
    CellFileSet cellFileSet;
    ScreenMapFileSet subScreenMapFileSet;
    CellFileSet cupNameFileSet;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    DisplaySettings *displaySettings;
    u32 mainObjSize;
    u32 subObjSizeLeft;
    u32 characterIndex;
    u32 labelTableIndex;
    u32 cellFlag;
    s32 index;
    void *message;
    s32 courseIndex;
    s32 loopIndex;
    LabelCanvasEntry *tableEntry;

    labelTableIndex = 0;
    gResultsGp = HeapAlloc(heap, 0x60);
    MemFillWordsByBlock_inline(gResultsGp, 0x60);
    gResultsGp->mOamLists[0] = firstOamList;
    gResultsGp->mOamLists[1] = secondOamList;
    gResultsGp->mCommonMessages = FindFileInLoadedArchives(data_usa_02162138);
    gResultsGp->mSecretMessages = FindSceneFile(gSecretBmgName);
    gResultsGp->mCupIndex = gMenuShared->mCupIndex;
    gResultsGp->mCupRankIndex = gMenuShared->mCupRankIndex;
    if (gResultsGp->mCupRankIndex < 0) {
        gResultsGp->mCupRankIndex = 0;
    }
    gResultsGp->mUnk_44 = gMenuShared->mGrade;
    Init3dEngine();
    displaySettings = CreateDisplaySettings(heap, data_021547f0);
    SetBg1Record(&displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x10, 6, 0);
    SetBg3RecordParams(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 2, 6);
    SetBg3RecordParams(&displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    InitDisplayFromSettings(displaySettings);
    config.mUseTxtSystem = 1;
    config.mTxtSystemFont = GetFontByIndex(1);
    config.mUseCanvas1 = 0;
    config.mUseCanvas2 = 1;
    config.mUseCanvas3 = 0;
    config.mUseSelectChoises = 0;
    config.mSelectChoisesFont = NULL;
    config.mUseSelectReturn = 0;
    config.mUseBackScreen = 0;
    config.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &config);
    LoadAndQueueScreenMapFileSet(0, &mainScreenMapFileSet, gResultsGpMBNcgrName, gResultsGpMBNclrName,
                                 gResultsGpM1NscrName, 1, FindSceneFile);
    LoadNscrData(&mainScreenMapFileSet.mScreenMaps[3], FindSceneFile(gResultsGpM2NscrName));
    NNS_GfdRegisterNewVramTransferTask(0xb, 0, &mainScreenMapFileSet.mScreenMaps[3]->mData,
                                       mainScreenMapFileSet.mScreenMaps[3]->mDataSize);
    mainObjSize = GX_GetSizeOfOBJ();
    mainFileSet = &gResultsGp->mCellFileSets[0];
    LoadCellFileSet(mainFileSet, gResultsGpMNcgrName, gResultsGpMNcerName, gResultsGpMONclrName, gResultsGpMBnclName,
                    gResultsGpMBnllName, NULL, FindSceneFile);
    SetupCellFileSet(0, heap, mainFileSet);
    MIi_CpuCopy16(&gBackupBuffers->mFirstBlock->mPlayerName, playerName, 0x14);
    playerName[10] = 0;
    InitLabelCanvas(heap, 0, mainFileSet->mLabelLayout, 0x82, 0xd, 0x14, mainFileSet->mCells, mainFileSet->mCellLayout,
                    mainFileSet->mCellTable, mainObjSize);
    PrintLabelLayoutTextNoFixedAdvance(0, 0, mainFileSet->mLabelLayout, playerName, mainFileSet->mCellLayout,
                                       mainFileSet->mCellTable);
    SetLabelPriority(0, 1, mainFileSet->mLabelLayout, mainFileSet->mCellTable, mainFileSet->mCellLayout);
    for (index = 0; index < 8; index++) {
        if (index == gResultsGp->mCupRankIndex) {
            cellFlag = 1;
        } else {
            cellFlag = 0;
        }
        mainFileSet->mCellTable[gCupRankCellIndexTable[index]].mVisible = cellFlag;
    }
    for (index = 0; index < 8; index++) {
        if (index == gResultsGp->mUnk_44) {
            cellFlag = 1;
        } else {
            cellFlag = 0;
        }
        mainFileSet->mCellTable[data_usa_02153888[index]].mVisible = cellFlag;
    }
    if (gResultsGp->mCupRankIndex >= 3) {
        cellFlag = 1;
    } else {
        cellFlag = 0;
    }
    mainFileSet->mCellTable[3].mVisible = cellFlag;
    mainFileSet->mCellTable[2].mVisible = mainFileSet->mCellTable[3].mVisible;
    mainFileSet->mCellTable[1].mVisible = (mainFileSet->mCellTable[2].mVisible == 0) ? 1 : 0;
    mainFileSet->mCellTable[0].mVisible = mainFileSet->mCellTable[1].mVisible;
    characterIndex = gMenuShared->mCharacterIndex;
    mainFileSet = &gResultsGp->mCellFileSets[0];
    SetPlayerCharacterCellFileSet(1, &cellFileSet);
    QueueCellCharsAndFirstPalette(characterIndex, cellFileSet.mCells, cellFileSet.mChars, cellFileSet.mPalette,
                                  cellFileSet.mCellLayout, 0, 0x14, mainFileSet->mCells, mainFileSet->mCellLayout);
    LoadAndQueueScreenMapFileSet(1, &subScreenMapFileSet, gResultsGpSBNcgrName, gResultsGpSBNclrName,
                                 gResultsGpSNscrName, 3, FindSceneFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    subFileSet = &gResultsGp->mCellFileSets[1];
    LoadCellFileSet(subFileSet, gResultsGpSNcgrName, gResultsGpSNcerName, gResultsGpSONclrName, gResultsGpSBnclName,
                    gResultsGpSBnllName, NULL, FindSceneFile);
    SetupCellFileSet(1, heap, subFileSet);
    loopIndex = 0;
    tableEntry = data_usa_02153918;
    for (; loopIndex < 16; loopIndex++) {
        subObjSizeLeft -= SetupLabelCanvas(1, heap, subFileSet, tableEntry, subObjSizeLeft);
        tableEntry++;
    }
    message = GetBmgEntry(gResultsGp->mCommonMessages, gEngineMessageIndexTable[gMenuShared->mEngineIndex]);
    for (loopIndex = 0; loopIndex < 2; loopIndex++) {
        PrintLabelLayoutTextNoFixedAdvance(1, data_usa_02153918[labelTableIndex].mLabelIndex, subFileSet->mLabelLayout,
                                           message, subFileSet->mCellLayout, subFileSet->mCellTable);
        labelTableIndex++;
    }
    if (gMenuShared->mMirrorMode != 0) {
        message = GetBmgEntry(gResultsGp->mCommonMessages, 0x71);
        for (loopIndex = 0; loopIndex < 2; loopIndex++) {
            PrintLabelLayoutTextNoFixedAdvance(1, data_usa_02153918[labelTableIndex].mLabelIndex,
                                               subFileSet->mLabelLayout, message, subFileSet->mCellLayout,
                                               subFileSet->mCellTable);
            labelTableIndex++;
        }
    } else {
        labelTableIndex += 2;
    }
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        message = GetBmgEntry(gResultsGp->mCommonMessages,
                              GetCourseMessageIndex(data_usa_02153898[gResultsGp->mCupIndex][courseIndex]));
        PrintLabelLayoutTextNoFixedAdvance(1, data_usa_02153918[labelTableIndex].mLabelIndex, subFileSet->mLabelLayout,
                                           message, subFileSet->mCellLayout, subFileSet->mCellTable);
        labelTableIndex++;
    }
    for (loopIndex = 0; loopIndex < 4; loopIndex++) {
        WriteCourseTimeText(timeText, loopIndex);
        PrintLabelLayoutTextFixedDigits(1, data_usa_02153918[labelTableIndex].mLabelIndex, subFileSet->mLabelLayout,
                                        timeText, subFileSet->mCellLayout, subFileSet->mCellTable, 7);
        PrintLabelLayoutTextFixedDigits(1, data_usa_02153918[labelTableIndex + 4].mLabelIndex, subFileSet->mLabelLayout,
                                        timeText, subFileSet->mCellLayout, subFileSet->mCellTable, 7);
        labelTableIndex++;
    }
    subFileSet = &gResultsGp->mCellFileSets[1];
    LoadCellFileSet(&cupNameFileSet, gCupNameLeftNcgrName, gCupNameLeftNcerName, NULL, gCupNameLeftBnclName, NULL, NULL,
                    FindSceneFile);
    QueueCellChars(data_usa_02153868[gResultsGp->mCupIndex], cupNameFileSet.mCells, cupNameFileSet.mChars,
                   cupNameFileSet.mCellLayout, 1, 0, subFileSet->mCells, subFileSet->mCellLayout);
    InitFrmVramManagers();
    InitTrophy(gResultsGp->mCupIndex, (u16) gResultsGp->mCupRankIndex);
    index = -1;
    switch (gResultsGp->mUnk_44) {
        case 5:
            index = 0x1e;
            break;
        case 6:
            index = 0x1f;
            break;
        case 7:
            index = 0x20;
            break;
    }
    if (index >= 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, (u16) index);
    }
    if (TrySetGrandPrixRecord()) {
        WaitThreadFunctionsDone();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
        gResultsGp->mSecretMessageMask = SetAndWriteSecretMessageFlags();
    }
}

// Draws the Grand Prix results; after a delay and a button press or touch, shows each pending secret message, then
// picks the next scene.
void AdvanceResultsGp(SceneNumbers *sceneNumbers) {
    u32 inputSlotIndex;
    void *secretMessage;
    s32 screenIndex;
    inputSlotIndex = GetPadInputSlot();
    secretMessage = NULL;
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        DrawLayoutTable(gResultsGp->mCellFileSets[screenIndex].mCellLayout,
                        gResultsGp->mCellFileSets[screenIndex].mCells,
                        gResultsGp->mCellFileSets[screenIndex].mLabelLayout, gResultsGp->mOamLists[screenIndex],
                        gResultsGp->mCellFileSets[screenIndex].mCellTable);
    }
    if (gResultsGp->mCupRankIndex < 3) {
        AdvanceTrophy();
        DrawTrophy();
    }
    switch (gResultsGp->mState) {
        case 0: {
            s32 frameLimit;
            s32 frames;
            frameLimit = GetResultsGpFrameLimit(gResultsGp->mCupRankIndex);
            frames = gResultsGp->mState0Frames;
            gResultsGp->mState0Frames = frames + 1;
            if (frames >= frameLimit) {
                void *commonMessage;
                u32 messageMask;
                if (!(u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A)) {
                    BOOL newlyPaired;
                    BOOL recentlyUnpaired;
                    u16 hasPair;
                    newlyPaired = FALSE;
                    recentlyUnpaired = FALSE;
                    hasPair = gInputSlots[inputSlotIndex].mPair.mHasPair;
                    if (hasPair == 0) {
                        if (gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) {
                            recentlyUnpaired = TRUE;
                        }
                    }
                    if (recentlyUnpaired == FALSE) {
                        if (gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0) {
                            if (hasPair != 0) {
                                newlyPaired = TRUE;
                            }
                        }
                    }
                    if (newlyPaired == FALSE) {
                        break;
                    }
                }
                commonMessage = GetBmgEntry(gResultsGp->mCommonMessages, 4);
                messageMask = gResultsGp->mSecretMessageMask;
                if (messageMask != 0) {
                    if (messageMask & 0x1) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 0);
                        gResultsGp->mSecretMessageMask &= ~0x1;
                    } else if (messageMask & 0x2) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 1);
                        gResultsGp->mSecretMessageMask &= ~0x2;
                    } else if (messageMask & 0x4) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 2);
                        gResultsGp->mSecretMessageMask &= ~0x4;
                    } else if (messageMask & 0x8) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 3);
                        gResultsGp->mSecretMessageMask &= ~0x8;
                    } else if (messageMask & 0x10) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 4);
                        gResultsGp->mSecretMessageMask &= ~0x10;
                    } else if (messageMask & 0x20) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 5);
                        gResultsGp->mSecretMessageMask &= ~0x20;
                    } else if (messageMask & 0x40) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 6);
                        gResultsGp->mSecretMessageMask &= ~0x40;
                    } else if (messageMask & 0x80) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 7);
                        gResultsGp->mSecretMessageMask &= ~0x80;
                    } else if (messageMask & 0x100) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 8);
                        gResultsGp->mSecretMessageMask &= ~0x100;
                    } else if (messageMask & 0x200) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 9);
                        gResultsGp->mSecretMessageMask &= ~0x200;
                    } else if (messageMask & 0x400) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 10);
                        gResultsGp->mSecretMessageMask &= ~0x400;
                    } else if (messageMask & 0x800) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 11);
                        gResultsGp->mSecretMessageMask &= ~0x800;
                    }
                    SetTxtSystemOpenSoundId(0x53);
                    SetupTxtSystemSubTextButtonEx(secretMessage, commonMessage, 0, 1, 1, 0);
                    gResultsGp->mState = 1;
                } else {
                    switch (GetStaffRollKindAfterGp()) {
                        case 0:
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 0;
                            }
                            break;
                        case 1:
                            SetupStaffRollRace(0);
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 2;
                            }
                            break;
                        case 2:
                            SetupStaffRollRace(1);
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 2;
                            }
                            break;
                    }
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                    gResultsGp->mState = 2;
                }
            }
        } break;
        case 1:
            if (GetTxtSystemDone()) {
                RequestTxtSystemClose();
                gResultsGp->mState = 0;
            }
            break;
    }
    AdvanceSceneText();
}

#pragma thumb off
