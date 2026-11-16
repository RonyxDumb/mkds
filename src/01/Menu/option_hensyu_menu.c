#include "01/Menu/option_hensyu_menu.h"
#include "registers.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/option_select_menu.h"
#include "01/Menu/nickname_scene.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Menu/select_return.h"
#include "01/Menu/option_nickname_scenes.h"
#include "01/Menu/record_gpx_grade_text.h"
#include "Main/Graphics/layout_rect_table.h"
#include "display_blend_affine_setup.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u8 gOptionHensyuMenuSTableIndices[2] = {4, 5};
const u8 gOptionHensyuMenuXluCellIndices[2] = {0, 1};
const u8 gOptionHensyuMenuCellIndices[2] = {6, 7};
const u8 gOptionHensyuMenuOffsetTableIndices[2][4] = {{0, 2, 4, 6}, {1, 3, 5, 7}};
const s32 gOptionHensyuMenuOffsetCellCounts[2] = {4, 4};
OptionHensyuMenu *gOptionHensyuMenu;

void InitOptionHensyuMenu(void *heap) {
    s32 index;
    s32 cellIndex;
    void *optionFirstBuffer;
    gOptionHensyuMenu = HeapAlloc(heap, sizeof(OptionHensyuMenu));
    gOptionHensyuMenu->mHeap = heap;
    gOptionHensyuMenu->mState = OPTION_HENSYU_MENU_STATE_WAIT_FADE;
    gOptionHensyuMenu->mNextState = OPTION_HENSYU_MENU_STATE_WAIT_FADE;
    switch (GetOptionPrevState()) {
        case OPTION_STATE_TOP_MENU:
        case OPTION_STATE_SCENE_KEYBOARD:
            gOptionHensyuMenu->mIndex = 0;
            break;
        case OPTION_STATE_EMBREM_SELECT:
        case OPTION_STATE_SCENE_EMBLEM:
            gOptionHensyuMenu->mIndex = 1;
            break;
    }
    gOptionHensyuMenu->mStateFrames = 0;
    gOptionHensyuMenu->mHighlightVisible = TRUE;
    LocateAndQueueOptionHensyuMenu();
    for (index = 0; index < 2; index++) {
        SetCellOamModeXlu(gOptionHensyuMenuXluCellIndices[index], 1, gOptionHensyuMenu->mOptionHensyuMenuSNcer,
                          gOptionHensyuMenu->mOptionHensyuMenuSBncl);
    }
    optionFirstBuffer = GetOptionFirstBuffer();
    ResetOamLists(optionFirstBuffer, GetOptionSecondBuffer());
    InitLayoutTable(heap, gOptionHensyuMenu->mOptionHensyuMenuSBncl, NULL, &gOptionHensyuMenu->mOptionHensyuMenuSTable);
    for (index = 0; index < 2; index++) {
        for (cellIndex = 0; cellIndex < gOptionHensyuMenuOffsetCellCounts[index]; cellIndex++) {
            if (index == 1) {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[gOptionHensyuMenuOffsetTableIndices[index][cellIndex]]
                    .mOffsetX = OPTION_HENSYU_MENU_SLIDE_DISTANCE;
            } else {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[gOptionHensyuMenuOffsetTableIndices[index][cellIndex]]
                    .mOffsetX = -OPTION_HENSYU_MENU_SLIDE_DISTANCE;
            }
        }
    }
    SetSelectReturnSoundId(SELECT_RETURN_SOUND_ID);
}

void ReleaseOptionHensyuMenu(void) {
    gOptionHensyuMenu = NULL;
}

