#include "01/OptionSelectMenu.h"
#include "01/code_02199964.h"
#include "01/code_0219853c.h"
#include "00/code_02181f98.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212b000.h"
#include "01/code_0219e824.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02126230.h"
#include "01/code_02192e78.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_02148950.h"
#include "code_0201ea58.h"
#include "code_0214a390.h"
#include "registers.h"

OptionSelectMenu *gOptionSelectMenu;

void InitOptionSelectMenuTexts(void) {
    s32 i;

    {
        s32 v0 = 0x8000;
        u8 a[2][2] = {{0xdc, 0x10}, {0xf0, 0x50}};
        s32 c[2] = {0xb, 0xc};

        for (i = 0; i < 2; i++) {
            v0 -= jn_ui_initLabel(gOptionSelectMenu->mHeap, data_ov001_021a6a24[i],
                                  gOptionSelectMenu->mOptionSelectMenuMBnll, a[i][0], a[i][1], i,
                                  gOptionSelectMenu->mOptionSelectMenuMNcer, gOptionSelectMenu->mOptionSelectMenuMBncl,
                                  gOptionSelectMenu->mOptionSelectMenuMTable, v0);
            jn_ui_212426C(0, data_ov001_021a6a24[i], gOptionSelectMenu->mOptionSelectMenuMBnll,
                          jn_msg_getMessage(gOptionSelectMenu->mOptionMessages, c[i]),
                          gOptionSelectMenu->mOptionSelectMenuMBncl, gOptionSelectMenu->mOptionSelectMenuMTable);
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
            v2 -= jn_ui_initLabel(gOptionSelectMenu->mHeap, data_ov001_021a6a34[i],
                                  gOptionSelectMenu->mOptionSelectMenuSBnll, b[i][0], b[i][1], data_ov001_021a6a30[i],
                                  gOptionSelectMenu->mOptionSelectMenuSNcer, gOptionSelectMenu->mOptionSelectMenuSBncl,
                                  gOptionSelectMenu->mOptionSelectMenuSTable, v2);
            jn_ui_212426C(1, data_ov001_021a6a34[i], gOptionSelectMenu->mOptionSelectMenuSBnll, jn_msg_getMessage(v1, d[i]),
                          gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSTable);
        }
    }
}

