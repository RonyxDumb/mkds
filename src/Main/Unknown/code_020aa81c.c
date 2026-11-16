#include "Main/Unknown/code_020aa81c.h"

#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020ab5bc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/code_020ab660.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02167000.h"
#include "g2d_CharCanvas.h"
#include "code_0214d018.h"
#include "tp.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_020ab088.h"
#include "Main/Unknown/code_020ab5e4.h"
#include "Main/Unknown/code_020ab714.h"
#include "Main/Unknown/code_020ab194.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ab72c.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_020ab758.h"
#include "Main/Unknown/code_020ab798.h"
#include "Main/Unknown/code_020ab7a4.h"
#include "Main/Unknown/code_020ab848.h"
#include "Main/Unknown/code_020ab8c4.h"
#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020a9ed8.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_020aba9c.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020aa810.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_021059e0.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "registers.h"

#pragma thumb on

void SplitBytesIntoNibbles(u8 *bytes, u8 *nibbles, s32 n) {
    s32 i;
    s32 byteCount;

    byteCount = n * n / 2;
    for (i = 0; i < byteCount; i++) {
        nibbles[i * 2] = bytes[i] & 0xf;
        nibbles[i * 2 + 1] = (bytes[i] >> 4) & 0xf;
    }
}

s32 GetKeyboardLastCharIndex(void) {
    s32 lastCharIndex;
    KeyboardTextEntry *keyboardTextEntry;
    s32 textIndex;
    s32 j;

    lastCharIndex = 0;
    keyboardTextEntry = gKeyboardTextEntry;
    textIndex = keyboardTextEntry->mTextIndex;
    j = keyboardTextEntry->mTextLimit - 1;
    if (textIndex == j && keyboardTextEntry->mText[textIndex] >= 0x20) {
        lastCharIndex = textIndex;
    } else {
        j = textIndex - 1;
        if (j >= 0 && keyboardTextEntry->mText[j] >= 0x20) {
            lastCharIndex = j;
        }
    }
    return lastCharIndex;
}

s32 KeyboardKeyCallback(u32 keyValue, s32 b) {
    s32 r;
    s32 lastCharIndex;
    u16 convertedChar;
    u16 currentChar;

    r = 0;
    lastCharIndex = GetKeyboardLastCharIndex();
    switch ((s32) keyValue) {
        case 6:
            if (GetKeyboardChosenKeyValue() != 6) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e7);
            } else {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 7:
            if (GetKeyboardChosenKeyValue() != 7) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e8);
            } else {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x10:
            convertedChar = ConvertCharPair1(gKeyboardTextEntry->mText[lastCharIndex]);
            currentChar = gKeyboardTextEntry->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x11:
            convertedChar = ConvertCharPair2(gKeyboardTextEntry->mText[lastCharIndex]);
            currentChar = gKeyboardTextEntry->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x12:
            convertedChar = ConvertCharPair3(gKeyboardTextEntry->mText[lastCharIndex]);
            currentChar = gKeyboardTextEntry->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 4:
        case 5:
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1eb);
            break;
        case 0x20:
        case 0x3000:
            if (b != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ea);
            }
            break;
        case 8:
            if (b != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e9);
            }
            break;
        default:
            if (b != 0 && keyValue >= 0x20) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e6);
            }
            break;
    }
    return r;
}

u16 KeyboardCursorCallback(s32 rectValue, u16 b) {
    u16 r;

    r = 0;
    switch (rectValue) {
        case 1:
            if ((b & 0x20) != 0 || (b & 0x10) != 0) {
                r = 2;
            } else if ((b & 0x40) != 0) {
                r = a079[gKeyboardTextEntry->mLayoutIndex].mUnk_00;
            } else if ((b & 0x80) != 0) {
                r = a079[gKeyboardTextEntry->mLayoutIndex].mUnk_02;
            }
            break;
        case 2:
            if ((b & 0x20) != 0 || (b & 0x10) != 0) {
                r = 1;
            } else if ((b & 0x40) != 0) {
                r = a079[gKeyboardTextEntry->mLayoutIndex].mUnk_04;
            } else if ((b & 0x80) != 0) {
                r = a079[gKeyboardTextEntry->mLayoutIndex].mUnk_06;
            }
            break;
    }
    sfx_2105AC0(0x1e4);
    return r;
}

