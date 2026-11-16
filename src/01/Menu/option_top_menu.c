#include "01/Menu/option_top_menu.h"
#include "display_blend_affine_setup.h"
#include "registers.h"

#include "01/Menu/option_nickname_scenes.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/record_gpx_grade_text.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_reset.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/txt_system.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Menu/record_vs.h"
#include "Main/Sound/sound_system.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u8 gOptionTopMenuOffsetTableIndices[3][4] = {{0, 3, 6, 9}, {1, 4, 7, 0xa}, {2, 5, 8, 0xb}};
const s32 gOptionTopMenuOffsetCellCounts[3] = {4, 4, 4};
OptionStateCallbacks gOptionTopMenuCallbacks = {InitOptionTopMenu, ReleaseOptionTopMenu, AdvanceOptionTopMenu,
                                                WriteOptionTopMenuRegisters};
const u8 gOptionTopMenuSTableIndices[3] = {6, 7, 8};
const u8 gOptionTopMenuXluCellIndices[3] = {0, 1, 2};
const u8 gOptionTopMenuCellIndices[3] = {9, 0xa, 0xb};
OptionTopMenu *gOptionTopMenu;

void InitOptionTopMenu(void *heap) {
    s32 index;
    s32 cellIndex;

    gOptionTopMenu = Mem_AllocateHeap(heap, sizeof(OptionTopMenu));
    gOptionTopMenu->mHeap = heap;
    gOptionTopMenu->mState = OPTION_TOP_STATE_WAIT_FADE;
    gOptionTopMenu->mNextState = OPTION_TOP_STATE_WAIT_FADE;
    switch (GetOptionPrevState()) {
        case OPTION_STATE_SELECT_MENU:
        case OPTION_STATE_SCENE_TITLE:
            gOptionTopMenu->mIndex = OPTION_TOP_ROW_SETTINGS;
            break;
        case OPTION_STATE_HENSYU_MENU:
            gOptionTopMenu->mIndex = OPTION_TOP_ROW_EDIT;
            break;
    }
    gOptionTopMenu->mStateFrames = 0;
    gOptionTopMenu->mHighlightVisible = TRUE;
    gOptionTopMenu->mOptionMessages = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("option.bmg");
    gOptionTopMenu->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
    if (GetOptionPrevState() == OPTION_STATE_SELECT_MENU) {
        gOptionTopMenu->mBg0Offset = OPTION_TOP_BG0_SLIDE_DISTANCE;
    } else {
        gOptionTopMenu->mBg0Offset = 0;
    }
    LocateAndQueueOptionTopMenu();
    for (index = 0; index < 3; index++) {
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(gOptionTopMenuXluCellIndices[index], 1, gOptionTopMenu->mOptionTopMenuSNcer,
                          gOptionTopMenu->mOptionTopMenuSBncl);
    }
    OamBuffer_SomeFn_from_thumb(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    InitLayoutTable(heap, gOptionTopMenu->mOptionTopMenuSBncl, NULL, &gOptionTopMenu->mOptionTopMenuSTable);
    for (index = 0; index < 3; index++) {
        for (cellIndex = 0; cellIndex < gOptionTopMenuOffsetCellCounts[index]; cellIndex++) {
            if (index == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[index][cellIndex]].mOffsetX =
                    OPTION_TOP_SLIDE_DISTANCE;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[index][cellIndex]].mOffsetX =
                    -OPTION_TOP_SLIDE_DISTANCE;
            }
        }
    }
    SetSelectReturnSoundId(0xf);
}

void ReleaseOptionTopMenu(void) {
    gOptionTopMenu = NULL;
}

