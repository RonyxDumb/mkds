#include "Main/Menu/select_cup_course.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_reset.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/cup_picture.h"
#include "Main/Menu/select_race_rule.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02119a90.h"

#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/result_archive_path.h"
#include "gfd_VramTransferManager.h"
#include "Main/Race/race_setup.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02119544.h"
#include "Main/Unknown/code_021196f4.h"
#include "Main/Menu/select_cup_course_index.h"
#include "Main/Unknown/code_021196dc.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Menu/cup_mark.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Race/ghost_record_set.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/Unknown/code_02119dfc.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Menu/select_return.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Graphics/layout_rect_table.h"
#include "code_0212df7c.h"
#include "registers.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma thumb on
static inline s32 SelectCupCourseIsPairNewUnlessLost(InputSlotIndex inputIndex) {
    BOOL result;
    BOOL recentlyLost;
    u16 hasPair;

    result = FALSE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[inputIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[inputIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[inputIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        result = TRUE;
    }
    return result;
}

void AdvanceSelectCupCourseState3(void) {
    s32 touchedRectIndex;
    InputSlotIndex inputIndex;
    s16 courseIndex;

    touchedRectIndex = -1;
    inputIndex = UNK_02175628_INDEX_8;
    AdvanceSelectCupCourseIndexChange();
    if (SelectCupCourseIsPairNewUnlessLost(inputIndex) != 0) {
        touchedRectIndex =
            RectTableFindContaining(gSelectCupCourse->mSelectCupMBnbl, gInputSlots[inputIndex].mPair.mPairX,
                                    gInputSlots[inputIndex].mPair.mPairY + 0x20);
    }
    if ((u16) (gInputSlots[inputIndex].mPressedBits & PAD_KEY_B) != 0 ||
        (SelectCupCourseIsPairNewUnlessLost(inputIndex) != 0 &&
         IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[inputIndex].mPair.mPairX,
                                                         gInputSlots[inputIndex].mPair.mPairY) != FALSE)) {
        if (IsSelectCupCourseIndexChangeRunning() == 0) {
            if (gBootInfo->mBootType == 2) {
                SetSelectReturnSoundId(-1);
            } else {
                SetSelectReturnSoundId(0xe);
            }
            RequestSelectCupCourseState8();
            gSelectCupCourse->mResult = 2;
            RequestSelectReturnState3WithSound(0);
        }
        return;
    }
    if ((u32) touchedRectIndex <= 3) {
        courseIndex = gSelectCupCourseRectCourseIndices[touchedRectIndex];
        if (gSelectCupCourse->mIndex == courseIndex) {
            gSelectCupCourse->mHighlightShown = FALSE;
        }
        gSelectCupCourse->mIndex = courseIndex;
        RequestSelectCupCourseState4();
        return;
    }
    if (touchedRectIndex == 4) {
        RequestSelectCupCourseState4();
        return;
    }
    if ((u16) (gInputSlots[inputIndex].mPressedBits & PAD_KEY_A) != 0) {
        RequestSelectCupCourseState4();
        gSelectCupCourse->mHighlightShown = FALSE;
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gSelectCupCourse->mIndex = gSelectCupCourse->mIndex - 1;
        if (gSelectCupCourse->mIndex < 0) {
            gSelectCupCourse->mIndex = 3;
        }
        if (gBootInfo->mBootType != 2) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gSelectCupCourse->mIndex = gSelectCupCourse->mIndex + 1;
        if (gSelectCupCourse->mIndex >= 4) {
            gSelectCupCourse->mIndex = 0;
        }
        if (gBootInfo->mBootType != 2) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    }
}

void AdvanceSelectCupCourseState4(void) {
    AdvanceSelectCupCourseIndexChange();
    if (gSelectCupCourse->mStateFrames == 5) {
        gSelectCupCourse->mHighlightShown = TRUE;
    }
    gSelectCupCourse->mStateFrames++;
    if (gSelectCupCourse->mStateFrames >= 10) {
        if (IsSelectCupCourseIndexChangeRunning() == 0) {
            if (gSelectCupCourse->mMode == 0) {
                SetupGhostRecordSetForCupCourse();
                if (HasNoSelectableGhost() != FALSE) {
                    ReadGhostRecordsForKind(0);
                    RequestSelectCupCourseState5();
                    return;
                }
                SetCourseIdFromSelectCupCourse();
                gSelectCupCourse->mResult = 1;
                RequestSelectCupCourseState8();
                return;
            }
            RequestSelectCupCourseState5();
        }
    }
}

void AdvanceSelectCupCourseState5(void) {
    switch (gSelectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            if (IsSelectChoisesState1NoState0Request() != 0) {
                RequestSelectCupCourseState6();
            }
            break;
        case 2:
            gSelectCupCourse->mStateFrames++;
            if (gSelectCupCourse->mStateFrames >= 0xf) {
                if (IsSelectChoisesState1NoState0Request() != 0 || GetSelectChoisesDone() != 0) {
                    RequestSelectCupCourseState6();
                }
            }
            break;
    }
}

void AdvanceSelectCupCourseState6(void) {
    s32 choiceIndex;

    if (GetSelectChoisesDone() != 0) {
        RequestSelectCupCourseState7();
        if (gBootInfo->mBootType == 2) {
            choiceIndex = GetSelectChoisesIndex();
            switch (choiceIndex) {
                case 0:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 7);
                    break;
                case -1:
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x10);
                    break;
            }
        }
    }
}

