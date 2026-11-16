#pragma once

#include "types.h"
#include "Main/Graphics/animation_function_pointers.h"

// Four words of a 2x2 matrix.
typedef struct MtxFx22 {
    /* 00 */ s32 mElements[4];
} MtxFx22;

// Three rows of three words.
typedef struct MtxFx33 {
    union {
        /* 00 */ Vec3 mRows[3];
        /* 00 */ s32 mElements[9];
    };
} MtxFx33;

// Matrix of three direction vectors and a position.
typedef struct MtxFx43 {
    union {
        /* 00 */ Vec3 mRows[4];
        /* 00 */ MtxFx33 mAxes;
    };
} MtxFx43;

typedef struct NNSG3dResDictTreeNode {
    /* 00 */ u8 mRefBit;
    /* 01 */ u8 mIdxLeft;
    /* 02 */ u8 mIdxRight;
    /* 03 */ u8 mIdxEntry;
} NNSG3dResDictTreeNode;

// Dictionaries below this many entries are searched one name after the other, dictionaries of this many entries or more
// through the tree.
#define G3D_DICT_LINEAR_SEARCH_LIMIT 0x10

typedef struct NNSG3dResDict {
    /* 00 */ u8 mRevision;
    /* 01 */ u8 mNumEntry;
    /* 02 */ u16 mSizeDictBlk;
    /* 04 */ u16 mDummy_;
    /* 06 */ u16 mOfsEntry;
    /* 08 */ NNSG3dResDictTreeNode mNode[1];
} NNSG3dResDict;

typedef struct NNSG3dResDictEntryHeader {
    /* 00 */ u16 mSizeUnit;
    /* 02 */ u16 mOfsName;
    /* 04 */ u8 mData[4];
} NNSG3dResDictEntryHeader;

// Entry idx of a dictionary whose entries are all of type T, and the 16-byte name of entry idx.
#define DICT_ENTRY(T, entries, idx) ((T *) ((entries)->mData + (entries)->mSizeUnit * (idx)))
#define DICT_ENTRY_NAME(entries, idx) ((const u32 *) ((const u8 *) (entries) + (entries)->mOfsName + (idx) * 16))

typedef struct NNSG3dResShp {
    /* 00 */ NNSG3dResDict mDict;
} NNSG3dResShp;

typedef struct NNSG3dResMat {
    /* 00 */ u16 mOfsDictTexToMatList;
    /* 02 */ u16 mOfsDictPlttToMatList;
    /* 04 */ NNSG3dResDict mDict;
} NNSG3dResMat;

// Bits of NNSG3dResMatData.mFlag. The three NO_TEX bits say that the scale, rotation or translation part is left out of
// the words at mTexMtxData; HAS_EXTRA_MTX says that 16 more words follow those parts (only the environment map and
// projection map commands read them).
#define G3D_MAT_FLAG_HAS_TEX_MTX 0x1
#define G3D_MAT_FLAG_NO_TEX_SCALE 0x2
#define G3D_MAT_FLAG_NO_TEX_ROT 0x4
#define G3D_MAT_FLAG_NO_TEX_TRANS 0x8
#define G3D_MAT_FLAG_WIREFRAME 0x20
#define G3D_MAT_FLAG_HAS_EXTRA_MTX 0x2000

// Polygon attribute fields of NNSG3dResMatData.mPolyAttr, fields of the texture image word (mTexImageParam,
// mPrmTexImage), of mExtraParam and of the VRAM keys (mVramKey).
#define G3D_POLY_ATTR_ALPHA_MASK 0x1f0000
#define G3D_POLY_ATTR_FOG 0x8000
#define G3D_POLY_ATTR_XL_DEPTH_UPDATE 0x800
#define G3D_POLY_ATTR_CULL_MODE_MASK 0xc0
#define G3D_POLY_ATTR_POLYGON_ID_MASK 0x3f000000
#define G3D_TEX_IMAGE_FORMAT_MASK 0x1c000000
#define G3D_TEX_IMAGE_FORMAT_4X4 0x14000000
#define G3D_TEX_IMAGE_KEEP_MASK 0xc00f0000
#define G3D_TEX_GEN_MASK 0xc0000000
#define G3D_TEX_GEN_TEXCOORD 0x40000000
#define G3D_TEX_GEN_ENV_MAP 0x80000000
#define G3D_TEX_GEN_PROJ_MAP 0xc0000000
#define G3D_TEX_EXTRA_WIDTH_MASK 0x7ff
#define G3D_TEX_EXTRA_HEIGHT_MASK 0x3ff800
#define G3D_VRAM_KEY_OFFSET_MASK 0xffff

