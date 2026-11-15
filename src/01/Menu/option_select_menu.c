#include "01/Menu/option_select_menu.h"
#include "01/Menu/option_hensyu_menu.h"
#include "01/Menu/nickname_scene.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "01/Menu/option_nickname_scenes.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/palette_blend.h"
#include "01/Menu/option_states.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "code_02148950.h"
#include "Main/Graphics/layout_rect_table.h"
#include "g2.h"
#include "registers.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u8 gOptionSelectMenuMLabelIndices[2] = {0, 1};
const u8 gOptionSelectMenuXluCellIndices[2] = {0, 1};
const u8 gOptionSelectMenuRowSTableIndices[3] = {5, 6, 7};
const u8 gOptionSelectMenuOffsetMIndices[1] = {0};
const u8 gOptionSelectMenuValueCounts[3] = {3, 2, 0};
const u8 gOptionSelectMenuSLabelIndices[3] = {0, 1, 2};
const u8 gOptionSelectMenuValueSTableIndices[3][3] = {{0x14, 0x15, 0x16}, {0x17, 0x18, 0}, {0, 0, 0}};
const s32 gOptionSelectMenuGroupSTableCounts[3] = {0xc, 0xb, 2};
const u8 gOptionSelectMenuTimerSTableIndices[2][3][2] = {{{0x10, 0x11}, {0xc, 0xd}, {8, 9}},
                                                         {{0x12, 0x13}, {0xe, 0xf}, {0xa, 0xb}}};
