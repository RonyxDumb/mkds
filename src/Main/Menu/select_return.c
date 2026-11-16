#include "Main/Menu/select_return.h"
#include "registers.h"

#include "Main/System/heap.h"
#include "Main/Graphics/text_draw.h"
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
#include "arena_cache_init.h"
#include "vram_transfer_queue.h"
#include "char_canvas_text_draw.h"
#include "display_blend_affine_setup.h"
#include "Main/System/input_slots.h"
#include "Main/Graphics/font_and_player_character.h"
#include "thread_scheduler.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/System/stdio_files.h"
#include "print_memory_multibyte_write.h"
#include "capture_output_effect.h"
#include "vram_load_2d_graphics.h"
#include "Main/System/result_archive_path.h"
#include "sound_archive_load_result.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u8 gSelectChoisesNscrOrigins[2][2] = {{2, 8}, {2, 0xe}};
const ByteRect gSelectChoisesTileRect = {1, 1, 1, 2};
const ByteRect gSelectChoisesPaletteRects[2] = {{1, 0x1e, 7, 0xa}, {1, 0x1e, 0xd, 0x10}};
const s8 gSelectReturnPressBg2Offsets[12] = {4, 8, 0xb, 0xd, 0xc, 0xc, 0xa, 4, 0, 0, 0, 0};
const s8 gSelectReturnSlideInBg2Offsets[12] = {-40, -30, -22, -16, -10, -6, -4, -2, -1, 0, 0, 0};
const s8 gSelectReturnSlideOutBg2Offsets[12] = {0, -6, -12, -18, -24, -30, -40, -40, -40, -40, 0, 0};
const ByteRect gSelectChoisesHitRects[2] = {{8, 0xf8, 0x3c, 0x53}, {8, 0xf8, 0x6c, 0x83}};
SelectReturn *g_SelectReturn;
SelectChoises *g_SelectChoisesContext;

#pragma thumb on
s32 InitializeSelectReturn_from_thumb(void *heap, s32 subCharOffset) {
    u32 subDisplayBits;
    g_SelectReturn = Mem_AllocateHeap(heap, sizeof(*g_SelectReturn));
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InitSelectReturnDisplay();
        subCharOffset = LoadSelectReturnGraphics_from_thumb(subCharOffset);
        g_SelectReturn->mDisplayBitOn = TRUE;
    } else {
        g_SelectReturn->mDisplayBitOn = FALSE;
        subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
        subDisplayBits &= ~4;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
    }
    g_SelectReturn->mEnabled = TRUE;
    g_SelectReturn->mState = SELECT_RETURN_STATE_HIDDEN;
    g_SelectReturn->mNextState = SELECT_RETURN_STATE_HIDDEN;
    g_SelectReturn->mStateFrames = 0;
    g_SelectReturn->mSlideInRequested = FALSE;
    g_SelectReturn->mSlideOutRequested = FALSE;
    g_SelectReturn->mBg2Offset = -0x28;
    g_SelectReturn->mSoundId = SELECT_RETURN_SOUND_ID;
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void SelectReturnContext_Dispose_from_thumb(void) {
    g_SelectReturn = NULL;
}
#pragma thumb off

#pragma thumb on
void InitSelectReturnDisplay(void) {
    u32 subDisplayBits;
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits | 4) << 8);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0xe00;
}

