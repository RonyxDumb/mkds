#pragma once

#include "types.h"
#include "code_02010c84.h"
#include "code_02013740.h"
#include "code_02010804.h"

// Two samples read together by getScaleDataEx_.
typedef struct FxPairS16 {
    /* 00 */ s16 mFirst;
    /* 02 */ s16 mSecond;
} FxPairS16;

typedef struct FxPairS32 {
    /* 00 */ s32 mFirst;
    /* 04 */ s32 mSecond;
} FxPairS32;

// Bits of NNSG3dResNodeData.mFlag. The translation or rotation is left out when its bit is set. With ROT_PIVOT the
// rotation stores only two values; the pivot element is in bits 4 to 7, bit 8 makes it negative and the NEGATE bits
// flip the sign of the stored values when they are placed.
#define G3D_NODE_TRANS_IDENTITY 0x1
#define G3D_NODE_ROT_IDENTITY 0x2
#define G3D_NODE_ROT_PIVOT 0x8
#define G3D_NODE_ROT_PIVOT_MASK 0xf0
#define G3D_NODE_ROT_PIVOT_NEGATIVE 0x100
#define G3D_NODE_ROT_NEGATE_SECOND 0x200
#define G3D_NODE_ROT_NEGATE_FIRST 0x400

typedef struct NNSG3dResNodeData {
    /* 00 */ u16 mFlag;
    /* 02 */ s16 mRotFirst;
    /* 04 */ s16 mTransRotData[8];
} NNSG3dResNodeData;

void *NNSi_G3dGetBinaryBlockFromFile(const u8 *pFileHead, u32 fileSignature, u32 blockSignature);
NNSG3dResVisAnmSet *NNS_G3dGetVisAnmSet(const u8 *pFileHead);
NNSG3dResVisAnm *NNS_G3dGetVisAnmByIdx(NNSG3dResVisAnmSet *pAnmSet, u8 idx);
BOOL getRotDataByIdx_(MtxFx33 *pRot, const s16 *pArrayRot3, const s16 *pArrayRot5, u32 info);
void getRotDataEx_(MtxFx33 *pRot, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getRotData_(MtxFx33 *pRot, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getScaleDataEx_(s32 *sInvs, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getScaleData_(s32 *sInvs, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getTransDataEx_(s32 *pVal, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getTransData_(s32 *pVal, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getJntSRTAnmResult_(const NNSG3dResJntAnm *pJntAnm, int dataIdx, s32 frame, NNSG3dJntAnmResult *pResult);
void getMdlRot_(NNSG3dJntAnmResult *pResult);
void getMdlScale_(NNSG3dJntAnmResult *pResult);
void getMdlTrans_(NNSG3dJntAnmResult *pResult);
void NNSi_G3dAnmCalcNsBca(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, int dataIdx);
void NNSi_G3dAnmObjInitNsBca(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);
void NNSi_G3dAnmCalcNsBma(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBma(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);
u16 GetMatColAnmuAlphaValue_(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame);
u16 GetMatColAnmValue_(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame);
void NNSi_G3dAnmCalcNsBta(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBta(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);
void GetTexSRTAnm_(const NNSG3dResTexSRTAnm *pTexAnm, u16 idx, u32 frame, NNSG3dMatAnmResult *pResult);
u32 GetTexSRTAnmSinCosVal_(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, u32 data, u32 frame);
s32 GetTexSRTAnmVectorVal_(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, s32 data, u32 frame);
void NNSi_G3dAnmCalcNsBtp(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void SetPlttParamaters_(const NNSG3dResTex *pTex, const u32 *pPlttName, NNSG3dMatAnmResult *pResult);
void SetTexParamaters_(const NNSG3dResTex *pTex, const u32 *pTexName, NNSG3dMatAnmResult *pResult);
void NNSi_G3dAnmObjInitNsBtp(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);
void NNSi_G3dAnmCalcNsBva(u32 *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBva(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);

extern void (*NNS_G3dFuncSbcTable[32])(NNSG3dRS *, u32);
extern Vec3 gSbcBillboardYPosition;
extern Vec3 gSbcBillboardYScale;