const u8 gOptionSelectMenuGroupSTableIndices[3][12] = {{0, 2, 5, 0xc, 0xd, 8, 9, 0x10, 0x11, 0x14, 0x15, 0x16},
                                                       {1, 3, 6, 0xe, 0xf, 0xa, 0xb, 0x12, 0x13, 0x17, 0x18, 0},
                                                       {4, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
OptionSelectMenu *gOptionSelectMenu;

void InitOptionSelectMenuTexts(void) {
    s32 labelIndex;

    {
        s32 mainRemainingSize = 0x8000;
        u8 mainLabelSizes[2][2] = {{0xdc, 0x10}, {0xf0, 0x50}};
        s32 mainMessageIndices[2] = {0xb, 0xc};

        for (labelIndex = 0; labelIndex < 2; labelIndex++) {
            mainRemainingSize -= InitLabelCanvas(
                gOptionSelectMenu->mHeap, gOptionSelectMenuMLabelIndices[labelIndex],
                gOptionSelectMenu->mOptionSelectMenuMBnll, mainLabelSizes[labelIndex][0], mainLabelSizes[labelIndex][1],
                labelIndex, gOptionSelectMenu->mOptionSelectMenuMNcer, gOptionSelectMenu->mOptionSelectMenuMBncl,
                gOptionSelectMenu->mOptionSelectMenuMTable, mainRemainingSize);
            PrintLabelLayoutTextNoFixedAdvance(
                0, gOptionSelectMenuMLabelIndices[labelIndex], gOptionSelectMenu->mOptionSelectMenuMBnll,
                GetBmgEntry(gOptionSelectMenu->mOptionMessages, mainMessageIndices[labelIndex]),
                gOptionSelectMenu->mOptionSelectMenuMBncl, gOptionSelectMenu->mOptionSelectMenuMTable);
        }
    }
    {
        s32 subRemainingSize = GX_GetSizeOfSubOBJ();
        void *subMessages;
        u8 subLabelSizes[3][2] = {{0x9b, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
        s32 subMessageIndices[3] = {0, 2, 4};

        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            subMessages = gOptionSelectMenu->mOptionMessages;
            if (labelIndex == 2) {
                subMessages = gOptionSelectMenu->mCommonMessages;
            }
            subRemainingSize -=
                InitLabelCanvas(gOptionSelectMenu->mHeap, gOptionSelectMenuSLabelIndices[labelIndex],
                                gOptionSelectMenu->mOptionSelectMenuSBnll, subLabelSizes[labelIndex][0],
                                subLabelSizes[labelIndex][1], gOptionSelectMenuRowSTableIndices[labelIndex],
                                gOptionSelectMenu->mOptionSelectMenuSNcer, gOptionSelectMenu->mOptionSelectMenuSBncl,
                                gOptionSelectMenu->mOptionSelectMenuSTable, subRemainingSize);
            PrintLabelLayoutTextNoFixedAdvance(
                1, gOptionSelectMenuSLabelIndices[labelIndex], gOptionSelectMenu->mOptionSelectMenuSBnll,
                GetBmgEntry(subMessages, subMessageIndices[labelIndex]), gOptionSelectMenu->mOptionSelectMenuSBncl,
                gOptionSelectMenu->mOptionSelectMenuSTable);
        }
    }
}

void InitOptionSelectMenu(void *heap) {
    s32 index;

    gOptionSelectMenu = HeapAlloc(heap, sizeof(OptionSelectMenu));
    gOptionSelectMenu->mHeap = heap;
    gOptionSelectMenu->mState = OPTION_SELECT_STATE_SLIDE_IN;
    gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_SLIDE_IN;
    gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
    gOptionSelectMenu->mStateFrames = 0;
    gOptionSelectMenu->mHighlightVisible = TRUE;
    LocateAndQueueOptionSelectMenu();
    InitPaletteBlend(heap, gOptionSelectMenu->mOptionSelectMenuSONclr, 3);
    for (index = 0; index < 2; index++) {
        SetCellOamModeXlu(gOptionSelectMenuXluCellIndices[index], 1, gOptionSelectMenu->mOptionSelectMenuSNcer,
                          gOptionSelectMenu->mOptionSelectMenuSBncl);
    }
    ResetOamLists(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    InitLayoutTable(heap, gOptionSelectMenu->mOptionSelectMenuMBncl, gOptionSelectMenu->mOptionSelectMenuMBnll,
                    &gOptionSelectMenu->mOptionSelectMenuMTable);
    InitLayoutTable(heap, gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSBnll,
                    &gOptionSelectMenu->mOptionSelectMenuSTable);
    gOptionSelectMenu->mOptionMessages = FindSceneFile("option.bmg");
    gOptionSelectMenu->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitOptionSelectMenuTexts();
    gOptionSelectMenu->mBg0Bg1Offset = -140;
    for (index = 0; index < 3; index++) {
        if (index == 2) {
            gOptionSelectMenu->mGroupOffsets[index].mOffsetX = 0;
            gOptionSelectMenu->mGroupOffsets[index].mOffsetY = 0x28;
        } else if (index == 1) {
            gOptionSelectMenu->mGroupOffsets[index].mOffsetX = 250;
            gOptionSelectMenu->mGroupOffsets[index].mOffsetY = 0;
        } else {
            gOptionSelectMenu->mGroupOffsets[index].mOffsetX = -250;
            gOptionSelectMenu->mGroupOffsets[index].mOffsetY = 0;
        }
    }
    SetOptionSoundRowFromSave();
    if (gBackupBuffers->mFirstBlock->mLocateFriendOff == 0) {
        gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_LOCATE_FRIEND] = 0;
    } else {
        gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_LOCATE_FRIEND] = 1;
    }
    for (index = 0; index < 2; index++) {
        gOptionSelectMenu->mSavedRowValues[index] = gOptionSelectMenu->mRowValues[index];
    }
    WriteOptionSelectMenuTableOffsets();
    SetOptionSelectMenuValuesOnOff();
    for (index = 0; index < 2; index++) {
        gOptionSelectMenu->mOffsetTimers[index][0] = 0;
        gOptionSelectMenu->mOffsetTimers[index][1] = 0;
    }
    gOptionSelectMenu->mOkChosen = FALSE;
    gOptionSelectMenu->mBg1Visible = TRUE;
    SetSelectReturnSoundId(0xe);
}

void ReleaseOptionSelectMenu(void) {
    u32 displayBits;

    SetOptionSoundRowFromSave();
    ApplyOptionSelectMenuSound();
    displayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((displayBits & ~2) << 8);
    ClearPaletteBlendPointer();
    gOptionSelectMenu = NULL;
}

void LocateAndQueueOptionSelectMenu(void) {
    Ncgr *chars;
    Nscr *screenMap;
    Nclr *palette;

    LocateNcgr(&chars, FindSceneFile("Option_select_menu_m_b.ncgr"));
    LocateNscr(&screenMap, FindSceneFile("Option_select_menu_m.nscr"));
    LocateNclr(&palette, FindSceneFile("Option_select_menu_m_b.nclr"));
    gOptionSelectMenu->mOptionSelectMenuMBncl = FindSceneFile("Option_select_menu_m.bncl");
    gOptionSelectMenu->mOptionSelectMenuSBncl = FindSceneFile("Option_select_menu_s.bncl");
    gOptionSelectMenu->mOptionSelectMenuSBnbl = FindSceneFile("Option_select_menu_s.bnbl");
    gOptionSelectMenu->mOptionSelectMenuMBnll = FindSceneFile("Option_select_menu_m.bnll");
    gOptionSelectMenu->mOptionSelectMenuSBnll = FindSceneFile("Option_select_menu_s.bnll");
    LocateNcgr2(&gOptionSelectMenu->mOptionSelectMenuMNcgr, FindSceneFile("Option_select_menu_m.nce.ncgr"));
    LocateNcer(&gOptionSelectMenu->mOptionSelectMenuMNcer, FindSceneFile("Option_select_menu_m.nce.ncer"));
    LocateNclr(&gOptionSelectMenu->mOptionSelectMenuMONclr, FindSceneFile("Option_select_menu_m_o.nclr"));
    LocateNcgr2(&gOptionSelectMenu->mOptionSelectMenuSNcgr, FindSceneFile("Option_select_menu_s.nce.ncgr"));
    LocateNcer(&gOptionSelectMenu->mOptionSelectMenuSNcer, FindSceneFile("Option_select_menu_s.nce.ncer"));
    LocateNclr(&gOptionSelectMenu->mOptionSelectMenuSONclr, FindSceneFile("Option_select_menu_s_o.nclr"));
    NNS_GfdRegisterNewVramTransferTask(5, 0, chars->mData, chars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(9, 0, screenMap->mData, screenMap->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0x20, palette->mData + 0x10, 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, gOptionSelectMenu->mOptionSelectMenuMNcgr->mData,
                                       gOptionSelectMenu->mOptionSelectMenuMNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gOptionSelectMenu->mOptionSelectMenuSNcgr->mData,
                                       gOptionSelectMenu->mOptionSelectMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, gOptionSelectMenu->mOptionSelectMenuMONclr->mData,
                                       gOptionSelectMenu->mOptionSelectMenuMONclr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gOptionSelectMenu->mOptionSelectMenuSONclr->mData,
                                       gOptionSelectMenu->mOptionSelectMenuSONclr->mDataSize);
}

void ApplyOptionSelectMenuSound(void) {
    switch (gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND]) {
        case SOUND_MODE_STEREO:
            SetSoundOutputEffect(0);
            break;
        case SOUND_MODE_SURROUND:
            SetSoundOutputEffect(1);
            break;
        case SOUND_MODE_HEADPHONES:
            SetSoundOutputEffect(2);
            break;
    }
}

void SetSoundModeFromOptionRow(void) {
    switch (gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND]) {
        case SOUND_MODE_STEREO:
            gBackupBuffers->mFirstBlock->mSoundMode = SOUND_MODE_STEREO;
            break;
        case SOUND_MODE_SURROUND:
            gBackupBuffers->mFirstBlock->mSoundMode = SOUND_MODE_SURROUND;
            break;
        case SOUND_MODE_HEADPHONES:
            gBackupBuffers->mFirstBlock->mSoundMode = SOUND_MODE_HEADPHONES;
            break;
    }
}

void SetOptionSoundRowFromSave(void) {
    switch (gBackupBuffers->mFirstBlock->mSoundMode) {
        case SOUND_MODE_STEREO:
            gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND] = SOUND_MODE_STEREO;
            break;
        case SOUND_MODE_SURROUND:
            gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND] = SOUND_MODE_SURROUND;
            break;
        case SOUND_MODE_HEADPHONES:
            gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND] = SOUND_MODE_HEADPHONES;
            break;
    }
}