s32 LoadSelectReturnGraphics_from_thumb(s32 subCharOffset) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;
    s32 rowIndex;
    s32 columnIndex;
    s32 unusedValue;
    MaybeReadCharBlock_1(&ncgr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_return_s_b_00.ncgr"));
    MaybeReadScreenBlock(&nscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_return_s_bg_00.nscr"));
    Gfx_ReadPaletteRelative(&nclr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_return_s_b_00.nclr"));
    subCharOffset -= ncgr->mDataSize;
    Arm_FlushRange(ncgr->mData, ncgr->mDataSize);
    CopyBgData_Bg2_Bottom(ncgr->mData, subCharOffset, ncgr->mDataSize);
    for (rowIndex = 0; rowIndex < 0x20; rowIndex++) {
        for (columnIndex = 0; columnIndex < 0x20; columnIndex++) {
            *(g_SelectReturn->mScreenMapCopy + rowIndex * 0x20 + columnIndex) =
                (subCharOffset >> 5) + *((u16 *) nscr->mData + rowIndex * 0x20 + columnIndex);
        }
    }
    Arm_FlushRange(g_SelectReturn->mScreenMapCopy, nscr->mDataSize);
    TEQSub_Fn26Impl_Fn28Impl(g_SelectReturn->mScreenMapCopy, 0, nscr->mDataSize);
    Arm_FlushRange(nclr->mData, 0x180);
    CopyPaletteBottom(nclr->mData + 0xc0, 0x180, 0x40);
    return subCharOffset;
}

void SetSelectReturnPaletteBits(s32 paletteKind) {
    s32 tileIndex;
    u16 paletteBits;
    paletteBits = 0xc000;
    if (paletteKind == 0) {
        paletteBits = 0xd000;
    }
    for (tileIndex = 0x260; tileIndex < 0x360; tileIndex++) {
        g_SelectReturn->mScreenMapCopy[tileIndex] &= ~0xf000;
        g_SelectReturn->mScreenMapCopy[tileIndex] |= paletteBits;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG2_MAP, 0x4c0, &g_SelectReturn->mScreenMapCopy[0x260],
                                           0x200);
    }
}

void AdvanceSelectReturnHidden(void) {
    if (g_SelectReturn->mSlideInRequested != FALSE) {
        g_SelectReturn->mNextState = SELECT_RETURN_STATE_SLIDE_IN;
        g_SelectReturn->mStateFrames = 0;
        SetSelectReturnPaletteBits(1);
    }
}

void AdvanceSelectReturnSlideIn(void) {
    SelectReturn *selectReturn;
    g_SelectReturn->mBg2Offset = LookupSelectReturnSlideInBg2Offset(g_SelectReturn->mStateFrames);
    g_SelectReturn->mStateFrames++;
    selectReturn = g_SelectReturn;
    if (selectReturn->mStateFrames >= SELECT_RETURN_SLIDE_STEPS) {
        selectReturn->mNextState = SELECT_RETURN_STATE_SHOWN;
        g_SelectReturn->mStateFrames = 0;
        g_SelectReturn->mSlideInRequested = FALSE;
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectReturnShown(void) {
    SelectReturn *selectReturn;
    selectReturn = g_SelectReturn;
    if (selectReturn->mPressRequested != FALSE) {
        selectReturn->mNextState = SELECT_RETURN_STATE_PRESS;
        SetSelectReturnPaletteBits(0);
        return;
    }
    if (selectReturn->mSlideOutRequested != FALSE) {
        selectReturn->mNextState = SELECT_RETURN_STATE_SLIDE_OUT;
    }
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectReturnPress(void) {
    SelectReturn *selectReturn;
    selectReturn = g_SelectReturn;
    selectReturn->mBg2Offset = gSelectReturnPressBg2Offsets[selectReturn->mStateFrames];
    g_SelectReturn->mStateFrames++;
    selectReturn = g_SelectReturn;
    if (selectReturn->mStateFrames >= SELECT_RETURN_PRESS_STEPS) {
        if (selectReturn->mSlideOutRequested != FALSE) {
            selectReturn->mNextState = SELECT_RETURN_STATE_SLIDE_OUT;
            SetSelectReturnPaletteBits(0);
        } else {
            selectReturn->mNextState = SELECT_RETURN_STATE_SHOWN;
            SetSelectReturnPaletteBits(1);
        }
        g_SelectReturn->mStateFrames = 0;
        g_SelectReturn->mPressRequested = FALSE;
    }
}

void AdvanceSelectReturnSlideOut(void) {
    SelectReturn *selectReturn;
    g_SelectReturn->mBg2Offset = LookupSelectReturnSlideOutBg2Offset(g_SelectReturn->mStateFrames);
    g_SelectReturn->mStateFrames++;
    selectReturn = g_SelectReturn;
    if (selectReturn->mStateFrames >= SELECT_RETURN_SLIDE_STEPS) {
        selectReturn->mNextState = SELECT_RETURN_STATE_HIDDEN;
        g_SelectReturn->mStateFrames = 0;
        g_SelectReturn->mSlideOutRequested = FALSE;
    }
}

void SelectReturnContext_OnSceneUpdate_from_thumb(void) {
    SelectReturn *selectReturn;
    selectReturn = g_SelectReturn;
    if (selectReturn->mEnabled != FALSE) {
        selectReturn->mState = selectReturn->mNextState;
        switch (g_SelectReturn->mState) {
            case SELECT_RETURN_STATE_HIDDEN:
                AdvanceSelectReturnHidden();
                break;
            case SELECT_RETURN_STATE_SLIDE_IN:
                AdvanceSelectReturnSlideIn();
                break;
            case SELECT_RETURN_STATE_SHOWN:
                AdvanceSelectReturnShown();
                break;
            case SELECT_RETURN_STATE_PRESS:
                AdvanceSelectReturnPress();
                break;
            case SELECT_RETURN_STATE_SLIDE_OUT:
                AdvanceSelectReturnSlideOut();
                break;
        }
    }
}

void SelectReturnContext_OnSceneVblank_from_thumb(void) {
    SelectReturn *selectReturn;
    u32 subDisplayBits;
    selectReturn = g_SelectReturn;
    if (selectReturn->mEnabled != FALSE) {
        if (selectReturn->mDisplayBitOn != FALSE) {
            if (((reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8 & 4) == 0) {
                subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
                reg_GXS_DB_DISPCNT =
                    (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits | 4) << 8);
            }
        } else {
            if (((reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8 & 4) != 0) {
                subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
                reg_GXS_DB_DISPCNT =
                    (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits & ~4) << 8);
            }
        }
        reg_G2S_DB_BG2OFS = (g_SelectReturn->mBg2Offset << 16) & 0x1ff0000;
    }
}

void RequestSelectReturnSlideIn(void) {
    if (IsSelectReturnShownNoRequest() != 0) {
        g_SelectReturn->mSlideInRequested = FALSE;
    } else {
        g_SelectReturn->mSlideInRequested = TRUE;
    }
    g_SelectReturn->mPressRequested = FALSE;
    g_SelectReturn->mSlideOutRequested = FALSE;
}

// requestSlideOut != 0 also asks for the slide out once the press ends.
void RequestSelectReturnPressWithSound(s32 requestSlideOut) {
    s32 soundId;
    g_SelectReturn->mSlideInRequested = FALSE;
    g_SelectReturn->mPressRequested = TRUE;
    if (requestSlideOut != 0) {
        g_SelectReturn->mSlideOutRequested = TRUE;
    } else {
        g_SelectReturn->mSlideOutRequested = FALSE;
    }
    soundId = g_SelectReturn->mSoundId;
    if (soundId != -1) {
        PlaySseqFromSarc(&gSharedSeqHandle, 0, (u16) soundId);
    }
}

void RequestSelectReturnSlideOut(void) {
    if (IsSelectReturnHiddenNoRequest() != 0) {
        g_SelectReturn->mSlideOutRequested = FALSE;
    } else {
        g_SelectReturn->mSlideOutRequested = TRUE;
    }
    g_SelectReturn->mSlideInRequested = FALSE;
    g_SelectReturn->mPressRequested = FALSE;
}

BOOL IsSelectReturnShownNoRequest(void) {
    BOOL result;
    BOOL shownNoSlideOutRequest;
    SelectReturn *selectReturn;
    result = FALSE;
    shownNoSlideOutRequest = FALSE;
    selectReturn = g_SelectReturn;
    if (selectReturn->mState == SELECT_RETURN_STATE_SHOWN && selectReturn->mSlideOutRequested == FALSE) {
        shownNoSlideOutRequest = TRUE;
    }
    if (shownNoSlideOutRequest != FALSE) {
        if (selectReturn->mPressRequested == FALSE) {
            result = TRUE;
        }
    }
    return result;
}

BOOL IsSelectReturnHiddenNoRequest(void) {
    BOOL result;
    SelectReturn *selectReturn;
    result = FALSE;
    selectReturn = g_SelectReturn;
    if (selectReturn->mState == SELECT_RETURN_STATE_HIDDEN && selectReturn->mSlideInRequested == FALSE) {
        result = TRUE;
    }
    return result;
}
#pragma thumb off

#pragma thumb on

int LookupSelectReturnSlideInBg2Offset(int frame) {
    if (frame < 0) {
        frame = 0;
    }
    if (10 <= frame) {
        frame = 9;
    }
    return gSelectReturnSlideInBg2Offsets[frame];
}

int LookupSelectReturnSlideOutBg2Offset(int frame) {
    if (frame < 0) {
        frame = 0;
    }
    if (10 <= frame) {
        frame = 9;
    }
    return gSelectReturnSlideOutBg2Offsets[frame];
}

#pragma thumb off

#pragma thumb on
BOOL IsSelectReturnShownNoRequestAndInRect(s32 pointX, s32 pointY) {
    if (IsSelectReturnShownNoRequest() != 0 && pointX >= 0 && pointX <= 0x28 && pointY >= 0x98 && pointY <= 0xc0) {
        return TRUE;
    }
    return FALSE;
}
#pragma thumb off

#pragma thumb on
void ClearSelectReturnDisplayBitOn(void) {
    g_SelectReturn->mDisplayBitOn = 0;
}
#pragma thumb off

#pragma thumb on
void SetSelectReturnDisplayBitOn(void) {
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        g_SelectReturn->mDisplayBitOn = TRUE;
    }
}
#pragma thumb off

#pragma thumb on
void SetSelectReturnSoundId(u32 soundId) {
    g_SelectReturn->mSoundId = soundId;
}
#pragma thumb off

#pragma thumb on
// Zeroes the char buffer gate; StartSelectChoises sets it after taking the strings.
void ClearSelectChoisesUseCharBuffers(void) {
    g_SelectChoisesContext->mUseCharBuffers = 0;
}
#pragma thumb off

#pragma thumb on
s32 SelectChoisesContext_Initialize_from_thumb(void *heap, void *font, s32 subCharOffset) {
    s32 canvasIndex;
    s32 charSpacing;
    NNSG2dCharCanvas *charCanvas;
    TextCanvas *textCanvas;
    u32 subDisplayBits;
    g_SelectChoisesContext = Mem_AllocateHeap(heap, sizeof(*g_SelectChoisesContext));
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        SelectChoisesContext_InitializeBg_from_thumb();
        subCharOffset = SelectChoisesContext_LoadGraphics_from_thumb(subCharOffset);
        g_SelectChoisesContext->mDisplayBitOn = 1;
    } else {
        g_SelectChoisesContext->mDisplayBitOn = 0;
        subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
        subDisplayBits &= ~1;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
    }
    for (canvasIndex = 0; canvasIndex < 2; canvasIndex++) {
        g_SelectChoisesContext->mCharBuffers[canvasIndex] = Mem_AllocateHeap(heap, SELECT_CHOISES_CHAR_BUFFER_BYTES);
        G2d_Sprite_CreateFromTiles(&g_SelectChoisesContext->mCharCanvases[canvasIndex],
                                   g_SelectChoisesContext->mCharBuffers[canvasIndex], 0x20, 2, 4);
        charCanvas = &g_SelectChoisesContext->mCharCanvases[canvasIndex];
        charCanvas->mPClear(charCanvas, 0);
        charSpacing = ComputeSomeInterCharacterWidth();
        textCanvas = &g_SelectChoisesContext->mTextCanvases[canvasIndex];
        textCanvas->mCharCanvas = &g_SelectChoisesContext->mCharCanvases[canvasIndex];
        textCanvas->mFont = font;
        textCanvas->mCharSpacing = charSpacing;
        textCanvas->mLineSpacing = 0;
    }
    ClearSelectChoisesUseCharBuffers();
    g_SelectChoisesContext->mEnabled = 1;
    g_SelectChoisesContext->mState = SELECT_CHOISES_STATE_HIDDEN;
    g_SelectChoisesContext->mNextState = SELECT_CHOISES_STATE_HIDDEN;
    g_SelectChoisesContext->mChosenFrames = 0;
    g_SelectChoisesContext->mToggleFrames = 0;
    g_SelectChoisesContext->mToggleOn = 1;
    g_SelectChoisesContext->mChooseRequested = 0;
    g_SelectChoisesContext->mHiddenRequested = 0;
    g_SelectChoisesContext->mDone = 0;
    g_SelectChoisesContext->mIndexNone = 0;
    g_SelectChoisesContext->mSoundIds[0] = SELECT_CHOISES_FIRST_SOUND_ID;
    g_SelectChoisesContext->mSoundIds[1] = SELECT_CHOISES_SECOND_SOUND_ID;
    g_SelectChoisesContext->mIndexNoneSoundId = SELECT_CHOISES_NONE_SOUND_ID;
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void SelectChoisesContext_Dispose_from_thumb(void) {
    g_SelectChoisesContext = NULL;
}
#pragma thumb off

#pragma thumb on
u32 SelectChoisesContext_InitializeBg_from_thumb(void) {
    u32 operandBits;
    u32 registerValue;
    u32 registerAddress;
    registerAddress = 0x4001008u;
    registerValue = *(const u16 *) ((registerAddress) + 0u);
    operandBits = 3u;
    registerValue = (registerValue) & ~(operandBits);
    *(u16 *) ((registerAddress) + 0u) = registerValue;
    registerValue = *(const u16 *) ((registerAddress) + 0u);
    operandBits = 67u;
    registerValue = (registerValue) & (operandBits);
    operandBits = 0xb00u;
    registerValue = (registerValue) | (operandBits);
    *(u16 *) ((registerAddress) + 0u) = registerValue;
    return operandBits;
}
#pragma thumb off

#pragma thumb on

s32 SelectChoisesContext_LoadGraphics_from_thumb(s32 subCharOffset) {
    Ncgr *chars;
    Nscr *screenMap;
    Nclr *palette;
    s32 firstTileIndex;
    s32 rowIndex;
    s32 columnIndex;
    s32 tileColumn;
    s32 tileRowOffset;
    const ByteRect *tileRect;

    MaybeReadCharBlock_1(&chars, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_choises_s_b.ncgr"));
    MaybeReadScreenBlock(&screenMap, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_choises_s_bg.nscr"));
    Gfx_ReadPaletteRelative(&palette, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_choises_s_b.nclr"));
    subCharOffset = subCharOffset - chars->mDataSize;
    firstTileIndex = subCharOffset >> 5;
    g_SelectChoisesContext->mFirstTileIndex = firstTileIndex;
    Arm_FlushRange(chars->mData, chars->mDataSize);
    CopyBgData_Bg0_Bottom(chars->mData, subCharOffset, chars->mDataSize);
    for (rowIndex = 0; rowIndex < 32; rowIndex++) {
        for (columnIndex = 0; columnIndex < 32; columnIndex++) {
            *(g_SelectChoisesContext->mNscrCopy + rowIndex * 32 + columnIndex) =
                firstTileIndex + *((u16 *) screenMap->mData + rowIndex * 32 + columnIndex);
        }
    }
    Arm_FlushRange(g_SelectChoisesContext->mNscrCopy, screenMap->mDataSize);
    TEQSub_Fn24Impl(g_SelectChoisesContext->mNscrCopy, 0, screenMap->mDataSize);
    tileRect = &gSelectChoisesTileRect;
    tileRowOffset = tileRect->mMinY * 32;
    tileColumn = tileRect->mMinX;
    g_SelectChoisesContext->mToggleOnFirstTile = g_SelectChoisesContext->mFirstTileIndex + (tileColumn + tileRowOffset);
    g_SelectChoisesContext->mToggleOffFirstTile = g_SelectChoisesContext->mFirstTileIndex + (tileRowOffset + (tileColumn + 3));
    Arm_FlushRange(palette->mData, 0x1c0);
    CopyPaletteBottom(palette->mData + 0xe0, 0x1c0, 0x40);
    return subCharOffset;
}

void RefreshSelectChoisesNscrCopy(void) {
    s32 column;
    s32 choiceIndex;
    s32 row;
    BOOL useToggleOnTiles;
    const ByteRect *tileRect;
    s32 lastColumn;
    s32 tileIndex;
    const u8(*origin)[2];
    s32 lastRow;
    s32 screenMapIndex;

    choiceIndex = 0;
    origin = gSelectChoisesNscrOrigins;
    tileRect = &gSelectChoisesTileRect;
    lastColumn = tileRect->mMaxX - tileRect->mMinX;
    lastRow = tileRect->mMaxY - tileRect->mMinY;
    for (; choiceIndex < 2; choiceIndex++) {
        useToggleOnTiles = FALSE;
        if (choiceIndex == g_SelectChoisesContext->mIndex && g_SelectChoisesContext->mToggleOn != 0) {
            useToggleOnTiles = TRUE;
        }
        for (row = 0; row <= lastRow; row++) {
            for (column = 0; column <= lastColumn; column++) {
                screenMapIndex = column + (*origin)[0] + ((row + (*origin)[1]) << 5);
                tileIndex = row * 32 + (g_SelectChoisesContext->mToggleOffFirstTile + column);
                if (useToggleOnTiles != FALSE) {
                    tileIndex = row * 32 + (g_SelectChoisesContext->mToggleOnFirstTile + column);
                }
                if (useToggleOnTiles != FALSE) {
                    g_SelectChoisesContext->mNscrCopy[screenMapIndex] =
                        tileIndex + ((g_SelectChoisesContext->mNscrCopy[screenMapIndex] & 0xffff0c00) + 0xe000);
                } else {
                    g_SelectChoisesContext->mNscrCopy[screenMapIndex] =
                        tileIndex + (g_SelectChoisesContext->mNscrCopy[screenMapIndex] & 0xfffffc00);
                }
            }
        }
        origin++;
    }
}

void RefreshSelectChoisesPaletteBits(void) {
    s32 choiceIndex;
    s32 row;
    s32 column;
    s32 topNibble;
    s32 entry;

    for (choiceIndex = 0; choiceIndex < 2; choiceIndex++) {
        topNibble = 0xe;
        if (g_SelectChoisesContext->mIndex != choiceIndex) {
            topNibble = 0xf;
        }
        for (row = gSelectChoisesPaletteRects[choiceIndex].mMinY; row <= gSelectChoisesPaletteRects[choiceIndex].mMaxY;
             row++) {
            for (column = gSelectChoisesPaletteRects[choiceIndex].mMinX;
                 column <= gSelectChoisesPaletteRects[choiceIndex].mMaxX; column++) {
                entry = g_SelectChoisesContext->mNscrCopy[row * 32 + column];
                entry &= 0xffff0fff;
                entry += TO_FIXED12(topNibble);
                g_SelectChoisesContext->mNscrCopy[row * 32 + column] = entry;
            }
        }
    }
}

void SelectChoisesContext_UpdateGraphics_from_thumb(void) {
    g_SelectChoisesContext->mToggleFrames = 0;
    g_SelectChoisesContext->mToggleOn = 1;
    RefreshSelectChoisesPaletteBits();
    RefreshSelectChoisesNscrCopy();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_MAP, 0, g_SelectChoisesContext->mNscrCopy, 0x800);
    }
}

void RefreshSelectChoisesPaletteNoIndex(void) {
    s32 savedIndex;

    savedIndex = g_SelectChoisesContext->mIndex;
    g_SelectChoisesContext->mIndex = -1;
    RefreshSelectChoisesPaletteBits();
    g_SelectChoisesContext->mIndex = savedIndex;
    g_SelectChoisesContext->mToggleFrames = 0;
    g_SelectChoisesContext->mToggleOn = 1;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_MAP, 0, g_SelectChoisesContext->mNscrCopy, 0x800);
    }
}

void SelectChoisesContext_UpdateFn_State0_from_thumb(void) {
    s32 choiceIndex;
    s32 partIndex;
    s32 tileOffset;

    if (g_SelectChoisesContext->mChooseRequested != 0) {
        SelectChoisesContext_UpdateGraphics_from_thumb();
        g_SelectChoisesContext->mNextState = SELECT_CHOISES_STATE_CHOOSE;
        choiceIndex = 0;
        g_SelectChoisesContext->mChooseRequested = choiceIndex;
        g_SelectChoisesContext->mChosenFrames = choiceIndex;
        g_SelectChoisesContext->mIndexNone = choiceIndex;
        if (g_SelectChoisesContext->mUseCharBuffers != 0) {
            for (choiceIndex = 0; choiceIndex < 2; choiceIndex++) {
                for (partIndex = 0; partIndex < 2; partIndex++) {
                    tileOffset = (partIndex + choiceIndex * 2) * 32 + 5;
                    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                        AllocateReserveTEQSub(
                            0x14, (g_SelectChoisesContext->mFirstTileIndex + tileOffset) << 5,
                            g_SelectChoisesContext->mCharBuffers[choiceIndex] + ((partIndex * 32 + 5) << 5), 0x360);
                    }
                }
            }
        }
    }
}

static inline BOOL SelectChoisesIsPointInByteRect(u16 pointX, u16 pointY, u8 minX, u8 maxX, u8 minY, u8 maxY) {
    if (pointX >= minX && pointX <= maxX && pointY >= minY && pointY <= maxY) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 SelectChoisesIsPairNewUnlessLost(u32 inputSlotIndex) {
    BOOL result = FALSE;
    BOOL recentlyLost = FALSE;
    u16 hasPair = g_GlobalCYT[inputSlotIndex].mPair.mHasPair;

    if (hasPair == 0 && g_GlobalCYT[inputSlotIndex].mPair.mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && g_GlobalCYT[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        result = TRUE;
    }
    return result;
}

void SelectChoisesContext_UpdateFn_State1_from_thumb(void) {
    s32 hit;
    u16 touchX;
    u16 touchY;
    InputSlotIndex inputSlotIndex;
    u16 keys;

    inputSlotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    touchX = g_GlobalCYT[inputSlotIndex].mPair.mPairX;
    touchY = g_GlobalCYT[inputSlotIndex].mPair.mPairY;
    if (g_SelectChoisesContext->mHiddenRequested != 0) {
        g_SelectChoisesContext->mNextState = SELECT_CHOISES_STATE_HIDDEN;
        g_SelectChoisesContext->mHiddenRequested = 0;
        return;
    }
    hit = -1;
    if (SelectChoisesIsPairNewUnlessLost(inputSlotIndex) != 0) {
        if (SelectChoisesIsPointInByteRect(touchX, touchY, gSelectChoisesHitRects[0].mMinX,
                                           gSelectChoisesHitRects[0].mMaxX, gSelectChoisesHitRects[0].mMinY,
                                           gSelectChoisesHitRects[0].mMaxY) != FALSE) {
            hit = 0;
        }
        if (SelectChoisesIsPointInByteRect(touchX, touchY, gSelectChoisesHitRects[1].mMinX,
                                           gSelectChoisesHitRects[1].mMaxX, gSelectChoisesHitRects[1].mMinY,
                                           gSelectChoisesHitRects[1].mMaxY) != FALSE) {
            hit = 1;
        }
    }
    keys = g_GlobalCYT[inputSlotIndex].mPressedBits;
    if ((u16) (keys & PAD_KEY_A) != 0 || hit != -1) {
        if (hit == -1 || g_SelectChoisesContext->mIndex == hit) {
            RefreshSelectChoisesPaletteNoIndex();
        } else {
            g_SelectChoisesContext->mIndex = hit;
            SelectChoisesContext_UpdateGraphics_from_thumb();
        }
        g_SelectChoisesContext->mNextState = SELECT_CHOISES_STATE_CHOSEN;
        if (g_SelectChoisesContext->mDisplayBitOn != 0) {
            if (g_SelectChoisesContext->mSoundIds[g_SelectChoisesContext->mIndex] != -1) {
                MaybePlaySomeSseqFromSarc0((u16) g_SelectChoisesContext->mSoundIds[g_SelectChoisesContext->mIndex]);
            }
        }
    } else {
        if ((u16) (keys & PAD_KEY_B) != 0) {
            g_SelectChoisesContext->mIndexNone = 1;
            g_SelectChoisesContext->mChosenFrames = SELECT_CHOISES_RETURN_START_FRAME;
            g_SelectChoisesContext->mNextState = SELECT_CHOISES_STATE_CHOSEN;
            if (g_SelectChoisesContext->mDisplayBitOn != 0) {
                if (g_SelectChoisesContext->mIndexNoneSoundId != -1) {
                    MaybePlaySomeSseqFromSarc0((u16) g_SelectChoisesContext->mIndexNoneSoundId);
                }
            }
            return;
        }
        if ((u16) (keys & PAD_KEY_UP) != 0 && g_SelectChoisesContext->mIndex == 1) {
            g_SelectChoisesContext->mIndex = 0;
            SelectChoisesContext_UpdateGraphics_from_thumb();
            if (g_SelectChoisesContext->mDisplayBitOn != 0) {
                MaybePlaySomeSseqFromSarc0(0);
            }
            return;
        }
        if ((u16) (keys & PAD_KEY_DOWN) != 0 && g_SelectChoisesContext->mIndex == 0) {
            g_SelectChoisesContext->mIndex = 1;
            SelectChoisesContext_UpdateGraphics_from_thumb();
            if (g_SelectChoisesContext->mDisplayBitOn != 0) {
                MaybePlaySomeSseqFromSarc0(0);
            }
        }
    }
}
#pragma thumb off

#pragma thumb on

void SelectChoisesContext_UpdateFn_State2_from_thumb(void) {
    SelectChoises *selectChoises;
    int stateFrames;
    selectChoises = g_SelectChoisesContext;
    if (selectChoises->mHiddenRequested != 0) {
        selectChoises->mNextState = SELECT_CHOISES_STATE_HIDDEN;
        g_SelectChoisesContext->mHiddenRequested = 0;
        return;
    }
    selectChoises->mChosenFrames = selectChoises->mChosenFrames + 1;
    stateFrames = g_SelectChoisesContext->mChosenFrames;
    if (SELECT_CHOISES_CHOSEN_FRAMES <= stateFrames) {
        g_SelectChoisesContext->mDone = 1;
        g_SelectChoisesContext->mChosenFrames = SELECT_CHOISES_CHOSEN_FRAMES;
        return;
    }
    if (5 <= stateFrames) {
        SelectChoisesContext_UpdateGraphics_from_thumb();
    }
}

#pragma thumb off

#pragma thumb on

void SelectChoisesContext_OnSceneUpdate_from_thumb(void) {
    if (g_SelectChoisesContext->mEnabled != 0) {
        g_SelectChoisesContext->mState = g_SelectChoisesContext->mNextState;
        switch (g_SelectChoisesContext->mState) {
            case SELECT_CHOISES_STATE_HIDDEN:
                SelectChoisesContext_UpdateFn_State0_from_thumb();
                break;
            case SELECT_CHOISES_STATE_CHOOSE:
                SelectChoisesContext_UpdateFn_State1_from_thumb();
                break;
            case SELECT_CHOISES_STATE_CHOSEN:
                SelectChoisesContext_UpdateFn_State2_from_thumb();
                break;
        }
        g_SelectChoisesContext->mToggleFrames++;
        if ((g_SelectChoisesContext->mToggleOn != 0 && g_SelectChoisesContext->mToggleFrames > SELECT_CHOISES_TOGGLE_ON_FRAMES) ||
            (g_SelectChoisesContext->mToggleOn == 0 && g_SelectChoisesContext->mToggleFrames > SELECT_CHOISES_TOGGLE_OFF_FRAMES)) {
            g_SelectChoisesContext->mToggleOn = g_SelectChoisesContext->mToggleOn == 0;
            g_SelectChoisesContext->mToggleFrames = 0;
            RefreshSelectChoisesNscrCopy();
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_MAP, 0, g_SelectChoisesContext->mNscrCopy, 0x800);
            }
        }
    }
}

void SelectChoisesContext_OnSceneVblank_from_thumb(void) {
    u32 subDisplayBits;

    if (g_SelectChoisesContext->mEnabled != 0) {
        reg_G2S_DB_BG0OFS = 0;
        if (g_SelectChoisesContext->mState == SELECT_CHOISES_STATE_HIDDEN || g_SelectChoisesContext->mDisplayBitOn == 0) {
            UpdateBldcntBldalphaBldy(&reg_G2S_DB_BLDCNT, 0x1e, 0x1f, 6, 10, 0);
            subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits & ~1) << 8);
        } else {
            UpdateBldcntBldalphaBldy(&reg_G2S_DB_BLDCNT, 0x1e, 0x1f, 6, 10, -10);
            subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits | 1) << 8);
        }
    }
}

