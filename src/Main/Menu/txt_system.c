#include "Main/Menu/txt_system.h"
#include "registers.h"
#include "fixed_point_graphics_setup.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/text_draw.h"

#include "Main/Menu/back_screen_keyboard_tables.h"
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
#include "Main/Graphics/text_canvas.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/input_slots.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "arena_cache_init.h"
#include "vram_transfer_queue.h"
#include "char_canvas_text_draw.h"
#include "display_blend_affine_setup.h"
#include "sound_archive_load_result.h"
#include "Main/System/stdio_files.h"
#include "print_memory_multibyte_write.h"
#include "capture_output_effect.h"
#include "Main/Graphics/font_and_player_character.h"
#include "thread_scheduler.h"
#include "bg_screen_char_pointers.h"
#include "vram_load_2d_graphics.h"
#include "cpu_copy_clear_16.h"
#include "Main/System/result_archive_path.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u8 g_TextSystemContextTileDimensionTable[8][2] = {{0x16, 0xb}, {0x16, 7}, {0x16, 0xb}, {0x16, 7},
                                        {0x16, 2},   {9, 2},    {9, 2},      {0, 0}};
const s16 g_TextSystemContext_FadeYValues[2] = {0xa0, -176};
const u16 gTxtSystemCanvasCharOffsets[8] = {4, 4, 4, 4, 9, 9, 0x1b, 0};
const ByteRect gTxtSystemNscrRects[7] = {{3, 0x1c, 2, 0xe},       {3, 0x1c, 4, 0xc},        {4, 0x1b, 0x10, 0x13},
                                         {3, 0x1c, 0x10, 0x13},   {0x17, 0x1b, 0x10, 0x13}, {0x17, 0x1b, 0x10, 0x13},
                                         {0x17, 0x1b, 0x10, 0x13}};
const ByteRect gTxtSystemHitRects[7] = {{0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0x20, 0xe0, 0x80, 0xa0},
                                        {0x18, 0x70, 0x80, 0xa0},
                                        {0x90, 0xe8, 0x80, 0xa0}};
TxtSystem *g_TextSystemContext;

#pragma thumb on

void TextSystemContext_DisableAllSprites_from_thumb(void) {
    s32 canvasIndex;

    for (canvasIndex = 0; canvasIndex < 7; canvasIndex++) {
        g_TextSystemContext->mCanvasInUse[canvasIndex] = 0;
    }
}

static inline void InitTxtSystemTextCanvas(TextCanvas *textCanvas, NNSG2dCharCanvas *charCanvas, void *font) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = 1;
    textCanvas->mLineSpacing = 1;
}

s32 TextSystemContext_Initialize_from_thumb(void *heap, TxtSystemArgs *args) {
    s32 subCharOffset;
    s32 index;
    NNSG2dCharCanvas *charCanvas;

    subCharOffset = args->mSubCharOffset;
    g_TextSystemContext = Mem_AllocateHeap(heap, sizeof(*g_TextSystemContext));
    if (args->mUseCanvas1 != 0) {
        g_TextSystemContext->mUseCanvas1 = 1;
    }
    if (args->mUseCanvas2 != 0) {
        g_TextSystemContext->mUseCanvas2 = 1;
    }
    if (args->mUseCanvas3 != 0) {
        g_TextSystemContext->mUseCanvas3 = 1;
    }
    g_TextSystemContext->mEnabled = 1;
    TextSystemContext_InitializeBg_from_thumb();
    subCharOffset = TextSystemContext_LoadGraphics_from_thumb(subCharOffset);
    for (index = 0; index < 7; index++) {
        if (!((index == 1 && g_TextSystemContext->mUseCanvas1 == 0) || (index == 2 && g_TextSystemContext->mUseCanvas2 == 0) ||
              (index == 3 && g_TextSystemContext->mUseCanvas3 == 0))) {
            g_TextSystemContext->mCharBuffers[index] =
                Mem_AllocateHeap(heap, (g_TextSystemContextTileDimensionTable[index][0] * g_TextSystemContextTileDimensionTable[index][1]) << 5);
            G2d_Sprite_CreateFromTiles(&g_TextSystemContext->mCharCanvases[index], g_TextSystemContext->mCharBuffers[index],
                                       g_TextSystemContextTileDimensionTable[index][0], g_TextSystemContextTileDimensionTable[index][1], 4);
            charCanvas = &g_TextSystemContext->mCharCanvases[index];
            charCanvas->mPClear(charCanvas, 0);
            InitTxtSystemTextCanvas(&g_TextSystemContext->mTextCanvases[index], &g_TextSystemContext->mCharCanvases[index], args->mFont);
        }
    }
    TextSystemContext_DisableAllSprites_from_thumb();
    g_TextSystemContext->mState = TXT_SYSTEM_STATE_CLOSED;
    g_TextSystemContext->mNextState = TXT_SYSTEM_STATE_CLOSED;
    g_TextSystemContext->mPrevState = TXT_SYSTEM_STATE_CLOSED;
    g_TextSystemContext->mStateFrames = 0;
    g_TextSystemContext->mAnimFrameIndexFrames = 0;
    g_TextSystemContext->mAnimFrameIndex = 0;
    g_TextSystemContext->mAnimVisible[0] = 0;
    g_TextSystemContext->mAnimVisible[1] = 0;
    g_TextSystemContext->mAnimRequested[0] = 0;
    g_TextSystemContext->mAnimRequested[1] = 0;
    g_TextSystemContext->mBlendPlanesEnabled[0] = 0;
    g_TextSystemContext->mBlendPlanesEnabled[1] = 0;
    g_TextSystemContext->mBlendPlanesRequested[0] = 0;
    g_TextSystemContext->mBlendPlanesRequested[1] = 0;
    g_TextSystemContext->mOpenRequested = 0;
    g_TextSystemContext->mCloseRequested = 0;
    g_TextSystemContext->mDone = 0;
    g_TextSystemContext->mInputAccepted = 0;
    g_TextSystemContext->mInputSoundId = TXT_SYSTEM_INPUT_SOUND_ID;
    g_TextSystemContext->mSecondInputSoundId = TXT_SYSTEM_SECOND_INPUT_SOUND_ID;
    g_TextSystemContext->mOpenSoundId = TXT_SYSTEM_OPEN_SOUND_ID;
    for (index = 0; index < 2; index++) {
        g_TextSystemContext->mBgOffset[index] = -192;
        g_TextSystemContext->mBgOffsetAtOpen[index] = 0;
        g_TextSystemContext->mBgOffsetRequested[index] = 0;
    }
    g_TextSystemContext->mBlendPlanes[0] = GX_PLANEMASK_BG0 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ;
    g_TextSystemContext->mBlendPlanes[1] = GX_PLANEMASK_BG1 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ;
    g_TextSystemContext->mBrightness = 0;
    for (index = 0; index < 2; index++) {
        g_TextSystemContext->mBlendEv1[index] = MENU_BLEND_FIRST_COEFFICIENT;
        g_TextSystemContext->mBlendEv2[index] = MENU_BLEND_SECOND_COEFFICIENT;
    }
    g_TextSystemContext->mMode = 0;
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void TextSystemContext_Dispose_from_thumb(void) {
    g_TextSystemContext = NULL;
}
#pragma thumb off

#pragma thumb on

void TextSystemContext_InitializeBg_from_thumb(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    mainDisplayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((mainDisplayBits | 4) << 8);
    reg_G2_BG2CNT &= ~REG_G2_BG2CNT_PRIORITY_MASK;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0x9e10;
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits | 1) << 8);
    reg_G2S_DB_BG0CNT &= ~REG_G2S_DB_BG0CNT_PRIORITY_MASK;
    reg_G2S_DB_BG0CNT =
        (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0x8b00;
}