void AdvanceOptionSelectMenuState0(void) {
    s32 groupIndex;
    s32 entryIndex;
    s16 offsetX;

    gOptionSelectMenu->mStateFrames++;
    gOptionSelectMenu->mBg0Bg1Offset = InterpolateS16(1, -140, 0, gOptionSelectMenu->mStateFrames, 10);
    offsetX = InterpolateS16(1, 250, 0, gOptionSelectMenu->mStateFrames, 10);
    for (groupIndex = 0; groupIndex < 2; groupIndex++) {
        for (entryIndex = 0; entryIndex < gOptionSelectMenuGroupSTableCounts[groupIndex]; entryIndex++) {
            if (groupIndex == 1) {
                gOptionSelectMenu->mGroupOffsets[groupIndex].mOffsetX = -offsetX;
            } else {
                gOptionSelectMenu->mGroupOffsets[groupIndex].mOffsetX = offsetX;
            }
        }
    }
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_SLIDE_IN_BG2;
        gOptionSelectMenu->mStateFrames = 0;
    }
}

void AdvanceOptionSelectMenuState1(void) {
    gOptionSelectMenu->mStateFrames++;
    gOptionSelectMenu->mGroupOffsets[2].mOffsetY = -LookupSelectReturnState1Bg2Offset(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_WAIT_INPUT;
        gOptionSelectMenu->mStateFrames = 0;
    }
}

