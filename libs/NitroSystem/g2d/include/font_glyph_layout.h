#pragma once

#include "types.h"
#include "snd_bank.h"

// 3 bytes: NNSi_G2dFontGetStringWidth adds the first two, or reads the third.
typedef struct NNSG2dCharWidths {
    /* 00 */ s8 mLeft;
    /* 01 */ u8 mGlyphWidth;
    /* 02 */ s8 mCharWidth;
} NNSG2dCharWidths;

// Entry of the chain at 0x0c of an NNSG2dFontInformation: the range mIndexBegin..mIndexEnd with 8 bytes of header, then
// entries of NNSG2dFont.mWidthEntrySize bytes.
typedef struct NNSG2dFontWidth {
    /* 00 */ u16 mIndexBegin;
    /* 02 */ u16 mIndexEnd;
    /* 04 */ struct NNSG2dFontWidth *mPNext;
    /* 08 */ u8 mCharWidths[1];
} NNSG2dFontWidth;

// Halfword number, then pairs of halfwords.
typedef struct FontCodeMapInfo {
    /* 00 */ u16 mNum;
    /* 02 */ UnsignedHalfwordPair mScanEntries[1];
} FontCodeMapInfo;

// mMappingMethod values.
typedef enum FontCodeMapMethod {
    FONT_CODE_MAP_OFFSET = 0,
    FONT_CODE_MAP_TABLE = 1,
    FONT_CODE_MAP_PAIRS = 2,
} FontCodeMapMethod;

// Entry of the chain at 0x10 of an NNSG2dFontInformation: the range mCcodeBegin..mCcodeEnd and a
// FontCodeMapMethod kind: base number in mMapInfo[0], halfwords from mMapInfo, or mPairTable.mNum pairs.
typedef struct FontCodeMap {
    /* 00 */ u16 mCcodeBegin;
    /* 02 */ u16 mCcodeEnd;
    /* 04 */ u16 mMappingMethod;
    /* 06 */ u16 mReserved;
    /* 08 */ struct FontCodeMap *mPNext;
    union {
        /* 0c */ u16 mMapInfo[1];
        /* 0c */ FontCodeMapInfo mPairTable;
    };
} FontCodeMap;

// Object behind NNSG2dFontInformation.mPGlyph: a byte at 0x01, a halfword at 0x02 and bytes from 0x08
// (DrawKeyboardGlyphs).
typedef struct FontGlyph {
    /* 00 */ u8 mCellWidth;
    /* 01 */ u8 mCellHeight;
    /* 02 */ u16 mCellSize;
    /* 04 */ s8 mBaselinePos;
    /* 05 */ u8 mMaxCharWidth;
    /* 06 */ u8 mBpp;
    /* 07 */ u8 mFlags;
    /* 08 */ u8 mGlyphTable[1];
} FontGlyph;

typedef struct NNSG2dFontInformation {
    /* 00 */ u8 mFontType;
    /* 01 */ s8 mLinefeed;
    /* 02 */ u16 mAlterCharIndex;
    /* 04 */ NNSG2dCharWidths mDefaultWidth;
    /* 07 */ u8 mEncoding;
    /* 08 */ FontGlyph *mPGlyph;
    /* 0c */ NNSG2dFontWidth *mPWidth;
    /* 10 */ FontCodeMap *mPMap;
} NNSG2dFontInformation;

// Called with the address of a pointer to halfwords (NNSi_G2dSplitCharUTF16); returns a u16.
typedef u16 SplitCharFunc();

typedef struct NNSG2dFont {
    /* 00 */ NNSG2dFontInformation *mPRes;
    /* 04 */ SplitCharFunc *mCbCharSpliter;
    /* 08 */ u16 mFileVersionIndex;
    /* 0a */ u16 mWidthEntrySize;
} NNSG2dFont;

// Width and height written by NNSi_G2dFontGetTextRect.
typedef struct NNSG2dTextRect {
    /* 00 */ s32 mWidth;
    /* 04 */ s32 mHeight;
} NNSG2dTextRect;

#include "g2d_NSC_load.h" // NNSG2dBinaryFileHeader

void NNSi_G2dFontGetTextRect(NNSG2dTextRect *pRect, NNSG2dFont *pFont, s32 hSpace, s32 vSpace, u8 *txt);
s32 NNSi_G2dFontGetTextHeight(NNSG2dFont *pFont, s32 vSpace, u8 *txt);
s32 NNSi_G2dFontGetStringWidth(NNSG2dFont *pFont, s32 hSpace, u8 *str, u8 **pPos);
NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(NNSG2dFont *pFont, u32 idx);
u32 NNS_G2dFontFindGlyphIndex(NNSG2dFont *pFont, u32 code);
void NNS_G2dFontInitUTF16(NNSG2dFont *pFont, NNSG2dBinaryFileHeader *pNftrFile);
void NNS_G2dFontInitAuto(NNSG2dFont *pFont, NNSG2dBinaryFileHeader *pNftrFile);
u32 GetGlyphIndex(FontCodeMap *pMap, u32 code);
u32 NNSi_G2dCalcRequiredOBJ(u32 areaWidth, u32 areaHeight);
void NNS_G2dMapScrToChar256x16Pltt(u16 *areaBase, s32 areaWidth, s32 areaHeight, s32 scnWidth, s32 charNo, u32 cplt);
void NNS_G2dMapScrToCharText(u16 *scnBase, s32 areaWidth, s32 areaHeight, s32 areaLeft, s32 areaTop, s32 scnWidth,
                             s32 charNo, u32 cplt);

s32 NNS_G2dArrangeOBJ1D(void *oam, s32 areaWidth, s32 areaHeight, s32 originX, s32 originY, s32 color, s32 charName,
                        s32 vramMode);
