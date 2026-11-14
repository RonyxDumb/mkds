#include "code_02022aa8.h"

#include "snd_bank.h"
#include "code_020245a4.h"
#include "Main/Menu/data_02153000.h"
#include "Main/Graphics/cell_file_set.h"
#include "g2d_CharCanvas.h"
#include "Main/Graphics/layout_entry_angle.h" // OamAttrEntry

void NNS_G2dMapScrToCharText(u16 *scnBase, s32 areaWidth, s32 areaHeight, s32 areaLeft, s32 areaTop, s32 scnWidth,
                             s32 charNo, u32 cplt) {
    s32 endCol;
    s32 endRow;
    s32 column;
    u16 *screenRow;
    u32 cpltBits;
    s32 rowIdx;
    s32 colIdx;

    if (scnWidth <= 0x20) {
        NNS_G2dMapScrToChar256x16Pltt(scnBase + (scnWidth * areaTop + areaLeft), areaWidth, areaHeight, scnWidth,
                                      charNo, cplt);
        return;
    }
    endRow = areaTop + areaHeight;
    endCol = areaLeft + areaWidth;
    cpltBits = (u16) (cplt << 12);
    for (; areaTop < endRow; areaTop++) {
        if (areaTop < 0x20) {
            rowIdx = areaTop;
        } else {
            rowIdx = areaTop + 0x20;
        }
        column = areaLeft;
        screenRow = scnBase + rowIdx * 32;
        for (; column < endCol; column++) {
            if (column < 0x20) {
                colIdx = column;
            } else {
                colIdx = column + 0x3e0;
            }
            screenRow[colIdx] = cpltBits | charNo;
            charNo++;
        }
    }
}

void NNS_G2dMapScrToChar256x16Pltt(u16 *areaBase, s32 areaWidth, s32 areaHeight, s32 scnWidth, s32 charNo, u32 cplt) {
    s32 columnIndex;
    s32 rowIndex;
    u16 *screenRow;
    u32 cpltBits;

    cpltBits = (u16) (cplt << 12);
    for (rowIndex = 0; rowIndex < areaHeight; rowIndex++) {
        screenRow = areaBase;
        for (columnIndex = 0; columnIndex < areaWidth; columnIndex++) {
            *screenRow++ = cpltBits | charNo++;
        }
        areaBase += scnWidth;
    }
}

u32 NNSi_G2dCalcRequiredOBJ(u32 areaWidth, u32 areaHeight) {
    u32 wholeW;
    u32 wholeH;
    u32 widthFour;
    u32 heightFour;
    u32 widthRest;
    u32 heightRest;
    u32 total;

    wholeW = areaWidth >> 3;
    wholeH = areaHeight >> 3;
    widthFour = (areaWidth & 4) >> 2;
    heightFour = (areaHeight & 4) >> 2;
    widthRest = ((areaWidth & 2) >> 1) + (areaWidth & 1);
    heightRest = ((areaHeight & 2) >> 1) + (areaHeight & 1);
    total = 0;
    total += wholeW * wholeH;
    total += wholeH * (widthFour + (widthRest << 1));
    total += wholeW * (heightFour + (heightRest << 1));
    return (widthRest + widthFour) * (heightRest + heightFour) + total;
}

static inline u32 clz_inline(u32 value) {
    u32 leadingZeros;
    asm { clz leadingZeros, value }
    return leadingZeros;
}

