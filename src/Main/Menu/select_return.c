#include "Main/Menu/select_return.h"
#include "registers.h"

#include "Main/System/heap.h"
#include "Main/Graphics/text_draw.h"
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
#include "code_0200eddc.h"
#include "gfd_VramTransferManager.h"
#include "g2d_CharCanvas.h"
#include "g2.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Graphics/font_and_player_character.h"
#include "os_thread.h"
#include "Main/Menu/data_0215d000.h"
#include "Main/Menu/data_0216e000.h"
#include "code_02134398.h"
#include "output_effect.h"
#include "gx_load2d.h"
#include "Main/System/result_archive_path.h"
#include "code_0212df7c.h"
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
SelectReturn *gSelectReturn;
SelectChoises *gSelectChoises;

#pragma thumb on
s32 InitSelectReturn(void *heap, s32 subCharOffset) {
    u32 subDisplayBits;
    gSelectReturn = HeapAlloc(heap, 0x828);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InitSelectReturnDisplay();
        subCharOffset = LoadSelectReturn(subCharOffset);
        gSelectReturn->mDisplayBitOn = TRUE;
    } else {
        gSelectReturn->mDisplayBitOn = FALSE;
        subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
        subDisplayBits &= ~4;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
    }
    gSelectReturn->mEnabled = TRUE;
    gSelectReturn->mState = SELECT_RETURN_STATE_HIDDEN;
    gSelectReturn->mNextState = SELECT_RETURN_STATE_HIDDEN;
    gSelectReturn->mStateFrames = 0;
    gSelectReturn->mSlideInRequested = FALSE;
    gSelectReturn->mSlideOutRequested = FALSE;
    gSelectReturn->mBg2Offset = -0x28;
    gSelectReturn->mSoundId = 0xe;
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void ClearSelectReturnPointer(void) {
    gSelectReturn = NULL;
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

s32 LoadSelectReturn(s32 subCharOffset) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;
    s32 rowIndex;
    s32 columnIndex;
    s32 unusedValue;
    LocateNcgr(&ncgr, FindFileInLoadedArchives("select_return_s_b_00.ncgr"));
    LocateNscr(&nscr, FindFileInLoadedArchives("select_return_s_bg_00.nscr"));
    LocateNclr(&nclr, FindFileInLoadedArchives("select_return_s_b_00.nclr"));
    subCharOffset -= ncgr->mDataSize;
    DC_FlushRange(ncgr->mData, ncgr->mDataSize);
    GXS_LoadBG2Char(ncgr->mData, subCharOffset, ncgr->mDataSize);
    for (rowIndex = 0; rowIndex < 0x20; rowIndex++) {
        for (columnIndex = 0; columnIndex < 0x20; columnIndex++) {
            *(gSelectReturn->mScreenMapCopy + rowIndex * 0x20 + columnIndex) =
                (subCharOffset >> 5) + *((u16 *) nscr->mData + rowIndex * 0x20 + columnIndex);
        }
    }
    DC_FlushRange(gSelectReturn->mScreenMapCopy, nscr->mDataSize);
    GXS_LoadBG2Scr(gSelectReturn->mScreenMapCopy, 0, nscr->mDataSize);
    DC_FlushRange(nclr->mData, 0x180);
    GXS_LoadBGPltt(nclr->mData + 0xc0, 0x180, 0x40);
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
        gSelectReturn->mScreenMapCopy[tileIndex] &= ~0xf000;
        gSelectReturn->mScreenMapCopy[tileIndex] |= paletteBits;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG2_MAP, 0x4c0, &gSelectReturn->mScreenMapCopy[0x260],
                                           0x200);
    }
}

void AdvanceSelectReturnHidden(void) {
    if (gSelectReturn->mSlideInRequested != FALSE) {
        gSelectReturn->mNextState = SELECT_RETURN_STATE_SLIDE_IN;
        gSelectReturn->mStateFrames = 0;
        SetSelectReturnPaletteBits(1);
    }
}

