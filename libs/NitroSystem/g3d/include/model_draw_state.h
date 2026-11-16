#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx43, NNSG3dResMdl, NNSG3dResMatData, NNSG3dResShpData
#include "matrix44_concat.h" // MtxFx44

typedef struct NNSG3dAnmObj NNSG3dAnmObj;
typedef struct NNSG3dRS NNSG3dRS;
typedef struct NNSG3dResTex NNSG3dResTex;
typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;

// Result of a visibility animation.
typedef struct NNSG3dVisAnmResult {
    /* 00 */ BOOL mIsVisible;
} NNSG3dVisAnmResult;

// Bits of NNSG3dJntAnmResult.mFlag (also set in the first byte of a node's flags in the resource).
#define G3D_JNT_ANM_SCALE_IS_IDENTITY 0x1
#define G3D_JNT_ANM_ROT_IS_IDENTITY 0x2
#define G3D_JNT_ANM_TRANS_IS_IDENTITY 0x4
#define G3D_JNT_ANM_SCALE_EX0_IS_IDENTITY 0x8
#define G3D_JNT_ANM_SCALE_EX1_IS_IDENTITY 0x10
#define G3D_JNT_ANM_SCALE_EX_ARE_IDENTITY 0x18
#define G3D_JNT_ANM_ALL_IDENTITY 0x7

// Result of a joint animation for one node. Bit 0 of mFlag says the scale is one, bit 1 that the rotation is zero,
// bit 2 that the translation is zero, bits 3 and 4 that mScaleEx0 and mScaleEx1 are one.
typedef struct NNSG3dJntAnmResult {
    /* 00 */ u32 mFlag;
    /* 04 */ Vec3 mScale;
    /* 10 */ Vec3 mScaleEx0;
    /* 1c */ Vec3 mScaleEx1;
    /* 28 */ MtxFx33 mRot;
    /* 4c */ Vec3 mTrans;
} NNSG3dJntAnmResult;

// Bits of NNSG3dMatAnmResult.mFlag: the texture matrix parts that are left out, and whether the matrix is used.
#define G3D_MAT_ANM_SCALE_IS_IDENTITY 0x1
#define G3D_MAT_ANM_ROT_IS_IDENTITY 0x2
#define G3D_MAT_ANM_TRANS_IS_IDENTITY 0x4
#define G3D_MAT_ANM_TEX_MTX_SET 0x8

// Result of a material animation: the colors, polygon attributes and texture parameters of one material.
struct NNSG3dMatAnmResult {
    /* 00 */ u32 mFlag; // bit 3 set means the texture matrix is set from this result
    /* 04 */ u32 mPrmMatColor0;
    /* 08 */ u32 mPrmMatColor1;
    /* 0c */ u32 mPrmPolygonAttr;
    /* 10 */ u32 mPrmTexImage; // bits 30 and 31 are read and set
    /* 14 */ u32 mPrmTexPltt;
    /* 18 */ s32 mScaleST[2];
    /* 20 */ s16 mSinCosR[2];
    /* 24 */ s32 mTransST[2];
    /* 2c */ u16 mOrigWidth;
    /* 2e */ u16 mOrigHeight;
    /* 30 */ s32 mMagW;
    /* 34 */ s32 mMagH;
};

typedef BOOL (*NNSG3dFuncAnmBlendMat)(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);
typedef BOOL (*NNSG3dFuncAnmBlendJnt)(NNSG3dJntAnmResult *, const NNSG3dAnmObj *, u32);
typedef BOOL (*NNSG3dFuncAnmBlendVis)(NNSG3dVisAnmResult *, const NNSG3dAnmObj *, u32);
typedef void (*NNSG3dSbcCallBackFunc)(NNSG3dRS *);
typedef void (*NNSG3dGetJointScale)(NNSG3dJntAnmResult *, void *, u8 *, u32);

// Animation object. Several are linked through mNext; bit 8 and bit 9 of mMapData[n] are tested and the low byte is
// passed on to the function at mFuncAnm, which is called with a pointer to its result, this object and that byte.
struct NNSG3dAnmObj {
    /* 00 */ s32 mFrame;
    /* 04 */ s32 mRatio;
    /* 08 */ void *mResAnm;
    /* 0c */ void (*mFuncAnm)(void *, NNSG3dAnmObj *, u32);
    /* 10 */ NNSG3dAnmObj *mNext;
    /* 14 */ const NNSG3dResTex *mResTex;
    /* 18 */ u8 mPriority;
    /* 19 */ u8 mNumMapData;
    /* 1a */ u16 mMapData[1];
};

