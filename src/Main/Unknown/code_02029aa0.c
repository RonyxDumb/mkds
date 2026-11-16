#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_020019b0.h" // SceneNumbersView
#include "01/code_021804e0.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202a340.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020a23a0.h"
#include "Main/Unknown/code_0210f71c.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
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
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_02016468.h"
#include "code_0212df7c.h"
#include "code_0214a390.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02090354.h"

#pragma thumb on

// Sets up the Grand Prix results screen: loads its files and lays out the cup, course and time texts.
void gpres_init(void *heap, void *firstOamList, void *secondOamList) {
    s16 timeText[10];
    Unk02125de0Arg config;
    ScreenMapFileSet mainScreenMapFileSet;
    u16 playerName[11];
    CellFileSet cellFileSet;
    ScreenMapFileSet subScreenMapFileSet;
    CellFileSet cupNameFileSet;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    Unk02180774 *displaySettings;
    u32 mainObjSize;
    u32 subObjSizeLeft;
    u32 characterIndex;
    u32 labelTableIndex;
    u32 cellFlag;
    s32 i;
    void *message;
    s32 courseIndex;
    s32 j;
    Unk02153918 *tableEntry;

    labelTableIndex = 0;
    gpres_sState = heap_alloc(heap, 0x60);
    MemFillWordsByBlock_inline(gpres_sState, 0x60);
    gpres_sState->mOamLists[0] = firstOamList;
    gpres_sState->mOamLists[1] = secondOamList;
    gpres_sState->mCommonMessages = arc_get2dArcFile(aCommon_bmg_13);
    gpres_sState->mSecretMessages = arc_getSceneArcFile(aSecret_bmg);
    gpres_sState->mCupIndex = gStruct217B488->mCupIndex;
    gpres_sState->mCupRankIndex = gStruct217B488->mCupRankIndex;
    if (gpres_sState->mCupRankIndex < 0) {
        gpres_sState->mCupRankIndex = 0;
    }
    gpres_sState->field44 = gStruct217B488->field80;
    race_initG3d();
    displaySettings = dc_createDisplayConfig(heap, data_021547f0);
    dc_setBg1Config(&displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x10, 6, 0);
    dc_setBg3Config(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 2, 6);
    dc_setBg3Config(&displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    dc_setDisplayConfig(displaySettings);
    config.field0 = 1;
    config.field4 = m2d_getFont(1);
    config.field8 = 0;
    config.fieldC = 1;
    config.field10 = 0;
    config.field14 = 0;
    config.field18 = NULL;
    config.field1C = 0;
    config.field20 = 0;
    config.field24 = 0;
    gmenu_unpackData();
    gmenu_init(heap, &config);
    mutil2_initUnpackBgGraphics(0, &mainScreenMapFileSet, aResults_gp_m_b, aResults_gp_m_0, aResults_gp_m1_, 1,
                  arc_getSceneArcFile);
    g2du_unpackScreenData(&mainScreenMapFileSet.mScreenMaps[3], arc_getSceneArcFile(aResults_gp_m2_));
    NNS_GfdRegisterNewVramTransferTask(0xb, 0, &mainScreenMapFileSet.mScreenMaps[3]->mData,
                    mainScreenMapFileSet.mScreenMaps[3]->mDataSize);
    mainObjSize = GX_GetSizeOfOBJ();
    mainFileSet = &gpres_sState->mCellFileSets[0];
    mutil2_loadUnpackLayout(mainFileSet, aResults_gp_m_n, aResults_gp_m_1, aResults_gp_m_o, aResults_gp_m_2,
                    aResults_gp_m_4, NULL, arc_getSceneArcFile);
    mutil2_initLayout(0, heap, mainFileSet);
    MIi_CpuCopy16(&gSaveData->mFirstBlock->mPlayerName, playerName, 0x14);
    playerName[10] = 0;
    jn_ui_initLabel(heap, 0, mainFileSet->mLabelLayout, 0x82, 0xd, 0x14, mainFileSet->mCells, mainFileSet->mCellLayout,
                    mainFileSet->mCellTable, mainObjSize);
    jn_ui_212426C(0, 0, mainFileSet->mLabelLayout, playerName, mainFileSet->mCellLayout, mainFileSet->mCellTable);
    jn_ui_setLabelPriority(0, 1, mainFileSet->mLabelLayout, mainFileSet->mCellTable, mainFileSet->mCellLayout);
    for (i = 0; i < 8; i++) {
        if (i == gpres_sState->mCupRankIndex) {
            cellFlag = 1;
        } else {
            cellFlag = 0;
        }
        mainFileSet->mCellTable[gCupRankCellIndexTable[i]].mVisible = cellFlag;
    }
    for (i = 0; i < 8; i++) {
        if (i == gpres_sState->field44) {
            cellFlag = 1;
        } else {
            cellFlag = 0;
        }
        mainFileSet->mCellTable[data_02153888[i]].mVisible = cellFlag;
    }
    if (gpres_sState->mCupRankIndex >= 3) {
        cellFlag = 1;
    } else {
        cellFlag = 0;
    }
    mainFileSet->mCellTable[3].mVisible = cellFlag;
    mainFileSet->mCellTable[2].mVisible = mainFileSet->mCellTable[3].mVisible;
    mainFileSet->mCellTable[1].mVisible = (mainFileSet->mCellTable[2].mVisible == 0) ? 1 : 0;
    mainFileSet->mCellTable[0].mVisible = mainFileSet->mCellTable[1].mVisible;
    characterIndex = gStruct217B488->mCharacterIndex;
    mainFileSet = &gpres_sState->mCellFileSets[0];
    mutil2_loadPortraits(1, &cellFileSet);
    QueueCellCharsAndFirstPalette(characterIndex, cellFileSet.mCells, cellFileSet.mChars, cellFileSet.mPalette,
                                  cellFileSet.mCellLayout, 0, 0x14, mainFileSet->mCells, mainFileSet->mCellLayout);
    mutil2_initUnpackBgGraphics(1, &subScreenMapFileSet, aResults_gp_s_b, aResults_gp_s_0, aResults_gp_s_n, 3,
                  arc_getSceneArcFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    subFileSet = &gpres_sState->mCellFileSets[1];
    mutil2_loadUnpackLayout(subFileSet, aResults_gp_s_5, aResults_gp_s_3, aResults_gp_s_o, aResults_gp_s_4,
                    aResults_gp_s_1, NULL, arc_getSceneArcFile);
    mutil2_initLayout(1, heap, subFileSet);
    j = 0;
    tableEntry = data_02153918;
    for (; j < 16; j++) {
        subObjSizeLeft -= mutil2_initLabel(1, heap, subFileSet, tableEntry, subObjSizeLeft);
        tableEntry++;
    }
    message = jn_msg_getMessage(gpres_sState->mCommonMessages, gpres_sCCModeStringIds[gStruct217B488->mEngineIndex]);
    for (j = 0; j < 2; j++) {
        jn_ui_212426C(1, data_02153918[labelTableIndex].field0, subFileSet->mLabelLayout, message,
                      subFileSet->mCellLayout, subFileSet->mCellTable);
        labelTableIndex++;
    }
    if (gStruct217B488->mMirrorMode != 0) {
        message = jn_msg_getMessage(gpres_sState->mCommonMessages, 0x71);
        for (j = 0; j < 2; j++) {
            jn_ui_212426C(1, data_02153918[labelTableIndex].field0, subFileSet->mLabelLayout, message,
                          subFileSet->mCellLayout, subFileSet->mCellTable);
            labelTableIndex++;
        }
    } else {
        labelTableIndex += 2;
    }
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        message = jn_msg_getMessage(gpres_sState->mCommonMessages,
                              mutil2_getCourseNameCommonMsgId(gpres_sCupCourses[gpres_sState->mCupIndex][courseIndex]));
        jn_ui_212426C(1, data_02153918[labelTableIndex].field0, subFileSet->mLabelLayout, message,
                      subFileSet->mCellLayout, subFileSet->mCellTable);
        labelTableIndex++;
    }
    for (j = 0; j < 4; j++) {
        gpres_getCourseTimeAsString(timeText, j);
        jn_ui_2124224(1, data_02153918[labelTableIndex].field0, subFileSet->mLabelLayout, timeText,
                      subFileSet->mCellLayout, subFileSet->mCellTable, 7);
        jn_ui_2124224(1, data_02153918[labelTableIndex + 4].field0, subFileSet->mLabelLayout, timeText,
                      subFileSet->mCellLayout, subFileSet->mCellTable, 7);
        labelTableIndex++;
    }
    subFileSet = &gpres_sState->mCellFileSets[1];
    mutil2_loadUnpackLayout(&cupNameFileSet, aCup_name_lef_2, aCup_name_lef_0, NULL, aCup_name_left_, NULL, NULL,
                    arc_getSceneArcFile);
    jn_ui_fillPlaceholder(gpres_sCupCellIds[gpres_sState->mCupIndex], cupNameFileSet.mCells, cupNameFileSet.mChars,
                   cupNameFileSet.mCellLayout, 1, 0, subFileSet->mCells, subFileSet->mCellLayout);
    race_initResManagement();
    trophy_init(gpres_sState->mCupIndex, (u16) gpres_sState->mCupRankIndex);
    i = -1;
    switch (gpres_sState->field44) {
        case 5:
            i = 0x1e;
            break;
        case 6:
            i = 0x1f;
            break;
        case 7:
            i = 0x20;
            break;
    }
    if (i >= 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) i);
    }
    if (race_saveGpResult()) {
        bgwkr_waitForCompletion();
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
        gpres_sState->mSecretMessageMask = unlock_updateUnlocks();
    }
}

