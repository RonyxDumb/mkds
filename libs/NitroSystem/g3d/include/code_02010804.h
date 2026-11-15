#pragma once

#include "types.h"
#include "code_02012b30.h"

typedef struct NNSG3dResTex NNSG3dResTex;
typedef u32 NNSG3dTexKey;
typedef u32 NNSG3dPlttKey;

typedef struct NNSG3dResTexInfo {
    /* 00 */ NNSG3dTexKey mVramKey;
    /* 04 */ u16 mSizeTex;
    /* 06 */ u16 mOfsDict;
    /* 08 */ u16 mFlag;
    /* 0a */ u16 mDummy_;
    /* 0c */ u32 mOfsTex;
} NNSG3dResTexInfo;

typedef struct NNSG3dResTex4x4Info {
    /* 00 */ NNSG3dTexKey mVramKey;
    /* 04 */ u16 mSizeTex;
    /* 06 */ u16 mOfsDict;
    /* 08 */ u16 mFlag;
    /* 0a */ u16 mDummy_;
    /* 0c */ u32 mOfsTex;
    /* 10 */ u32 mOfsTexPlttIdx;
} NNSG3dResTex4x4Info;

// Bit of NNSG3dResTex4x4Info.mFlag: the palette is the four-color kind; it is passed on when the palette is allocated.
#define G3D_TEX_4X4_FLAG_PLTT_4COLOR 0x8000

typedef struct NNSG3dResPlttInfo {
    /* 00 */ NNSG3dPlttKey mVramKey;
    /* 04 */ u16 mSizePltt;
    /* 06 */ u16 mFlag;
    /* 08 */ u16 mOfsDict;
    /* 0a */ u16 mDummy_;
    /* 0c */ u32 mOfsPlttData;
} NNSG3dResPlttInfo;

typedef struct NNSG3dResDictTexData {
    /* 00 */ u32 mTexImageParam;
    /* 04 */ u32 mExtraParam;
} NNSG3dResDictTexData;

typedef struct NNSG3dResDictPlttData {
    /* 00 */ u16 mOffset;
    /* 02 */ u16 mFlag;
} NNSG3dResDictPlttData;

// Flag of a texture palette entry: the palette holds four colors.
#define TEXTURE_PALETTE_FOUR_COLOR 0x8000

struct NNSG3dResTex {
    /* 00 */ NNSG3dResDataBlockHeader mHeader;
    /* 08 */ NNSG3dResTexInfo mTexInfo;
    /* 18 */ NNSG3dResTex4x4Info mTex4x4Info;
    /* 2c */ NNSG3dResPlttInfo mPlttInfo;
    /* 3c */ NNSG3dResDict mDict;
};

void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL execBeginEnd);
void NNS_G3dPlttSetPlttKey(NNSG3dResTex *pTex, NNSG3dPlttKey plttKey);
