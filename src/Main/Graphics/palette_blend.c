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
#include "print_memory_functions.h"
#include "capture_output_effect.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "registers.h"

PaletteBlend *gPaletteBlend;
StaffRollText *gStaffRollText;

#pragma thumb on
void InitPaletteBlend(void *heap, Nclr *nclr, u32 paletteIndex) {
    s32 colorIndex;
    s32 color;
    gPaletteBlend = HeapAlloc(heap, sizeof(*gPaletteBlend));
    gPaletteBlend->mCycleFrames = 0;
    gPaletteBlend->mStopped = FALSE;
    gPaletteBlend->mPaletteIndex = paletteIndex;
    gPaletteBlend->mFirstBlend = TRUE;
    MI_CpuCopy8(nclr->mData + paletteIndex * 0x10, gPaletteBlend->mPalette, 0x20);
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
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, gPaletteBlend->mPaletteIndex << 5,
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

void InitStaffRollText(void *heap) {
    s32 screenEntryIndex;
    s32 charSpacing;
    Nclr *nclr;
    StaffRollText *staffRollText;
    TextCanvas *textCanvas;
    void *font;
    gStaffRollText = HeapAlloc(heap, sizeof(*gStaffRollText));
    gStaffRollText->mHeap = heap;
    gStaffRollText->mState = STAFF_ROLL_TEXT_IDLE;
    gStaffRollText->mNextState = STAFF_ROLL_TEXT_IDLE;
    NNS_GfdInitVramTransferManager(HeapAlloc(heap, STAFF_ROLL_VRAM_TASK_COUNT * sizeof(NNSGfdVramTransferTask)),
                                   STAFF_ROLL_VRAM_TASK_COUNT);
    gStaffRollText->mScrollYFixed = 0;
    gStaffRollText->mNextReadScrollY = 0;
    gStaffRollText->mScrollYRemaining = -1;
    gStaffRollText->mScrollYPerFrame = STAFF_ROLL_SCROLL_Y_PER_FRAME_DEFAULT;
    gStaffRollText->mCharSpacing = 1;
    gStaffRollText->mTextColor = 1;
    gStaffRollText->mAlignFlags = TEXT_CANVAS_FLAG_TOP | TEXT_CANVAS_FLAG_LEFT;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x100;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2S_DB_BG0CNT =
        (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0x1000;
    MemFillWordsByBlock_inline((void *) G2S_GetBG0CharPtr(), 0x8000);
    for (screenEntryIndex = 0; screenEntryIndex < 0x400; screenEntryIndex++) {
        ((u16 *) G2S_GetBG0ScrPtr())[screenEntryIndex] = screenEntryIndex | 0xf000;
    }
    LoadNclrData(&nclr, FindSceneFile("ending_staffRoll_b_00.nclr"));
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG_PALETTE, 0x1e0, nclr->mData + 0xf0, 0x20);
    NNS_G2dCharCanvasInitForBG(gStaffRollText->mCharCanvas, gStaffRollText->mCharBuffer, 0x20, 2, 4);
    charSpacing = gStaffRollText->mCharSpacing;
    font = GetFontByIndex(2);
    staffRollText = gStaffRollText;
    textCanvas = &staffRollText->mTextCanvas;
    staffRollText->mTextCanvas.mCharCanvas = staffRollText->mCharCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = 0;
    MI_CpuFill8(gStaffRollText->mCharBuffer, 0, sizeof(gStaffRollText->mCharBuffer));
    gStaffRollText->mTextPosition = GetBmgEntry(FindSceneFile("staffRoll.bmg"), 0);
}

void ClearStaffRollTextPointer(void) {
    gStaffRollText = NULL;
}

void AdvanceStaffRollTextScrolling(void) {
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
    gStaffRollText->mScrollYFixed += gStaffRollText->mScrollYPerFrame;
    bgPositionY = FROM_FIXED12(gStaffRollText->mScrollYFixed) - 8;
    if (bgPositionY < 0) {
        bgPositionY += 0x100;
    }
    bgPositionY = bgPositionY % 256;
    MemFillWordsByBlock_inline((void *) (G2S_GetBG0CharPtr() + ((bgPositionY >> 3) << 10)), 0x400);
    staffRollText = gStaffRollText;
    if (staffRollText->mScrollYRemaining > 0) {
        staffRollText->mScrollYRemaining -= staffRollText->mScrollYPerFrame;
        if (gStaffRollText->mScrollYRemaining <= 0) {
            gStaffRollText->mNextState = STAFF_ROLL_TEXT_SCROLL_DONE;
        }
        return;
    }
    if (staffRollText->mScrollYFixed <= staffRollText->mNextReadScrollY) {
        return;
    }
    charCount = 0;
    lineDone = FALSE;
    MI_CpuFill8(lineText, 0, sizeof(lineText));
    do {
        staffRollText = gStaffRollText;
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
                                gStaffRollText->mAlignFlags |= TEXT_CANVAS_FLAG_LEFT;
                                break;
                            case STAFF_ROLL_ALIGN_CENTER:
                                gStaffRollText->mAlignFlags |= TEXT_CANVAS_FLAG_CENTER;
                                break;
                            case STAFF_ROLL_ALIGN_RIGHT:
                                gStaffRollText->mAlignFlags |= TEXT_CANVAS_FLAG_RIGHT;
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
            gStaffRollText->mTextPosition += tagSize;
        } else if (character == 0xa) {
            lineDone = TRUE;
            staffRollText->mNextReadScrollY += 0x10000;
            gStaffRollText->mTextPosition += 2;
        } else if (character == 0) {
            staffRollText->mTextPosition = textPosition + 2;
        } else {
            lineText[charCount] = character;
            charCount++;
            staffRollText->mTextPosition += 2;
        }
    } while (lineDone == FALSE);
    MI_CpuFill8(gStaffRollText->mCharBuffer, 0, sizeof(gStaffRollText->mCharBuffer));
    color = gStaffRollText->mTextColor;
    value = 0;
    if (color == 3) {
        value = 2;
    }
    NNSi_G2dTextCanvasDrawTextRect(&gStaffRollText->mTextCanvas, 8, value, 0xf0, 0x10, color,
                                   gStaffRollText->mAlignFlags, lineText);
    staffRollText = gStaffRollText;
    bgPositionY = ((FROM_FIXED12(staffRollText->mScrollYFixed) % 256) + 0xc0) >> 3;
    bgPositionY = bgPositionY << 3;
    if (bgPositionY >= 0x100) {
        bgPositionY -= 0x100;
    }
    if (bgPositionY + 0x10 > 0x100) {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG0_TILES, bgPositionY << 7, staffRollText->mCharBuffer,
                                           (0x100 - bgPositionY) << 7);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG0_TILES, 0,
                                           &gStaffRollText->mCharBuffer[bgPositionY << 7], (bgPositionY - 0xf0) << 7);
    } else {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG0_TILES, bgPositionY << 7, staffRollText->mCharBuffer,
                                           0x800);
    }
}

void AdvanceStaffRollText(void) {
    gStaffRollText->mState = gStaffRollText->mNextState;
    switch (gStaffRollText->mState) {
        case STAFF_ROLL_TEXT_IDLE:
            break;
        case STAFF_ROLL_TEXT_SCROLLING:
            AdvanceStaffRollTextScrolling();
            break;
        case STAFF_ROLL_TEXT_SCROLL_DONE:
            break;
    }
}

void SetStaffRollScrollAndDrainQueue(void) {
    reg_G2S_DB_BG0OFS = ((FROM_FIXED12(gStaffRollText->mScrollYFixed) % 256) << 16) & 0x1ff0000;
    NNS_GfdDoVramTransfer();
}

void StartStaffRollText(void) {
    gStaffRollText->mNextState = STAFF_ROLL_TEXT_SCROLLING;
}
