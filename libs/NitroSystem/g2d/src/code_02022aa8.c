#include "code_02022aa8.h"

#include "code_020219e8.h"
#include "code_020245a4.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/code_02022000.h"
#include "g2d_CharCanvas.h"
#include "Main/Unknown/code_02124094.h" // Unk02022eb0

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
    Unk02022eb0 *pObj;
    u8 *sizeEntry;
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
    s32 shape;
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
    sizeEntry = data_usa_021530f8[heightLog][widthLog];
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
    shape = OBJSizeToShape(sizeEntry);
    numX = areaWidth >> widthShift;
    numY = areaHeight >> heightShift;
    charNameStep = (nameUnit << widthShift << heightShift) >> vramMode;
    for (oy = 0; oy < numY; oy++) {
        objY = originY + (oy << heightShift) * 8;
        for (colIdx = 0; colIdx < numX; colIdx++) {
            objX = (originX + (colIdx << widthShift) * 8) & 0x1ff;
            pObj->mUnk_00 = (pObj->mUnk_00 & 0xfe00ff00) | (objY & 0xff) | (objX << 16);
            pObj->mUnk_00 = (pObj->mUnk_00 & 0x3fff3fff) | shape;
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

u32 GetGlyphIndex(Unk02022dd8 *pMap, u32 code) {
    u32 index;
    Unk02021a5c *first;
    Unk02021a5c *last;
    Unk02021a5c *middle;
    Unk02022dd8_s *scan;

    index = 0xffff;
    switch (pMap->mUnk_04) {
        case 0:
            index = (u16) (pMap->mUnk_0c.mUnk_00 + (code - pMap->mUnk_00));
            break;
        case 1:
            index = (OFFSET_PTR(u16, pMap, 0xc))[code - pMap->mUnk_00];
            break;
        case 2:
            scan = &pMap->mUnk_0c;
            first = scan->mUnk_02;
            last = first + (scan->mUnk_00 - 1);
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

void NNS_G2dFontInitAuto(Unk02022aa8 *pFont, NNSG2dBinaryFileHeader *pNftrFile) {
    u32 result;
    u32 encoding;

    result = NNSi_G2dGetUnpackedFont(pNftrFile, &pFont->mPRes);
    encoding = pFont->mPRes->mEncoding;
    pFont->mUnk_08 = result - 1;
    pFont->mUnk_0a = pFont->mUnk_08 != 0 ? 2 : 3;
    pFont->mCbCharSpliter = data_021530e8[encoding];
}

void NNS_G2dFontInitUTF16(Unk02022aa8 *pFont, NNSG2dBinaryFileHeader *pNftrFile) {
    pFont->mUnk_08 = NNSi_G2dGetUnpackedFont(pNftrFile, &pFont->mPRes) - 1;
    pFont->mUnk_0a = pFont->mUnk_08 != 0 ? 2 : 3;
    pFont->mCbCharSpliter = NNSi_G2dSplitCharUTF16;
}

u32 NNS_G2dFontFindGlyphIndex(Unk02022aa8 *pFont, u32 code) {
    Unk02022dd8 *charMap;

    charMap = pFont->mPRes->mPMap;
    while (charMap != 0) {
        if (charMap->mUnk_00 <= code && code <= charMap->mUnk_02) {
            return GetGlyphIndex(charMap, code);
        }
        charMap = charMap->mUnk_08;
    }
    return 0xffff;
}

NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(Unk02022aa8 *pFont, u32 idx) {
    Unk02022c80_n *pRange;
    NNSG2dFontInformation *pRes;

    pRes = pFont->mPRes;
    pRange = pRes->mPWidth;
    while (pRange != 0) {
        if (pRange->mUnk_00 <= idx && idx <= pRange->mUnk_02) {
            return (NNSG2dCharWidths *) ((u8 *) pRange + 8 + pFont->mUnk_0a * (idx - pRange->mUnk_00));
        }
        pRange = pRange->mUnk_04;
    }
    return &pRes->mDefaultWidth;
}

s32 NNSi_G2dFontGetStringWidth(Unk02022aa8 *pFont, s32 hSpace, u8 *str, u8 **pPos) {
    u8 *pos = str;
    s32 width;
    Unk02022aa8_f *readChar;
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
        if (pFont->mUnk_08 != 0) {
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

s32 NNSi_G2dFontGetTextHeight(Unk02022aa8 *pFont, s32 vSpace, u8 *txt) {
    u8 *pos = txt;
    Unk02022b10 unusedState = {0, 0};
    s32 lines;
    Unk02022aa8_f *readChar;
    u16 code;

    readChar = pFont->mCbCharSpliter;
    lines = 1;
    code = readChar(&pos);
    while (code != 0) {
        if (code == 10) {
            lines++;
        }
        code = readChar(&pos);
    }
    return lines * (vSpace + pFont->mPRes->mLinefeed) - vSpace;
}

void NNSi_G2dFontGetTextRect(Unk02022b10 *pRect, Unk02022aa8 *pFont, s32 hSpace, s32 vSpace, u8 *txt) {
    Unk02022b10 rect = {0, 0};
    s32 lines;
    s32 width;

    lines = 1;
    while (txt != 0) {
        width = NNSi_G2dFontGetStringWidth(pFont, hSpace, txt, &txt);
        if (width > rect.mUnk_00) {
            rect.mUnk_00 = width;
        }
        lines++;
    }
    rect.mUnk_04 = (lines - 1) * (vSpace + pFont->mPRes->mLinefeed) - vSpace;
    *pRect = rect;
}
