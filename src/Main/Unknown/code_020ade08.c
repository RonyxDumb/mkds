#include "Main/Unknown/code_020ade08.h"

#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/code_020ad8e0.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ae0c8.h"
#include "Main/Unknown/code_020ae0e4.h"
#include "Main/Unknown/code_020ae0f8.h"
#include "Main/Unknown/code_020ae178.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_0212b09c.h"
#include "code_0200eddc.h"
#include "g2d_CharCanvas.h"
#include "code_0213c9f8.h"
#include "code_0213ecf8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae1f4.h"
#include "Main/Unknown/code_020ae214.h"
#include "Main/Unknown/code_020ae21c.h"
#include "Main/Unknown/code_020ae23c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0203b680.h"
#include "Main/Unknown/code_0203b69c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_020ae3d8.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0215d000.h"

#pragma optimize_for_size on

// Course ids, four per cup.
u32 CourseOrderAll[] = {20, 22, 31, 18, 27, 28, 33, 24, 30, 17, 25, 19, 34, 26, 32, 29, 10, 11, 13,
                       14, 35, 16, 12, 9,  15, 36, 37, 38, 39, 23, 40, 1,  3,  4,  5,  6,  7,  8,
                       2,  21, 42, 43, 44, 45, 46, 47, 41, 48, 49, 50, 51, 52, 53, 54, 0};

#pragma thumb on

u16 oam_getAffineId(void *oamList) {
    u16 *countPointer;
    u16 matrixIndex;

    countPointer = OFFSET_PTR(u16, oamList, 0x402);
    matrixIndex = *countPointer;
    *countPointer = matrixIndex + 1;
    return matrixIndex;
}

s32 func_020ae584(s32 index) {
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

s16 mutil_FX_CosIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2 + 1];
}

s32 mutil_FX_TRUNC_MUL(s32 value, s32 factor) {
    return ((s64) value * factor) >> 12;
}

s32 sub_20AE54C(s32 value) {
    return value >> 12;
}

#pragma thumb on

// Mode 0 is linear, mode 1 eases the difference; returns b for d <= 0 and c for d >= e.
s16 mutil_interpolate(s32 mode, s16 start, s16 end, s32 elapsedFrames, s32 durationFrames) {
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
            easeValue = mutil_FX_CosIdx((elapsedFrames << 15) / durationFrames);
            difference = end - start;
            if (difference > 0) {
                scaledDifference = 0.5f + (difference << 12);
            } else {
                scaledDifference = (difference << 12) - 0.5f;
            }
            return start + sub_20AE54C(mutil_FX_TRUNC_MUL(scaledDifference, 0x1000 - easeValue)) / 2;
    }
}

s16 mutil_getButtonOutEffectOffset(s32 frame) {
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

u16 mutil_input_getTriggeredKeysWithMask(InputSlot *inputSlot, u32 mask) {
    return inputSlot->mPressedBits & mask;
}

u16 mutil_input_getTriggeredKeysWithMaskById(u32 slotIndex, u32 mask) {
    return mutil_input_getTriggeredKeysWithMask(&gInputUnits[slotIndex], mask);
}

// Returns the masked bits in place, not 0 or 1.
u16 mutil_input_getRepeatedKeysWithMask(InputSlot *inputSlot, u32 mask) {
    return inputSlot->mRepeatBits & mask;
}

// Returns the masked bits in place, not 0 or 1.
u16 mutil_input_getRepeatedKeysWithMaskById(u32 slotIndex, u32 mask) {
    return mutil_input_getRepeatedKeysWithMask(&gInputUnits[slotIndex], mask);
}

#pragma thumb on

u16 mutil_checkKeys(u32 slotIndex, u32 mask) {
    int newBits;
    int repeatBits;
    newBits = mutil_input_getTriggeredKeysWithMaskById(slotIndex, mask);
    repeatBits = mutil_input_getRepeatedKeysWithMaskById(slotIndex, mask);
    return newBits | repeatBits;
}

#pragma thumb off

u32 func_020ae3f4(void) {
    return (gSystemData->field20);
}

u32 func_020ae3d8(void) {
    return ((u32) &gStruct217AA00->field1EE8);
}

#pragma thumb on

u32 func_020ae3b4(u32 limit) {
    int v1;
    u32 randomState;
    v1 = func_020ae3f4();
    if (v1 == 0) {
        randomState = (u32) sysdat_getRandom();
    } else {
        randomState = func_020ae3d8();
    }
    return sub_2046524((RandomState64 *) randomState, limit);
}

#pragma thumb off

#pragma thumb on

u32 SPM_GetCourseIDByCupIndex(s32 cupIndex, s32 courseIndex) {
    return CourseOrderAll[cupIndex * 4 + courseIndex];
}

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn) {
    u32 table;
    s32 rowCount;
    s32 columnCount;
    u8 row;
    u8 column;

    table = (u32) arc_get2dArcFile("/missionTable.mtbl");
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

u32 sub_20AE338(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mHasPair;
}

BOOL sub_20AE308(InputSlotPair *inputSlotPair) {
    if (sub_20AE338(inputSlotPair) == 0 && inputSlotPair->mNoPairCount < 5) {
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

BOOL func_020ae2b0(InputSlotPair *inputSlotPair) {
    if (sub_20AE308(inputSlotPair) == 0 && IsPairNew(inputSlotPair) != 0) {
        return 1;
    }
    return 0;
}

BOOL IsSlotPairNew(u32 slotIndex) {
    return func_020ae2b0((InputSlotPair *) &gInputUnits[slotIndex].mPairX);
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

u32 GetPairX(u32 pair) {
    return (*OFFSET_PTR(const u16, pair, 0));
}

u32 GetSlotPairX(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 inputSlots;
    u32 value12;
    inputSlots = (u32) &gInputUnits;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (inputSlots);
    value12 = (u32) &GetPairX;
    value0 = (value1) + (0x48u);
    value0 = GetPairX(value0);
    return value0;
}

u32 GetPairY(u32 pair) {
    return (*OFFSET_PTR(const u16, pair, 2));
}

u32 GetSlotPairY(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 inputSlots;
    u32 value12;
    inputSlots = (u32) &gInputUnits;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (inputSlots);
    value12 = (u32) &GetPairY;
    value0 = (value1) + (0x48u);
    value0 = GetPairY(value0);
    return value0;
}

#pragma thumb on

u32 ReverseBytes32(u32 value) {
    return (u8) (value >> 24) + (((u8) (value >> 16) << 8) + (((u8) value << 24) + ((u8) (value >> 8) << 16)));
}

void *GetCharacterBmgEntry(u32 characterIndex, u32 b) {
    u32 messageIndexes[13] = {20, 25, 24, 27, 22, 26, 23, 21, 29, 28, 30, 31, 32};
    u32 messageIndex;

    if (b != 0 && characterIndex == 1) {
        messageIndex = 0x21;
    } else if (b != 0 && characterIndex == 8) {
        messageIndex = 0x22;
    } else {
        messageIndex = messageIndexes[characterIndex];
    }
    return jn_msg_getMessage(m2d_get2dArcFile("common.bmg"), messageIndex);
}

#pragma thumb off

u32 GetRacerType(u32 entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (112));
    return value0;
}

BOOL IsRacerPlayerOrGhostOrNet(u32 entryIndex) {
    if (GetRacerType(entryIndex) == 0 || GetRacerType(entryIndex) == 2 || GetRacerType(entryIndex) == 3) {
        return 1;
    }
    return 0;
}

u32 GetKartEntryName(u32 entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (136));
    return value0;
}

u32 GetCurrentRaceMode_0(void) {
    return (gRaceMultiConfig->mMode);
}

u32 GetRacerCharacterId_0(u32 entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (104));
    return value0;
}

int GetKartEntryNumber(int entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const s8 *) ((value1) + (134));
    return value0;
}