void LocateAndQueueOptionTopMenu(void) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;

    MaybeReadCharBlock_1(&ncgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_top_menu_m_b.ncgr"));
    MaybeReadScreenBlock(&nscr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_top_menu_m.nscr"));
    Gfx_ReadPaletteRelative(&nclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_top_menu_m_b.nclr"));
    gOptionTopMenu->mOptionTopMenuSBncl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_top_menu_s.bncl");
    gOptionTopMenu->mOptionTopMenuSBnbl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_top_menu_s.bnbl");
    Gfx_ReadCharGraphicsRelative(&gOptionTopMenu->mOptionTopMenuSNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_top_menu_s.nce.ncgr"));
    LocateNcer(&gOptionTopMenu->mOptionTopMenuSNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_top_menu_s.nce.ncer"));
    Gfx_ReadPaletteRelative(&gOptionTopMenu->mOptionTopMenuSONclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Option_top_menu_s_o.nclr"));
    AllocateReserveTEQSub(4, 0, ncgr->mData, ncgr->mDataSize);
    AllocateReserveTEQSub(8, 0, nscr->mData, nscr->mDataSize);
    AllocateReserveTEQSub(15, 0, nclr->mData, 0x100);
    AllocateReserveTEQSub(0x23, 0, gOptionTopMenu->mOptionTopMenuSNcgr->mData,
                                       gOptionTopMenu->mOptionTopMenuSNcgr->mDataSize);
    AllocateReserveTEQSub(0x1e, 0, gOptionTopMenu->mOptionTopMenuSONclr->mData,
                                       gOptionTopMenu->mOptionTopMenuSONclr->mDataSize);
}

void AdvanceOptionTopMenuWaitFade(void) {
    int fadesClear;
    fadesClear = Bright_IsBothScreensFadedIn();
    if (fadesClear != 0) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_IN;
    }
}

void AdvanceOptionTopMenuSlideIn(void) {
    s32 amount;
    s32 rowIndex;
    s32 cellIndex;

    gOptionTopMenu->mStateFrames++;
    amount = ComputeValueInterpolation_from_thumb(1, OPTION_TOP_SLIDE_DISTANCE, 0, gOptionTopMenu->mStateFrames, OPTION_TOP_SLIDE_FRAMES);
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionTopMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    -amount;
            }
        }
    }
    if (GetOptionPrevState() == OPTION_STATE_SELECT_MENU && gOptionTopMenu->mIndex != OPTION_TOP_ROW_ERASE_DATA) {
        gOptionTopMenu->mBg0Offset =
            ComputeValueInterpolation_from_thumb(1, OPTION_TOP_BG0_SLIDE_DISTANCE, 0, gOptionTopMenu->mStateFrames, OPTION_TOP_SLIDE_FRAMES);
    }
    if (gOptionTopMenu->mStateFrames >= OPTION_TOP_SLIDE_FRAMES) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_WAIT_SELECT_RETURN;
        gOptionTopMenu->mStateFrames = 0;
        RequestSelectReturnSlideIn();
    }
}

void AdvanceOptionTopMenuWaitSelectReturn(void) {
    int returnShownNoRequest;
    returnShownNoRequest = IsSelectReturnShownNoRequest();
    if (returnShownNoRequest != 0) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_INPUT;
    }
}

