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

const u8 gOptionSelectMenuMLabelIndices[2] = {0, 1};
const u8 gOptionSelectMenuXluCellIndices[2] = {0, 1};
const u8 gOptionSelectMenuValueCounts[2] = {3, 2};
const u8 gOptionSelectMenuOffsetMIndices[1] = {0};
const u8 gOptionSelectMenuRowSTableIndices[3] = {5, 6, 7};
const u8 gOptionSelectMenuSLabelIndices[3] = {0, 1, 2};
const u8 gOptionSelectMenuValueSTableIndices[3][3] = {{0x14, 0x15, 0x16}, {0x17, 0x18, 0}, {0, 0, 0}};
const s32 gOptionSelectMenuGroupSTableCounts[3] = {0xc, 0xb, 2};
const u8 gOptionSelectMenuTimerSTableIndices[2][3][2] = {{{0x10, 0x11}, {0xc, 0xd}, {8, 9}}, {{0x12, 0x13}, {0xe, 0xf}, {0xa, 0xb}}};
const u8 gOptionSelectMenuGroupSTableIndices[3][12] = {{0, 2, 5, 0xc, 0xd, 8, 9, 0x10, 0x11, 0x14, 0x15, 0x16}, {1, 3, 6, 0xe, 0xf, 0xa, 0xb, 0x12, 0x13, 0x17, 0x18, 0}, {4, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
OptionSelectMenu *gOptionSelectMenu;

void InitOptionSelectMenuTexts(void) {
    s32 i;

    {
        s32 v0 = 0x8000;
        u8 a[2][2] = {{0xdc, 0x10}, {0xf0, 0x50}};
        s32 c[2] = {0xb, 0xc};

        for (i = 0; i < 2; i++) {
            v0 -= InitLabelCanvas(gOptionSelectMenu->mHeap, gOptionSelectMenuMLabelIndices[i],
                                  gOptionSelectMenu->mOptionSelectMenuMBnll, a[i][0], a[i][1], i,
                                  gOptionSelectMenu->mOptionSelectMenuMNcer, gOptionSelectMenu->mOptionSelectMenuMBncl,
                                  gOptionSelectMenu->mOptionSelectMenuMTable, v0);
            PrintLabelLayoutTextNoFixedAdvance(
                0, gOptionSelectMenuMLabelIndices[i], gOptionSelectMenu->mOptionSelectMenuMBnll,
                GetBmgEntry(gOptionSelectMenu->mOptionMessages, c[i]), gOptionSelectMenu->mOptionSelectMenuMBncl,
                gOptionSelectMenu->mOptionSelectMenuMTable);
        }
    }
    {
        s32 v2 = GX_GetSizeOfSubOBJ();
        void *v1;
        u8 b[3][2] = {{0x9b, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
        s32 d[3] = {0, 2, 4};

        for (i = 0; i < 3; i++) {
            v1 = gOptionSelectMenu->mOptionMessages;
            if (i == 2) {
                v1 = gOptionSelectMenu->mCommonMessages;
            }
            v2 -= InitLabelCanvas(
                gOptionSelectMenu->mHeap, gOptionSelectMenuSLabelIndices[i], gOptionSelectMenu->mOptionSelectMenuSBnll,
                b[i][0], b[i][1], gOptionSelectMenuRowSTableIndices[i], gOptionSelectMenu->mOptionSelectMenuSNcer,
                gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSTable, v2);
            PrintLabelLayoutTextNoFixedAdvance(
                1, gOptionSelectMenuSLabelIndices[i], gOptionSelectMenu->mOptionSelectMenuSBnll, GetBmgEntry(v1, d[i]),
                gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSTable);
        }
    }
}

void InitOptionSelectMenu(void *a) {
    s32 i;

    gOptionSelectMenu = HeapAlloc(a, 0x90);
    gOptionSelectMenu->mHeap = a;
    gOptionSelectMenu->mState = 0;
    gOptionSelectMenu->mNextState = 0;
    gOptionSelectMenu->mIndex = 0;
    gOptionSelectMenu->mStateFrames = 0;
    gOptionSelectMenu->mHighlightVisible = TRUE;
    LocateAndQueueOptionSelectMenu();
    InitPaletteBlend(a, gOptionSelectMenu->mOptionSelectMenuSONclr, 3);
    for (i = 0; i < 2; i++) {
        SetCellOamModeXlu(gOptionSelectMenuXluCellIndices[i], 1, gOptionSelectMenu->mOptionSelectMenuSNcer,
                          gOptionSelectMenu->mOptionSelectMenuSBncl);
    }
    ResetOamLists(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    InitLayoutTable(a, gOptionSelectMenu->mOptionSelectMenuMBncl, gOptionSelectMenu->mOptionSelectMenuMBnll,
                    &gOptionSelectMenu->mOptionSelectMenuMTable);
    InitLayoutTable(a, gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSBnll,
                    &gOptionSelectMenu->mOptionSelectMenuSTable);
    gOptionSelectMenu->mOptionMessages = FindSceneFile("option.bmg");
    gOptionSelectMenu->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitOptionSelectMenuTexts();
    gOptionSelectMenu->mBg0Bg1Offset = -140;
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            gOptionSelectMenu->mGroupOffsets[i].mOffsetX = 0;
            gOptionSelectMenu->mGroupOffsets[i].mOffsetY = 0x28;
        } else if (i == 1) {
            gOptionSelectMenu->mGroupOffsets[i].mOffsetX = 250;
            gOptionSelectMenu->mGroupOffsets[i].mOffsetY = 0;
        } else {
            gOptionSelectMenu->mGroupOffsets[i].mOffsetX = -250;
            gOptionSelectMenu->mGroupOffsets[i].mOffsetY = 0;
        }
    }
    SetOptionSoundRowFromSave();
    if (gBackupBuffers->mFirstBlock->mLocateFriendOff == 0) {
        gOptionSelectMenu->mRowValues[1] = 0;
    } else {
        gOptionSelectMenu->mRowValues[1] = 1;
    }
    for (i = 0; i < 2; i++) {
        gOptionSelectMenu->mSavedRowValues[i] = gOptionSelectMenu->mRowValues[i];
    }
    WriteOptionSelectMenuTableOffsets();
    SetOptionSelectMenuValuesOnOff();
    for (i = 0; i < 2; i++) {
        gOptionSelectMenu->mOffsetTimers[i][0] = 0;
        gOptionSelectMenu->mOffsetTimers[i][1] = 0;
    }
    gOptionSelectMenu->mOkChosen = FALSE;
    gOptionSelectMenu->mBg1Visible = TRUE;
    SetSelectReturnSoundId(0xe);
}

void ReleaseOptionSelectMenu(void) {
    u32 v;

    SetOptionSoundRowFromSave();
    ApplyOptionSelectMenuSound();
    v = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v & ~2) << 8);
    ClearPaletteBlendPointer();
    gOptionSelectMenu = NULL;
}

void LocateAndQueueOptionSelectMenu(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    LocateNcgr(&a, FindSceneFile("Option_select_menu_m_b.ncgr"));
    LocateNscr(&b, FindSceneFile("Option_select_menu_m.nscr"));
    LocateNclr(&c, FindSceneFile("Option_select_menu_m_b.nclr"));
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
    NNS_GfdRegisterNewVramTransferTask(5, 0, a->mData, a->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(9, 0, b->mData, b->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0x20, c->mData + 0x10, 0x20);
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
    switch (gOptionSelectMenu->mRowValues[0]) {
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
    switch (gOptionSelectMenu->mRowValues[0]) {
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
            gOptionSelectMenu->mRowValues[0] = SOUND_MODE_STEREO;
            break;
        case SOUND_MODE_SURROUND:
            gOptionSelectMenu->mRowValues[0] = SOUND_MODE_SURROUND;
            break;
        case SOUND_MODE_HEADPHONES:
            gOptionSelectMenu->mRowValues[0] = SOUND_MODE_HEADPHONES;
            break;
    }
}

void AdvanceOptionSelectMenuState0(void) {
    s32 i;
    s32 j;
    s16 v;

    gOptionSelectMenu->mStateFrames++;
    gOptionSelectMenu->mBg0Bg1Offset = InterpolateS16(1, -140, 0, gOptionSelectMenu->mStateFrames, 10);
    v = InterpolateS16(1, 250, 0, gOptionSelectMenu->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gOptionSelectMenuGroupSTableCounts[i]; j++) {
            if (i == 1) {
                gOptionSelectMenu->mGroupOffsets[i].mOffsetX = -v;
            } else {
                gOptionSelectMenu->mGroupOffsets[i].mOffsetX = v;
            }
        }
    }
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = 1;
        gOptionSelectMenu->mStateFrames = 0;
    }
}

void AdvanceOptionSelectMenuState1(void) {
    gOptionSelectMenu->mStateFrames++;
    gOptionSelectMenu->mGroupOffsets[2].mOffsetY = -LookupSelectReturnState1Bg2Offset(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = 2;
        gOptionSelectMenu->mStateFrames = 0;
    }
}

void AdvanceOptionSelectMenuState2(void) {
    OptionSelectMenu *p;
    s32 sel;
    s32 r5;
    BOOL hasB;
    BOOL hasA;
    s32 i;
    InputSlotIndex idx;
    u16 v;

    p = gOptionSelectMenu;
    sel = p->mIndex;
    idx = UNK_02175628_INDEX_8;
    hasB = FALSE;
    r5 = -1;
    hasA = FALSE;
    v = gInputSlots[idx].mPair.mHasPair;
    if (v == 0 && gInputSlots[idx].mPair.mNoPairCount < 5) {
        hasA = TRUE;
    }
    if (hasA == FALSE && gInputSlots[idx].mPair.mPrevHasPair == 0 && v != 0) {
        hasB = TRUE;
    }
    if (hasB != FALSE) {
        r5 = RectTableFindContaining(p->mOptionSelectMenuSBnbl, gInputSlots[idx].mPair.mPairX,
                                     gInputSlots[idx].mPair.mPairY);
    }
    if ((u16) (gInputSlots[idx].mPressedBits & PAD_KEY_B) != 0) {
        goto L1;
    } else {
        BOOL c = FALSE;
        BOOL d = FALSE;
        v = gInputSlots[idx].mPair.mHasPair;
        if (v == 0 && gInputSlots[idx].mPair.mNoPairCount < 5) {
            d = TRUE;
        }
        if (d == FALSE && gInputSlots[idx].mPair.mPrevHasPair == 0 && v != 0) {
            c = TRUE;
        }
        if (c != FALSE && IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[idx].mPair.mPairX,
                                                                          gInputSlots[idx].mPair.mPairY) != FALSE) {
        L1:
            gOptionSelectMenu->mNextState = 4;
            gOptionSelectMenu->mNextOptionState = 0;
            for (i = 0; i < 2; i++) {
                gOptionSelectMenu->mRowValues[i] = gOptionSelectMenu->mSavedRowValues[i];
            }
            RequestSelectReturnState3WithSound(0);
            goto end;
        }
    }
    if (((u16) (gInputSlots[idx].mPressedBits & PAD_KEY_A) != 0 && gOptionSelectMenu->mIndex == 2) || r5 == 2) {
        SetSoundModeFromOptionRow();
        if (gOptionSelectMenu->mRowValues[1] == 0) {
            gBackupBuffers->mFirstBlock->mUnk_31 &= ~0x10;
        } else {
            gBackupBuffers->mFirstBlock->mUnk_31 |= 0x10;
        }
        WriteBackupFirstBlockWrapper();
        if (gOptionSelectMenu->mIndex == 2) {
            gOptionSelectMenu->mHighlightVisible = FALSE;
        }
        gOptionSelectMenu->mNextState = 3;
        gOptionSelectMenu->mNextOptionState = 0;
        gOptionSelectMenu->mIndex = 2;
        gOptionSelectMenu->mOkChosen = TRUE;
        StopPaletteBlend();
        StartSoundOncePerFrame(5);
    } else if (r5 == 0) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        StartSoundOncePerFrame(10);
    } else if (r5 == 1) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        StartSoundOncePerFrame(1);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gOptionSelectMenu->mIndex--;
        if (gOptionSelectMenu->mIndex < 0) {
            gOptionSelectMenu->mIndex = 2;
        }
        StartSoundOncePerFrame(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 ||
               (gOptionSelectMenu->mIndex != 2 && (u16) (gInputSlots[idx].mPressedBits & PAD_KEY_A) != 0)) {
        gOptionSelectMenu->mIndex++;
        if (gOptionSelectMenu->mIndex > 2) {
            gOptionSelectMenu->mIndex = 0;
        }
        StartSoundOncePerFrame(0);
    } else if (gOptionSelectMenu->mIndex != 2 && GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        if (gOptionSelectMenu->mIndex == 0) {
            StartSoundOncePerFrame(10);
        } else {
            StartSoundOncePerFrame(1);
        }
    } else if (gOptionSelectMenu->mIndex != 2 && GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
            gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        }
        if (gOptionSelectMenu->mIndex == 0) {
            StartSoundOncePerFrame(10);
        } else {
            StartSoundOncePerFrame(1);
        }
    } else if (r5 == 3) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        StartSoundOncePerFrame(10);
    } else if (r5 == 4) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        StartSoundOncePerFrame(10);
    } else if (r5 == 5) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        StartSoundOncePerFrame(1);
    } else if (r5 == 6) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        StartSoundOncePerFrame(1);
    }