void AdvanceSelectReturnSlideIn(void) {
    SelectReturn *selectReturn;
    gSelectReturn->mBg2Offset = LookupSelectReturnSlideInBg2Offset(gSelectReturn->mStateFrames);
    gSelectReturn->mStateFrames++;
    selectReturn = gSelectReturn;
    if (selectReturn->mStateFrames >= 10) {
        selectReturn->mNextState = SELECT_RETURN_STATE_SHOWN;
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mSlideInRequested = FALSE;
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectReturnShown(void) {
    SelectReturn *selectReturn;
    selectReturn = gSelectReturn;
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
    selectReturn = gSelectReturn;
    selectReturn->mBg2Offset = gSelectReturnPressBg2Offsets[selectReturn->mStateFrames];
    gSelectReturn->mStateFrames++;
    selectReturn = gSelectReturn;
    if (selectReturn->mStateFrames >= 9) {
        if (selectReturn->mSlideOutRequested != FALSE) {
            selectReturn->mNextState = SELECT_RETURN_STATE_SLIDE_OUT;
            SetSelectReturnPaletteBits(0);
        } else {
            selectReturn->mNextState = SELECT_RETURN_STATE_SHOWN;
            SetSelectReturnPaletteBits(1);
        }
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mPressRequested = FALSE;
    }
}

void AdvanceSelectReturnSlideOut(void) {
    SelectReturn *selectReturn;
    gSelectReturn->mBg2Offset = LookupSelectReturnSlideOutBg2Offset(gSelectReturn->mStateFrames);
    gSelectReturn->mStateFrames++;
    selectReturn = gSelectReturn;
    if (selectReturn->mStateFrames >= 10) {
        selectReturn->mNextState = SELECT_RETURN_STATE_HIDDEN;
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mSlideOutRequested = FALSE;
    }
}

void AdvanceSelectReturn(void) {
    SelectReturn *selectReturn;
    selectReturn = gSelectReturn;
    if (selectReturn->mEnabled != FALSE) {
        selectReturn->mState = selectReturn->mNextState;
        switch (gSelectReturn->mState) {
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

void WriteSelectReturnRegisters(void) {
    SelectReturn *selectReturn;
    u32 subDisplayBits;
    selectReturn = gSelectReturn;
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
        reg_G2S_DB_BG2OFS = (gSelectReturn->mBg2Offset << 16) & 0x1ff0000;
    }
}

void RequestSelectReturnSlideIn(void) {
    if (IsSelectReturnShownNoRequest() != 0) {
        gSelectReturn->mSlideInRequested = FALSE;
    } else {
        gSelectReturn->mSlideInRequested = TRUE;
    }
    gSelectReturn->mPressRequested = FALSE;
    gSelectReturn->mSlideOutRequested = FALSE;
}

// requestSlideOut != 0 also asks for the slide out once the press ends.
void RequestSelectReturnPressWithSound(s32 requestSlideOut) {
    s32 soundId;
    gSelectReturn->mSlideInRequested = FALSE;
    gSelectReturn->mPressRequested = TRUE;
    if (requestSlideOut != 0) {
        gSelectReturn->mSlideOutRequested = TRUE;
    } else {
        gSelectReturn->mSlideOutRequested = FALSE;
    }
    soundId = gSelectReturn->mSoundId;
    if (soundId != -1) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, (u16) soundId);
    }
}

void RequestSelectReturnSlideOut(void) {
    if (IsSelectReturnHiddenNoRequest() != 0) {
        gSelectReturn->mSlideOutRequested = FALSE;
    } else {
        gSelectReturn->mSlideOutRequested = TRUE;
    }
    gSelectReturn->mSlideInRequested = FALSE;
    gSelectReturn->mPressRequested = FALSE;
}

BOOL IsSelectReturnShownNoRequest(void) {
    BOOL result;
    BOOL shownNoSlideOutRequest;
    SelectReturn *selectReturn;
    result = FALSE;
    shownNoSlideOutRequest = FALSE;
    selectReturn = gSelectReturn;
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
    selectReturn = gSelectReturn;
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
    gSelectReturn->mDisplayBitOn = 0;
}
#pragma thumb off

#pragma thumb on
void SetSelectReturnDisplayBitOn(void) {
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        gSelectReturn->mDisplayBitOn = TRUE;
    }
}
#pragma thumb off

#pragma thumb on
void SetSelectReturnSoundId(u32 soundId) {
    gSelectReturn->mSoundId = soundId;
}
#pragma thumb off

#pragma thumb on
// Zeroes the char buffer gate; StartSelectChoises sets it after taking the strings.
void ClearSelectChoisesUseCharBuffers(void) {
    gSelectChoises->mUseCharBuffers = 0;
}
#pragma thumb off

#pragma thumb on
s32 InitSelectChoises(void *heap, void *font, s32 subCharOffset) {
    s32 canvasIndex;
    s32 charSpacing;
    NNSG2dCharCanvas *charCanvas;
    TextCanvas *textCanvas;
    u32 subDisplayBits;
    gSelectChoises = HeapAlloc(heap, 0x8b4);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InitSelectChoisesDisplay();
        subCharOffset = LoadSelectChoises(subCharOffset);
        gSelectChoises->mDisplayBitOn = 1;
    } else {
        gSelectChoises->mDisplayBitOn = 0;
        subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
        subDisplayBits &= ~1;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
    }
    for (canvasIndex = 0; canvasIndex < 2; canvasIndex++) {
        gSelectChoises->mCharBuffers[canvasIndex] = HeapAlloc(heap, 0x800);
        NNS_G2dCharCanvasInitForBG(&gSelectChoises->mCharCanvases[canvasIndex],
                                   gSelectChoises->mCharBuffers[canvasIndex], 0x20, 2, 4);
        charCanvas = &gSelectChoises->mCharCanvases[canvasIndex];
        charCanvas->mPClear(charCanvas, 0);
        charSpacing = IsLanguageJa();
        textCanvas = &gSelectChoises->mTextCanvases[canvasIndex];
        textCanvas->mCharCanvas = &gSelectChoises->mCharCanvases[canvasIndex];
        textCanvas->mFont = font;
        textCanvas->mCharSpacing = charSpacing;
        textCanvas->mLineSpacing = 0;
    }
    ClearSelectChoisesUseCharBuffers();
    gSelectChoises->mEnabled = 1;
    gSelectChoises->mState = SELECT_CHOISES_STATE_HIDDEN;
    gSelectChoises->mNextState = SELECT_CHOISES_STATE_HIDDEN;
    gSelectChoises->mChosenFrames = 0;
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
    gSelectChoises->mChooseRequested = 0;
    gSelectChoises->mHiddenRequested = 0;
    gSelectChoises->mDone = 0;
    gSelectChoises->mIndexNone = 0;
    gSelectChoises->mSoundIds[0] = 7;
    gSelectChoises->mSoundIds[1] = 0x10;
    gSelectChoises->mIndexNoneSoundId = 0x10;
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void ClearSelectChoisesPointer(void) {
    gSelectChoises = NULL;
}
#pragma thumb off

#pragma thumb on
u32 InitSelectChoisesDisplay(void) {
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

s32 LoadSelectChoises(s32 subCharOffset) {
    Ncgr *chars;
    Nscr *screenMap;
    Nclr *palette;
    s32 firstTileIndex;
    s32 rowIndex;
    s32 columnIndex;
    s32 tileColumn;
    s32 tileRowOffset;
    const ByteRect *tileRect;

    LocateNcgr(&chars, FindFileInLoadedArchives("select_choises_s_b.ncgr"));
    LocateNscr(&screenMap, FindFileInLoadedArchives("select_choises_s_bg.nscr"));
    LocateNclr(&palette, FindFileInLoadedArchives("select_choises_s_b.nclr"));
    subCharOffset = subCharOffset - chars->mDataSize;
    firstTileIndex = subCharOffset >> 5;
    gSelectChoises->mFirstTileIndex = firstTileIndex;
    DC_FlushRange(chars->mData, chars->mDataSize);
    GXS_LoadBG0Char(chars->mData, subCharOffset, chars->mDataSize);
    for (rowIndex = 0; rowIndex < 32; rowIndex++) {
        for (columnIndex = 0; columnIndex < 32; columnIndex++) {
            *(gSelectChoises->mNscrCopy + rowIndex * 32 + columnIndex) =
                firstTileIndex + *((u16 *) screenMap->mData + rowIndex * 32 + columnIndex);
        }
    }
    DC_FlushRange(gSelectChoises->mNscrCopy, screenMap->mDataSize);
    GXS_LoadBG0Scr(gSelectChoises->mNscrCopy, 0, screenMap->mDataSize);
    tileRect = &gSelectChoisesTileRect;
    tileRowOffset = tileRect->mMinY * 32;
    tileColumn = tileRect->mMinX;
    gSelectChoises->mToggleOnFirstTile = gSelectChoises->mFirstTileIndex + (tileColumn + tileRowOffset);
    gSelectChoises->mToggleOffFirstTile = gSelectChoises->mFirstTileIndex + (tileRowOffset + (tileColumn + 3));
    DC_FlushRange(palette->mData, 0x1c0);
    GXS_LoadBGPltt(palette->mData + 0xe0, 0x1c0, 0x40);
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
        if (choiceIndex == gSelectChoises->mIndex && gSelectChoises->mToggleOn != 0) {
            useToggleOnTiles = TRUE;
        }
        for (row = 0; row <= lastRow; row++) {
            for (column = 0; column <= lastColumn; column++) {
                screenMapIndex = column + (*origin)[0] + ((row + (*origin)[1]) << 5);
                tileIndex = row * 32 + (gSelectChoises->mToggleOffFirstTile + column);
                if (useToggleOnTiles != FALSE) {
                    tileIndex = row * 32 + (gSelectChoises->mToggleOnFirstTile + column);
                }
                if (useToggleOnTiles != FALSE) {
                    gSelectChoises->mNscrCopy[screenMapIndex] =
                        tileIndex + ((gSelectChoises->mNscrCopy[screenMapIndex] & 0xffff0c00) + 0xe000);
                } else {
                    gSelectChoises->mNscrCopy[screenMapIndex] =
                        tileIndex + (gSelectChoises->mNscrCopy[screenMapIndex] & 0xfffffc00);
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
        if (gSelectChoises->mIndex != choiceIndex) {
            topNibble = 0xf;
        }
        for (row = gSelectChoisesPaletteRects[choiceIndex].mMinY; row <= gSelectChoisesPaletteRects[choiceIndex].mMaxY;
             row++) {
            for (column = gSelectChoisesPaletteRects[choiceIndex].mMinX;
                 column <= gSelectChoisesPaletteRects[choiceIndex].mMaxX; column++) {
                entry = gSelectChoises->mNscrCopy[row * 32 + column];
                entry &= 0xffff0fff;
                entry += TO_FIXED12(topNibble);
                gSelectChoises->mNscrCopy[row * 32 + column] = entry;
            }
        }
    }
}

void RefreshAndQueueSelectChoises(void) {
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
    RefreshSelectChoisesPaletteBits();
    RefreshSelectChoisesNscrCopy();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG0_MAP, 0, gSelectChoises->mNscrCopy, 0x800);
    }
}

void RefreshSelectChoisesPaletteNoIndex(void) {
    s32 savedIndex;

    savedIndex = gSelectChoises->mIndex;
    gSelectChoises->mIndex = -1;
    RefreshSelectChoisesPaletteBits();
    gSelectChoises->mIndex = savedIndex;
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG0_MAP, 0, gSelectChoises->mNscrCopy, 0x800);
    }
}