void AdvanceOptionSelectMenuState2(void) {
    OptionSelectMenu *menu;
    s32 sel;
    s32 r5;
    BOOL hasB;
    BOOL hasA;
    s32 rowIndex;
    InputSlotIndex idx;
    u16 hasPair;

    menu = gOptionSelectMenu;
    sel = menu->mIndex;
    idx = INPUT_SLOT_PAD_OR_PARTICIPANT;
    hasB = FALSE;
    r5 = -1;
    hasA = FALSE;
    hasPair = gInputSlots[idx].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[idx].mPair.mNoPairCount < 5) {
        hasA = TRUE;
    }
    if (hasA == FALSE && gInputSlots[idx].mPair.mPrevHasPair == 0 && hasPair != 0) {
        hasB = TRUE;
    }
    if (hasB != FALSE) {
        r5 = RectTableFindContaining(menu->mOptionSelectMenuSBnbl, gInputSlots[idx].mPair.mPairX,
                                     gInputSlots[idx].mPair.mPairY);
    }
    if ((u16) (gInputSlots[idx].mPressedBits & PAD_KEY_B) != 0) {
        goto L1;
    } else {
        BOOL touchBegan = FALSE;
        BOOL recentlyLost = FALSE;
        hasPair = gInputSlots[idx].mPair.mHasPair;
        if (hasPair == 0 && gInputSlots[idx].mPair.mNoPairCount < 5) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[idx].mPair.mPrevHasPair == 0 && hasPair != 0) {
            touchBegan = TRUE;
        }
        if (touchBegan != FALSE && IsSelectReturnState2NoState3Or4RequestAndInRect(
                                       gInputSlots[idx].mPair.mPairX, gInputSlots[idx].mPair.mPairY) != FALSE) {
        L1:
            gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_SLIDE_OUT;
            gOptionSelectMenu->mNextOptionState = OPTION_STATE_TOP_MENU;
            for (rowIndex = 0; rowIndex < 2; rowIndex++) {
                gOptionSelectMenu->mRowValues[rowIndex] = gOptionSelectMenu->mSavedRowValues[rowIndex];
            }
            RequestSelectReturnState3WithSound(0);
            goto end;
        }
    }
    if (((u16) (gInputSlots[idx].mPressedBits & PAD_KEY_A) != 0 && gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_OK) ||
        r5 == OPTION_SELECT_ROW_OK) {
        SetSoundModeFromOptionRow();
        if (gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_LOCATE_FRIEND] == 0) {
            gBackupBuffers->mFirstBlock->mUnk_31 &= ~0x10;
        } else {
            gBackupBuffers->mFirstBlock->mUnk_31 |= 0x10;
        }
        WriteBackupFirstBlockWrapper();
        if (gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_OK) {
            gOptionSelectMenu->mHighlightVisible = FALSE;
        }
        gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_OK_PRESSED_DELAY;
        gOptionSelectMenu->mNextOptionState = OPTION_STATE_TOP_MENU;
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_OK;
        gOptionSelectMenu->mOkChosen = TRUE;
        StopPaletteBlend();
        StartSoundOncePerFrame(5);
    } else if (r5 == OPTION_SELECT_ROW_SOUND) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        StartSoundOncePerFrame(10);
    } else if (r5 == OPTION_SELECT_ROW_LOCATE_FRIEND) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_LOCATE_FRIEND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        StartSoundOncePerFrame(1);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gOptionSelectMenu->mIndex--;
        if (gOptionSelectMenu->mIndex < 0) {
            gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_OK;
        }
        StartSoundOncePerFrame(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 || (gOptionSelectMenu->mIndex != OPTION_SELECT_ROW_OK &&
                                                            (u16) (gInputSlots[idx].mPressedBits & PAD_KEY_A) != 0)) {
        gOptionSelectMenu->mIndex++;
        if (gOptionSelectMenu->mIndex > OPTION_SELECT_ROW_OK) {
            gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
        }
        StartSoundOncePerFrame(0);
    } else if (gOptionSelectMenu->mIndex != OPTION_SELECT_ROW_OK && GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        if (gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_SOUND) {
            StartSoundOncePerFrame(10);
        } else {
            StartSoundOncePerFrame(1);
        }
    } else if (gOptionSelectMenu->mIndex != OPTION_SELECT_ROW_OK && GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
            gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        }
        if (gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_SOUND) {
            StartSoundOncePerFrame(10);
        } else {
            StartSoundOncePerFrame(1);
        }
    } else if (r5 == 3) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        StartSoundOncePerFrame(10);
    } else if (r5 == 4) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        StartSoundOncePerFrame(10);
    } else if (r5 == 5) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_LOCATE_FRIEND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        StartSoundOncePerFrame(1);
    } else if (r5 == 6) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_LOCATE_FRIEND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        StartSoundOncePerFrame(1);
    }
