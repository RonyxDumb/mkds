#include "Main/Menu/txt_system.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/text_draw.h"

#include "Main/Menu/data_0215d000.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Menu/data_02180728.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "code_0200eddc.h"
#include "gfd_VramTransferManager.h"
#include "g2d_CharCanvas.h"
#include "g2.h"
#include "code_0212df7c.h"
#include "Main/Menu/data_0216e000.h"
#include "code_02134398.h"
#include "output_effect.h"
#include "Main/Graphics/font_and_player_character.h"
#include "os_thread.h"
#include "gx_bgcnt.h"
#include "gx_load2d.h"
#include "code_0214cfe4.h"
#include "Main/System/result_archive_path.h"
#include "code_0214d018.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u8 gTxtSystemCanvasSizes[8][2] = {{0x16, 0xb}, {0x16, 7}, {0x16, 0xb}, {0x16, 7}, {0x16, 2}, {9, 2}, {9, 2}, {0, 0}};
const s16 gTxtSystemBgOffsets[2] = {0xa0, -176};
const u16 gTxtSystemCanvasCharOffsets[8] = {4, 4, 4, 4, 9, 9, 0x1b, 0};
const ByteRect gTxtSystemNscrRects[7] = {{3, 0x1c, 2, 0xe}, {3, 0x1c, 4, 0xc}, {4, 0x1b, 0x10, 0x13}, {3, 0x1c, 0x10, 0x13}, {0x17, 0x1b, 0x10, 0x13}, {0x17, 0x1b, 0x10, 0x13}, {0x17, 0x1b, 0x10, 0x13}};
const ByteRect gTxtSystemHitRects[7] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0x20, 0xe0, 0x80, 0xa0}, {0x18, 0x70, 0x80, 0xa0}, {0x90, 0xe8, 0x80, 0xa0}};
TxtSystem *gTxtSystem;

#pragma thumb on

void ClearTxtSystemCanvasInUse(void) {
    s32 canvasIndex;

    for (canvasIndex = 0; canvasIndex < 7; canvasIndex++) {
        gTxtSystem->mCanvasInUse[canvasIndex] = 0;
    }
}

static inline void InitTxtSystemTextCanvas(TextCanvas *textCanvas, NNSG2dCharCanvas *charCanvas, void *font) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = 1;
    textCanvas->mLineSpacing = 1;
}

s32 InitTxtSystem(void *heap, TxtSystemArgs *args) {
    s32 subCharOffset;
    s32 index;
    NNSG2dCharCanvas *charCanvas;

    subCharOffset = args->mSubCharOffset;
    gTxtSystem = HeapAlloc(heap, 0x2278);
    if (args->mUseCanvas1 != 0) {
        gTxtSystem->mUseCanvas1 = 1;
    }
    if (args->mUseCanvas2 != 0) {
        gTxtSystem->mUseCanvas2 = 1;
    }
    if (args->mUseCanvas3 != 0) {
        gTxtSystem->mUseCanvas3 = 1;
    }
    gTxtSystem->mEnabled = 1;
    InitTxtSystemDisplay();
    subCharOffset = LoadTxtSystem(subCharOffset);
    for (index = 0; index < 7; index++) {
        if (!((index == 1 && gTxtSystem->mUseCanvas1 == 0) || (index == 2 && gTxtSystem->mUseCanvas2 == 0) ||
              (index == 3 && gTxtSystem->mUseCanvas3 == 0))) {
            gTxtSystem->mCharBuffers[index] =
                HeapAlloc(heap, (gTxtSystemCanvasSizes[index][0] * gTxtSystemCanvasSizes[index][1]) << 5);
            NNS_G2dCharCanvasInitForBG(&gTxtSystem->mCharCanvases[index], gTxtSystem->mCharBuffers[index],
                                       gTxtSystemCanvasSizes[index][0], gTxtSystemCanvasSizes[index][1], 4);
            charCanvas = &gTxtSystem->mCharCanvases[index];
            charCanvas->mPClear(charCanvas, 0);
            InitTxtSystemTextCanvas(&gTxtSystem->mTextCanvases[index], &gTxtSystem->mCharCanvases[index], args->mFont);
        }
    }
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mState = 0;
    gTxtSystem->mNextState = 0;
    gTxtSystem->mPrevState = 0;
    gTxtSystem->mStateFrames = 0;
    gTxtSystem->mAnimFrameIndexFrames = 0;
    gTxtSystem->mAnimFrameIndex = 0;
    gTxtSystem->mAnimVisible[0] = 0;
    gTxtSystem->mAnimVisible[1] = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesEnabled[0] = 0;
    gTxtSystem->mBlendPlanesEnabled[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = 0;
    gTxtSystem->mBlendPlanesRequested[1] = 0;
    gTxtSystem->mOpenRequested = 0;
    gTxtSystem->mCloseRequested = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mInputAccepted = 0;
    gTxtSystem->mInputSoundId = 5;
    gTxtSystem->mSecondInputSoundId = 0x10;
    gTxtSystem->mOpenSoundId = 0x23;
    for (index = 0; index < 2; index++) {
        gTxtSystem->mBgOffset[index] = -192;
        gTxtSystem->mBgOffsetAtOpen[index] = 0;
        gTxtSystem->mBgOffsetRequested[index] = 0;
    }
    gTxtSystem->mBlendPlanes[0] = 0x19;
    gTxtSystem->mBlendPlanes[1] = 0x1a;
    gTxtSystem->mBrightness = 0;
    for (index = 0; index < 2; index++) {
        gTxtSystem->mBlendEv1[index] = 6;
        gTxtSystem->mBlendEv2[index] = 10;
    }
    gTxtSystem->mMode = 0;
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void ClearTxtSystemPointer(void) {
    gTxtSystem = NULL;
}
#pragma thumb off

#pragma thumb on

void InitTxtSystemDisplay(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    mainDisplayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((mainDisplayBits | 4) << 8);
    reg_G2_BG2CNT &= ~3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x9e10;
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits | 1) << 8);
    reg_G2S_DB_BG0CNT &= ~3;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x8b00;
}