end:
    if (gOptionSelectMenu->mRowValues[0] < 0) {
        gOptionSelectMenu->mRowValues[0] = 2;
    }
    if (gOptionSelectMenu->mRowValues[0] > 2) {
        gOptionSelectMenu->mRowValues[0] = 0;
    }
    if (gOptionSelectMenu->mRowValues[1] < 0) {
        gOptionSelectMenu->mRowValues[1] = 1;
    }
    if (gOptionSelectMenu->mRowValues[1] > 1) {
        gOptionSelectMenu->mRowValues[1] = 0;
    }
    if (gOptionSelectMenu->mIndex == 2 && sel != 2) {
        ResetPaletteBlendCycle();
    }
    ApplyOptionSelectMenuSound();
}

void AdvanceOptionSelectMenuState3(void) {
    gOptionSelectMenu->mStateFrames++;
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = 4;
        gOptionSelectMenu->mStateFrames = 0;
    } else if (gOptionSelectMenu->mStateFrames >= 5) {
        gOptionSelectMenu->mHighlightVisible = TRUE;
    }
}

void AdvanceOptionSelectMenuState4(void) {
    s32 i;
    s32 j;
    s16 t;
    void *a;
    void *b;

    gOptionSelectMenu->mBg0Bg1Offset = InterpolateS16(1, 0, -0x8c, gOptionSelectMenu->mStateFrames, 10);
    gOptionSelectMenu->mStateFrames++;
    t = InterpolateS16(1, 0, 250, gOptionSelectMenu->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gOptionSelectMenuGroupSTableCounts[i]; j++) {
            if (i == 1) {
                gOptionSelectMenu->mGroupOffsets[i].mOffsetX = -t;
            } else {
                gOptionSelectMenu->mGroupOffsets[i].mOffsetX = t;
            }
        }
    }
    gOptionSelectMenu->mGroupOffsets[2].mOffsetY = -LookupSelectReturnState4Bg2Offset(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= 10) {
        if (gOptionSelectMenu->mStateFrames >= 10 && IsSelectReturnState2NoState3Or4Request() != 0) {
            gOptionSelectMenu->mBg1Visible = FALSE;
            if (gOptionSelectMenu->mOkChosen != FALSE) {
                SetTxtSystemOpenSoundId(0x21);
                a = GetBmgEntry(gOptionSelectMenu->mOptionMessages, 0x10);
                b = GetBmgEntry(gOptionSelectMenu->mCommonMessages, 4);
                SetupTxtSystemSubTextButton(a, b);
                gOptionSelectMenu->mNextState = 5;
                gOptionSelectMenu->mStateFrames = 0;
                RequestSelectReturnState4();
            } else {
                RequestOptionState(gOptionSelectMenu->mNextOptionState);
            }
        }
    }
}