#pragma thumb on

void CopyKartEntryName(u32 entryIndex, u16 *nameOut, u32 c) {
    u16 numberText[2];
    u16 numberedName[10];
    u16 x[12];
    u16 i;
    u32 charCount;
    u16 *source;

    for (i = 0; i < 11; i++) {
        nameOut[i] = 0;
    }
    if (IsRacerPlayerOrGhostOrNet(entryIndex) != 0) {
        source = (u16 *) GetKartEntryName(entryIndex);
        if (source == NULL) {
            return;
        }
        if (c != 0) {
            charCount = 10;
        } else {
            charCount = CopyTextWithinWidth(source, &x[1]);
        }
    } else {
        if (GetCurrentRaceMode_0() == MODE_GRAND_PRIX || GetCurrentRaceMode_0() == MODE_MISSION_RUN) {
            source = GetCharacterBmgEntry(GetRacerCharacterId_0(entryIndex), c);
            charCount = 20;
        } else {
            wcsncpy(numberedName, jn_msg_getMessage(m2d_get2dArcFile("common.bmg"), 0x72), 9);
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
    s32 i;
    s32 j;

    font = m2d_getFont(0);
    messageScreenCharBuffer = err_getCharData();
    err_clearCharData();
    for (i = 0; i < 0x100; i++) {
        messageScreenCharBuffer[i] = 0;
    }
    NNS_G2dCharCanvasInitForBG(&charCanvas, messageScreenCharBuffer, 8, 2, 4);
    InitTextCanvas(&textCanvas, &charCanvas, font, 2, 0);
    CopyKartEntryName(entryIndex, name, 0);
    for (j = -1; j < 2; j++) {
        for (i = -1; i < 2; i++) {
            DrawTextOnCanvas(&textCanvas, j + 0x20, i + 8, 2, 0x412, name);
        }
    }
    DrawTextOnCanvas(&textCanvas, 0x20, 8, 1, 0x412, name);
    DC_FlushRange(err_getCharData(), 0x200);
}

void SetPixel2Bit(u16 *pixels, s32 pixelX, s32 pixelY, s32 value) {
    u16 halfword;
    s32 o;
    s32 shift;

    o = (pixelX + pixelY * 64) / 8 * 2;
    halfword = pixels[(pixelX + pixelY * 64) / 8];
    shift = pixelX % 8 * 2;
    halfword &= ~(3 << shift);
    pixels[(pixelX + pixelY * 64) / 8] = halfword | (value << shift);
}

void PlotNibblePixels(const u16 *sourcePixels, u16 *dest, s32 colorForValue1, s32 colorForValue2,
                      PixelSetFunc *pixelSetFunc) {
    s32 i;
    s32 j;
    s32 k;
    s32 p;
    s32 q;
    s32 u;
    s32 w;
    u16 nibbles;

    for (i = 0; i < 16; i++) {
        p = i / 8;
        q = i % 8;
        for (j = 0; j < 16; j++) {
            u = j / 2;
            w = j % 2;
            nibbles = sourcePixels[i * 16 + j];
            for (k = 0; k < 4; k++) {
                switch ((u8) ((nibbles >> (k * 4)) % 16)) {
                    case 0:
                        break;
                    case 1:
                        pixelSetFunc(dest, q * 8 + w * 4 + k, p * 8 + u, colorForValue1);
                        break;
                    case 2:
                        pixelSetFunc(dest, q * 8 + w * 4 + k, p * 8 + u, colorForValue2);
                        break;
                }
            }
        }
    }
}

#pragma thumb off