static inline void FillScreenBuffer(void *dst, u16 value) {
    vu16 fillValue = value;

    Mem_CpuFill16(fillValue, dst, 0x1000);
}

s32 TextSystemContext_LoadGraphics_from_thumb(s32 subCharOffset) {
    Ncgr *firstChars;
    Ncgr *secondChars;
    Nclr *palette;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        MaybeReadCharBlock_1(&firstChars, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("txt_system_b_00.ncgr"));
        MaybeReadScreenBlock(&g_TextSystemContext->mBgNscrs[0], FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("txt_system_bg_00.nscr"));
        Gfx_ReadPaletteRelative(&palette, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("txt_system_b_00.nclr"));
    } else {
        MaybeReadCharBlock_1(&firstChars, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_b_00.ncgr"));
        MaybeReadCharBlock_1(&secondChars, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_b_01.ncgr"));
        MaybeReadScreenBlock(&g_TextSystemContext->mBgNscrs[0], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_00.nscr"));
        MaybeReadScreenBlock(&g_TextSystemContext->mBgNscrs[1], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_00_2.nscr"));
        MaybeReadScreenBlock(&g_TextSystemContext->mBgNscrs[2], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_01_2.nscr"));
        MaybeReadScreenBlock(&g_TextSystemContext->mBgNscrs[3], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_01.nscr"));
        MaybeReadScreenBlock(&g_TextSystemContext->mBgNscrs[4], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_02.nscr"));
        MaybeReadScreenBlock(&g_TextSystemContext->mBgNscrs[5], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_02_2.nscr"));
        MaybeReadScreenBlock(&g_TextSystemContext->mBgNscrs[6], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_02_3.nscr"));
        Gfx_ReadPaletteRelative(&palette, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_b_00.nclr"));
    }
    g_TextSystemContext->mCanvasFileCharIndex[0] = 0;
    Arm_FlushRange(firstChars->mData, firstChars->mDataSize);
    CopyBgData_Bg2_Top(firstChars->mData, 0, firstChars->mDataSize);
    if (g_TextSystemContext->mUseCanvas2 != 0) {
        subCharOffset = subCharOffset - firstChars->mDataSize;
        g_TextSystemContext->mCanvasFileCharIndex[2] = subCharOffset >> 5;
        Arm_FlushRange(firstChars->mData, firstChars->mDataSize);
        CopyBgData_Bg0_Bottom(firstChars->mData, subCharOffset, firstChars->mDataSize);
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        if (g_TextSystemContext->mUseCanvas1 != 0) {
            g_TextSystemContext->mCanvasFileCharIndex[1] = 0;
        }
        g_TextSystemContext->mB01CharIndex[0] = firstChars->mDataSize >> 5;
        Arm_FlushRange(secondChars->mData, secondChars->mDataSize);
        CopyBgData_Bg2_Top(secondChars->mData, g_TextSystemContext->mB01CharIndex[0] << 5, secondChars->mDataSize);
        if (g_TextSystemContext->mUseCanvas3 != 0) {
            g_TextSystemContext->mCanvasFileCharIndex[3] = g_TextSystemContext->mCanvasFileCharIndex[2];
        }
        subCharOffset = subCharOffset - secondChars->mDataSize;
        g_TextSystemContext->mCanvasFileCharIndex[4] = subCharOffset >> 5;
        g_TextSystemContext->mCanvasFileCharIndex[5] = subCharOffset >> 5;
        g_TextSystemContext->mCanvasFileCharIndex[6] = subCharOffset >> 5;
        g_TextSystemContext->mB01CharIndex[1] = subCharOffset >> 5;
        Arm_FlushRange(secondChars->mData, secondChars->mDataSize);
        CopyBgData_Bg0_Bottom(secondChars->mData, subCharOffset, secondChars->mDataSize);
    }
    Arm_FlushRange(palette->mData, 0x1c0);
    CopyPaletteTop(palette->mData + 0xe0, 0x1c0, 0x40);
    CopyPaletteBottom(palette->mData + 0xe0, 0x1c0, 0x40);
    g_TextSystemContext->mUnselectedButtonColor = palette->mData[0xee];
    g_TextSystemContext->mSelectedButtonColor = palette->mData[0xdf];
    MemFillWordsByBlock_inline((void *) G2_GetBG2ScrPtr(), 0x1000);
    FillScreenBuffer((void *) GetAnotherSubEngineBGOffset(), g_TextSystemContext->mCanvasFileCharIndex[4]);
    return subCharOffset;
}

void TextSystemContext_UpdateAnimationGraphics_from_thumb(void) {
    s32 row;
    s32 screenIndex;
    s32 column;
    s32 rectIndex;
    u16 *screenBuffer;

    rectIndex = g_TextSystemContext->mAnimFrameIndex + 4;
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        if (g_TextSystemContext->mAnimVisible[screenIndex] != 0) {
            screenBuffer = g_TextSystemContext->mMainScreenBuffer;
            if (screenIndex == 1) {
                screenBuffer = g_TextSystemContext->mSubScreenBuffer;
            }
            for (row = gTxtSystemNscrRects[rectIndex].mMinY; row <= gTxtSystemNscrRects[rectIndex].mMaxY; row++) {
                for (column = gTxtSystemNscrRects[rectIndex].mMinX; column <= gTxtSystemNscrRects[rectIndex].mMaxX;
                     column++) {
                    *(screenBuffer + row * 32 + column) =
                        g_TextSystemContext->mB01CharIndex[screenIndex] +
                        *((u16 *) g_TextSystemContext->mBgNscrs[rectIndex]->mData + row * 32 + column);
                }
            }
        }
    }
}

void TextSystemContext_LoadEnabledSpritesAndAnimations_from_thumb(u32 *drawFlags) {
    u8 rectIndices[9] = {0, 1, 0, 1, 2, 3, 0, 0, 0};
    s32 index;
    s32 row;
    s32 column;
    s32 rectIndex;
    u16 *screenBuffer;

    MemFillWordsByBlock_inline(g_TextSystemContext->mMainScreenBuffer, 0x1000);
    FillScreenBuffer(&g_TextSystemContext->mSubScreenBuffer, g_TextSystemContext->mCanvasFileCharIndex[4]);
    for (index = 0; index < 9; index++) {
        if (*drawFlags != 0) {
            if ((u32) (index - 7) <= 1) {
                TextSystemContext_UpdateAnimationGraphics_from_thumb();
            } else if (index != 6) {
                rectIndex = rectIndices[index];
                screenBuffer = g_TextSystemContext->mSubScreenBuffer;
                if ((u32) index <= 1) {
                    screenBuffer = g_TextSystemContext->mMainScreenBuffer;
                }
                for (row = gTxtSystemNscrRects[rectIndex].mMinY; row <= gTxtSystemNscrRects[rectIndex].mMaxY; row++) {
                    for (column = gTxtSystemNscrRects[rectIndex].mMinX; column <= gTxtSystemNscrRects[rectIndex].mMaxX;
                         column++) {
                        *(screenBuffer + row * 32 + column) =
                            g_TextSystemContext->mCanvasFileCharIndex[index] +
                            *((u16 *) g_TextSystemContext->mBgNscrs[rectIndex]->mData + row * 32 + column);
                    }
                }
            }
        }
        drawFlags++;
    }
}
#pragma thumb off

#pragma thumb on

void TextSystemContext_ReloadButtonGraphics_from_thumb(void) {
    TxtSystem *txtSystem;
    txtSystem = g_TextSystemContext;
    if (0 < txtSystem->mExtraCanvasCount) {
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE, ((0xee - txtSystem->mSelectedIndex) * 2),
                                           &txtSystem->mSelectedButtonColor, 2);
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE, (0xfe - g_TextSystemContext->mSelectedIndex) * 2,
                                           &g_TextSystemContext->mSelectedButtonColor, 2);
        txtSystem = g_TextSystemContext;
        if (txtSystem->mExtraCanvasCount == 2) {
            AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE,
                                               ((txtSystem->mSelectedIndex + 0xed) * 2),
                                               &txtSystem->mUnselectedButtonColor, 2);
            AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE, (g_TextSystemContext->mSelectedIndex + 0xfd) * 2,
                                               &g_TextSystemContext->mUnselectedButtonColor, 2);
        }
    }
}

void TextSystemContext_ReloadButtonGraphics2_from_thumb(void) {
    int buttonEntryIndex;
    if (0 < g_TextSystemContext->mExtraCanvasCount) {
        buttonEntryIndex = 0;
        do {
            AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE, ((buttonEntryIndex + 0xed) * 2),
                                               &g_TextSystemContext->mUnselectedButtonColor, 2);
            AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE, ((buttonEntryIndex + 0xfd) * 2),
                                               &g_TextSystemContext->mUnselectedButtonColor, 2);
            buttonEntryIndex = buttonEntryIndex + 1;
        } while (buttonEntryIndex < 2);
    }
}

#pragma thumb off

#pragma thumb on

// Closed: serves an open request by building the screens and queueing them.
void TextSystemContext_UpdateFn_State0_from_thumb(void) {
    u32 drawFlags[9];
    s32 index;
    s32 bufferSize;
    s32 queueCommand;

    if (g_TextSystemContext->mOpenRequested != 0) {
        for (index = 0; index < 9; index++) {
            if (index <= 6) {
                if (g_TextSystemContext->mCanvasInUse[index] != 0) {
                    drawFlags[index] = 1;
                } else {
                    drawFlags[index] = 0;
                }
            } else {
                if ((&g_TextSystemContext->mNextState)[index] != 0) {
                    (&g_TextSystemContext->mNextState)[index] = 0;
                    *(&g_TextSystemContext->mState + index - 1) = 1;
                    drawFlags[index] = 1;
                } else {
                    drawFlags[index] = 0;
                }
            }
        }
        TextSystemContext_LoadEnabledSpritesAndAnimations_from_thumb(drawFlags);
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_BG2_MAP, 0, g_TextSystemContext->mMainScreenBuffer, 0x1000);
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_MAP, 0, &g_TextSystemContext->mSubScreenBuffer, 0x1000);
        g_TextSystemContext->mNextState = TXT_SYSTEM_STATE_OPENING;
        g_TextSystemContext->mStateFrames = 0;
        for (index = 0; index < 2; index++) {
            g_TextSystemContext->mBgOffsetAtOpen[index] = g_TextSystemContext->mBgOffsetRequested[index];
        }
        for (index = 0; index < 2; index++) {
            g_TextSystemContext->mBlendPlanesEnabled[index] = g_TextSystemContext->mBlendPlanesRequested[index];
        }
        for (index = 0; index < 7; index++) {
            if (g_TextSystemContext->mCanvasInUse[index] != 0) {
                bufferSize = (g_TextSystemContextTileDimensionTable[index][0] * g_TextSystemContextTileDimensionTable[index][1]) << 5;
                queueCommand = 0x14;
                if ((u32) index <= 1) {
                    queueCommand = 6;
                }
                AllocateReserveTEQSub(
                    queueCommand, (g_TextSystemContext->mCanvasFileCharIndex[index] + gTxtSystemCanvasCharOffsets[index]) << 5,
                    g_TextSystemContext->mCharBuffers[index], bufferSize);
            }
        }
        if (g_TextSystemContext->mExtraCanvasCount > 0) {
            TextSystemContext_ReloadButtonGraphics_from_thumb();
        }
        if (g_TextSystemContext->mAnimVisible[0] == 0 && g_TextSystemContext->mAnimVisible[1] == 0) {
            if (g_TextSystemContext->mOpenSoundId != -1) {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, (u16) g_TextSystemContext->mOpenSoundId);
            }
        }
    }
}