static inline void FillScreenBuffer(void *dst, u16 value) {
    vu16 fillValue = value;

    MIi_CpuClear16(fillValue, dst, 0x1000);
}

s32 LoadTxtSystem(s32 subCharOffset) {
    Ncgr *firstChars;
    Ncgr *secondChars;
    Nclr *palette;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        LocateNcgr(&firstChars, FindSceneFile("txt_system_b_00.ncgr"));
        LocateNscr(&gTxtSystem->mBgNscrs[0], FindSceneFile("txt_system_bg_00.nscr"));
        LocateNclr(&palette, FindSceneFile("txt_system_b_00.nclr"));
    } else {
        LocateNcgr(&firstChars, FindFileInLoadedArchives("txt_system_b_00.ncgr"));
        LocateNcgr(&secondChars, FindFileInLoadedArchives("txt_system_b_01.ncgr"));
        LocateNscr(&gTxtSystem->mBgNscrs[0], FindFileInLoadedArchives("txt_system_bg_00.nscr"));
        LocateNscr(&gTxtSystem->mBgNscrs[1], FindFileInLoadedArchives("txt_system_bg_00_2.nscr"));
        LocateNscr(&gTxtSystem->mBgNscrs[2], FindFileInLoadedArchives("txt_system_bg_01_2.nscr"));
        LocateNscr(&gTxtSystem->mBgNscrs[3], FindFileInLoadedArchives("txt_system_bg_01.nscr"));
        LocateNscr(&gTxtSystem->mBgNscrs[4], FindFileInLoadedArchives("txt_system_bg_02.nscr"));
        LocateNscr(&gTxtSystem->mBgNscrs[5], FindFileInLoadedArchives("txt_system_bg_02_2.nscr"));
        LocateNscr(&gTxtSystem->mBgNscrs[6], FindFileInLoadedArchives("txt_system_bg_02_3.nscr"));
        LocateNclr(&palette, FindFileInLoadedArchives("txt_system_b_00.nclr"));
    }
    gTxtSystem->mCanvasFileCharIndex[0] = 0;
    DC_FlushRange(firstChars->mData, firstChars->mDataSize);
    GX_LoadBG2Char(firstChars->mData, 0, firstChars->mDataSize);
    if (gTxtSystem->mUseCanvas2 != 0) {
        subCharOffset = subCharOffset - firstChars->mDataSize;
        gTxtSystem->mCanvasFileCharIndex[2] = subCharOffset >> 5;
        DC_FlushRange(firstChars->mData, firstChars->mDataSize);
        GXS_LoadBG0Char(firstChars->mData, subCharOffset, firstChars->mDataSize);
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        if (gTxtSystem->mUseCanvas1 != 0) {
            gTxtSystem->mCanvasFileCharIndex[1] = 0;
        }
        gTxtSystem->mB01CharIndex[0] = firstChars->mDataSize >> 5;
        DC_FlushRange(secondChars->mData, secondChars->mDataSize);
        GX_LoadBG2Char(secondChars->mData, gTxtSystem->mB01CharIndex[0] << 5, secondChars->mDataSize);
        if (gTxtSystem->mUseCanvas3 != 0) {
            gTxtSystem->mCanvasFileCharIndex[3] = gTxtSystem->mCanvasFileCharIndex[2];
        }
        subCharOffset = subCharOffset - secondChars->mDataSize;
        gTxtSystem->mCanvasFileCharIndex[4] = subCharOffset >> 5;
        gTxtSystem->mCanvasFileCharIndex[5] = subCharOffset >> 5;
        gTxtSystem->mCanvasFileCharIndex[6] = subCharOffset >> 5;
        gTxtSystem->mB01CharIndex[1] = subCharOffset >> 5;
        DC_FlushRange(secondChars->mData, secondChars->mDataSize);
        GXS_LoadBG0Char(secondChars->mData, subCharOffset, secondChars->mDataSize);
    }
    DC_FlushRange(palette->mData, 0x1c0);
    GX_LoadBGPltt(palette->mData + 0xe0, 0x1c0, 0x40);
    GXS_LoadBGPltt(palette->mData + 0xe0, 0x1c0, 0x40);
    gTxtSystem->mUnselectedButtonColor = palette->mData[0xee];
    gTxtSystem->mSelectedButtonColor = palette->mData[0xdf];
    MemFillWordsByBlock_inline((void *) G2_GetBG2ScrPtr(), 0x1000);
    FillScreenBuffer((void *) G2S_GetBG0ScrPtr(), gTxtSystem->mCanvasFileCharIndex[4]);
    return subCharOffset;
}