void LocateAndQueueOptionHensyuMenu(void) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;

    LocateNcgr(&ncgr, FindSceneFile("Option_top_menu_m_b.ncgr"));
    LocateNscr(&nscr, FindSceneFile("Option_top_menu_m.nscr"));
    LocateNclr(&nclr, FindSceneFile("Option_top_menu_m_b.nclr"));
    gOptionHensyuMenu->mOptionHensyuMenuSBncl = FindSceneFile("option_hensyu_menu_s.bncl");
    gOptionHensyuMenu->mOptionHensyuMenuSBnbl = FindSceneFile("option_hensyu_menu_s.bnbl");
    LocateNcgr2(&gOptionHensyuMenu->mOptionHensyuMenuSNcgr, FindSceneFile("Option_hensyu_menu_s.nce.ncgr"));
    LocateNcer(&gOptionHensyuMenu->mOptionHensyuMenuSNcer, FindSceneFile("Option_hensyu_menu_s.nce.ncer"));
    LocateNclr(&gOptionHensyuMenu->mOptionHensyuMenuSONclr, FindSceneFile("Option_hensyu_menu_s_o.nclr"));
    NNS_GfdRegisterNewVramTransferTask(4, 0, ncgr->mData, ncgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, nscr->mData, nscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(15, 0, nclr->mData, 0x100);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gOptionHensyuMenu->mOptionHensyuMenuSNcgr->mData,
                                       gOptionHensyuMenu->mOptionHensyuMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gOptionHensyuMenu->mOptionHensyuMenuSONclr->mData,
                                       gOptionHensyuMenu->mOptionHensyuMenuSONclr->mDataSize);
}

void AdvanceOptionHensyuMenuWaitFade(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        gOptionHensyuMenu->mNextState = OPTION_HENSYU_MENU_STATE_SLIDE_IN;
    }
}

void AdvanceOptionHensyuMenuSlideIn(void) {
    s32 rowIndex;
    s32 cellIndex;
    s32 offsetX;
    gOptionHensyuMenu->mStateFrames++;
    offsetX = InterpolateS16(1, OPTION_HENSYU_MENU_SLIDE_DISTANCE, 0, gOptionHensyuMenu->mStateFrames,
                             OPTION_HENSYU_MENU_SLIDE_FRAMES);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionHensyuMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[gOptionHensyuMenuOffsetTableIndices[rowIndex][cellIndex]]
                    .mOffsetX = offsetX;
            } else {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[gOptionHensyuMenuOffsetTableIndices[rowIndex][cellIndex]]
                    .mOffsetX = -offsetX;
            }
        }
    }
    if (gOptionHensyuMenu->mStateFrames >= OPTION_HENSYU_MENU_SLIDE_FRAMES) {
        gOptionHensyuMenu->mNextState = OPTION_HENSYU_MENU_STATE_WAIT_SELECT_RETURN;
        gOptionHensyuMenu->mStateFrames = 0;
        RequestSelectReturnSlideIn();
    }
}

void AdvanceOptionHensyuMenuWaitSelectReturn(void) {
    int returnShownNoRequest;
    returnShownNoRequest = IsSelectReturnShownNoRequest();
    if (returnShownNoRequest != 0) {
        gOptionHensyuMenu->mNextState = OPTION_HENSYU_MENU_STATE_SELECT;
    }
}