// Opening: slides the box in over 15 steps.
void TextSystemContext_UpdateFn_State1_from_thumb(void) {
    TxtSystem *txtSystem;
    s32 screenIndex;

    g_TextSystemContext->mStateFrames++;
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        g_TextSystemContext->mBgOffset[screenIndex] =
            ComputeValueInterpolation_from_thumb(1, g_TextSystemContext_FadeYValues[g_TextSystemContext->mOpenFromIndex],
                           -g_TextSystemContext->mBgOffsetAtOpen[screenIndex], g_TextSystemContext->mStateFrames, TXT_SYSTEM_SLIDE_STEPS);
    }
    txtSystem = g_TextSystemContext;
    txtSystem->mBrightness = (txtSystem->mStateFrames * -10) / TXT_SYSTEM_SLIDE_STEPS;
    if (g_TextSystemContext->mStateFrames >= TXT_SYSTEM_SLIDE_STEPS) {
        if (g_TextSystemContext->mCloseRequested == 0) {
            g_TextSystemContext->mOpenRequested = 0;
        }
        g_TextSystemContext->mNextState = TXT_SYSTEM_STATE_OPEN;
        g_TextSystemContext->mStateFrames = 0;
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

    if (g_GlobalCYT[inputSlotIndex].mPair.mHasPair == 0 &&
        g_GlobalCYT[inputSlotIndex].mPair.mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && g_GlobalCYT[inputSlotIndex].mPair.mPrevHasPair == 0 &&
        g_GlobalCYT[inputSlotIndex].mPair.mHasPair != 0) {
        result = TRUE;
    }
    return result;
}