void AdvanceOptionSelectMenuState5(void) {
    s32 r;

    if (GetTxtSystemDone() != 0) {
        if (gBackupBuffers->mBusy == 0) {
            if (gBackupAccess->mBackupEnabled != 0) {
                r = gBackupAccess->mCommandRunning;
            } else {
                r = 0;
            }
        } else {
            r = 1;
        }
        if (r == 0) {
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
    s32 i;
    s32 j;
    u16 a;
    u16 b;

    a = gOptionSelectMenu->mOptionSelectMenuMBncl->mCount;
    b = gOptionSelectMenu->mOptionSelectMenuSBncl->mCount;
    for (i = 0; i < 1; i++) {
        gOptionSelectMenu->mOptionSelectMenuMTable[gOptionSelectMenuOffsetMIndices[i]].mOffsetY =
            gOptionSelectMenu->mBg0Bg1Offset;
    }
    for (i = 0; i < 2; i++) {
        (gOptionSelectMenu->mOptionSelectMenuMTable + a)[gOptionSelectMenuMLabelIndices[i]].mOffsetY =
            gOptionSelectMenu->mBg0Bg1Offset;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gOptionSelectMenuGroupSTableCounts[i]; j++) {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuGroupSTableIndices[i][j]].mOffsetX =
                gOptionSelectMenu->mGroupOffsets[i].mOffsetX;
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuGroupSTableIndices[i][j]].mOffsetY =
                gOptionSelectMenu->mGroupOffsets[i].mOffsetY;
        }
        (gOptionSelectMenu->mOptionSelectMenuSTable + b)[gOptionSelectMenuSLabelIndices[i]].mOffsetX =
            gOptionSelectMenu->mGroupOffsets[i].mOffsetX;
        (gOptionSelectMenu->mOptionSelectMenuSTable + b)[gOptionSelectMenuSLabelIndices[i]].mOffsetY =
            gOptionSelectMenu->mGroupOffsets[i].mOffsetY;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][j][0]].mOffsetX -=
                LookupFrameOffset(6 - gOptionSelectMenu->mOffsetTimers[i][0]);
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][j][1]].mOffsetX +=
                LookupFrameOffset(6 - gOptionSelectMenu->mOffsetTimers[i][1]);
        }
    }
}

