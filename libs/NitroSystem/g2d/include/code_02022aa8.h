#pragma once

#include "types.h"
#include "code_020219e8.h" // Unk02021a5c

// 3 bytes: NNSi_G2dFontGetStringWidth adds the first two, or reads the third.
typedef struct NNSG2dCharWidths {
    /* 00 */ s8 mLeft;
    /* 01 */ u8 mGlyphWidth;
    /* 02 */ s8 mCharWidth;
} NNSG2dCharWidths;

// Entry of the chain at 0x0c of an NNSG2dFontInformation: a range of mUnk_00..mUnk_02 with 8 bytes of header, then
// entries of mUnk_0a (of the object) bytes.
typedef struct Unk02022c80_n {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ struct Unk02022c80_n *mUnk_04;
} Unk02022c80_n;

// Halfword number, then pairs of halfwords.
typedef struct Unk02022dd8_s {
    /* 00 */ u16 mUnk_00;
    /* 02 */ Unk02021a5c mUnk_02[1];
} Unk02022dd8_s;

// Entry of the chain at 0x10 of an NNSG2dFontInformation: a range of mUnk_00..mUnk_02 and a kind (0: base number in
// mUnk_0c, 1: halfwords from 0x0c, 2: mUnk_0c pairs from 0x0e).
typedef struct FontCodeMap {
    /* 00 */ u16 mCcodeBegin;
    /* 02 */ u16 mCcodeEnd;
    /* 04 */ u16 mMappingMethod;
    /* 06 */ u16 mReserved;
    /* 08 */ struct FontCodeMap *mPNext;
    /* 0c */ Unk02022dd8_s mMapInfo;
} FontCodeMap;

// Object behind NNSG2dFontInformation.mUnk_08: a byte at 0x01, a halfword at 0x02 and bytes from 0x08
// (DrawKeyboardGlyphs).
typedef struct Unk02022ce4_08 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ u8 mUnk_08[1];
} Unk02022ce4_08;

typedef struct NNSG2dFontInformation {
    /* 00 */ u8 mFontType;
    /* 01 */ s8 mLinefeed;
    /* 02 */ u16 mAlterCharIndex;
    /* 04 */ NNSG2dCharWidths mDefaultWidth;
    /* 07 */ u8 mEncoding;
    /* 08 */ Unk02022ce4_08 *mPGlyph;
    /* 0c */ Unk02022c80_n *mPWidth;
    /* 10 */ FontCodeMap *mPMap;
} NNSG2dFontInformation;

// Called with the address of a pointer to halfwords (NNSi_G2dSplitCharUTF16); returns a u16.
typedef u16 SplitCharFunc();

typedef struct Unk02022aa8 {
    /* 00 */ NNSG2dFontInformation *mPRes;
    /* 04 */ SplitCharFunc *mCbCharSpliter;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk02022aa8;

// Width and height written by NNSi_G2dFontGetTextRect.
typedef struct NNSG2dTextRect {
    /* 00 */ s32 mWidth;
    /* 04 */ s32 mHeight;
} NNSG2dTextRect;

#include "g2d_NSC_load.h" // NNSG2dBinaryFileHeader

void NNSi_G2dFontGetTextRect(NNSG2dTextRect *pRect, Unk02022aa8 *pFont, s32 hSpace, s32 vSpace, u8 *txt);
s32 NNSi_G2dFontGetTextHeight(Unk02022aa8 *pFont, s32 vSpace, u8 *txt);
s32 NNSi_G2dFontGetStringWidth(Unk02022aa8 *pFont, s32 hSpace, u8 *str, u8 **pPos);
NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(Unk02022aa8 *pFont, u32 idx);
u32 NNS_G2dFontFindGlyphIndex(Unk02022aa8 *pFont, u32 code);
void NNS_G2dFontInitUTF16(Unk02022aa8 *pFont, NNSG2dBinaryFileHeader *pNftrFile);
void NNS_G2dFontInitAuto(Unk02022aa8 *pFont, NNSG2dBinaryFileHeader *pNftrFile);
u32 GetGlyphIndex(FontCodeMap *pMap, u32 code);
u32 NNSi_G2dCalcRequiredOBJ(u32 areaWidth, u32 areaHeight);
void NNS_G2dMapScrToChar256x16Pltt(u16 *areaBase, s32 areaWidth, s32 areaHeight, s32 scnWidth, s32 charNo, u32 cplt);
void NNS_G2dMapScrToCharText(u16 *scnBase, s32 areaWidth, s32 areaHeight, s32 areaLeft, s32 areaTop, s32 scnWidth,
                             s32 charNo, u32 cplt);