// Open: answers a close request, or a touch or key press when the box has buttons.
void TextSystemContext_UpdateFn_State2_from_thumb(void) {
    s32 buttonCount;
    s32 offsetTouchY;
    u16 clampedTouchY;
    s32 hit;
    u16 touchX;
    TxtSystem *txtSystem;
    u32 inputSlotIndex;
    u16 keys;

    switch (g_TextSystemContext->mMode) {
        case 0:
            inputSlotIndex = 8;
            break;
        case 1:
            inputSlotIndex = GetSomeCYId_9();
            break;
    }
    touchX = g_GlobalCYT[inputSlotIndex].mPair.mPairX;
    txtSystem = g_TextSystemContext;
    offsetTouchY = txtSystem->mBgOffset[1] + g_GlobalCYT[inputSlotIndex].mPair.mPairY;
    if (offsetTouchY < 0) {
        offsetTouchY = 0xff;
    }
    if (offsetTouchY > 0xff) {
        offsetTouchY = 0xff;
    }
    clampedTouchY = offsetTouchY;
    if (txtSystem->mCloseRequested != 0) {
        txtSystem->mNextState = TXT_SYSTEM_STATE_CLOSING;
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
    keys = g_GlobalCYT[inputSlotIndex].mPressedBits;
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
        TextSystemContext_ReloadButtonGraphics2_from_thumb();
    } else {
        if (hit == -1 || txtSystem->mSelectedIndex == hit) {
            TextSystemContext_ReloadButtonGraphics2_from_thumb();
        } else {
            txtSystem->mSelectedIndex = hit;
            TextSystemContext_ReloadButtonGraphics_from_thumb();
        }
    }
    g_TextSystemContext->mNextState = TXT_SYSTEM_STATE_BUTTON_PRESSED;
    if (g_TextSystemContext->mExtraCanvasCount == 2 && g_TextSystemContext->mSelectedIndex == 1) {
        if (g_TextSystemContext->mSecondInputSoundId != -1) {
            PlaySseqFromSarc(&gSharedSeqHandle, 0, (u16) g_TextSystemContext->mSecondInputSoundId);
        }
    } else {
        if (g_TextSystemContext->mInputSoundId != -1) {
            PlaySseqFromSarc(&gSharedSeqHandle, 0, (u16) g_TextSystemContext->mInputSoundId);
        }
    }
    g_TextSystemContext->mInputAccepted = 1;
    return;
L:
    if (buttonCount == 2) {
        if ((u16) (keys & PAD_KEY_LEFT) != 0 && txtSystem->mSelectedIndex == 1) {
            txtSystem->mSelectedIndex = 0;
            TextSystemContext_ReloadButtonGraphics_from_thumb();
            MaybePlaySomeSseqFromSarc0(0);
            return;
        }
        if ((u16) (keys & 0x10) != 0 && txtSystem->mSelectedIndex == 0) {
            txtSystem->mSelectedIndex = 1;
            TextSystemContext_ReloadButtonGraphics_from_thumb();
            MaybePlaySomeSseqFromSarc0(0);
        }
    }
}