void AdvanceOptionTopMenuInput(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    u32 touchedRect = -1;
    BOOL touchBegan = FALSE;
    BOOL recentlyLost = FALSE;
    u16 keyBPressed;
    s32 previousIndex;
    s32 keyAPressed;

    if (g_GlobalCYT[slotIndex].mPair.mHasPair == 0 &&
        g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 &&
        g_GlobalCYT[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRect = RectTableFindContaining(gOptionTopMenu->mOptionTopMenuSBnbl, g_GlobalCYT[slotIndex].mPair.mPairX,
                                              g_GlobalCYT[slotIndex].mPair.mPairY);
    }
    keyBPressed = g_GlobalCYT[slotIndex].mPressedBits & PAD_KEY_B;
    if (keyBPressed == 0) {
        BOOL touchBeganAgain = FALSE;
        BOOL recentlyLostAgain = FALSE;
        if (g_GlobalCYT[slotIndex].mPair.mHasPair == 0 &&
            g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            recentlyLostAgain = TRUE;
        }
        if (recentlyLostAgain == FALSE && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 &&
            g_GlobalCYT[slotIndex].mPair.mHasPair != 0) {
            touchBeganAgain = TRUE;
        }
        if (touchBeganAgain != FALSE &&
            IsSelectReturnShownNoRequestAndInRect(g_GlobalCYT[slotIndex].mPair.mPairX,
                                                  g_GlobalCYT[slotIndex].mPair.mPairY) != FALSE) {
            goto leave;
        }
    } else {
    leave:
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_OUT;
        gOptionTopMenu->mNextOptionState = OPTION_STATE_SCENE_TITLE;
        RequestSelectReturnPressWithSound(1);
        return;
    }
    keyAPressed = g_GlobalCYT[slotIndex].mPressedBits & PAD_KEY_A;
    if ((u16) keyAPressed != 0 || touchedRect <= 2) {
        previousIndex = gOptionTopMenu->mIndex;
        if ((u16) keyAPressed == 0) {
            switch (touchedRect) {
                case OPTION_TOP_ROW_SETTINGS:
                    gOptionTopMenu->mIndex = OPTION_TOP_ROW_SETTINGS;
                    break;
                case OPTION_TOP_ROW_EDIT:
                    gOptionTopMenu->mIndex = OPTION_TOP_ROW_EDIT;
                    break;
                case OPTION_TOP_ROW_ERASE_DATA:
                    gOptionTopMenu->mIndex = OPTION_TOP_ROW_ERASE_DATA;
                    break;
            }
        }
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_PRESS;
        switch (gOptionTopMenu->mIndex) {
            case OPTION_TOP_ROW_SETTINGS:
                gOptionTopMenu->mNextOptionState = OPTION_STATE_SELECT_MENU;
                break;
            case OPTION_TOP_ROW_EDIT:
                gOptionTopMenu->mNextOptionState = OPTION_STATE_HENSYU_MENU;
                break;
            case OPTION_TOP_ROW_ERASE_DATA:
                break;
        }
        if (gOptionTopMenu->mIndex == previousIndex) {
            gOptionTopMenu->mHighlightVisible = FALSE;
        }
        MaybePlaySomeSseqFromSarc0(5);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gOptionTopMenu->mIndex--;
        if (gOptionTopMenu->mIndex < 0) {
            gOptionTopMenu->mIndex = OPTION_TOP_ROW_ERASE_DATA;
        }
        MaybePlaySomeSseqFromSarc0(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gOptionTopMenu->mIndex++;
        if (gOptionTopMenu->mIndex > OPTION_TOP_ROW_ERASE_DATA) {
            gOptionTopMenu->mIndex = OPTION_TOP_ROW_SETTINGS;
        }
        MaybePlaySomeSseqFromSarc0(0);
    }
}

void AdvanceOptionTopMenuPress(void) {
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames >= OPTION_TOP_PRESS_FRAMES) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_OUT;
        gOptionTopMenu->mStateFrames = 0;
        if (gOptionTopMenu->mIndex == OPTION_TOP_ROW_ERASE_DATA) {
            RequestSelectReturnSlideOut();
        }
    } else if (gOptionTopMenu->mStateFrames >= OPTION_TOP_HIGHLIGHT_FRAME) {
        gOptionTopMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionTopMenuSlideOut(void) {
    s32 amount;
    s32 rowIndex;
    s32 cellIndex;

    if (GetOptionNextScene() == -1 && gOptionTopMenu->mNextOptionState == OPTION_STATE_SCENE_TITLE) {
        RequestOptionNextScene(0);
    }
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames <= OPTION_TOP_SLIDE_FRAMES) {
        amount = ComputeValueInterpolation_from_thumb(1, 0, OPTION_TOP_SLIDE_DISTANCE, gOptionTopMenu->mStateFrames, OPTION_TOP_SLIDE_FRAMES);
    } else {
        amount = OPTION_TOP_SLIDE_DISTANCE;
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionTopMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuOffsetTableIndices[rowIndex][cellIndex]].mOffsetX =
                    -amount;
            }
        }
    }
    if (gOptionTopMenu->mNextOptionState == OPTION_STATE_SELECT_MENU) {
        gOptionTopMenu->mBg0Offset =
            ComputeValueInterpolation_from_thumb(1, 0, OPTION_TOP_BG0_SLIDE_DISTANCE, gOptionTopMenu->mStateFrames, OPTION_TOP_SLIDE_FRAMES);
    }
    if (gOptionTopMenu->mStateFrames >= OPTION_TOP_SLIDE_FRAMES &&
        (gOptionTopMenu->mIndex != OPTION_TOP_ROW_ERASE_DATA || IsSelectReturnHiddenNoRequest() != 0) &&
        GetOptionNextScene() == -1) {
        if (gOptionTopMenu->mIndex == OPTION_TOP_ROW_ERASE_DATA) {
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_ASK_RESET;
            gOptionTopMenu->mStateFrames = 0;
            TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mOptionMessages, 3),
                                            Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mCommonMessages, 0),
                                            Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mCommonMessages, 1), 1);
        } else {
            RequestOptionState(gOptionTopMenu->mNextOptionState);
        }
    }
}

void AdvanceOptionTopMenuAskReset(void) {
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        if (TextSystem_IsButton2Focused_from_thumb() == 0) {
            TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mOptionMessages, 4),
                                            Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mCommonMessages, 0),
                                            Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mCommonMessages, 1), 1);
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_ASK_RESET_AGAIN;
        } else {
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_IN;
        }
    }
}

void AdvanceOptionTopMenuAskResetAgain(void) {
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        if (TextSystem_IsButton2Focused_from_thumb() == 0) {
            OverwriteEmptySaveData_from_thumb();
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_WAIT_RESET_WRITE;
            TextSystem_DisplayProgressDialog_from_thumb(Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mOptionMessages, 5), 1, 1, 1, 0, 1);
        } else {
            gOptionTopMenu->mNextState = OPTION_TOP_STATE_SLIDE_IN;
        }
    }
}

