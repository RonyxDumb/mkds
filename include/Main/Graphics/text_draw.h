#pragma once

#include "types.h"
#include "Main/Graphics/layout_entry_angle.h" // LabelTextCanvas
#include "Main/Scene/display_settings.h" // DisplaySettings

// Tag in a run of halfwords: 0x1a, a byte (the number of bytes), a byte (1) and a halfword (0xff).
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
static inline s32 IsDigitOrDash(u16 c) {
    if ((c >= 0x30 && c <= 0x39) || (c >= 0xff10 && c <= 0xff19) || c == 0x2d) {
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
void FormatMessageWithText(u16 *insertText, u16 *message, u16 *formattedText, u32 unusedArg4);
DisplaySettings *CreateSceneDisplaySettings(void *heap);
DisplaySettings *CreateWiFiStatesDisplaySettings(void *heap);
s32 CountDecimalDigits(u32 number);
s32 FormatAsciiNumber(u32 number, u16 *buffer);
s32 FormatFullWidthNumber(u32 number, u16 *buffer);