// ButtonPressed: ten steps after an accepted input, then sets mDone.
void TextSystemContext_UpdateFn_State3_from_thumb(void) {
    g_TextSystemContext->mStateFrames++;
    g_TextSystemContext->mInputAccepted = 0;
    if (g_TextSystemContext->mStateFrames >= TXT_SYSTEM_PRESS_STEPS) {
        g_TextSystemContext->mDone = 1;
        g_TextSystemContext->mNextState = TXT_SYSTEM_STATE_OPEN;
        g_TextSystemContext->mStateFrames = 0;
    } else if (g_TextSystemContext->mStateFrames >= TXT_SYSTEM_PRESS_COLOR_STEP) {
        TextSystemContext_ReloadButtonGraphics_from_thumb();
    }
}

// Closing: slides the box out over 15 steps.
void TextSystemContext_UpdateFn_State4_from_thumb(void) {
    TxtSystem *txtSystem;
    s32 screenIndex;

    g_TextSystemContext->mStateFrames++;
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        g_TextSystemContext->mBgOffset[screenIndex] =
            ComputeValueInterpolation_from_thumb(1, -g_TextSystemContext->mBgOffsetAtOpen[screenIndex], g_TextSystemContext_FadeYValues[g_TextSystemContext->mCloseToIndex],
                           g_TextSystemContext->mStateFrames, TXT_SYSTEM_SLIDE_STEPS);
    }
    txtSystem = g_TextSystemContext;
    txtSystem->mBrightness = -10 - (txtSystem->mStateFrames * -10) / TXT_SYSTEM_SLIDE_STEPS;
    if (g_TextSystemContext->mStateFrames >= TXT_SYSTEM_SLIDE_STEPS) {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            g_TextSystemContext->mBgOffset[screenIndex] = -192;
        }
        g_TextSystemContext->mNextState = TXT_SYSTEM_STATE_CLOSED;
        TextSystemContext_ReloadButtonGraphics2_from_thumb();
        g_TextSystemContext->mStateFrames = 0;
        g_TextSystemContext->mCloseRequested = 0;
        g_TextSystemContext->mDone = 0;
        g_TextSystemContext->mAnimVisible[0] = 0;
        g_TextSystemContext->mAnimVisible[1] = 0;
    }
}

void TextSystemContext_OnSceneUpdate_from_thumb(void) {
    if (g_TextSystemContext->mEnabled != 0) {
        g_TextSystemContext->mPrevState = g_TextSystemContext->mState;
        g_TextSystemContext->mState = g_TextSystemContext->mNextState;
        switch (g_TextSystemContext->mState) {
            case TXT_SYSTEM_STATE_CLOSED:
                TextSystemContext_UpdateFn_State0_from_thumb();
                break;
            case TXT_SYSTEM_STATE_OPENING:
                TextSystemContext_UpdateFn_State1_from_thumb();
                break;
            case TXT_SYSTEM_STATE_OPEN:
                TextSystemContext_UpdateFn_State2_from_thumb();
                break;
            case TXT_SYSTEM_STATE_BUTTON_PRESSED:
                TextSystemContext_UpdateFn_State3_from_thumb();
                break;
            case TXT_SYSTEM_STATE_CLOSING:
                TextSystemContext_UpdateFn_State4_from_thumb();
                break;
        }
        if (g_TextSystemContext->mAnimVisible[0] != 0 || g_TextSystemContext->mAnimVisible[1] != 0) {
            g_TextSystemContext->mAnimFrameIndexFrames++;
            if (g_TextSystemContext->mAnimFrameIndexFrames >= TXT_SYSTEM_ANIM_FRAME_TICKS) {
                g_TextSystemContext->mAnimFrameIndexFrames = 0;
                g_TextSystemContext->mAnimFrameIndex++;
                if (g_TextSystemContext->mAnimFrameIndex >= TXT_SYSTEM_ANIM_FRAME_COUNT) {
                    g_TextSystemContext->mAnimFrameIndex = 0;
                }
                TextSystemContext_UpdateAnimationGraphics_from_thumb();
                AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_BG2_MAP, 0, g_TextSystemContext->mMainScreenBuffer,
                                                   0x1000);
                AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_MAP, 0, &g_TextSystemContext->mSubScreenBuffer,
                                                   0x1000);
            }
        }
    }
}