typedef struct NNSG3dResMatData {
    /* 00 */ u16 mItemTag;
    /* 02 */ u16 mSize;
    /* 04 */ u32 mDiffAmb;
    /* 08 */ u32 mSpecEmi;
    /* 0c */ u32 mPolyAttr; // bits 16-20 are the alpha
    /* 10 */ u32 mPolyAttrMask;
    /* 14 */ u32 mTexImageParam;
    /* 18 */ u32 mTexImageParamMask;
    /* 1c */ u16 mTexPlttBase;
    /* 1e */ u16 mFlag; // bits 0-3, 5 and 13 are tested
    /* 20 */ u16 mOrigWidth;
    /* 22 */ u16 mOrigHeight;
    /* 24 */ s32 mMagW;
    /* 28 */ s32 mMagH;
    /* 2c */ u8 mTexMtxData[1]; // optional texture matrix words follow
} NNSG3dResMatData;

typedef struct NNSG3dResShpData {
    /* 00 */ u16 mItemTag;
    /* 02 */ u16 mSize;
    /* 04 */ u32 mFlag;
    /* 08 */ u32 mOfsDL; // byte offset from this struct
    /* 0c */ u32 mSizeDL; // second argument of NNS_G3dGeSendDL
} NNSG3dResShpData;

typedef struct NNSG3dResMdlInfo {
    /* 00 */ u8 mSbcType;
    /* 01 */ u8 mScalingRule;
    /* 02 */ u8 mTexMtxMode;
    /* 03 */ u8 mNumNode;
    /* 04 */ u8 mNumMat;
    /* 05 */ u8 mNumShp;
    /* 06 */ u8 mFirstUnusedMtxStackID;
    /* 07 */ u8 mDummy_;
    /* 08 */ s32 mPosScale;
    /* 0c */ s32 mInvPosScale;
    /* 10 */ u16 mNumVertex;
    /* 12 */ u16 mNumPolygon;
    /* 14 */ u16 mNumTriangle;
    /* 16 */ u16 mNumQuad;
    /* 18 */ s16 mBoxX;
    /* 1a */ s16 mBoxY;
    /* 1c */ s16 mBoxZ;
    /* 1e */ s16 mBoxW;
    /* 20 */ s16 mBoxH;
    /* 22 */ s16 mBoxD;
    /* 24 */ s32 mBoxPosScale;
    /* 28 */ s32 mBoxInvPosScale;
} NNSG3dResMdlInfo;

// Model resource: byte offsets (counted from this struct) of the SBC, material and shape blocks.
typedef struct NNSG3dResMdl {
    /* 00 */ u32 mSize;
    /* 04 */ u32 mOfsSbc;
    /* 08 */ u32 mOfsMat;
    /* 0c */ u32 mOfsShp;
    /* 10 */ u32 mOfsEvpMtx;
    /* 14 */ NNSG3dResMdlInfo mInfo;
    /* 40 */ NNSG3dResDict mNodeInfo;
} NNSG3dResMdl;

// File file of a model or texture resource: signature, then at headerSize the table of data block offsets.
typedef struct NNSG3dResTex NNSG3dResTex;

// Values of NNSG3dResFileHeader.mSigVal: the four file name letters plus a version digit, read as one word.
#define FILE_SIGNATURE_MODEL 0x30444d42
#define FILE_SIGNATURE_TEXTURE 0x30585442
#define FILE_SIGNATURE_VISIBILITY_ANIM 0x30415642
#define FILE_SIGNATURE_MATERIAL_COLOR_ANIM 0x30414d42
#define FILE_SIGNATURE_JOINT_ANIM 0x30414342
#define FILE_SIGNATURE_TEXTURE_SRT_ANIM 0x30415442
#define FILE_SIGNATURE_TEXTURE_PATTERN_ANIM 0x30505442

typedef struct NNSG3dResFileHeader {
    /* 00 */ u32 mSigVal;
    /* 04 */ u16 mByteOrder;
    /* 06 */ u16 mVersion;
    /* 08 */ u32 mFileSize;
    /* 0c */ u16 mHeaderSize;
    /* 0e */ u16 mDataBlocks;
} NNSG3dResFileHeader;

