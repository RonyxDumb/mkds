#include "Main/Menu/keyboard_keys.h"
#include "reset_interrupts_halt.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "char_canvas_text_draw.h"
#include "cpu_copy_fill.h"
#include "touch_panel_sampling.h"
#include "cpu_copy_clear_16.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/iron_ball_kart.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "arena_cache_init.h"
#include "vram_load_2d_graphics.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/System/result_archive_path.h"
#include "Main/Sound/sound_seq.h"
#include "sound_archive_load_result.h"
#include "Main/System/input_slots.h"
#include "sound_player_control.h"
#include "registers.h"
#include "model_texture_bind.h"
#include "wide_string_functions.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

s32 gKeyboardOffsetX;
s32 gKeyboardOffsetY;
u16 *gCharTablePair2[2];
u16 *gCharTablePair1[2];
u16 *gCharTablePair3[2];
KeyboardCanvas gKeyboardCanvas;

const u16 gKeyboardLayoutRectCounts[6] = {0xd, 0x3b, 0x32, 0x37, 0x3a, 0x3a};
const KeyboardCursorTargets gKeyboardCursorTargets[6] = {
    {0x30, 0x37, 8, 0x39},    {0x305d, 0x3055, 0xff1f, 0x3084}, {0x60, 0x34, 0x5b, 0x39},
    {0xa1, 0xe4, 0xa3, 0xec}, {0xff0f, 0x2033, 0x2122, 0x40},   {0xe01c, 0x34, 0x25b2, 0x39},
};
KeyboardKeys g_Global78Sub_2;
s32 gKeyboardWrapMargin = 0x20;
u16 gKeyboardInputMasks[3] = {1, 2, 0x400};
u16 *gCharTables[4] = {gCharTablePairFirst, gCharTablePair1Second, gCharTablePair2Second, gCharTablePair3Second};
u16 gCharTablePairFirst[60] = {
    0x3042, 0x3044, 0x3046, 0x3048, 0x304a, 0x304b, 0x304d, 0x304f, 0x3051, 0x3053, 0x3055, 0x3057,
    0x3059, 0x305b, 0x305d, 0x305f, 0x3061, 0x3064, 0x3066, 0x3068, 0x306f, 0x3072, 0x3075, 0x3078,
    0x307b, 0x3084, 0x3086, 0x3088, 0x308f, 0x30a2, 0x30a4, 0x30a6, 0x30a8, 0x30aa, 0x30ab, 0x30ad,
    0x30af, 0x30b1, 0x30b3, 0x30b5, 0x30b7, 0x30b9, 0x30bb, 0x30bd, 0x30bf, 0x30c1, 0x30c4, 0x30c6,
    0x30c8, 0x30cf, 0x30d2, 0x30d5, 0x30d8, 0x30db, 0x30e4, 0x30e6, 0x30e8, 0x30ef, 0,      0,
};
u16 gCharTablePair1Second[60] = {
    0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x304c, 0x304e, 0x3050, 0x3052, 0x3054, 0x3056, 0x3058,
    0x305a, 0x305c, 0x305e, 0x3060, 0x3062, 0x3065, 0x3067, 0x3069, 0x3070, 0x3073, 0x3076, 0x3079,
    0x307c, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x30f4, 0x3000, 0x3000, 0x30ac, 0x30ae,
    0x30b0, 0x30b2, 0x30b4, 0x30b6, 0x30b8, 0x30ba, 0x30bc, 0x30be, 0x30c0, 0x30c2, 0x30c5, 0x30c7,
    0x30c9, 0x30d0, 0x30d3, 0x30d6, 0x30d9, 0x30dc, 0x3000, 0x3000, 0x3000, 0x3000, 0,      0,
};
u16 gCharTablePair2Second[60] = {
    0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000,
    0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3071, 0x3074, 0x3077, 0x307a,
    0x307d, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000,
    0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000,
    0x3000, 0x30d1, 0x30d4, 0x30d7, 0x30da, 0x30dd, 0x3000, 0x3000, 0x3000, 0x3000, 0,      0,
};
u16 gCharTablePair3Second[60] = {
    0x3041, 0x3043, 0x3045, 0x3047, 0x3049, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000,
    0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3063, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000,
    0x3000, 0x3083, 0x3085, 0x3087, 0x308e, 0x30a1, 0x30a3, 0x30a5, 0x30a7, 0x30a9, 0x30f5, 0x3000,
    0x3000, 0x30f6, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x30c3, 0x3000,
    0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x30e3, 0x30e5, 0x30e7, 0x30ee, 0,      0,
};

#pragma thumb on

void SplitBytesIntoNibbles(u8 *bytes, u8 *nibbles, s32 size) {
    s32 byteIndex;
    s32 byteCount;

    byteCount = size * size / 2;
    for (byteIndex = 0; byteIndex < byteCount; byteIndex++) {
        nibbles[byteIndex * 2] = bytes[byteIndex] & 0xf;
        nibbles[byteIndex * 2 + 1] = (bytes[byteIndex] >> 4) & 0xf;
    }
}

s32 GetKeyboardLastCharIndex(void) {
    s32 lastCharIndex;
    KeyboardTextEntry *keyboardTextEntry;
    s32 textIndex;
    s32 index;

    lastCharIndex = 0;
    keyboardTextEntry = g_Global78;
    textIndex = keyboardTextEntry->mTextIndex;
    index = keyboardTextEntry->mTextLimit - 1;
    if (textIndex == index && keyboardTextEntry->mText[textIndex] >= KEYBOARD_VALUE_FIRST_CHARACTER) {
        lastCharIndex = textIndex;
    } else {
        index = textIndex - 1;
        if (index >= 0 && keyboardTextEntry->mText[index] >= KEYBOARD_VALUE_FIRST_CHARACTER) {
            lastCharIndex = index;
        }
    }
    return lastCharIndex;
}

s32 KeyboardKeyCallback(u32 keyValue, s32 newPress) {
    s32 result;
    s32 lastCharIndex;
    u16 convertedChar;
    u16 currentChar;

    result = 0;
    lastCharIndex = GetKeyboardLastCharIndex();
    switch ((s32) keyValue) {
        case KEYBOARD_VALUE_HIRAGANA:
            if (GetKeyboardChosenKeyValue() != KEYBOARD_VALUE_HIRAGANA) {
                PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1e7);
            } else {
                PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case KEYBOARD_VALUE_KATAKANA:
            if (GetKeyboardChosenKeyValue() != KEYBOARD_VALUE_KATAKANA) {
                PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1e8);
            } else {
                PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case KEYBOARD_VALUE_CONVERT_FIRST:
            convertedChar = ConvertCharPair1(g_Global78->mText[lastCharIndex]);
            currentChar = g_Global78->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case KEYBOARD_VALUE_CONVERT_SECOND:
            convertedChar = ConvertCharPair2(g_Global78->mText[lastCharIndex]);
            currentChar = g_Global78->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case KEYBOARD_VALUE_CONVERT_THIRD:
            convertedChar = ConvertCharPair3(g_Global78->mText[lastCharIndex]);
            currentChar = g_Global78->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case KEYBOARD_VALUE_SHIFT:
        case KEYBOARD_VALUE_CAPS:
            PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1eb);
            break;
        case KEYBOARD_VALUE_SPACE:
        case KEYBOARD_VALUE_IDEOGRAPHIC_SPACE:
            if (newPress != 0) {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1ea);
            }
            break;
        case KEYBOARD_VALUE_DELETE:
            if (newPress != 0) {
                PlaySseqFromSarc(&gSharedSeqHandle, result, 0x1e9);
            }
            break;
        default:
            if (newPress != 0 && keyValue >= KEYBOARD_VALUE_FIRST_CHARACTER) {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1e6);
            }
            break;
    }
    return result;
}

u16 KeyboardCursorCallback(s32 rectValue, u16 keys) {
    u16 nextRectValue;

    nextRectValue = 0;
    switch (rectValue) {
        case KEYBOARD_VALUE_FIRST_BUTTON:
            if ((keys & 0x20) != 0 || (keys & 0x10) != 0) {
                nextRectValue = 2;
            } else if ((keys & 0x40) != 0) {
                nextRectValue = gKeyboardCursorTargets[g_Global78->mLayoutIndex].mUpFromRect1;
            } else if ((keys & 0x80) != 0) {
                nextRectValue = gKeyboardCursorTargets[g_Global78->mLayoutIndex].mDownFromRect1;
            }
            break;
        case KEYBOARD_VALUE_SECOND_BUTTON:
            if ((keys & 0x20) != 0 || (keys & 0x10) != 0) {
                nextRectValue = 1;
            } else if ((keys & 0x40) != 0) {
                nextRectValue = gKeyboardCursorTargets[g_Global78->mLayoutIndex].mUpFromRect2;
            } else if ((keys & 0x80) != 0) {
                nextRectValue = gKeyboardCursorTargets[g_Global78->mLayoutIndex].mDownFromRect2;
            }
            break;
    }
    MaybePlaySomeSseqFromSarc0(0x1e4);
    return nextRectValue;
}

