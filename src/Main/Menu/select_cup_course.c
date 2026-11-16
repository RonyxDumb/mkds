#include "Main/Menu/select_cup_course.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_reset.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/cup_picture.h"
#include "Main/Menu/select_race_rule.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/select_cup_name_files.h"
#include "Main/Menu/select_cup_course_index.h"

#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/result_archive_path.h"
#include "vram_transfer_queue.h"
#include "Main/Race/race_setup.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/cup_mark.h"
#include "Main/Race/ghost_record_set.h"
#include "Main/Menu/trophy_icon.h"
#include "Main/System/input_slots.h"
#include "Main/Menu/kart_icon_row.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "sound_archive_load_result.h"
#include "registers.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/select_cup_grid.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on
SelectCupCourse *gSelectCupCourse;

static inline s32 SelectCupCourseIsPairNewUnlessLost(InputSlotIndex inputIndex) {
    BOOL result;
    BOOL recentlyLost;
    u16 hasPair;

    result = FALSE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[inputIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[inputIndex].mPair.mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[inputIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        result = TRUE;
    }
    return result;
}

void AdvanceSelectCupCoursePickCourse(void) {
    s32 touchedRectIndex;
    InputSlotIndex inputIndex;
    s16 courseIndex;

    touchedRectIndex = -1;
    inputIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    AdvanceSelectCupCourseIndexChange();
    if (SelectCupCourseIsPairNewUnlessLost(inputIndex) != 0) {
        touchedRectIndex =
            RectTableFindContaining(gSelectCupCourse->mSelectCupMBnbl, gInputSlots[inputIndex].mPair.mPairX,
                                    gInputSlots[inputIndex].mPair.mPairY + 0x20);
    }
    if ((u16) (gInputSlots[inputIndex].mPressedBits & PAD_KEY_B) != 0 ||
        (SelectCupCourseIsPairNewUnlessLost(inputIndex) != 0 &&
         IsSelectReturnShownNoRequestAndInRect(gInputSlots[inputIndex].mPair.mPairX,
                                               gInputSlots[inputIndex].mPair.mPairY) != FALSE)) {
        if (IsSelectCupCourseIndexChangeRunning() == 0) {
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                SetSelectReturnSoundId(-1);
            } else {
                SetSelectReturnSoundId(0xe);
            }
            RequestSelectCupCourseSlideOut();
            gSelectCupCourse->mResult = MENU_SCREEN_RESULT_BACK;
            RequestSelectReturnPressWithSound(0);
        }
        return;
    }
    if ((u32) touchedRectIndex <= 3) {
        courseIndex = gSelectCupCourseRectCourseIndices[touchedRectIndex];
        if (gSelectCupCourse->mIndex == courseIndex) {
            gSelectCupCourse->mHighlightShown = FALSE;
        }
        gSelectCupCourse->mIndex = courseIndex;
        RequestSelectCupCourseWaitPicked();
        return;
    }
    if (touchedRectIndex == 4) {
        RequestSelectCupCourseWaitPicked();
        return;
    }
    if ((u16) (gInputSlots[inputIndex].mPressedBits & PAD_KEY_A) != 0) {
        RequestSelectCupCourseWaitPicked();
        gSelectCupCourse->mHighlightShown = FALSE;
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_UP) != 0) {
        gSelectCupCourse->mIndex = gSelectCupCourse->mIndex - 1;
        if (gSelectCupCourse->mIndex < 0) {
            gSelectCupCourse->mIndex = 3;
        }
        if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_DOWN) != 0) {
        gSelectCupCourse->mIndex = gSelectCupCourse->mIndex + 1;
        if (gSelectCupCourse->mIndex >= 4) {
            gSelectCupCourse->mIndex = 0;
        }
        if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    }
}