void InitKeyboardTextEntry(s32 a, s32 b, s32 textCapacity) {
    KeyboardTextEntry *keyboardTextEntry;

    gKeyboardTextEntry = heap_alloc(proc_getHeap(proc_getCurrent()), 0x78);
    gKeyboardTextEntry->mTextCapacity = textCapacity;
    gKeyboardTextEntry->mTextLimit = textCapacity;
    gKeyboardTextEntry->mTextIndex = 0;
    gKeyboardTextEntry->mUnk_48 = 0;
    gKeyboardTextEntry->mText = heap_alloc(proc_getHeap(proc_getCurrent()), (textCapacity + 1) * 2);
    gKeyboardTextEntry->mBg2ScrSize = b * (a * 2);
    gKeyboardTextEntry->mBg2Scr = heap_alloc(proc_getHeap(proc_getCurrent()), gKeyboardTextEntry->mBg2ScrSize);
    gKeyboardTextEntry->mBg2CharSize = 0x4020;
    gKeyboardTextEntry->mBg2Char =
        heap_allocEx(proc_getHeap(proc_getCurrent()), gKeyboardTextEntry->mBg2CharSize, 0x20);
    keyboardTextEntry = gKeyboardTextEntry;
    InitKeyboardKeysAndCanvas(m2d_getFont(0), keyboardTextEntry->mBg2Char, keyboardTextEntry->mBg2Scr, a, b, 0);
    SetKeyboardCursorCallback(KeyboardCursorCallback);
    SetKeyboardKeyCallback(KeyboardKeyCallback);
    func_020ab07c(0);
    func_020ab070(1);
    gKeyboardTextEntry->mOffsetX = 0;
    gKeyboardTextEntry->mOffsetY = 0;
    gKeyboardTextEntry->mButton0X0 = 0x23;
    gKeyboardTextEntry->mButton0Y0 = 0x7a;
    gKeyboardTextEntry->mButton0X1 = 0x7d;
    gKeyboardTextEntry->mButton0Y1 = 0x8e;
    gKeyboardTextEntry->mButton1X0 = 0x83;
    gKeyboardTextEntry->mButton1Y0 = 0x7a;
    gKeyboardTextEntry->mButton1X1 = 0xdd;
    gKeyboardTextEntry->mButton1Y1 = 0x8e;
    g2du_unpackCharacterData(&gKeyboardTextEntry->mNcgrs[0], arc_getSceneArcFile(aKeyboard_s_b_1));
    g2du_unpackCharacterData(&gKeyboardTextEntry->mNcgrs[2], arc_getSceneArcFile(aKeyboard_s_b_a));
    g2du_unpackCharacterData(&gKeyboardTextEntry->mNcgrs[1], arc_getSceneArcFile(aKeyboard_s_b_j));
    g2du_unpackCharacterData(&gKeyboardTextEntry->mNcgrs[3], arc_getSceneArcFile(aKeyboard_s_b_e));
    g2du_unpackCharacterData(&gKeyboardTextEntry->mNcgrs[4], arc_getSceneArcFile(aKeyboard_s_b_0));
    g2du_getCharacterData(&gKeyboardTextEntry->mUnk_24, arc_getSceneArcFile(aKeyboard_s_b_p));
    gKeyboardTextEntry->mKbds[0] = arc_getSceneArcFile(a10key_kbd);
    gKeyboardTextEntry->mKbds[2] = arc_getSceneArcFile(aAscii_kbd);
    gKeyboardTextEntry->mKbds[1] = arc_getSceneArcFile(aJp_kbd);
    gKeyboardTextEntry->mKbds[3] = arc_getSceneArcFile(aEuro_kbd);
    gKeyboardTextEntry->mKbds[4] = arc_getSceneArcFile(aPicto_kbd_0);
    gKeyboardTextEntry->mKbds[5] = arc_getSceneArcFile(aPicto_kbd);
    gKbdmapAscii = arc_getSceneArcFile(aAscii_kbdmap);
    gKbdmapAsciiCaps = arc_getSceneArcFile(aAscii_caps_kbd);
    gKbdmapAsciiShift = arc_getSceneArcFile(aAscii_shift_kb);
    gKbdmapHiragana = arc_getSceneArcFile(aHiragana_kbdma);
    gKbdmapHiraganaDakuten = arc_getSceneArcFile(aHiragana_dakut);
    gKbdmapHiraganaHandaku = arc_getSceneArcFile(aHiragana_handa);
    gKbdmapHiraganaSmall = arc_getSceneArcFile(aHiragana_small);
    gKbdmapKatakana = arc_getSceneArcFile(aKatakana_kbdma);
    gKbdmapKatakanaDakuten = arc_getSceneArcFile(aKatakana_dakut);
    gKbdmapKatakanaHandaku = arc_getSceneArcFile(aKatakana_handa);
    gKbdmapKatakanaSmall = arc_getSceneArcFile(aKatakana_small);
    gKbdmapOther1 = arc_getSceneArcFile(aOther1_kbdmap);
    gKbdmapOther2 = arc_getSceneArcFile(aOther2_kbdmap);
    gKbdmapOther3 = arc_getSceneArcFile(aOther3_kbdmap);
    SetupKeyboardInputMasks(1, 2, 0x400);
}

