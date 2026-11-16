#include "g2d_CharCanvas.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"

const u32 data_02153118[4][4] = {{0, 0x4000, 0x40004000}, {0x8000, 0x40000000, 0x80004000}, {0x40008000, 0x80008000, 0x80000000, 0xc0004000}, {0, 0, 0xc0008000, 0xc0000000}};

u32 OBJSizeToShape(const u8 *pSize) {
    return data_02153118[pSize[1]][pSize[0]];
}

void ClearChar(u8 *pChar, s32 x, s32 y, s32 w, s32 h, u32 cl8, s32 bpp) {
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

    if (w == 8 && h == 8) {
        fill = cl8;
        MIi_CpuClearFast(fill, pChar, bpp << 3);
        return;
    }
    if (bpp == 4) {
        bitStart = x * 4;
        rightPad = 32 - (bitStart + w * 4);
        mask = (0xffffffffu >> bitStart) << (rightPad + bitStart);
        color = cl8 & (mask >> rightPad);
        mask = ~(mask >> rightPad);
        pRow = (u32 *) pChar + y;
        pEnd = pRow + h;
        for (; pRow < pEnd; pRow++) {
            *pRow = color | (*pRow & mask);
        }
    } else {
        bitStart = x * 8;
        rightPad = 64 - (bitStart + w * 8);
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
        pRow8 = (u32 *) pChar + y * 2;
        pEnd8 = pRow8 + h * 2;
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

void LetterChar(Unk02023d84 *pInfo) {
    u8 *pGlyphBits;
    u32 xEnd;
    s32 xStart;
    u32 colorBase8;
    s32 yStart;
    s32 yEnd;
    s32 bitsPerRow;
    s32 bpp;
    s32 x;
    s32 y;
    u32 *pRow;
    s32 bitPos;
    u32 *pRowEnd;
    s32 bitX;
    u32 colorBase;
    u32 rowLo;
    u32 rowHi;
    u32 row;
    s32 glyphBpp;
    Unk020247fc reader;
    u32 pixel;
    Unk020247fc reader8;

    x = pInfo->field8;
    y = pInfo->fieldC;
    xStart = x >= 0 ? x : 0;
    xEnd = x + pInfo->field10;
    if (y >= 0) {
        yStart = y;
    } else {
        yStart = 0;
    }
    yEnd = y + pInfo->field14;
    if ((s32) xEnd >= 8) {
        xEnd = 8;
    }
    yEnd = yEnd >= 8 ? 8 : yEnd;
    if (y > 0) {
        y = 0;
    }
    bitPos = -y;
    if (x > 0) {
        x = 0;
    }
    glyphBpp = pInfo->field1C;
    bitsPerRow = pInfo->field18;
    bitPos = bitPos * bitsPerRow + glyphBpp * -x;
    bpp = pInfo->field20;
    xStart = xStart * bpp;
    xEnd = xEnd * bpp;
    pGlyphBits = pInfo->field4;
    if (bpp == 4) {
        colorBase = pInfo->field24;
        pRow = pInfo->field0 + yStart;
        pRowEnd = pInfo->field0 + yEnd;
        if (pRow < pRowEnd) {
            do {
                row = *pRow;
                reader.field0 = pGlyphBits + ((u32) bitPos >> 3);
                reader.field4 = 0;
                reader.field5 = 0;
                BitStreamReadBits(&reader, bitPos % 8);
                for (bitX = xStart; bitX < xEnd; bitX += 4) {
                    pixel = BitStreamReadBits(&reader, glyphBpp);
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
    colorBase8 = pInfo->field24;
    pRow = pInfo->field0 + yStart * 2;
    pRowEnd = pInfo->field0 + yEnd * 2;
    for (; pRow < pRowEnd; pRow += 2) {
        rowLo = pRow[0];
        rowHi = pRow[1];
        reader8.field0 = pGlyphBits + ((u32) bitPos >> 3);
        reader8.field4 = 0;
        reader8.field5 = 0;
        BitStreamReadBits(&reader8, bitPos % 8);
        for (bitX = xStart; bitX < xEnd; bitX += 8) {
            pixel = BitStreamReadBits(&reader8, glyphBpp);
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

void DrawGlyphLine(Unk02023374 *pCanvas, Unk02022aa8 *pFont, s32 x, s32 y, u32 cl, NNSG2dGlyph *pGlyph) {
    Unk02023d84 info;
    s32 glyphWidth;
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

    bytesPerChar = (pCanvas->fieldC * 0x40) / 8;
    glyphWidth = pGlyph->mPWidths->mGlyphWidth;
    glyphHeight = pFont->field0->field8->field1;
    canvasW = pCanvas->field4;
    canvasH = pCanvas->field8;
    pBase = pCanvas->field0;
    if (glyphWidth == 0) {
        return;
    }
    if (x + glyphWidth < 0) {
        return;
    }
    if (y + glyphHeight < 0) {
        return;
    }
    if (x <= 0) {
        firstX = 0;
    } else {
        firstX = (u32) x >> 3;
    }
    endX = (u32) (x + glyphWidth + 7) >> 3;
    if (y <= 0) {
        firstY = 0;
    } else {
        firstY = (u32) y >> 3;
    }
    endY = y + glyphHeight + 7;
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
    stride = pCanvas->field10;
    pTile = pBase + bytesPerChar * (stride * firstY + firstX);
    rowSkip = bytesPerChar * (stride - numX);
    if (x >= 0) {
        x &= 7;
    }
    if (y >= 0) {
        y &= 7;
    }
    info.field4 = pGlyph->mImage;
    limitY = y - numY * 8;
    info.field10 = glyphWidth;
    info.field24 = cl - 1;
    info.field14 = glyphHeight;
    limitX = x - numX * 8;
    info.field1C = pFont->field0->field8->field4[2];
    info.field20 = pCanvas->fieldC;
    info.field18 = info.field1C * pFont->field0->field8->field0;
    for (curY = y; curY > limitY; curY -= 8) {
        info.fieldC = curY;
        for (curX = x; curX > limitX; curX -= 8) {
            info.field0 = (u32 *) pTile;
            info.field8 = curX;
            LetterChar(&info);
            pTile += bytesPerChar;
        }
        pTile += rowSkip;
    }
}

void DrawGlyph1D(Unk02023374 *pCanvas, Unk02022aa8 *pFont, s32 x, s32 y, u32 cl, NNSG2dGlyph *pGlyph) {
    Unk02023d84 info;
    s32 glyphWidth;
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

    bytesPerChar = (pCanvas->fieldC * 0x40) / 8;
    glyphWidth = pGlyph->mPWidths->mGlyphWidth;
    canvasW = pCanvas->field4;
    canvasH = pCanvas->field8;
    glyphHeight = pFont->field0->field8->field1;
    if (glyphWidth == 0) {
        return;
    }
    if (x + glyphWidth < 0) {
        return;
    }
    if (y + glyphHeight < 0) {
        return;
    }
    if (x <= 0) {
        firstX = 0;
    } else {
        firstX = (u32) x >> 3;
    }
    endX = x + glyphWidth + 7;
    if (y <= 0) {
        firstY = 0;
    } else {
        firstY = (u32) y >> 3;
    }
    endY = (u32) (y + glyphHeight + 7) >> 3;
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
    pBase = pCanvas->field0;
    if (x >= 0) {
        x &= 7;
    }
    if (y >= 0) {
        y &= 7;
    }
    limitX = x - numX * 8;
    limitY = y - numY * 8;
    info.field4 = pGlyph->mImage;
    info.field24 = cl - 1;
    info.field14 = glyphHeight;
    info.field10 = glyphWidth;
    info.field1C = pFont->field0->field8->field4[2];
    info.field20 = pCanvas->fieldC;
    info.field18 = info.field1C * pFont->field0->field8->field0;
    objSizeWord = pCanvas->field10;
    width = pCanvas->field4;
    height = pCanvas->field8;
    objWidth = ((u8 *) &objSizeWord)[0];
    objHeight = ((u8 *) &objSizeWord)[1];
    charY = firstY;
    for (curY = y; curY > limitY; curY -= 8) {
        info.fieldC = curY;
        charX = firstX;
        for (curX = x; curX > limitX; curX -= 8) {
            charIdx = GetCharIndex1D(charX, charY, width, height, objWidth, objHeight);
            info.field0 = (u32 *) (pBase + charIdx * bytesPerChar);
            info.field8 = curX;
            LetterChar(&info);
            charX++;
        }
        charY++;
    }
}

void ClearContinuous(Unk02023374 *pCanvas, u32 cl) {
    volatile u32 fill;
    s32 bytes;

    if (pCanvas->fieldC == 4) {
        cl = cl | (cl << 4);
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    } else {
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    }
    fill = cl;
    bytes = pCanvas->field4 * pCanvas->field8;
    bytes *= (pCanvas->fieldC * 0x40) / 8;
    MIi_CpuClearFast(fill, pCanvas->field0, bytes);
}

void ClearAreaLine(Unk02023374 *pCanvas, u32 cl, s32 x, s32 y, s32 w, s32 h) {
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

    bitsPerPixel = pCanvas->fieldC;
    xEnd = x + w;
    yEnd = y + h;
    if (bitsPerPixel == 4) {
        cl = cl | (cl << 4);
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    } else {
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    }
    pixelY = y & ~7;
    charX0 = x & ~7;
    bytesPerChar = (bitsPerPixel * 0x40) / 8;
    xEndAligned = (xEnd + 7) & ~7;
    yEndAligned = (yEnd + 7) & ~7;
    pRow = pCanvas->field0 + bytesPerChar * ((pixelY / 8) * pCanvas->field10 + charX0 / 8);
    rowStep = pCanvas->field10 * bytesPerChar;
    for (; pixelY < yEndAligned; pixelY += 8) {
        if (pixelY < y) {
            rowOffset = y - pixelY;
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
            if (pixelX < x) {
                colOffset = x - pixelX;
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

void ClearArea1D(Unk02023374 *pCanvas, u32 cl, s32 x, s32 y, s32 w, s32 h) {
    s32 pixelY;
    s32 rows;
    s32 bottom;
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

    bitsPerPixel = pCanvas->fieldC;
    xEnd = x + w;
    yEnd = y + h;
    if (bitsPerPixel == 4) {
        cl = cl | (cl << 4);
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    } else {
        cl = cl | (cl << 8);
        cl = cl | (cl << 16);
    }
    xAligned = x & ~7;
    pixelY = y & ~7;
    objSizeWord = pCanvas->field10;
    xEndAligned = (xEnd + 7) & ~7;
    yEndAligned = (yEnd + 7) & ~7;
    bytesPerChar = (bitsPerPixel * 0x40) / 8;
    charX0 = xAligned / 8;
    charY = pixelY / 8;
    canvasW = pCanvas->field4;
    canvasH = pCanvas->field8;
    pBase = pCanvas->field0;
    objWidth = ((u8 *) &objSizeWord)[0];
    objHeight = ((u8 *) &objSizeWord)[1];
    for (; pixelY < yEndAligned; pixelY += 8) {
        charX = charX0;
        if (pixelY < y) {
            rowOffset = y - pixelY;
        } else {
            rowOffset = 0;
        }
        bottom = yEnd - pixelY;
        if (bottom > 8) {
            bottom = 8;
        }
        rows = bottom - rowOffset;
        for (pixelX = xAligned; pixelX < xEndAligned; pixelX += 8) {
            charIdx = GetCharIndex1D(charX, charY, canvasW, canvasH, objWidth, objHeight);
            if (pixelX < x) {
                colOffset = x - pixelX;
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

void InitCharCanvas(Unk02023374 *pCanvas, void *charBase, s32 areaWidth, s32 areaHeight, u32 bpp,
                    void (*drawGlyph)(Unk02023374 *, Unk02022aa8 *, s32, s32, u32, NNSG2dGlyph *),
                    void (*clearAll)(Unk02023374 *, u32), void (*clearArea)(Unk02023374 *, u32, s32, s32, s32, s32),
                    u32 stride) {
    pCanvas->field4 = areaWidth;
    pCanvas->field8 = areaHeight;
    pCanvas->fieldC = bpp;
    pCanvas->field0 = charBase;
    pCanvas->field14 = drawGlyph;
    pCanvas->field18 = clearAll;
    pCanvas->field1C = clearArea;
    pCanvas->field10 = stride;
}

s32 NNS_G2dCharCanvasDrawChar(Unk02023374 *pCanvas, Unk02022aa8 *pFont, s32 x, s32 y, u32 cl, u16 ccode) {
    NNSG2dGlyph glyph;
    u32 glyphIdx;
    Unk02022ce4_08 *pRes;

    glyphIdx = NNS_G2dFontFindGlyphIndex(pFont, ccode);
    if (glyphIdx == 0xffff) {
        glyphIdx = pFont->field0->field2;
    }
    glyph.mPWidths = NNS_G2dFontGetCharWidthsFromIndex(pFont, glyphIdx);
    pRes = pFont->field0->field8;
    glyph.mImage = &pRes->field8[glyphIdx * pRes->field2];
    pCanvas->field14(pCanvas, pFont, x + glyph.mPWidths->mLeft, y, cl, &glyph);
    if (pFont->field8 != 0) {
        return glyph.mPWidths->mLeft + glyph.mPWidths->mGlyphWidth;
    }
    return glyph.mPWidths->mCharWidth;
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
    ldr r4, =data_021530f8
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