// Bit of NNSG3dRenderObj.mFlag: an animation object was added or removed, so the hint bit sets are rebuilt.
#define G3D_RENDER_OBJ_FLAG_ANM_CHANGED 0x10

// Default priority of an animation object.
#define G3D_ANM_PRIORITY_DEFAULT 0x7f

// Render object: the model and the animation objects drawn with it.
typedef struct NNSG3dRenderObj {
    /* 00 */ u32 mFlag;
    /* 04 */ NNSG3dResMdl *mResMdl;
    /* 08 */ NNSG3dAnmObj *mAnmMat;
    /* 0c */ NNSG3dFuncAnmBlendMat mFuncBlendMat;
    /* 10 */ NNSG3dAnmObj *mAnmJnt;
    /* 14 */ NNSG3dFuncAnmBlendJnt mFuncBlendJnt;
    /* 18 */ NNSG3dAnmObj *mAnmVis;
    /* 1c */ NNSG3dFuncAnmBlendVis mFuncBlendVis;
    /* 20 */ NNSG3dSbcCallBackFunc mCbFunc;
    /* 24 */ u8 mCbCmd;
    /* 25 */ u8 mCbTiming;
    /* 26 */ u16 mDummy_;
    /* 28 */ NNSG3dSbcCallBackFunc mCbInitFunc;
    /* 2c */ void *mPtrUser;
    /* 30 */ u8 *mPtrUserSbc;
    /* 34 */ NNSG3dJntAnmResult *mRecJntAnm;
    /* 38 */ NNSG3dMatAnmResult *mRecMatAnm;
    /* 3c */ u32 mHintMatAnmExist[2];
    /* 44 */ u32 mHintJntAnmExist[2];
    /* 4c */ u32 mHintVisAnmExist[2];
} NNSG3dRenderObj;

// NNSG3dRS.mFlag bit: mCurrentNodeDesc is valid.
#define NNS_G3D_RSFLAG_CURRENT_NODEDESC_VALID 0x10

// More NNSG3dRS.mFlag bits: bit 0 is set while the current node is visible; a callback sets bit 6 to say it did the
// work of the command itself; bit 8 stops the commands from being sent to the geometry engine; bit 9 makes the
// interpreter only step over the commands.
#define G3D_RS_FLAG_NODE_VISIBLE 0x1
#define G3D_RS_FLAG_CALLBACK_HANDLED 0x40
#define G3D_RS_FLAG_NO_COMMANDS 0x100
#define G3D_RS_FLAG_SKIP_ALL 0x200

// Render state of the SBC interpreter. mC points into the byte sequence that the SBC functions advance.
// NNSG3dRS.mFlag bits.
#define RENDER_STATE_NODE_VISIBLE 0x1
#define RENDER_STATE_NO_ALPHA 0x2
#define RENDER_STATE_NODE_SET 0x4
#define RENDER_STATE_MATERIAL_SET 0x8
#define RENDER_STATE_NODE_DESC_SET 0x10
#define RENDER_STATE_DONE 0x20
#define RENDER_STATE_SKIP_COMMAND 0x40
#define RENDER_STATE_RECORD 0x80
#define RENDER_STATE_NO_GE_COMMANDS 0x100
#define RENDER_STATE_SKIP_DRAW 0x200
#define RENDER_STATE_SKIP_MATRIX 0x400
// NNSG3dRenderObj.mFlag bits.
#define RENDER_OBJ_RECORD 0x1
#define RENDER_OBJ_NO_GE_COMMANDS 0x2
#define RENDER_OBJ_SKIP_DRAW 0x4
#define RENDER_OBJ_SKIP_MATRIX 0x8
#define RENDER_OBJ_HINTS_STALE 0x10
// NNSG3dMatAnmResult.mFlag bits.
#define MAT_RESULT_TEX_UNIT_SCALE 0x1
#define MAT_RESULT_TEX_NO_ROTATION 0x2
#define MAT_RESULT_TEX_NO_TRANSLATION 0x4
#define MAT_RESULT_TEX_MATRIX_SET 0x8
#define MAT_RESULT_TEX_MATRIX_MULTIPLY 0x10
#define MAT_RESULT_WIREFRAME 0x20
// NNSG3dJntAnmResult.mFlag bits.
#define JNT_RESULT_NO_ROTATION 0x2
#define JNT_RESULT_NO_TRANSLATION 0x4
#define JNT_RESULT_FIRST_EXTRA_SCALE_UNIT 0x8
#define JNT_RESULT_SECOND_EXTRA_SCALE_UNIT 0x10
#define JNT_RESULT_SEGMENT_SCALE_COMPENSATE 0x20
// Material data flag bits.
#define MAT_DATA_TEX_MATRIX_USED 0x1
#define MAT_DATA_TEX_UNIT_SCALE 0x2
#define MAT_DATA_TEX_NO_ROTATION 0x4
#define MAT_DATA_TEX_NO_TRANSLATION 0x8
#define MAT_DATA_WIREFRAME 0x20
// Polygon attribute bits 16 to 20, the alpha of the polygon.
#define G3D_POLYGON_ATTR_ALPHA_MASK 0x1f0000
// Entries of the callback vectors of NNSG3dRS (one per SBC command number).
#define G3D_CALLBACK_VECTOR_COUNT 0x20

