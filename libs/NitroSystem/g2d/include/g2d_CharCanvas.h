#pragma once

#include "types.h"
#include "Main/Unknown/types_02180728.h" // TextCanvas
#include "code_02022aa8.h" // Unk02022aa8
#include "code_020245a4.h" // NNSiG2dBitReader

// Two pointers, passed by address to the function at 0x14 of Unk02023374.
typedef struct NNSG2dGlyph {
    /* 00 */ NNSG2dCharWidths *mPWidths;
    /* 04 */ u8 *mImage;
} NNSG2dGlyph;

// 0x20-byte object set up by NNS_G2dCharCanvasInitForOBJ1D and NNS_G2dCharCanvasInitForBG: a buffer of 8 x 8 blocks of
// mUnk_0c * 8 bytes and the functions that draw into it.
typedef struct Unk02023374 {
    /* 00 */ u8 *mCharBase;
    /* 04 */ s32 mAreaWidth;
    /* 08 */ s32 mAreaHeight;
    /* 0c */ u8 mDstBpp;
    /* 10 */ u32 mParam;
    /* 14 */ void (*mPDrawGlyph)(struct Unk02023374 *, Unk02022aa8 *, s32, s32, u32, NNSG2dGlyph *);
    /* 18 */ void (*mPClear)(struct Unk02023374 *, u32);
    /* 1c */ void (*mPClearArea)(struct Unk02023374 *, u32, s32, s32, s32, s32);
} Unk02023374;

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

void InitCharCanvas(Unk02023374 *a, void *b, s32 c, s32 d, u32 e,
                    void (*f)(Unk02023374 *, Unk02022aa8 *, s32, s32, u32, NNSG2dGlyph *),
                    void (*g)(Unk02023374 *, u32), void (*h)(Unk02023374 *, u32, s32, s32, s32, s32), u32 i);
void ClearArea1D(Unk02023374 *pCanvas, u32 cl, s32 areaX, s32 areaY, s32 areaWidth, s32 areaHeight);
void ClearAreaLine(Unk02023374 *pCanvas, u32 cl, s32 areaX, s32 areaY, s32 areaWidth, s32 areaHeight);
void ClearContinuous(Unk02023374 *pCanvas, u32 cl);
void DrawGlyph1D(Unk02023374 *pCanvas, Unk02022aa8 *pFont, s32 drawX, s32 drawY, u32 cl, NNSG2dGlyph *pGlyph);
void DrawGlyphLine(Unk02023374 *pCanvas, Unk02022aa8 *pFont, s32 drawX, s32 drawY, u32 cl, NNSG2dGlyph *pGlyph);
void LetterChar(LetterCharInfo *pInfo);
void ClearChar(u8 *pChar, s32 startX, s32 startY, s32 width, s32 height, u32 cl8, s32 bpp);
u32 OBJSizeToShape(const u8 *pSize);
void NNSi_G2dTextCanvasDrawTextAlign(TextCanvas *pTxn, s32 drawX, s32 drawY, s32 areaWidth, u32 cl, u32 flags,
                                     u16 *txt);
void NNSi_G2dTextCanvasDrawString(TextCanvas *pTxn, s32 drawX, s32 drawY, u32 cl, u16 *str, u16 **pPos);
void NNS_G2dCharCanvasInitForOBJ1D(void *pCC, void *charBase, s32 areaWidth, s32 areaHeight, s32 colorMode);
void NNS_G2dCharCanvasInitForBG(void *pCC, void *charBase, u32 areaWidth, u32 areaHeight, u32 colorMode);
s32 NNS_G2dCharCanvasDrawChar(Unk02023374 *pCanvas, Unk02022aa8 *pFont, s32 drawX, s32 drawY, u32 cl, u16 ccode);
u32 GetCharIndex1D(u32 cx, u32 cy, u32 areaWidth, u32 areaHeight, u32 objWidth, u32 objHeight);
void NNSi_G2dTextCanvasDrawTextRect(TextCanvas *pTxn, s32 drawX, s32 drawY, s32 areaWidth, s32 areaHeight, s32 cl,
                                    u32 flags, u16 *txt);
u32 NNSi_G2dTextCanvasDrawText(TextCanvas *pTxn, s32 drawX, s32 drawY, u32 cl, u32 flags, void *txt);
