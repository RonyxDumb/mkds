#include "Main/Unknown/code_02032ab0.h"
#include "Main/Unknown/code_020019b0.h" // SceneNumbersView
#include "Main/Unknown/code_0202578c.h"

#include "00/code_021832d8.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_020336ec.h"
#include "Main/System/Heap.h"
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
#include "Main/Ui/BackScreen.h"
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
#include "Main/Net/WiFiSession.h"
#include "Main/Unknown/code_02125de0.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "01/code_021804e0.h"
#include "code_0201ea30.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

#pragma thumb on

// Fills with 0 through a halfword stack offset of its own.
static inline void func_02032f94_inline(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    MIi_CpuClear16(fillValue, buffer, byteCount);
}

static inline Unk0217aa1c_144_00 *func_02032f94_inline_2(s32 index) {
    return &rres_sRaceResults->mTeamResults[rres_205DB28()].mTeams[index];
}

static inline CourseTeamResults *func_02032f94_inline_3(void) {
    return &rres_sRaceResults->mTeamResults[rres_205DB28()];
}

void bres_init(void *heap, s32 b, s32 c) {
    Unk02180774 *displaySettings;
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    ResultsBattle *results;
    ScreenMapFileSet *screenMapFileSet;
    Unk0201ea30 *cellLayout;
    u32 remainingObjSize;
    s32 j;
    s32 k;
    s32 orderIndex;
    u16 i;
    u16 entryIndex;
    u16 entryName[11];
    Unk02125de0Arg v;
    s32 orderUsed[8];

    bres_sState = heap_alloc(heap, 0x154);
    MemFillWordsByBlock_inline(bres_sState, 0x154);
    bres_sState->mUnk_0b8[0] = b;
    bres_sState->mUnk_0b8[1] = c;
    bres_sState->mMode = gSystemData->mUnk_20;
    if (bres_sState->mMode == 3) {
        SetupWiFiSession(3);
    }
    race_initG3d();
    displaySettings = dc_createDisplayConfig(heap, data_021547f0);
    dc_setBg0Config(displaySettings->mMainBgRecords, 3, 0, 0, 0, 0xd, 2, 0);
    dc_setBg1Config(displaySettings->mMainBgRecords, 0, 0, 0, 0, 0xc, 0, 0);
    dc_setBg2Config(displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x1e, 6);
    dc_setBg3Config(displaySettings->mMainBgRecords, 3, 0, 0, 0, 0x1d, 6);
    dc_setBg3Config(displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    dc_setDisplayConfig(displaySettings);
    v.mUnk_00 = 0;
    v.mUnk_04 = NULL;
    v.mUnk_08 = 0;
    v.mUnk_0c = 0;
    v.mUnk_10 = 0;
    v.mUnk_14 = 1;
    v.mUnk_18 = m2d_getFont(2);
    v.mUnk_1c = 0;
    v.mUnk_20 = 0;
    v.mUnk_24 = 0;
    gmenu_unpackData();
    gmenu_init(heap, &v);
    race_initResManagement();
    bres_sState->mCommonMessages = arc_get2dArcFile(aCommon_bmg_7);
    switch (bres_sState->mMode) {
        case 0:
            bres_sState->mOwnEntryIndex = 0;
            bres_sState->mKartCount = gRaceMultiConfig->mKartCount;
            bres_sState->mState = 2;
            break;
        case 1:
        case 2:
            SetSelectChoisesSoundId(1, 0xf);
            bres_sState->mOwnEntryIndex =
                gStruct217AA00->mUnk_1e52[(u16) (gStruct217AA00->mUnk_0000 == 2 ? gStruct217AA00->mOwnIndex : 0)]
                    .mEntryIndex;
            bres_sState->mKartCount = gRaceMultiConfig->mKartCount;
            bres_sState->mState = 0;
            break;
        case 3:
            bres_sState->mOwnEntryIndex = GetPackedIndex(func_ov000_0219bb50());
            bres_sState->mKartCount = gStruct217D384->mKartCount;
            bres_sState->mUseTimer = TRUE;
            bres_sState->mTimer = 0x384;
            bres_sState->mState = 2;
            break;
    }
    bres_2033E6C();
    if (gRaceMultiConfig->mUseTeams != 0) {
        j = 0;
        k = 0;
        switch (gRaceMultiConfig->mRuleKind) {
            case 1:
                j = func_02032f94_inline_2(0)->mUnk_02;
                k = func_02032f94_inline_2(1)->mUnk_02;
                break;
            case 2:
                j = func_02032f94_inline_3()->mTeams[0].mUnk_00;
                k = func_02032f94_inline_3()->mTeams[1].mUnk_00;
                break;
        }
        if (j == k) {
            bres_sState->mUnk_0d4 = bres_sState->mKartCount;
            bres_sState->mFileSetKind = 2;
        } else if (j > k) {
            bres_sState->mUnk_0d4 = gRaceMultiConfig->mTeamKartCounts[0];
            bres_sState->mFileSetKind = 3;
        } else if (k > j) {
            bres_sState->mUnk_0d4 = gRaceMultiConfig->mTeamKartCounts[1];
            bres_sState->mFileSetKind = 4;
        }
    } else if (bres_2033E24() != 0) {
        bres_sState->mUnk_0d4 = bres_sState->mKartCount;
        bres_sState->mFileSetKind = 2;
    } else if (bres_sState->mEntries[bres_sState->mOwnEntryIndex].mRank == 0) {
        bres_sState->mFileSetKind = 0;
    } else {
        bres_sState->mFileSetKind = 1;
    }
    mutil2_loadPortraits(1, &bres_sState->mCellFileSets[2]);
    mutil2_loadPortraits(0, &bres_sState->mCellFileSets[3]);
    bres_sState->mUnk_0c0 = m2d_getPortraitShyGuyONclr(1);
    bres_sState->mUnk_0c4 = m2d_getPortraitShyGuyONclr(0);
    screenMapFileSet = &bres_sState->mScreenMapFileSets[0];
    mutil2_loadUnpackBgGraphics(screenMapFileSet, data_02153f80[bres_sState->mFileSetKind][0],
                         data_02153f84[bres_sState->mFileSetKind][0], data_02153f8c[bres_sState->mFileSetKind][0],
                         3, arc_getSceneArcFile);
    g2du_unpackScreenData(&screenMapFileSet->mScreenMaps[2], arc_getSceneArcFile(data_02153f88[bres_sState->mFileSetKind][0]));
    GX_LoadBG3Char(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    GX_LoadBGPltt(screenMapFileSet->mPalette->mData, 0, 0x140);
    GX_LoadBG2Scr(screenMapFileSet->mScreenMaps[2]->mData, 0, screenMapFileSet->mScreenMaps[2]->mDataSize);
    GX_LoadBG3Scr(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    mainCellFileSet = &bres_sState->mCellFileSets[0];
    mutil2_loadUnpackLayout(mainCellFileSet, data_02153f90[bres_sState->mFileSetKind][0],
                    data_02153f94[bres_sState->mFileSetKind][0], data_02153f98[bres_sState->mFileSetKind][0],
                    data_02153f9c[bres_sState->mFileSetKind][0], data_02153fa0[bres_sState->mFileSetKind][0],
                    NULL, arc_getSceneArcFile);
    mutil2_initLayout(0, heap, mainCellFileSet);
    switch (bres_sState->mFileSetKind) {
        case 0:
            bres_initVictory(heap);
            break;
        case 1:
            bres_initLose(heap);
            break;
        case 2:
            bres_initDraw(heap);
            break;
        case 3:
        case 4:
            bres_initVSTeams(heap);
            break;
    }
    cellLayout = mainCellFileSet->mCellLayout;
    for (i = 0; i < cellLayout->mUnk_06; i++) {
        jn_ui_getBnclElement(mainCellFileSet->mCellLayout, i);
    }
    screenMapFileSet = &bres_sState->mScreenMapFileSets[1];
    mutil2_loadUnpackBgGraphics(screenMapFileSet, aResults_battle, aResults_batt_0,
                         aResults_batt_1, 3, arc_getSceneArcFile);
    GXS_LoadBG3Char(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    GXS_LoadBGPltt(screenMapFileSet->mPalette->mData, 0, 0x140);
    GXS_LoadBG3Scr(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    remainingObjSize = GX_GetSizeOfSubOBJ();
    results = bres_sState;
    subCellFileSet = &results->mCellFileSets[1];
    mutil2_loadUnpackLayout(subCellFileSet, aResults_batt_4, aResults_batt_5, aResults_batt_6,
                    aResults_batt_2, aResults_batt_3, NULL, arc_getSceneArcFile);
    jn_ui_initLayout(heap, subCellFileSet->mCellLayout, subCellFileSet->mLabelLayout, &subCellFileSet->mCellTable);
    GXS_LoadOBJ(((Ncgr *) results->mCellFileSets[1].mChars)->mData, 0,
                ((Ncgr *) results->mCellFileSets[1].mChars)->mDataSize);
    GXS_LoadOBJPltt(((Nclr *) subCellFileSet->mPalette)->mData, 0, ((Nclr *) subCellFileSet->mPalette)->mDataSize);
    for (i = 0; i < subCellFileSet->mLabelLayout->mUnk_06; i++) {
        remainingObjSize -= mutil2_initLabel(1, heap, subCellFileSet, data_02153f00[i], remainingObjSize);
    }
    for (i = 0; i < subCellFileSet->mCellLayout->mUnk_06; i++) {
        jn_ui_setCellPriority(i, 2, subCellFileSet->mCells, subCellFileSet->mCellLayout);
    }
    for (i = 0; i < 8; i++) {
        orderUsed[i] = 0;
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        orderIndex = bres_sState->mEntries[entryIndex].mOrderIndex;
        k = gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mKind;
        if ((k == PLAYER_KIND_HUMAN || k == PLAYER_KIND_CPU || k == PLAYER_KIND_PEER) &&
            (bres_sState->mMode != 3 || bres_sState->mEntries[entryIndex].mScore != 0)) {
            bres_2033AB8(1, entryIndex, orderIndex + 0x30, 1);
            func_02032f94_inline(entryName, 0x16);
            CopyKartEntryName(entryIndex, entryName, 0);
            jn_ui_212426C(1, orderIndex, subCellFileSet->mLabelLayout, entryName, subCellFileSet->mCellLayout,
                          subCellFileSet->mCellTable);
            bres_2033B80(entryIndex);
            bres_2033C80(entryIndex);
            orderUsed[orderIndex] = 1;
        }
    }
    for (i = 0; i < 8; i++) {
        if (orderUsed[i] == 0) {
            subCellFileSet->mCellTable[i + 0x48].mVisible = 0;
            subCellFileSet->mCellTable[i + 0x30].mVisible = subCellFileSet->mCellTable[i + 0x48].mVisible;
            subCellFileSet->mCellTable[i + 0x38].mVisible = subCellFileSet->mCellTable[i + 0x30].mVisible;
            subCellFileSet->mCellTable[i + 0x28].mVisible = subCellFileSet->mCellTable[i + 0x38].mVisible;
            subCellFileSet->mCellTable[i + 0x20].mVisible = subCellFileSet->mCellTable[i + 0x28].mVisible;
            subCellFileSet->mCellTable[i + 0x18].mVisible = subCellFileSet->mCellTable[i + 0x20].mVisible;
            subCellFileSet->mCellTable[i + 0x10].mVisible = subCellFileSet->mCellTable[i + 0x18].mVisible;
            subCellFileSet->mCellTable[i + 0x08].mVisible = subCellFileSet->mCellTable[i + 0x10].mVisible;
            subCellFileSet->mCellTable[i].mVisible = subCellFileSet->mCellTable[i + 0x08].mVisible;
        }
    }
    switch (bres_sState->mFileSetKind) {
        case 3:
            if (gRaceMultiConfig->mCurrentEntries[(u16) bres_sState->mOwnEntryIndex].mPlayer.mTeamIndex == 0) {
                k = 0;
            } else {
                k = 7;
            }
            break;
        case 4:
            if (gRaceMultiConfig->mCurrentEntries[(u16) bres_sState->mOwnEntryIndex].mPlayer.mTeamIndex == 1) {
                k = 0;
            } else {
                k = 7;
            }
            break;
        case 0:
            k = 0;
            break;
        default:
            k = 7;
            break;
    }
    trophy_init(8, (u16) k);
}

#pragma thumb off

#pragma thumb on

void bres_update(SceneNumbersView *sceneNumbers) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    InputSlotIndex inputSlotIndex;
    s32 shownTimer;
    s32 cellCount;
    void *tensCellLayout;
    void *tensCells;
    void *unitsCellLayout;
    void *unitsCells;
    s32 i;
    s32 frameLimit;

    subCellFileSet = &bres_sState->mCellFileSets[1];
    mainCellFileSet = &bres_sState->mCellFileSets[0];
    if (bres_sState->mUseTimer != FALSE) {
        if (bres_sState->mTimer != 0) {
            bres_sState->mTimer = bres_sState->mTimer - 1;
            shownTimer = (bres_sState->mTimer + 0x3c) / 0x3c;
            mainCellFileSet->mCellTable[bres_sState->mTimerTensCell].mVisible = shownTimer >= 10 ? 1 : 0;
            if (bres_sState->mTimer == 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x51);
            } else if ((bres_sState->mTimer + 0x3c) % 0x3c == 0 && shownTimer <= 4) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x50);
            }
        } else {
            shownTimer = 0;
        }
        tensCellLayout = mainCellFileSet->mCellLayout;
        tensCells = mainCellFileSet->mCells;
        jn_ui_fillPlaceholder(bres_sState->mTimerDigitCellBase + (shownTimer / 10) % 10, tensCells, mainCellFileSet->mChars,
                       tensCellLayout, 0, bres_sState->mTimerTensCell, tensCells, tensCellLayout);
        unitsCellLayout = mainCellFileSet->mCellLayout;
        unitsCells = mainCellFileSet->mCells;
        jn_ui_fillPlaceholder(bres_sState->mTimerDigitCellBase + shownTimer % 10, unitsCells, mainCellFileSet->mChars,
                       unitsCellLayout, 0, bres_sState->mTimerTensCell + 1, unitsCells, unitsCellLayout);
    } else {
        mainCellFileSet->mCellTable[bres_sState->mTimerTensCell + 1].mVisible = 0;
        mainCellFileSet->mCellTable[bres_sState->mTimerTensCell].mVisible =
            mainCellFileSet->mCellTable[bres_sState->mTimerTensCell + 1].mVisible;
    }
    switch (bres_sState->mState) {
        case 0:
            bres_sState->mState0To2Frames = bres_sState->mState0To2Frames + 1;
            if (StartDataSharingSync() == 1) {
                bres_sState->mState = 1;
            }
            break;
        case 1:
            bres_sState->mState0To2Frames = bres_sState->mState0To2Frames + 1;
            if (FinishDataSharingSync() == 1) {
                bres_sState->mState = 2;
            }
            break;
        case 2:
            frameLimit = func_0210f714();
            bres_sState->mState0To2Frames = bres_sState->mState0To2Frames + 1;
            if (bres_sState->mState0To2Frames > frameLimit) {
                bres_sState->mState0To2Frames = 0;
                bres_sState->mState = 3;
            }
            break;
        case 3:
            switch (bres_sState->mMode) {
                case 0:
                    if ((u16) (gInputUnits[input_getDirectInputUnitId()].mPressedBits & PAD_KEY_A) != 0) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        if (sceneNumbers != NULL) {
                            sceneNumbers->mNextScene = 1;
                        }
                        bres_sState->mState = 7;
                    }
                    break;
                case 1:
                case 2:
                    inputSlotIndex = UNK_02175628_INDEX_8;
                    if ((u16) (gInputUnits[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0) {
                        bres_startSelectChoices();
                        bres_sState->mState = 4;
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                    }
                    break;
                case 3:
                    if (bres_2033DFC() != 0) {
                        func_02121dec(1);
                        bres_sState->mState = 5;
                    } else if ((u16) (gInputUnits[input_getDirectInputUnitId()].mPressedBits & PAD_KEY_A) != 0 ||
                               bres_2033DD0() != 0) {
                        bres_startSelectChoices();
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        bres_sState->mState = 4;
                    }
                    break;
            }
            break;
        case 4:
            switch (bres_sState->mMode) {
                case 1:
                case 2:
                    if (GetSelectChoisesDone() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                if (gSystemData->mUnk_1c_2 != 0) {
                                    gStruct217B488->mUnk_74 = 3;
                                    gStruct217B488->mUnk_08 = 4;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mNextScene = 6;
                                    }
                                } else {
                                    gStruct217B488->mUnk_08 = 4;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mNextScene = 1;
                                    }
                                }
                                bres_sState->mState = 7;
                                break;
                            case 1:
                                gStruct217AA00->mUnk_0454 = gStruct217AA00->mUnk_0454 | 0x80;
                                bres_sState->mState = 6;
                                break;
                            case -1:
                                bres_sState->mState = 3;
                                break;
                        }
                        RequestSelectChoisesState0();
                    }
                    break;
                case 3:
                    if (GetSelectChoisesDone() != 0 || bres_2033DFC() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                bres_sState->mState = 5;
                                func_02121dec(1);
                                break;
                            case 1:
                                func_02121dec(0);
                                gStruct217B488->mUnk_1c = 1;
                                if (sceneNumbers != NULL) {
                                    sceneNumbers->mNextScene = 0xc;
                                }
                                bres_sState->mState = 7;
                                break;
                            case -1:
                                bres_sState->mState = 3;
                                break;
                        }
                        RequestSelectChoisesState0();
                    }
                    break;
            }
            break;
        case 5:
            if (func_02121c78() != 0) {
                switch (func_02121c78()) {
                    case 1:
                        gStruct217B488->mUnk_1c = 2;
                        break;
                    case 2:
                        gStruct217B488->mUnk_1c = 1;
                        break;
                }
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0xc;
                }
                bres_sState->mState = 7;
            }
            break;
        case 6:
            if (func_02054f58() == 1) {
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0;
                }
                bres_sState->mState = 7;
            }
            break;
    }
    trophy_update();
    trophy_render();
    for (i = 0; i < 2; i++) {
        jn_ui_renderElements(bres_sState->mCellFileSets[i].mCellLayout, bres_sState->mCellFileSets[i].mCells,
                        bres_sState->mCellFileSets[i].mLabelLayout, (void *) bres_sState->mUnk_0b8[i],
                        bres_sState->mCellFileSets[i].mCellTable);
    }
    cellCount = subCellFileSet->mCellLayout->mUnk_06;
    for (i = 0; i < 8; i++) {
        subCellFileSet->mCellTable[i + cellCount].mOffsetY = subCellFileSet->mCellTable[i + cellCount].mOffsetY + 1;
        jn_ui_setLabelColorParam(i, 0xe, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        jn_ui_renderElement(i + cellCount, subCellFileSet->mCellLayout, subCellFileSet->mCells,
                             subCellFileSet->mLabelLayout, (void *) bres_sState->mUnk_0b8[1],
                             subCellFileSet->mCellTable);
        jn_ui_setLabelColorParam(i, 0xf, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        subCellFileSet->mCellTable[i + cellCount].mOffsetY = subCellFileSet->mCellTable[i + cellCount].mOffsetY - 1;
    }
    gmenu_render();
}

void bres_finalize(void) {
    gStruct217B488->mUnk_04 = 1;
    gmenu_finish();
}

#pragma thumb off
