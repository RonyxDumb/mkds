#include "Main/Graphics/text_draw.h"
#include "Main/Scene/display_settings.h"
#include "char_canvas_text_draw.h"
#include "cpu_copy_clear_16.h"
#include "font_glyph_layout.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "01/Scene/test_scene.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void G2d_Text_SomeFn_2_from_thumb(LabelTextCanvas *textCanvas, s32 left, s32 top, s32 width, s32 height, s32 color, s32 alignFlags,
                    s32 lineAlign, void *text, s32 fixedDigitsOnly, s8 fixedAdvance, s32 colorZeroIsTwo) {
    s32 maxWidth;
    s32 textHeight;
    s32 lineWidths[20];
    u16 expandedText[500];

    G2d_Text_SomeFn_3_from_thumb(textCanvas, &maxWidth, lineWidths, &textHeight, text, expandedText, fixedDigitsOnly,
                         (s32) fixedAdvance);
    G2d_Text_SomeFn_4_from_thumb(textCanvas, maxWidth, lineWidths, textHeight, left, top, width, height, color, alignFlags, lineAlign,
                  expandedText, fixedDigitsOnly, fixedAdvance, colorZeroIsTwo);
}

void G2d_Text_SomeFn_from_thumb(void *textCanvas, u32 left, u32 top, u32 width, u32 height, u32 color, u32 alignFlags,
                                  u32 lineAlign, void *text) {
    G2d_Text_SomeFn_2_from_thumb(textCanvas, left, top, width, height, color, alignFlags, lineAlign, text, 0, -1, 0);
}

void G2d_Text_SomeFn_5_from_thumb(LabelTextCanvas *textCanvas, s32 left, s32 top, s32 width, s32 height, u32 color,
                                u32 alignFlags, u32 lineAlign, void *text, s32 fixedDigitsOnly, s8 fixedAdvance) {
    G2d_Text_SomeFn_2_from_thumb(textCanvas, left, top, width, height, color, alignFlags, lineAlign, text, fixedDigitsOnly,
                   fixedAdvance, 0);
}

// Like G2d_Text_SomeFn_from_thumb, but colour tag 0 gives colour 2; used for button text.
void G2d_Text_SomeFn_1_from_thumb(void *textCanvas, u32 left, u32 top, u32 width, u32 height, u32 color, u32 alignFlags,
                          u32 lineAlign, void *text) {
    G2d_Text_SomeFn_2_from_thumb(textCanvas, left, top, width, height, color, alignFlags, lineAlign, text, 0, -1, 1);
}