void RefreshTxtSystemAnim(void) {
    s32 row;
    s32 screenIndex;
    s32 column;
    s32 rectIndex;
    u16 *screenBuffer;

    rectIndex = gTxtSystem->mAnimFrameIndex + 4;
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        if (gTxtSystem->mAnimVisible[screenIndex] != 0) {
            screenBuffer = gTxtSystem->mMainScreenBuffer;
            if (screenIndex == 1) {
                screenBuffer = gTxtSystem->mSubScreenBuffer;
            }
            for (row = gTxtSystemNscrRects[rectIndex].mMinY; row <= gTxtSystemNscrRects[rectIndex].mMaxY; row++) {
                for (column = gTxtSystemNscrRects[rectIndex].mMinX; column <= gTxtSystemNscrRects[rectIndex].mMaxX;
                     column++) {
                    *(screenBuffer + row * 32 + column) =
                        gTxtSystem->mB01CharIndex[screenIndex] +
                        *((u16 *) gTxtSystem->mBgNscrs[rectIndex]->mData + row * 32 + column);
                }
            }
        }
    }
}

void RefreshTxtSystemScreenBuffers(u32 *drawFlags) {
    u8 rectIndices[9] = {0, 1, 0, 1, 2, 3, 0, 0, 0};
    s32 index;
    s32 row;
    s32 column;
    s32 rectIndex;
    u16 *screenBuffer;

    MemFillWordsByBlock_inline(gTxtSystem->mMainScreenBuffer, 0x1000);
    FillScreenBuffer(&gTxtSystem->mSubScreenBuffer, gTxtSystem->mCanvasFileCharIndex[4]);
    for (index = 0; index < 9; index++) {
        if (*drawFlags != 0) {
            if ((u32) (index - 7) <= 1) {
                RefreshTxtSystemAnim();
            } else if (index != 6) {
                rectIndex = rectIndices[index];
                screenBuffer = gTxtSystem->mSubScreenBuffer;
                if ((u32) index <= 1) {
                    screenBuffer = gTxtSystem->mMainScreenBuffer;
                }
                for (row = gTxtSystemNscrRects[rectIndex].mMinY; row <= gTxtSystemNscrRects[rectIndex].mMaxY; row++) {
                    for (column = gTxtSystemNscrRects[rectIndex].mMinX; column <= gTxtSystemNscrRects[rectIndex].mMaxX;
                         column++) {
                        *(screenBuffer + row * 32 + column) =
                            gTxtSystem->mCanvasFileCharIndex[index] +
                            *((u16 *) gTxtSystem->mBgNscrs[rectIndex]->mData + row * 32 + column);
                    }
                }
            }
        }
        drawFlags++;
    }
}
#pragma thumb off

#pragma thumb on

void QueueTxtSystemButtonColors(void) {
    TxtSystem *txtSystem;
    txtSystem = gTxtSystem;
    if (0 < txtSystem->mExtraCanvasCount) {
        NNS_GfdRegisterNewVramTransferTask(0x1f, ((0xee - txtSystem->mSelectedIndex) * 2),
                                           &txtSystem->mSelectedButtonColor, 2);
        NNS_GfdRegisterNewVramTransferTask(0x1f, (0xfe - gTxtSystem->mSelectedIndex) * 2,
                                           &gTxtSystem->mSelectedButtonColor, 2);
        txtSystem = gTxtSystem;
        if (txtSystem->mExtraCanvasCount == 2) {
            NNS_GfdRegisterNewVramTransferTask(0x1f, ((txtSystem->mSelectedIndex + 0xed) * 2),
                                               &txtSystem->mUnselectedButtonColor, 2);
            NNS_GfdRegisterNewVramTransferTask(0x1f, (gTxtSystem->mSelectedIndex + 0xfd) * 2,
                                               &gTxtSystem->mUnselectedButtonColor, 2);
        }
    }
}

