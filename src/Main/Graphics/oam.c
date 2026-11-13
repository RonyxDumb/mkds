#include "Main/Graphics/oam.h"

#include "os_thread.h"
#include "Main/Menu/keyboard_keys.h"
#include "Main/Menu/data_02180728.h"
#include "Main/Menu/title_bg.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Menu/message_screen.h"
#include "code_0200eddc.h"
#include "g2d_CharCanvas.h"
#include "code_0213c9f8.h"
#include "code_0213ecf8.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Race/mission_table_value.h"
#include "Main/System/result_archive_path.h"
#include "Main/Sound/scene_sound_set.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_02147cd8.h"
#include "Main/System/init_after_startup.h"

#pragma optimize_for_size on

// Course ids, four per cup.
u32 gCupCourseIds[] = {20, 22, 31, 18, 27, 28, 33, 24, 30, 17, 25, 19, 34, 26, 32, 29, 10, 11, 13,
                       14, 35, 16, 12, 9,  15, 36, 37, 38, 39, 23, 40, 1,  3,  4,  5,  6,  7,  8,
                       2,  21, 42, 43, 44, 45, 46, 47, 41, 48, 49, 50, 51, 52, 53, 54, 0};

#pragma thumb on

u16 AllocOamMatrixIndex(void *oamList) {
    u16 *countPointer;
    u16 matrixIndex;

    countPointer = OFFSET_PTR(u16, oamList, 0x402);
    matrixIndex = *countPointer;
    *countPointer = matrixIndex + 1;
    return matrixIndex;
}

s32 LookupRowOffset(s32 index) {
    s32 values[15] = {4, 8, 10, 13, 12, 12, 12, 4, -4, -8, -12, -16, -16, -24, -40};

    if (index < 0) {
        return 0;
    }
    if (index >= 15) {
        return -40;
    }
    return values[index];
}

#pragma thumb off

s16 InterpolateFX_CosIdx(s32 angle) {
    return FX_CosIdx(angle);
}

s32 InterpolateMulFixed12NoRound(s32 value, s32 factor) {
    return MUL_FIXED12_NO_ROUND(value, factor);
}

s32 InterpolateGetFixed12Whole(s32 value) {
    return FROM_FIXED12(value);
}

#pragma thumb on

// Mode 0 is linear, mode 1 eases the difference; returns start while elapsedFrames <= 0 and end once it reaches
// durationFrames.
s16 InterpolateS16(s32 mode, s16 start, s16 end, s32 elapsedFrames, s32 durationFrames) {
    s32 easeValue;
    s32 difference;
    float scaledDifference;

    if (elapsedFrames <= 0) {
        return start;
    }
    if (elapsedFrames >= durationFrames) {
        return end;
    }
    switch (mode) {
        case 0:
            return start + elapsedFrames * (end - start) / durationFrames;
        case 1:
            easeValue = InterpolateFX_CosIdx((elapsedFrames << 15) / durationFrames);
            difference = end - start;
            if (difference > 0) {
                scaledDifference = 0.5f + TO_FIXED12(difference);
            } else {
                scaledDifference = TO_FIXED12(difference) - 0.5f;
            }
            return start +
                   InterpolateGetFixed12Whole(InterpolateMulFixed12NoRound(scaledDifference, 0x1000 - easeValue)) / 2;
    }
}

s16 GetSelectedPressOffset(s32 frame) {
    if (frame < 0) {
        return 0;
    }
    if (frame < 3) {
        return frame * -3;
    }
    if (frame < 7) {
        return -9;
    }
    if (frame < 10) {
        return (frame - 7) * 3 - 9;
    }
    return 0;
}

#pragma thumb off

u16 GetInputSlotNewBits(InputSlot *inputSlot, u32 mask) {
    return inputSlot->mPressedBits & mask;
}