// Measures every line and copies the text with each name tag written out as characters.
void G2d_Text_SomeFn_3_from_thumb(LabelTextCanvas *textCanvas, s32 *maxWidth, s32 *lineWidths, s32 *textHeight, void *text,
                          u16 *expandedText, s32 fixedDigitsOnly, s32 fixedAdvance) {
    s32 lineHeight;
    s32 charSpacing;
    s32 lineIndex;
    s32 tagSize;
    s32 playerNameCharCount;
    s32 ownerTextCharCount;
    s32 fixedAdvanceWithSpacing;
    s32 ownerTextIndex;
    s32 playerNameIndex;
    u8 *readPointer;
    u16 playerNameChars[10];
    u16 ownerTextChars[10];
    NNSG2dFont *font;
    u16 charCode;
    s32 variant;
    s32 value;
    u32 glyphIndex;
    u16 tagTextChar;
    NNSG2dCharWidths *charWidths;
    s32 *lineWidthPointer;
    u16 *writePointer;

    lineIndex = 0;
    charSpacing = textCanvas->mCharSpacing;
    font = textCanvas->mFont;
    lineHeight = textCanvas->mLineSpacing + font->mPRes->mLinefeed;
    readPointer = text;
    writePointer = expandedText;
    *maxWidth = ~lineIndex;
    *lineWidths = lineIndex;
    *textHeight = font->mPRes->mLinefeed;
    charCode = font->mCbCharSpliter(&readPointer);
    if (charCode != 0) {
        lineWidthPointer = lineWidths;
        fixedAdvanceWithSpacing = fixedAdvance + charSpacing;
        do {
            if (charCode == 0x1a) {
                tagSize = ((TextTag *) readPointer)->mSize;
                variant = ((TextTag *) readPointer)->mVariant;
                switch (((TextTag *) readPointer)->mKind) {
                    case TEXT_TAG_KIND_NONE:
                        break;
                    case TEXT_TAG_KIND_NAME:
                        switch (variant) {
                            case TEXT_TAG_NAME_PLAYER:
                                for (value = 0; value < 10; value++) {
                                    tagTextChar = g_SaveDataHolder->mFirstBlock->mPlayerName[value];
                                    if (tagTextChar == 0) {
                                        value = 10;
                                    } else {
                                        *writePointer++ = tagTextChar;
                                        if (fixedAdvance == -1 ||
                                            (fixedDigitsOnly != 0 && !IsDigitOrDash(tagTextChar))) {
                                            glyphIndex = NFTR_GetTileIndexForCharacter(font, tagTextChar);
                                            if (glyphIndex == 0xffff) {
                                                glyphIndex = font->mPRes->mAlterCharIndex;
                                            }
                                            charWidths = NFTR_GetCharacterWidthTileEntry(font, glyphIndex);
                                            *lineWidthPointer += charWidths->mCharWidth + charSpacing;
                                        } else {
                                            *lineWidthPointer += fixedAdvanceWithSpacing;
                                        }
                                    }
                                }
                                break;
                            case TEXT_TAG_NAME_PLAYER_FIT:
                                playerNameCharCount = GetClampedString10LengthForFontIndex0_from_thumb(
                                    g_SaveDataHolder->mFirstBlock->mPlayerName, playerNameChars);
                                for (playerNameIndex = 0; playerNameIndex < playerNameCharCount; playerNameIndex++) {
                                    *writePointer++ = playerNameChars[playerNameIndex];
                                    if (fixedAdvance == -1 ||
                                        (fixedDigitsOnly != 0 && !IsDigitOrDash(playerNameChars[playerNameIndex]))) {
                                        glyphIndex = NFTR_GetTileIndexForCharacter(font, playerNameChars[playerNameIndex]);
                                        if (glyphIndex == 0xffff) {
                                            glyphIndex = font->mPRes->mAlterCharIndex;
                                        }
                                        charWidths = NFTR_GetCharacterWidthTileEntry(font, glyphIndex);
                                        *lineWidthPointer += charWidths->mCharWidth + charSpacing;
                                    } else {
                                        *lineWidthPointer += fixedAdvanceWithSpacing;
                                    }
                                }
                            case TEXT_TAG_NAME_OWNER_TEXT:
                                for (value = 0; value < 10; value++) {
                                    tagTextChar = g_GlobalP->mOwnerText[value];
                                    if (tagTextChar == 0) {
                                        value = 10;
                                    } else {
                                        *writePointer++ = tagTextChar;
                                        if (fixedAdvance == -1 ||
                                            (fixedDigitsOnly != 0 && !IsDigitOrDash(tagTextChar))) {
                                            glyphIndex = NFTR_GetTileIndexForCharacter(font, tagTextChar);
                                            if (glyphIndex == 0xffff) {
                                                glyphIndex = font->mPRes->mAlterCharIndex;
                                            }
                                            charWidths = NFTR_GetCharacterWidthTileEntry(font, glyphIndex);
                                            *lineWidthPointer += charWidths->mCharWidth + charSpacing;
                                        } else {
                                            *lineWidthPointer += fixedAdvanceWithSpacing;
                                        }
                                    }
                                }
                                break;
                            case TEXT_TAG_NAME_OWNER_TEXT_FIT:
                                ownerTextCharCount =
                                    GetClampedString10LengthForFontIndex0_from_thumb(g_GlobalP->mOwnerText, ownerTextChars);
                                for (ownerTextIndex = 0; ownerTextIndex < ownerTextCharCount; ownerTextIndex++) {
                                    *writePointer++ = ownerTextChars[ownerTextIndex];
                                    if (fixedAdvance == -1 ||
                                        (fixedDigitsOnly != 0 && !IsDigitOrDash(ownerTextChars[ownerTextIndex]))) {
                                        glyphIndex = NFTR_GetTileIndexForCharacter(font, ownerTextChars[ownerTextIndex]);
                                        if (glyphIndex == 0xffff) {
                                            glyphIndex = font->mPRes->mAlterCharIndex;
                                        }
                                        charWidths = NFTR_GetCharacterWidthTileEntry(font, glyphIndex);
                                        *lineWidthPointer += charWidths->mCharWidth + charSpacing;
                                    } else {
                                        *lineWidthPointer += fixedAdvanceWithSpacing;
                                    }
                                }
                                break;
                        }
                        break;
                    case TEXT_TAG_KIND_KEEP:
                        if (variant == 0) {
                            Mem_CpuCopy8(readPointer - 2, writePointer, tagSize);
                            writePointer += tagSize >> 1;
                        }
                        break;
                }
                readPointer = readPointer + tagSize - 2;
            } else {
                *writePointer++ = charCode;
                if (charCode == 0xa) {
                    *textHeight += lineHeight;
                    if (*maxWidth < *lineWidthPointer) {
                        *maxWidth = *lineWidthPointer;
                    }
                    lineWidthPointer++;
                    lineIndex++;
                    *lineWidthPointer = 0;
                } else {
                    value = charSpacing;
                    if (*(u16 *) readPointer == 0 || *(u16 *) readPointer == 0xa) {
                        value = 0;
                    }
                    if (fixedAdvance == -1 || (fixedDigitsOnly != 0 && !IsDigitOrDash(charCode))) {
                        glyphIndex = NFTR_GetTileIndexForCharacter(font, charCode);
                        if (glyphIndex == 0xffff) {
                            glyphIndex = font->mPRes->mAlterCharIndex;
                        }
                        charWidths = NFTR_GetCharacterWidthTileEntry(font, glyphIndex);
                        *lineWidthPointer += charWidths->mCharWidth + value;
                    } else {
                        *lineWidthPointer += fixedAdvance + value;
                    }
                }
            }
        } while ((charCode = font->mCbCharSpliter(&readPointer)) != 0);
    }
    *writePointer = 0;
    if (*maxWidth < lineWidths[lineIndex]) {
        *maxWidth = lineWidths[lineIndex];
    }
}