struct NNSG3dRS {
    /* 00 */ u8 *mC;
    /* 04 */ NNSG3dRenderObj *mRenderObj;
    /* 08 */ u32 mFlag; // bit 0, bit 6, bit 8 and bit 9 are tested
    /* 0c */ NNSG3dSbcCallBackFunc mCbVecFunc[G3D_CALLBACK_VECTOR_COUNT];
    /* 8c */ u8 mCbVecTiming[G3D_CALLBACK_VECTOR_COUNT];
    /* ac */ u8 mCurrentNode;
    /* ad */ u8 mCurrentMat;
    /* ae */ u8 mCurrentNodeDesc;
    /* af */ u8 mDummy_;
    /* b0 */ NNSG3dMatAnmResult *mMatAnmResult;
    /* b4 */ NNSG3dJntAnmResult *mJntAnmResult;
    /* b8 */ NNSG3dVisAnmResult *mVisAnmResult;
    /* bc */ u32 mIsMatCached[2];
    /* c4 */ u32 mIsScaleCacheOne[2];
    /* cc */ u32 mIsEvpCached[2]; // bit set indexed by a node number (word = number >> 5)
    /* d4 */ void *mResNodeInfo;
    /* d8 */ NNSG3dResMat *mResMat;
    /* dc */ void *mResShp;
    /* e0 */ s32 mPosScale;
    /* e4 */ s32 mInvPosScale;
    /* e8 */ NNSG3dGetJointScale mFuncJntScale;
    /* ec */ void (*mFuncJntMtx)(NNSG3dJntAnmResult *);
    /* f0 */ void (*mFuncTexMtx)(NNSG3dMatAnmResult *);
    /* f4 */ NNSG3dMatAnmResult mTmpMatAnmResult;
    /* 12c */ NNSG3dJntAnmResult mTmpJntAnmResult;
    /* 184 */ NNSG3dVisAnmResult mTmpVisAnmResult;
};

// Caches of the SBC interpreter: material results, joint scale and inverse scale, and the envelope matrices with their
// normal matrices, indexed by material or joint number below 64.
typedef struct NNSG3dRSOnGlb {
    /* 0000 */ NNSG3dMatAnmResult mMatCache[64];
    struct {
        /* 00 */ Vec3 mScale;
        /* 0c */ Vec3 mInvScale;
    } /* 0e00 */ mScaleCache[64];
    struct {
        /* 00 */ s32 mMtx[16];
        /* 40 */ s32 mNrmMtx[9];
    } /* 1400 */ mEvpCache[64];
} NNSG3dRSOnGlb;

// One animation format of the table of animation formats: its categories and its StructDC_SomeFn_from_thumb function.
typedef struct NNSG3dAnmObjInitFunc {
    /* 00 */ u8 mCategory0;
    /* 01 */ u8 mDummy_;
    /* 02 */ u16 mCategory1;
    /* 04 */ void (*mFunc)(NNSG3dAnmObj *, void *, const NNSG3dResMdl *);
} NNSG3dAnmObjInitFunc;

// Header of an animation resource.
typedef struct NNSG3dResAnmHeader {
    /* 00 */ u8 mCategory0;
    /* 01 */ u8 mRevision;
    /* 02 */ u16 mCategory1;
} NNSG3dResAnmHeader;

// Packed viewport value of mPrmViewPort that covers the whole screen.
#define VIEWPORT_WHOLE_SCREEN 0xbfff0000

// Matrix modes of the geometry engine that the interpreter sets: position and vector matrices together, texture matrix.
#define G3D_MTX_MODE_POS_VEC 2
#define G3D_MTX_MODE_TEXTURE 3

// Bits of NNSG3dGlb.mFlag. The first two are tested by the billboard and environment map commands to pick the camera
// matrices they multiply in (both are cleared by NNS_G3dGlbFlushP). The valid bits say that the cached inverse is up
// to date; G3D_GLB_BASE_DEPENDENT_CACHES are the bits of the caches that depend on the base transform.
#define G3D_GLB_FLAG_USE_BASE_SRT_CAMERA 0x1
#define G3D_GLB_FLAG_USE_CAMERA 0x2
#define G3D_GLB_FLAG_INV_CAMERA_VALID 0x8
#define G3D_GLB_FLAG_SRT_CAMERA_VALID 0x80
#define G3D_GLB_BASE_DEPENDENT_CACHES 0xa4