u16 GetNewBits(u32 slotIndex, u32 mask) {
    return GetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

// Returns the masked bits in place, not 0 or 1.
u16 GetInputSlotRepeatBits(InputSlot *inputSlot, u32 mask) {
    return inputSlot->mRepeatBits & mask;
}

// Returns the masked bits in place, not 0 or 1.
u16 GetRepeatBits(u32 slotIndex, u32 mask) {
    return GetInputSlotRepeatBits(&gInputSlots[slotIndex], mask);
}

#pragma thumb on

u16 GetNewOrRepeatBits(u32 slotIndex, u32 mask) {
    int newBits;
    int repeatBits;
    newBits = GetNewBits(slotIndex, mask);
    repeatBits = GetRepeatBits(slotIndex, mask);
    return newBits | repeatBits;
}

#pragma thumb off

u32 GetConnectionKind(void) {
    return (gStartupWork->mConnectionKind);
}

RandomState64 *GetConnectionWorkRandomState(void) {
    return &gConnectionWork->mRandomState;
}

#pragma thumb on

// Connection kind 0 draws from the random state in gStartupWork (GetRandomState), any other kind from the one in
// ConnectionWork.
u32 NextRandomBelowByConnectionKind(u32 limit) {
    int connectionKind;
    RandomState64 *randomState;
    connectionKind = GetConnectionKind();
    if (connectionKind == 0) {
        randomState = GetRandomState();
    } else {
        randomState = GetConnectionWorkRandomState();
    }
    return NextRandomBelowU16(randomState, limit);
}

#pragma thumb off

#pragma thumb on

u32 GetCupCourseId(s32 cupIndex, s32 courseIndex) {
    return gCupCourseIds[cupIndex * 4 + courseIndex];
}

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn) {
    MissionTable *table;
    s32 rowCount;
    s32 columnCount;
    u8 row;
    u8 column;

    table = FindFileInLoadedArchives("/missionTable.mtbl");
    rowCount = GetMissionTableRowCount(table);
    columnCount = GetMissionTableColumnCount(table);
    for (row = 1; row <= rowCount; row++) {
        for (column = 1; column <= columnCount; column++) {
            if (value == GetMissionTableValue(table, row, column)) {
                *outRow = row;
                *outColumn = column;
            }
        }
    }
}

#pragma thumb off

u32 GetPairHasPair(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mHasPair;
}

BOOL IsPairRecentlyLost(InputSlotPair *inputSlotPair) {
    if (GetPairHasPair(inputSlotPair) == 0 && inputSlotPair->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

BOOL IsPairNew(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

BOOL IsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair) {
    if (IsPairRecentlyLost(inputSlotPair) == 0 && IsPairNew(inputSlotPair) != 0) {
        return 1;
    }
    return 0;
}

BOOL IsSlotPairNew(u32 slotIndex) {
    return IsPairNewUnlessRecentlyLost(&gInputSlots[slotIndex].mPair);
}

#pragma thumb on

BOOL IsNewPairInRect(u32 slotIndex, PairRect pairRect) {
    u32 slotPairX;
    u32 slotPairY;

    if (IsSlotPairNew(slotIndex) != 0) {
        slotPairX = GetSlotPairX(slotIndex);
        slotPairY = GetSlotPairY(slotIndex);
        if (pairRect.mMinX <= slotPairX && slotPairX <= pairRect.mMaxX && pairRect.mMinY <= slotPairY &&
            slotPairY <= pairRect.mMaxY) {
            return 1;
        }
    }
    return 0;
}

#pragma thumb off

u32 GetPairX(InputSlotPair *pair) {
    return pair->mPairX;
}

u32 GetSlotPairX(u32 slotIndex) {
    return GetPairX(&gInputSlots[slotIndex].mPair);
}

u32 GetPairY(InputSlotPair *pair) {
    return pair->mPairY;
}

u32 GetSlotPairY(u32 slotIndex) {
    return GetPairY(&gInputSlots[slotIndex].mPair);
}

#pragma thumb on

u32 ReverseBytes32(u32 value) {
    return (u8) (value >> 24) + (((u8) (value >> 16) << 8) + (((u8) value << 24) + ((u8) (value >> 8) << 16)));
}

void *GetCharacterBmgEntry(u32 characterIndex, u32 fullName) {
    u32 messageIndexes[13] = {20, 25, 24, 27, 22, 26, 23, 21, 29, 28, 30, 31, 32};
    u32 messageIndex;

    if (fullName != 0 && characterIndex == 1) {
        messageIndex = 0x21;
    } else if (fullName != 0 && characterIndex == 8) {
        messageIndex = 0x22;
    } else {
        messageIndex = messageIndexes[characterIndex];
    }
    return GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), messageIndex);
}

#pragma thumb off

u32 KartEntryGetCurrentPlayerKind(u32 entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
}

BOOL IsKartEntryHumanGhostOrPeer(u32 entryIndex) {
    if (KartEntryGetCurrentPlayerKind(entryIndex) == PLAYER_KIND_HUMAN ||
        KartEntryGetCurrentPlayerKind(entryIndex) == PLAYER_KIND_GHOST ||
        KartEntryGetCurrentPlayerKind(entryIndex) == PLAYER_KIND_PEER) {
        return 1;
    }
    return 0;
}

void *GetKartEntryName(u32 entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mName;
}

u32 KartEntryGetCurrentMode(void) {
    return (gRaceSetup->mMode);
}

u32 KartEntryGetCurrentCharacterIndex(u32 entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mCharacterIndex;
}

int GetKartEntryNumber(int entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mNumber;
}

#pragma thumb on

