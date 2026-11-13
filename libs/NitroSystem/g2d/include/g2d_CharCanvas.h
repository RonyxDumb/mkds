#pragma once

#include "types.h"
#include "Main/Menu/data_02180728.h" // TextCanvas
#include "code_02022aa8.h" // NNSG2dFont
#include "code_020245a4.h" // NNSiG2dBitReader

// Two pointers, passed by address to the function at 0x14 of NNSG2dCharCanvas.
typedef struct NNSG2dGlyph {
    /* 00 */ NNSG2dCharWidths *mPWidths;
    /* 04 */ u8 *mImage;
} NNSG2dGlyph;

// 0x20-byte object set up by NNS_G2dCharCanvasInitForOBJ1D and NNS_G2dCharCanvasInitForBG: a buffer of 8 x 8 blocks of
// mUnk_0c * 8 bytes and the functions that draw into it.
typedef struct NNSG2dCharCanvas {
    /* 00 */ u8 *mCharBase;
    /* 04 */ s32 mAreaWidth;
    /* 08 */ s32 mAreaHeight;
    /* 0c */ u8 mDstBpp;
    /* 10 */ u32 mParam;
    /* 14 */ void (*mPDrawGlyph)(struct NNSG2dCharCanvas *, NNSG2dFont *, s32, s32, u32, NNSG2dGlyph *);
    /* 18 */ void (*mPClear)(struct NNSG2dCharCanvas *, u32);
    /* 1c */ void (*mPClearArea)(struct NNSG2dCharCanvas *, u32, s32, s32, s32, s32);
} NNSG2dCharCanvas;

// Argument of LetterChar, built on the stack by DrawGlyph1D and DrawGlyphLine.
typedef struct LetterCharInfo {
    /* 00 */ u32 *mDst;
    /* 04 */ u8 *mSrc;
    /* 08 */ s32 mOfsX;
    /* 0c */ s32 mOfsY;
    /* 10 */ s32 mWidth;
    /* 14 */ s32 mHeight;
    /* 18 */ s32 mDsrc;
    /* 1c */ s32 mSrcBpp;
    /* 20 */ s32 mDstBpp;
    /* 24 */ u32 mCl;
} LetterCharInfo;

void InitCharCanvas(NNSG2dCharCanvas *a, void *b, s32 c, s32 d, u32 e,
                    void (*f)(NNSG2dCharCanvas *, NNSG2dFont *, s32, s32, u32, NNSG2dGlyph *),
                    void (*g)(NNSG2dCharCanvas *, u32), void (*h)(NNSG2dCharCanvas *, u32, s32, s32, s32, s32), u32 i);
void ClearArea1D(NNSG2dCharCanvas *pCanvas, u32 cl, s32 areaX, s32 areaY, s32 areaWidth, s32 areaHeight);
void ClearAreaLine(NNSG2dCharCanvas *pCanvas, u32 cl, s32 areaX, s32 areaY, s32 areaWidth, s32 areaHeight);
void ClearContinuous(NNSG2dCharCanvas *pCanvas, u32 cl);
void DrawGlyph1D(NNSG2dCharCanvas *pCanvas, NNSG2dFont *pFont, s32 drawX, s32 drawY, u32 cl, NNSG2dGlyph *pGlyph);
void DrawGlyphLine(NNSG2dCharCanvas *pCanvas, NNSG2dFont *pFont, s32 drawX, s32 drawY, u32 cl, NNSG2dGlyph *pGlyph);
void LetterChar(LetterCharInfo *pInfo);
void ClearChar(u8 *pChar, s32 startX, s32 startY, s32 width, s32 height, u32 cl8, s32 bpp);
u32 OBJSizeToShape(const u8 *pSize);
void NNSi_G2dTextCanvasDrawTextAlign(TextCanvas *pTxn, s32 drawX, s32 drawY, s32 areaWidth, u32 cl, u32 flags,
                                     u16 *txt);
void NNSi_G2dTextCanvasDrawString(TextCanvas *pTxn, s32 drawX, s32 drawY, u32 cl, u16 *str, u16 **pPos);
void NNS_G2dCharCanvasInitForOBJ1D(void *pCC, void *charBase, s32 areaWidth, s32 areaHeight, s32 colorMode);
void NNS_G2dCharCanvasInitForBG(void *pCC, void *charBase, u32 areaWidth, u32 areaHeight, u32 colorMode);
s32 NNS_G2dCharCanvasDrawChar(NNSG2dCharCanvas *pCanvas, NNSG2dFont *pFont, s32 drawX, s32 drawY, u32 cl, u16 ccode);
u32 GetCharIndex1D(u32 cx, u32 cy, u32 areaWidth, u32 areaHeight, u32 objWidth, u32 objHeight);
void NNSi_G2dTextCanvasDrawTextRect(TextCanvas *pTxn, s32 drawX, s32 drawY, s32 areaWidth, s32 areaHeight, s32 cl,
                                    u32 flags, u16 *txt);
u32 NNSi_G2dTextCanvasDrawText(TextCanvas *pTxn, s32 drawX, s32 drawY, u32 cl, u32 flags, void *txt);

extern SplitCharFunc *const spliterTable[4];
extern const u8 objs[4][4][2];
extern const u32 objShapes[4][4];
