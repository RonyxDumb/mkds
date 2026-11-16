#pragma once

#include "types.h"

typedef struct TextCanvas TextCanvas;

typedef void PixelSetFunc(u16 *a, s32 b, s32 c, s32 d);

typedef struct InputSlotPair InputSlotPair;

// The bounds of a rectangle, passed by value to IsNewPairInRect.
typedef struct PairRect {
    /* 00 */ u16 mMinX;
    /* 02 */ u16 mMinY;
    /* 04 */ u16 mMaxX;
    /* 06 */ u16 mMaxY;
} PairRect;

typedef struct InputSlotPair InputSlotPair;

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn);

typedef struct InputSlot InputSlot;

extern u32 CourseOrderAll[];

void PlotNibblePixels(const u16 *sourcePixels, u16 *dest, s32 colorForValue1, s32 colorForValue2,
                      PixelSetFunc *pixelSetFunc);
void SetPixel2Bit(u16 *pixels, s32 pixelX, s32 pixelY, s32 value);
void RenderKartEntryName(u32 entryIndex);
void DrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void InitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
void CopyKartEntryName(u32 entryIndex, u16 *nameOut, u32 c);
int GetKartEntryNumber(int entryIndex);
BOOL IsRacerPlayerOrGhostOrNet(u32 entryIndex);
u32 GetRacerType(u32 entryIndex);
BOOL IsNewPairInRect(u32 slotIndex, PairRect pairRect);
BOOL IsSlotPairNew(u32 slotIndex);
BOOL func_020ae2b0(InputSlotPair *inputSlotPair);
BOOL IsPairNew(InputSlotPair *inputSlotPair);
BOOL sub_20AE308(InputSlotPair *inputSlotPair);
unsigned int sub_20AE338(InputSlotPair *inputSlotPair);
u32 SPM_GetCourseIDByCupIndex(s32 cupIndex, s32 courseIndex);
u32 func_020ae3b4(u32 limit);
u16 mutil_input_getRepeatedKeysWithMaskById(u32 slotIndex, u32 mask);
u16 mutil_input_getRepeatedKeysWithMask(InputSlot *inputSlot, u32 mask);
u16 mutil_input_getTriggeredKeysWithMaskById(u32 slotIndex, u32 mask);
u16 mutil_input_getTriggeredKeysWithMask(InputSlot *inputSlot, u32 mask);
s16 mutil_getButtonOutEffectOffset(s32 frame);
s16 mutil_interpolate(s32 mode, s16 start, s16 end, s32 elapsedFrames, s32 durationFrames);
s32 sub_20AE54C(s32 value);
s32 mutil_FX_TRUNC_MUL(s32 value, s32 factor);
s16 mutil_FX_CosIdx(s32 angle);
s32 func_020ae584(s32 index);
u16 oam_getAffineId(void *oamList);