void AdvanceSelectCupCourseState7(void) {
    s32 choiceIndex;

    switch (gSelectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            if (IsSelectChoisesState0NoState1Request() != 0) {
                choiceIndex = GetSelectChoisesIndex();
                switch (choiceIndex) {
                    case 0:
                        SetCourseIdFromSelectCupCourse();
                        gSelectCupCourse->mResult = 1;
                        RequestSelectCupCourseState8();
                        break;
                    case -1:
                    case 1:
                        RequestSelectCupCourseState3();
                        break;
                }
            }
            break;
        case 2:
            gSelectCupCourse->mStateFrames++;
            if (gSelectCupCourse->mStateFrames >= 0xf) {
                if (IsSelectChoisesState0NoState1Request() != 0) {
                    choiceIndex = GetSelectChoisesIndex();
                    switch (choiceIndex) {
                        case 0:
                            SetCourseIdFromSelectCupCourse();
                            gSelectCupCourse->mResult = 1;
                            RequestSelectCupCourseState8();
                            if (gBootInfo->mBootType == 2) {
                                SlideOutSelectRaceRuleWait();
                            }
                            break;
                        case -1:
                        case 1:
                            RequestSelectCupCourseState3();
                            break;
                    }
                }
            }
            break;
    }
}

void AdvanceSelectCupCourseState8(void) {
    BOOL movesTaOrVsCells;
    s16 offsetY;
    s32 cellCount;
    s32 cellIndex;

    gSelectCupCourse->mStateFrames++;
    if (gBootInfo->mBootType == 2) {
        return;
    }
    if (gSelectCupCourse->mMode == 0) {
        if (gSelectCupCourse->mResult == 1) {
            if (HasNoSelectableGhost() != FALSE) {
                movesTaOrVsCells = TRUE;
            } else {
                movesTaOrVsCells = FALSE;
            }
        } else {
            movesTaOrVsCells = TRUE;
        }
    } else {
        movesTaOrVsCells = TRUE;
    }
    InterpolateS16(1, 0, 0x100, gSelectCupCourse->mStateFrames, 10);
    offsetY = InterpolateS16(1, 0, -0xc0, gSelectCupCourse->mStateFrames, 10);
    if (movesTaOrVsCells != FALSE) {
        cellCount = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mCount;
        gSelectCupCourse->mBg0Offset = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[cellCount].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[cellCount + 1].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[cellCount + 2].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[cellCount + 3].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[cellCount + 4].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[cellCount + 5].mOffsetY = offsetY;
    }
    if (gSelectCupCourse->mResult != 2) {
        cellCount = gSelectCupCourse->mSelectCupMBncl->mCount;
        gSelectCupCourse->mBg3Offset = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[0x14].mOffsetY = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[0x13].mOffsetY = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[2].mOffsetY = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[1].mOffsetY = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[0].mOffsetY = offsetY - 0x20;
        for (cellIndex = 0; cellIndex < 8; cellIndex++) {
            gSelectCupCourse->mSelectCupMTable[gSelectCupCourseRecordCells[cellIndex]].mOffsetY = offsetY - 0x20;
        }
        offsetY -= 0x20;
        for (cellIndex = 0; cellIndex < 4; cellIndex++) {
            gSelectCupCourse->mSelectCupMTable[gSelectCupCourseLabelCells[cellIndex]].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupMTable[cellCount + gSelectCupCourseLabelIndices[cellIndex]].mOffsetY = offsetY;
        }
    }
}