void RequestSelectChoisesChoose(void) {
    if ((g_SelectChoisesContext->mState == SELECT_CHOISES_STATE_HIDDEN && g_SelectChoisesContext->mChooseRequested != 0) ||
        g_SelectChoisesContext->mState == SELECT_CHOISES_STATE_CHOOSE) {
        g_SelectChoisesContext->mHiddenRequested = 1;
    } else {
        g_SelectChoisesContext->mHiddenRequested = 0;
    }
    g_SelectChoisesContext->mChooseRequested = 1;
}

void StartSelectChoises(void *firstText, void *secondText, s32 startOnSecond) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &g_SelectChoisesContext->mCharCanvases[0];
    charCanvas->mPClear(charCanvas, 5);
    charCanvas = &g_SelectChoisesContext->mCharCanvases[1];
    charCanvas->mPClear(charCanvas, 5);
    G2d_Text_SomeFn_from_thumb(&g_SelectChoisesContext->mTextCanvases[0], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, firstText);
    G2d_Text_SomeFn_from_thumb(&g_SelectChoisesContext->mTextCanvases[1], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, secondText);
    ClearSelectChoisesUseCharBuffers();
    g_SelectChoisesContext->mUseCharBuffers = 1;
    RequestSelectChoisesChoose();
    if (startOnSecond == 0) {
        g_SelectChoisesContext->mIndex = 0;
    } else {
        g_SelectChoisesContext->mIndex = 1;
    }
    SelectChoisesContext_UpdateGraphics_from_thumb();
    g_SelectChoisesContext->mDone = 0;
    g_SelectChoisesContext->mToggleFrames = 0;
    g_SelectChoisesContext->mToggleOn = 1;
}