void InitOptionSelectMenu(void *a) {
    s32 i;

    gOptionSelectMenu = heap_alloc(a, 0x90);
    gOptionSelectMenu->mHeap = a;
    gOptionSelectMenu->mState = 0;
    gOptionSelectMenu->mNextState = 0;
    gOptionSelectMenu->mIndex = 0;
    gOptionSelectMenu->mStateFrames = 0;
    gOptionSelectMenu->mUnk_38 = TRUE;
    LocateAndQueueOptionSelectMenu();
    InitPaletteBlend(a, gOptionSelectMenu->mOptionSelectMenuSONclr, 3);
    for (i = 0; i < 2; i++) {
        jn_ui_setCellIsTranslucent(data_ov001_021a6a28[i], 1, gOptionSelectMenu->mOptionSelectMenuSNcer,
                      gOptionSelectMenu->mOptionSelectMenuSBncl);
    }
    oam_clearResetBuffers(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    jn_ui_initLayout(a, gOptionSelectMenu->mOptionSelectMenuMBncl, gOptionSelectMenu->mOptionSelectMenuMBnll,
                    &gOptionSelectMenu->mOptionSelectMenuMTable);
    jn_ui_initLayout(a, gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSBnll,
                    &gOptionSelectMenu->mOptionSelectMenuSTable);
    gOptionSelectMenu->mOptionMessages = arc_getSceneArcFile(aOptionBmg_0);
    gOptionSelectMenu->mCommonMessages = arc_get2dArcFile(aCommonBmg_0);
    InitOptionSelectMenuTexts();
    gOptionSelectMenu->mBg0Bg1Offset = -140;
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            gOptionSelectMenu->mUnk_26[i].mUnk_00 = 0;
            gOptionSelectMenu->mUnk_26[i].mUnk_02 = 0x28;
        } else if (i == 1) {
            gOptionSelectMenu->mUnk_26[i].mUnk_00 = 250;
            gOptionSelectMenu->mUnk_26[i].mUnk_02 = 0;
        } else {
            gOptionSelectMenu->mUnk_26[i].mUnk_00 = -250;
            gOptionSelectMenu->mUnk_26[i].mUnk_02 = 0;
        }
    }
    SetOptionSoundRowFromSave();
    if (gSaveData->mFirstBlock->mLocateFriendOff == 0) {
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
    gOptionSelectMenu->mUnk_1c = FALSE;
    gOptionSelectMenu->mUnk_3c = TRUE;
    gmenu_setSeqArcIndex(0xe);
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

    g2du_getCharacterDataBG(&a, arc_getSceneArcFile(aOptionSelectMe));
    g2du_getScreenData(&b, arc_getSceneArcFile(aOptionSelectMe_0));
    g2du_getPaletteData(&c, arc_getSceneArcFile(aOptionSelectMe_1));
    gOptionSelectMenu->mOptionSelectMenuMBncl = arc_getSceneArcFile(aOptionSelectMe_2);
    gOptionSelectMenu->mOptionSelectMenuSBncl = arc_getSceneArcFile(aOptionSelectMe_3);
    gOptionSelectMenu->mOptionSelectMenuSBnbl = arc_getSceneArcFile(aOptionSelectMe_4);
    gOptionSelectMenu->mOptionSelectMenuMBnll = arc_getSceneArcFile(aOptionSelectMe_5);
    gOptionSelectMenu->mOptionSelectMenuSBnll = arc_getSceneArcFile(aOptionSelectMe_6);
    g2du_getCharacterData(&gOptionSelectMenu->mOptionSelectMenuMNcgr, arc_getSceneArcFile(aOptionSelectMe_7));
    g2du_getCellBankData(&gOptionSelectMenu->mOptionSelectMenuMNcer, arc_getSceneArcFile(aOptionSelectMe_8));
    g2du_getPaletteData(&gOptionSelectMenu->mOptionSelectMenuMONclr, arc_getSceneArcFile(aOptionSelectMe_9));
    g2du_getCharacterData(&gOptionSelectMenu->mOptionSelectMenuSNcgr, arc_getSceneArcFile(aOptionSelectMe_10));
    g2du_getCellBankData(&gOptionSelectMenu->mOptionSelectMenuSNcer, arc_getSceneArcFile(aOptionSelectMe_11));
    g2du_getPaletteData(&gOptionSelectMenu->mOptionSelectMenuSONclr, arc_getSceneArcFile(aOptionSelectMe_12));
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
            sound_2108E94(0);
            break;
        case SOUND_MODE_SURROUND:
            sound_2108E94(1);
            break;
        case SOUND_MODE_HEADPHONES:
            sound_2108E94(2);
            break;
    }
}

void SetSoundModeFromOptionRow(void) {
    switch (gOptionSelectMenu->mRowValues[0]) {
        case SOUND_MODE_STEREO:
            gSaveData->mFirstBlock->mSoundMode = SOUND_MODE_STEREO;
            break;
        case SOUND_MODE_SURROUND:
            gSaveData->mFirstBlock->mSoundMode = SOUND_MODE_SURROUND;
            break;
        case SOUND_MODE_HEADPHONES:
            gSaveData->mFirstBlock->mSoundMode = SOUND_MODE_HEADPHONES;
            break;
    }
}