// Global state of the G3D library; the leading part is sent to the geometry engine as one command block.
typedef struct NNSG3dGlb {
    /* 000 */ u32 mCmd0;
    /* 004 */ u32 mMtxModeProj;
    /* 008 */ MtxFx44 mProjMtx;
    /* 048 */ u32 mMtxModePosVec;
    /* 04c */ MtxFx43 mCameraMtx;
    /* 07c */ u32 mCmd1;
    /* 080 */ u32 mLightVec[4];
    /* 090 */ u32 mCmd2;
    /* 094 */ u32 mPrmMatColor0;
    /* 098 */ u32 mPrmMatColor1;
    /* 09c */ u32 mPrmPolygonAttr;
    /* 0a0 */ u32 mPrmViewPort;
    /* 0a4 */ u32 mCmd3;
    /* 0a8 */ u32 mLightColor[4];
    /* 0b8 */ u32 mCmd4;
    /* 0bc */ MtxFx33 mPrmBaseRot;
    /* 0e0 */ Vec3 mPrmBaseTrans;
    /* 0ec */ Vec3 mPrmBaseScale;
    /* 0f8 */ u32 mPrmTexImageParam;
    /* 0fc */ u32 mFlag;
    /* 100 */ MtxFx43 mInvCameraMtx;
    /* 130 */ MtxFx43 mSrtCameraMtx;
    /* 160 */ MtxFx43 mInvSrtCameraMtx;
    /* 190 */ MtxFx43 mInvBaseMtx;
    /* 1c0 */ MtxFx44 mInvProjMtx;
    /* 200 */ MtxFx44 mInvCameraProjMtx;
    /* 240 */ Vec3 mCamPos;
    /* 24c */ Vec3 mCamUp;
    /* 258 */ Vec3 mCamTarget;
} NNSG3dGlb;

void StructML_MaybeSetModel(NNSG3dRenderObj *renderObj, NNSG3dResMdl *resMdl);
void MaybeCreateAnimationBlock(NNSG3dAnmObj *anmObj, void *resAnm, const NNSG3dResMdl *resMdl, void *resTex);
u32 Anim_GetNeededBlockSize(const NNSG3dResAnmHeader *anm, const NNSG3dResMdl *mdl);
MtxFx43 *NNS_G3dGlbGetInvWV(void);
MtxFx43 *NNS_G3dGlbGetWV(void);
void calcSrtCameraMtx_(void);
MtxFx43 *NNS_G3dGlbGetInvV(void);
void NNS_G3dGlbPolygonAttr(u32 light, u32 polyMode, u32 cullMode, u32 polygonId, u32 alpha, u32 extra);
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 shininess);
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 vtxColor);
void NNS_G3dGlbLightColor(u32 lightId, u32 rgb);
void NNS_G3dGlbLightVector(u32 lightId, s32 vectorX, s32 vectorY, s32 vectorZ);
void NNS_G3dGlbSetBaseScale(const Vec3 *scale);
void NNS_G3dGlbSetBaseTrans(const Vec3 *trans);
void NNS_G3dGlbFlushP(void);
void NNS_G3dGlbInit(void);
BOOL NNSi_G3dAnmBlendVis(NNSG3dVisAnmResult *result, NNSG3dAnmObj *anmObj, u32 nodeId);
BOOL NNSi_G3dAnmBlendJnt(NNSG3dJntAnmResult *result, NNSG3dAnmObj *anmObj, u32 nodeId);
void blendScaleVec_(Vec3 *dest, const Vec3 *src, s32 weight, u32 srcIsOne);
BOOL NNSi_G3dAnmBlendMat(NNSG3dMatAnmResult *result, NNSG3dAnmObj *anmObj, u32 matId);
void NNSi_G3dFuncSbc_PRJMAP(NNSG3dRS *state);
void NNSi_G3dFuncSbc_ENVMAP(NNSG3dRS *state);
void NNSi_G3dFuncSbc_CALLDL(NNSG3dRS *state);
void NNSi_G3dFuncSbc_NODEMIX(NNSG3dRS *state);
void NNSi_G3dFuncSbc_BBY(NNSG3dRS *state, u32 mode);
void NNSi_G3dFuncSbc_BB(NNSG3dRS *state, u32 mode);
void NNS_G3dDraw1Mat1Shp(NNSG3dResMdl *resMdl, u32 matId, u32 shpId, BOOL sendMat);