void RequestSelectChoisesHidden(void) {
    g_SelectChoisesContext->mChooseRequested = 0;
    g_SelectChoisesContext->mHiddenRequested = 1;
}

BOOL IsSelectChoisesChooseNoRequest(void) {
    u32 result;

    result = 0;
    if (g_SelectChoisesContext->mState == SELECT_CHOISES_STATE_CHOOSE && g_SelectChoisesContext->mHiddenRequested == 0) {
        result = 1;
    }
    return result;
}

BOOL IsSelectChoisesHiddenNoRequest(void) {
    BOOL result;

    result = FALSE;
    if (g_SelectChoisesContext->mState == SELECT_CHOISES_STATE_HIDDEN && g_SelectChoisesContext->mChooseRequested == 0) {
        result = TRUE;
    }
    return result;
}
#pragma thumb off

#pragma thumb on

s32 GetSelectChoisesIndex(void) {
    if (g_SelectChoisesContext->mIndexNone != 0) {
        return 0xffffffff;
    }
    return g_SelectChoisesContext->mIndex;
}

u32 GetSelectChoisesDone(void) {
    return g_SelectChoisesContext->mDone;
}

void SetSelectChoisesSoundId(int choiceIndex, u32 soundId) {
    if (choiceIndex == -1) {
        g_SelectChoisesContext->mIndexNoneSoundId = soundId;
        return;
    }
    g_SelectChoisesContext->mSoundIds[choiceIndex] = soundId;
}

#pragma thumb off
