#include "Main/Unknown/code_020a9ed8.h"

#include "Main/Unknown/code_020a9f20.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "code_0213ecf8.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/code_020aa810.h"

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
