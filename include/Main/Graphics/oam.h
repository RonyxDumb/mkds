#pragma once

#include "types.h"
#include "Main/System/input_slots.h"

typedef struct TextCanvas TextCanvas;

// Value of a pixel in a text glyph bitmap: nothing, the text color, the outline color.
#define GLYPH_PIXEL_CLEAR 0
#define GLYPH_PIXEL_TEXT 1
#define GLYPH_PIXEL_OUTLINE 2
// Highest value InputSlotPair.mNoPairCount counts to (touch and mic pairs stop counting once past it).
#define INPUT_PAIR_NO_PAIR_COUNT_LIMIT 5
// Frames after a pair is lost during which IsPairRecentlyLost still answers yes.
#define INPUT_PAIR_RECENTLY_LOST_FRAMES 5

typedef void PixelSetFunc(u16 *pixels, s32 pixelX, s32 pixelY, s32 value);

typedef struct InputSlotPair InputSlotPair;

// The bounds of a rectangle, passed by value to IsNewPairInRect.
typedef struct PairRect {
    /* 00 */ u16 mMinX;
    /* 02 */ u16 mMinY;
    /* 04 */ u16 mMaxX;
    /* 06 */ u16 mMaxY;
} PairRect;

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn);

typedef struct InputSlot InputSlot;

extern u32 gCupCourseIds[];

void PlotNibblePixels(const u16 *sourcePixels, u16 *dest, s32 textColor, s32 outlineColor, PixelSetFunc *pixelSetFunc);
void SetPixel2Bit(u16 *pixels, s32 pixelX, s32 pixelY, s32 value);
void SomeDrawRacerName_from_thumb(u32 entryIndex);
void G2d_TextCanvas_PrintString2(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void G2d_Text_Create(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
void FormatRacerNameString_from_thumb(u32 entryIndex, u16 *nameOut, u32 fullName);
int GetRacerCpuIndex(int entryIndex);
BOOL IsRacerPlayerOrGhostOrNet(u32 entryIndex);
u32 GetRacerType(u32 entryIndex);
BOOL IsNewPairInRect(u32 slotIndex, PairRect pairRect);
BOOL IsSlotPairNew(u32 slotIndex);
BOOL IsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair);
BOOL IsPairNew(InputSlotPair *inputSlotPair);
BOOL IsPairRecentlyLost(InputSlotPair *inputSlotPair);
unsigned int GetPairHasPair(InputSlotPair *inputSlotPair);
u32 GetCupCourseId(s32 cupIndex, s32 courseIndex);
u32 NextRandomBelowByConnectionKind(u32 limit);
u16 GetRepeatBits(u32 slotIndex, u32 mask);
u16 GetInputSlotRepeatBits(InputSlot *inputSlot, u32 mask);
u16 GetNewBits(u32 slotIndex, u32 mask);
u16 GetInputSlotNewBits(InputSlot *inputSlot, u32 mask);
s16 GetSelectedPressOffset(s32 frame);
s16 ComputeValueInterpolation_from_thumb(s32 mode, s16 start, s16 end, s32 elapsedFrames, s32 durationFrames);
s32 InterpolateGetFixed12Whole(s32 value);
s32 InterpolateMulFixed12NoRound(s32 value, s32 factor);
s16 InterpolateFX_CosIdx(s32 angle);
s32 LookupRowOffset(s32 index);
u16 AllocOamMatrixIndex(void *oamList);

u32 GetRacerCharacterId_0(u32 entryIndex);

unsigned int GetCurrentRaceMode_0(void);

void *GetRacerName(u32 entryIndex);

void *GetCharacterNameString_from_thumb(u32 characterIndex, u32 fullName);
u32 SwapEndianness32_from_thumb(u32 value);

u32 GetSlotPairY(u32 slotIndex);

unsigned int GetPairY(InputSlotPair *pair);

u32 GetSlotPairX(u32 slotIndex);

unsigned int GetPairX(InputSlotPair *pair);

typedef struct RandomState64 RandomState64;

RandomState64 *GetConnectionWorkRandomState(void);
unsigned int GetConnectionKind(void);

u16 GetNewOrRepeatBits(u32 slotIndex, u32 mask);