s32 GetTextLineOffset(u32 alignFlags, s32 lineAlign, s32 rectWidth, s32 textWidth, s32 lineWidth) {
    s32 offset;

    offset = 0;
    if (alignFlags & 0x400) {
        offset += (rectWidth - textWidth) >> 1;
    } else if (alignFlags & 0x800) {
        offset += rectWidth - textWidth;
    }
    if (lineAlign == 1) {
        offset += (textWidth - lineWidth) >> 1;
    } else if (lineAlign == 2) {
        offset += textWidth - lineWidth;
    }
    return offset;
}

void G2d_Text_SomeFn_4_from_thumb(LabelTextCanvas *textCanvas, s32 textWidth, s32 *lineWidths, s32 textHeight, s32 left, s32 top,
                   s32 width, s32 height, s32 color, u32 alignFlags, s32 lineAlign, void *text, s32 fixedDigitsOnly,
                   s32 fixedAdvance, s32 colorZeroIsTwo) {
    s32 cursorX;
    s32 cursorY;
    s32 lineAdvance;
    s32 charSpacing;
    NNSG2dFont *font;
    s32 bottom;
    s32 right;
    NNSG2dCharWidths *charWidths;
    u16 charCode;
    u8 tagSize;
    u16 variant;
    u8 kind;
    u8 colorValue;
    u32 glyphIndex;
    u8 *readPointer;

    cursorX = left;
    cursorY = top;
    charSpacing = textCanvas->mCharSpacing;
    font = textCanvas->mFont;
    lineAdvance = textCanvas->mLineSpacing + font->mPRes->mLinefeed;
    readPointer = text;
    cursorX += GetTextLineOffset(alignFlags, lineAlign, width, textWidth, *lineWidths);
    if (cursorX < 0) {
        return;
    }
    if (alignFlags & 0x80) {
        cursorY += (height - textHeight) >> 1;
    } else if (alignFlags & 0x100) {
        cursorY += height - textHeight;
    }
    if (cursorY < 0) {
        return;
    }
    charCode = font->mCbCharSpliter(&readPointer);
    if (charCode == 0) {
        return;
    }
    bottom = top + height;
    right = left + width;
    do {
        if (charCode == 0x1a) {
            tagSize = ((TextTag *) readPointer)->mSize;
            variant = ((TextTag *) readPointer)->mVariant;
            kind = ((TextTag *) readPointer)->mKind;
            if (kind == 0xff && variant == 0) {
                colorValue = ((TextTag *) readPointer)->mColorValue;
                if (colorZeroIsTwo != 0) {
                    if (colorValue == 0) {
                        color = 2;
                    } else {
                        color = colorValue * 2 + 1;
                    }
                } else {
                    color = colorValue * 2 + 1;
                }
            }
            readPointer = readPointer + tagSize - 2;
        } else if (charCode == 0xa) {
            cursorY += lineAdvance;
            lineWidths++;
            if (cursorY >= bottom) {
                return;
            }
            cursorX = left + GetTextLineOffset(alignFlags, lineAlign, width, textWidth, *lineWidths);
            if (cursorX < 0) {
                return;
            }
        } else {
            if (fixedAdvance == -1 || (fixedDigitsOnly != 0 && !IsDigitOrDash(charCode))) {
                cursorX += G2d_Sprite_MaybePutChar(textCanvas->mCharCanvas, textCanvas->mFont, cursorX, cursorY,
                                                     color, charCode);
            } else {
                glyphIndex = NFTR_GetTileIndexForCharacter(font, charCode);
                if (glyphIndex == 0xffff) {
                    glyphIndex = font->mPRes->mAlterCharIndex;
                }
                charWidths = NFTR_GetCharacterWidthTileEntry(font, glyphIndex);
                cursorX += (fixedAdvance - charWidths->mCharWidth) >> 1;
                G2d_Sprite_MaybePutChar(textCanvas->mCharCanvas, textCanvas->mFont, cursorX, cursorY, color,
                                          charCode);
                cursorX += fixedAdvance - ((fixedAdvance - charWidths->mCharWidth) >> 1);
            }
            if (cursorX > right) {
                return;
            }
            cursorX += charSpacing;
        }
    } while ((charCode = font->mCbCharSpliter(&readPointer)) != 0);
}