void AdvanceOptionTopMenuWaitResetWrite(void) {
    s32 flag;

    if (TextSystem_JustFadedIn_from_thumb() != 0) {
        PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x22);
    }
    if (g_SaveDataHolder->mBusy == 0) {
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            flag = g_SaveDataIoManager->mCommandRunning;
        } else {
            flag = 0;
        }
    } else {
        flag = 1;
    }
    if (flag == 0 && TextSystem_IsDialogIdle_from_thumb() != 0) {
        gOptionTopMenu->mNextState = OPTION_TOP_STATE_RESET_DONE;
        TextSystem_SetFadeInSseqId_from_thumb(0x21);
        TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mOptionMessages, 6),
                                    Bmg_GetRawStringPointer_from_thumb(gOptionTopMenu->mCommonMessages, 4));
    }
}

void AdvanceOptionTopMenuResetDone(void) {
    int queryResult;
    queryResult = GetOptionNextScene();
    if ((queryResult == -1) && (gOptionTopMenu->mNextOptionState == OPTION_STATE_SCENE_TITLE)) {
        RequestOptionNextScene(0);
    }
    queryResult = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (queryResult != 0) {
        TextSystem_SetFadeInSseqId_from_thumb(0x23);
        TextSystem_CloseDialog_from_thumb();
        gOptionTopMenu->mNextOptionState = OPTION_STATE_SCENE_TITLE;
    }
}

void UpdateOptionTopMenuHighlight(void) {
    int rowIndex;
    BOOL zero = FALSE;

    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        if (rowIndex == gOptionTopMenu->mIndex && gOptionTopMenu->mHighlightVisible != FALSE) {
            gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuSTableIndices[rowIndex]].mVisible = 1;
            SetCellPaletteIndex(gOptionTopMenuCellIndices[rowIndex], 14, gOptionTopMenu->mOptionTopMenuSNcer,
                                gOptionTopMenu->mOptionTopMenuSBncl);
        } else {
            gOptionTopMenu->mOptionTopMenuSTable[gOptionTopMenuSTableIndices[rowIndex]].mVisible = zero;
            SetCellPaletteIndex(gOptionTopMenuCellIndices[rowIndex], 15, gOptionTopMenu->mOptionTopMenuSNcer,
                                gOptionTopMenu->mOptionTopMenuSBncl);
        }
    }
}

void AdvanceOptionTopMenu(void) {
    OptionTopMenu *optionTopMenu;

    gOptionTopMenu->mState = gOptionTopMenu->mNextState;
    switch (gOptionTopMenu->mState) {
        case OPTION_TOP_STATE_WAIT_FADE:
            AdvanceOptionTopMenuWaitFade();
            break;
        case OPTION_TOP_STATE_SLIDE_IN:
            AdvanceOptionTopMenuSlideIn();
            break;
        case OPTION_TOP_STATE_WAIT_SELECT_RETURN:
            AdvanceOptionTopMenuWaitSelectReturn();
            break;
        case OPTION_TOP_STATE_INPUT:
            AdvanceOptionTopMenuInput();
            break;
        case OPTION_TOP_STATE_PRESS:
            AdvanceOptionTopMenuPress();
            break;
        case OPTION_TOP_STATE_SLIDE_OUT:
            AdvanceOptionTopMenuSlideOut();
            break;
        case OPTION_TOP_STATE_ASK_RESET:
            AdvanceOptionTopMenuAskReset();
            break;
        case OPTION_TOP_STATE_ASK_RESET_AGAIN:
            AdvanceOptionTopMenuAskResetAgain();
            break;
        case OPTION_TOP_STATE_WAIT_RESET_WRITE:
            AdvanceOptionTopMenuWaitResetWrite();
            break;
        case OPTION_TOP_STATE_RESET_DONE:
            AdvanceOptionTopMenuResetDone();
            break;
    }
    UpdateOptionTopMenuHighlight();
    optionTopMenu = gOptionTopMenu;
    DrawLayoutTable(optionTopMenu->mOptionTopMenuSBncl, optionTopMenu->mOptionTopMenuSNcer, NULL,
                    GetOptionSecondBuffer(), optionTopMenu->mOptionTopMenuSTable);
}

void WriteOptionTopMenuRegisters(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG0OFS = gOptionTopMenu->mBg0Offset << 0x10 & (0x01ff0000u);
}

void RegisterOptionTopMenuCallbacks(void) {
    OptionStateCallbacks callbacks = gOptionTopMenuCallbacks;

    SetOptionStateCallbacks(&callbacks);
}