s32 NNS_G2dArrangeOBJ1D(void *oam, s32 areaWidth, s32 areaHeight, s32 originX, s32 originY, s32 color, s32 charName,
                        s32 vramMode) {
    OamAttrEntry *pObj;
    const u8 *sizeEntry;
    s32 heightLog;
    s32 widthLog;
    s32 widthShift;
    s32 heightShift;
    u32 alignedWidth;
    u32 alignedHeight;
    s32 nameUnit;
    s32 numX;
    s32 charNameStep;
    s32 colIdx;
    s32 objY;
    s32 objCount;
    s32 numY;
    s32 objShape;
    s32 oy;
    u32 objX;
    s32 rest;
    u32 remainder;
    s32 subX;

    pObj = oam;
    if (areaWidth >= 8) {
        widthLog = 3;
    } else {
        widthLog = 31 - clz_inline(areaWidth);
    }
    if (areaHeight >= 8) {
        heightLog = 3;
    } else {
        heightLog = 31 - clz_inline(areaHeight);
    }
    sizeEntry = objs[heightLog][widthLog];
    widthShift = sizeEntry[0];
    heightShift = sizeEntry[1];
    alignedWidth = areaWidth & (-1 << widthShift);
    alignedHeight = areaHeight & (-1 << heightShift);
    if (color == 0) {
        nameUnit = 1;
    } else {
        nameUnit = 2;
    }
    objCount = 0;
    objShape = OBJSizeToShape(sizeEntry);
    numX = areaWidth >> widthShift;
    numY = areaHeight >> heightShift;
    charNameStep = (nameUnit << widthShift << heightShift) >> vramMode;
    for (oy = 0; oy < numY; oy++) {
        objY = originY + (oy << heightShift) * 8;
        for (colIdx = 0; colIdx < numX; colIdx++) {
            objX = (originX + (colIdx << widthShift) * 8) & 0x1ff;
            pObj->mUnk_00 = (pObj->mUnk_00 & 0xfe00ff00) | (objY & 0xff) | (objX << 16);
            pObj->mUnk_00 = (pObj->mUnk_00 & 0x3fff3fff) | objShape;
            pObj->mUnk_04 = (pObj->mUnk_04 & -0x400) | charName;
            charName += charNameStep;
            pObj->mUnk_00 = (pObj->mUnk_00 & ~0x2000) | (color << 13);
            pObj++;
        }
    }
    objCount += numX * numY;
    if (alignedWidth < areaWidth) {
        remainder = areaWidth - alignedWidth;
        subX = originX + alignedWidth * 8;
        rest = NNS_G2dArrangeOBJ1D(pObj, remainder, alignedHeight, subX, originY, color, charName, vramMode);
        pObj += rest;
        charName += (nameUnit * remainder * alignedHeight) >> vramMode;
        objCount += rest;
    }
    if (alignedHeight < areaHeight) {
        remainder = areaHeight - alignedHeight;
        rest = NNS_G2dArrangeOBJ1D(pObj, alignedWidth, remainder, originX, originY + alignedHeight * 8, color, charName,
                                   vramMode);
        pObj += rest;
        charName += (nameUnit * alignedWidth * remainder) >> vramMode;
        objCount += rest;
    }
    if (alignedWidth < areaWidth && alignedHeight < areaHeight) {
        objCount +=
            NNS_G2dArrangeOBJ1D(pObj, areaWidth - alignedWidth, areaHeight - alignedHeight, originX + alignedWidth * 8,
                                originY + alignedHeight * 8, color, charName, vramMode);
    }
    return objCount;
}

u32 GetGlyphIndex(FontCodeMap *pMap, u32 code) {
    u32 index;
    UnsignedHalfwordPair *first;
    UnsignedHalfwordPair *last;
    UnsignedHalfwordPair *middle;
    FontCodeMapInfo *scan;

    index = 0xffff;
    switch (pMap->mMappingMethod) {
        case 0:
            index = (u16) (pMap->mMapInfo[0] + (code - pMap->mCcodeBegin));
            break;
        case 1:
            index = pMap->mMapInfo[code - pMap->mCcodeBegin];
            break;
        case 2:
            scan = &pMap->mPairTable;
            first = scan->mScanEntries;
            last = first + (scan->mNum - 1);
            while (first <= last) {
                middle = first + (last - first) / 2;
                if (middle->mUnk_00 < code) {
                    first = middle + 1;
                } else if (code < middle->mUnk_00) {
                    last = middle - 1;
                } else {
                    index = middle->mUnk_02;
                    break;
                }
            }
            break;
    }
    return index;
}

void NNS_G2dFontInitAuto(NNSG2dFont *pFont, NNSG2dBinaryFileHeader *pNftrFile) {
    u32 result;
    u32 encodingId;

    result = NNSi_G2dGetUnpackedFont(pNftrFile, &pFont->mPRes);
    encodingId = pFont->mPRes->mEncoding;
    pFont->mFileVersionIndex = result - 1;
    pFont->mWidthEntrySize = pFont->mFileVersionIndex != 0 ? 2 : 3;
    pFont->mCbCharSpliter = spliterTable[encodingId];
}