void MaybeHandleBmgFormatting_from_thumb(u16 *insertText, u16 *message, u16 *formattedText, u32 formattedCapacity) {
    s32 length;
    s32 tagSize;
    u16 *writePointer;
    u16 halfword;

    length = 0;
    while (*message != 0x1a || ((TextTagWithCharCode *) message)->mKind != TEXT_TAG_KIND_NAME ||
           ((TextTagWithCharCode *) message)->mVariant != TEXT_TAG_VARIANT_INSERT) {
        formattedText[length] = *message;
        length++;
        message++;
    }
    message += ((TextTagWithCharCode *) message)->mSize >> 1;
    if (*insertText != 0) {
        writePointer = formattedText + length;
        do {
            *writePointer++ = ((TextTagWithCharCode *) insertText)->mCharCode;
            length++;
            insertText++;
        } while (*insertText != 0);
    }
    while ((halfword = *message) != 0) {
        if (halfword == 0x1a) {
            tagSize = ((TextTagWithCharCode *) message)->mSize;
            CopyMemory16(message, formattedText + length, tagSize);
            message += tagSize >> 1;
            length += tagSize >> 1;
        } else {
            formattedText[length] = halfword;
            length++;
            message++;
        }
    }
    formattedText[length] = 0;
}

DisplaySettings *CreateLoadSomeDisplayConfig_from_thumb(void *heap) {
    DisplaySettingsDesc desc = {1, 0x12, 0x18, 1, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 4, 0x100, 0, 0, 8, 0};
    DisplaySettings *displaySettings;

    displaySettings = CreateDisplayConfig(heap, &desc);
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, 0, 0, 0, 0, 0x12, 2, 0);
    DisplayEngineConfig_SetBg3Config(&displaySettings->mSubBgRecords, 1, 0, 0, 0, 0x10, 4);
    SetGlobalDisplayConfig(displaySettings);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) |
                     REG_GX_DISPCNT_OBJMAP_CH_MASK;
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) |
        REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK;
    return displaySettings;
}

DisplaySettings *CreateWiFiStatesDisplaySettings(void *heap) {
    DisplaySettingsDesc desc = {1, 0x13, 0x18, 1, 0, 1, 0, 4, 0x60, 0, 0, 3, 0x10, 0, 0x80, 0x100, 0, 0, 8, 0};
    DisplaySettings *displaySettings;

    displaySettings = CreateDisplayConfig(heap, &desc);
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, 0, 0, 0, 0, 0x12, 2, 0);
    DisplayEngineConfig_SetBg3Config(&displaySettings->mSubBgRecords, 1, 0, 0, 0, 0xf, 0);
    SetGlobalDisplayConfig(displaySettings);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) |
                     REG_GX_DISPCNT_OBJMAP_CH_MASK;
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) |
        REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK;
    return displaySettings;
}

s32 CountDecimalDigits(u32 number) {
    s32 digitIndex;
    s32 digitCount;

    digitCount = 1;
    for (digitIndex = 0; digitIndex < 10; digitIndex++) {
        number = number / 10;
        if (number == 0) {
            break;
        }
        digitCount++;
    }
    return digitCount;
}

s32 FormatIntegerInString16_from_thumb(u32 number, u16 *buffer) {
    s32 digitCount;
    s32 digitIndex;
    digitCount = CountDecimalDigits(number);
    for (digitIndex = 0; digitIndex < digitCount; digitIndex++) {
        *(buffer + digitCount - digitIndex - 1) = (u16) (number % 10) + 0x30;
        number = number / 10;
    }
    buffer[digitCount] = 0;
    return digitCount;
}

s32 FormatFullWidthNumber(u32 number, u16 *buffer) {
    s32 digitCount;
    s32 digitIndex;
    digitCount = CountDecimalDigits(number);
    for (digitIndex = 0; digitIndex < digitCount; digitIndex++) {
        *(buffer + digitCount - digitIndex - 1) = (u16) (number % 10) + 0xff10;
        number = number / 10;
    }
    buffer[digitCount] = 0;
    return digitCount;
}

#pragma thumb off