void AdvanceSelectChoisesHidden(void) {
    s32 choiceIndex;
    s32 partIndex;
    s32 tileOffset;

    if (gSelectChoises->mChooseRequested != 0) {
        RefreshAndQueueSelectChoises();
        gSelectChoises->mNextState = SELECT_CHOISES_STATE_CHOOSE;
        choiceIndex = 0;
        gSelectChoises->mChooseRequested = choiceIndex;
        gSelectChoises->mChosenFrames = choiceIndex;
        gSelectChoises->mIndexNone = choiceIndex;
        if (gSelectChoises->mUseCharBuffers != 0) {
            for (choiceIndex = 0; choiceIndex < 2; choiceIndex++) {
                for (partIndex = 0; partIndex < 2; partIndex++) {
                    tileOffset = (partIndex + choiceIndex * 2) * 32 + 5;
                    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                        NNS_GfdRegisterNewVramTransferTask(
                            0x14, (gSelectChoises->mFirstTileIndex + tileOffset) << 5,
                            gSelectChoises->mCharBuffers[choiceIndex] + ((partIndex * 32 + 5) << 5), 0x360);
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
    u16 hasPair = gInputSlots[inputSlotIndex].mPair.mHasPair;

    if (hasPair == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        result = TRUE;
    }
    return result;
}

void AdvanceSelectChoisesChoose(void) {
    s32 hit;
    u16 touchX;
    u16 touchY;
    InputSlotIndex inputSlotIndex;
    u16 keys;

    inputSlotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    touchX = gInputSlots[inputSlotIndex].mPair.mPairX;
    touchY = gInputSlots[inputSlotIndex].mPair.mPairY;
    if (gSelectChoises->mHiddenRequested != 0) {
        gSelectChoises->mNextState = SELECT_CHOISES_STATE_HIDDEN;
        gSelectChoises->mHiddenRequested = 0;
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
    keys = gInputSlots[inputSlotIndex].mPressedBits;
    if ((u16) (keys & PAD_KEY_A) != 0 || hit != -1) {
        if (hit == -1 || gSelectChoises->mIndex == hit) {
            RefreshSelectChoisesPaletteNoIndex();
        } else {
            gSelectChoises->mIndex = hit;
            RefreshAndQueueSelectChoises();
        }
        gSelectChoises->mNextState = SELECT_CHOISES_STATE_CHOSEN;
        if (gSelectChoises->mDisplayBitOn != 0) {
            if (gSelectChoises->mSoundIds[gSelectChoises->mIndex] != -1) {
                StartSoundOncePerFrame((u16) gSelectChoises->mSoundIds[gSelectChoises->mIndex]);
            }
        }
    } else {
        if ((u16) (keys & PAD_KEY_B) != 0) {
            gSelectChoises->mIndexNone = 1;
            gSelectChoises->mChosenFrames = 0xb;
            gSelectChoises->mNextState = SELECT_CHOISES_STATE_CHOSEN;
            if (gSelectChoises->mDisplayBitOn != 0) {
                if (gSelectChoises->mIndexNoneSoundId != -1) {
                    StartSoundOncePerFrame((u16) gSelectChoises->mIndexNoneSoundId);
                }
            }
            return;
        }
        if ((u16) (keys & PAD_KEY_UP) != 0 && gSelectChoises->mIndex == 1) {
            gSelectChoises->mIndex = 0;
            RefreshAndQueueSelectChoises();
            if (gSelectChoises->mDisplayBitOn != 0) {
                StartSoundOncePerFrame(0);
            }
            return;
        }
        if ((u16) (keys & PAD_KEY_DOWN) != 0 && gSelectChoises->mIndex == 0) {
            gSelectChoises->mIndex = 1;
            RefreshAndQueueSelectChoises();
            if (gSelectChoises->mDisplayBitOn != 0) {
                StartSoundOncePerFrame(0);
            }
        }
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectChoisesChosen(void) {
    SelectChoises *selectChoises;
    int stateFrames;
    selectChoises = gSelectChoises;
    if (selectChoises->mHiddenRequested != 0) {
        selectChoises->mNextState = SELECT_CHOISES_STATE_HIDDEN;
        gSelectChoises->mHiddenRequested = 0;
        return;
    }
    selectChoises->mChosenFrames = selectChoises->mChosenFrames + 1;
    stateFrames = gSelectChoises->mChosenFrames;
    if (15 <= stateFrames) {
        gSelectChoises->mDone = 1;
        gSelectChoises->mChosenFrames = 0xf;
        return;
    }
    if (5 <= stateFrames) {
        RefreshAndQueueSelectChoises();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectChoises(void) {
    if (gSelectChoises->mEnabled != 0) {
        gSelectChoises->mState = gSelectChoises->mNextState;
        switch (gSelectChoises->mState) {
            case SELECT_CHOISES_STATE_HIDDEN:
                AdvanceSelectChoisesHidden();
                break;
            case SELECT_CHOISES_STATE_CHOOSE:
                AdvanceSelectChoisesChoose();
                break;
            case SELECT_CHOISES_STATE_CHOSEN:
                AdvanceSelectChoisesChosen();
                break;
        }
        gSelectChoises->mToggleFrames++;
        if ((gSelectChoises->mToggleOn != 0 && gSelectChoises->mToggleFrames > 0x1e) ||
            (gSelectChoises->mToggleOn == 0 && gSelectChoises->mToggleFrames > 0x14)) {
            gSelectChoises->mToggleOn = gSelectChoises->mToggleOn == 0;
            gSelectChoises->mToggleFrames = 0;
            RefreshSelectChoisesNscrCopy();
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG0_MAP, 0, gSelectChoises->mNscrCopy, 0x800);
            }
        }
    }
}

void WriteSelectChoisesRegisters(void) {
    u32 subDisplayBits;

    if (gSelectChoises->mEnabled != 0) {
        reg_G2S_DB_BG0OFS = 0;
        if (gSelectChoises->mState == SELECT_CHOISES_STATE_HIDDEN || gSelectChoises->mDisplayBitOn == 0) {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x1e, 0x1f, 6, 10, 0);
            subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits & ~1) << 8);
        } else {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x1e, 0x1f, 6, 10, -10);
            subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits | 1) << 8);
        }
    }
}

void RequestSelectChoisesChoose(void) {
    if ((gSelectChoises->mState == SELECT_CHOISES_STATE_HIDDEN && gSelectChoises->mChooseRequested != 0) ||
        gSelectChoises->mState == SELECT_CHOISES_STATE_CHOOSE) {
        gSelectChoises->mHiddenRequested = 1;
    } else {
        gSelectChoises->mHiddenRequested = 0;
    }
    gSelectChoises->mChooseRequested = 1;
}

void StartSelectChoises(void *firstText, void *secondText, s32 startOnSecond) {
    NNSG2dCharCanvas *charCanvas;

    charCanvas = &gSelectChoises->mCharCanvases[0];
    charCanvas->mPClear(charCanvas, 5);
    charCanvas = &gSelectChoises->mCharCanvases[1];
    charCanvas->mPClear(charCanvas, 5);
    DrawTextInRectNoFixedAdvance(&gSelectChoises->mTextCanvases[0], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, firstText);
    DrawTextInRectNoFixedAdvance(&gSelectChoises->mTextCanvases[1], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, secondText);
    ClearSelectChoisesUseCharBuffers();
    gSelectChoises->mUseCharBuffers = 1;
    RequestSelectChoisesChoose();
    if (startOnSecond == 0) {
        gSelectChoises->mIndex = 0;
    } else {
        gSelectChoises->mIndex = 1;
    }
    RefreshAndQueueSelectChoises();
    gSelectChoises->mDone = 0;
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
}

void RequestSelectChoisesHidden(void) {
    gSelectChoises->mChooseRequested = 0;
    gSelectChoises->mHiddenRequested = 1;
}

BOOL IsSelectChoisesChooseNoRequest(void) {
    u32 result;

    result = 0;
    if (gSelectChoises->mState == SELECT_CHOISES_STATE_CHOOSE && gSelectChoises->mHiddenRequested == 0) {
        result = 1;
    }
    return result;
}

BOOL IsSelectChoisesHiddenNoRequest(void) {
    BOOL result;

    result = FALSE;
    if (gSelectChoises->mState == SELECT_CHOISES_STATE_HIDDEN && gSelectChoises->mChooseRequested == 0) {
        result = TRUE;
    }
    return result;
}
#pragma thumb off

#pragma thumb on

s32 GetSelectChoisesIndex(void) {
    if (gSelectChoises->mIndexNone != 0) {
        return 0xffffffff;
    }
    return gSelectChoises->mIndex;
}

u32 GetSelectChoisesDone(void) {
    return gSelectChoises->mDone;
}

void SetSelectChoisesSoundId(int choiceIndex, u32 soundId) {
    if (choiceIndex == -1) {
        gSelectChoises->mIndexNoneSoundId = soundId;
        return;
    }
    gSelectChoises->mSoundIds[choiceIndex] = soundId;
}

#pragma thumb off