void AdvanceOptionHensyuMenuSelect(void) {
    u32 touchedRect;
    BOOL touchBegan;
    BOOL recentlyLost;
    u16 hasPair;
    s32 previousIndex;
    OptionHensyuMenu *optionHensyuMenu;
    InputSlotIndex slotIndex;

    slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    touchedRect = -1;
    touchBegan = FALSE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRect = RectTableFindContaining(gOptionHensyuMenu->mOptionHensyuMenuSBnbl,
                                              gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY);
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        touchBegan = FALSE;
        recentlyLost = FALSE;
        hasPair = gInputSlots[slotIndex].mPair.mHasPair;
        if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
            touchBegan = TRUE;
        }
        if (touchBegan != FALSE &&
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) != FALSE) {
            goto leave;
        }
    } else {
    leave:
        gOptionHensyuMenu->mNextState = OPTION_HENSYU_MENU_STATE_SLIDE_OUT;
        gOptionHensyuMenu->mNextOptionState = OPTION_STATE_TOP_MENU;
        RequestSelectReturnPressWithSound(0);
        return;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0 || touchedRect <= 1) {
        optionHensyuMenu = gOptionHensyuMenu;
        previousIndex = optionHensyuMenu->mIndex;
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) == 0) {
            switch (touchedRect) {
                case 0:
                    optionHensyuMenu->mIndex = 0;
                    break;
                case 1:
                    optionHensyuMenu->mIndex = 1;
                    break;
            }
        }
        gOptionHensyuMenu->mNextState = OPTION_HENSYU_MENU_STATE_HOLD_CHOSEN;
        optionHensyuMenu = gOptionHensyuMenu;
        switch (optionHensyuMenu->mIndex) {
            case 0:
                optionHensyuMenu->mNextOptionState = OPTION_STATE_SCENE_KEYBOARD;
                break;
            case 1:
                if (gBackupBuffers->mEmblemRecord->mFilled != 0) {
                    optionHensyuMenu->mNextOptionState = OPTION_STATE_EMBREM_SELECT;
                } else {
                    optionHensyuMenu->mNextOptionState = OPTION_STATE_SCENE_EMBLEM;
                    gMenuShared->mOptionReturnsToEmbremSelect = FALSE;
                }
                break;
        }
        if (gOptionHensyuMenu->mIndex == previousIndex) {
            gOptionHensyuMenu->mHighlightVisible = FALSE;
        }
        StartSoundOncePerFrame(5);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        if (gOptionHensyuMenu->mIndex > 0) {
            gOptionHensyuMenu->mIndex--;
            StartSoundOncePerFrame(0);
            return;
        }
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        if (gOptionHensyuMenu->mIndex < 1) {
            gOptionHensyuMenu->mIndex++;
            StartSoundOncePerFrame(0);
        }
    }
}

void AdvanceOptionHensyuMenuHoldChosen(void) {
    gOptionHensyuMenu->mStateFrames++;
    if (gOptionHensyuMenu->mStateFrames >= OPTION_HENSYU_MENU_PRESS_FRAMES) {
        gOptionHensyuMenu->mNextState = OPTION_HENSYU_MENU_STATE_SLIDE_OUT;
        gOptionHensyuMenu->mStateFrames = 0;
        if (gOptionHensyuMenu->mNextOptionState == OPTION_STATE_SCENE_KEYBOARD) {
            RequestSelectReturnSlideOut();
        }
    } else if (gOptionHensyuMenu->mStateFrames >= OPTION_HENSYU_MENU_HIGHLIGHT_FRAME) {
        gOptionHensyuMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionHensyuMenuSlideOut(void) {
    s32 rowIndex;
    s32 cellIndex;
    s32 offsetX;
    if (GetOptionNextScene() == -1) {
        if (gOptionHensyuMenu->mNextOptionState == OPTION_STATE_SCENE_KEYBOARD) {
            RequestOptionNextScene(0xe);
        } else if (gOptionHensyuMenu->mNextOptionState == OPTION_STATE_SCENE_EMBLEM) {
            RequestOptionNextScene(3);
        }
    }
    gOptionHensyuMenu->mStateFrames++;
    if (gOptionHensyuMenu->mStateFrames <= OPTION_HENSYU_MENU_SLIDE_FRAMES) {
        offsetX = InterpolateS16(1, 0, OPTION_HENSYU_MENU_SLIDE_DISTANCE, gOptionHensyuMenu->mStateFrames,
                                 OPTION_HENSYU_MENU_SLIDE_FRAMES);
    } else {
        offsetX = OPTION_HENSYU_MENU_SLIDE_DISTANCE;
    }
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (cellIndex = 0; cellIndex < gOptionHensyuMenuOffsetCellCounts[rowIndex]; cellIndex++) {
            if (rowIndex == 1) {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[gOptionHensyuMenuOffsetTableIndices[rowIndex][cellIndex]]
                    .mOffsetX = offsetX;
            } else {
                gOptionHensyuMenu->mOptionHensyuMenuSTable[gOptionHensyuMenuOffsetTableIndices[rowIndex][cellIndex]]
                    .mOffsetX = -offsetX;
            }
        }
    }
    if (gOptionHensyuMenu->mStateFrames >= OPTION_HENSYU_MENU_SLIDE_FRAMES) {
        if (gOptionHensyuMenu->mNextOptionState == OPTION_STATE_TOP_MENU ||
            gOptionHensyuMenu->mNextOptionState == OPTION_STATE_EMBREM_SELECT || IsSelectReturnHiddenNoRequest() != 0) {
            if (GetOptionNextScene() == -1) {
                RequestOptionState(gOptionHensyuMenu->mNextOptionState);
            }
        }
    }
}

void UpdateOptionHensyuMenuHighlight(void) {
    s32 rowIndex;
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        if (rowIndex == gOptionHensyuMenu->mIndex && gOptionHensyuMenu->mHighlightVisible != FALSE) {
            gOptionHensyuMenu->mOptionHensyuMenuSTable[gOptionHensyuMenuSTableIndices[rowIndex]].mVisible = 1;
            SetCellPaletteIndex(gOptionHensyuMenuCellIndices[rowIndex], 0xe, gOptionHensyuMenu->mOptionHensyuMenuSNcer,
                                gOptionHensyuMenu->mOptionHensyuMenuSBncl);
        } else {
            gOptionHensyuMenu->mOptionHensyuMenuSTable[gOptionHensyuMenuSTableIndices[rowIndex]].mVisible = 0;
            SetCellPaletteIndex(gOptionHensyuMenuCellIndices[rowIndex], 0xf, gOptionHensyuMenu->mOptionHensyuMenuSNcer,
                                gOptionHensyuMenu->mOptionHensyuMenuSBncl);
        }
    }
}

