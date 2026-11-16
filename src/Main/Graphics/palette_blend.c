#include "Main/Graphics/palette_blend.h"

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
#include "char_canvas_text_draw.h"
#include "bg_screen_char_pointers.h"
#include "vram_transfer_queue.h"
#include "cpu_copy_fill.h"
#include "Main/System/heap.h"
#include "Main/System/stdio_files.h"
#include "print_memory_multibyte_write.h"
#include "capture_output_effect.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "registers.h"

PaletteBlend *gPaletteBlend;
StaffRollText *g_GlobalSTF;

#pragma thumb on
void InitPaletteBlend(void *heap, Nclr *nclr, u32 paletteIndex) {
    s32 colorIndex;
    s32 color;
    gPaletteBlend = Mem_AllocateHeap(heap, sizeof(*gPaletteBlend));
    gPaletteBlend->mCycleFrames = 0;
    gPaletteBlend->mStopped = FALSE;
    gPaletteBlend->mPaletteIndex = paletteIndex;
    gPaletteBlend->mFirstBlend = TRUE;
    Mem_CpuCopy8(nclr->mData + paletteIndex * 0x10, gPaletteBlend->mPalette, 0x20);
    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
        color = gPaletteBlend->mFromColors[colorIndex];
        gPaletteBlend->mBlendFrom[colorIndex].mBits0To4 = color & 0x1f;
        gPaletteBlend->mBlendFrom[colorIndex].mBits5To9 = (color & 0x3e0) >> 5;
        gPaletteBlend->mBlendFrom[colorIndex].mBits10To14 = (color & 0x7c00) >> 10;
    }
    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
        color = gPaletteBlend->mToColors[colorIndex];
        gPaletteBlend->mBlendTo[colorIndex].mBits0To4 = color & 0x1f;
        gPaletteBlend->mBlendTo[colorIndex].mBits5To9 = (color & 0x3e0) >> 5;
        gPaletteBlend->mBlendTo[colorIndex].mBits10To14 = (color & 0x7c00) >> 10;
    }
}
#pragma thumb off

#pragma thumb on
void ClearPaletteBlendPointer(void) {
    gPaletteBlend = NULL;
}
#pragma thumb off

#pragma thumb on
void BlendPaletteColors(s32 weight) {
    s32 colorIndex;
    PaletteBlend *paletteBlend;
    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
        paletteBlend = gPaletteBlend;
        (&paletteBlend->mPalette[1])[colorIndex] =
            ((((0x1000 - weight) * paletteBlend->mBlendFrom[colorIndex].mBits10To14 +
               weight * paletteBlend->mBlendTo[colorIndex].mBits10To14) >>
              12)
             << 10) |
            ((((0x1000 - weight) * paletteBlend->mBlendFrom[colorIndex].mBits0To4 +
               weight * paletteBlend->mBlendTo[colorIndex].mBits0To4) >>
              12) |
             ((((0x1000 - weight) * paletteBlend->mBlendFrom[colorIndex].mBits5To9 +
                weight * paletteBlend->mBlendTo[colorIndex].mBits5To9) >>
               12)
              << 5));
    }
    if (gPaletteBlend->mFirstBlend == FALSE) {
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, gPaletteBlend->mPaletteIndex << 5,
                                           gPaletteBlend->mPalette, 0x20);
    } else {
        gPaletteBlend->mFirstBlend = FALSE;
    }
}

void AdvancePaletteBlend(void) {
    s32 cycleFrames;
    if (gPaletteBlend->mStopped == FALSE) {
        gPaletteBlend->mCycleFrames++;
        if (gPaletteBlend->mCycleFrames >= PALETTE_BLEND_CYCLE_FRAMES) {
            gPaletteBlend->mCycleFrames = 0;
        }
    }
    cycleFrames = gPaletteBlend->mCycleFrames;
    if (cycleFrames < 0x1e) {
        BlendPaletteColors(TO_FIXED12(0x1e - cycleFrames) / 0x1e);
    } else if (cycleFrames < 0x3c) {
        BlendPaletteColors(0);
    } else {
        BlendPaletteColors(TO_FIXED12(cycleFrames - 0x3c) / 0x1e);
    }
}

void ResetPaletteBlendCycle(void) {
    gPaletteBlend->mCycleFrames = 0;
}

void StopPaletteBlend(void) {
    gPaletteBlend->mCycleFrames = 0;
    gPaletteBlend->mStopped = TRUE;
}

void StartPaletteBlend(void) {
    gPaletteBlend->mStopped = FALSE;
}
#pragma thumb off