void SetOptionSelectMenuValuesOnOff(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < gOptionSelectMenuValueCounts[i]; j++) {
            if (j == gOptionSelectMenu->mRowValues[i]) {
                gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuValueSTableIndices[i][j]].mVisible = 1;
            } else {
                gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuValueSTableIndices[i][j]].mVisible = 0;
            }
        }
    }
}

void SetOptionSelectMenuRowsOnOff(void) {
    s32 i;
    s32 k;

    for (i = 0; i < 3; i++) {
        if (i == gOptionSelectMenu->mIndex && gOptionSelectMenu->mHighlightVisible != FALSE) {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuRowSTableIndices[i]].mVisible = 1;
            SetLabelPaletteIndex(gOptionSelectMenuSLabelIndices[i], 14, gOptionSelectMenu->mOptionSelectMenuSBnll,
                                 gOptionSelectMenu->mOptionSelectMenuSTable, gOptionSelectMenu->mOptionSelectMenuSBncl);
            for (k = 0; k < gOptionSelectMenuValueCounts[i]; k++) {
                SetCellPaletteIndex(gOptionSelectMenuValueSTableIndices[i][k], 14,
                                    gOptionSelectMenu->mOptionSelectMenuSNcer,
                                    gOptionSelectMenu->mOptionSelectMenuSBncl);
            }
        } else {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuRowSTableIndices[i]].mVisible = 0;
            SetLabelPaletteIndex(gOptionSelectMenuSLabelIndices[i], 15, gOptionSelectMenu->mOptionSelectMenuSBnll,
                                 gOptionSelectMenu->mOptionSelectMenuSTable, gOptionSelectMenu->mOptionSelectMenuSBncl);
            for (k = 0; k < gOptionSelectMenuValueCounts[i]; k++) {
                SetCellPaletteIndex(gOptionSelectMenuValueSTableIndices[i][k], 15,
                                    gOptionSelectMenu->mOptionSelectMenuSNcer,
                                    gOptionSelectMenu->mOptionSelectMenuSBncl);
            }
        }
    }
}