void CopyKartEntryName(u32 entryIndex, u16 *nameOut, u32 fullName) {
    u16 numberText[2];
    u16 numberedName[10];
    u16 nameChars[12];
    u16 charIndex;
    u32 charCount;
    u16 *source;

    for (charIndex = 0; charIndex < 11; charIndex++) {
        nameOut[charIndex] = 0;
    }
    if (IsKartEntryHumanGhostOrPeer(entryIndex) != 0) {
        source = GetKartEntryName(entryIndex);
        if (source == NULL) {
            return;
        }
        if (fullName != 0) {
            charCount = 10;
        } else {
            charCount = CopyTextWithinWidth(source, &nameChars[1]);
        }
    } else {
        if (KartEntryGetCurrentMode() == MODE_GRAND_PRIX || KartEntryGetCurrentMode() == MODE_MISSION_RUN) {
            source = GetCharacterBmgEntry(KartEntryGetCurrentCharacterIndex(entryIndex), fullName);
            charCount = 20;
        } else {
            wcsncpy(numberedName, GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), 0x72), 9);
            swprintf(numberText, 2, L"%d", GetKartEntryNumber(entryIndex));
            wcsncat(numberedName, numberText, 1);
            source = numberedName;
            charCount = 10;
        }
    }
    if (source != NULL) {
        wcsncpy(nameOut, source, charCount);
    }
}

#pragma thumb off

void InitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

void DrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    NNSi_G2dTextCanvasDrawText(textCanvas, textX, textY, color, flags, text);
}

#pragma thumb on

// Writes the entry name, outlined, into the text buffer and flushes it.
void RenderKartEntryName(u32 entryIndex) {
    Unk02023374 charCanvas;
    TextCanvas textCanvas;
    u16 name[22];
    void *font;
    u16 *messageScreenCharBuffer;
    s32 index;
    s32 offsetX;

    font = GetFontByIndex(0);
    messageScreenCharBuffer = GetMessageScreenCharBuffer();
    ClearMessageScreenChars();
    for (index = 0; index < 0x100; index++) {
        messageScreenCharBuffer[index] = 0;
    }
    NNS_G2dCharCanvasInitForBG(&charCanvas, messageScreenCharBuffer, 8, 2, 4);
    InitTextCanvas(&textCanvas, &charCanvas, font, 2, 0);
    CopyKartEntryName(entryIndex, name, 0);
    for (offsetX = -1; offsetX < 2; offsetX++) {
        for (index = -1; index < 2; index++) {
            DrawTextOnCanvas(&textCanvas, offsetX + 0x20, index + 8, 2, 0x412, name);
        }
    }
    DrawTextOnCanvas(&textCanvas, 0x20, 8, 1, 0x412, name);
    DC_FlushRange(GetMessageScreenCharBuffer(), 0x200);
}

void SetPixel2Bit(u16 *pixels, s32 pixelX, s32 pixelY, s32 value) {
    u16 halfword;
    s32 byteOffset;
    s32 shift;

    byteOffset = (pixelX + pixelY * 64) / 8 * 2;
    halfword = pixels[(pixelX + pixelY * 64) / 8];
    shift = pixelX % 8 * 2;
    halfword &= ~(3 << shift);
    pixels[(pixelX + pixelY * 64) / 8] = halfword | (value << shift);
}

void PlotNibblePixels(const u16 *sourcePixels, u16 *dest, s32 colorForValue1, s32 colorForValue2,
                      PixelSetFunc *pixelSetFunc) {
    s32 tileIndex;
    s32 rowHalfIndex;
    s32 nibbleIndex;
    s32 tileRow;
    s32 tileColumn;
    s32 rowInTile;
    s32 halfOfRow;
    u16 nibbles;

    for (tileIndex = 0; tileIndex < 16; tileIndex++) {
        tileRow = tileIndex / 8;
        tileColumn = tileIndex % 8;
        for (rowHalfIndex = 0; rowHalfIndex < 16; rowHalfIndex++) {
            rowInTile = rowHalfIndex / 2;
            halfOfRow = rowHalfIndex % 2;
            nibbles = sourcePixels[tileIndex * 16 + rowHalfIndex];
            for (nibbleIndex = 0; nibbleIndex < 4; nibbleIndex++) {
                switch ((u8) ((nibbles >> (nibbleIndex * 4)) % 16)) {
                    case 0:
                        break;
                    case 1:
                        pixelSetFunc(dest, tileColumn * 8 + halfOfRow * 4 + nibbleIndex, tileRow * 8 + rowInTile,
                                     colorForValue1);
                        break;
                    case 2:
                        pixelSetFunc(dest, tileColumn * 8 + halfOfRow * 4 + nibbleIndex, tileRow * 8 + rowInTile,
                                     colorForValue2);
                        break;
                }
            }
        }
    }
}

#pragma thumb off
