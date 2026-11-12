#include "Main/Menu/keyboard_keys.h"
#include "Main/Unknown/code_020aa81c.h"
#include "code_0200fc8c.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020ab5bc.h"
#include "Main/Graphics/font_and_player_character.h"
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
#include "Main/MapObjects/iron_ball_kart.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_020aba9c.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_020aa810.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/code_021059e0.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "registers.h"
#include "code_0200fe74.h"
#include "Main/Unknown/code_020a9f20.h"
#include "code_0213ecf8.h"

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
    keyboardTextEntry = gKeyboardTextEntry;
    textIndex = keyboardTextEntry->mTextIndex;
    index = keyboardTextEntry->mTextLimit - 1;
    if (textIndex == index && keyboardTextEntry->mText[textIndex] >= 0x20) {
        lastCharIndex = textIndex;
    } else {
        index = textIndex - 1;
        if (index >= 0 && keyboardTextEntry->mText[index] >= 0x20) {
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
        case 6:
            if (GetKeyboardChosenKeyValue() != 6) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1e7);
            } else {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case 7:
            if (GetKeyboardChosenKeyValue() != 7) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1e8);
            } else {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case 0x10:
            convertedChar = ConvertCharPair1(gKeyboardTextEntry->mText[lastCharIndex]);
            currentChar = gKeyboardTextEntry->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case 0x11:
            convertedChar = ConvertCharPair2(gKeyboardTextEntry->mText[lastCharIndex]);
            currentChar = gKeyboardTextEntry->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case 0x12:
            convertedChar = ConvertCharPair3(gKeyboardTextEntry->mText[lastCharIndex]);
            currentChar = gKeyboardTextEntry->mText[lastCharIndex];
            if (currentChar == convertedChar) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1ed);
                result = 3;
            }
            break;
        case 4:
        case 5:
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1eb);
            break;
        case 0x20:
        case 0x3000:
            if (newPress != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ea);
            }
            break;
        case 8:
            if (newPress != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, result, 0x1e9);
            }
            break;
        default:
            if (newPress != 0 && keyValue >= 0x20) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1e6);
            }
            break;
    }
    return result;
}

u16 KeyboardCursorCallback(s32 rectValue, u16 keys) {
    u16 nextRectValue;

    nextRectValue = 0;
    switch (rectValue) {
        case 1:
            if ((keys & 0x20) != 0 || (keys & 0x10) != 0) {
                nextRectValue = 2;
            } else if ((keys & 0x40) != 0) {
                nextRectValue = data_02156808[gKeyboardTextEntry->mLayoutIndex].mUpFromRect1;
            } else if ((keys & 0x80) != 0) {
                nextRectValue = data_02156808[gKeyboardTextEntry->mLayoutIndex].mDownFromRect1;
            }
            break;
        case 2:
            if ((keys & 0x20) != 0 || (keys & 0x10) != 0) {
                nextRectValue = 1;
            } else if ((keys & 0x40) != 0) {
                nextRectValue = data_02156808[gKeyboardTextEntry->mLayoutIndex].mUpFromRect2;
            } else if ((keys & 0x80) != 0) {
                nextRectValue = data_02156808[gKeyboardTextEntry->mLayoutIndex].mDownFromRect2;
            }
            break;
    }
    StartSoundOncePerFrame(0x1e4);
    return nextRectValue;
}