void AdvanceSelectCupCourseWaitPicked(void) {
    AdvanceSelectCupCourseIndexChange();
    if (gSelectCupCourse->mStateFrames == SELECT_CUP_COURSE_HIGHLIGHT_STEP) {
        gSelectCupCourse->mHighlightShown = TRUE;
    }
    gSelectCupCourse->mStateFrames++;
    if (gSelectCupCourse->mStateFrames >= SELECT_CUP_COURSE_CONFIRM_STEPS) {
        if (IsSelectCupCourseIndexChangeRunning() == 0) {
            if (gSelectCupCourse->mMode == SELECT_CUP_COURSE_MODE_WITH_GHOSTS) {
                SetupGhostRecordSetForCupCourse();
                if (HasNoSelectableGhost() != FALSE) {
                    ReadGhostRecordsForKind(0);
                    RequestSelectCupCourseWaitChoices();
                    return;
                }
                SetCourseIdFromSelectCupCourse();
                gSelectCupCourse->mResult = 1;
                RequestSelectCupCourseSlideOut();
                return;
            }
            RequestSelectCupCourseWaitChoices();
        }
    }
}

void AdvanceSelectCupCourseWaitChoices(void) {
    switch (gSelectCupCourse->mMode) {
        case SELECT_CUP_COURSE_MODE_WITH_GHOSTS:
        case SELECT_CUP_COURSE_MODE_NO_CONNECTION:
        case SELECT_CUP_COURSE_MODE_MULTI_OTHER:
            if (IsSelectChoisesChooseNoRequest() != 0) {
                RequestSelectCupCourseChoose();
            }
            break;
        case SELECT_CUP_COURSE_MODE_MULTI_SIMPLE:
            gSelectCupCourse->mStateFrames++;
            if (gSelectCupCourse->mStateFrames >= SELECT_CUP_COURSE_MULTI_SIMPLE_WAIT_FRAMES) {
                if (IsSelectChoisesChooseNoRequest() != 0 || GetSelectChoisesDone() != 0) {
                    RequestSelectCupCourseChoose();
                }
            }
            break;
    }
}