void AdvanceOptionSelectMenuOffsetTimers(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (i == gOptionSelectMenu->mIndex) {
                if (gOptionSelectMenu->mOffsetTimers[i][j] > 0) {
                    gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][0][j]].mVisible =
                        1;
                    gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][1][j]].mVisible =
                        1;
                    gOptionSelectMenu->mOffsetTimers[i][j]--;
                } else {
                    gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][0][j]].mVisible =
                        0;
                    gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][1][j]].mVisible =
                        1;
                }
            } else {
                gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][0][j]].mVisible = 0;
                gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][1][j]].mVisible = 0;
            }
        }
    }
}

void AdvanceOptionSelectMenu(void) {
    OptionSelectMenu *p;

    gOptionSelectMenu->mState = gOptionSelectMenu->mNextState;
    switch (gOptionSelectMenu->mState) {
        case 0:
            AdvanceOptionSelectMenuState0();
            break;
        case 1:
            AdvanceOptionSelectMenuState1();
            break;
        case 2:
            AdvanceOptionSelectMenuState2();
            break;
        case 3:
            AdvanceOptionSelectMenuState3();
            break;
        case 4:
            AdvanceOptionSelectMenuState4();
            break;
        case 5:
            AdvanceOptionSelectMenuState5();
            break;
    }
    AdvancePaletteBlend();
    WriteOptionSelectMenuTableOffsets();
    SetOptionSelectMenuValuesOnOff();
    SetOptionSelectMenuRowsOnOff();
    AdvanceOptionSelectMenuOffsetTimers();
    p = gOptionSelectMenu;
    DrawLayoutTable(p->mOptionSelectMenuMBncl, p->mOptionSelectMenuMNcer, p->mOptionSelectMenuMBnll,
                    GetOptionFirstBuffer(), p->mOptionSelectMenuMTable);
    p = gOptionSelectMenu;
    DrawLayoutTable(p->mOptionSelectMenuSBncl, p->mOptionSelectMenuSNcer, p->mOptionSelectMenuSBnll,
                    GetOptionSecondBuffer(), p->mOptionSelectMenuSTable);
}

void WriteOptionSelectMenuRegisters(void) {
    u32 plane;

    if (gOptionSelectMenu->mBg1Visible != FALSE) {
        plane = (reg_GX_DISPCNT & 0x1f00) >> 8;
        plane |= 2;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (plane << 8);
    } else {
        plane = (reg_GX_DISPCNT & 0x1f00) >> 8;
        plane &= ~2;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (plane << 8);
    }
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG0OFS = (-gOptionSelectMenu->mBg0Bg1Offset << 16) & 0x1ff0000;
    reg_G2_BG1OFS = (-gOptionSelectMenu->mBg0Bg1Offset << 16) & 0x1ff0000;
}

void RegisterOptionSelectMenuCallbacks(void) {
    UnkFunc *table[4] = {InitOptionSelectMenu, ReleaseOptionSelectMenu, AdvanceOptionSelectMenu,
                         WriteOptionSelectMenuRegisters};

    SetOptionStateCallbacks((table));
}