s32 AdvanceSelectCupCourse(void) {
    s32 rowIndex;
    u16 *screenMap;

    gSelectCupCourse->mState = gSelectCupCourse->mNextState;
    switch (gSelectCupCourse->mState) {
        case 0:
            AdvanceSelectCupCourseState0();
            break;
        case 1:
            AdvanceSelectCupCourseState1();
            break;
        case 2:
            AdvanceSelectCupCourseState2();
            break;
        case 3:
            AdvanceSelectCupCourseState3();
            break;
        case 4:
            AdvanceSelectCupCourseState4();
            break;
        case 5:
            AdvanceSelectCupCourseState5();
            break;
        case 6:
            AdvanceSelectCupCourseState6();
            break;
        case 7:
            AdvanceSelectCupCourseState7();
            break;
        case 8:
            AdvanceSelectCupCourseState8();
            break;
    }
    AdvanceSelectCupCourseHighlight();
    if (gBootInfo->mBootType != 2) {
        if (gSelectCupCourse->mCupPicturePending != FALSE && IsCupPictureReady() != FALSE) {
            screenMap = GetCupPictureNscrData();
            NNS_GfdRegisterNewVramTransferTask(0x1f, 0, GetCupPictureNclrData(), 0xe0);
            NNS_GfdRegisterNewVramTransferTask(0x17, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (rowIndex = 0; rowIndex < 11; rowIndex++) {
                NNS_GfdRegisterNewVramTransferTask(0x1b, ((rowIndex + 8) * 0x20 + 0x16) * 2,
                                                   screenMap + ((rowIndex + 8) * 0x20 + 0x16), 0x14);
            }
            gSelectCupCourse->mCupPicturePending = FALSE;
        }
        DrawLayoutTable(gSelectCupCourse->mSelectCupCourseTaOrVsMBncl, gSelectCupCourse->mSelectCupCourseMNcer,
                        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, gSelectCupCourse->mMainOam,
                        gSelectCupCourse->mSelectCupCourseTaOrVsMTable);
        DrawLayoutTable(gSelectCupCourse->mSelectCupMBncl, gSelectCupCourse->mSelectCupMNcer,
                        gSelectCupCourse->mSelectCupMBnll, gSelectCupCourse->mSubOam,
                        gSelectCupCourse->mSelectCupMTable);
    } else {
        AdvanceSelectRaceRuleWait();
    }
    if (gSelectCupCourse->mState == 8 && gSelectCupCourse->mStateFrames >= 10) {
        return gSelectCupCourse->mResult;
    }
    return 0;
}

void WriteSelectCupCourseBgOffsets(void) {
    reg_G2_BG0OFS = (-gSelectCupCourse->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectCupCourse->mBg3Offset << 16) & 0x1ff0000;
}

void LoadSelectCupGridData(void) {
    Ncgr *selectCupMChars = NULL;
    Unk02021dc8 *selectCupMCells = NULL;
    Nclr *selectCupMOPalette = NULL;
    Ncgr *selectCupSChars = NULL;
    Unk02021dc8 *selectCupSCells = NULL;
    Nclr *selectCupSOPalette = NULL;
    Ncgr *selectCupMBChars = NULL;
    Nscr *selectCupMScreenMap = NULL;
    Nclr *selectCupMBPalette = NULL;

    if (gBootInfo->mBootType != 2) {
        LoadNcgrData(&selectCupMBChars, FindSceneFile(gSelectCupGridMBNcgrName));
        LoadNclrData(&selectCupMBPalette, FindSceneFile(gSelectCupGridMBNclrName));
        LoadNscrData(&selectCupMScreenMap, FindSceneFile(gSelectCupGridMNscrName));
        LoadNcgrData2(&selectCupMChars, FindSceneFile(gSelectCupGridMNcgrName));
        LoadNcerData(&selectCupMCells, FindSceneFile(gSelectCupGridMNcerName));
        LoadNclrData(&selectCupMOPalette, FindSceneFile(gSelectCupGridMONclrName));
        LoadNcgrData2(&selectCupSChars, FindSceneFile(gSelectCupGridSNcgrName));
        LoadNcerData(&selectCupSCells, FindSceneFile(gSelectCupGridSNcerName));
        LoadNclrData(&selectCupSOPalette, FindSceneFile(gSelectCupGridSONclrName));
        LoadSelectCupNameMData();
        LoadCommonCupMarkData();
        LoadTrophyIconData();
    }
}

void LocateAndQueueSelectCupGrid(void) {
    Ncgr *selectCupMChars = NULL;
    Nclr *selectCupMOPalette = NULL;
    Ncgr *selectCupSChars = NULL;
    Nclr *selectCupSOPalette = NULL;
    Ncgr *selectCupMBChars = NULL;
    Nscr *selectCupMScreenMap = NULL;
    Nclr *selectCupMBPalette = NULL;
    u16 *paletteData;

    if (gBootInfo->mBootType == 2) {
        gSelectCupGrid->mSelectCupSBnbl = FindSceneFile(gSelectCupGridSBnblName);
        return;
    }
    LocateNcgr(&selectCupMBChars, FindSceneFile(gSelectCupGridMBNcgrName));
    LocateNclr(&selectCupMBPalette, FindSceneFile(gSelectCupGridMBNclrName));
    LocateNscr(&selectCupMScreenMap, FindSceneFile(gSelectCupGridMNscrName));
    gSelectCupGrid->mSecondScreenMapBuffer = HeapAlloc(gSelectCupGrid->mHeap, 0x800);
    gSelectCupGrid->mSelectCupMBncl = FindSceneFile(gSelectCupGridMBnclName);
    gSelectCupGrid->mSelectCupMBnll = FindSceneFile(gSelectCupGridMBnllName);
    LocateNcgr2(&selectCupMChars, FindSceneFile(gSelectCupGridMNcgrName));
    LocateNcer(&gSelectCupGrid->mSelectCupMNcer, FindSceneFile(gSelectCupGridMNcerName));
    LocateNclr(&selectCupMOPalette, FindSceneFile(gSelectCupGridMONclrName));
    gSelectCupGrid->mSelectCupSBncl = FindSceneFile(gSelectCupGridSBnclName);
    gSelectCupGrid->mSelectCupSBnbl = FindSceneFile(gSelectCupGridSBnblName);
    LocateNcgr2(&selectCupSChars, FindSceneFile(gSelectCupGridSNcgrName));
    LocateNcer(&gSelectCupGrid->mSelectCupSNcer, FindSceneFile(gSelectCupGridSNcerName));
    LocateNclr(&selectCupSOPalette, FindSceneFile(gSelectCupGridSONclrName));
    paletteData = selectCupMOPalette->mData;
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        NNS_GfdRegisterNewVramTransferTask(4, 0, selectCupMBChars->mData, selectCupMBChars->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(0xf, 0, selectCupMBPalette->mData, 0x100);
        NNS_GfdRegisterNewVramTransferTask(8, 0, &selectCupMScreenMap->mData, selectCupMScreenMap->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(8, 0x800, gSelectCupGrid->mSecondScreenMapBuffer, 0x800);
    }
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, selectCupMChars->mData, selectCupMChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, selectCupMOPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, paletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, selectCupSChars->mData, selectCupSChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, selectCupSOPalette->mData, selectCupSOPalette->mDataSize);
}

u32 GetSelectCupGridCupEnabled(u32 cupIndex) {
    u32 enabled;
    s32 flagIndex;

    enabled = 0;
    switch (gSelectCupGrid->mMode) {
        case 0:
        case 2:
            switch (cupIndex) {
                case 0:
                case 1:
                case 4:
                case 5:
                    enabled = 1;
                    break;
                default:
                    if (GetMirrorMode() != 0) {
                        enabled = IsBackupFlagSet(gSelectCupGridMirrorFlagIndices[cupIndex]);
                    } else {
                        enabled = IsBackupFlagSet(
                            gSelectCupGridEngineFlagIndices[cupIndex][gSelectCupGridEngineSlots[GetEngineIndex()]]);
                    }
                    break;
            }
            break;
        case 1:
            switch (cupIndex) {
                case 0:
                case 1:
                case 4:
                case 5:
                    enabled = 1;
                    break;
                default:
                    enabled = 0;
                    for (flagIndex = 0; flagIndex < 4; flagIndex++) {
                        if (flagIndex == 3) {
                            enabled |= IsBackupFlagSet(gSelectCupGridMirrorFlagIndices[cupIndex]);
                        } else {
                            enabled |= IsBackupFlagSet(gSelectCupGridEngineFlagIndices[cupIndex][flagIndex]);
                        }
                    }
                    break;
            }
            break;
        case 3:
            if (cupIndex == 0 || cupIndex == 4) {
                enabled = 1;
            }
            break;
        case 4:
            switch (cupIndex) {
                case 0:
                case 1:
                case 4:
                case 5:
                    enabled = 1;
                    break;
                default:
                    if (GetMirrorMode() != 0) {
                        enabled = IsBitSetInAnyParticipant(gSelectCupGridMirrorFlagIndices[cupIndex]);
                    } else {
                        enabled = IsBitSetInAnyParticipant(
                            gSelectCupGridEngineFlagIndices[cupIndex][gSelectCupGridEngineSlots[GetEngineIndex()]]);
                    }
                    break;
            }
            break;
    }
    return enabled;
}
#pragma thumb off
