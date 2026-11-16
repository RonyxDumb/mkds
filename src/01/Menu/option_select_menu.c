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
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/record_gpx_grade_text.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/palette_blend.h"
#include "01/Menu/option_states.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "vram_bank_display_setup.h"
#include "Main/Graphics/layout_rect_table.h"
#include "display_blend_affine_setup.h"
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
                Bmg_GetRawStringPointer_from_thumb(gOptionSelectMenu->mOptionMessages, mainMessageIndices[labelIndex]),
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
                Bmg_GetRawStringPointer_from_thumb(subMessages, subMessageIndices[labelIndex]), gOptionSelectMenu->mOptionSelectMenuSBncl,
                gOptionSelectMenu->mOptionSelectMenuSTable);
        }
    }
}

void InitOptionSelectMenu(void *heap) {
    s32 index;

    gOptionSelectMenu = Mem_AllocateHeap(heap, sizeof(OptionSelectMenu));
    gOptionSelectMenu->mHeap = heap;
    gOptionSelectMenu->mState = OPTION_SELECT_STATE_SLIDE_IN;
    gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_SLIDE_IN;
    gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
    gOptionSelectMenu->mStateFrames = 0;
    gOptionSelectMenu->mHighlightVisible = TRUE;
    LocateAndQueueOptionSelectMenu();
    InitPaletteBlend(heap, gOptionSelectMenu->mOptionSelectMenuSONclr, 3);
    for (index = 0; index < 2; index++) {
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(gOptionSelectMenuXluCellIndices[index], 1, gOptionSelectMenu->mOptionSelectMenuSNcer,
                          gOptionSelectMenu->mOptionSelectMenuSBncl);
    }
    OamBuffer_SomeFn_from_thumb(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    InitLayoutTable(heap, gOptionSelectMenu->mOptionSelectMenuMBncl, gOptionSelectMenu->mOptionSelectMenuMBnll,
                    &gOptionSelectMenu->mOptionSelectMenuMTable);
    InitLayoutTable(heap, gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSBnll,
                    &gOptionSelectMenu->mOptionSelectMenuSTable);
    gOptionSelectMenu->mOptionMessages = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("option.bmg");
    gOptionSelectMenu->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
    InitOptionSelectMenuTexts();
    gOptionSelectMenu->mBg0Bg1Offset = -OPTION_SELECT_BG_SLIDE_DISTANCE;
    for (index = 0; index < 3; index++) {
        if (index == 2) {
            gOptionSelectMenu->mGroupOffsets[index].mOffsetX = 0;
            gOptionSelectMenu->mGroupOffsets[index].mOffsetY = OPTION_SELECT_BG2_SLIDE_DISTANCE;
        } else if (index == 1) {
            gOptionSelectMenu->mGroupOffsets[index].mOffsetX = OPTION_SELECT_SLIDE_DISTANCE;
            gOptionSelectMenu->mGroupOffsets[index].mOffsetY = 0;
        } else {
            gOptionSelectMenu->mGroupOffsets[index].mOffsetX = -OPTION_SELECT_SLIDE_DISTANCE;
            gOptionSelectMenu->mGroupOffsets[index].mOffsetY = 0;
        }
    }
    SetOptionSoundRowFromSave();
    if (g_SaveDataHolder->mFirstBlock->mLocateFriendOff == 0) {
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
    SetSelectReturnSoundId(SELECT_RETURN_SOUND_ID);
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

    MaybeReadCharBlock_1(&chars, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_m_b.ncgr"));
    MaybeReadScreenBlock(&screenMap, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_m.nscr"));
    Gfx_ReadPaletteRelative(&palette, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_m_b.nclr"));
    gOptionSelectMenu->mOptionSelectMenuMBncl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_m.bncl");
    gOptionSelectMenu->mOptionSelectMenuSBncl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_s.bncl");
    gOptionSelectMenu->mOptionSelectMenuSBnbl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_s.bnbl");
    gOptionSelectMenu->mOptionSelectMenuMBnll = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_m.bnll");
    gOptionSelectMenu->mOptionSelectMenuSBnll = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_s.bnll");
    Gfx_ReadCharGraphicsRelative(&gOptionSelectMenu->mOptionSelectMenuMNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_m.nce.ncgr"));
    LocateNcer(&gOptionSelectMenu->mOptionSelectMenuMNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_m.nce.ncer"));
    Gfx_ReadPaletteRelative(&gOptionSelectMenu->mOptionSelectMenuMONclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_m_o.nclr"));
    Gfx_ReadCharGraphicsRelative(&gOptionSelectMenu->mOptionSelectMenuSNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_s.nce.ncgr"));
    LocateNcer(&gOptionSelectMenu->mOptionSelectMenuSNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_s.nce.ncer"));
    Gfx_ReadPaletteRelative(&gOptionSelectMenu->mOptionSelectMenuSONclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_select_menu_s_o.nclr"));
    AllocateReserveTEQSub(5, 0, chars->mData, chars->mDataSize);
    AllocateReserveTEQSub(9, 0, screenMap->mData, screenMap->mDataSize);
    AllocateReserveTEQSub(0xf, 0x20, palette->mData + 0x10, 0x20);
    AllocateReserveTEQSub(0x13, 0, gOptionSelectMenu->mOptionSelectMenuMNcgr->mData,
                                       gOptionSelectMenu->mOptionSelectMenuMNcgr->mDataSize);
    AllocateReserveTEQSub(0x23, 0, gOptionSelectMenu->mOptionSelectMenuSNcgr->mData,
                                       gOptionSelectMenu->mOptionSelectMenuSNcgr->mDataSize);
    AllocateReserveTEQSub(0xe, 0, gOptionSelectMenu->mOptionSelectMenuMONclr->mData,
                                       gOptionSelectMenu->mOptionSelectMenuMONclr->mDataSize);
    AllocateReserveTEQSub(0x1e, 0, gOptionSelectMenu->mOptionSelectMenuSONclr->mData,
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
            g_SaveDataHolder->mFirstBlock->mSoundMode = SOUND_MODE_STEREO;
            break;
        case SOUND_MODE_SURROUND:
            g_SaveDataHolder->mFirstBlock->mSoundMode = SOUND_MODE_SURROUND;
            break;
        case SOUND_MODE_HEADPHONES:
            g_SaveDataHolder->mFirstBlock->mSoundMode = SOUND_MODE_HEADPHONES;
            break;
    }
}

void SetOptionSoundRowFromSave(void) {
    switch (g_SaveDataHolder->mFirstBlock->mSoundMode) {
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

void AdvanceOptionSelectMenuSlideIn(void) {
    s32 groupIndex;
    s32 entryIndex;
    s16 offsetX;

    gOptionSelectMenu->mStateFrames++;
    gOptionSelectMenu->mBg0Bg1Offset = ComputeValueInterpolation_from_thumb(1, -OPTION_SELECT_BG_SLIDE_DISTANCE, 0,
                                                      gOptionSelectMenu->mStateFrames, OPTION_SELECT_SLIDE_FRAMES);
    offsetX =
        ComputeValueInterpolation_from_thumb(1, OPTION_SELECT_SLIDE_DISTANCE, 0, gOptionSelectMenu->mStateFrames, OPTION_SELECT_SLIDE_FRAMES);
    for (groupIndex = 0; groupIndex < 2; groupIndex++) {
        for (entryIndex = 0; entryIndex < gOptionSelectMenuGroupSTableCounts[groupIndex]; entryIndex++) {
            if (groupIndex == 1) {
                gOptionSelectMenu->mGroupOffsets[groupIndex].mOffsetX = -offsetX;
            } else {
                gOptionSelectMenu->mGroupOffsets[groupIndex].mOffsetX = offsetX;
            }
        }
    }
    if (gOptionSelectMenu->mStateFrames >= OPTION_SELECT_SLIDE_FRAMES) {
        gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_SLIDE_IN_BG2;
        gOptionSelectMenu->mStateFrames = 0;
    }
}

void AdvanceOptionSelectMenuSlideInBg2(void) {
    gOptionSelectMenu->mStateFrames++;
    gOptionSelectMenu->mGroupOffsets[2].mOffsetY = -LookupSelectReturnSlideInBg2Offset(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= OPTION_SELECT_SLIDE_FRAMES) {
        gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_WAIT_INPUT;
        gOptionSelectMenu->mStateFrames = 0;
    }
}

void AdvanceOptionSelectMenuWaitInput(void) {
    OptionSelectMenu *menu;
    s32 sel;
    s32 touchedRect;
    BOOL hasB;
    BOOL hasA;
    s32 rowIndex;
    InputSlotIndex idx;
    u16 hasPair;

    menu = gOptionSelectMenu;
    sel = menu->mIndex;
    idx = INPUT_SLOT_PAD_OR_PARTICIPANT;
    hasB = FALSE;
    touchedRect = -1;
    hasA = FALSE;
    hasPair = g_GlobalCYT[idx].mPair.mHasPair;
    if (hasPair == 0 && g_GlobalCYT[idx].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        hasA = TRUE;
    }
    if (hasA == FALSE && g_GlobalCYT[idx].mPair.mPrevHasPair == 0 && hasPair != 0) {
        hasB = TRUE;
    }
    if (hasB != FALSE) {
        touchedRect = RectTableFindContaining(menu->mOptionSelectMenuSBnbl, g_GlobalCYT[idx].mPair.mPairX,
                                              g_GlobalCYT[idx].mPair.mPairY);
    }
    if ((u16) (g_GlobalCYT[idx].mPressedBits & PAD_KEY_B) != 0) {
        goto leaveMenu;
    } else {
        BOOL touchBegan = FALSE;
        BOOL recentlyLost = FALSE;
        hasPair = g_GlobalCYT[idx].mPair.mHasPair;
        if (hasPair == 0 && g_GlobalCYT[idx].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && g_GlobalCYT[idx].mPair.mPrevHasPair == 0 && hasPair != 0) {
            touchBegan = TRUE;
        }
        if (touchBegan != FALSE && IsSelectReturnShownNoRequestAndInRect(g_GlobalCYT[idx].mPair.mPairX,
                                                                         g_GlobalCYT[idx].mPair.mPairY) != FALSE) {
        leaveMenu:
            gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_SLIDE_OUT;
            gOptionSelectMenu->mNextOptionState = OPTION_STATE_TOP_MENU;
            for (rowIndex = 0; rowIndex < 2; rowIndex++) {
                gOptionSelectMenu->mRowValues[rowIndex] = gOptionSelectMenu->mSavedRowValues[rowIndex];
            }
            RequestSelectReturnPressWithSound(0);
            goto end;
        }
    }
    if (((u16) (g_GlobalCYT[idx].mPressedBits & PAD_KEY_A) != 0 && gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_OK) ||
        touchedRect == OPTION_SELECT_ROW_OK) {
        SetSoundModeFromOptionRow();
        if (gOptionSelectMenu->mRowValues[OPTION_SELECT_ROW_LOCATE_FRIEND] == 0) {
            g_SaveDataHolder->mFirstBlock->mLocateFriendOff = 0;
        } else {
            g_SaveDataHolder->mFirstBlock->mLocateFriendOff = 1;
        }
        WriteSaveDataSectionHeaderToSaveData_from_thumb();
        if (gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_OK) {
            gOptionSelectMenu->mHighlightVisible = FALSE;
        }
        gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_OK_PRESSED_DELAY;
        gOptionSelectMenu->mNextOptionState = OPTION_STATE_TOP_MENU;
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_OK;
        gOptionSelectMenu->mOkChosen = TRUE;
        StopPaletteBlend();
        MaybePlaySomeSseqFromSarc0(5);
    } else if (touchedRect == OPTION_SELECT_ROW_SOUND) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        MaybePlaySomeSseqFromSarc0(10);
    } else if (touchedRect == OPTION_SELECT_ROW_LOCATE_FRIEND) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_LOCATE_FRIEND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        MaybePlaySomeSseqFromSarc0(1);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gOptionSelectMenu->mIndex--;
        if (gOptionSelectMenu->mIndex < 0) {
            gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_OK;
        }
        MaybePlaySomeSseqFromSarc0(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 || (gOptionSelectMenu->mIndex != OPTION_SELECT_ROW_OK &&
                                                            (u16) (g_GlobalCYT[idx].mPressedBits & PAD_KEY_A) != 0)) {
        gOptionSelectMenu->mIndex++;
        if (gOptionSelectMenu->mIndex > OPTION_SELECT_ROW_OK) {
            gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
        }
        MaybePlaySomeSseqFromSarc0(0);
    } else if (gOptionSelectMenu->mIndex != OPTION_SELECT_ROW_OK && GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = OPTION_SELECT_OFFSET_TIMER_FRAMES;
        if (gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_SOUND) {
            MaybePlaySomeSseqFromSarc0(10);
        } else {
            MaybePlaySomeSseqFromSarc0(1);
        }
    } else if (gOptionSelectMenu->mIndex != OPTION_SELECT_ROW_OK && GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
            gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = OPTION_SELECT_OFFSET_TIMER_FRAMES;
        }
        if (gOptionSelectMenu->mIndex == OPTION_SELECT_ROW_SOUND) {
            MaybePlaySomeSseqFromSarc0(10);
        } else {
            MaybePlaySomeSseqFromSarc0(1);
        }
    } else if (touchedRect == 3) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = OPTION_SELECT_OFFSET_TIMER_FRAMES;
        MaybePlaySomeSseqFromSarc0(10);
    } else if (touchedRect == 4) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_SOUND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = OPTION_SELECT_OFFSET_TIMER_FRAMES;
        MaybePlaySomeSseqFromSarc0(10);
    } else if (touchedRect == 5) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_LOCATE_FRIEND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = OPTION_SELECT_OFFSET_TIMER_FRAMES;
        MaybePlaySomeSseqFromSarc0(1);
    } else if (touchedRect == 6) {
        gOptionSelectMenu->mIndex = OPTION_SELECT_ROW_LOCATE_FRIEND;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = OPTION_SELECT_OFFSET_TIMER_FRAMES;
        MaybePlaySomeSseqFromSarc0(1);
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

void AdvanceOptionSelectMenuOkPressedDelay(void) {
    gOptionSelectMenu->mStateFrames++;
    if (gOptionSelectMenu->mStateFrames >= OPTION_SELECT_PRESS_FRAMES) {
        gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_SLIDE_OUT;
        gOptionSelectMenu->mStateFrames = 0;
    } else if (gOptionSelectMenu->mStateFrames >= OPTION_SELECT_HIGHLIGHT_FRAME) {
        gOptionSelectMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionSelectMenuSlideOut(void) {
    s32 groupIndex;
    s32 entryIndex;
    s16 offsetX;
    void *text;
    void *buttonText;

    gOptionSelectMenu->mBg0Bg1Offset = ComputeValueInterpolation_from_thumb(1, 0, -OPTION_SELECT_BG_SLIDE_DISTANCE,
                                                      gOptionSelectMenu->mStateFrames, OPTION_SELECT_SLIDE_FRAMES);
    gOptionSelectMenu->mStateFrames++;
    offsetX =
        ComputeValueInterpolation_from_thumb(1, 0, OPTION_SELECT_SLIDE_DISTANCE, gOptionSelectMenu->mStateFrames, OPTION_SELECT_SLIDE_FRAMES);
    for (groupIndex = 0; groupIndex < 2; groupIndex++) {
        for (entryIndex = 0; entryIndex < gOptionSelectMenuGroupSTableCounts[groupIndex]; entryIndex++) {
            if (groupIndex == 1) {
                gOptionSelectMenu->mGroupOffsets[groupIndex].mOffsetX = -offsetX;
            } else {
                gOptionSelectMenu->mGroupOffsets[groupIndex].mOffsetX = offsetX;
            }
        }
    }
    gOptionSelectMenu->mGroupOffsets[2].mOffsetY =
        -LookupSelectReturnSlideOutBg2Offset(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= OPTION_SELECT_SLIDE_FRAMES) {
        if (gOptionSelectMenu->mStateFrames >= OPTION_SELECT_SLIDE_FRAMES && IsSelectReturnShownNoRequest() != 0) {
            gOptionSelectMenu->mBg1Visible = FALSE;
            if (gOptionSelectMenu->mOkChosen != FALSE) {
                TextSystem_SetFadeInSseqId_from_thumb(0x21);
                text = Bmg_GetRawStringPointer_from_thumb(gOptionSelectMenu->mOptionMessages, 0x10);
                buttonText = Bmg_GetRawStringPointer_from_thumb(gOptionSelectMenu->mCommonMessages, 4);
                TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(text, buttonText);
                gOptionSelectMenu->mNextState = OPTION_SELECT_STATE_WAIT_BACKUP;
                gOptionSelectMenu->mStateFrames = 0;
                RequestSelectReturnSlideOut();
            } else {
                RequestOptionState(gOptionSelectMenu->mNextOptionState);
            }
        }
    }
}

void AdvanceOptionSelectMenuWaitBackup(void) {
    s32 backupBusy;

    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        if (g_SaveDataHolder->mBusy == 0) {
            if (g_SaveDataIoManager->mBackupEnabled != 0) {
                backupBusy = g_SaveDataIoManager->mCommandRunning;
            } else {
                backupBusy = 0;
            }
        } else {
            backupBusy = 1;
        }
        if (backupBusy == 0) {
            TextSystem_SetFadeInSseqId_from_thumb(0x23);
            TextSystem_CloseDialog_from_thumb();
            RequestSelectReturnSlideIn();
        }
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0 && IsSelectReturnShownNoRequest() != 0) {
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
                .mOffsetX -=
                LookupFrameOffset(OPTION_SELECT_OFFSET_TIMER_FRAMES - gOptionSelectMenu->mOffsetTimers[index][0]);
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[index][entryIndex][1]]
                .mOffsetX +=
                LookupFrameOffset(OPTION_SELECT_OFFSET_TIMER_FRAMES - gOptionSelectMenu->mOffsetTimers[index][1]);
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
            AdvanceOptionSelectMenuSlideIn();
            break;
        case OPTION_SELECT_STATE_SLIDE_IN_BG2:
            AdvanceOptionSelectMenuSlideInBg2();
            break;
        case OPTION_SELECT_STATE_WAIT_INPUT:
            AdvanceOptionSelectMenuWaitInput();
            break;
        case OPTION_SELECT_STATE_OK_PRESSED_DELAY:
            AdvanceOptionSelectMenuOkPressedDelay();
            break;
        case OPTION_SELECT_STATE_SLIDE_OUT:
            AdvanceOptionSelectMenuSlideOut();
            break;
        case OPTION_SELECT_STATE_WAIT_BACKUP:
            AdvanceOptionSelectMenuWaitBackup();
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