// Value of the mSignature of a model data block: the ASCII tag "MDL0".
#define RES_BLOCK_SIGNATURE_MODEL_SET 0x304c444d

// Header of a data block of a resource file.
typedef struct NNSG3dResDataBlockHeader {
    /* 00 */ u32 mSignature;
    /* 04 */ u32 mSize;
} NNSG3dResDataBlockHeader;

void NNS_G3dResDefaultRelease(NNSG3dResFileHeader *file);
s32 NNS_G3dResDefaultSetup(NNSG3dResFileHeader *file);
void NNS_G3dInit(void);
void NNS_G3dGetCurrentMtx(MtxFx43 *pos, void *vec);
void NNS_G3dMdlSetMdlXLDepthUpdateAll(NNSG3dResMdl *mdl, u32 flag);
void NNS_G3dMdlSetMdlFogEnableFlagAll(NNSG3dResMdl *mdl, u32 flag);
void NNS_G3dMdlSetMdlAlphaAll(NNSG3dResMdl *mdl, u32 alpha);
void NNS_G3dMdlSetMdlPolygonIDAll(NNSG3dResMdl *mdl, u32 polygonId);
void NNS_G3dMdlSetMdlCullModeAll(NNSG3dResMdl *mdl, u32 cullMode);
void NNS_G3dMdlSetMdlPolygonModeAll(NNSG3dResMdl *mdl, u32 polyMode);
void NNS_G3dMdlSetMdlLightEnableFlagAll(NNSG3dResMdl *mdl, u32 light);
void NNS_G3dMdlSetMdlEmiAll(NNSG3dResMdl *mdl, u32 color);
void NNS_G3dMdlSetMdlSpecAll(NNSG3dResMdl *mdl, u32 color);
void NNS_G3dMdlSetMdlAmbAll(NNSG3dResMdl *mdl, u32 color);
void NNS_G3dMdlSetMdlDiffAll(NNSG3dResMdl *mdl, u32 color);
u32 NNS_G3dMdlGetMdlFogEnableFlag(NNSG3dResMdl *mdl, u32 matId);
u32 NNS_G3dMdlGetMdlAlpha(NNSG3dResMdl *mdl, u32 matId);
u32 NNS_G3dMdlGetMdlPolygonID(NNSG3dResMdl *mdl, u32 matId);
u32 NNS_G3dMdlGetMdlCullMode(NNSG3dResMdl *mdl, u32 matId);
void NNS_G3dMdlSetMdlXLDepthUpdate(NNSG3dResMdl *mdl, u32 matId, s32 flag);
void NNS_G3dMdlSetMdlFogEnableFlag(NNSG3dResMdl *mdl, u32 matId, s32 flag);
void NNS_G3dMdlSetMdlAlpha(NNSG3dResMdl *mdl, u32 matId, u32 alpha);
void NNS_G3dMdlSetMdlPolygonID(NNSG3dResMdl *mdl, u32 matId, u32 polygonId);
void NNS_G3dMdlSetMdlCullMode(NNSG3dResMdl *mdl, u32 matId, u32 cullMode);
void NNS_G3dMdlSetMdlPolygonMode(NNSG3dResMdl *mdl, u32 matId, u32 polyMode);
void NNS_G3dMdlSetMdlLightEnableFlag(NNSG3dResMdl *mdl, u32 matId, u32 light);
void NNS_G3dMdlSetMdlEmi(NNSG3dResMdl *mdl, u32 matId, u32 color);
void NNS_G3dMdlSetMdlSpec(NNSG3dResMdl *mdl, u32 matId, u32 color);
void NNS_G3dMdlSetMdlAmb(NNSG3dResMdl *mdl, u32 matId, u32 color);
void NNS_G3dMdlSetMdlDiff(NNSG3dResMdl *mdl, u32 matId, u32 color);
NNSG3dResTex *NNS_G3dGetTex(NNSG3dResFileHeader *file);

extern u32 gPrjMapTexImageParamCommand[2];
extern u32 gEnvMapTexImageParamCommand[2];
extern void (*NNS_G3dFuncSbcMatTable[4])(NNSG3dRS *, u32, void *, u32);
extern void (*NNS_G3dFuncSbcShpTable[4])(NNSG3dRS *, u32, void *, u32);
extern s32 gPrjMapTextureMtx[16];