void ResetTxtSystemButtonColors(void) {
    int buttonEntryIndex;
    if (0 < gTxtSystem->mExtraCanvasCount) {
        buttonEntryIndex = 0;
        do {
            NNS_GfdRegisterNewVramTransferTask(0x1f, ((buttonEntryIndex + 0xed) * 2),
                                               &gTxtSystem->mUnselectedButtonColor, 2);
            NNS_GfdRegisterNewVramTransferTask(0x1f, ((buttonEntryIndex + 0xfd) * 2),
                                               &gTxtSystem->mUnselectedButtonColor, 2);
            buttonEntryIndex = buttonEntryIndex + 1;
        } while (buttonEntryIndex < 2);
    }
}

#pragma thumb off

#pragma thumb on

// State 0: serves an open request by building the screens and queueing them.
void AdvanceTxtSystemState0(void) {
    u32 drawFlags[9];
    s32 index;
    s32 bufferSize;
    s32 queueCommand;

    if (gTxtSystem->mOpenRequested != 0) {
        for (index = 0; index < 9; index++) {
            if (index <= 6) {
                if (gTxtSystem->mCanvasInUse[index] != 0) {
                    drawFlags[index] = 1;
                } else {
                    drawFlags[index] = 0;
                }
            } else {
                if ((&gTxtSystem->mNextState)[index] != 0) {
                    (&gTxtSystem->mNextState)[index] = 0;
                    *(&gTxtSystem->mState + index - 1) = 1;
                    drawFlags[index] = 1;
                } else {
                    drawFlags[index] = 0;
                }
            }
        }
        RefreshTxtSystemScreenBuffers(drawFlags);
        NNS_GfdRegisterNewVramTransferTask(10, 0, gTxtSystem->mMainScreenBuffer, 0x1000);
        NNS_GfdRegisterNewVramTransferTask(0x18, 0, &gTxtSystem->mSubScreenBuffer, 0x1000);
        gTxtSystem->mNextState = 1;
        gTxtSystem->mStateFrames = 0;
        for (index = 0; index < 2; index++) {
            gTxtSystem->mBgOffsetAtOpen[index] = gTxtSystem->mBgOffsetRequested[index];
        }
        for (index = 0; index < 2; index++) {
            gTxtSystem->mBlendPlanesEnabled[index] = gTxtSystem->mBlendPlanesRequested[index];
        }
        for (index = 0; index < 7; index++) {
            if (gTxtSystem->mCanvasInUse[index] != 0) {
                bufferSize = (gTxtSystemCanvasSizes[index][0] * gTxtSystemCanvasSizes[index][1]) << 5;
                queueCommand = 0x14;
                if ((u32) index <= 1) {
                    queueCommand = 6;
                }
                NNS_GfdRegisterNewVramTransferTask(
                    queueCommand, (gTxtSystem->mCanvasFileCharIndex[index] + gTxtSystemCanvasCharOffsets[index]) << 5,
                    gTxtSystem->mCharBuffers[index], bufferSize);
            }
        }
        if (gTxtSystem->mExtraCanvasCount > 0) {
            QueueTxtSystemButtonColors();
        }
        if (gTxtSystem->mAnimVisible[0] == 0 && gTxtSystem->mAnimVisible[1] == 0) {
            if (gTxtSystem->mOpenSoundId != -1) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, (u16) gTxtSystem->mOpenSoundId);
            }
        }
    }
}

// State 1: slides the box in over 15 steps.
void AdvanceTxtSystemState1(void) {
    TxtSystem *txtSystem;
    s32 screenIndex;

    gTxtSystem->mStateFrames++;
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        gTxtSystem->mBgOffset[screenIndex] =
            InterpolateS16(1, gTxtSystemBgOffsets[gTxtSystem->mOpenFromIndex],
                           -gTxtSystem->mBgOffsetAtOpen[screenIndex], gTxtSystem->mStateFrames, 0xf);
    }
    txtSystem = gTxtSystem;
    txtSystem->mBrightness = (txtSystem->mStateFrames * -10) / 15;
    if (gTxtSystem->mStateFrames >= 15) {
        if (gTxtSystem->mCloseRequested == 0) {
            gTxtSystem->mOpenRequested = 0;
        }
        gTxtSystem->mNextState = 2;
        gTxtSystem->mStateFrames = 0;
    }
}