void SetOptionSoundRowFromSave(void) {
    switch (gSaveData->mFirstBlock->mSoundMode) {
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
    gOptionSelectMenu->mBg0Bg1Offset = mutil_interpolate(1, -140, 0, gOptionSelectMenu->mStateFrames, 10);
    v = mutil_interpolate(1, 250, 0, gOptionSelectMenu->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gOptionSelectMenuGroupSTableCounts[i]; j++) {
            if (i == 1) {
                gOptionSelectMenu->mUnk_26[i].mUnk_00 = -v;
            } else {
                gOptionSelectMenu->mUnk_26[i].mUnk_00 = v;
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
    gOptionSelectMenu->mUnk_26[2].mUnk_02 = -LookupSelectReturnState1Bg2Offset(gOptionSelectMenu->mStateFrames);
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
    v = gInputUnits[idx].mHasPair;
    if (v == 0 && gInputUnits[idx].mNoPairCount < 5) {
        hasA = TRUE;
    }
    if (hasA == FALSE && gInputUnits[idx].mPrevHasPair == 0 && v != 0) {
        hasB = TRUE;
    }
    if (hasB != FALSE) {
        r5 = jn_ui_checkTouch(p->mOptionSelectMenuSBnbl, gInputUnits[idx].mPairX, gInputUnits[idx].mPairY);
    }
    if ((u16) (gInputUnits[idx].mPressedBits & PAD_KEY_B) != 0) {
        goto L1;
    } else {
        BOOL c = FALSE;
        BOOL d = FALSE;
        v = gInputUnits[idx].mHasPair;
        if (v == 0 && gInputUnits[idx].mNoPairCount < 5) {
            d = TRUE;
        }
        if (d == FALSE && gInputUnits[idx].mPrevHasPair == 0 && v != 0) {
            c = TRUE;
        }
        if (c != FALSE && gmenu_checkSelectReturnTouch(gInputUnits[idx].mPairX,
                                                                          gInputUnits[idx].mPairY) != FALSE) {
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
    if (((u16) (gInputUnits[idx].mPressedBits & PAD_KEY_A) != 0 && gOptionSelectMenu->mIndex == 2) || r5 == 2) {
        SetSoundModeFromOptionRow();
        if (gOptionSelectMenu->mRowValues[1] == 0) {
            gSaveData->mFirstBlock->mUnk_31 &= ~0x10;
        } else {
            gSaveData->mFirstBlock->mUnk_31 |= 0x10;
        }
        savd_flushNksy();
        if (gOptionSelectMenu->mIndex == 2) {
            gOptionSelectMenu->mUnk_38 = FALSE;
        }
        gOptionSelectMenu->mNextState = 3;
        gOptionSelectMenu->mNextOptionState = 0;
        gOptionSelectMenu->mIndex = 2;
        gOptionSelectMenu->mUnk_1c = TRUE;
        StopPaletteBlend();
        sfx_2105AC0(5);
    } else if (r5 == 0) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        sfx_2105AC0(10);
    } else if (r5 == 1) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        sfx_2105AC0(1);
    } else if (mutil_checkKeys(8, PAD_KEY_UP) != 0) {
        gOptionSelectMenu->mIndex--;
        if (gOptionSelectMenu->mIndex < 0) {
            gOptionSelectMenu->mIndex = 2;
        }
        sfx_2105AC0(0);
    } else if (mutil_checkKeys(8, PAD_KEY_DOWN) != 0 ||
               (gOptionSelectMenu->mIndex != 2 && (u16) (gInputUnits[idx].mPressedBits & PAD_KEY_A) != 0)) {
        gOptionSelectMenu->mIndex++;
        if (gOptionSelectMenu->mIndex > 2) {
            gOptionSelectMenu->mIndex = 0;
        }
        sfx_2105AC0(0);
    } else if (gOptionSelectMenu->mIndex != 2 && mutil_checkKeys(8, PAD_KEY_LEFT) != 0) {
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        if (gOptionSelectMenu->mIndex == 0) {
            sfx_2105AC0(10);
        } else {
            sfx_2105AC0(1);
        }
    } else if (gOptionSelectMenu->mIndex != 2 && mutil_checkKeys(8, PAD_KEY_RIGHT) != 0) {
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        if (mutil_checkKeys(8, PAD_KEY_RIGHT) != 0) {
            gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        }
        if (gOptionSelectMenu->mIndex == 0) {
            sfx_2105AC0(10);
        } else {
            sfx_2105AC0(1);
        }
    } else if (r5 == 3) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        sfx_2105AC0(10);
    } else if (r5 == 4) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        sfx_2105AC0(10);
    } else if (r5 == 5) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][0] = 6;
        sfx_2105AC0(1);
    } else if (r5 == 6) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mRowValues[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mOffsetTimers[gOptionSelectMenu->mIndex][1] = 6;
        sfx_2105AC0(1);
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
        gOptionSelectMenu->mUnk_38 = TRUE;
    }
}

