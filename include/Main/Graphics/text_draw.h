#pragma once

#include "types.h"
#include "Main/Graphics/layout_entry_angle.h" // LabelTextCanvas
#include "Main/Scene/display_settings.h" // DisplaySettings

// TextTag.mKind: nothing to expand, a name to insert (the variant picks which), a tag kept for the draw pass (copied
// only when its variant is 0).
#define TEXT_TAG_KIND_NONE 0
#define TEXT_TAG_KIND_NAME 1
#define TEXT_TAG_KIND_KEEP 0xff
// TextTag.mVariant of a name tag: the player name, the player name cut to a fixed width, the owner text, the owner text
// cut to that width; and the variant of the tag that marks where FormatMessageWithText inserts its text. (The cut
// player-name case runs on into the owner-text case.)
#define TEXT_TAG_NAME_PLAYER 0
#define TEXT_TAG_NAME_PLAYER_FIT 1
#define TEXT_TAG_NAME_OWNER_TEXT 10
#define TEXT_TAG_NAME_OWNER_TEXT_FIT 11
#define TEXT_TAG_VARIANT_INSERT 0xff

// A tag in message text: a char code, its size, kind and variant.
typedef struct TextTagWithCharCode {
    /* 00 */ u16 mCharCode;
    /* 02 */ u8 mSize;
    /* 03 */ u8 mKind;
    /* 04 */ u16 mVariant;
} TextTagWithCharCode;

// Tag that MeasureAndExpandText and DrawTextLines read through the pointer they pass to the function at member 4 of
// NNSG2dFont: a byte (the number of bytes), a byte, a halfword and a byte.
typedef struct TextTag {
    /* 00 */ u8 mSize;
    /* 01 */ u8 mKind;
    /* 02 */ u16 mVariant;
    /* 04 */ u8 mColorValue;
} TextTag;

// 1 when the halfword is in 0x30..0x39 or 0xff10..0xff19, or is 0x2d; else 0.
static inline s32 IsDigitOrDash(u16 character) {
    if ((character >= 0x30 && character <= 0x39) || (character >= 0xff10 && character <= 0xff19) || character == 0x2d) {
        return 1;
    }
    return 0;
}

void DrawTextInRect(LabelTextCanvas *textCanvas, s32 left, s32 top, s32 width, s32 height, s32 color, s32 alignFlags,
                    s32 lineAlign, void *text, s32 fixedDigitsOnly, s8 fixedAdvance, s32 colorZeroIsTwo);
void DrawTextInRectNoFixedAdvance(void *textCanvas, u32 left, u32 top, u32 width, u32 height, u32 color, u32 alignFlags,
                                  u32 lineAlign, void *text);
void DrawTextInRectFixedAdvance(LabelTextCanvas *textCanvas, s32 left, s32 top, s32 width, s32 height, u32 color,
                                u32 alignFlags, u32 lineAlign, void *text, s32 fixedDigitsOnly, s8 fixedAdvance);
void DrawButtonTextInRect(void *textCanvas, u32 left, u32 top, u32 width, u32 height, u32 color, u32 alignFlags,
                          u32 lineAlign, void *text);
void MeasureAndExpandText(LabelTextCanvas *textCanvas, s32 *maxWidth, s32 *lineWidths, s32 *textHeight, void *text,
                          u16 *expandedText, s32 fixedDigitsOnly, s32 fixedAdvance);
s32 GetTextLineOffset(u32 alignFlags, s32 lineAlign, s32 rectWidth, s32 textWidth, s32 lineWidth);
void DrawTextLines(LabelTextCanvas *textCanvas, s32 textWidth, s32 *lineWidths, s32 textHeight, s32 left, s32 top,
                   s32 width, s32 height, s32 color, u32 alignFlags, s32 lineAlign, void *text, s32 fixedDigitsOnly,
                   s32 fixedAdvance, s32 colorZeroIsTwo);
void FormatMessageWithText(u16 *insertText, u16 *message, u16 *formattedText, u32 formattedCapacity);
DisplaySettings *CreateSceneDisplaySettings(void *heap);
DisplaySettings *CreateWiFiStatesDisplaySettings(void *heap);
s32 CountDecimalDigits(u32 number);
s32 FormatAsciiNumber(u32 number, u16 *buffer);
s32 FormatFullWidthNumber(u32 number, u16 *buffer);