static inline BOOL IsPointInByteRect(u16 pointX, u16 pointY, u8 minX, u8 maxX, u8 minY, u8 maxY) {
    if (pointX >= minX && pointX <= maxX && pointY >= minY && pointY <= maxY) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 TxtSystemIsPairNewUnlessLost(u32 inputSlotIndex) {
    BOOL result = FALSE;
    BOOL recentlyLost = FALSE;

    if (gInputSlots[inputSlotIndex].mPair.mHasPair == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[inputSlotIndex].mPair.mHasPair != 0) {
        result = TRUE;
    }
    return result;
}

// State 2: open; answers a close request, or a touch or key press when the box has buttons.
void AdvanceTxtSystemState2(void) {
    s32 buttonCount;
    s32 offsetTouchY;
    u16 clampedTouchY;
    s32 hit;
    u16 touchX;
    TxtSystem *txtSystem;
    u32 inputSlotIndex;
    u16 keys;

    switch (gTxtSystem->mMode) {
        case 0:
            inputSlotIndex = 8;
            break;
        case 1:
            inputSlotIndex = GetPadInputSlot();
            break;
    }
    touchX = gInputSlots[inputSlotIndex].mPair.mPairX;
    txtSystem = gTxtSystem;
    offsetTouchY = txtSystem->mBgOffset[1] + gInputSlots[inputSlotIndex].mPair.mPairY;
    if (offsetTouchY < 0) {
        offsetTouchY = 0xff;
    }
    if (offsetTouchY > 0xff) {
        offsetTouchY = 0xff;
    }
    clampedTouchY = offsetTouchY;
    if (txtSystem->mCloseRequested != 0) {
        txtSystem->mNextState = 4;
        return;
    }
    buttonCount = txtSystem->mExtraCanvasCount;
    if (buttonCount <= 0) {
        return;
    }
    hit = -1;
    if (buttonCount == 2) {
        if (TxtSystemIsPairNewUnlessLost(inputSlotIndex) != 0) {
            if (IsPointInByteRect(touchX, clampedTouchY, gTxtSystemHitRects[5].mMinX, gTxtSystemHitRects[5].mMaxX,
                                  gTxtSystemHitRects[5].mMinY, gTxtSystemHitRects[5].mMaxY) != FALSE) {
                hit = 0;
            }
            if (IsPointInByteRect(touchX, clampedTouchY, gTxtSystemHitRects[6].mMinX, gTxtSystemHitRects[6].mMaxX,
                                  gTxtSystemHitRects[6].mMinY, gTxtSystemHitRects[6].mMaxY) != FALSE) {
                hit = 1;
            }
        }
    }
    keys = gInputSlots[inputSlotIndex].mPressedBits;
    if ((u16) (keys & PAD_KEY_A) == 0) {
        if (TxtSystemIsPairNewUnlessLost(inputSlotIndex) == 0 || buttonCount != 1 ||
            IsPointInByteRect(touchX, clampedTouchY, gTxtSystemHitRects[4].mMinX, gTxtSystemHitRects[4].mMaxX,
                              gTxtSystemHitRects[4].mMinY, gTxtSystemHitRects[4].mMaxY) == FALSE) {
            if (hit == -1) {
                goto L;
            }
        }
    }
    if (buttonCount == 1) {
        ResetTxtSystemButtonColors();
    } else {
        if (hit == -1 || txtSystem->mSelectedIndex == hit) {
            ResetTxtSystemButtonColors();
        } else {
            txtSystem->mSelectedIndex = hit;
            QueueTxtSystemButtonColors();
        }
    }
    gTxtSystem->mNextState = 3;
    if (gTxtSystem->mExtraCanvasCount == 2 && gTxtSystem->mSelectedIndex == 1) {
        if (gTxtSystem->mSecondInputSoundId != -1) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, (u16) gTxtSystem->mSecondInputSoundId);
        }
    } else {
        if (gTxtSystem->mInputSoundId != -1) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, (u16) gTxtSystem->mInputSoundId);
        }
    }
    gTxtSystem->mInputAccepted = 1;
    return;
L:
    if (buttonCount == 2) {
        if ((u16) (keys & PAD_KEY_LEFT) != 0 && txtSystem->mSelectedIndex == 1) {
            txtSystem->mSelectedIndex = 0;
            QueueTxtSystemButtonColors();
            StartSoundOncePerFrame(0);
            return;
        }
        if ((u16) (keys & 0x10) != 0 && txtSystem->mSelectedIndex == 0) {
            txtSystem->mSelectedIndex = 1;
            QueueTxtSystemButtonColors();
            StartSoundOncePerFrame(0);
        }
    }
}

// State 3: ten steps after an accepted input, then sets mDone.
void AdvanceTxtSystemState3(void) {
    gTxtSystem->mStateFrames++;
    gTxtSystem->mInputAccepted = 0;
    if (gTxtSystem->mStateFrames >= 10) {
        gTxtSystem->mDone = 1;
        gTxtSystem->mNextState = 2;
        gTxtSystem->mStateFrames = 0;
    } else if (gTxtSystem->mStateFrames >= 5) {
        QueueTxtSystemButtonColors();
    }
}