void TextSystemContext_OnSceneVblank_from_thumb(void) {
    if (g_TextSystemContext->mEnabled != 0) {
        reg_G2_BG2OFS = (g_TextSystemContext->mBgOffset[0] << 16) & 0x1ff0000;
        reg_G2S_DB_BG0OFS = (g_TextSystemContext->mBgOffset[1] << 16) & 0x1ff0000;
        if (g_TextSystemContext->mBlendPlanesEnabled[0] != 0) {
            UpdateBldcntBldalphaBldy(&reg_G2_BLDCNT, g_TextSystemContext->mBlendPlanes[0], 0x1f, g_TextSystemContext->mBlendEv1[0],
                                       g_TextSystemContext->mBlendEv2[0], g_TextSystemContext->mBrightness);
        } else {
            UpdateBldcntBldalphaBldy(&reg_G2_BLDCNT, 0, 0x1f, g_TextSystemContext->mBlendEv1[0], g_TextSystemContext->mBlendEv2[0],
                                       g_TextSystemContext->mBrightness);
        }
        if (g_TextSystemContext->mBlendPlanesEnabled[1] != 0) {
            UpdateBldcntBldalphaBldy(&reg_G2S_DB_BLDCNT, g_TextSystemContext->mBlendPlanes[1], 0x1f, g_TextSystemContext->mBlendEv1[1],
                                       g_TextSystemContext->mBlendEv2[1], g_TextSystemContext->mBrightness);
        } else {
            UpdateBldcntBldalphaBldy(&reg_G2S_DB_BLDCNT, 0, 0x1f, g_TextSystemContext->mBlendEv1[1], g_TextSystemContext->mBlendEv2[1],
                                       g_TextSystemContext->mBrightness);
        }
    }
}

void TextSystemContext_StartDialog_from_thumb(void) {
    if ((g_TextSystemContext->mState == TXT_SYSTEM_STATE_CLOSED && g_TextSystemContext->mOpenRequested != 0) ||
        g_TextSystemContext->mState == TXT_SYSTEM_STATE_OPENING || g_TextSystemContext->mState == TXT_SYSTEM_STATE_OPEN) {
        g_TextSystemContext->mCloseRequested = 1;
    } else {
        g_TextSystemContext->mCloseRequested = 0;
    }
    g_TextSystemContext->mOpenRequested = 1;
}
#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainText(void *text) {
    TextSystem_DisplayProgressDialog_TopScreen_from_thumb(text, 1, 1, 1, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void TextSystem_DisplayProgressDialog_TopScreen_from_thumb(void *text, s32 mainBlendPlanes, s32 subBlendPlanes, s32 openFromIndex, s32 closeToIndex,
                              s32 mainAnim, s32 subAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &g_TextSystemContext->mCharCanvases[0];
    charCanvas->mPClear(charCanvas, 0xf);
    G2d_Text_SomeFn_from_thumb(&g_TextSystemContext->mTextCanvases[0], 0, 0, g_TextSystemContextTileDimensionTable[0][0] << 3,
                                 g_TextSystemContextTileDimensionTable[0][1] << 3, 1, 0x480, 1, text);
    TextSystemContext_DisableAllSprites_from_thumb();
    g_TextSystemContext->mCanvasInUse[0] = 1;
    TextSystemContext_StartDialog_from_thumb();
    g_TextSystemContext->mExtraCanvasCount = 0;
    g_TextSystemContext->mDone = 0;
    g_TextSystemContext->mAnimRequested[0] = mainAnim;
    g_TextSystemContext->mAnimRequested[1] = subAnim;
    g_TextSystemContext->mBlendPlanesRequested[0] = mainBlendPlanes;
    g_TextSystemContext->mBlendPlanesRequested[1] = subBlendPlanes;
    g_TextSystemContext->mOpenFromIndex = openFromIndex;
    g_TextSystemContext->mCloseToIndex = closeToIndex;
}

void SetupTxtSystemMainTextShort(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex,
                                 u32 closeToIndex, u32 mainAnim, u32 subAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &g_TextSystemContext->mCharCanvases[1];
    charCanvas->mPClear(charCanvas, 0xf);
    G2d_Text_SomeFn_from_thumb(&g_TextSystemContext->mTextCanvases[1], 0, 0, g_TextSystemContextTileDimensionTable[1][0] << 3,
                                 g_TextSystemContextTileDimensionTable[1][1] << 3, 1, 0x480, 1, text);
    TextSystemContext_DisableAllSprites_from_thumb();
    g_TextSystemContext->mCanvasInUse[1] = 1;
    TextSystemContext_StartDialog_from_thumb();
    g_TextSystemContext->mExtraCanvasCount = 0;
    g_TextSystemContext->mDone = 0;
    g_TextSystemContext->mAnimRequested[0] = mainAnim;
    g_TextSystemContext->mAnimRequested[1] = subAnim;
    g_TextSystemContext->mBlendPlanesRequested[0] = mainBlendPlanes;
    g_TextSystemContext->mBlendPlanesRequested[1] = subBlendPlanes;
    g_TextSystemContext->mOpenFromIndex = openFromIndex;
    g_TextSystemContext->mCloseToIndex = closeToIndex;
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

    charCanvas = &g_TextSystemContext->mCharCanvases[0];
    charCanvas->mPClear(charCanvas, 0xf);
    charCanvas = &g_TextSystemContext->mCharCanvases[4];
    charCanvas->mPClear(charCanvas, 0xe);
    G2d_Text_SomeFn_from_thumb(&g_TextSystemContext->mTextCanvases[0], 0, 0, g_TextSystemContextTileDimensionTable[0][0] << 3,
                                 g_TextSystemContextTileDimensionTable[0][1] << 3, 1, 0x480, 1, text);
    G2d_Text_SomeFn_1_from_thumb(&g_TextSystemContext->mTextCanvases[4], 0, 0, g_TextSystemContextTileDimensionTable[4][0] << 3,
                         g_TextSystemContextTileDimensionTable[4][1] << 3, 2, 0x480, 1, buttonText);
    TextSystemContext_DisableAllSprites_from_thumb();
    g_TextSystemContext->mCanvasInUse[0] = 1;
    g_TextSystemContext->mCanvasInUse[4] = 1;
    TextSystemContext_StartDialog_from_thumb();
    g_TextSystemContext->mExtraCanvasCount = 1;
    g_TextSystemContext->mSelectedIndex = 0;
    g_TextSystemContext->mDone = 0;
    g_TextSystemContext->mAnimRequested[0] = mainAnim;
    g_TextSystemContext->mAnimRequested[1] = 0;
    g_TextSystemContext->mBlendPlanesRequested[0] = mainBlendPlanes;
    g_TextSystemContext->mBlendPlanesRequested[1] = subBlendPlanes;
    g_TextSystemContext->mOpenFromIndex = openFromIndex;
    g_TextSystemContext->mCloseToIndex = closeToIndex;
}

void SetupTxtSystemMainTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex) {
    SetupTxtSystemMainTextTwoButtonsEx(text, buttonText, secondButtonText, selectedIndex, 1, 1, 1, 0, 0);
}

void SetupTxtSystemMainTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                        u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                                        u32 mainAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &g_TextSystemContext->mCharCanvases[0];
    charCanvas->mPClear(charCanvas, 0xf);
    charCanvas = &g_TextSystemContext->mCharCanvases[5];
    charCanvas->mPClear(charCanvas, 0xe);
    charCanvas = &g_TextSystemContext->mCharCanvases[6];
    charCanvas->mPClear(charCanvas, 0xd);
    G2d_Text_SomeFn_from_thumb(&g_TextSystemContext->mTextCanvases[0], 0, 0, g_TextSystemContextTileDimensionTable[0][0] << 3,
                                 g_TextSystemContextTileDimensionTable[0][1] << 3, 1, 0x480, 1, text);
    G2d_Text_SomeFn_1_from_thumb(&g_TextSystemContext->mTextCanvases[5], 0, 0, g_TextSystemContextTileDimensionTable[5][0] << 3,
                         g_TextSystemContextTileDimensionTable[5][1] << 3, 2, 0x480, 1, buttonText);
    G2d_Text_SomeFn_1_from_thumb(&g_TextSystemContext->mTextCanvases[6], 0, 0, g_TextSystemContextTileDimensionTable[6][0] << 3,
                         g_TextSystemContextTileDimensionTable[6][1] << 3, 2, 0x480, 1, secondButtonText);
    TextSystemContext_DisableAllSprites_from_thumb();
    g_TextSystemContext->mCanvasInUse[0] = 1;
    g_TextSystemContext->mCanvasInUse[5] = 1;
    g_TextSystemContext->mCanvasInUse[6] = 1;
    TextSystemContext_StartDialog_from_thumb();
    g_TextSystemContext->mExtraCanvasCount = 2;
    g_TextSystemContext->mSelectedIndex = selectedIndex;
    g_TextSystemContext->mDone = 0;
    g_TextSystemContext->mAnimRequested[0] = mainAnim;
    g_TextSystemContext->mAnimRequested[1] = 0;
    g_TextSystemContext->mBlendPlanesRequested[0] = mainBlendPlanes;
    g_TextSystemContext->mBlendPlanesRequested[1] = subBlendPlanes;
    g_TextSystemContext->mOpenFromIndex = openFromIndex;
    g_TextSystemContext->mCloseToIndex = closeToIndex;
}

#pragma thumb off

#pragma thumb on

void TextSystem_DisplayProgressDialog_Simple_from_thumb(void *text) {
    TextSystem_DisplayProgressDialog_from_thumb(text, 1, 1, 1, 0, 0);
}

#pragma thumb off

#pragma thumb on

void TextSystem_DisplayProgressDialog_from_thumb(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                             u32 subAnim) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &g_TextSystemContext->mCharCanvases[2];
    charCanvas->mPClear(charCanvas, 0xf);
    G2d_Text_SomeFn_from_thumb(&g_TextSystemContext->mTextCanvases[2], 0, 0, g_TextSystemContextTileDimensionTable[2][0] << 3,
                                 g_TextSystemContextTileDimensionTable[2][1] << 3, 1, 0x480, 1, text);
    TextSystemContext_DisableAllSprites_from_thumb();
    g_TextSystemContext->mCanvasInUse[2] = 1;
    TextSystemContext_StartDialog_from_thumb();
    g_TextSystemContext->mExtraCanvasCount = 0;
    g_TextSystemContext->mDone = 0;
    g_TextSystemContext->mAnimRequested[0] = 0;
    g_TextSystemContext->mAnimRequested[1] = subAnim;
    g_TextSystemContext->mBlendPlanesRequested[0] = mainBlendPlanes;
    g_TextSystemContext->mBlendPlanesRequested[1] = subBlendPlanes;
    g_TextSystemContext->mOpenFromIndex = openFromIndex;
    g_TextSystemContext->mCloseToIndex = closeToIndex;
}

#pragma thumb off

#pragma thumb on

void TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(void *text, void *buttonText) {
    u32 subBlendPlanes = ((0x1u) + (0x0u));
    TextSystem_DisplaySingleButtonDialog_from_thumb(text, buttonText, 0x1u, subBlendPlanes, 0x1u, 0x0u);
}

#pragma thumb off

#pragma thumb on

void TextSystem_DisplaySingleButtonDialog_from_thumb(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                   u32 openFromIndex, u32 closeToIndex) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &g_TextSystemContext->mCharCanvases[2];
    charCanvas->mPClear(charCanvas, 0xf);
    charCanvas = &g_TextSystemContext->mCharCanvases[4];
    charCanvas->mPClear(charCanvas, 0xe);
    G2d_Text_SomeFn_from_thumb(&g_TextSystemContext->mTextCanvases[2], 0, 0, g_TextSystemContextTileDimensionTable[2][0] << 3,
                                 g_TextSystemContextTileDimensionTable[2][1] << 3, 1, 0x480, 1, text);
    G2d_Text_SomeFn_1_from_thumb(&g_TextSystemContext->mTextCanvases[4], 0, 0, g_TextSystemContextTileDimensionTable[4][0] << 3,
                         g_TextSystemContextTileDimensionTable[4][1] << 3, 2, 0x480, 1, buttonText);
    TextSystemContext_DisableAllSprites_from_thumb();
    g_TextSystemContext->mCanvasInUse[2] = 1;
    g_TextSystemContext->mCanvasInUse[4] = 1;
    TextSystemContext_StartDialog_from_thumb();
    g_TextSystemContext->mExtraCanvasCount = 1;
    g_TextSystemContext->mSelectedIndex = 0;
    g_TextSystemContext->mDone = 0;
    g_TextSystemContext->mAnimRequested[0] = 0;
    g_TextSystemContext->mAnimRequested[1] = 0;
    g_TextSystemContext->mBlendPlanesRequested[0] = mainBlendPlanes;
    g_TextSystemContext->mBlendPlanesRequested[1] = subBlendPlanes;
    g_TextSystemContext->mOpenFromIndex = openFromIndex;
    g_TextSystemContext->mCloseToIndex = closeToIndex;
}

void TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex) {
    TextSystem_DisplayDoubleButtonDialog_from_thumb(text, buttonText, secondButtonText, selectedIndex, 1, 1, 1, 0);
}

void TextSystem_DisplayDoubleButtonDialog_from_thumb(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                       u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &g_TextSystemContext->mCharCanvases[2];
    charCanvas->mPClear(charCanvas, 0xf);
    charCanvas = &g_TextSystemContext->mCharCanvases[5];
    charCanvas->mPClear(charCanvas, 0xe);
    charCanvas = &g_TextSystemContext->mCharCanvases[6];
    charCanvas->mPClear(charCanvas, 0xd);
    G2d_Text_SomeFn_from_thumb(&g_TextSystemContext->mTextCanvases[2], 0, 0, g_TextSystemContextTileDimensionTable[2][0] << 3,
                                 g_TextSystemContextTileDimensionTable[2][1] << 3, 1, 0x480, 1, text);
    G2d_Text_SomeFn_1_from_thumb(&g_TextSystemContext->mTextCanvases[5], 0, 0, g_TextSystemContextTileDimensionTable[5][0] << 3,
                         g_TextSystemContextTileDimensionTable[5][1] << 3, 2, 0x480, 1, buttonText);
    G2d_Text_SomeFn_1_from_thumb(&g_TextSystemContext->mTextCanvases[6], 0, 0, g_TextSystemContextTileDimensionTable[6][0] << 3,
                         g_TextSystemContextTileDimensionTable[6][1] << 3, 2, 0x480, 1, secondButtonText);
    TextSystemContext_DisableAllSprites_from_thumb();
    g_TextSystemContext->mCanvasInUse[2] = 1;
    g_TextSystemContext->mCanvasInUse[5] = 1;
    g_TextSystemContext->mCanvasInUse[6] = 1;
    TextSystemContext_StartDialog_from_thumb();
    g_TextSystemContext->mExtraCanvasCount = 2;
    g_TextSystemContext->mSelectedIndex = selectedIndex;
    g_TextSystemContext->mDone = 0;
    g_TextSystemContext->mAnimRequested[0] = 0;
    g_TextSystemContext->mAnimRequested[1] = 0;
    g_TextSystemContext->mBlendPlanesRequested[0] = mainBlendPlanes;
    g_TextSystemContext->mBlendPlanesRequested[1] = subBlendPlanes;
    g_TextSystemContext->mOpenFromIndex = openFromIndex;
    g_TextSystemContext->mCloseToIndex = closeToIndex;
}

void TextSystem_CloseDialog_from_thumb(void) {
    g_TextSystemContext->mOpenRequested = 0;
    g_TextSystemContext->mCloseRequested = 1;
}

BOOL TextSystem_IsDialogIdle_from_thumb(void) {
    BOOL result;

    result = FALSE;
    if (g_TextSystemContext->mState == TXT_SYSTEM_STATE_OPEN && g_TextSystemContext->mCloseRequested == 0) {
        result = TRUE;
    }
    return result;
}

BOOL TextSystem_IsDialogFinished_from_thumb(void) {
    BOOL result;

    result = FALSE;
    if (g_TextSystemContext->mState == TXT_SYSTEM_STATE_CLOSED && g_TextSystemContext->mOpenRequested == 0) {
        result = TRUE;
    }
    return result;
}

BOOL TextSystem_JustFadedIn_from_thumb(void) {
    BOOL result;

    result = FALSE;
    if (g_TextSystemContext->mPrevState == TXT_SYSTEM_STATE_OPENING && g_TextSystemContext->mState == TXT_SYSTEM_STATE_OPEN) {
        result = TRUE;
    }
    return result;
}

#pragma thumb off

#pragma thumb on
s32 TextSystem_IsButton2Focused_from_thumb(void) {
    u32 selectedIndex;
    selectedIndex = g_TextSystemContext->mSelectedIndex;
    return selectedIndex;
}
#pragma thumb off

#pragma thumb on
s32 TextSystem_WasAnyDialogButtonPressed_from_thumb(void) {
    u32 done;
    done = g_TextSystemContext->mDone;
    return done;
}
#pragma thumb off

#pragma thumb on

u32 GetTxtSystemInputAccepted(void) {
    return g_TextSystemContext->mInputAccepted;
}

void SetTxtSystemMode(u32 mode) {
    g_TextSystemContext->mMode = mode;
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
    g_TextSystemContext->mBgOffsetRequested[0] = mainOffset;
    g_TextSystemContext->mBgOffsetRequested[1] = subOffset;
}

#pragma thumb off

#pragma thumb on
void SetTxtSystemSoundId(int soundIndex, u32 soundId) {
    u32 offset = soundIndex;
    u32 soundIdCopy = soundId;
    u32 address;
    address = (u32) &g_TextSystemContext;
    address = *(const u32 *) ((address) + 0u);
    offset = (offset << 2);
    address = (address) + (offset);
    offset = 0x2250u;
    *(u32 *) ((address) + (offset)) = soundIdCopy;
}
#pragma thumb off

#pragma thumb on

void TextSystem_SetFadeInSseqId_from_thumb(u32 soundId) {
    g_TextSystemContext->mOpenSoundId = soundId;
}

#pragma thumb off