void AdvanceOptionHensyuMenu(void) {
    OptionHensyuMenu *optionHensyuMenu;
    gOptionHensyuMenu->mState = gOptionHensyuMenu->mNextState;
    switch (gOptionHensyuMenu->mState) {
        case OPTION_HENSYU_MENU_STATE_WAIT_FADE:
            AdvanceOptionHensyuMenuWaitFade();
            break;
        case OPTION_HENSYU_MENU_STATE_SLIDE_IN:
            AdvanceOptionHensyuMenuSlideIn();
            break;
        case OPTION_HENSYU_MENU_STATE_WAIT_SELECT_RETURN:
            AdvanceOptionHensyuMenuWaitSelectReturn();
            break;
        case OPTION_HENSYU_MENU_STATE_SELECT:
            AdvanceOptionHensyuMenuSelect();
            break;
        case OPTION_HENSYU_MENU_STATE_HOLD_CHOSEN:
            AdvanceOptionHensyuMenuHoldChosen();
            break;
        case OPTION_HENSYU_MENU_STATE_SLIDE_OUT:
            AdvanceOptionHensyuMenuSlideOut();
            break;
    }
    UpdateOptionHensyuMenuHighlight();
    optionHensyuMenu = gOptionHensyuMenu;
    DrawLayoutTable(optionHensyuMenu->mOptionHensyuMenuSBncl, optionHensyuMenu->mOptionHensyuMenuSNcer, NULL,
                    GetOptionSecondBuffer(), optionHensyuMenu->mOptionHensyuMenuSTable);
}

void WriteOptionHensyuMenuRegisters(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterOptionHensyuMenuCallbacks(void) {
    OptionStateCallbacks callbacks = {InitOptionHensyuMenu, ReleaseOptionHensyuMenu, AdvanceOptionHensyuMenu,
                                WriteOptionHensyuMenuRegisters};
    SetOptionStateCallbacks(&callbacks);
}