void InitKeyboardTextEntry(s32 screenMapWidth, s32 screenMapHeight, s32 textCapacity) {
    KeyboardTextEntry *keyboardTextEntry;

    gKeyboardTextEntry = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x78);
    gKeyboardTextEntry->mTextCapacity = textCapacity;
    gKeyboardTextEntry->mTextLimit = textCapacity;
    gKeyboardTextEntry->mTextIndex = 0;
    gKeyboardTextEntry->mTextIndexCopy = 0;
    gKeyboardTextEntry->mText = HeapAlloc(GetHeap(GetCurrentHeapCall()), (textCapacity + 1) * 2);
    gKeyboardTextEntry->mBg2ScrSize = screenMapHeight * (screenMapWidth * 2);
    gKeyboardTextEntry->mBg2Scr = HeapAlloc(GetHeap(GetCurrentHeapCall()), gKeyboardTextEntry->mBg2ScrSize);
    gKeyboardTextEntry->mBg2CharSize = 0x4020;
    gKeyboardTextEntry->mBg2Char =
        HeapAllocAligned(GetHeap(GetCurrentHeapCall()), gKeyboardTextEntry->mBg2CharSize, 0x20);
    keyboardTextEntry = gKeyboardTextEntry;
    InitKeyboardKeysAndCanvas(GetFontByIndex(0), keyboardTextEntry->mBg2Char, keyboardTextEntry->mBg2Scr,
                              screenMapWidth, screenMapHeight, 0);
    SetKeyboardCursorCallback(KeyboardCursorCallback);
    SetKeyboardKeyCallback(KeyboardKeyCallback);
    SetKeyboardScreenMapTopBits(0);
    SetKeyboardGlyphColor(1);
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
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[0], FindSceneFile(gKeyboardSB10keyNcgrName));
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[2], FindSceneFile(gKeyboardSBAsciiNcgrName));
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[1], FindSceneFile(gKeyboardSBJpNcgrName));
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[3], FindSceneFile(gKeyboardSBEuroNcgrName));
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[4], FindSceneFile(gKeyboardSBPictNcgrName));
    LocateNcgr2(&gKeyboardTextEntry->mNcgrs[5], FindSceneFile(data_02167c6c));
    gKeyboardTextEntry->mKbds[0] = FindSceneFile(g10KeyKbdName);
    gKeyboardTextEntry->mKbds[2] = FindSceneFile(gAsciiKbdName);
    gKeyboardTextEntry->mKbds[1] = FindSceneFile(gJpKbdName);
    gKeyboardTextEntry->mKbds[3] = FindSceneFile(gEuroKbdName);
    gKeyboardTextEntry->mKbds[4] = FindSceneFile(gPictoKbdName);
    gKeyboardTextEntry->mKbds[5] = FindSceneFile(data_02167cbc);
    gKbdmapAscii = FindSceneFile(gAsciiKbdmapName);
    gKbdmapAsciiCaps = FindSceneFile(gAsciiCapsKbdmapName);
    gKbdmapAsciiShift = FindSceneFile(gAsciiShiftKbdmapName);
    gKbdmapHiragana = FindSceneFile(gHiraganaKbdmapName);
    gKbdmapHiraganaDakuten = FindSceneFile(gHiraganaDakutenKbdmapName);
    gKbdmapHiraganaHandaku = FindSceneFile(gHiraganaHandakuKbdmapName);
    gKbdmapHiraganaSmall = FindSceneFile(gHiraganaSmallKbdmapName);
    gKbdmapKatakana = FindSceneFile(gKatakanaKbdmapName);
    gKbdmapKatakanaDakuten = FindSceneFile(gKatakanaDakutenKbdmapName);
    gKbdmapKatakanaHandaku = FindSceneFile(gKatakanaHandakuKbdmapName);
    gKbdmapKatakanaSmall = FindSceneFile(gKatakanaSmallKbdmapName);
    gKbdmapOther1 = FindSceneFile(gOther1KbdmapName);
    gKbdmapOther2 = FindSceneFile(gOther2KbdmapName);
    gKbdmapOther3 = FindSceneFile(gOther3KbdmapName);
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
    inputSlotIndex = UNK_02175628_INDEX_8;
    if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & 8) != 0) {
        if (GetKeyboardCursorValueWrapper() != 1) {
            MoveKeyboardCursorToValueWrapper(1);
        }
    } else if (GetKeyboardKeyValue() == 8) {
        gKeyboardTextEntry->mTextIndexCopy = gKeyboardTextEntry->mTextIndex;
        keyboardTextEntry = gKeyboardTextEntry;
        if (keyboardTextEntry->mTextIndex != 0) {
            if (keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] == 0) {
                keyboardTextEntry->mTextIndex--;
            }
            gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextIndex] = 0;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1e3);
        }
    } else if (GetKeyboardKeyValue() >= 0x20) {
        gKeyboardTextEntry->mTextIndexCopy = gKeyboardTextEntry->mTextIndex;
        keyboardTextEntry = gKeyboardTextEntry;
        if (keyboardTextEntry->mTextIndex < keyboardTextEntry->mTextLimit) {
            if (keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] != GetKeyboardKeyValue()) {
                keyboardTextEntry = gKeyboardTextEntry;
                keyboardTextEntry->mText[keyboardTextEntry->mTextIndex] = GetKeyboardKeyValue();
                gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextIndex + 1] = 0;
                if (gKeyboardTextEntry->mTextIndex < gKeyboardTextEntry->mTextLimit - 1) {
                    gKeyboardTextEntry->mTextIndex++;
                }
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1e2);
            }
        }
    } else if (GetKeyboardKeyValue() == 0x10) {
        convertedChar = ConvertCharPair1(gKeyboardTextEntry->mText[lastCharIndex]);
        if (convertedChar != gKeyboardTextEntry->mText[lastCharIndex]) {
            gKeyboardTextEntry->mText[lastCharIndex] = convertedChar;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x11) {
        convertedChar = ConvertCharPair2(gKeyboardTextEntry->mText[lastCharIndex]);
        if (convertedChar != gKeyboardTextEntry->mText[lastCharIndex]) {
            gKeyboardTextEntry->mText[lastCharIndex] = convertedChar;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x12) {
        convertedChar = ConvertCharPair3(gKeyboardTextEntry->mText[lastCharIndex]);
        if (convertedChar != gKeyboardTextEntry->mText[lastCharIndex]) {
            gKeyboardTextEntry->mText[lastCharIndex] = convertedChar;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x13) {
        convertedChar = CycleCharTables(gKeyboardTextEntry->mText[lastCharIndex]);
        if (convertedChar != gKeyboardTextEntry->mText[lastCharIndex]) {
            gKeyboardTextEntry->mText[lastCharIndex] = convertedChar;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ec);
        } else {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ed);
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
void SetKeyboardScreenMapTopBitsWrapper(u32 topBits) {
    u32 topBitsCopy = topBits;
    u32 unusedValue;
    SetKeyboardScreenMapTopBits(topBitsCopy);
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
    s32 charIndex;

    for (charIndex = 0; charIndex < gKeyboardTextEntry->mTextCapacity; charIndex++) {
        gKeyboardTextEntry->mText[charIndex] = 0;
    }
    for (charIndex = 0; charIndex < gKeyboardTextEntry->mTextLimit; charIndex++) {
        gKeyboardTextEntry->mText[charIndex] = *text;
        if (*text == 0) {
            gKeyboardTextEntry->mTextIndex = charIndex;
            gKeyboardTextEntry->mTextIndexCopy = gKeyboardTextEntry->mTextIndex;
            return;
        }
        text++;
    }
    gKeyboardTextEntry->mTextIndex = gKeyboardTextEntry->mTextLimit - 1;
    gKeyboardTextEntry->mTextIndexCopy = gKeyboardTextEntry->mTextIndex;
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
        gKeyboardTextEntry->mTextIndexCopy = gKeyboardTextEntry->mTextIndex;
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
            gKeyboardInput.mTouchStatus = touch != 0 ? 1 : 3;
            gKeyboardInput.mTouchHeldFrames = 0;
        } else if (touch != 0) {
            gKeyboardInput.mTouchStatus = 2;
            gKeyboardInput.mTouchHeldFrames++;
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
    s32 rectIndex;
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
        for (rectIndex = 0; rectIndex < rectCount; rectIndex++) {
            if (rects[rectIndex].mWidth > 1 && rects[rectIndex].mHeight > 1 && keyboardRect == &rects[rectIndex]) {
                switch (rectIndex) {
                    case 0:
                        return 8;
                    case 1:
                        return 0xa;
                    case 2:
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

void InitKeyboardKeysAndCanvas(struct Unk02022aa8 *font, void *bg2Char, u16 *bg2Scr, s32 screenMapWidth,
                               s32 screenMapHeight, s32 screenMapTileBase) {
    MI_CpuFill8(&gKeyboardKeys, 0, 0x54);
    gKeyboardCanvas.mFont = font;
    gKeyboardCanvas.mBg2Char = bg2Char;
    gKeyboardCanvas.mMarkedBg2Char = bg2Char;
    gKeyboardCanvas.mBg2Scr = bg2Scr;
    gKeyboardCanvas.mScreenMapWidth = screenMapWidth;
    gKeyboardCanvas.mScreenMapHeight = screenMapHeight;
    gKeyboardCanvas.mScreenMapTileBase = screenMapTileBase;
    InitKeyboardInput();
    SetupRepeatCounter(&data_0217b2ac, 0x28, 5);
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
void SetKeyboardCursorCallback(u16 (*arg0)(s32, u16)) {
    gKeyboardKeys.mCursorCallback = arg0;
}
#pragma thumb off

#pragma thumb on
void SetKeyboardKeyCallback(s32 (*arg0)(u32, s32)) {
    gKeyboardKeys.mKeyCallback = arg0;
}
#pragma thumb off

#pragma thumb on

void CallKeyboardKeyCallback(s32 newPress) {
    if (gKeyboardKeys.mKeyCallback != NULL) {
        if (gKeyboardKeys.mKeyCallback(GetKeyboardValueForKeyId(gKeyboardKeys.mKeyId), newPress) != 0) {
            gKeyboardKeys.mKeyId = 0;
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

    columnCount = keyboardKeys->mCurrentLayout->mNcgr->mUnk_02;
    rowCount = keyboardKeys->mCurrentLayout->mNcgr->mUnk_00;
    clearValue = columnCount * rowCount;
    MIi_CpuClear16(clearValue, gKeyboardCanvas.mBg2Scr,
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
    Unk02022aa8 *font;
    KeyboardRect *rect;
    FontGlyph *glyphInfo;
    NNSG2dCharWidths *charWidths;
    NNSG2dGlyph glyph;
    Unk02023374 charCanvas;
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
    NNS_G2dCharCanvasInitForBG(&charCanvas, gKeyboardCanvas.mBg2Char, layout->mNcgr->mUnk_02, layout->mNcgr->mUnk_00,
                               4);
    rectIndex = FindFirstCharRectIndex(layout);
    drawnCount = 0;
    if (layout->mRectCount - rectIndex > 0) {
        charMapOffset = 0;
        firstCharRectIndex = rectIndex;
        do {
            rect = GetKeyboardLayoutRect(layout, rectIndex);
            character = *OFFSET_PTR(u16, keyboardKeys->mCharMap, charMapOffset);
            if (rect->mWidth > 1 && rect->mHeight > 1) {
                glyphIndex = NNS_G2dFontFindGlyphIndex(font, character);
                if (glyphIndex == 0xffff) {
                    glyphIndex = font->mPRes->mAlterCharIndex;
                }
                charWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
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
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mMarkedBg2Char, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3,
                                      8, ringRect->mX, ringRect->mY, ringRect->mX + ringRect->mWidth,
                                      ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
    if (keyboardKeys->mToggledKeyId != 0) {
        startRect = layout->mRects + (keyboardKeys->mToggledKeyId - 1);
        ringRect = startRect;
        do {
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mMarkedBg2Char, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3,
                                      8, ringRect->mX, ringRect->mY, ringRect->mX + ringRect->mWidth,
                                      ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
    startRect = keyboardKeys->mCursorRect;
    if (startRect != NULL && startRect->mKeyId != 0 && startRect->mKeyId <= 0xff &&
        startRect->mKeyId != gKeyboardLayoutKeyIds[1] && startRect->mKeyId != gKeyboardLayoutKeyIds[0] &&
        startRect != keyboardKeys->mTouchStartRect && startRect != keyboardKeys->mKeyDownRect) {
        ringRect = startRect;
        do {
            AddToNonzeroNibblesOnRectEdge(
                gKeyboardCanvas.mMarkedBg2Char, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8, ringRect->mX,
                ringRect->mY, ringRect->mX + ringRect->mWidth, ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
    startRect = keyboardKeys->mKeyDownRect;
    if (startRect != NULL && startRect->mKeyId != 0 && startRect->mKeyId <= 0xff &&
        startRect->mKeyId != gKeyboardLayoutKeyIds[1] && startRect->mKeyId != gKeyboardLayoutKeyIds[0]) {
        ringRect = startRect;
        do {
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mMarkedBg2Char, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3,
                                      8, ringRect->mX, ringRect->mY, ringRect->mX + ringRect->mWidth,
                                      ringRect->mY + ringRect->mHeight);
            ringRect += ringRect->mNextRectOffset;
        } while (ringRect != startRect);
    }
    startRect = keyboardKeys->mTouchStartRect;
    if (startRect != NULL && startRect->mKeyId != 0 && startRect->mKeyId <= 0xff &&
        startRect->mKeyId != gKeyboardLayoutKeyIds[1] && startRect->mKeyId != gKeyboardLayoutKeyIds[0] &&
        startRect != keyboardKeys->mKeyDownRect) {
        if (keyboardKeys->mTouchRect != NULL && startRect->mKeyId == keyboardKeys->mTouchRect->mKeyId) {
            ringRect = startRect;
            do {
                AddToNonzeroNibblesInRect(
                    gKeyboardCanvas.mMarkedBg2Char, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8, ringRect->mX,
                    ringRect->mY, ringRect->mX + ringRect->mWidth, ringRect->mY + ringRect->mHeight);
                ringRect += ringRect->mNextRectOffset;
            } while (ringRect != startRect);
            return;
        }
        ringRect = startRect;
        do {
            AddToNonzeroNibblesOnRectEdge(
                gKeyboardCanvas.mMarkedBg2Char, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8, ringRect->mX,
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
    gKeyboardKeys.mKeyId = 0;
    gKeyboardKeys.mKeyValue = 0;
    if (gKeyboardKeys.mCurrentLayout != NULL && gKeyboardKeys.mCharMap != NULL) {
        if (GetKeyboardKeysDown(gKeyboardInputMasks[0]) != 0) {
            gKeyboardKeys.mKeyDownRect = gKeyboardKeys.mCursorRect;
        } else if (GetKeyboardKeysDown(gKeyboardInputMasks[1]) != 0) {
            gKeyboardKeys.mKeyDownRect = gKeyboardKeys.mCurrentLayout->mRects;
        } else {
            gKeyboardKeys.mKeyDownRect = NULL;
        }
        keyMask = gKeyboardInputMasks[0];
        if ((GetKeyboardKeysPressedOrRepeated() & keyMask) != 0) {
            gKeyboardKeys.mKeyId = gKeyboardKeys.mCursorRect->mKeyId;
            CallKeyboardKeyCallback(GetKeyboardKeysPressed(keyMask));
        } else {
            keyMask = gKeyboardInputMasks[1];
            if ((GetKeyboardKeysPressedOrRepeated() & keyMask) != 0) {
                gKeyboardKeys.mKeyId = 1;
                CallKeyboardKeyCallback(GetKeyboardKeysPressed(keyMask));
            } else {
                keyMask = gKeyboardInputMasks[2];
                if ((GetKeyboardKeysPressedOrRepeated() & keyMask) != 0) {
                    fn = gKeyboardKeys.mCurrentLayout->mCallback;
                    if (fn == AsciiLayoutCallback) {
                        layoutKeyId = gKeyboardLayoutKeyIds[1];
                        if (layoutKeyId == 0) {
                            gKeyboardKeys.mKeyId = 4;
                        } else if (layoutKeyId == 4) {
                            gKeyboardKeys.mKeyId = 5;
                        } else if (layoutKeyId == 5) {
                            gKeyboardKeys.mKeyId = 5;
                        }
                        CallKeyboardKeyCallback(GetKeyboardKeysPressed(keyMask));
                    } else if (fn == HiraganaKatakanaLayoutCallback) {
                        gKeyboardKeys.mKeyId = 0xffff;
                        CallKeyboardKeyCallback(GetKeyboardKeysPressed(keyMask));
                    }
                }
            }
        }
        if ((GetKeyboardKeysPressedOrRepeated() & 0x40) != 0) {
            gKeyboardKeys.mCursorRect =
                FindKeyboardRectInDirection(0x40, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x80) != 0) {
            gKeyboardKeys.mCursorRect =
                FindKeyboardRectInDirection(0x80, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x20) != 0) {
            gKeyboardKeys.mCursorRect =
                FindKeyboardRectInDirection(0x20, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x10) != 0) {
            gKeyboardKeys.mCursorRect =
                FindKeyboardRectInDirection(0x10, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        }
        if (GetKeyboardTouchDown() != 0) {
            gKeyboardKeys.mTouchRect =
                FindKeyboardRectAt(&gKeyboardKeys, GetKeyboardLastTouchX(), GetKeyboardLastTouchY());
        }
        if (GetKeyboardTouchStatus() == 1) {
            gKeyboardKeys.mTouchStartRect =
                FindKeyboardRectAt(&gKeyboardKeys, GetKeyboardLastTouchX(), GetKeyboardLastTouchY());
            if (gKeyboardKeys.mTouchStartRect != NULL) {
                gKeyboardKeys.mKeyId = gKeyboardKeys.mTouchStartRect->mKeyId;
                CallKeyboardKeyCallback(1);
            }
        } else if (GetKeyboardTouchStatus() == 3) {
            gKeyboardKeys.mTouchStartRect = NULL;
        }
        if (IsKeyboardTouchOnStartKeyId(&gKeyboardKeys) != 0) {
            AdvanceRepeatCounter(&data_0217b2ac);
            if (IsRepeatCounterFiring(&data_0217b2ac) != FALSE) {
                gKeyboardKeys.mKeyId = gKeyboardKeys.mTouchStartRect->mKeyId;
                CallKeyboardKeyCallback(0);
            }
        } else {
            ResetRepeatCounter(&data_0217b2ac);
        }
        gKeyboardKeys.mKeyValue = GetKeyboardValueForKeyId(gKeyboardKeys.mKeyId);
        if (gKeyboardKeys.mKeyValue >= 0x20) {
            fn = gKeyboardKeys.mCurrentLayout->mCallback;
            if (fn == AsciiLayoutCallback) {
                if (gKeyboardLayoutKeyIds[1] == 4) {
                    gKeyboardLayoutKeyIds[1] = 0;
                }
            } else if (fn == HiraganaKatakanaLayoutCallback) {
                gKeyboardLayoutKeyIds[1] = 0;
            }
        }
        if (gKeyboardKeys.mKeyId != 0 && gKeyboardKeys.mCurrentLayout->mCallback != NULL) {
            gKeyboardKeys.mCurrentLayout->mCallback(&gKeyboardKeys);
        }
        DrawKeyboardGlyphs(&gKeyboardKeys);
        MarkKeyboardRects(&gKeyboardKeys);
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
        touchPoint.mValidity = 3;
    }
    AdvanceKeyboardKeys(((reg_PAD_KEYINPUT | SYSTEM_WORK->mButtonXY) ^ 0x2fff) & 0x2fff, touchPoint);
}

#pragma thumb off

#pragma thumb on
u32 GetKeyboardKeyValue(void) {
    u32 keyValue;
    keyValue = gKeyboardKeys.mKeyValue;
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
    if (cursorRect->mKeyId <= 0xff) {
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

    if (gKeyboardKeys.mCursorCallback != NULL) {
        callbackResult = gKeyboardKeys.mCursorCallback(GetKeyboardRectValue(rect), direction);
        if (callbackResult != 0) {
            callbackRect = FindKeyboardRectByValue(callbackResult);
            if (callbackRect != NULL) {
                return callbackRect;
            }
        }
    }
    if (rect->mKeyId <= 0xff) {
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
                ncgr = gKeyboardKeys.mCurrentLayout->mNcgr;
                spanX = ncgr->mUnk_02 << 3;
                spanY = ncgr->mUnk_00 << 3;
                localX = scanX - offsetX;
                margin = data_usa_021679f8;
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
                foundRect = FindKeyboardRectAt(&gKeyboardKeys, wrappedX, wrappedY);
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

    gKeyboardKeys.mCurrentLayout = &data_0217b294;
    gKeyboardKeys.mCurrentLayout->mRects = rects;
    gKeyboardKeys.mCurrentLayout->mNcgr = ncgr;
    gKeyboardKeys.mCurrentLayout->mCallback = callback;
    gKeyboardKeys.mCurrentLayout->mFixedKeyCount = fixedCount - 1;
    gKeyboardKeys.mCurrentLayout->mRectCount = rectCount;
    gKeyboardKeys.mCharMap = charMap + 1;
    if (gKeyboardKeys.mTouchStartRect != NULL) {
        touchX = GetKeyboardLastTouchX();
        touchY = GetKeyboardLastTouchY();
        gKeyboardKeys.mTouchStartRect = FindKeyboardRectAt(&gKeyboardKeys, touchX, touchY);
    }
    FillKeyboardBg2Scr(&gKeyboardKeys);
    DrawKeyboardGlyphs(&gKeyboardKeys);
    MarkKeyboardRects(&gKeyboardKeys);
    RefreshKeyboardCursor(&gKeyboardKeys);
}

void SetupKeyboardLayoutHiragana(KeyboardRect *rects, Ncgr *ncgr, u32 rectCount) {
    gKeyboardLayoutKeyIds[0] = 4;
    gKeyboardLayoutKeyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, HiraganaKatakanaLayoutCallback, 9, rectCount, gKbdmapHiragana);
}

#pragma thumb off

#pragma thumb on

void SetupKeyboardLayoutAscii(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount) {
    u16 *keyIds;
    keyIds = (u16 *) &gKeyboardLayoutKeyIds;
    *(u16 *) &gKeyboardLayoutKeyIds = 0;
    keyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, AsciiLayoutCallback, 6, rectCount, gKbdmapAscii);
}

void SetupKeyboardLayoutOther1(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount) {
    u16 *keyIds;
    keyIds = (u16 *) &gKeyboardLayoutKeyIds;
    *(u16 *) &gKeyboardLayoutKeyIds = 0;
    keyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, NULL, 4, rectCount, gKbdmapOther1);
}

void SetupKeyboardLayoutOther2(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount) {
    u16 *keyIds;
    keyIds = (u16 *) &gKeyboardLayoutKeyIds;
    *(u16 *) &gKeyboardLayoutKeyIds = 0;
    keyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, NULL, 4, rectCount, gKbdmapOther2);
}

void SetupKeyboardLayoutOther3(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount) {
    u16 *keyIds;
    keyIds = (u16 *) &gKeyboardLayoutKeyIds;
    *(u16 *) &gKeyboardLayoutKeyIds = 0;
    keyIds[1] = 0;
    SetupKeyboardLayout(rects, ncgr, NULL, 4, rectCount, gKbdmapOther3);
}

#pragma thumb off

#pragma thumb on

void SetKeyboardRect(KeyboardRect *rect, u32 left, u32 top, u32 right, u32 bottom) {
    if (rect != NULL) {
        rect->mX = left;
        rect->mY = top;
        rect->mWidth = right - left;
        rect->mHeight = bottom - top;
        rect->mNextRectOffset = 0;
        rect->mKeyId = 0xff00;
    }
}

#pragma thumb off

#pragma thumb on

void SetKeyboardButton0Rect(u32 left, u32 top, u32 right, u32 bottom) {
    SetKeyboardRect(&gKeyboardKeys.mButton0Rect, left, top, right, bottom);
}

void SetKeyboardButton1Rect(u32 left, u32 top, u32 right, u32 bottom) {
    SetKeyboardRect(&gKeyboardKeys.mButton1Rect, left, top, right, bottom);
}

#pragma thumb off
