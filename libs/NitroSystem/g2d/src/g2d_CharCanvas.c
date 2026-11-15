#include "g2d_CharCanvas.h"
#include "code_0214d018.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"

SplitCharFunc *const spliterTable[4] = {NNSi_G2dSplitCharUTF8, NNSi_G2dSplitCharUTF16, NNSi_G2dSplitCharShiftJIS,
                                        NNSi_G2dSplitChar1Byte};
const u8 objs[4][4][2] = {{{0, 0}, {1, 0}, {2, 0}, {2, 0}},
                          {{0, 1}, {1, 1}, {2, 1}, {2, 1}},
                          {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
                          {{0, 2}, {1, 2}, {2, 3}, {3, 3}}};
const u32 objShapes[4][4] = {{0, 0x4000, 0x40004000, 0},
                             {0x8000, 0x40000000, 0x80004000, 0},
                             {0x40008000, 0x80008000, 0x80000000, 0xc0004000},
                             {0, 0, 0xc0008000, 0xc0000000}};

u32 OBJSizeToShape(const u8 *pSize) {
    return objShapes[pSize[1]][pSize[0]];
}

void ClearChar(u8 *pChar, s32 startX, s32 startY, s32 width, s32 height, u32 cl8, s32 bpp) {
    u32 color;
    u32 *pRow;
    u32 *pEnd;
    u32 mask;
    u32 rightPad;
    u32 extra;
    u32 bitStart;
    u32 maskLo;
    u32 maskHi;
    u32 colorHi;
    u32 colorLo;
    u32 *pRow8;
    u32 *pEnd8;
    volatile u32 fill;

    if (width == 8 && height == 8) {
        fill = cl8;
        MIi_CpuClearFast(fill, pChar, bpp << 3);
        return;
    }
    if (bpp == 4) {
        bitStart = startX * 4;
        rightPad = 32 - (bitStart + width * 4);
        mask = (0xffffffffu >> bitStart) << (rightPad + bitStart);
        color = cl8 & (mask >> rightPad);
        mask = ~(mask >> rightPad);
        pRow = (u32 *) pChar + startY;
        pEnd = pRow + height;
        for (; pRow < pEnd; pRow++) {
            *pRow = color | (*pRow & mask);
        }
    } else {
        bitStart = startX * 8;
        rightPad = 64 - (bitStart + width * 8);
        mask = 0xffffffffu >> bitStart;
        if (rightPad >= 32) {
            extra = rightPad - 32;
            maskLo = (mask << (bitStart + extra)) >> extra;
        } else {
            maskLo = mask << bitStart;
        }
        mask = 0xffffffffu << rightPad;
        if (bitStart >= 32) {
            bitStart -= 32;
            maskHi = (mask >> (bitStart + rightPad)) << bitStart;
        } else {
            maskHi = mask >> rightPad;
        }
        pRow8 = (u32 *) pChar + startY * 2;
        pEnd8 = pRow8 + height * 2;
        colorLo = cl8 & maskLo;
        colorHi = cl8 & maskHi;
        maskLo = ~maskLo;
        maskHi = ~maskHi;
        for (; pRow8 < pEnd8; pRow8 += 2) {
            pRow8[0] = colorLo | (pRow8[0] & maskLo);
            pRow8[1] = colorHi | (pRow8[1] & maskHi);
        }
    }
}

void LetterChar(LetterCharInfo *pInfo) {
    u8 *pGlyphBits;
    u32 xEnd;
    s32 xStart;
    u32 colorBase8;
    s32 yStart;
    s32 yEnd;
    s32 bitsPerRow;
    s32 bpp;
    s32 offsetX;
    s32 offsetY;
    u32 *pRow;
    s32 bitPos;
    u32 *pRowEnd;
    s32 bitX;
    u32 colorBase;
    u32 rowLo;
    u32 rowHi;
    u32 row;
    s32 glyphBpp;
    NNSiG2dBitReader bitStream;
    u32 pixel;
    NNSiG2dBitReader reader8;

    offsetX = pInfo->mOfsX;
    offsetY = pInfo->mOfsY;
    xStart = offsetX >= 0 ? offsetX : 0;
    xEnd = offsetX + pInfo->mWidth;
    if (offsetY >= 0) {
        yStart = offsetY;
    } else {
        yStart = 0;
    }
    yEnd = offsetY + pInfo->mHeight;
    if ((s32) xEnd >= 8) {
        xEnd = 8;
    }
    yEnd = yEnd >= 8 ? 8 : yEnd;
    if (offsetY > 0) {
        offsetY = 0;
    }
    bitPos = -offsetY;
    if (offsetX > 0) {
        offsetX = 0;
    }
    glyphBpp = pInfo->mSrcBpp;
    bitsPerRow = pInfo->mDsrc;
    bitPos = bitPos * bitsPerRow + glyphBpp * -offsetX;
    bpp = pInfo->mDstBpp;
    xStart = xStart * bpp;
    xEnd = xEnd * bpp;
    pGlyphBits = pInfo->mSrc;
    if (bpp == 4) {
        colorBase = pInfo->mCl;
        pRow = pInfo->mDst + yStart;
        pRowEnd = pInfo->mDst + yEnd;
        if (pRow < pRowEnd) {
            do {
                row = *pRow;
                bitStream.mSrc = pGlyphBits + ((u32) bitPos >> 3);
                bitStream.mAvailableBits = 0;
                bitStream.mBits = 0;
                NNSi_G2dBitReaderRead(&bitStream, bitPos % 8);
                for (bitX = xStart; bitX < xEnd; bitX += 4) {
                    pixel = NNSi_G2dBitReaderRead(&bitStream, glyphBpp);
                    if (pixel != 0) {
                        row = (row & ~(0xf << bitX)) | ((colorBase + pixel) << bitX);
                    }
                }
                *pRow = row;
                bitPos += bitsPerRow;
                pRow++;
            } while (pRow < pRowEnd);
        }
        return;
    }
    colorBase8 = pInfo->mCl;
    pRow = pInfo->mDst + yStart * 2;
    pRowEnd = pInfo->mDst + yEnd * 2;
    for (; pRow < pRowEnd; pRow += 2) {
        rowLo = pRow[0];
        rowHi = pRow[1];
        reader8.mSrc = pGlyphBits + ((u32) bitPos >> 3);
        reader8.mAvailableBits = 0;
        reader8.mBits = 0;
        NNSi_G2dBitReaderRead(&reader8, bitPos % 8);
        for (bitX = xStart; bitX < xEnd; bitX += 8) {
            pixel = NNSi_G2dBitReaderRead(&reader8, glyphBpp);
            if (pixel != 0) {
                if ((u32) bitX < 0x20) {
                    rowLo = (rowLo & ~(0xff << bitX)) | ((colorBase8 + pixel) << bitX);
                } else {
                    rowHi = (rowHi & ~(0xff << (u32) (bitX - 0x20))) | ((colorBase8 + pixel) << (u32) (bitX - 0x20));
                }
            }
        }
        pRow[0] = rowLo;
        pRow[1] = rowHi;
        bitPos += bitsPerRow;
    }
}

void DrawGlyphLine(NNSG2dCharCanvas *pCanvas, NNSG2dFont *pFont, s32 drawX, s32 drawY, u32 cl, NNSG2dGlyph *pGlyph) {
    LetterCharInfo info;
    s32 inkWidth;
    s32 rowSkip;
    u32 canvasW;
    s32 curX;
    u32 canvasH;
    u32 firstY;
    u32 endX;
    s32 glyphHeight;
    u32 endY;
    s32 numX;
    u32 firstX;
    s32 numY;
    s32 limitX;
    s32 limitY;
    s32 curY;
    u32 stride;
    u8 *pTile;
    s32 bytesPerChar;
    u8 *pBase;

    bytesPerChar = (pCanvas->mDstBpp * 0x40) / 8;
    inkWidth = pGlyph->mPWidths->mGlyphWidth;
    glyphHeight = pFont->mPRes->mPGlyph->mCellHeight;
    canvasW = pCanvas->mAreaWidth;
    canvasH = pCanvas->mAreaHeight;
    pBase = pCanvas->mCharBase;
    if (inkWidth == 0) {
        return;
    }
    if (drawX + inkWidth < 0) {
        return;
    }
    if (drawY + glyphHeight < 0) {
        return;
    }
    if (drawX <= 0) {
        firstX = 0;
    } else {
        firstX = (u32) drawX >> 3;
    }
    endX = (u32) (drawX + inkWidth + 7) >> 3;
    if (drawY <= 0) {
        firstY = 0;
    } else {
        firstY = (u32) drawY >> 3;
    }
    endY = drawY + glyphHeight + 7;
    if (endX >= canvasW) {
        endX = canvasW;
    }
    endY >>= 3;
    if (endY >= canvasH) {
        endY = canvasH;
    }
    numX = endX - firstX;
    numY = endY - firstY;
    if (numX < 0) {
        return;
    }
    if (numY < 0) {
        return;
    }
    stride = pCanvas->mParam;
    pTile = pBase + bytesPerChar * (stride * firstY + firstX);
    rowSkip = bytesPerChar * (stride - numX);
    if (drawX >= 0) {
        drawX &= 7;
    }
    if (drawY >= 0) {
        drawY &= 7;
    }
    info.mSrc = pGlyph->mImage;
    limitY = drawY - numY * 8;
    info.mWidth = inkWidth;
    info.mCl = cl - 1;
    info.mHeight = glyphHeight;
    limitX = drawX - numX * 8;
    info.mSrcBpp = pFont->mPRes->mPGlyph->mBpp;
    info.mDstBpp = pCanvas->mDstBpp;
    info.mDsrc = info.mSrcBpp * pFont->mPRes->mPGlyph->mCellWidth;
    for (curY = drawY; curY > limitY; curY -= 8) {
        info.mOfsY = curY;
        for (curX = drawX; curX > limitX; curX -= 8) {
            info.mDst = (u32 *) pTile;
            info.mOfsX = curX;
            LetterChar(&info);
            pTile += bytesPerChar;
        }
        pTile += rowSkip;
    }
}

void DrawGlyph1D(NNSG2dCharCanvas *pCanvas, NNSG2dFont *pFont, s32 drawX, s32 drawY, u32 cl, NNSG2dGlyph *pGlyph) {
    LetterCharInfo info;
    s32 inkWidth;
    u32 canvasW;
    u32 canvasH;
    u32 firstX;
    u32 firstY;
    u32 endX;
    u32 endY;
    s32 numX;
    s32 glyphHeight;
    s32 numY;
    s32 limitY;
    s32 curX;
    s32 limitX;
    s32 curY;
    u32 charX;
    u32 charY;
    u32 objSizeWord;
    u8 *pBase;
    s32 bytesPerChar;
    u32 objHeight;
    u32 objWidth;
    u32 charIdx;
    u32 height;
    u32 width;

    bytesPerChar = (pCanvas->mDstBpp * 0x40) / 8;
    inkWidth = pGlyph->mPWidths->mGlyphWidth;
    canvasW = pCanvas->mAreaWidth;
    canvasH = pCanvas->mAreaHeight;
    glyphHeight = pFont->mPRes->mPGlyph->mCellHeight;
    if (inkWidth == 0) {
        return;
    }
    if (drawX + inkWidth < 0) {
        return;
    }
    if (drawY + glyphHeight < 0) {
        return;
    }
    if (drawX <= 0) {
        firstX = 0;
    } else {
        firstX = (u32) drawX >> 3;
    }
    endX = drawX + inkWidth + 7;
    if (drawY <= 0) {
        firstY = 0;
    } else {
        firstY = (u32) drawY >> 3;
    }
    endY = (u32) (drawY + glyphHeight + 7) >> 3;
    endX >>= 3;
    if (endX >= canvasW) {
        endX = canvasW;
    }
    if (endY >= canvasH) {
        endY = canvasH;
    }
    numX = endX - firstX;
    numY = endY - firstY;
    if (numX < 0) {
        return;
    }
    if (numY < 0) {
        return;
    }
    pBase = pCanvas->mCharBase;
    if (drawX >= 0) {
        drawX &= 7;
    }
    if (drawY >= 0) {
        drawY &= 7;
    }
    limitX = drawX - numX * 8;
    limitY = drawY - numY * 8;
    info.mSrc = pGlyph->mImage;
    info.mCl = cl - 1;
    info.mHeight = glyphHeight;
    info.mWidth = inkWidth;
    info.mSrcBpp = pFont->mPRes->mPGlyph->mBpp;
    info.mDstBpp = pCanvas->mDstBpp;
    info.mDsrc = info.mSrcBpp * pFont->mPRes->mPGlyph->mCellWidth;
    objSizeWord = pCanvas->mParam;
    width = pCanvas->mAreaWidth;
    height = pCanvas->mAreaHeight;
    objWidth = ((u8 *) &objSizeWord)[0];
    objHeight = ((u8 *) &objSizeWord)[1];
    charY = firstY;
    for (curY = drawY; curY > limitY; curY -= 8) {
        info.mOfsY = curY;
        charX = firstX;
        for (curX = drawX; curX > limitX; curX -= 8) {
            charIdx = GetCharIndex1D(charX, charY, width, height, objWidth, objHeight);
            info.mDst = (u32 *) (pBase + charIdx * bytesPerChar);
            info.mOfsX = curX;
            LetterChar(&info);
            charX++;
        }
        charY++;
    }
}

void ClearContinuous(NNSG2dCharCanvas *pCanvas, u32 cl) {
    volatile u32 fill;
    s32 bytes;

    if (pCanvas->mDstBpp == 4) {
        cl = cl | (cl << 4);
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    } else {
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    }
    fill = cl;
    bytes = pCanvas->mAreaWidth * pCanvas->mAreaHeight;
    bytes *= (pCanvas->mDstBpp * 0x40) / 8;
    MIi_CpuClearFast(fill, pCanvas->mCharBase, bytes);
}

void ClearAreaLine(NNSG2dCharCanvas *pCanvas, u32 cl, s32 areaX, s32 areaY, s32 areaWidth, s32 areaHeight) {
    s32 pixelY;
    s32 xEnd;
    s32 yEnd;
    s32 yEndAligned;
    u8 *pRow;
    s32 charX0;
    s32 bitsPerPixel;
    s32 bytesPerChar;
    s32 rowStep;
    s32 rows;
    s32 rowOffset;
    s32 pixelX;
    s32 xEndAligned;
    u8 *charData;
    s32 colOffset;
    s32 cols;

    bitsPerPixel = pCanvas->mDstBpp;
    xEnd = areaX + areaWidth;
    yEnd = areaY + areaHeight;
    if (bitsPerPixel == 4) {
        cl = cl | (cl << 4);
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    } else {
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    }
    pixelY = areaY & ~7;
    charX0 = areaX & ~7;
    bytesPerChar = (bitsPerPixel * 0x40) / 8;
    xEndAligned = (xEnd + 7) & ~7;
    yEndAligned = (yEnd + 7) & ~7;
    pRow = pCanvas->mCharBase + bytesPerChar * ((pixelY / 8) * pCanvas->mParam + charX0 / 8);
    rowStep = pCanvas->mParam * bytesPerChar;
    for (; pixelY < yEndAligned; pixelY += 8) {
        if (pixelY < areaY) {
            rowOffset = areaY - pixelY;
        } else {
            rowOffset = 0;
        }
        rows = yEnd - pixelY;
        if (rows > 8) {
            rows = 8;
        }
        rows -= rowOffset;
        charData = pRow;
        for (pixelX = charX0; pixelX < xEndAligned; pixelX += 8) {
            if (pixelX < areaX) {
                colOffset = areaX - pixelX;
            } else {
                colOffset = 0;
            }
            cols = xEnd - pixelX;
            if (cols > 8) {
                cols = 8;
            }
            cols -= colOffset;
            ClearChar(charData, colOffset, rowOffset, cols, (s64) rows, cl, bitsPerPixel);
            charData += bytesPerChar;
        }
        pRow += rowStep;
    }
}

void ClearArea1D(NNSG2dCharCanvas *pCanvas, u32 cl, s32 areaX, s32 areaY, s32 areaWidth, s32 areaHeight) {
    s32 pixelY;
    s32 rows;
    s32 rowEnd;
    s32 xEnd;
    s32 yEnd;
    s32 yEndAligned;
    u8 *pBase;
    s32 charX0;
    s32 xAligned;
    u32 objHeight;
    u32 objWidth;
    u32 canvasH;
    u32 canvasW;
    s32 bitsPerPixel;
    s32 bytesPerChar;
    u32 objSizeWord;
    s32 rowOffset;
    s32 pixelX;
    s32 charX;
    s32 charY;
    s32 xEndAligned;
    s32 colOffset;
    s32 cols;
    u32 charIdx;

    bitsPerPixel = pCanvas->mDstBpp;
    xEnd = areaX + areaWidth;
    yEnd = areaY + areaHeight;
    if (bitsPerPixel == 4) {
        cl = cl | (cl << 4);
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    } else {
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    }
    xAligned = areaX & ~7;
    pixelY = areaY & ~7;
    objSizeWord = pCanvas->mParam;
    xEndAligned = (xEnd + 7) & ~7;
    yEndAligned = (yEnd + 7) & ~7;
    bytesPerChar = (bitsPerPixel * 0x40) / 8;
    charX0 = xAligned / 8;
    charY = pixelY / 8;
    canvasW = pCanvas->mAreaWidth;
    canvasH = pCanvas->mAreaHeight;
    pBase = pCanvas->mCharBase;
    objWidth = ((u8 *) &objSizeWord)[0];
    objHeight = ((u8 *) &objSizeWord)[1];
    for (; pixelY < yEndAligned; pixelY += 8) {
        charX = charX0;
        if (pixelY < areaY) {
            rowOffset = areaY - pixelY;
        } else {
            rowOffset = 0;
        }
        rowEnd = yEnd - pixelY;
        if (rowEnd > 8) {
            rowEnd = 8;
        }
        rows = rowEnd - rowOffset;
        for (pixelX = xAligned; pixelX < xEndAligned; pixelX += 8) {
            charIdx = GetCharIndex1D(charX, charY, canvasW, canvasH, objWidth, objHeight);
            if (pixelX < areaX) {
                colOffset = areaX - pixelX;
            } else {
                colOffset = 0;
            }
            cols = xEnd - pixelX;
            if (cols > 8) {
                cols = 8;
            }
            cols -= colOffset;
            ClearChar(pBase + charIdx * bytesPerChar, colOffset, rowOffset, cols, rows, cl, bitsPerPixel);
            charX++;
        }
        charY++;
    }
}

void InitCharCanvas(NNSG2dCharCanvas *pCanvas, void *charBase, s32 areaWidth, s32 areaHeight, u32 bpp,
                    void (*drawGlyph)(NNSG2dCharCanvas *, NNSG2dFont *, s32, s32, u32, NNSG2dGlyph *),
                    void (*clearAll)(NNSG2dCharCanvas *, u32),
                    void (*clearArea)(NNSG2dCharCanvas *, u32, s32, s32, s32, s32), u32 stride) {
    pCanvas->mAreaWidth = areaWidth;
    pCanvas->mAreaHeight = areaHeight;
    pCanvas->mDstBpp = bpp;
    pCanvas->mCharBase = charBase;
    pCanvas->mPDrawGlyph = drawGlyph;
    pCanvas->mPClear = clearAll;
    pCanvas->mPClearArea = clearArea;
    pCanvas->mParam = stride;
}

s32 NNS_G2dCharCanvasDrawChar(NNSG2dCharCanvas *pCanvas, NNSG2dFont *pFont, s32 drawX, s32 drawY, u32 cl, u16 ccode) {
    NNSG2dGlyph glyphInfo;
    u32 glyphIdx;
    FontGlyph *pRes;

    glyphIdx = NNS_G2dFontFindGlyphIndex(pFont, ccode);
    if (glyphIdx == 0xffff) {
        glyphIdx = pFont->mPRes->mAlterCharIndex;
    }
    glyphInfo.mPWidths = NNS_G2dFontGetCharWidthsFromIndex(pFont, glyphIdx);
    pRes = pFont->mPRes->mPGlyph;
    glyphInfo.mImage = &pRes->mGlyphTable[glyphIdx * pRes->mCellSize];
    pCanvas->mPDrawGlyph(pCanvas, pFont, drawX + glyphInfo.mPWidths->mLeft, drawY, cl, &glyphInfo);
    if (pFont->mFileVersionIndex != 0) {
        return glyphInfo.mPWidths->mLeft + glyphInfo.mPWidths->mGlyphWidth;
    }
    return glyphInfo.mPWidths->mCharWidth;
}

void NNS_G2dCharCanvasInitForBG(void *pCC, void *charBase, u32 areaWidth, u32 areaHeight, u32 colorMode) {
    InitCharCanvas(pCC, charBase, areaWidth, areaHeight, colorMode, DrawGlyphLine, ClearContinuous, ClearAreaLine,
                   areaWidth);
}

// clang-format off
// Sets up an OBJ-order canvas; written as assembly because it uses clz.
asm void NNS_G2dCharCanvasInitForOBJ1D(void *pCC, void *charBase, s32 areaWidth, s32 areaHeight, s32 colorMode) {
    stmfd sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x18
    cmp r2, #0x8
    movlt r4, r2
    movge ip, #0x3
    clzlt r4, r4
    rsblt ip, r4, #0x1f
    cmp r3, #0x8
    movlt r4, r3
    movge r6, #0x3
    clzlt r4, r4
    rsblt r6, r4, #0x1f
    ldr r4, =objs
    ldr r5, [sp, #0x28]
    add r4, r4, r6, lsl #0x3
    ldrb r6, [r4, ip, lsl #0x1]
    add ip, r4, ip, lsl #0x1
    ldr r4, =DrawGlyph1D
    strb r6, [sp, #0x14]
    ldrb r6, [ip, #0x1]
    ldr lr, =ClearContinuous
    ldr ip, =ClearArea1D
    strb r6, [sp, #0x15]
    str r5, [sp, #0x0]
    str r4, [sp, #0x4]
    str lr, [sp, #0x8]
    str ip, [sp, #0xc]
    ldr ip, [sp, #0x14]
    str ip, [sp, #0x10]
    bl InitCharCanvas
    add sp, sp, #0x18
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
// clang-format on