// Draws the Grand Prix results; after a delay and a button press or touch, shows each pending secret message, then
// picks the next scene.
void gpres_update(SceneNumbersView *sceneNumbers) {
    u32 inputSlotIndex;
    void *secretMessage;
    s32 i;
    inputSlotIndex = input_getDirectInputUnitId();
    secretMessage = NULL;
    for (i = 0; i < 2; i++) {
        jn_ui_renderElements(gpres_sState->mCellFileSets[i].mCellLayout, gpres_sState->mCellFileSets[i].mCells,
                        gpres_sState->mCellFileSets[i].mLabelLayout, gpres_sState->mOamLists[i],
                        gpres_sState->mCellFileSets[i].mCellTable);
    }
    if (gpres_sState->mCupRankIndex < 3) {
        trophy_update();
        trophy_render();
    }
    switch (gpres_sState->mState) {
        case 0: {
            s32 frameLimit;
            s32 frames;
            frameLimit = sub_210F71C(gpres_sState->mCupRankIndex);
            frames = gpres_sState->mState0Frames;
            gpres_sState->mState0Frames = frames + 1;
            if (frames >= frameLimit) {
                void *commonMessage;
                u32 messageMask;
                if (!(u16) (gInputUnits[inputSlotIndex].mPressedBits & PAD_KEY_A)) {
                    BOOL y;
                    BOOL x;
                    u16 z;
                    y = FALSE;
                    x = FALSE;
                    z = data_02175674[inputSlotIndex].mPressedBits;
                    if (z == 0) {
                        if (data_02175680[inputSlotIndex].mPressedBits < 5) {
                            x = TRUE;
                        }
                    }
                    if (x == FALSE) {
                        if (data_0217567c[inputSlotIndex].mPressedBits == 0) {
                            if (z != 0) {
                                y = TRUE;
                            }
                        }
                    }
                    if (y == FALSE) {
                        break;
                    }
                }
                commonMessage = jn_msg_getMessage(gpres_sState->mCommonMessages, 4);
                messageMask = gpres_sState->mSecretMessageMask;
                if (messageMask != 0) {
                    if (messageMask & 0x1) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 0);
                        gpres_sState->mSecretMessageMask &= ~0x1;
                    } else if (messageMask & 0x2) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 1);
                        gpres_sState->mSecretMessageMask &= ~0x2;
                    } else if (messageMask & 0x4) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 2);
                        gpres_sState->mSecretMessageMask &= ~0x4;
                    } else if (messageMask & 0x8) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 3);
                        gpres_sState->mSecretMessageMask &= ~0x8;
                    } else if (messageMask & 0x10) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 4);
                        gpres_sState->mSecretMessageMask &= ~0x10;
                    } else if (messageMask & 0x20) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 5);
                        gpres_sState->mSecretMessageMask &= ~0x20;
                    } else if (messageMask & 0x40) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 6);
                        gpres_sState->mSecretMessageMask &= ~0x40;
                    } else if (messageMask & 0x80) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 7);
                        gpres_sState->mSecretMessageMask &= ~0x80;
                    } else if (messageMask & 0x100) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 8);
                        gpres_sState->mSecretMessageMask &= ~0x100;
                    } else if (messageMask & 0x200) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 9);
                        gpres_sState->mSecretMessageMask &= ~0x200;
                    } else if (messageMask & 0x400) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 10);
                        gpres_sState->mSecretMessageMask &= ~0x400;
                    } else if (messageMask & 0x800) {
                        secretMessage = jn_msg_getMessage(gpres_sState->mSecretMessages, 11);
                        gpres_sState->mSecretMessageMask &= ~0x800;
                    }
                    SetTxtSystemOpenSoundId(0x53);
                    gmenu_createSubMessageBoxConfirm(secretMessage, commonMessage, 0, 1, 1, 0);
                    gpres_sState->mState = 1;
                } else {
                    switch (unlock_hasUnlockedTrueStaffRoll()) {
                        case 0:
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 0;
                            }
                            break;
                        case 1:
                            rconf_setupStaffRoll(0);
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 2;
                            }
                            break;
                        case 2:
                            rconf_setupStaffRoll(1);
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 2;
                            }
                            break;
                    }
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                    gpres_sState->mState = 2;
                }
            }
        } break;
        case 1:
            if (GetTxtSystemDone()) {
                RequestTxtSystemClose();
                gpres_sState->mState = 0;
            }
            break;
    }
    gmenu_render();
}

#pragma thumb off