end:
    if (gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND] < 0) {
        gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND] = SOUND_MODE_HEADPHONES;
    }
    if (gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND] > SOUND_MODE_HEADPHONES) {
        gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_SOUND] = SOUND_MODE_SURROUND;
    }
    if (gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_LOCATE_FRIEND] < 0) {
        gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_LOCATE_FRIEND] = 1;
    }
    if (gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_LOCATE_FRIEND] > 1) {
        gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_LOCATE_FRIEND] = 0;
    }
    if (gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_OK && sel != OPTION_SELECT_ROW_OK) {
        ResetPaletteBlendCycle();
    }
    ApplyOptionSelectMenuSound();
}

void AdvanceOptionSelectMenuState3(void) {
    gOptionSelectMenu->mStateFrames++;
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_SLIDE_OUT;
        gOptionSelectMenu->mStateFrames = 0;
    } else if (gOptionSelectMenu->mStateFrames >= 5) {
        gOptionSelectMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionSelectMenuState4(void) {
    s32 groupIndex;
    s32 entryIndex;
    s16 offsetX;
    void *text;
    void *buttonText;

    gOptionSelectMenu->mBg0Bg1Offset = InterpolateS16(1, 0, -0x8c, gOptionSelectMenu->mStateFrames, 10);
    gOptionSelectMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 250, gOptionSelectMenu->mStateFrames, 10);
    for (groupIndex = 0; groupIndex < 2; groupIndex++) {
        for (entryIndex = 0; entryIndex < gOptionSelectMenuGroupSTableCounts[groupIndex]; entryIndex++) {
            if (groupIndex == 1) {
                gOptionSelectMenu->mGroupOffsets[groupIndex].mOffsetX = -offsetX;
            } else {
                gOptionSelectMenu->mGroupOffsets[groupIndex].mOffsetX = offsetX;
            }
        }
    }
    gOptionSelectMenu->mGroupOffsets[2].mOffsetY = -LookupSelectReturnState4Bg2Offset(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= 10) {
        if (gOptionSelectMenu->mStateFrames >= 10 && IsSelectReturnState2NoState3Or4Request() != 0) {
            gOptionSelectMenu->mBg1Visible = FALSE;
            if (gOptionSelectMenu->mOkChosen != FALSE) {
                SetTxtSystemOpenSoundId(0x21);
                text = GetBmgEntry(gOptionSelectMenu->mOptionMessages, 0x10);
                buttonText = GetBmgEntry(gOptionSelectMenu->mCommonMessages, 4);
                SetupTxtSystemSubTextButton(text, buttonText);
                gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_WAIT_BACKUP;
                gOptionSelectMenu->mStateFrames = 0;
                RequestSelectReturnState4();
            } else {
                RequestOptionState(gOptionSelectMenu->mNextOptionState);
            }
        }
    }
}

void AdvanceOptionSelectMenuState5(void) {
    s32 backupBusy;

    if (GetTxtSystemDone() != 0) {
        if (gBackupBuffers->mBusy == 0) {
            if (gBackupAccess->mBackupEnabled != 0) {
                backupBusy = gBackupAccess->mCommandRunning;
            } else {
                backupBusy = 0;
            }
        } else {
            backupBusy = 1;
        }
        if (backupBusy == 0) {
            SetTxtSystemOpenSoundId(0x23);
            RequestTxtSystemClose();
            RequestSelectReturnState1();
        }
    }
    if (IsTxtSystemState0NoOpenRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        RequestOptionState(gOptionSelectMenu->mNextOptionState);
    }
}