// Entries of the VRAM transfer task array that the staff roll text sets up.
#define STAFF_ROLL_VRAM_TASK_COUNT 0xa

void LoadStaffRollStuff(void *heap) {
    s32 screenEntryIndex;
    s32 charSpacing;
    Nclr *nclr;
    StaffRollText *staffRollText;
    TextCanvas *textCanvas;
    void *font;
    g_GlobalSTF = Mem_AllocateHeap(heap, sizeof(*g_GlobalSTF));
    g_GlobalSTF->mHeap = heap;
    g_GlobalSTF->mState = STAFF_ROLL_TEXT_IDLE;
    g_GlobalSTF->mNextState = STAFF_ROLL_TEXT_IDLE;
    InitializeGlobalTEQ(Mem_AllocateHeap(heap, STAFF_ROLL_VRAM_TASK_COUNT * sizeof(NNSGfdVramTransferTask)),
                                   STAFF_ROLL_VRAM_TASK_COUNT);
    g_GlobalSTF->mScrollYFixed = 0;
    g_GlobalSTF->mNextReadScrollY = 0;
    g_GlobalSTF->mScrollYRemaining = -1;
    g_GlobalSTF->mScrollYPerFrame = STAFF_ROLL_SCROLL_Y_PER_FRAME_DEFAULT;
    g_GlobalSTF->mCharSpacing = 1;
    g_GlobalSTF->mTextColor = 1;
    g_GlobalSTF->mAlignFlags = TEXT_CANVAS_FLAG_TOP | TEXT_CANVAS_FLAG_LEFT;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x100;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2S_DB_BG0CNT =
        (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0x1000;
    MemFillWordsByBlock_inline((void *) GetVramBg0BaseOffset_Bottom(), 0x8000);
    for (screenEntryIndex = 0; screenEntryIndex < 0x400; screenEntryIndex++) {
        ((u16 *) GetAnotherSubEngineBGOffset())[screenEntryIndex] = screenEntryIndex | 0xf000;
    }
    Gfx_ReadPalette(&nclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ending_staffRoll_b_00.nclr"));
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE, 0x1e0, nclr->mData + 0xf0, 0x20);
    G2d_Sprite_CreateFromTiles(g_GlobalSTF->mCharCanvas, g_GlobalSTF->mCharBuffer, 0x20, 2, 4);
    charSpacing = g_GlobalSTF->mCharSpacing;
    font = GetLoadedFont_from_thumb(2);
    staffRollText = g_GlobalSTF;
    textCanvas = &staffRollText->mTextCanvas;
    staffRollText->mTextCanvas.mCharCanvas = staffRollText->mCharCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = 0;
    Mem_CpuFill8(g_GlobalSTF->mCharBuffer, 0, sizeof(g_GlobalSTF->mCharBuffer));
    g_GlobalSTF->mTextPosition = Bmg_GetRawStringPointer_from_thumb(FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("staffRoll.bmg"), 0);
}

void ResetStaffRollStuffObject(void) {
    g_GlobalSTF = NULL;
}

void FormatSomeStaffRollBmgString(void) {
    s32 tagSize;
    s32 value;
    s32 charCount;
    u8 *textPosition;
    StaffRollText *staffRollText;
    u16 lineText[100];
    s32 color;
    BOOL lineDone;
    s32 variant;
    s32 argument;
    u32 character;
    s32 bgPositionY;
    StaffRollTag *tag;
    g_GlobalSTF->mScrollYFixed += g_GlobalSTF->mScrollYPerFrame;
    bgPositionY = FROM_FIXED12(g_GlobalSTF->mScrollYFixed) - 8;
    if (bgPositionY < 0) {
        bgPositionY += 0x100;
    }
    bgPositionY = bgPositionY % 256;
    MemFillWordsByBlock_inline((void *) (GetVramBg0BaseOffset_Bottom() + ((bgPositionY >> 3) << 10)), 0x400);
    staffRollText = g_GlobalSTF;
    if (staffRollText->mScrollYRemaining > 0) {
        staffRollText->mScrollYRemaining -= staffRollText->mScrollYPerFrame;
        if (g_GlobalSTF->mScrollYRemaining <= 0) {
            g_GlobalSTF->mNextState = STAFF_ROLL_TEXT_SCROLL_DONE;
        }
        return;
    }
    if (staffRollText->mScrollYFixed <= staffRollText->mNextReadScrollY) {
        return;
    }
    charCount = 0;
    lineDone = FALSE;
    Mem_CpuFill8(lineText, 0, sizeof(lineText));
    do {
        staffRollText = g_GlobalSTF;
        textPosition = staffRollText->mTextPosition;
        tag = (StaffRollTag *) textPosition;
        character = tag->mCharacter;
        if (character == 0x1a) {
            value = tag->mKind;
            tagSize = tag->mSize;
            variant = tag->mVariant;
            if (value == 1) {
                argument = 0;
                if (variant != 0x63) {
                    argument = tag->mArgument;
                }
                switch (variant) {
                    case STAFF_ROLL_TAG_ALIGN:
                        staffRollText->mAlignFlags = TEXT_CANVAS_FLAG_TOP;
                        switch (argument) {
                            case STAFF_ROLL_ALIGN_LEFT:
                                g_GlobalSTF->mAlignFlags |= TEXT_CANVAS_FLAG_LEFT;
                                break;
                            case STAFF_ROLL_ALIGN_CENTER:
                                g_GlobalSTF->mAlignFlags |= TEXT_CANVAS_FLAG_CENTER;
                                break;
                            case STAFF_ROLL_ALIGN_RIGHT:
                                g_GlobalSTF->mAlignFlags |= TEXT_CANVAS_FLAG_RIGHT;
                                break;
                        }
                        break;
                    case STAFF_ROLL_TAG_SKIP_LINES:
                        lineDone = TRUE;
                        staffRollText->mNextReadScrollY += argument << 16;
                        break;
                    case STAFF_ROLL_TAG_COLOR:
                        staffRollText->mTextColor = argument * 2 + 1;
                        break;
                    case STAFF_ROLL_TAG_CHAR_SPACING:
                        staffRollText->mCharSpacing = argument;
                        break;
                    case STAFF_ROLL_TAG_SCROLL_SPEED:
                        staffRollText->mScrollYPerFrame = TO_FIXED12(argument) / 100;
                        break;
                    case STAFF_ROLL_TAG_NO_EFFECT:
                        break;
                    case STAFF_ROLL_TAG_END:
                        lineDone = TRUE;
                        staffRollText->mScrollYRemaining = STAFF_ROLL_END_SCROLL_Y;
                        break;
                }
            }
            g_GlobalSTF->mTextPosition += tagSize;
        } else if (character == 0xa) {
            lineDone = TRUE;
            staffRollText->mNextReadScrollY += 0x10000;
            g_GlobalSTF->mTextPosition += 2;
        } else if (character == 0) {
            staffRollText->mTextPosition = textPosition + 2;
        } else {
            lineText[charCount] = character;
            charCount++;
            staffRollText->mTextPosition += 2;
        }
    } while (lineDone == FALSE);
    Mem_CpuFill8(g_GlobalSTF->mCharBuffer, 0, sizeof(g_GlobalSTF->mCharBuffer));
    color = g_GlobalSTF->mTextColor;
    value = 0;
    if (color == 3) {
        value = 2;
    }
    G2d_Text_PrintString4(&g_GlobalSTF->mTextCanvas, 8, value, 0xf0, 0x10, color,
                                   g_GlobalSTF->mAlignFlags, lineText);
    staffRollText = g_GlobalSTF;
    bgPositionY = ((FROM_FIXED12(staffRollText->mScrollYFixed) % 256) + 0xc0) >> 3;
    bgPositionY = bgPositionY << 3;
    if (bgPositionY >= 0x100) {
        bgPositionY -= 0x100;
    }
    if (bgPositionY + 0x10 > 0x100) {
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_TILES, bgPositionY << 7, staffRollText->mCharBuffer,
                                           (0x100 - bgPositionY) << 7);
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_TILES, 0,
                                           &g_GlobalSTF->mCharBuffer[bgPositionY << 7], (bgPositionY - 0xf0) << 7);
    } else {
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_TILES, bgPositionY << 7, staffRollText->mCharBuffer,
                                           0x800);
    }
}

void AdvanceStaffRollText(void) {
    g_GlobalSTF->mState = g_GlobalSTF->mNextState;
    switch (g_GlobalSTF->mState) {
        case STAFF_ROLL_TEXT_IDLE:
            break;
        case STAFF_ROLL_TEXT_SCROLLING:
            FormatSomeStaffRollBmgString();
            break;
        case STAFF_ROLL_TEXT_SCROLL_DONE:
            break;
    }
}

void SetStaffRollScrollAndDrainQueue(void) {
    reg_G2S_DB_BG0OFS = ((FROM_FIXED12(g_GlobalSTF->mScrollYFixed) % 256) << 16) & 0x1ff0000;
    HandleAllGlobalTEQSubs();
}

void RunWhenStaffRollCount(void) {
    g_GlobalSTF->mNextState = STAFF_ROLL_TEXT_SCROLLING;
}