void NNS_G2dFontInitUTF16(NNSG2dFont *pFont, NNSG2dBinaryFileHeader *pNftrFile) {
    pFont->mFileVersionIndex = NNSi_G2dGetUnpackedFont(pNftrFile, &pFont->mPRes) - 1;
    pFont->mWidthEntrySize = pFont->mFileVersionIndex != 0 ? 2 : 3;
    pFont->mCbCharSpliter = NNSi_G2dSplitCharUTF16;
}

u32 NNS_G2dFontFindGlyphIndex(NNSG2dFont *pFont, u32 code) {
    FontCodeMap *charMap;

    charMap = pFont->mPRes->mPMap;
    while (charMap != 0) {
        if (charMap->mCcodeBegin <= code && code <= charMap->mCcodeEnd) {
            return GetGlyphIndex(charMap, code);
        }
        charMap = charMap->mPNext;
    }
    return 0xffff;
}

NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(NNSG2dFont *pFont, u32 idx) {
    NNSG2dFontWidth *pRange;
    NNSG2dFontInformation *pRes;

    pRes = pFont->mPRes;
    pRange = pRes->mPWidth;
    while (pRange != 0) {
        if (pRange->mIndexBegin <= idx && idx <= pRange->mIndexEnd) {
            return (NNSG2dCharWidths *) ((u8 *) pRange + 8 + pFont->mWidthEntrySize * (idx - pRange->mIndexBegin));
        }
        pRange = pRange->mPNext;
    }
    return &pRes->mDefaultWidth;
}

s32 NNSi_G2dFontGetStringWidth(NNSG2dFont *pFont, s32 hSpace, u8 *str, u8 **pPos) {
    u8 *pos = str;
    s32 width;
    SplitCharFunc *readChar;
    u16 code;
    u32 glyph;
    NNSG2dCharWidths *pWidths;
    s32 charWidth;

    readChar = pFont->mCbCharSpliter;
    width = 0;
    code = readChar(&pos);
    while (code != 0) {
        if (code == 10) {
            break;
        }
        glyph = NNS_G2dFontFindGlyphIndex(pFont, code);
        if (glyph == 0xffff) {
            glyph = pFont->mPRes->mAlterCharIndex;
        }
        pWidths = NNS_G2dFontGetCharWidthsFromIndex(pFont, glyph);
        if (pFont->mFileVersionIndex != 0) {
            charWidth = pWidths->mLeft + pWidths->mGlyphWidth;
        } else {
            charWidth = pWidths->mCharWidth;
        }
        width += hSpace + charWidth;
        code = readChar(&pos);
    }
    if (pPos != 0) {
        *pPos = code == 10 ? pos : 0;
    }
    if (width > 0) {
        width -= hSpace;
    }
    return width;
}

s32 NNSi_G2dFontGetTextHeight(NNSG2dFont *pFont, s32 vSpace, u8 *txt) {
    u8 *pos = txt;
    NNSG2dTextRect unusedState = {0, 0};
    s32 lineCount;
    SplitCharFunc *readChar;
    u16 code;

    readChar = pFont->mCbCharSpliter;
    lineCount = 1;
    code = readChar(&pos);
    while (code != 0) {
        if (code == 10) {
            lineCount++;
        }
        code = readChar(&pos);
    }
    return lineCount * (vSpace + pFont->mPRes->mLinefeed) - vSpace;
}

void NNSi_G2dFontGetTextRect(NNSG2dTextRect *pRect, NNSG2dFont *pFont, s32 hSpace, s32 vSpace, u8 *txt) {
    NNSG2dTextRect rect = {0, 0};
    s32 lineCount;
    s32 width;

    lineCount = 1;
    while (txt != 0) {
        width = NNSi_G2dFontGetStringWidth(pFont, hSpace, txt, &txt);
        if (width > rect.mWidth) {
            rect.mWidth = width;
        }
        lineCount++;
    }
    rect.mHeight = (lineCount - 1) * (vSpace + pFont->mPRes->mLinefeed) - vSpace;
    *pRect = rect;
}