void AdvanceSelectCupCourseChoose(void) {
    s32 choiceIndex;

    if (GetSelectChoisesDone() != 0) {
        RequestSelectCupCourseCloseChoices();
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
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

void AdvanceSelectCupCourseCloseChoices(void) {
    s32 choiceIndex;

    switch (gSelectCupCourse->mMode) {
        case SELECT_CUP_COURSE_MODE_WITH_GHOSTS:
        case SELECT_CUP_COURSE_MODE_NO_CONNECTION:
        case SELECT_CUP_COURSE_MODE_MULTI_OTHER:
            if (IsSelectChoisesHiddenNoRequest() != 0) {
                choiceIndex = GetSelectChoisesIndex();
                switch (choiceIndex) {
                    case 0:
                        SetCourseIdFromSelectCupCourse();
                        gSelectCupCourse->mResult = 1;
                        RequestSelectCupCourseSlideOut();
                        break;
                    case -1:
                    case 1:
                        RequestSelectCupCoursePickCourse();
                        break;
                }
            }
            break;
        case SELECT_CUP_COURSE_MODE_MULTI_SIMPLE:
            gSelectCupCourse->mStateFrames++;
            if (gSelectCupCourse->mStateFrames >= SELECT_CUP_COURSE_MULTI_SIMPLE_WAIT_FRAMES) {
                if (IsSelectChoisesHiddenNoRequest() != 0) {
                    choiceIndex = GetSelectChoisesIndex();
                    switch (choiceIndex) {
                        case 0:
                            SetCourseIdFromSelectCupCourse();
                            gSelectCupCourse->mResult = 1;
                            RequestSelectCupCourseSlideOut();
                            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                                SlideOutSelectRaceRuleWait();
                            }
                            break;
                        case -1:
                        case 1:
                            RequestSelectCupCoursePickCourse();
                            break;
                    }
                }
            }
            break;
    }
}

void AdvanceSelectCupCourseSlideOut(void) {
    BOOL movesTaOrVsCells;
    s16 offsetY;
    s32 cellCount;
    s32 cellIndex;

    gSelectCupCourse->mStateFrames++;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    if (gSelectCupCourse->mMode == SELECT_CUP_COURSE_MODE_WITH_GHOSTS) {
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
    if (gSelectCupCourse->mResult != MENU_SCREEN_RESULT_BACK) {
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
        case SELECT_CUP_COURSE_STATE_WAIT_FADE:
            AdvanceSelectCupCourseWaitFade();
            break;
        case SELECT_CUP_COURSE_STATE_SLIDE_IN:
            AdvanceSelectCupCourseSlideIn();
            break;
        case SELECT_CUP_COURSE_STATE_WAIT_RETURN:
            AdvanceSelectCupCourseWaitReturn();
            break;
        case SELECT_CUP_COURSE_STATE_PICK_COURSE:
            AdvanceSelectCupCoursePickCourse();
            break;
        case SELECT_CUP_COURSE_STATE_CONFIRM_PICK:
            AdvanceSelectCupCourseWaitPicked();
            break;
        case SELECT_CUP_COURSE_STATE_WAIT_CHOICES:
            AdvanceSelectCupCourseWaitChoices();
            break;
        case SELECT_CUP_COURSE_STATE_CHOOSE:
            AdvanceSelectCupCourseChoose();
            break;
        case SELECT_CUP_COURSE_STATE_CLOSE_CHOICES:
            AdvanceSelectCupCourseCloseChoices();
            break;
        case SELECT_CUP_COURSE_STATE_SLIDE_OUT:
            AdvanceSelectCupCourseSlideOut();
            break;
    }
    AdvanceSelectCupCourseHighlight();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        if (gSelectCupCourse->mCupPicturePending != FALSE && IsCupPictureReady() != FALSE) {
            screenMap = GetCupPictureNscrData();
            NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG_PALETTE, 0, GetCupPictureNclrData(), 0xe0);
            NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_TILES, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (rowIndex = 0; rowIndex < 11; rowIndex++) {
                NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_MAP, ((rowIndex + 8) * 0x20 + 0x16) * 2,
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
    if (gSelectCupCourse->mState == SELECT_CUP_COURSE_STATE_SLIDE_OUT &&
        gSelectCupCourse->mStateFrames >= SELECT_CUP_COURSE_SLIDE_STEPS) {
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
    NNSG2dCellDataBank *selectCupMCells = NULL;
    Nclr *selectCupMOPalette = NULL;
    Ncgr *selectCupSChars = NULL;
    NNSG2dCellDataBank *selectCupSCells = NULL;
    Nclr *selectCupSOPalette = NULL;
    Ncgr *selectCupMBChars = NULL;
    Nscr *selectCupMScreenMap = NULL;
    Nclr *selectCupMBPalette = NULL;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
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

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        gSelectCupGrid->mSelectCupSBnbl = FindSceneFile(gSelectCupGridSBnblName);
        return;
    }
    LocateNcgr(&selectCupMBChars, FindSceneFile(gSelectCupGridMBNcgrName));
    LocateNclr(&selectCupMBPalette, FindSceneFile(gSelectCupGridMBNclrName));
    LocateNscr(&selectCupMScreenMap, FindSceneFile(gSelectCupGridMNscrName));
    gSelectCupGrid->mSecondScreenMapBuffer = HeapAlloc(gSelectCupGrid->mHeap, SECOND_SCREEN_MAP_BYTES);
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
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_TILES, 0, selectCupMBChars->mData,
                                           selectCupMBChars->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG_PALETTE, 0, selectCupMBPalette->mData, 0x100);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_MAP, 0, &selectCupMScreenMap->mData,
                                           selectCupMScreenMap->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_MAP, 0x800, gSelectCupGrid->mSecondScreenMapBuffer,
                                           SECOND_SCREEN_MAP_BYTES);
    }
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_TILES, 0, selectCupMChars->mData,
                                       selectCupMChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0, selectCupMOPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0x1c0, paletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_TILES, 0, selectCupSChars->mData,
                                       selectCupSChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, 0, selectCupSOPalette->mData,
                                       selectCupSOPalette->mDataSize);
}

u32 GetSelectCupGridCupEnabled(u32 cupIndex) {
    u32 enabled;
    s32 flagIndex;

    enabled = 0;
    switch (gSelectCupGrid->mMode) {
        case SELECT_CUP_GRID_MODE_SHOW_RECORDS:
        case SELECT_CUP_GRID_MODE_NO_CONNECTION:
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
        case SELECT_CUP_GRID_MODE_NO_RECORDS:
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
        case SELECT_CUP_GRID_MODE_MULTI_SIMPLE:
            if (cupIndex == 0 || cupIndex == 4) {
                enabled = 1;
            }
            break;
        case SELECT_CUP_GRID_MODE_MULTI_OTHER:
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