void AdvanceOptionSelectMenuState4(void) {
    s32 i;
    s32 j;
    s16 t;
    void *a;
    void *b;

    gOptionSelectMenu->mBg0Bg1Offset = mutil_interpolate(1, 0, -0x8c, gOptionSelectMenu->mStateFrames, 10);
    gOptionSelectMenu->mStateFrames++;
    t = mutil_interpolate(1, 0, 250, gOptionSelectMenu->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gOptionSelectMenuGroupSTableCounts[i]; j++) {
            if (i == 1) {
                gOptionSelectMenu->mUnk_26[i].mUnk_00 = -t;
            } else {
                gOptionSelectMenu->mUnk_26[i].mUnk_00 = t;
            }
        }
    }
    gOptionSelectMenu->mUnk_26[2].mUnk_02 = -LookupSelectReturnState4Bg2Offset(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= 10) {
        if (gOptionSelectMenu->mStateFrames >= 10 && IsSelectReturnState2NoState3Or4Request() != 0) {
            gOptionSelectMenu->mUnk_3c = FALSE;
            if (gOptionSelectMenu->mUnk_1c != FALSE) {
                SetTxtSystemOpenSoundId(0x21);
                a = jn_msg_getMessage(gOptionSelectMenu->mOptionMessages, 0x10);
                b = jn_msg_getMessage(gOptionSelectMenu->mCommonMessages, 4);
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
        if (gSaveData->mBusy == 0) {
            if (gSaveCore->mBackupEnabled != 0) {
                r = gSaveCore->mCommandRunning;
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

    a = gOptionSelectMenu->mOptionSelectMenuMBncl->mUnk_06;
    b = gOptionSelectMenu->mOptionSelectMenuSBncl->mUnk_06;
    for (i = 0; i < 1; i++) {
        gOptionSelectMenu->mOptionSelectMenuMTable[data_ov001_021a6a20[i]].mOffsetY = gOptionSelectMenu->mBg0Bg1Offset;
    }
    for (i = 0; i < 2; i++) {
        (gOptionSelectMenu->mOptionSelectMenuMTable + a)[data_ov001_021a6a24[i]].mOffsetY =
            gOptionSelectMenu->mBg0Bg1Offset;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gOptionSelectMenuGroupSTableCounts[i]; j++) {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuGroupSTableIndices[i][j]].mOffsetX =
                gOptionSelectMenu->mUnk_26[i].mUnk_00;
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuGroupSTableIndices[i][j]].mOffsetY =
                gOptionSelectMenu->mUnk_26[i].mUnk_02;
        }
        (gOptionSelectMenu->mOptionSelectMenuSTable + b)[data_ov001_021a6a34[i]].mOffsetX =
            gOptionSelectMenu->mUnk_26[i].mUnk_00;
        (gOptionSelectMenu->mOptionSelectMenuSTable + b)[data_ov001_021a6a34[i]].mOffsetY =
            gOptionSelectMenu->mUnk_26[i].mUnk_02;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][j][0]].mOffsetX -=
                func_020adc64(6 - gOptionSelectMenu->mOffsetTimers[i][0]);
            gOptionSelectMenu->mOptionSelectMenuSTable[gOptionSelectMenuTimerSTableIndices[i][j][1]].mOffsetX +=
                func_020adc64(6 - gOptionSelectMenu->mOffsetTimers[i][1]);
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
        if (i == gOptionSelectMenu->mIndex && gOptionSelectMenu->mUnk_38 != FALSE) {
            gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a30[i]].mVisible = 1;
            jn_ui_setLabelColorParam(data_ov001_021a6a34[i], 14, gOptionSelectMenu->mOptionSelectMenuSBnll,
                                 gOptionSelectMenu->mOptionSelectMenuSTable, gOptionSelectMenu->mOptionSelectMenuSBncl);
            for (k = 0; k < gOptionSelectMenuValueCounts[i]; k++) {
                jn_ui_setCellCparam(gOptionSelectMenuValueSTableIndices[i][k], 14,
                                    gOptionSelectMenu->mOptionSelectMenuSNcer,
                                    gOptionSelectMenu->mOptionSelectMenuSBncl);
            }
        } else {
            gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a30[i]].mVisible = 0;
            jn_ui_setLabelColorParam(data_ov001_021a6a34[i], 15, gOptionSelectMenu->mOptionSelectMenuSBnll,
                                 gOptionSelectMenu->mOptionSelectMenuSTable, gOptionSelectMenu->mOptionSelectMenuSBncl);
            for (k = 0; k < gOptionSelectMenuValueCounts[i]; k++) {
                jn_ui_setCellCparam(gOptionSelectMenuValueSTableIndices[i][k], 15,
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
    jn_ui_renderElements(p->mOptionSelectMenuMBncl, p->mOptionSelectMenuMNcer, p->mOptionSelectMenuMBnll,
                    GetOptionFirstBuffer(), p->mOptionSelectMenuMTable);
    p = gOptionSelectMenu;
    jn_ui_renderElements(p->mOptionSelectMenuSBncl, p->mOptionSelectMenuSNcer, p->mOptionSelectMenuSBnll,
                    GetOptionSecondBuffer(), p->mOptionSelectMenuSTable);
}

void WriteOptionSelectMenuRegisters(void) {
    u32 plane;

    if (gOptionSelectMenu->mUnk_3c != FALSE) {
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