// State 4: slides the box out over 15 steps.
void AdvanceTxtSystemState4(void) {
    TxtSystem *txtSystem;
    s32 screenIndex;

    gTxtSystem->mStateFrames++;
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        gTxtSystem->mBgOffset[screenIndex] =
            InterpolateS16(1, -gTxtSystem->mBgOffsetAtOpen[screenIndex], gTxtSystemBgOffsets[gTxtSystem->mCloseToIndex],
                           gTxtSystem->mStateFrames, 0xf);
    }
    txtSystem = gTxtSystem;
    txtSystem->mBrightness = -10 - (txtSystem->mStateFrames * -10) / 15;
    if (gTxtSystem->mStateFrames >= 15) {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            gTxtSystem->mBgOffset[screenIndex] = -192;
        }
        gTxtSystem->mNextState = 0;
        ResetTxtSystemButtonColors();
        gTxtSystem->mStateFrames = 0;
        gTxtSystem->mCloseRequested = 0;
        gTxtSystem->mDone = 0;
        gTxtSystem->mAnimVisible[0] = 0;
        gTxtSystem->mAnimVisible[1] = 0;
    }
}

void AdvanceTxtSystem(void) {
    if (gTxtSystem->mEnabled != 0) {
        gTxtSystem->mPrevState = gTxtSystem->mState;
        gTxtSystem->mState = gTxtSystem->mNextState;
        switch (gTxtSystem->mState) {
            case 0:
                AdvanceTxtSystemState0();
                break;
            case 1:
                AdvanceTxtSystemState1();
                break;
            case 2:
                AdvanceTxtSystemState2();
                break;
            case 3:
                AdvanceTxtSystemState3();
                break;
            case 4:
                AdvanceTxtSystemState4();
                break;
        }
        if (gTxtSystem->mAnimVisible[0] != 0 || gTxtSystem->mAnimVisible[1] != 0) {
            gTxtSystem->mAnimFrameIndexFrames++;
            if (gTxtSystem->mAnimFrameIndexFrames >= 4) {
                gTxtSystem->mAnimFrameIndexFrames = 0;
                gTxtSystem->mAnimFrameIndex++;
                if (gTxtSystem->mAnimFrameIndex >= 3) {
                    gTxtSystem->mAnimFrameIndex = 0;
                }
                RefreshTxtSystemAnim();
                NNS_GfdRegisterNewVramTransferTask(10, 0, gTxtSystem->mMainScreenBuffer, 0x1000);
                NNS_GfdRegisterNewVramTransferTask(0x18, 0, &gTxtSystem->mSubScreenBuffer, 0x1000);
            }
        }
    }
}

void WriteTxtSystemRegisters(void) {
    if (gTxtSystem->mEnabled != 0) {
        reg_G2_BG2OFS = (gTxtSystem->mBgOffset[0] << 16) & 0x1ff0000;
        reg_G2S_DB_BG0OFS = (gTxtSystem->mBgOffset[1] << 16) & 0x1ff0000;
        if (gTxtSystem->mBlendPlanesEnabled[0] != 0) {
            G2x_SetBlendBrightnessExt_(&reg_G2_BLDCNT, gTxtSystem->mBlendPlanes[0], 0x1f, gTxtSystem->mBlendEv1[0],
                                       gTxtSystem->mBlendEv2[0], gTxtSystem->mBrightness);
        } else {
            G2x_SetBlendBrightnessExt_(&reg_G2_BLDCNT, 0, 0x1f, gTxtSystem->mBlendEv1[0], gTxtSystem->mBlendEv2[0],
                                       gTxtSystem->mBrightness);
        }
        if (gTxtSystem->mBlendPlanesEnabled[1] != 0) {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, gTxtSystem->mBlendPlanes[1], 0x1f, gTxtSystem->mBlendEv1[1],
                                       gTxtSystem->mBlendEv2[1], gTxtSystem->mBrightness);
        } else {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0, 0x1f, gTxtSystem->mBlendEv1[1], gTxtSystem->mBlendEv2[1],
                                       gTxtSystem->mBrightness);
        }
    }
}