void CreateGlobal78_from_thumb(s32 screenMapWidth, s32 screenMapHeight, s32 textCapacity) {
    KeyboardTextEntry *keyboardTextEntry;

    g_Global78 = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(KeyboardTextEntry));
    g_Global78->mTextCapacity = textCapacity;
    g_Global78->mTextLimit = textCapacity;
    g_Global78->mTextIndex = 0;
    g_Global78->mTextIndexCopy = 0;
    g_Global78->mText = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), (textCapacity + 1) * 2);
    g_Global78->mBg2ScrSize = screenMapHeight * (screenMapWidth * 2);
    g_Global78->mBg2Scr = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), g_Global78->mBg2ScrSize);
    g_Global78->mBg2CharSize = KEYBOARD_BG2_CHAR_SIZE;
    g_Global78->mBg2Char =
        Mem_AllocateHeapAligned(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), g_Global78->mBg2CharSize, HEAP_ALIGN_CACHE_LINE);
    keyboardTextEntry = g_Global78;
    InitKeyboardKeysAndCanvas(GetLoadedFont_from_thumb(0), keyboardTextEntry->mBg2Char, keyboardTextEntry->mBg2Scr,
                              screenMapWidth, screenMapHeight, 0);
    SetKeyboardCursorCallback(KeyboardCursorCallback);
    SetKeyboardKeyCallback(KeyboardKeyCallback);
    SetKeyboardScreenMapTopBits(0);
    SetKeyboardGlyphColor(1);
    g_Global78->mOffsetX = 0;
    g_Global78->mOffsetY = 0;
    g_Global78->mButton0X0 = 0x23;
    g_Global78->mButton0Y0 = 0x7a;
    g_Global78->mButton0X1 = 0x7d;
    g_Global78->mButton0Y1 = 0x8e;
    g_Global78->mButton1X0 = 0x83;
    g_Global78->mButton1Y0 = 0x7a;
    g_Global78->mButton1X1 = 0xdd;
    g_Global78->mButton1Y1 = 0x8e;
    Gfx_ReadCharGraphics(&g_Global78->mNcgrs[0], FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_10key.NCGR"));
    Gfx_ReadCharGraphics(&g_Global78->mNcgrs[2], FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_ascii.NCGR"));
    Gfx_ReadCharGraphics(&g_Global78->mNcgrs[1], FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_jp.NCGR"));
    Gfx_ReadCharGraphics(&g_Global78->mNcgrs[3], FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_euro.NCGR"));
    Gfx_ReadCharGraphics(&g_Global78->mNcgrs[4], FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_pict.NCGR"));
    Gfx_ReadCharGraphicsRelative(&g_Global78->mNcgrs[5], FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_pict.NCGR"));
    g_Global78->mKbds[0] = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("10key.kbd");
    g_Global78->mKbds[2] = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ascii.kbd");
    g_Global78->mKbds[1] = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("jp.kbd");
    g_Global78->mKbds[3] = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("euro.kbd");
    g_Global78->mKbds[4] = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("picto.kbd");
    g_Global78->mKbds[5] = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("picto.kbd");
    g_AsciiKbdmap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ascii.kbdmap");
    gKbdmapAsciiCaps = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ascii_caps.kbdmap");
    gKbdmapAsciiShift = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("ascii_shift.kbdmap");
    g_HiraganaMap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("hiragana.kbdmap");
    g_HiraganaDakutenMap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("hiragana_dakuten.kbdmap");
    g_HiraganaHandakuMap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("hiragana_handaku.kbdmap");
    g_HiraganaSmallMap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("hiragana_small.kbdmap");
    g_KatakanaMap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("katakana.kbdmap");
    g_KatakanaDakutenMap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("katakana_dakuten.kbdmap");
    g_KatakanaHandakuMap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("katakana_handaku.kbdmap");
    g_KatakanaSmallMap = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("katakana_small.kbdmap");
    g_Other1Map = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("other1.kbdmap");
    g_Other2Map = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("other2.kbdmap");
    g_Other3Map = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("other3.kbdmap");
    SetupKeyboardInputMasks(1, 2, 0x400);
}

void AdvanceKeyboardTextEntry(void) {
    s32 lastCharIndex;
    InputSlotIndex inputSlotIndex;
    KeyboardTextEntry *keyboardTextEntry;
    u16 convertedChar;

    lastCharIndex = GetKeyboardLastCharIndex();
    PollKeyboard();
    GetKeyboardKeyValue();
    inputSlotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    if ((u16) (g_GlobalCYT[inputSlotIndex].mPressedBits & PAD_KEY_START) != 0) {
        if (GetKeyboardCursorValueWrapper() != 1) {
            MoveKeyboardCursorToValueWrapper(1);
        }
    } else if (GetKeyboardKeyValue() == KEYBOARD_VALUE_DELETE) {
        g_Global78->mTextIndexCopy = g_Global78->mTextIndex;
        keyboardTextEntry = g_Global78;
        if (keyboardTextEntry->mTextIndex != 0) {
            if (keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] == 0) {
                keyboardTextEntry->mTextIndex--;
            }
            g_Global78->mText[g_Global78->mTextIndex] = 0;
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1e3);
        }
    } else if (GetKeyboardKeyValue() >= KEYBOARD_VALUE_FIRST_CHARACTER) {
        g_Global78->mTextIndexCopy = g_Global78->mTextIndex;
        keyboardTextEntry = g_Global78;
        if (keyboardTextEntry->mTextIndex < keyboardTextEntry->mTextLimit) {
            if (keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] != GetKeyboardKeyValue()) {
                keyboardTextEntry = g_Global78;
                keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] = GetKeyboardKeyValue();
                g_Global78->mText[g_Global78->mTextIndex + 1] = 0;
                if (g_Global78->mTextIndex < g_Global78->mTextLimit - 1) {
                    g_Global78->mTextIndex++;
                }
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1e2);
            }
        }
    } else if (GetKeyboardKeyValue() == KEYBOARD_VALUE_CONVERT_FIRST) {
        convertedChar = ConvertCharPair1(g_Global78->mText[lastCharIndex]);
        if (convertedChar != g_Global78->mText[lastCharIndex]) {
            g_Global78->mText[lastCharIndex] = convertedChar;
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == KEYBOARD_VALUE_CONVERT_SECOND) {
        convertedChar = ConvertCharPair2(g_Global78->mText[lastCharIndex]);
        if (convertedChar != g_Global78->mText[lastCharIndex]) {
            g_Global78->mText[lastCharIndex] = convertedChar;
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == KEYBOARD_VALUE_CONVERT_THIRD) {
        convertedChar = ConvertCharPair3(g_Global78->mText[lastCharIndex]);
        if (convertedChar != g_Global78->mText[lastCharIndex]) {
            g_Global78->mText[lastCharIndex] = convertedChar;
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == KEYBOARD_VALUE_CYCLE_CHAR_TABLES) {
        convertedChar = CycleCharTables(g_Global78->mText[lastCharIndex]);
        if (convertedChar != g_Global78->mText[lastCharIndex]) {
            g_Global78->mText[lastCharIndex] = convertedChar;
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1ec);
        } else {
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1ed);
        }
    }
    GetKeyboardKeyValue();
}

#pragma thumb off

#pragma thumb on

void UploadKeyboardBg2Data(void) {
    Arm_FlushRange(g_Global78->mBg2Scr, g_Global78->mBg2ScrSize);
    TEQSub_Fn26Impl_Fn28Impl(g_Global78->mBg2Scr, 0, g_Global78->mBg2ScrSize);
    Arm_FlushRange(g_Global78->mBg2Char, g_Global78->mBg2CharSize);
    CopyBgData_Bg2_Bottom(g_Global78->mBg2Char, 0, g_Global78->mBg2CharSize);
}

#pragma thumb off

#pragma thumb on
void SetKeyboardScreenMapTopBitsWrapper(u32 topBits) {
    u32 topBitsCopy = topBits;
    u32 unusedValue;
    SetKeyboardScreenMapTopBits(topBitsCopy);
}
#pragma thumb off

#pragma thumb on

void SelectKeyboardLayout(u32 layoutIndex) {
    switch (layoutIndex) {
        case KEYBOARD_LAYOUT_DIGITS:
            SetupKeyboardLayoutOther3(g_Global78->mKbds[layoutIndex], g_Global78->mNcgrs[layoutIndex],
                                      gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case KEYBOARD_LAYOUT_KANA:
            SetupKeyboardLayoutHiragana(g_Global78->mKbds[layoutIndex], g_Global78->mNcgrs[layoutIndex],
                                        gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case KEYBOARD_LAYOUT_ASCII:
            SetupKeyboardLayoutAscii(g_Global78->mKbds[layoutIndex], g_Global78->mNcgrs[layoutIndex],
                                     gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case KEYBOARD_LAYOUT_EURO:
            SetupKeyboardLayoutOther1(g_Global78->mKbds[layoutIndex], g_Global78->mNcgrs[layoutIndex],
                                      gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case KEYBOARD_LAYOUT_PICTOGRAMS:
            SetupKeyboardLayoutOther2(g_Global78->mKbds[layoutIndex], g_Global78->mNcgrs[layoutIndex],
                                      gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case KEYBOARD_LAYOUT_PICTOGRAMS_EXTRA:
            SetupKeyboardLayoutOther3(g_Global78->mKbds[layoutIndex], g_Global78->mNcgrs[layoutIndex],
                                      gKeyboardLayoutRectCounts[layoutIndex]);
            break;
    }
    g_Global78->mLayoutIndex = layoutIndex;
}

void SetKeyboardOffset(s32 offsetX, s32 offsetY) {
    g_Global78->mOffsetX = offsetX;
    g_Global78->mOffsetY = offsetY;
    StoreKeyboardOffset(g_Global78->mOffsetX, g_Global78->mOffsetY);
    reg_G2S_DB_BG2OFS = (-g_Global78->mOffsetX & 0x1ff) | ((-g_Global78->mOffsetY << 16) & 0x1ff0000);
    SetKeyboardButton0Rect(g_Global78->mOffsetX + g_Global78->mButton0X0,
                           g_Global78->mOffsetY + g_Global78->mButton0Y0,
                           g_Global78->mOffsetX + g_Global78->mButton0X1,
                           g_Global78->mOffsetY + g_Global78->mButton0Y1);
    SetKeyboardButton1Rect(g_Global78->mOffsetX + g_Global78->mButton1X0,
                           g_Global78->mOffsetY + g_Global78->mButton1Y0,
                           g_Global78->mOffsetX + g_Global78->mButton1X1,
                           g_Global78->mOffsetY + g_Global78->mButton1Y1);
}

#pragma thumb off

#pragma thumb on

void SetKeyboardButton0Corners(u32 startX, u32 startY, u32 endX, u32 endY) {
    KeyboardTextEntry **keyboardTextEntryPointer;
    KeyboardTextEntry *keyboardTextEntry;
    keyboardTextEntryPointer = &g_Global78;
    g_Global78->mButton0X0 = startX;
    (*keyboardTextEntryPointer)->mButton0Y0 = startY;
    (*keyboardTextEntryPointer)->mButton0X1 = endX;
    (*keyboardTextEntryPointer)->mButton0Y1 = endY;
    keyboardTextEntry = *keyboardTextEntryPointer;
    SetKeyboardButton0Rect(keyboardTextEntry->mOffsetX + keyboardTextEntry->mButton0X0,
                           keyboardTextEntry->mOffsetY + keyboardTextEntry->mButton0Y0,
                           keyboardTextEntry->mOffsetX + keyboardTextEntry->mButton0X1,
                           keyboardTextEntry->mOffsetY + keyboardTextEntry->mButton0Y1);
}

void SetKeyboardButton1Corners(u32 startX, u32 startY, u32 endX, u32 endY) {
    KeyboardTextEntry **keyboardTextEntryPointer;
    KeyboardTextEntry *keyboardTextEntry;
    keyboardTextEntryPointer = &g_Global78;
    g_Global78->mButton1X0 = startX;
    (*keyboardTextEntryPointer)->mButton1Y0 = startY;
    (*keyboardTextEntryPointer)->mButton1X1 = endX;
    (*keyboardTextEntryPointer)->mButton1Y1 = endY;
    keyboardTextEntry = *keyboardTextEntryPointer;
    SetKeyboardButton1Rect(keyboardTextEntry->mOffsetX + keyboardTextEntry->mButton1X0,
                           keyboardTextEntry->mOffsetY + keyboardTextEntry->mButton1Y0,
                           keyboardTextEntry->mOffsetX + keyboardTextEntry->mButton1X1,
                           keyboardTextEntry->mOffsetY + keyboardTextEntry->mButton1Y1);
}

#pragma thumb off

#pragma thumb on

void MoveKeyboardCursorToValueWrapper(u16 value) {
    MoveKeyboardCursorToValue(value);
}

u32 GetKeyboardCursorValueWrapper(void) {
    return GetKeyboardCursorValue();
}

#pragma thumb off

#pragma thumb on

void GetKeyboardCursorBoundsRelative(s32 *left, s32 *top, s32 *right, s32 *bottom) {
    s32 value;
    GetKeyboardCursorRectBounds(left, top, right, bottom);
    *left = *left - g_Global78->mOffsetX;
    *top = *top - g_Global78->mOffsetY;
    *right = *right - g_Global78->mOffsetX;
    *bottom = *bottom - g_Global78->mOffsetY;
    value = *left;
    if (value < 0) {
        value += 0x100;
    }
    *left = value;
    value = *top;
    if (value < 0) {
        value += 0x100;
    }
    *top = value;
    value = *right;
    if (value < 0) {
        value += 0x100;
    }
    *right = value;
    value = *bottom;
    if (value < 0) {
        value += 0x100;
    }
    *bottom = value;
}

#pragma thumb off

#pragma thumb on

void SetKeyboardText(const u16 *text) {
    s32 charIndex;

    for (charIndex = 0; charIndex < g_Global78->mTextCapacity; charIndex++) {
        g_Global78->mText[charIndex] = 0;
    }
    for (charIndex = 0; charIndex < g_Global78->mTextLimit; charIndex++) {
        g_Global78->mText[charIndex] = *text;
        if (*text == 0) {
            g_Global78->mTextIndex = charIndex;
            g_Global78->mTextIndexCopy = g_Global78->mTextIndex;
            return;
        }
        text++;
    }
    g_Global78->mTextIndex = g_Global78->mTextLimit - 1;
    g_Global78->mTextIndexCopy = g_Global78->mTextIndex;
    g_Global78->mText[g_Global78->mTextLimit] = 0;
}

#pragma thumb off

#pragma thumb on

u16 *GetKeyboardText(void) {
    return g_Global78->mText;
}

#pragma thumb off

#pragma thumb on

void SetKeyboardTextLimit(u16 textLimit) {
    g_Global78->mTextLimit = textLimit;
    if (g_Global78->mTextIndex >= g_Global78->mTextLimit - 1) {
        g_Global78->mTextIndex = g_Global78->mTextLimit - 1;
        g_Global78->mTextIndexCopy = g_Global78->mTextIndex;
        g_Global78->mText[g_Global78->mTextLimit] = 0;
    }
}

#pragma thumb off

#pragma thumb on

u16 GetKeyboardTextIndex(void) {
    return g_Global78->mTextIndex;
}

#pragma thumb off

#pragma thumb on

void ClearKeyboardInput(void) {
    MemFillWordsByBlock_inline(&gKeyboardInput, 0x28);
}

#pragma thumb off

#pragma thumb on

void InitKeyboardInput(void) {
    ClearKeyboardInput();
    gKeyboardInput.mTouchEnabled = TRUE;
}

#pragma thumb off

#pragma thumb on

void AdvanceKeyboardInput(u16 keys, volatile TPData touchPoint) {
    u32 changedKeys;
    u16 touch;

    changedKeys = keys ^ gKeyboardInput.mKeysDown;
    gKeyboardInput.mKeysPressed = keys & changedKeys;
    gKeyboardInput.mKeysReleased = ~keys & changedKeys;
    gKeyboardInput.mKeysDown = keys;
    if ((gKeyboardInput.mKeysDown & gKeyboardInput.mCountedKeys) != 0) {
        gKeyboardInput.mCountedKeyFrames++;
    } else {
        gKeyboardInput.mCountedKeyFrames = 0;
    }
    if (gKeyboardInput.mTouchEnabled != FALSE) {
        if (touchPoint.mValidity != 0) {
            touchPoint.mX = gKeyboardInput.mPrevSample[0];
            touchPoint.mY = gKeyboardInput.mPrevSample[1];
            touchPoint.mTouch = gKeyboardInput.mPrevSample[2];
            touchPoint.mValidity = gKeyboardInput.mPrevSample[3];
            touchPoint.mTouch = 0;
        }
        touch = touchPoint.mTouch;
        if (touch != gKeyboardInput.mPrevSample[2]) {
            gKeyboardInput.mTouchStatus = touch != 0 ? KEYBOARD_TOUCH_BEGAN : KEYBOARD_TOUCH_ENDED;
            gKeyboardInput.mTouchHeldFrames = 0;
        } else if (touch != 0) {
            gKeyboardInput.mTouchStatus = KEYBOARD_TOUCH_HELD;
            gKeyboardInput.mTouchHeldFrames++;
        } else {
            gKeyboardInput.mTouchStatus = KEYBOARD_TOUCH_IDLE;
        }
        if (touch != 0) {
            gKeyboardInput.mLastTouchX = touchPoint.mX;
            gKeyboardInput.mLastTouchY = touchPoint.mY;
        }
        gKeyboardInput.mTouchDown = touch;
        gKeyboardInput.mPrevSample[0] = touchPoint.mX;
        gKeyboardInput.mPrevSample[1] = touchPoint.mY;
        gKeyboardInput.mPrevSample[2] = touchPoint.mTouch;
        gKeyboardInput.mPrevSample[3] = touchPoint.mValidity;
    }
}

#pragma thumb off

#pragma thumb on
u32 GetKeyboardKeysPressed(u32 mask) {
    u32 value = mask;
    u32 pressedKeys;
    pressedKeys = gKeyboardInput.mKeysPressed;
    pressedKeys = (pressedKeys) & (value);
    value = (pressedKeys) + (0u);
    return value;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardKeysDown(u32 mask) {
    u32 value = mask;
    u32 downKeys;
    downKeys = gKeyboardInput.mKeysDown;
    downKeys = (downKeys) & (value);
    value = (downKeys) + (0u);
    return value;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardTouchDown(void) {
    u32 touchDown;
    touchDown = gKeyboardInput.mTouchDown;
    return touchDown;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardTouchStatus(void) {
    u32 touchStatus;
    touchStatus = gKeyboardInput.mTouchStatus;
    return touchStatus;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardLastTouchX(void) {
    u32 lastTouchX;
    lastTouchX = gKeyboardInput.mLastTouchX;
    return lastTouchX;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardLastTouchY(void) {
    u32 lastTouchY;
    lastTouchY = gKeyboardInput.mLastTouchY;
    return lastTouchY;
}
#pragma thumb off

#pragma thumb on
u32 IsKeyboardTouchEnabled(void) {
    u32 touchEnabled;
    touchEnabled = gKeyboardInput.mTouchEnabled;
    return touchEnabled;
}
#pragma thumb off

#pragma thumb on

void SetupRepeatCounterDefault(RepeatCounter *repeatCounter) {
    repeatCounter->mRepeatFrames = 0x0u;
    repeatCounter->mFired = 0x0u;
    repeatCounter->mFirstFireFrame = 0x28u;
    repeatCounter->mRepeatFireFrame = 0x2du;
}

void SetupRepeatCounter(RepeatCounter *repeatCounter, u32 firstFireFrame, u32 repeatGap) {
    repeatCounter->mRepeatFrames = 0x0u;
    repeatCounter->mFired = 0x0u;
    repeatCounter->mFirstFireFrame = firstFireFrame;
    repeatCounter->mRepeatFireFrame = ((firstFireFrame) + (repeatGap));
}

#pragma thumb off

#pragma thumb on

void AdvanceRepeatCounter(RepeatCounter *repeatCounter) {
    repeatCounter->mRepeatFrames = repeatCounter->mRepeatFrames + 1;
    if (repeatCounter->mRepeatFrames == repeatCounter->mFirstFireFrame ||
        repeatCounter->mRepeatFrames == repeatCounter->mRepeatFireFrame) {
        repeatCounter->mFired = 1;
    }
    if (repeatCounter->mRepeatFrames > repeatCounter->mRepeatFireFrame) {
        repeatCounter->mRepeatFrames = repeatCounter->mFirstFireFrame + 1;
    }
}

#pragma thumb off

#pragma thumb on

void ResetRepeatCounter(RepeatCounter *repeatCounter) {
    repeatCounter->mRepeatFrames = 0x0u;
    repeatCounter->mFired = 0x0u;
}

#pragma thumb off

#pragma thumb on

BOOL IsRepeatCounterFiring(RepeatCounter *repeatCounter) {
    if (repeatCounter->mRepeatFrames == repeatCounter->mFirstFireFrame ||
        repeatCounter->mRepeatFrames == repeatCounter->mRepeatFireFrame) {
        return TRUE;
    }
    return FALSE;
}

void SetupKeyboardKeyRepeat(u16 keyMask) {
    SetupRepeatCounterDefault(&gKeyboardKeyRepeat.mCounter);
    gKeyboardKeyRepeat.mKeyMask = keyMask;
    gKeyboardKeyRepeat.mRepeatKeys = 0;
}

void AdvanceKeyboardKeyRepeat(void) {
    if (gKeyboardKeyRepeat.mRepeatKeys == 0 && GetKeyboardKeysPressed(gKeyboardKeyRepeat.mKeyMask) != 0) {
        gKeyboardKeyRepeat.mRepeatKeys = GetKeyboardKeysPressed(gKeyboardKeyRepeat.mKeyMask);
        return;
    }
    if (GetKeyboardKeysDown(gKeyboardKeyRepeat.mRepeatKeys) != 0) {
        AdvanceRepeatCounter(&gKeyboardKeyRepeat.mCounter);
    } else {
        ResetRepeatCounter(&gKeyboardKeyRepeat.mCounter);
        gKeyboardKeyRepeat.mRepeatKeys = 0;
    }
}

u16 GetKeyboardRepeatedKeys(void) {
    u32 repeatedKeys;

    if (IsRepeatCounterFiring(&gKeyboardKeyRepeat.mCounter) != FALSE) {
        repeatedKeys = GetKeyboardKeysDown(gKeyboardKeyRepeat.mRepeatKeys);
    } else {
        repeatedKeys = 0;
    }
    return repeatedKeys;
}

u16 GetKeyboardKeysPressedOrRepeated(void) {
    if (GetKeyboardKeysPressed(0x2fff) != 0) {
        return GetKeyboardKeysPressed(0x2fff);
    }
    return GetKeyboardRepeatedKeys();
}

void AsciiLayoutCallback(KeyboardKeys *keyboardKeys) {
    switch (keyboardKeys->mKeyId) {
        case KEYBOARD_KEY_ID_MODE_FIRST:
            keyboardKeys->mToggledKeyId =
                keyboardKeys->mToggledKeyId != KEYBOARD_KEY_ID_MODE_FIRST ? KEYBOARD_KEY_ID_MODE_FIRST : 0;
            break;
        case KEYBOARD_KEY_ID_MODE_SECOND:
            keyboardKeys->mToggledKeyId =
                keyboardKeys->mToggledKeyId != KEYBOARD_KEY_ID_MODE_SECOND ? KEYBOARD_KEY_ID_MODE_SECOND : 0;
            break;
    }
    switch (keyboardKeys->mToggledKeyId) {
        case 0:
            keyboardKeys->mCharMap = g_AsciiKbdmap + 1;
            break;
        case KEYBOARD_KEY_ID_MODE_FIRST:
            keyboardKeys->mCharMap = gKbdmapAsciiShift + 1;
            break;
        case KEYBOARD_KEY_ID_MODE_SECOND:
            keyboardKeys->mCharMap = gKbdmapAsciiCaps + 1;
            break;
    }
}

void HiraganaKatakanaLayoutCallback(KeyboardKeys *keyboardKeys) {
    switch (keyboardKeys->mKeyId) {
        case KEYBOARD_KEY_ID_MODE_FIRST:
            keyboardKeys->mChosenKeyId = KEYBOARD_KEY_ID_MODE_FIRST;
            keyboardKeys->mToggledKeyId = 0;
            break;
        case KEYBOARD_KEY_ID_MODE_SECOND:
            keyboardKeys->mChosenKeyId = KEYBOARD_KEY_ID_MODE_SECOND;
            keyboardKeys->mToggledKeyId = 0;
            break;
    }
    switch (keyboardKeys->mChosenKeyId) {
        case KEYBOARD_KEY_ID_MODE_FIRST:
            if (keyboardKeys->mToggledKeyId == 0) {
                keyboardKeys->mCharMap = g_HiraganaMap + 1;
            }
            break;
        case KEYBOARD_KEY_ID_MODE_SECOND:
            if (keyboardKeys->mToggledKeyId == 0) {
                keyboardKeys->mCharMap = g_KatakanaMap + 1;
            }
            break;
    }
}

KeyboardRect *FindKeyboardRectByValue(u16 value) {
    KeyboardRect *rects;
    s32 rectIndex;
    u16 rectCount;
    u16 fixedKeyCount;
    u16 *charMap;

    if (g_Global78Sub_2.mCurrentLayout != NULL) {
        rects = g_Global78Sub_2.mCurrentLayout->mRects;
        rectCount = g_Global78Sub_2.mCurrentLayout->mRectCount;
        fixedKeyCount = g_Global78Sub_2.mCurrentLayout->mFixedKeyCount;
        charMap = g_Global78Sub_2.mCharMap;
        switch (value) {
            case 0:
                return NULL;
            case KEYBOARD_VALUE_FIRST_BUTTON:
                return &g_Global78Sub_2.mButton0Rect;
            case KEYBOARD_VALUE_SECOND_BUTTON:
                return &g_Global78Sub_2.mButton1Rect;
            case KEYBOARD_VALUE_DELETE:
                return rects;
            case 10:
                return rects + 1;
            case KEYBOARD_VALUE_SPACE:
            case KEYBOARD_VALUE_IDEOGRAPHIC_SPACE:
                return rects + 2;
        }
        for (rectIndex = 0; rectIndex < rectCount; rectIndex++) {
            if (rects[rectIndex].mWidth > 1 && rects[rectIndex].mHeight > 1 &&
                value == charMap[rects[rectIndex].mKeyId - fixedKeyCount - 1]) {
                return &rects[rectIndex];
            }
        }
    }
    return NULL;
}

s32 GetKeyboardRectValue(KeyboardRect *keyboardRect) {
    KeyboardRect *rects;
    s32 rectIndex;
    s32 rectCount;
    u16 fixedKeyCount;
    u16 *charMap;

    if (g_Global78Sub_2.mCurrentLayout != NULL) {
        rects = g_Global78Sub_2.mCurrentLayout->mRects;
        rectCount = g_Global78Sub_2.mCurrentLayout->mRectCount;
        fixedKeyCount = g_Global78Sub_2.mCurrentLayout->mFixedKeyCount;
        charMap = g_Global78Sub_2.mCharMap;
        if (keyboardRect == NULL) {
            return 0;
        }
        if (keyboardRect == &g_Global78Sub_2.mButton0Rect) {
            return 1;
        }
        if (keyboardRect == &g_Global78Sub_2.mButton1Rect) {
            return 2;
        }
        for (rectIndex = 0; rectIndex < rectCount; rectIndex++) {
            if (rects[rectIndex].mWidth > 1 && rects[rectIndex].mHeight > 1 && keyboardRect == &rects[rectIndex]) {
                switch (rectIndex) {
                    case KEYBOARD_RECT_INDEX_DELETE:
                        return 8;
                    case 1:
                        return 0xa;
                    case KEYBOARD_RECT_INDEX_SPACE:
                        return 0x20;
                }
                return charMap[rects[rectIndex].mKeyId - fixedKeyCount - 1];
            }
        }
    }
    return 0;
}

s32 GetKeyboardValueForKeyId(u32 keyId) {
    KeyboardLayout *currentLayout;
    u16 fixedKeyCount;

    currentLayout = g_Global78Sub_2.mCurrentLayout;
    if (currentLayout != NULL) {
        if (keyId == 0) {
            return 0;
        }
        fixedKeyCount = currentLayout->mFixedKeyCount;
        if (keyId <= fixedKeyCount || keyId == 0xffff) {
            if (currentLayout->mCallback == HiraganaKatakanaLayoutCallback) {
                switch ((s32) keyId) {
                    case KEYBOARD_KEY_ID_DELETE:
                        return KEYBOARD_VALUE_DELETE;
                    case 2:
                        return 0xa;
                    case KEYBOARD_KEY_ID_SPACE:
                        return KEYBOARD_VALUE_IDEOGRAPHIC_SPACE;
                    case KEYBOARD_KEY_ID_MODE_FIRST:
                        return KEYBOARD_VALUE_HIRAGANA;
                    case KEYBOARD_KEY_ID_MODE_SECOND:
                        return KEYBOARD_VALUE_KATAKANA;
                    case KEYBOARD_KEY_ID_CONVERT_FIRST:
                        return KEYBOARD_VALUE_CONVERT_FIRST;
                    case KEYBOARD_KEY_ID_CONVERT_SECOND:
                        return KEYBOARD_VALUE_CONVERT_SECOND;
                    case KEYBOARD_KEY_ID_CONVERT_THIRD:
                        return KEYBOARD_VALUE_CONVERT_THIRD;
                    case KEYBOARD_KEY_ID_CYCLE:
                        return KEYBOARD_VALUE_CYCLE_CHAR_TABLES;
                }
            } else {
                switch (keyId) {
                    case KEYBOARD_KEY_ID_DELETE:
                        return KEYBOARD_VALUE_DELETE;
                    case 2:
                        return 0xa;
                    case KEYBOARD_KEY_ID_SPACE:
                        return KEYBOARD_VALUE_SPACE;
                    case KEYBOARD_KEY_ID_MODE_FIRST:
                        return KEYBOARD_VALUE_SHIFT;
                    case KEYBOARD_KEY_ID_MODE_SECOND:
                        return KEYBOARD_VALUE_CAPS;
                }
            }
        }
        if (keyId <= 0xff && g_Global78Sub_2.mCharMap[keyId - fixedKeyCount - 1] > KEYBOARD_VALUE_SPACE) {
            return g_Global78Sub_2.mCharMap[keyId - fixedKeyCount - 1];
        }
    }
    return 0;
}

void SetupKeyboardInputMasks(u16 firstMask, u16 secondMask, u16 thirdMask) {
    gKeyboardInputMasks[0] = firstMask;
    gKeyboardInputMasks[1] = secondMask;
    gKeyboardInputMasks[2] = thirdMask;
    SetupKeyboardKeyRepeat(gKeyboardInputMasks[2] | (gKeyboardInputMasks[0] | 0xf0 | gKeyboardInputMasks[1]));
}

#pragma thumb off

#pragma thumb on
void StoreKeyboardOffset(s32 offsetX, s32 offsetY) {
    gKeyboardOffsetX = offsetX;
    gKeyboardOffsetY = offsetY;
}
#pragma thumb off

#pragma thumb on

void GetKeyboardCursorRectBounds(s32 *left, s32 *top, s32 *right, s32 *bottom) {
    if (g_Global78Sub_2.mCursorRect != NULL && left != NULL && top != NULL && right != NULL && bottom != NULL) {
        *left = g_Global78Sub_2.mCursorRect->mX;
        *top = g_Global78Sub_2.mCursorRect->mY;
        *right = g_Global78Sub_2.mCursorRect->mX + g_Global78Sub_2.mCursorRect->mWidth;
        *bottom = g_Global78Sub_2.mCursorRect->mY + g_Global78Sub_2.mCursorRect->mHeight;
        if (g_Global78Sub_2.mCursorRect->mKeyId <= KEYBOARD_KEY_ID_LAST_KEY) {
            *left = *left + gKeyboardOffsetX;
            *top = *top + gKeyboardOffsetY;
            *right = *right + gKeyboardOffsetX;
            *bottom = *bottom + gKeyboardOffsetY;
        }
    }
}

void InitKeyboardKeysAndCanvas(struct NNSG2dFont *font, void *bg2Char, u16 *bg2Scr, s32 screenMapWidth,
                               s32 screenMapHeight, s32 screenMapTileBase) {
    Mem_CpuFill8(&g_Global78Sub_2, 0, sizeof(g_Global78Sub_2));
    gKeyboardCanvas.mFont = font;
    gKeyboardCanvas.mBg2Char = bg2Char;
    gKeyboardCanvas.mMarkedBg2Char = bg2Char;
    gKeyboardCanvas.mBg2Scr = bg2Scr;
    gKeyboardCanvas.mScreenMapWidth = screenMapWidth;
    gKeyboardCanvas.mScreenMapHeight = screenMapHeight;
    gKeyboardCanvas.mScreenMapTileBase = screenMapTileBase;
    InitKeyboardInput();
    SetupRepeatCounter(&g_Global78Sub_2.mTouchRepeat, 0x28, 5);
    SetupKeyboardKeyRepeat(gKeyboardInputMasks[2] | (gKeyboardInputMasks[0] | 0xf0 | gKeyboardInputMasks[1]));
    gCharTablePair1[0] = gCharTablePair2[0] = gCharTablePair3[0] = gCharTables[0];
    gCharTablePair1[1] = gCharTables[1];
    gCharTablePair2[1] = gCharTables[2];
    gCharTablePair3[1] = gCharTables[3];
}

#pragma thumb off

#pragma thumb on
void SetKeyboardScreenMapTopBits(u32 topBits) {
    u32 topBitsCopy = topBits;
    u32 unusedValue;
    gKeyboardCanvas.mScreenMapTopBits = topBitsCopy;
}
#pragma thumb off

#pragma thumb on
void SetKeyboardGlyphColor(u32 color) {
    u32 colorCopy = color;
    u32 unusedValue;
    gKeyboardCanvas.mGlyphColor = colorCopy;
}
#pragma thumb off

#pragma thumb on
void SetKeyboardCursorCallback(u16 (*callback)(s32, u16)) {
    g_Global78Sub_2.mCursorCallback = callback;
}
#pragma thumb off

#pragma thumb on
void SetKeyboardKeyCallback(s32 (*callback)(u32, s32)) {
    g_Global78Sub_2.mKeyCallback = callback;
}
#pragma thumb off

#pragma thumb on

void CallKeyboardKeyCallback(s32 newPress) {
    if (g_Global78Sub_2.mKeyCallback != NULL) {
        if (g_Global78Sub_2.mKeyCallback(GetKeyboardValueForKeyId(g_Global78Sub_2.mKeyId), newPress) != 0) {
            g_Global78Sub_2.mKeyId = 0;
        }
    }
}

void FillKeyboardBg2Scr(KeyboardKeys *keyboardKeys) {
    s32 rowCount;
    s32 columnCount;
    s32 row;
    s32 rowFirstTile;
    BOOL firstColumn;
    s32 column;
    volatile u16 clearValue;

    columnCount = keyboardKeys->mCurrentLayout->mNcgr->mColumnCount;
    rowCount = keyboardKeys->mCurrentLayout->mNcgr->mRowCount;
    clearValue = columnCount * rowCount;
    Mem_CpuFill16(clearValue, gKeyboardCanvas.mBg2Scr,
                   gKeyboardCanvas.mScreenMapHeight * (gKeyboardCanvas.mScreenMapWidth * 2));
    row = 0;
    rowFirstTile = 0;
    rowFirstTile = (u32) rowFirstTile;
    firstColumn = FALSE;
    if (row < rowCount) {
        rowFirstTile = 0;
        rowFirstTile = (u32) rowFirstTile;
        do {
            for (column = firstColumn; column < columnCount; column++) {
                gKeyboardCanvas.mBg2Scr[column + row * gKeyboardCanvas.mScreenMapHeight / 2] =
                    (gKeyboardCanvas.mScreenMapTopBits << 12) |
                    (column + (gKeyboardCanvas.mScreenMapTileBase + rowFirstTile));
            }
            rowFirstTile += columnCount;
            row++;
        } while (row < rowCount);
    }
}

u16 FindFirstCharRectIndex(KeyboardLayout *keyboardLayout) {
    u16 rectIndex;
    const KeyboardLayout *layoutCopy = keyboardLayout;

    for (rectIndex = 0; rectIndex < layoutCopy->mRectCount; rectIndex++) {
        if (keyboardLayout->mFixedKeyCount + 1 == keyboardLayout->mRects[rectIndex].mKeyId) {
            return rectIndex;
        }
    }
    return 0;
}

KeyboardRect *FindKeyboardRectAt(KeyboardKeys *keyboardKeys, s32 pointX, s32 pointY) {
    KeyboardRect *buttonRect;
    KeyboardLayout *layout;
    s32 rectCount;
    KeyboardRect *rects;
    s32 rectIndex;

    buttonRect = &keyboardKeys->mButton0Rect;
    if (buttonRect->mWidth > 1 && buttonRect->mHeight > 1 && buttonRect->mY <= pointY &&
        pointY < buttonRect->mY + buttonRect->mHeight && buttonRect->mX <= pointX &&
        pointX < buttonRect->mX + buttonRect->mWidth) {
        return buttonRect;
    }
    buttonRect = &keyboardKeys->mButton1Rect;
    if (buttonRect->mWidth > 1 && buttonRect->mHeight > 1 && buttonRect->mY <= pointY &&
        pointY < buttonRect->mY + buttonRect->mHeight && buttonRect->mX <= pointX &&
        pointX < buttonRect->mX + buttonRect->mWidth) {
        return buttonRect;
    }
    layout = keyboardKeys->mCurrentLayout;
    rects = layout->mRects;
    rectCount = layout->mRectCount;
    for (rectIndex = 0; rectIndex < rectCount; rectIndex++) {
        if (rects[rectIndex].mWidth > 1 && rects[rectIndex].mHeight > 1 &&
            gKeyboardOffsetY + rects[rectIndex].mY <= pointY &&
            pointY < gKeyboardOffsetY + (rects[rectIndex].mY + rects[rectIndex].mHeight) &&
            gKeyboardOffsetX + rects[rectIndex].mX <= pointX &&
            pointX < gKeyboardOffsetX + (rects[rectIndex].mX + rects[rectIndex].mWidth)) {
            return &rects[rectIndex];
        }
    }
    return NULL;
}

void DrawKeyboardGlyphs(KeyboardKeys *keyboardKeys) {
    NNSG2dFont *font;
    KeyboardRect *rect;
    FontGlyph *glyphInfo;
    NNSG2dCharWidths *charWidths;
    NNSG2dGlyph glyph;
    NNSG2dCharCanvas charCanvas;
    s32 glyphHeight;
    KeyboardLayout *layout;
    u32 character;
    s32 glyphIndex;
    s32 rectIndex;
    s32 charMapOffset;
    s32 marginX;
    s32 drawnCount;
    s32 firstCharRectIndex;

    font = gKeyboardCanvas.mFont;
    glyphHeight = font->mPRes->mPGlyph->mCellHeight;
    layout = keyboardKeys->mCurrentLayout;
    MIi_CpuCopyFast(layout->mNcgr->mData, gKeyboardCanvas.mBg2Char, layout->mNcgr->mDataSize);
    G2d_Sprite_CreateFromTiles(&charCanvas, gKeyboardCanvas.mBg2Char, layout->mNcgr->mColumnCount,
                               layout->mNcgr->mRowCount, 4);
    rectIndex = FindFirstCharRectIndex(layout);
    drawnCount = 0;
    if (layout->mRectCount - rectIndex > 0) {
        charMapOffset = 0;
        firstCharRectIndex = rectIndex;
        do {
            rect = GetKeyboardLayoutRect(layout, rectIndex);
            character = *OFFSET_PTR(u16, keyboardKeys->mCharMap, charMapOffset);
            if (rect->mWidth > 1 && rect->mHeight > 1) {
                glyphIndex = NFTR_GetTileIndexForCharacter(font, character);
                if (glyphIndex == 0xffff) {
                    glyphIndex = font->mPRes->mAlterCharIndex;
                }
                charWidths = NFTR_GetCharacterWidthTileEntry(font, glyphIndex);
                glyph.mPWidths = charWidths;
                glyphInfo = font->mPRes->mPGlyph;
                glyph.mImage = glyphInfo->mGlyphTable + glyphIndex * glyphInfo->mCellSize;
                marginX = (rect->mWidth - charWidths->mGlyphWidth) / 2;
                charCanvas.mPDrawGlyph(&charCanvas, font, rect->mX + marginX,
                                       rect->mY + (rect->mHeight - glyphHeight) / 2, gKeyboardCanvas.mGlyphColor,
                                       &glyph);
            }
            rectIndex++;
            charMapOffset += 2;
            drawnCount++;
        } while (drawnCount < layout->mRectCount - firstCharRectIndex);
    }
}

void MarkKeyboardRects(KeyboardKeys *keyboardKeys) {
    KeyboardLayout *layout;
    KeyboardRect *startRect;
    KeyboardRect *ringRect;

    layout = keyboardKeys->mCurrentLayout;
    MIi_CpuCopyFast(gKeyboardCanvas.mBg2Char, gKeyboardCanvas.mMarkedBg2Char, layout->mNcgr->mDataSize);
    MemFillWordsByBlock_inline((u8 *) gKeyboardCanvas.mMarkedBg2Char + (layout->mNcgr->mDataSize << 5), 0x20);
    if (keyboardKeys->mChosenKeyId != 0) {
        startRect = layout->mRects + (keyboardKeys->mChosenKeyId - 1);
        ringRect = startRect;
        do {
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mMarkedBg2Char,
                                      g_Global78Sub_2.mCurrentLayout->mNcgr->mColumnCount << 3, 8, ringRect->mX,
                                      ringRect->mY, ringRect->mX + ringRect->mWidth, ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
    if (keyboardKeys->mToggledKeyId != 0) {
        startRect = layout->mRects + (keyboardKeys->mToggledKeyId - 1);
        ringRect = startRect;
        do {
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mMarkedBg2Char,
                                      g_Global78Sub_2.mCurrentLayout->mNcgr->mColumnCount << 3, 8, ringRect->mX,
                                      ringRect->mY, ringRect->mX + ringRect->mWidth, ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
    startRect = keyboardKeys->mCursorRect;
    if (startRect != NULL && startRect->mKeyId != 0 && startRect->mKeyId <= KEYBOARD_KEY_ID_LAST_KEY &&
        startRect->mKeyId != g_Global78Sub_2.mToggledKeyId && startRect->mKeyId != g_Global78Sub_2.mChosenKeyId &&
        startRect != keyboardKeys->mTouchStartRect && startRect != keyboardKeys->mKeyDownRect) {
        ringRect = startRect;
        do {
            AddToNonzeroNibblesOnRectEdge(
                gKeyboardCanvas.mMarkedBg2Char, g_Global78Sub_2.mCurrentLayout->mNcgr->mColumnCount << 3, 8, ringRect->mX,
                ringRect->mY, ringRect->mX + ringRect->mWidth, ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
    startRect = keyboardKeys->mKeyDownRect;
    if (startRect != NULL && startRect->mKeyId != 0 && startRect->mKeyId <= KEYBOARD_KEY_ID_LAST_KEY &&
        startRect->mKeyId != g_Global78Sub_2.mToggledKeyId && startRect->mKeyId != g_Global78Sub_2.mChosenKeyId) {
        ringRect = startRect;
        do {
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mMarkedBg2Char,
                                      g_Global78Sub_2.mCurrentLayout->mNcgr->mColumnCount << 3, 8, ringRect->mX,
                                      ringRect->mY, ringRect->mX + ringRect->mWidth, ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
    startRect = keyboardKeys->mTouchStartRect;
    if (startRect != NULL && startRect->mKeyId != 0 && startRect->mKeyId <= KEYBOARD_KEY_ID_LAST_KEY &&
        startRect->mKeyId != g_Global78Sub_2.mToggledKeyId && startRect->mKeyId != g_Global78Sub_2.mChosenKeyId &&
        startRect != keyboardKeys->mKeyDownRect) {
        if (keyboardKeys->mTouchRect != NULL && startRect->mKeyId == keyboardKeys->mTouchRect->mKeyId) {
            ringRect = startRect;
            do {
                AddToNonzeroNibblesInRect(
                    gKeyboardCanvas.mMarkedBg2Char, g_Global78Sub_2.mCurrentLayout->mNcgr->mColumnCount << 3, 8,
                    ringRect->mX, ringRect->mY, ringRect->mX + ringRect->mWidth, ringRect->mY + ringRect->mHeight);
                ringRect += ringRect->mNextRectOffset;
            } while (ringRect != startRect);
            return;
        }
        ringRect = startRect;
        do {
            AddToNonzeroNibblesOnRectEdge(
                gKeyboardCanvas.mMarkedBg2Char, g_Global78Sub_2.mCurrentLayout->mNcgr->mColumnCount << 3, 8, ringRect->mX,
                ringRect->mY, ringRect->mX + ringRect->mWidth, ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
}

u32 IsKeyboardTouchOnStartKeyId(KeyboardKeys *keyboardKeys) {
    u32 isSameKeyId;
    u32 hasBothRects;
    KeyboardRect *touchStartRect;

    isSameKeyId = 0;
    hasBothRects = 0;
    touchStartRect = keyboardKeys->mTouchStartRect;
    if (touchStartRect != NULL && keyboardKeys->mTouchRect != NULL) {
        hasBothRects = 1;
    }
    if (hasBothRects != 0) {
        if (keyboardKeys->mTouchRect->mKeyId == touchStartRect->mKeyId) {
            isSameKeyId = 1;
        }
    }
    return isSameKeyId;
}

void AdvanceKeyboardKeys(u16 keys, TPData touchPoint) {
    u16 layoutKeyId;
    u16 keyMask;
    void (*fn)(KeyboardKeys *);

    AdvanceKeyboardInput(keys, touchPoint);
    AdvanceKeyboardKeyRepeat();
    g_Global78Sub_2.mKeyId = 0;
    g_Global78Sub_2.mKeyValue = 0;
    if (g_Global78Sub_2.mCurrentLayout != NULL && g_Global78Sub_2.mCharMap != NULL) {
        if (GetKeyboardKeysDown(gKeyboardInputMasks[0]) != 0) {
            g_Global78Sub_2.mKeyDownRect = g_Global78Sub_2.mCursorRect;
        } else if (GetKeyboardKeysDown(gKeyboardInputMasks[1]) != 0) {
            g_Global78Sub_2.mKeyDownRect = g_Global78Sub_2.mCurrentLayout->mRects;
        } else {
            g_Global78Sub_2.mKeyDownRect = NULL;
        }
        keyMask = gKeyboardInputMasks[0];
        if ((GetKeyboardKeysPressedOrRepeated() & keyMask) != 0) {
            g_Global78Sub_2.mKeyId = g_Global78Sub_2.mCursorRect->mKeyId;
            CallKeyboardKeyCallback(GetKeyboardKeysPressed(keyMask));
        } else {
            keyMask = gKeyboardInputMasks[1];
            if ((GetKeyboardKeysPressedOrRepeated() & keyMask) != 0) {
                g_Global78Sub_2.mKeyId = KEYBOARD_KEY_ID_DELETE;
                CallKeyboardKeyCallback(GetKeyboardKeysPressed(keyMask));
            } else {
                keyMask = gKeyboardInputMasks[2];
                if ((GetKeyboardKeysPressedOrRepeated() & keyMask) != 0) {
                    fn = g_Global78Sub_2.mCurrentLayout->mCallback;
                    if (fn == AsciiLayoutCallback) {
                        layoutKeyId = g_Global78Sub_2.mToggledKeyId;
                        if (layoutKeyId == 0) {
                            g_Global78Sub_2.mKeyId = KEYBOARD_KEY_ID_MODE_FIRST;
                        } else if (layoutKeyId == KEYBOARD_KEY_ID_MODE_FIRST) {
                            g_Global78Sub_2.mKeyId = KEYBOARD_KEY_ID_MODE_SECOND;
                        } else if (layoutKeyId == KEYBOARD_KEY_ID_MODE_SECOND) {
                            g_Global78Sub_2.mKeyId = KEYBOARD_KEY_ID_MODE_SECOND;
                        }
                        CallKeyboardKeyCallback(GetKeyboardKeysPressed(keyMask));
                    } else if (fn == HiraganaKatakanaLayoutCallback) {
                        g_Global78Sub_2.mKeyId = KEYBOARD_KEY_ID_CYCLE;
                        CallKeyboardKeyCallback(GetKeyboardKeysPressed(keyMask));
                    }
                }
            }
        }
        if ((GetKeyboardKeysPressedOrRepeated() & 0x40) != 0) {
            g_Global78Sub_2.mCursorRect =
                FindKeyboardRectInDirection(0x40, g_Global78Sub_2.mCursorRect, g_Global78Sub_2.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x80) != 0) {
            g_Global78Sub_2.mCursorRect =
                FindKeyboardRectInDirection(0x80, g_Global78Sub_2.mCursorRect, g_Global78Sub_2.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x20) != 0) {
            g_Global78Sub_2.mCursorRect =
                FindKeyboardRectInDirection(0x20, g_Global78Sub_2.mCursorRect, g_Global78Sub_2.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x10) != 0) {
            g_Global78Sub_2.mCursorRect =
                FindKeyboardRectInDirection(0x10, g_Global78Sub_2.mCursorRect, g_Global78Sub_2.mCurrentLayout->mRects);
        }
        if (GetKeyboardTouchDown() != 0) {
            g_Global78Sub_2.mTouchRect =
                FindKeyboardRectAt(&g_Global78Sub_2, GetKeyboardLastTouchX(), GetKeyboardLastTouchY());
        }
        if (GetKeyboardTouchStatus() == KEYBOARD_TOUCH_BEGAN) {
            g_Global78Sub_2.mTouchStartRect =
                FindKeyboardRectAt(&g_Global78Sub_2, GetKeyboardLastTouchX(), GetKeyboardLastTouchY());
            if (g_Global78Sub_2.mTouchStartRect != NULL) {
                g_Global78Sub_2.mKeyId = g_Global78Sub_2.mTouchStartRect->mKeyId;
                CallKeyboardKeyCallback(1);
            }
        } else if (GetKeyboardTouchStatus() == KEYBOARD_TOUCH_ENDED) {
            g_Global78Sub_2.mTouchStartRect = NULL;
        }
        if (IsKeyboardTouchOnStartKeyId(&g_Global78Sub_2) != 0) {
            AdvanceRepeatCounter(&g_Global78Sub_2.mTouchRepeat);
            if (IsRepeatCounterFiring(&g_Global78Sub_2.mTouchRepeat) != FALSE) {
                g_Global78Sub_2.mKeyId = g_Global78Sub_2.mTouchStartRect->mKeyId;
                CallKeyboardKeyCallback(0);
            }
        } else {
            ResetRepeatCounter(&g_Global78Sub_2.mTouchRepeat);
        }
        g_Global78Sub_2.mKeyValue = GetKeyboardValueForKeyId(g_Global78Sub_2.mKeyId);
        if (g_Global78Sub_2.mKeyValue >= KEYBOARD_VALUE_FIRST_CHARACTER) {
            fn = g_Global78Sub_2.mCurrentLayout->mCallback;
            if (fn == AsciiLayoutCallback) {
                if (g_Global78Sub_2.mToggledKeyId == KEYBOARD_KEY_ID_MODE_FIRST) {
                    g_Global78Sub_2.mToggledKeyId = 0;
                }
            } else if (fn == HiraganaKatakanaLayoutCallback) {
                g_Global78Sub_2.mToggledKeyId = 0;
            }
        }
        if (g_Global78Sub_2.mKeyId != 0 && g_Global78Sub_2.mCurrentLayout->mCallback != NULL) {
            g_Global78Sub_2.mCurrentLayout->mCallback(&g_Global78Sub_2);
        }
        DrawKeyboardGlyphs(&g_Global78Sub_2);
        MarkKeyboardRects(&g_Global78Sub_2);
    }
}

void PollKeyboard(void) {
    TPData rawSample;
    TPData touchPoint;

    if (IsKeyboardTouchEnabled() != 0) {
        do {
            TP_RequestSamplingAsync();
        } while (TP_WaitRawResult(&rawSample) != 0);
        TP_GetCalibratedPoint(&touchPoint, &rawSample);
    } else {
        touchPoint.mTouch = 0;
        touchPoint.mValidity = TP_VALIDITY_INVALID_XY;
    }
    AdvanceKeyboardKeys(((reg_PAD_KEYINPUT | SYSTEM_WORK->mButtonXY) ^ 0x2fff) & 0x2fff, touchPoint);
}

#pragma thumb off

#pragma thumb on
u32 GetKeyboardKeyValue(void) {
    u32 keyValue;
    keyValue = g_Global78Sub_2.mKeyValue;
    return keyValue;
}
#pragma thumb off

#pragma thumb on

u16 ConvertCharPair1(u16 charCode) {
    u16 converted;
    u16 mapped;

    if (charCode == 0 || charCode == 0x3000) {
        return charCode;
    }
    if (IsCharInTable2(charCode) != 0) {
        converted = ConvertCharPair2(charCode);
        mapped = LookupCharInTablePair(gCharTablePair1, converted);
        if (mapped != converted) {
            return mapped;
        }
        return charCode;
    }
    if (IsCharInTable3(charCode) != 0) {
        converted = ConvertCharPair3(charCode);
        mapped = LookupCharInTablePair(gCharTablePair1, converted);
        if (mapped != converted) {
            return mapped;
        }
        return charCode;
    }
    return LookupCharInTablePair(gCharTablePair1, charCode);
}

u16 ConvertCharPair2(u16 charCode) {
    u16 converted;
    u16 mapped;

    if (charCode == 0 || charCode == 0x3000) {
        return charCode;
    }
    if (IsCharInTable1(charCode) != 0) {
        converted = ConvertCharPair1(charCode);
        mapped = LookupCharInTablePair(gCharTablePair2, converted);
        if (mapped != converted) {
            return mapped;
        }
        return charCode;
    }
    return LookupCharInTablePair(gCharTablePair2, charCode);
}

u16 ConvertCharPair3(u16 charCode) {
    u16 converted;
    u16 mapped;

    if (charCode == 0 || charCode == 0x3000) {
        return charCode;
    }
    if (IsCharInTable1(charCode) != 0) {
        converted = ConvertCharPair1(charCode);
        mapped = LookupCharInTablePair(gCharTablePair3, converted);
        if (mapped != converted) {
            return mapped;
        }
        return charCode;
    }
    return LookupCharInTablePair(gCharTablePair3, charCode);
}

u16 CycleCharTables(u16 charCode) {
    s32 tableIndex;
    s32 offset;
    s32 charIndex;
    u16 **tablePtr;
    u16 *found;
    u16 *otherTable;

    if (charCode == 0 || charCode == 0x3000) {
        return charCode;
    }
    for (tableIndex = 0, tablePtr = gCharTables; tableIndex < 4; tablePtr++, tableIndex++) {
        found = wcschr(*tablePtr, charCode);
        if (found != NULL) {
            charIndex = found - gCharTables[tableIndex];
            break;
        }
    }
    if (tableIndex < 4) {
        for (offset = 1; offset < 4; offset++) {
            otherTable = gCharTables[(tableIndex + offset) % 4];
            if (otherTable[charIndex] != 0x3000) {
                return otherTable[charIndex];
            }
        }
    } else {
        return charCode;
    }
    return charCode;
}

u32 IsCharInTable1(u16 charCode) {
    if (wcschr(gCharTablePair1[1], charCode) != NULL) {
        return 1;
    }
    return 0;
}

u32 IsCharInTable2(u16 charCode) {
    if (wcschr(gCharTablePair2[1], charCode) != NULL) {
        return 1;
    }
    return 0;
}

u32 IsCharInTable3(u16 charCode) {
    if (wcschr(gCharTablePair3[1], charCode) != NULL) {
        return 1;
    }
    return 0;
}

void AddToNonzeroNibblesInTile(u32 *tile, u32 addValue, s32 startX, s32 startRow, s32 endX, s32 endRow) {
    u32 addMask;
    u32 rowMask;
    u32 *rowPtr;
    u32 rowValue;
    s32 pixelIndex;

    addMask = 0;
    for (pixelIndex = 0; pixelIndex < endX - startX; pixelIndex++) {
        addMask |= addValue << (pixelIndex * 4);
    }
    addMask <<= startX * 4;
    if (startRow < endRow) {
        rowPtr = tile + startRow;
        do {
            rowMask = addMask;
            rowValue = *rowPtr;
            if ((rowValue & 0xf0000000) == 0) {
                rowMask &= 0xfffffff;
            }
            if ((rowValue & 0xf000000) == 0) {
                rowMask &= 0xf0ffffff;
            }
            if ((rowValue & 0xf00000) == 0) {
                rowMask &= 0xff0fffff;
            }
            if ((rowValue & 0xf0000) == 0) {
                rowMask &= 0xfff0ffff;
            }
            if ((rowValue & 0xf000) == 0) {
                rowMask &= 0xffff0fff;
            }
            if ((rowValue & 0xf00) == 0) {
                rowMask &= 0xfffff0ff;
            }
            if ((rowValue & 0xf0) == 0) {
                rowMask &= ~0xf0;
            }
            if ((rowValue & 0xf) == 0) {
                rowMask &= ~0xf;
            }
            *rowPtr += rowMask;
            rowPtr++;
            startRow++;
        } while (startRow < endRow);
    }
}

void AddToNonzeroNibblesOnRectEdge(u32 (*tiles)[8], s32 rowWidth, u32 addValue, s32 left, s32 top, s32 right,
                                   s32 bottom) {
    AddToNonzeroNibblesInRect(tiles, rowWidth, addValue, left, top, right, top + 1);
    AddToNonzeroNibblesInRect(tiles, rowWidth, addValue, left, bottom - 1, right, bottom);
    AddToNonzeroNibblesInRect(tiles, rowWidth, addValue, left, top + 1, left + 1, bottom - 1);
    AddToNonzeroNibblesInRect(tiles, rowWidth, addValue, right - 1, top + 1, right, bottom - 1);
}

void AddToNonzeroNibblesInRect(u32 (*tiles)[8], s32 rowWidth, u32 addValue, s32 left, s32 top, s32 right, s32 bottom) {
    s32 tileY;
    s32 firstTileX;
    s32 endTileX;
    s32 endTileY;
    s32 tileTop;
    s32 tileRowBase;
    s32 tilesPerRow;

    if (left < right && top < bottom) {
        firstTileX = left >> 3;
        endTileX = ((right - 1) >> 3) + 1;
        endTileY = ((bottom - 1) >> 3) + 1;
        tileY = top >> 3;
        if (tileY < endTileY) {
            tileTop = tileY << 3;
            tilesPerRow = rowWidth >> 3;
            tileRowBase = tileY * tilesPerRow;
            do {
                s32 tileX;
                tileX = firstTileX;
                for (; tileX < endTileX; tileX++) {
                    s32 localLeft;
                    s32 localTop;
                    s32 localRight;
                    s32 localBottom;

                    localLeft = left - (tileX << 3);
                    if (localLeft < 0) {
                        localLeft = 0;
                    }
                    localTop = top - tileTop < 0 ? 0 : top - tileTop;
                    localRight = right - (tileX << 3);
                    if (localRight > 8) {
                        localRight = 8;
                    }
                    localBottom = bottom - tileTop > 8 ? 8 : bottom - tileTop;
                    AddToNonzeroNibblesInTile(tiles[tileX + tileRowBase], addValue, localLeft, localTop, localRight,
                                              localBottom);
                }
                tileTop += 8;
                tileRowBase += tilesPerRow;
                tileY++;
            } while (tileY < endTileY);
        }
    }
}

void RefreshKeyboardCursor(KeyboardKeys *keyboardKeys) {
    KeyboardRect *cursorRect;
    KeyboardRect *rectAtCenter;
    s32 centerX;
    s32 centerY;

    cursorRect = keyboardKeys->mCursorRect;
    if (cursorRect == NULL) {
        keyboardKeys->mCursorRect = keyboardKeys->mCurrentLayout->mRects + keyboardKeys->mCurrentLayout->mFixedKeyCount;
        return;
    }
    if (cursorRect->mKeyId <= KEYBOARD_KEY_ID_LAST_KEY) {
        centerX = gKeyboardOffsetX + ((cursorRect->mX << 1) + cursorRect->mWidth) / 2 + 3;
        centerY = gKeyboardOffsetY + ((cursorRect->mY << 1) + cursorRect->mHeight) / 2 - 3;
    } else {
        centerX = ((cursorRect->mX << 1) + cursorRect->mWidth) / 2 + 3;
        centerY = ((cursorRect->mY << 1) + cursorRect->mHeight) / 2 - 3;
    }
    rectAtCenter = FindKeyboardRectAt(keyboardKeys, centerX, centerY);
    if (rectAtCenter != NULL) {
        keyboardKeys->mCursorRect = rectAtCenter;
        return;
    }
    keyboardKeys->mCursorRect = keyboardKeys->mCurrentLayout->mRects + keyboardKeys->mCurrentLayout->mFixedKeyCount;
}

KeyboardRect *FindKeyboardRectInDirection(u32 direction, KeyboardRect *rect, KeyboardRect *unused) {
    s32 startX;
    s32 endX;
    s32 startY;
    s32 endY;
    s32 stepX;
    s32 stepY;
    s32 offsetX;
    s32 offsetY;
    s32 scanX;
    s32 wrappedX;
    s32 wrappedY;
    s32 localX;
    s32 localY;
    s32 margin;
    s32 negMargin;
    s32 spanX;
    s32 spanY;
    u16 callbackResult;
    KeyboardRect *callbackRect;
    KeyboardRect *foundRect;
    Ncgr *ncgr;

    if (g_Global78Sub_2.mCursorCallback != NULL) {
        callbackResult = g_Global78Sub_2.mCursorCallback(GetKeyboardRectValue(rect), direction);
        if (callbackResult != 0) {
            callbackRect = FindKeyboardRectByValue(callbackResult);
            if (callbackRect != NULL) {
                return callbackRect;
            }
        }
    }
    if (rect->mKeyId <= KEYBOARD_KEY_ID_LAST_KEY) {
        offsetX = gKeyboardOffsetX;
        offsetY = gKeyboardOffsetY;
    } else {
        offsetX = 0;
        offsetY = 0;
    }
    if ((direction & 0x40) != 0) {
        stepX = -8;
        stepY = -8;
        startX = endX = offsetX + (rect->mX + rect->mX + rect->mWidth) / 2;
        endX -= 0x10;
        startY = offsetY + rect->mY;
        endY = startY - 0x120;
    } else if ((direction & 0x80) != 0) {
        stepX = 8;
        stepY = 8;
        startX = endX = offsetX + (rect->mX + rect->mX + rect->mWidth) / 2;
        endX += 0x10;
        startY = offsetY + (rect->mY + rect->mHeight);
        endY = startY + 0x120;
    } else if ((direction & 0x20) != 0) {
        stepX = -8;
        stepY = 8;
        startX = offsetX + rect->mX;
        endX = startX - 0x120;
        startY = endY = offsetY + (rect->mY + rect->mY + rect->mHeight) / 2;
        endY += 0x10;
    } else if ((direction & 0x10) != 0) {
        stepX = 8;
        stepY = 8;
        startX = offsetX + (rect->mX + rect->mWidth);
        endX = startX + 0x120;
        startY = endY = offsetY + (rect->mY + rect->mY + rect->mHeight) / 2;
        endY += 0x10;
    }
    for (; startY != endY; startY += stepY) {
        scanX = startX;
        if (scanX != endX) {
            localY = startY - offsetY;
            do {
                wrappedX = scanX;
                wrappedY = startY;
                ncgr = g_Global78Sub_2.mCurrentLayout->mNcgr;
                spanX = ncgr->mColumnCount << 3;
                spanY = ncgr->mRowCount << 3;
                localX = scanX - offsetX;
                margin = gKeyboardWrapMargin;
                negMargin = -margin;
                if (localX < negMargin) {
                    wrappedX = scanX + (spanX + margin * 2);
                } else if (localX > spanX + margin) {
                    wrappedX = scanX - (spanX + margin * 2);
                }
                if (localY < negMargin) {
                    wrappedY = wrappedY + (spanY + margin * 2);
                } else if (localY > spanY + margin) {
                    wrappedY = wrappedY - (spanY + margin * 2);
                }
                foundRect = FindKeyboardRectAt(&g_Global78Sub_2, wrappedX, wrappedY);
                if (foundRect != NULL && foundRect != rect) {
                    return foundRect;
                }
                scanX += stepX;
            } while (scanX != endX);
        }
    }
    return rect;
}

u16 LookupCharInTablePair(u16 **tablePair, u16 charCode) {
    s32 tableIndex;
    u16 *found;
    u16 mapped;

    for (tableIndex = 0; tableIndex < 2; tableIndex++) {
        found = wcschr(tablePair[tableIndex], charCode);
        if (found != NULL) {
            mapped = tablePair[1 - tableIndex][found - tablePair[tableIndex]];
            if (mapped != 0x3000) {
                return mapped;
            }
            return charCode;
        }
    }
    return charCode;
}

void SetupKeyboardLayout(KeyboardRect *rects, Ncgr *ncgr, void (*callback)(KeyboardKeys *), s32 fixedCount,
                         u32 rectCount, u16 *charMap) {
    u32 touchX;
    u32 touchY;

    g_Global78Sub_2.mCurrentLayout = &g_Global78Sub_2.mLayout;
    g_Global78Sub_2.mCurrentLayout->mRects = rects;
    g_Global78Sub_2.mCurrentLayout->mNcgr = ncgr;
    g_Global78Sub_2.mCurrentLayout->mCallback = callback;
    g_Global78Sub_2.mCurrentLayout->mFixedKeyCount = fixedCount - 1;
    g_Global78Sub_2.mCurrentLayout->mRectCount = rectCount;
    g_Global78Sub_2.mCharMap = charMap + 1;
    if (g_Global78Sub_2.mTouchStartRect != NULL) {
        touchX = GetKeyboardLastTouchX();
        touchY = GetKeyboardLastTouchY();
        g_Global78Sub_2.mTouchStartRect = FindKeyboardRectAt(&g_Global78Sub_2, touchX, touchY);
    }
    FillKeyboardBg2Scr(&g_Global78Sub_2);
    DrawKeyboardGlyphs(&g_Global78Sub_2);
    MarkKeyboardRects(&g_Global78Sub_2);
    RefreshKeyboardCursor(&g_Global78Sub_2);
}

void SetupKeyboardLayoutHiragana(KeyboardRect *rects, Ncgr *ncgr, u32 rectCount) {
    g_Global78Sub_2.mChosenKeyId = KEYBOARD_KEY_ID_MODE_FIRST;
    g_Global78Sub_2.mToggledKeyId = 0;
    SetupKeyboardLayout(rects, ncgr, HiraganaKatakanaLayoutCallback, 9, rectCount, g_HiraganaMap);
}

#pragma thumb off

#pragma thumb on

void SetupKeyboardLayoutAscii(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount) {
    u16 *keyIds;
    keyIds = &g_Global78Sub_2.mChosenKeyId;
    g_Global78Sub_2.mChosenKeyId = 0;
    keyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, AsciiLayoutCallback, 6, rectCount, g_AsciiKbdmap);
}

void SetupKeyboardLayoutOther1(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount) {
    u16 *keyIds;
    keyIds = &g_Global78Sub_2.mChosenKeyId;
    g_Global78Sub_2.mChosenKeyId = 0;
    keyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, NULL, 4, rectCount, g_Other1Map);
}

void SetupKeyboardLayoutOther2(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount) {
    u16 *keyIds;
    keyIds = &g_Global78Sub_2.mChosenKeyId;
    g_Global78Sub_2.mChosenKeyId = 0;
    keyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, NULL, 4, rectCount, g_Other2Map);
}

void SetupKeyboardLayoutOther3(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount) {
    u16 *keyIds;
    keyIds = &g_Global78Sub_2.mChosenKeyId;
    g_Global78Sub_2.mChosenKeyId = 0;
    keyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, NULL, 4, rectCount, g_Other3Map);
}

#pragma thumb off

#pragma thumb on

void Struct78Sub_Create_from_thumb(KeyboardRect *rect, u32 left, u32 top, u32 right, u32 bottom) {
    if (rect != NULL) {
        rect->mX = left;
        rect->mY = top;
        rect->mWidth = right - left;
        rect->mHeight = bottom - top;
        rect->mNextRectOffset = 0;
        rect->mKeyId = KEYBOARD_RECT_ID_PLAIN;
    }
}

#pragma thumb off

#pragma thumb on

void SetKeyboardButton0Rect(u32 left, u32 top, u32 right, u32 bottom) {
    Struct78Sub_Create_from_thumb(&g_Global78Sub_2.mButton0Rect, left, top, right, bottom);
}

void SetKeyboardButton1Rect(u32 left, u32 top, u32 right, u32 bottom) {
    Struct78Sub_Create_from_thumb(&g_Global78Sub_2.mButton1Rect, left, top, right, bottom);
}

#pragma thumb off