void WriteOptionSelectMenuTableOffsets(void) {
    s32 index;
    s32 entryIndex;
    u16 mainLayoutCount;
    u16 subLayoutCount;

    mainLayoutCount = gOptionSelectMenu->mOptionSelectMenuMBncl->mCount;
    subLayoutCount = gOptionSelectMenu->mOptionSelectMenuSBncl->mCount;
    for (index = 0; index < 1; index++) {
        gOptionSelectMenu->mOptionSelectMenuMTable[gOptionSelectMenuOffsetMIndices[index]].mOffsetY =
            gOptionSelectMenu->mBg0Bg1Offset;
    }
    for (index = 0; index < 2; index++) {
        (gOptionSelectMenu->mOptionSelectMenuMTable + mainLayoutCount)[gOptionSelectMenuMLabelIndices[index]].mOffsetY =
            gOptionSelectMenu->mBg0Bg1Offset;
    }
    for (index = 0; index < 3; index++) {
        for (entryIndex = 0; entryIndex < gOptionSelectMenuGroupSTableCounts[index]; entryIndex++) {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuGroupSTableIndices[index][entryIndex]]
                .mOffsetX = gOptionSelectMenu->mGroupOffsets[index].mOffsetX;
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuGroupSTableIndices[index][entryIndex]]
                .mOffsetY = gOptionSelectMenu->mGroupOffsets[index].mOffsetY;
        }
        (gOptionSelectMenu->mOptionSelectMenuSTable + subLayoutCount)[gOptionSelectMenuSLabelIndices[index]].mOffsetX =
            gOptionSelectMenu->mGroupOffsets[index].mOffsetX;
        (gOptionSelectMenu->mOptionSelectMenuSTable + subLayoutCount)[gOptionSelectMenuSLabelIndices[index]].mOffsetY =
            gOptionSelectMenu->mGroupOffsets[index].mOffsetY;
    }
    for (index = 0; index < 2; index++) {
        for (entryIndex = 0; entryIndex < 3; entryIndex++) {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[index][entryIndex][0]]
                .mOffsetX -= LookupFrameOffset(6 - gOptionSelectMenu->mOffsetTimers[index][0]);
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[index][entryIndex][1]]
                .mOffsetX += LookupFrameOffset(6 - gOptionSelectMenu->mOffsetTimers[index][1]);
        }
    }
}

void SetOptionSelectMenuValuesOnOff(void) {
    s32 rowIndex;
    s32 valueIndex;

    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (valueIndex = 0; valueIndex < gOptionSelectMenuValueCounts[rowIndex]; valueIndex++) {
            if (valueIndex == gOptionSelectMenu->mRowValues[rowIndex]) {
                gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuValueSTableIndices[rowIndex][valueIndex]]
                    .mVisible = 1;
            } else {
                gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuValueSTableIndices[rowIndex][valueIndex]]
                    .mVisible = 0;
            }
        }
    }
}

void SetOptionSelectMenuRowsOnOff(void) {
    s32 rowIndex;
    s32 valueIndex;

    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        if (rowIndex == gOptionSelectMenu->mIndex && gOptionSelectMenu->mHighlightVisible != FALSE) {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuRowSTableIndices[rowIndex]].mVisible = 1;
            SetLabelPaletteIndex(gOptionSelectMenuSLabelIndices[rowIndex], 14,
                                 gOptionSelectMenu->mOptionSelectMenuSBnll, gOptionSelectMenu->mOptionSelectMenuSTable,
                                 gOptionSelectMenu->mOptionSelectMenuSBncl);
            for (valueIndex = 0; valueIndex < gOptionSelectMenuValueCounts[rowIndex]; valueIndex++) {
                SetCellPaletteIndex(gOptionSelectMenuValueSTableIndices[rowIndex][valueIndex], 14,
                                    gOptionSelectMenu->mOptionSelectMenuSNcer,
                                    gOptionSelectMenu->mOptionSelectMenuSBncl);
            }
        } else {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuRowSTableIndices[rowIndex]].mVisible = 0;
            SetLabelPaletteIndex(gOptionSelectMenuSLabelIndices[rowIndex], 15,
                                 gOptionSelectMenu->mOptionSelectMenuSBnll, gOptionSelectMenu->mOptionSelectMenuSTable,
                                 gOptionSelectMenu->mOptionSelectMenuSBncl);
            for (valueIndex = 0; valueIndex < gOptionSelectMenuValueCounts[rowIndex]; valueIndex++) {
                SetCellPaletteIndex(gOptionSelectMenuValueSTableIndices[rowIndex][valueIndex], 15,
                                    gOptionSelectMenu->mOptionSelectMenuSNcer,
                                    gOptionSelectMenu->mOptionSelectMenuSBncl);
            }
        }
    }
}