void AdvanceKeyboardTextEntry(void) {
    s32 lastCharIndex;
    InputSlotIndex inputSlotIndex;
    KeyboardTextEntry *keyboardTextEntry;
    u16 convertedChar;

    lastCharIndex = GetKeyboardLastCharIndex();
    KBD_Update();
    GetKeyboardKeyValue();
    inputSlotIndex = UNK_02175628_INDEX_8;
    if ((u16) (gInputUnits[inputSlotIndex].mPressedBits & 8) != 0) {
        if (GetKeyboardCursorValueWrapper() != 1) {
            MoveKeyboardCursorToValueWrapper(1);
        }
    } else if (GetKeyboardKeyValue() == 8) {
        gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
        keyboardTextEntry = gKeyboardTextEntry;
        if (keyboardTextEntry->mTextIndex != 0) {
            if (keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] == 0) {
                keyboardTextEntry->mTextIndex--;
            }
            gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextIndex] = 0;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e3);
        }
    } else if (GetKeyboardKeyValue() >= 0x20) {
        gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
        keyboardTextEntry = gKeyboardTextEntry;
        if (keyboardTextEntry->mTextIndex < keyboardTextEntry->mTextLimit) {
            if (keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] != GetKeyboardKeyValue()) {
                keyboardTextEntry = gKeyboardTextEntry;
                keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] = GetKeyboardKeyValue();
                gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextIndex + 1] = 0;
                if (gKeyboardTextEntry->mTextIndex < gKeyboardTextEntry->mTextLimit - 1) {
                    gKeyboardTextEntry->mTextIndex++;
                }
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e2);
            }
        }
    } else if (GetKeyboardKeyValue() == 0x10) {
        convertedChar = ConvertCharPair1(gKeyboardTextEntry->mText[lastCharIndex]);
        if (convertedChar != gKeyboardTextEntry->mText[lastCharIndex]) {
            gKeyboardTextEntry->mText[lastCharIndex] = convertedChar;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x11) {
        convertedChar = ConvertCharPair2(gKeyboardTextEntry->mText[lastCharIndex]);
        if (convertedChar != gKeyboardTextEntry->mText[lastCharIndex]) {
            gKeyboardTextEntry->mText[lastCharIndex] = convertedChar;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x12) {
        convertedChar = ConvertCharPair3(gKeyboardTextEntry->mText[lastCharIndex]);
        if (convertedChar != gKeyboardTextEntry->mText[lastCharIndex]) {
            gKeyboardTextEntry->mText[lastCharIndex] = convertedChar;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x13) {
        convertedChar = CycleCharTables(gKeyboardTextEntry->mText[lastCharIndex]);
        if (convertedChar != gKeyboardTextEntry->mText[lastCharIndex]) {
            gKeyboardTextEntry->mText[lastCharIndex] = convertedChar;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ed);
        }
    }
    GetKeyboardKeyValue();
}

#pragma thumb off

#pragma thumb on

void UploadKeyboardBg2Data(void) {
    DC_FlushRange(gKeyboardTextEntry->mBg2Scr, gKeyboardTextEntry->mBg2ScrSize);
    GXS_LoadBG2Scr(gKeyboardTextEntry->mBg2Scr, 0, gKeyboardTextEntry->mBg2ScrSize);
    DC_FlushRange(gKeyboardTextEntry->mBg2Char, gKeyboardTextEntry->mBg2CharSize);
    GXS_LoadBG2Char(gKeyboardTextEntry->mBg2Char, 0, gKeyboardTextEntry->mBg2CharSize);
}

#pragma thumb off

#pragma thumb on
void func_020aba94(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    func_020ab07c(value0);
}
#pragma thumb off

#pragma thumb on

void SelectKeyboardLayout(u32 layoutIndex) {
    switch (layoutIndex) {
        case 0:
            SetupKeyboardLayoutOther3(gKeyboardTextEntry->mKbds[layoutIndex], gKeyboardTextEntry->mNcgrs[layoutIndex],
                                      gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case 1:
            SetupKeyboardLayoutHiragana(gKeyboardTextEntry->mKbds[layoutIndex], gKeyboardTextEntry->mNcgrs[layoutIndex],
                                        gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case 2:
            SetupKeyboardLayoutAscii(gKeyboardTextEntry->mKbds[layoutIndex], gKeyboardTextEntry->mNcgrs[layoutIndex],
                                     gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case 3:
            SetupKeyboardLayoutOther1(gKeyboardTextEntry->mKbds[layoutIndex], gKeyboardTextEntry->mNcgrs[layoutIndex],
                                      gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case 4:
            SetupKeyboardLayoutOther2(gKeyboardTextEntry->mKbds[layoutIndex], gKeyboardTextEntry->mNcgrs[layoutIndex],
                                      gKeyboardLayoutRectCounts[layoutIndex]);
            break;
        case 5:
            SetupKeyboardLayoutOther3(gKeyboardTextEntry->mKbds[layoutIndex], gKeyboardTextEntry->mNcgrs[layoutIndex],
                                      gKeyboardLayoutRectCounts[layoutIndex]);
            break;
    }
    gKeyboardTextEntry->mLayoutIndex = layoutIndex;
}

void SetKeyboardOffset(s32 offsetX, s32 offsetY) {
    gKeyboardTextEntry->mOffsetX = offsetX;
    gKeyboardTextEntry->mOffsetY = offsetY;
    StoreKeyboardOffset(gKeyboardTextEntry->mOffsetX, gKeyboardTextEntry->mOffsetY);
    reg_G2S_DB_BG2OFS = (-gKeyboardTextEntry->mOffsetX & 0x1ff) | ((-gKeyboardTextEntry->mOffsetY << 16) & 0x1ff0000);
    SetKeyboardButton0Rect(gKeyboardTextEntry->mOffsetX + gKeyboardTextEntry->mButton0X0,
                           gKeyboardTextEntry->mOffsetY + gKeyboardTextEntry->mButton0Y0,
                           gKeyboardTextEntry->mOffsetX + gKeyboardTextEntry->mButton0X1,
                           gKeyboardTextEntry->mOffsetY + gKeyboardTextEntry->mButton0Y1);
    SetKeyboardButton1Rect(gKeyboardTextEntry->mOffsetX + gKeyboardTextEntry->mButton1X0,
                           gKeyboardTextEntry->mOffsetY + gKeyboardTextEntry->mButton1Y0,
                           gKeyboardTextEntry->mOffsetX + gKeyboardTextEntry->mButton1X1,
                           gKeyboardTextEntry->mOffsetY + gKeyboardTextEntry->mButton1Y1);
}

#pragma thumb off

#pragma thumb on

void SetKeyboardButton0Corners(u32 startX, u32 startY, u32 endX, u32 endY) {
    KeyboardTextEntry **keyboardTextEntryPointer;
    KeyboardTextEntry *keyboardTextEntry;
    keyboardTextEntryPointer = &gKeyboardTextEntry;
    gKeyboardTextEntry->mButton0X0 = startX;
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
    keyboardTextEntryPointer = &gKeyboardTextEntry;
    gKeyboardTextEntry->mButton1X0 = startX;
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
    *left = *left - gKeyboardTextEntry->mOffsetX;
    *top = *top - gKeyboardTextEntry->mOffsetY;
    *right = *right - gKeyboardTextEntry->mOffsetX;
    *bottom = *bottom - gKeyboardTextEntry->mOffsetY;
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
    s32 i;

    for (i = 0; i < gKeyboardTextEntry->mTextCapacity; i++) {
        gKeyboardTextEntry->mText[i] = 0;
    }
    for (i = 0; i < gKeyboardTextEntry->mTextLimit; i++) {
        gKeyboardTextEntry->mText[i] = *text;
        if (*text == 0) {
            gKeyboardTextEntry->mTextIndex = i;
            gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
            return;
        }
        text++;
    }
    gKeyboardTextEntry->mTextIndex = gKeyboardTextEntry->mTextLimit - 1;
    gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
    gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextLimit] = 0;
}

#pragma thumb off

#pragma thumb on

u16 *GetKeyboardText(void) {
    return gKeyboardTextEntry->mText;
}

#pragma thumb off

#pragma thumb on

void SetKeyboardTextLimit(u16 textLimit) {
    gKeyboardTextEntry->mTextLimit = textLimit;
    if (gKeyboardTextEntry->mTextIndex >= gKeyboardTextEntry->mTextLimit - 1) {
        gKeyboardTextEntry->mTextIndex = gKeyboardTextEntry->mTextLimit - 1;
        gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
        gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextLimit] = 0;
    }
}

#pragma thumb off

#pragma thumb on

u16 GetKeyboardTextIndex(void) {
    return gKeyboardTextEntry->mTextIndex;
}

#pragma thumb off

#pragma thumb on

void KBD_ClearPadTpInput(void) {
    MemFillWordsByBlock_inline(&gKeyboardInput, 0x28);
}

#pragma thumb off

#pragma thumb on

void KBD_StartupPadTpInput(void) {
    KBD_ClearPadTpInput();
    gKeyboardInput.mTouchEnabled = TRUE;
}

#pragma thumb off

#pragma thumb on

void KBD_UpdatePadTpInputValue(u16 keys, volatile TPData touchPoint) {
    u32 changedKeys;
    u16 touch;

    changedKeys = keys ^ gKeyboardInput.mKeysDown;
    gKeyboardInput.mKeysPressed = keys & changedKeys;
    gKeyboardInput.mKeysReleased = ~keys & changedKeys;
    gKeyboardInput.mKeysDown = keys;
    if ((gKeyboardInput.mKeysDown & gKeyboardInput.mUnk_0a) != 0) {
        gKeyboardInput.mUnk_00++;
    } else {
        gKeyboardInput.mUnk_00 = 0;
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
            gKeyboardInput.mTouchStatus = touch != 0 ? 1 : 3;
            gKeyboardInput.mUnk_18 = 0;
        } else if (touch != 0) {
            gKeyboardInput.mTouchStatus = 2;
            gKeyboardInput.mUnk_18++;
        } else {
            gKeyboardInput.mTouchStatus = 0;
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
u32 KBD_IsSetPadTrig(u32 mask) {
    u32 value0 = mask;
    u32 value1;
    value1 = gKeyboardInput.mKeysPressed;
    value1 = (value1) & (value0);
    value0 = (value1) + (0u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 KBD_IsSetPadPress(u32 mask) {
    u32 value0 = mask;
    u32 value1;
    value1 = gKeyboardInput.mKeysDown;
    value1 = (value1) & (value0);
    value0 = (value1) + (0u);
    return value0;
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
u32 KBD_IsEnableTpSampling(void) {
    u32 touchEnabled;
    touchEnabled = gKeyboardInput.mTouchEnabled;
    return touchEnabled;
}
#pragma thumb off

#pragma thumb on

void KBD_InitAutoRepeat(RepeatCounter *repeatCounter) {
    repeatCounter->mRepeatFrames = 0x0u;
    repeatCounter->mUnk_06 = 0x0u;
    repeatCounter->mFirstFireFrame = 0x28u;
    repeatCounter->mRepeatFireFrame = 0x2du;
}

void KBD_InitAutoRepeatValue(RepeatCounter *repeatCounter, u32 firstFireFrame, u32 repeatGap) {
    repeatCounter->mRepeatFrames = 0x0u;
    repeatCounter->mUnk_06 = 0x0u;
    repeatCounter->mFirstFireFrame = firstFireFrame;
    repeatCounter->mRepeatFireFrame = ((firstFireFrame) + (repeatGap));
}

#pragma thumb off

#pragma thumb on

void KBD_UpdateAutoRepeat(RepeatCounter *repeatCounter) {
    repeatCounter->mRepeatFrames = repeatCounter->mRepeatFrames + 1;
    if (repeatCounter->mRepeatFrames == repeatCounter->mFirstFireFrame ||
        repeatCounter->mRepeatFrames == repeatCounter->mRepeatFireFrame) {
        repeatCounter->mUnk_06 = 1;
    }
    if (repeatCounter->mRepeatFrames > repeatCounter->mRepeatFireFrame) {
        repeatCounter->mRepeatFrames = repeatCounter->mFirstFireFrame + 1;
    }
}

#pragma thumb off

#pragma thumb on

void KBD_ResetAutoRepeat(RepeatCounter *repeatCounter) {
    repeatCounter->mRepeatFrames = 0x0u;
    repeatCounter->mUnk_06 = 0x0u;
}

#pragma thumb off

#pragma thumb on

BOOL KBD_IsTriggerAutoRepeat(RepeatCounter *repeatCounter) {
    if (repeatCounter->mRepeatFrames == repeatCounter->mFirstFireFrame ||
        repeatCounter->mRepeatFrames == repeatCounter->mRepeatFireFrame) {
        return TRUE;
    }
    return FALSE;
}

void KBD_InitPadRepeat(u16 keyMask) {
    KBD_InitAutoRepeat(&gKeyboardKeyRepeat.mCounter);
    gKeyboardKeyRepeat.mKeyMask = keyMask;
    gKeyboardKeyRepeat.mRepeatKeys = 0;
}

void KBD_UpdatePadRepeat(void) {
    if (gKeyboardKeyRepeat.mRepeatKeys == 0 && KBD_IsSetPadTrig(gKeyboardKeyRepeat.mKeyMask) != 0) {
        gKeyboardKeyRepeat.mRepeatKeys = KBD_IsSetPadTrig(gKeyboardKeyRepeat.mKeyMask);
        return;
    }
    if (KBD_IsSetPadPress(gKeyboardKeyRepeat.mRepeatKeys) != 0) {
        KBD_UpdateAutoRepeat(&gKeyboardKeyRepeat.mCounter);
    } else {
        KBD_ResetAutoRepeat(&gKeyboardKeyRepeat.mCounter);
        gKeyboardKeyRepeat.mRepeatKeys = 0;
    }
}

u16 KBD_GetPadRepeat(void) {
    u32 repeatedKeys;

    if (KBD_IsTriggerAutoRepeat(&gKeyboardKeyRepeat.mCounter) != FALSE) {
        repeatedKeys = KBD_IsSetPadPress(gKeyboardKeyRepeat.mRepeatKeys);
    } else {
        repeatedKeys = 0;
    }
    return repeatedKeys;
}

u16 KBD_GetPadTrigRepeat(void) {
    if (KBD_IsSetPadTrig(0x2fff) != 0) {
        return KBD_IsSetPadTrig(0x2fff);
    }
    return KBD_GetPadRepeat();
}

void AsciiLayoutCallback(KeyboardKeys *keyboardKeys) {
    switch (keyboardKeys->mKeyId) {
        case 4:
            keyboardKeys->mToggledKeyId = keyboardKeys->mToggledKeyId != 4 ? 4 : 0;
            break;
        case 5:
            keyboardKeys->mToggledKeyId = keyboardKeys->mToggledKeyId != 5 ? 5 : 0;
            break;
    }
    switch (keyboardKeys->mToggledKeyId) {
        case 0:
            keyboardKeys->mCharMap = gKbdmapAscii + 1;
            break;
        case 4:
            keyboardKeys->mCharMap = gKbdmapAsciiShift + 1;
            break;
        case 5:
            keyboardKeys->mCharMap = gKbdmapAsciiCaps + 1;
            break;
    }
}

void HiraganaKatakanaLayoutCallback(KeyboardKeys *keyboardKeys) {
    switch (keyboardKeys->mKeyId) {
        case 4:
            keyboardKeys->mChosenKeyId = 4;
            keyboardKeys->mToggledKeyId = 0;
            break;
        case 5:
            keyboardKeys->mChosenKeyId = 5;
            keyboardKeys->mToggledKeyId = 0;
            break;
    }
    switch (keyboardKeys->mChosenKeyId) {
        case 4:
            if (keyboardKeys->mToggledKeyId == 0) {
                keyboardKeys->mCharMap = gKbdmapHiragana + 1;
            }
            break;
        case 5:
            if (keyboardKeys->mToggledKeyId == 0) {
                keyboardKeys->mCharMap = gKbdmapKatakana + 1;
            }
            break;
    }
}

KeyboardRect *FindKeyboardRectByValue(u16 value) {
    KeyboardRect *rects;
    s32 i;
    u16 rectCount;
    u16 fixedKeyCount;
    u16 *charMap;

    if (gKeyboardKeys.mCurrentLayout != NULL) {
        rects = gKeyboardKeys.mCurrentLayout->mRects;
        rectCount = gKeyboardKeys.mCurrentLayout->mRectCount;
        fixedKeyCount = gKeyboardKeys.mCurrentLayout->mFixedKeyCount;
        charMap = gKeyboardKeys.mCharMap;
        switch (value) {
            case 0:
                return NULL;
            case 1:
                return &gKeyboardKeys.mButton0Rect;
            case 2:
                return &gKeyboardKeys.mButton1Rect;
            case 8:
                return rects;
            case 10:
                return rects + 1;
            case 0x20:
            case 0x3000:
                return rects + 2;
        }
        for (i = 0; i < rectCount; i++) {
            if (rects[i].mWidth > 1 && rects[i].mHeight > 1 && value == charMap[rects[i].mKeyId - fixedKeyCount - 1]) {
                return &rects[i];
            }
        }
    }
    return NULL;
}

s32 GetKeyboardRectValue(KeyboardRect *keyboardRect) {
    KeyboardRect *rects;
    s32 i;
    s32 rectCount;
    u16 fixedKeyCount;
    u16 *charMap;

    if (gKeyboardKeys.mCurrentLayout != NULL) {
        rects = gKeyboardKeys.mCurrentLayout->mRects;
        rectCount = gKeyboardKeys.mCurrentLayout->mRectCount;
        fixedKeyCount = gKeyboardKeys.mCurrentLayout->mFixedKeyCount;
        charMap = gKeyboardKeys.mCharMap;
        if (keyboardRect == NULL) {
            return 0;
        }
        if (keyboardRect == &gKeyboardKeys.mButton0Rect) {
            return 1;
        }
        if (keyboardRect == &gKeyboardKeys.mButton1Rect) {
            return 2;
        }
        for (i = 0; i < rectCount; i++) {
            if (rects[i].mWidth > 1 && rects[i].mHeight > 1 && keyboardRect == &rects[i]) {
                switch (i) {
                    case 0:
                        return 8;
                    case 1:
                        return 0xa;
                    case 2:
                        return 0x20;
                }
                return charMap[rects[i].mKeyId - fixedKeyCount - 1];
            }
        }
    }
    return 0;
}

s32 GetKeyboardValueForKeyId(u32 keyId) {
    KeyboardLayout *currentLayout;
    u16 fixedKeyCount;

    currentLayout = gKeyboardKeys.mCurrentLayout;
    if (currentLayout != NULL) {
        if (keyId == 0) {
            return 0;
        }
        fixedKeyCount = currentLayout->mFixedKeyCount;
        if (keyId <= fixedKeyCount || keyId == 0xffff) {
            if (currentLayout->mCallback == HiraganaKatakanaLayoutCallback) {
                switch ((s32) keyId) {
                    case 1:
                        return 8;
                    case 2:
                        return 0xa;
                    case 3:
                        return 0x3000;
                    case 4:
                        return 6;
                    case 5:
                        return 7;
                    case 6:
                        return 0x10;
                    case 7:
                        return 0x11;
                    case 8:
                        return 0x12;
                    case 0xffff:
                        return 0x13;
                }
            } else {
                switch (keyId) {
                    case 1:
                        return 8;
                    case 2:
                        return 0xa;
                    case 3:
                        return 0x20;
                    case 4:
                        return 4;
                    case 5:
                        return 5;
                }
            }
        }
        if (keyId <= 0xff && gKeyboardKeys.mCharMap[keyId - fixedKeyCount - 1] > 0x20) {
            return gKeyboardKeys.mCharMap[keyId - fixedKeyCount - 1];
        }
    }
    return 0;
}

void SetupKeyboardInputMasks(u16 a, u16 b, u16 c) {
    gKeyboardInputMasks[0] = a;
    gKeyboardInputMasks[1] = b;
    gKeyboardInputMasks[2] = c;
    KBD_InitPadRepeat(gKeyboardInputMasks[2] | (gKeyboardInputMasks[0] | 0xf0 | gKeyboardInputMasks[1]));
}

#pragma thumb off

#pragma thumb on
u32 StoreKeyboardOffset(u32 offsetX, u32 offsetY) {
    u32 value0 = offsetX;
    u32 value1 = offsetY;
    u32 value2;
    value2 = (u32) &gKeyboardOffsetX;
    *(u32 *) ((value2) + 0u) = value0;
    value0 = (u32) &gKeyboardOffsetY;
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void GetKeyboardCursorRectBounds(s32 *left, s32 *top, s32 *right, s32 *bottom) {
    if (gKeyboardKeys.mCursorRect != NULL && left != NULL && top != NULL && right != NULL && bottom != NULL) {
        *left = gKeyboardKeys.mCursorRect->mX;
        *top = gKeyboardKeys.mCursorRect->mY;
        *right = gKeyboardKeys.mCursorRect->mX + gKeyboardKeys.mCursorRect->mWidth;
        *bottom = gKeyboardKeys.mCursorRect->mY + gKeyboardKeys.mCursorRect->mHeight;
        if (gKeyboardKeys.mCursorRect->mKeyId <= 0xff) {
            *left = *left + gKeyboardOffsetX;
            *top = *top + gKeyboardOffsetY;
            *right = *right + gKeyboardOffsetX;
            *bottom = *bottom + gKeyboardOffsetY;
        }
    }
}

void InitKeyboardKeysAndCanvas(struct Unk02022aa8 *font, void *bg2Char, u16 *bg2Scr, s32 d, s32 e, s32 f) {
    MI_CpuFill8(&gKeyboardKeys, 0, 0x54);
    gKeyboardCanvas.mFont = font;
    gKeyboardCanvas.mBg2Char = bg2Char;
    gKeyboardCanvas.mUnk_08 = bg2Char;
    gKeyboardCanvas.mBg2Scr = bg2Scr;
    gKeyboardCanvas.mUnk_10 = d;
    gKeyboardCanvas.mUnk_14 = e;
    gKeyboardCanvas.mUnk_1c = f;
    KBD_StartupPadTpInput();
    KBD_InitAutoRepeatValue(&data_0217b2ac, 0x28, 5);
    KBD_InitPadRepeat(gKeyboardInputMasks[2] | (gKeyboardInputMasks[0] | 0xf0 | gKeyboardInputMasks[1]));
    gCharTablePair1[0] = gCharTablePair2[0] = gCharTablePair3[0] = gCharTables[0];
    gCharTablePair1[1] = gCharTables[1];
    gCharTablePair2[1] = gCharTables[2];
    gCharTablePair3[1] = gCharTables[3];
}

#pragma thumb off

#pragma thumb on
void func_020ab07c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    gKeyboardCanvas.mUnk_18 = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab070(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    gKeyboardCanvas.mUnk_20 = value0;
}
#pragma thumb off

#pragma thumb on
void SetKeyboardCursorCallback(u16 (*arg0)(s32, u16)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &gKeyboardKeys;
    *(u32 *) ((value1) + 76u) = value0;
}
#pragma thumb off

#pragma thumb on
void SetKeyboardKeyCallback(s32 (*arg0)(u32, s32)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &gKeyboardKeys;
    *(u32 *) ((value1) + 80u) = value0;
}
#pragma thumb off

#pragma thumb on

void CallKeyboardKeyCallback(s32 a) {
    if (gKeyboardKeys.mKeyCallback != NULL) {
        if (gKeyboardKeys.mKeyCallback(GetKeyboardValueForKeyId(gKeyboardKeys.mKeyId), a) != 0) {
            gKeyboardKeys.mKeyId = 0;
        }
    }
}

void FillKeyboardBg2Scr(KeyboardKeys *keyboardKeys) {
    s32 w;
    s32 h;
    s32 i;
    s32 v1;
    BOOL j0;
    s32 j;
    volatile u16 n;

    h = keyboardKeys->mCurrentLayout->mNcgr->mUnk_02;
    w = keyboardKeys->mCurrentLayout->mNcgr->mUnk_00;
    n = h * w;
    MIi_CpuClear16(n, gKeyboardCanvas.mBg2Scr, gKeyboardCanvas.mUnk_14 * (gKeyboardCanvas.mUnk_10 * 2));
    i = 0;
    v1 = 0;
    v1 = (u32) v1;
    j0 = FALSE;
    if (i < w) {
        v1 = 0;
        v1 = (u32) v1;
        do {
            for (j = j0; j < h; j++) {
                gKeyboardCanvas.mBg2Scr[j + i * gKeyboardCanvas.mUnk_14 / 2] =
                    (gKeyboardCanvas.mUnk_18 << 12) | (j + (gKeyboardCanvas.mUnk_1c + v1));
            }
            v1 += h;
            i++;
        } while (i < w);
    }
}

u16 FindFirstCharRectIndex(KeyboardLayout *keyboardLayout) {
    u16 i;
    const KeyboardLayout *p = keyboardLayout;

    for (i = 0; i < p->mRectCount; i++) {
        if (keyboardLayout->mFixedKeyCount + 1 == keyboardLayout->mRects[i].mKeyId) {
            return i;
        }
    }
    return 0;
}

KeyboardRect *SearchButton(KeyboardKeys *keyboardKeys, s32 pointX, s32 pointY) {
    KeyboardRect *buttonRect;
    KeyboardLayout *layout;
    s32 rectCount;
    KeyboardRect *rects;
    s32 i;

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
    for (i = 0; i < rectCount; i++) {
        if (rects[i].mWidth > 1 && rects[i].mHeight > 1 && gKeyboardOffsetY + rects[i].mY <= pointY &&
            pointY < gKeyboardOffsetY + (rects[i].mY + rects[i].mHeight) && gKeyboardOffsetX + rects[i].mX <= pointX &&
            pointX < gKeyboardOffsetX + (rects[i].mX + rects[i].mWidth)) {
            return &rects[i];
        }
    }
    return NULL;
}

void RedrawKeytop(KeyboardKeys *keyboardKeys) {
    Unk02022aa8 *font;
    KeyboardRect *rect;
    Unk02022ce4_08 *u;
    NNSG2dCharWidths *charWidths;
    NNSG2dGlyph glyph;
    Unk02023374 charCanvas;
    s32 c;
    KeyboardLayout *layout;
    u32 character;
    s32 glyphIndex;
    s32 n;
    s32 charMapOffset;
    s32 marginX;
    s32 i;
    s32 firstCharRectIndex;

    font = gKeyboardCanvas.mFont;
    c = font->mUnk_00->mUnk_08->mUnk_01;
    layout = keyboardKeys->mCurrentLayout;
    MIi_CpuCopyFast(layout->mNcgr->mData, gKeyboardCanvas.mBg2Char, layout->mNcgr->mDataSize);
    NNS_G2dCharCanvasInitForBG(&charCanvas, gKeyboardCanvas.mBg2Char, layout->mNcgr->mUnk_02, layout->mNcgr->mUnk_00,
                               4);
    n = FindFirstCharRectIndex(layout);
    i = 0;
    if (layout->mRectCount - n > 0) {
        charMapOffset = 0;
        firstCharRectIndex = n;
        do {
            rect = &layout->mRects[(u32) n];
            character = *OFFSET_PTR(u16, keyboardKeys->mCharMap, charMapOffset);
            if (rect->mWidth > 1 && rect->mHeight > 1) {
                glyphIndex = NNS_G2dFontFindGlyphIndex(font, character);
                if (glyphIndex == 0xffff) {
                    glyphIndex = font->mUnk_00->mUnk_02;
                }
                charWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
                glyph.mPWidths = charWidths;
                u = font->mUnk_00->mUnk_08;
                glyph.mImage = u->mUnk_08 + glyphIndex * u->mUnk_02;
                marginX = (rect->mWidth - charWidths->mGlyphWidth) / 2;
                charCanvas.mUnk_14(&charCanvas, font, rect->mX + marginX, rect->mY + (rect->mHeight - c) / 2,
                                   gKeyboardCanvas.mUnk_20, &glyph);
            }
            n++;
            charMapOffset += 2;
            i++;
        } while (i < layout->mRectCount - firstCharRectIndex);
    }
}

void DrawKeyboard(KeyboardKeys *keyboardKeys) {
    KeyboardLayout *layout;
    KeyboardRect *e;
    KeyboardRect *r;

    layout = keyboardKeys->mCurrentLayout;
    MIi_CpuCopyFast(gKeyboardCanvas.mBg2Char, gKeyboardCanvas.mUnk_08, layout->mNcgr->mDataSize);
    MemFillWordsByBlock_inline((u8 *) gKeyboardCanvas.mUnk_08 + (layout->mNcgr->mDataSize << 5), 0x20);
    if (keyboardKeys->mChosenKeyId != 0) {
        e = layout->mRects + (keyboardKeys->mChosenKeyId - 1);
        r = e;
        do {
            AddBGCharRectangle(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                      r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
    if (keyboardKeys->mToggledKeyId != 0) {
        e = layout->mRects + (keyboardKeys->mToggledKeyId - 1);
        r = e;
        do {
            AddBGCharRectangle(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                      r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
    e = keyboardKeys->mCursorRect;
    if (e != NULL && e->mKeyId != 0 && e->mKeyId <= 0xff && e->mKeyId != data_0217b2b8[1] &&
        e->mKeyId != data_0217b2b8[0] && e != keyboardKeys->mTouchStartRect && e != keyboardKeys->mKeyDownRect) {
        r = e;
        do {
            AddToNonzeroNibblesOnRectEdge(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                          r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
    e = keyboardKeys->mKeyDownRect;
    if (e != NULL && e->mKeyId != 0 && e->mKeyId <= 0xff && e->mKeyId != data_0217b2b8[1] &&
        e->mKeyId != data_0217b2b8[0]) {
        r = e;
        do {
            AddBGCharRectangle(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                      r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
    e = keyboardKeys->mTouchStartRect;
    if (e != NULL && e->mKeyId != 0 && e->mKeyId <= 0xff && e->mKeyId != data_0217b2b8[1] &&
        e->mKeyId != data_0217b2b8[0] && e != keyboardKeys->mKeyDownRect) {
        if (keyboardKeys->mTouchRect != NULL && e->mKeyId == keyboardKeys->mTouchRect->mKeyId) {
            r = e;
            do {
                AddBGCharRectangle(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                          r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
                r += r->mNextRectOffset;
            } while (r != e);
            return;
        }
        r = e;
        do {
            AddToNonzeroNibblesOnRectEdge(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                          r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
}

u32 IsKeyboardTouchOnStartKeyId(KeyboardKeys *keyboardKeys) {
    u32 r;
    u32 b;
    KeyboardRect *touchStartRect;

    r = 0;
    b = 0;
    touchStartRect = keyboardKeys->mTouchStartRect;
    if (touchStartRect != NULL && keyboardKeys->mTouchRect != NULL) {
        b = 1;
    }
    if (b != 0) {
        if (keyboardKeys->mTouchRect->mKeyId == touchStartRect->mKeyId) {
            r = 1;
        }
    }
    return r;
}

void KBD_UpdateValue(u16 keys, TPData touchPoint) {
    u16 h;
    u16 k;
    void (*fn)(KeyboardKeys *);

    KBD_UpdatePadTpInputValue(keys, touchPoint);
    KBD_UpdatePadRepeat();
    gKeyboardKeys.mKeyId = 0;
    gKeyboardKeys.mKeyValue = 0;
    if (gKeyboardKeys.mCurrentLayout != NULL && gKeyboardKeys.mCharMap != NULL) {
        if (KBD_IsSetPadPress(gKeyboardInputMasks[0]) != 0) {
            gKeyboardKeys.mKeyDownRect = gKeyboardKeys.mCursorRect;
        } else if (KBD_IsSetPadPress(gKeyboardInputMasks[1]) != 0) {
            gKeyboardKeys.mKeyDownRect = gKeyboardKeys.mCurrentLayout->mRects;
        } else {
            gKeyboardKeys.mKeyDownRect = NULL;
        }
        k = gKeyboardInputMasks[0];
        if ((KBD_GetPadTrigRepeat() & k) != 0) {
            gKeyboardKeys.mKeyId = gKeyboardKeys.mCursorRect->mKeyId;
            CallKeyboardKeyCallback(KBD_IsSetPadTrig(k));
        } else {
            k = gKeyboardInputMasks[1];
            if ((KBD_GetPadTrigRepeat() & k) != 0) {
                gKeyboardKeys.mKeyId = 1;
                CallKeyboardKeyCallback(KBD_IsSetPadTrig(k));
            } else {
                k = gKeyboardInputMasks[2];
                if ((KBD_GetPadTrigRepeat() & k) != 0) {
                    fn = gKeyboardKeys.mCurrentLayout->mCallback;
                    if (fn == AsciiLayoutCallback) {
                        h = data_0217b2b8[1];
                        if (h == 0) {
                            gKeyboardKeys.mKeyId = 4;
                        } else if (h == 4) {
                            gKeyboardKeys.mKeyId = 5;
                        } else if (h == 5) {
                            gKeyboardKeys.mKeyId = 5;
                        }
                        CallKeyboardKeyCallback(KBD_IsSetPadTrig(k));
                    } else if (fn == HiraganaKatakanaLayoutCallback) {
                        gKeyboardKeys.mKeyId = 0xffff;
                        CallKeyboardKeyCallback(KBD_IsSetPadTrig(k));
                    }
                }
            }
        }
        if ((KBD_GetPadTrigRepeat() & 0x40) != 0) {
            gKeyboardKeys.mCursorRect =
                MoveCursor(0x40, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((KBD_GetPadTrigRepeat() & 0x80) != 0) {
            gKeyboardKeys.mCursorRect =
                MoveCursor(0x80, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((KBD_GetPadTrigRepeat() & 0x20) != 0) {
            gKeyboardKeys.mCursorRect =
                MoveCursor(0x20, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((KBD_GetPadTrigRepeat() & 0x10) != 0) {
            gKeyboardKeys.mCursorRect =
                MoveCursor(0x10, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        }
        if (GetKeyboardTouchDown() != 0) {
            gKeyboardKeys.mTouchRect =
                SearchButton(&gKeyboardKeys, GetKeyboardLastTouchX(), GetKeyboardLastTouchY());
        }
        if (GetKeyboardTouchStatus() == 1) {
            gKeyboardKeys.mTouchStartRect =
                SearchButton(&gKeyboardKeys, GetKeyboardLastTouchX(), GetKeyboardLastTouchY());
            if (gKeyboardKeys.mTouchStartRect != NULL) {
                gKeyboardKeys.mKeyId = gKeyboardKeys.mTouchStartRect->mKeyId;
                CallKeyboardKeyCallback(1);
            }
        } else if (GetKeyboardTouchStatus() == 3) {
            gKeyboardKeys.mTouchStartRect = NULL;
        }
        if (IsKeyboardTouchOnStartKeyId(&gKeyboardKeys) != 0) {
            KBD_UpdateAutoRepeat(&data_0217b2ac);
            if (KBD_IsTriggerAutoRepeat(&data_0217b2ac) != FALSE) {
                gKeyboardKeys.mKeyId = gKeyboardKeys.mTouchStartRect->mKeyId;
                CallKeyboardKeyCallback(0);
            }
        } else {
            KBD_ResetAutoRepeat(&data_0217b2ac);
        }
        gKeyboardKeys.mKeyValue = GetKeyboardValueForKeyId(gKeyboardKeys.mKeyId);
        if (gKeyboardKeys.mKeyValue >= 0x20) {
            fn = gKeyboardKeys.mCurrentLayout->mCallback;
            if (fn == AsciiLayoutCallback) {
                if (data_0217b2b8[1] == 4) {
                    data_0217b2b8[1] = 0;
                }
            } else if (fn == HiraganaKatakanaLayoutCallback) {
                data_0217b2b8[1] = 0;
            }
        }
        if (gKeyboardKeys.mKeyId != 0 && gKeyboardKeys.mCurrentLayout->mCallback != NULL) {
            gKeyboardKeys.mCurrentLayout->mCallback(&gKeyboardKeys);
        }
        RedrawKeytop(&gKeyboardKeys);
        DrawKeyboard(&gKeyboardKeys);
    }
}

void KBD_Update(void) {
    TPData rawSample;
    TPData touchPoint;

    if (KBD_IsEnableTpSampling() != 0) {
        do {
            TP_RequestSamplingAsync();
        } while (TP_WaitRawResult(&rawSample) != 0);
        TP_GetCalibratedPoint(&touchPoint, &rawSample);
    } else {
        touchPoint.mTouch = 0;
        touchPoint.mValidity = 3;
    }
    KBD_UpdateValue(((*(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff, touchPoint);
}

#pragma thumb off