void RequestTxtSystemOpen(void) {
    if ((gTxtSystem->mState == 0 && gTxtSystem->mOpenRequested != 0) || gTxtSystem->mState == 1 ||
        gTxtSystem->mState == 2) {
        gTxtSystem->mCloseRequested = 1;
    } else {
        gTxtSystem->mCloseRequested = 0;
    }
    gTxtSystem->mOpenRequested = 1;
}
#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainText(void *text) {
    SetupTxtSystemMainTextEx(text, 1, 1, 1, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainTextEx(void *text, s32 mainBlendPlanes, s32 subBlendPlanes, s32 openFromIndex, s32 closeToIndex,
                              s32 mainAnim, s32 subAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[0];
    charCanvas->mPClear(charCanvas, 0xf);
    DrawTextInRectNoFixedAdvance(&gTxtSystem->mTextCanvases[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3,
                                 gTxtSystemCanvasSizes[0][1] << 3, 1, 0x480, 1, text);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = mainAnim;
    gTxtSystem->mAnimRequested[1] = subAnim;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

void SetupTxtSystemMainTextShort(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex,
                                 u32 closeToIndex, u32 mainAnim, u32 subAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[1];
    charCanvas->mPClear(charCanvas, 0xf);
    DrawTextInRectNoFixedAdvance(&gTxtSystem->mTextCanvases[1], 0, 0, gTxtSystemCanvasSizes[1][0] << 3,
                                 gTxtSystemCanvasSizes[1][1] << 3, 1, 0x480, 1, text);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[1] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = mainAnim;
    gTxtSystem->mAnimRequested[1] = subAnim;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}
#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainTextButton(void *text, void *buttonText) {
    u32 subBlendPlanes = ((0x1u) + (0x0u));
    SetupTxtSystemMainTextButtonEx(text, buttonText, 0x1u, subBlendPlanes, 0x1u, 0x0u, 0x0u);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainTextButtonEx(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                    u32 openFromIndex, u32 closeToIndex, u32 mainAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[0];
    charCanvas->mPClear(charCanvas, 0xf);
    charCanvas = &gTxtSystem->mCharCanvases[4];
    charCanvas->mPClear(charCanvas, 0xe);
    DrawTextInRectNoFixedAdvance(&gTxtSystem->mTextCanvases[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3,
                                 gTxtSystemCanvasSizes[0][1] << 3, 1, 0x480, 1, text);
    DrawButtonTextInRect(&gTxtSystem->mTextCanvases[4], 0, 0, gTxtSystemCanvasSizes[4][0] << 3,
                         gTxtSystemCanvasSizes[4][1] << 3, 2, 0x480, 1, buttonText);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    gTxtSystem->mCanvasInUse[4] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 1;
    gTxtSystem->mSelectedIndex = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = mainAnim;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

void SetupTxtSystemMainTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex) {
    SetupTxtSystemMainTextTwoButtonsEx(text, buttonText, secondButtonText, selectedIndex, 1, 1, 1, 0, 0);
}

void SetupTxtSystemMainTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                        u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                                        u32 mainAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[0];
    charCanvas->mPClear(charCanvas, 0xf);
    charCanvas = &gTxtSystem->mCharCanvases[5];
    charCanvas->mPClear(charCanvas, 0xe);
    charCanvas = &gTxtSystem->mCharCanvases[6];
    charCanvas->mPClear(charCanvas, 0xd);
    DrawTextInRectNoFixedAdvance(&gTxtSystem->mTextCanvases[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3,
                                 gTxtSystemCanvasSizes[0][1] << 3, 1, 0x480, 1, text);
    DrawButtonTextInRect(&gTxtSystem->mTextCanvases[5], 0, 0, gTxtSystemCanvasSizes[5][0] << 3,
                         gTxtSystemCanvasSizes[5][1] << 3, 2, 0x480, 1, buttonText);
    DrawButtonTextInRect(&gTxtSystem->mTextCanvases[6], 0, 0, gTxtSystemCanvasSizes[6][0] << 3,
                         gTxtSystemCanvasSizes[6][1] << 3, 2, 0x480, 1, secondButtonText);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    gTxtSystem->mCanvasInUse[5] = 1;
    gTxtSystem->mCanvasInUse[6] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 2;
    gTxtSystem->mSelectedIndex = selectedIndex;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = mainAnim;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubText(void *text) {
    SetupTxtSystemSubTextEx(text, 1, 1, 1, 0, 0);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextEx(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                             u32 subAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[2];
    charCanvas->mPClear(charCanvas, 0xf);
    DrawTextInRectNoFixedAdvance(&gTxtSystem->mTextCanvases[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3,
                                 gTxtSystemCanvasSizes[2][1] << 3, 1, 0x480, 1, text);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = subAnim;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextButton(void *text, void *buttonText) {
    u32 subBlendPlanes = ((0x1u) + (0x0u));
    SetupTxtSystemSubTextButtonEx(text, buttonText, 0x1u, subBlendPlanes, 0x1u, 0x0u);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextButtonEx(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                   u32 openFromIndex, u32 closeToIndex) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[2];
    charCanvas->mPClear(charCanvas, 0xf);
    charCanvas = &gTxtSystem->mCharCanvases[4];
    charCanvas->mPClear(charCanvas, 0xe);
    DrawTextInRectNoFixedAdvance(&gTxtSystem->mTextCanvases[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3,
                                 gTxtSystemCanvasSizes[2][1] << 3, 1, 0x480, 1, text);
    DrawButtonTextInRect(&gTxtSystem->mTextCanvases[4], 0, 0, gTxtSystemCanvasSizes[4][0] << 3,
                         gTxtSystemCanvasSizes[4][1] << 3, 2, 0x480, 1, buttonText);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    gTxtSystem->mCanvasInUse[4] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 1;
    gTxtSystem->mSelectedIndex = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

void SetupTxtSystemSubTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex) {
    SetupTxtSystemSubTextTwoButtonsEx(text, buttonText, secondButtonText, selectedIndex, 1, 1, 1, 0);
}

void SetupTxtSystemSubTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                       u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[2];
    charCanvas->mPClear(charCanvas, 0xf);
    charCanvas = &gTxtSystem->mCharCanvases[5];
    charCanvas->mPClear(charCanvas, 0xe);
    charCanvas = &gTxtSystem->mCharCanvases[6];
    charCanvas->mPClear(charCanvas, 0xd);
    DrawTextInRectNoFixedAdvance(&gTxtSystem->mTextCanvases[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3,
                                 gTxtSystemCanvasSizes[2][1] << 3, 1, 0x480, 1, text);
    DrawButtonTextInRect(&gTxtSystem->mTextCanvases[5], 0, 0, gTxtSystemCanvasSizes[5][0] << 3,
                         gTxtSystemCanvasSizes[5][1] << 3, 2, 0x480, 1, buttonText);
    DrawButtonTextInRect(&gTxtSystem->mTextCanvases[6], 0, 0, gTxtSystemCanvasSizes[6][0] << 3,
                         gTxtSystemCanvasSizes[6][1] << 3, 2, 0x480, 1, secondButtonText);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    gTxtSystem->mCanvasInUse[5] = 1;
    gTxtSystem->mCanvasInUse[6] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 2;
    gTxtSystem->mSelectedIndex = selectedIndex;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

void RequestTxtSystemClose(void) {
    gTxtSystem->mOpenRequested = 0;
    gTxtSystem->mCloseRequested = 1;
}

BOOL IsTxtSystemState2NoCloseRequest(void) {
    BOOL result;

    result = FALSE;
    if (gTxtSystem->mState == 2 && gTxtSystem->mCloseRequested == 0) {
        result = TRUE;
    }
    return result;
}

BOOL IsTxtSystemState0NoOpenRequest(void) {
    BOOL result;

    result = FALSE;
    if (gTxtSystem->mState == 0 && gTxtSystem->mOpenRequested == 0) {
        result = TRUE;
    }
    return result;
}

BOOL IsTxtSystemState2AfterState1(void) {
    BOOL result;

    result = FALSE;
    if (gTxtSystem->mPrevState == 1 && gTxtSystem->mState == 2) {
        result = TRUE;
    }
    return result;
}

#pragma thumb off

#pragma thumb on
s32 GetTxtSystemSelectedIndex(void) {
    u32 selectedIndex;
    selectedIndex = gTxtSystem->mSelectedIndex;
    return selectedIndex;
}
#pragma thumb off

#pragma thumb on
s32 GetTxtSystemDone(void) {
    u32 done;
    done = gTxtSystem->mDone;
    return done;
}
#pragma thumb off

#pragma thumb on

u32 GetTxtSystemInputAccepted(void) {
    return gTxtSystem->mInputAccepted;
}

void SetTxtSystemMode(u32 mode) {
    gTxtSystem->mMode = mode;
}

#pragma thumb off

#pragma thumb on

void SetTxtSystemBgOffsetRequested(int mainOffset, int subOffset) {
    if (mainOffset < -0x96) {
        mainOffset = -0x96;
    }
    if (mainOffset > 0x96) {
        mainOffset = 0x96;
    }
    if (subOffset < -0x96) {
        subOffset = -0x96;
    }
    if (subOffset > 0x96) {
        subOffset = 0x96;
    }
    gTxtSystem->mBgOffsetRequested[0] = mainOffset;
    gTxtSystem->mBgOffsetRequested[1] = subOffset;
}

#pragma thumb off

#pragma thumb on
void SetTxtSystemSoundId(int soundIndex, u32 soundId) {
    u32 offset = soundIndex;
    u32 soundIdCopy = soundId;
    u32 address;
    address = (u32) &gTxtSystem;
    address = *(const u32 *) ((address) + 0u);
    offset = (offset << 2);
    address = (address) + (offset);
    offset = 0x2250u;
    *(u32 *) ((address) + (offset)) = soundIdCopy;
}
#pragma thumb off

#pragma thumb on

void SetTxtSystemOpenSoundId(u32 soundId) {
    gTxtSystem->mOpenSoundId = soundId;
}

#pragma thumb off