void AdvanceOptionSelectMenuOffsetTimers(void) {
    s32 rowIndex;
    s32 timerIndex;

    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (timerIndex = 0; timerIndex < 2; timerIndex++) {
            if (rowIndex == gOptionSelectMenu->mIndex) {
                if (gOptionSelectMenu->mOffsetTimers[rowIndex][timerIndex] > 0) {
                    gOptionSelectMenu
                        ->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[rowIndex][0][timerIndex]]
                        .mVisible = 1;
                    gOptionSelectMenu
                        ->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[rowIndex][1][timerIndex]]
                        .mVisible = 1;
                    gOptionSelectMenu->mOffsetTimers[rowIndex][timerIndex]--;
                } else {
                    gOptionSelectMenu
                        ->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[rowIndex][0][timerIndex]]
                        .mVisible = 0;
                    gOptionSelectMenu
                        ->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[rowIndex][1][timerIndex]]
                        .mVisible = 1;
                }
            } else {
                gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[rowIndex][0][timerIndex]]
                    .mVisible = 0;
                gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[rowIndex][1][timerIndex]]
                    .mVisible = 0;
            }
        }
    }
}

void AdvanceOptionSelectMenu(void) {
    OptionSelectMenu *menu;

    gOptionSelectMenu->mState = gOptionSelectMenu->mNextState;
    switch (gOptionSelectMenu->mState) {
        case OPTION_SELECT_STATE_SLIDE_IN:
            AdvanceOptionSelectMenuState0();
            break;
        case OPTION_SELECT_STATE_SLIDE_IN_BG2:
            AdvanceOptionSelectMenuState1();
            break;
        case OPTION_SELECT_STATE_WAIT_INPUT:
            AdvanceOptionSelectMenuState2();
            break;
        case OPTION_SELECT_STATE_OK_PRESSED_DELAY:
            AdvanceOptionSelectMenuState3();
            break;
        case OPTION_SELECT_STATE_SLIDE_OUT:
            AdvanceOptionSelectMenuState4();
            break;
        case OPTION_SELECT_STATE_WAIT_BACKUP:
            AdvanceOptionSelectMenuState5();
            break;
    }
    AdvancePaletteBlend();
    WriteOptionSelectMenuTableOffsets();
    SetOptionSelectMenuValuesOnOff();
    SetOptionSelectMenuRowsOnOff();
    AdvanceOptionSelectMenuOffsetTimers();
    menu = gOptionSelectMenu;
    DrawLayoutTable(menu->mOptionSelectMenuMBncl, menu->mOptionSelectMenuMNcer, menu->mOptionSelectMenuMBnll,
                    GetOptionFirstBuffer(), menu->mOptionSelectMenuMTable);
    menu = gOptionSelectMenu;
    DrawLayoutTable(menu->mOptionSelectMenuSBncl, menu->mOptionSelectMenuSNcer, menu->mOptionSelectMenuSBnll,
                    GetOptionSecondBuffer(), menu->mOptionSelectMenuSTable);
}

void WriteOptionSelectMenuRegisters(void) {
    u32 plane;

    if (gOptionSelectMenu->mBg1Visible != FALSE) {
        plane = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
        plane |= 2;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (plane << 8);
    } else {
        plane = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
        plane &= ~2;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (plane << 8);
    }
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG0OFS = (-gOptionSelectMenu->mBg0Bg1Offset << 16) & 0x1ff0000;
    reg_G2_BG1OFS = (-gOptionSelectMenu->mBg0Bg1Offset << 16) & 0x1ff0000;
}

void RegisterOptionSelectMenuCallbacks(void) {
    OptionStateCallbacks table = {InitOptionSelectMenu, ReleaseOptionSelectMenu, AdvanceOptionSelectMenu,
                                  WriteOptionSelectMenuRegisters};

    SetOptionStateCallbacks(&table);
}
