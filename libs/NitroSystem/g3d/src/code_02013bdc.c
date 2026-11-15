#include "code_02013bdc.h"
#include "code_02013740.h"
#include "res_struct_accessor_anm.h"
#include "code_02147cd8.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "unk_02152000_data.h"
#include "Main/Graphics/g3d_anm_function_pointers.h"
#include "data_02170000.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "code_02010c84.h"

void (*NNS_G3dFuncSbcTable[32])(NNSG3dRS *, u32) = {NNSi_G3dFuncSbc_NOP,
                                                    NNSi_G3dFuncSbc_RET,
                                                    NNSi_G3dFuncSbc_NODE,
                                                    NNSi_G3dFuncSbc_MTX,
                                                    NNSi_G3dFuncSbc_MAT,
                                                    NNSi_G3dFuncSbc_SHP,
                                                    NNSi_G3dFuncSbc_NODEDESC,
                                                    NNSi_G3dFuncSbc_BB,
                                                    NNSi_G3dFuncSbc_BBY,
                                                    (void (*)(NNSG3dRS *, u32)) NNSi_G3dFuncSbc_NODEMIX,
                                                    (void (*)(NNSG3dRS *, u32)) NNSi_G3dFuncSbc_CALLDL,
                                                    NNSi_G3dFuncSbc_POSSCALE,
                                                    (void (*)(NNSG3dRS *, u32)) NNSi_G3dFuncSbc_ENVMAP,
                                                    (void (*)(NNSG3dRS *, u32)) NNSi_G3dFuncSbc_PRJMAP,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    NULL};
#pragma explicit_zero_data on
Vec3 gSbcBillboardYScale = {0, 0, 0};
Vec3 gSbcBillboardYPosition = {0, 0, 0};
#pragma explicit_zero_data off

const u8 gRotPivotIndices[9][4] = {
    {4, 5, 7, 8}, {3, 5, 6, 8}, {3, 4, 6, 7}, {1, 2, 7, 8}, {0, 2, 6, 8},
    {0, 1, 6, 7}, {1, 2, 4, 5}, {0, 2, 3, 5}, {0, 1, 3, 4},
};

void NNSi_G3dAnmObjInitNsBva(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    u32 mapIndex;

    pAnmObj->mFuncAnm = NNS_G3dFuncAnmVisNsBvaDefault;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumNode;
    pAnmObj->mResAnm = pResAnm;
    for (mapIndex = 0; mapIndex < pAnmObj->mNumMapData; mapIndex++) {
        pAnmObj->mMapData[mapIndex] = mapIndex | 0x100;
    }
}

void NNSi_G3dAnmCalcNsBva(u32 *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx) {
    NNSG3dResVisAnm *visAnim;
    u32 bitPos;

    visAnim = pAnmObj->mResAnm;
    bitPos = FROM_FIXED12(pAnmObj->mFrame) * visAnim->mNumNode + dataIdx;
    *pResult = visAnim->mVisData[bitPos >> 5] & (1 << (bitPos & 0x1f));
}

void NNSi_G3dAnmObjInitNsBtp(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    volatile u16 zero;
    NNSG3dResTexPatAnm *patAnim;
    u8 *matBlock;
    NNSG3dResDictEntryHeader *dictEntries;
    s32 matIdx;
    u32 entryIndex;

    patAnim = pResAnm;
    matBlock = (u8 *) pResMdl + pResMdl->mOfsMat;
    pAnmObj->mFuncAnm = NNS_G3dFuncAnmMatNsBtpDefault;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumMat;
    pAnmObj->mResAnm = patAnim;
    zero = 0;
    MIi_CpuClear16(zero, pAnmObj->mMapData, pAnmObj->mNumMapData * 2);
    for (entryIndex = 0; entryIndex < patAnim->mDict.mNumEntry; entryIndex++) {
        dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &patAnim->mDict, patAnim->mDict.mOfsEntry);
        matIdx = NNS_G3dGetResDictIdxByName(matBlock + 4, DICT_ENTRY_NAME(dictEntries, entryIndex));
        if (matIdx >= 0) {
            pAnmObj->mMapData[matIdx] = entryIndex | 0x100;
        }
    }
}

void SetTexParamaters_(const NNSG3dResTex *pTex, const u32 *pTexName, NNSG3dMatAnmResult *pResult) {
    const NNSG3dResDictTexData *texEntry;
    u32 imageParam;
    u32 keyOffset;
    s32 width;
    s32 height;

    texEntry = NNS_G3dGetResDataByName(&pTex->mDict, pTexName);
    imageParam = pResult->mPrmTexImage;
    if ((texEntry->mTexImageParam & G3D_TEX_IMAGE_FORMAT_MASK) != G3D_TEX_IMAGE_FORMAT_4X4_COMPRESSED) {
        keyOffset = pTex->mTexInfo.mVramKey & G3D_VRAM_KEY_OFFSET_MASK;
    } else {
        keyOffset = pTex->mTex4x4Info.mVramKey & G3D_VRAM_KEY_OFFSET_MASK;
    }
    pResult->mPrmTexImage = imageParam & G3D_TEX_IMAGE_KEEP_MASK;
    pResult->mPrmTexImage = pResult->mPrmTexImage | (texEntry->mTexImageParam + keyOffset);
    pResult->mOrigWidth = texEntry->mExtraParam & G3D_TEX_EXTRA_WIDTH_MASK;
    pResult->mOrigHeight = (texEntry->mExtraParam & G3D_TEX_EXTRA_HEIGHT_MASK) >> 11;
    width = texEntry->mExtraParam & G3D_TEX_EXTRA_WIDTH_MASK;
    height = G3D_TEX_EXTRA_WIDTH_MASK & (texEntry->mExtraParam >> 11);
    if (width == pResult->mOrigWidth) {
        width = 0x1000;
    } else {
        width = FX_Div(TO_FIXED12(width), TO_FIXED12(pResult->mOrigWidth));
    }
    pResult->mMagW = width;
    if (height == pResult->mOrigHeight) {
        height = 0x1000;
    } else {
        height = FX_Div(TO_FIXED12(height), TO_FIXED12(pResult->mOrigHeight));
    }
    pResult->mMagH = height;
}

void SetPlttParamaters_(const NNSG3dResTex *pTex, const u32 *pPlttName, NNSG3dMatAnmResult *pResult) {
    const NNSG3dResDictPlttData *plttEntry;
    u32 keyOffset;
    u32 base;

    plttEntry = NNS_G3dGetResDataByName((u8 *) pTex + pTex->mPlttInfo.mOfsDict, pPlttName);
    keyOffset = (u16) pTex->mPlttInfo.mVramKey;
    base = plttEntry->mOffset;
    if (!(plttEntry->mFlag & 1)) {
        base = (u16) (base >> 1);
        keyOffset = (u16) (keyOffset >> 1);
    }
    pResult->mPrmTexPltt = base + keyOffset;
}

void NNSi_G3dAnmCalcNsBtp(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx) {
    NNSG3dResTexPatAnmFV *frameEntry;
    NNSG3dResTexPatAnm *patAnim;

    patAnim = pAnmObj->mResAnm;
    frameEntry = NNSi_G3dGetTexPatAnmFV(patAnim, (u16) dataIdx, (u32) (pAnmObj->mFrame << 4) >> 16);
    SetTexParamaters_(pAnmObj->mResTex, NNSi_G3dGetTexPatAnmTexNameByIdx(patAnim, frameEntry->mIdTex), pResult);
    if (frameEntry->mIdPltt == G3D_PATTERN_NO_PALETTE) {
        return;
    }
    SetPlttParamaters_(pAnmObj->mResTex, NNSi_G3dGetTexPatAnmPlttNameByIdx(patAnim, frameEntry->mIdPltt), pResult);
}

// Blends the two stored values when the frame falls between them.
s32 GetTexSRTAnmVectorVal_(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, s32 data, u32 frame) {
    const u8 *values;
    u32 lastStep;
    u32 sample;
    s32 first;
    s32 second;

    if (info & 0x20000000) {
        return data;
    }
    values = (const u8 *) pTexAnm;
    values += data;
    if (info & 0xc0000000) {
        lastStep = info & 0xffff;
        if (info & 0x40000000) {
            if (frame & 1) {
                if (frame > lastStep) {
                    frame = (lastStep >> 1) + 1;
                    goto single;
                }
                frame >>= 1;
                goto half;
            }
            frame >>= 1;
            goto single;
        }
        if (frame & 3) {
            if (frame > lastStep) {
                frame = (frame & 3) + (lastStep >> 2);
                goto single;
            }
            if (frame & 1) {
                if (frame & 2) {
                    frame >>= 2;
                    sample = frame + 1;
                } else {
                    sample = frame >> 2;
                    frame = sample + 1;
                }
                if (info & 0x10000000) {
                    first = ((const s16 *) values)[sample];
                    second = ((const s16 *) values)[frame];
                } else {
                    first = ((const s32 *) values)[sample];
                    second = ((const s32 *) values)[frame];
                }
                return (first * 3 + second) >> 2;
            }
            frame >>= 2;
            goto half;
        }
        frame >>= 2;
    }
single:
    if (info & 0x10000000) {
        return ((const s16 *) values)[frame];
    }
    return ((const s32 *) values)[frame];
half:
    if (info & 0x10000000) {
        first = ((const s16 *) values)[frame];
        second = (&((const s16 *) values)[frame])[1];
    } else {
        first = ((const s32 *) values)[frame];
        second = (&((const s32 *) values)[frame])[1];
    }
    return (first + second) >> 1;
}

// Returns sine in the low halfword and cosine in the high halfword.
u32 GetTexSRTAnmSinCosVal_(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, u32 data, u32 frame) {
    const FxPairS16 *values;
    u32 lastStep;
    u32 sample;
    s32 sinValue;
    s32 sSub;
    s32 cosValue;
    s32 cSub;

    if (info & 0x20000000) {
        return data;
    }
    values = OFFSET_PTR(const FxPairS16, pTexAnm, data);
    if (info & 0xc0000000) {
        lastStep = info & 0xffff;
        if (info & 0x40000000) {
            if (frame & 1) {
                if (frame > lastStep) {
                    frame = (lastStep >> 1) + 1;
                    goto single;
                }
                sample = frame >> 1;
                goto half;
            }
            frame >>= 1;
            goto single;
        }
        if (frame & 3) {
            if (frame > lastStep) {
                frame = (frame & 3) + (lastStep >> 2);
                goto single;
            }
            if (frame & 1) {
                if (frame & 2) {
                    lastStep = frame >> 2;
                    sample = lastStep + 1;
                } else {
                    sample = frame >> 2;
                    lastStep = sample + 1;
                }
                sinValue = values[sample].mFirst;
                sSub = values[lastStep].mFirst;
                cosValue = values[sample].mSecond;
                cSub = values[lastStep].mSecond;
                sinValue = sinValue * 3 + sSub;
                cosValue = cosValue * 3 + cSub;
                return (sinValue >> 2 & 0xffff) | (cosValue >> 2 << 16);
            }
            sample = frame >> 2;
            goto half;
        }
        frame >>= 2;
    }
single:
    return ((const u32 *) values)[frame];
half:
    sinValue = values[sample].mFirst;
    sSub = (values + sample)[1].mFirst;
    cosValue = (values + sample)->mSecond;
    cSub = (values + sample)[1].mSecond;
    return (((sinValue + sSub) >> 1) & 0xffff) | ((cosValue + cSub) >> 1 << 16);
}

void GetTexSRTAnm_(const NNSG3dResTexSRTAnm *pTexAnm, u16 idx, u32 frame, NNSG3dMatAnmResult *pResult) {
    const NNSG3dResDictEntryHeader *dictEntries;
    const NNSG3dResDictTexSRTAnmData *srtData;
    u32 flag;
    s32 valueS;
    s32 valueT;
    u32 rotation;

    dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, &pTexAnm->mDict, pTexAnm->mDict.mOfsEntry);
    srtData = DICT_ENTRY(const NNSG3dResDictTexSRTAnmData, dictEntries, idx);
    flag = pResult->mFlag;
    valueS = GetTexSRTAnmVectorVal_(pTexAnm, srtData->mTransS, srtData->mTransSEx, frame);
    valueT = GetTexSRTAnmVectorVal_(pTexAnm, srtData->mTransT, srtData->mTransTEx, frame);
    if (valueS == 0 && valueT == 0) {
        flag |= G3D_MAT_ANM_TRANS_IS_IDENTITY;
    } else {
        pResult->mTransST[0] = valueS;
        pResult->mTransST[1] = valueT;
        flag &= ~G3D_MAT_ANM_TRANS_IS_IDENTITY;
    }
    rotation = GetTexSRTAnmSinCosVal_(pTexAnm, srtData->mRot, srtData->mRotEx, frame);
    if (rotation == 0x10000000) {
        flag |= G3D_MAT_ANM_ROT_IS_IDENTITY;
    } else {
        pResult->mSinCosR[0] = rotation;
        pResult->mSinCosR[1] = rotation >> 16;
        flag &= ~G3D_MAT_ANM_ROT_IS_IDENTITY;
    }
    valueS = GetTexSRTAnmVectorVal_(pTexAnm, srtData->mScaleS, srtData->mScaleSEx, frame);
    valueT = GetTexSRTAnmVectorVal_(pTexAnm, srtData->mScaleT, srtData->mScaleTEx, frame);
    if (valueS == 0x1000 && valueT == 0x1000) {
        flag |= G3D_MAT_ANM_SCALE_IS_IDENTITY;
    } else {
        pResult->mScaleST[0] = valueS;
        pResult->mScaleST[1] = valueT;
        flag &= ~G3D_MAT_ANM_SCALE_IS_IDENTITY;
    }
    pResult->mFlag = flag;
}

void NNSi_G3dAnmObjInitNsBta(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    volatile u16 zero;
    NNSG3dResTexSRTAnm *srtAnim;
    u8 *matBlock;
    NNSG3dResDictEntryHeader *dictEntries;
    s32 matIdx;
    u32 entryIndex;

    srtAnim = pResAnm;
    matBlock = (u8 *) pResMdl + pResMdl->mOfsMat;
    pAnmObj->mFuncAnm = NNS_G3dFuncAnmMatNsBtaDefault;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumMat;
    zero = 0;
    MIi_CpuClear16(zero, pAnmObj->mMapData, pAnmObj->mNumMapData * 2);
    for (entryIndex = 0; entryIndex < srtAnim->mDict.mNumEntry; entryIndex++) {
        dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &srtAnim->mDict, srtAnim->mDict.mOfsEntry);
        matIdx = NNS_G3dGetResDictIdxByName(matBlock + 4, DICT_ENTRY_NAME(dictEntries, entryIndex));
        if (matIdx >= 0) {
            pAnmObj->mMapData[matIdx] = entryIndex | 0x100;
        }
    }
}

void NNSi_G3dAnmCalcNsBta(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx) {
    GetTexSRTAnm_(pAnmObj->mResAnm, dataIdx, FROM_FIXED12(pAnmObj->mFrame), pResult);
    pResult->mPrmTexImage &= ~G3D_TEX_GEN_MASK;
    pResult->mPrmTexImage |= G3D_TEX_GEN_TEXCOORD;
    pResult->mFlag |= G3D_MAT_ANM_TEX_MTX_SET;
}

// Blends the two stored colors when the frame falls between them.
u16 GetMatColAnmValue_(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame) {
    u32 color;
    u32 sampleNext;
    u32 sample;
    u32 colorNext;
    const u16 *values;
    const u8 *base;
    u32 lastStep;

    if (info & 0x20000000) {
        return info;
    }
    base = (const u8 *) pAnm;
    values = (const u16 *) (base + (info & 0xffff));
    if (!(info & 0xc0000000)) {
        return values[frame];
    }
    lastStep = (info & 0x1fff0000) >> 16;
    if (info & 0x40000000) {
        if (frame & 1) {
            if (frame > lastStep) {
                return (&values[lastStep >> 1])[1];
            }
            sample = frame >> 1;
            goto half;
        }
        return values[frame >> 1];
    }
    if (frame & 3) {
        if (frame > lastStep) {
            return (&values[lastStep >> 2])[frame & 3];
        }
        if (frame & 1) {
            if (frame & 2) {
                sampleNext = frame >> 2;
                frame = sampleNext + 1;
            } else {
                frame >>= 2;
                sampleNext = frame + 1;
            }
            color = values[frame];
            return ((color & 0x7c1f) * 3 + ((u32) values[sampleNext] & 0x7c1f)) >> 2 & 0x7c1f |
                   ((color & 0x3e0) * 3 + ((u32) values[sampleNext] & 0x3e0)) >> 2 & 0x3e0;
        }
        sample = frame >> 2;
        goto half;
    }
    return values[frame >> 2];
half:
    color = values[sample];
    colorNext = (&values[sample])[1];
    return ((color & 0x7c1f) + (colorNext & 0x7c1f)) >> 1 & 0x7c1f |
           ((color & 0x3e0) + (colorNext & 0x3e0)) >> 1 & 0x3e0;
}

u16 GetMatColAnmuAlphaValue_(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame) {
    const u8 *values;
    u32 sampleNext;
    u32 lastStep;

    if (info & 0x20000000) {
        return info;
    }
    values = (const u8 *) pAnm;
    values += info & 0xffff;
    if (!(info & 0xc0000000)) {
        return values[frame];
    }
    lastStep = (info & 0x1fff0000) >> 16;
    if (info & 0x40000000) {
        if (frame & 1) {
            if (frame > lastStep) {
                return (&values[lastStep >> 1])[1];
            }
            return (values[frame >> 1] + (&values[frame >> 1])[1]) >> 1;
        }
        return values[frame >> 1];
    }
    if (frame & 3) {
        if (frame > lastStep) {
            return (&values[lastStep >> 2])[frame & 3];
        }
        if (frame & 1) {
            if (frame & 2) {
                sampleNext = frame >> 2;
                frame = sampleNext + 1;
            } else {
                frame >>= 2;
                sampleNext = frame + 1;
            }
            lastStep = values[sampleNext];
            frame = values[frame];
            return (frame * 3 + lastStep) >> 2;
        }
        return (values[frame >> 2] + (&values[frame >> 2])[1]) >> 1;
    }
    return values[frame >> 2];
}

void NNSi_G3dAnmObjInitNsBma(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    volatile u16 zero;
    NNSG3dResMatCAnm *colorAnim;
    u8 *matBlock;
    NNSG3dResDictEntryHeader *dictEntries;
    s32 matIdx;
    u32 entryIndex;

    colorAnim = pResAnm;
    matBlock = (u8 *) pResMdl + pResMdl->mOfsMat;
    pAnmObj->mFuncAnm = NNS_G3dFuncAnmMatNsBmaDefault;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumMat;
    zero = 0;
    MIi_CpuClear16(zero, pAnmObj->mMapData, pAnmObj->mNumMapData * 2);
    for (entryIndex = 0; entryIndex < colorAnim->mDict.mNumEntry; entryIndex++) {
        dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &colorAnim->mDict, colorAnim->mDict.mOfsEntry);
        matIdx = NNS_G3dGetResDictIdxByName(matBlock + 4, DICT_ENTRY_NAME(dictEntries, entryIndex));
        if (matIdx >= 0) {
            pAnmObj->mMapData[matIdx] = entryIndex | 0x100;
        }
    }
}

void NNSi_G3dAnmCalcNsBma(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx) {
    u32 colorValue;
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResMatCAnm *colorAnim;
    u32 frame;
    NNSG3dResDictMatCAnmData *colorData;

    colorAnim = pAnmObj->mResAnm;
    frame = FROM_FIXED12(pAnmObj->mFrame);
    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &colorAnim->mDict, colorAnim->mDict.mOfsEntry);
    colorData = DICT_ENTRY(NNSG3dResDictMatCAnmData, dictEntries, (u16) dataIdx);
    colorValue = GetMatColAnmValue_(colorAnim, colorData->mDiffuse, frame);
    pResult->mPrmMatColor0 = (pResult->mPrmMatColor0 & 0x8000) | colorValue |
                             (GetMatColAnmValue_(colorAnim, colorData->mAmbient, frame) << 16);
    colorValue = GetMatColAnmValue_(colorAnim, colorData->mEmission, frame);
    pResult->mPrmMatColor1 = (pResult->mPrmMatColor1 & 0x8000) |
                             GetMatColAnmValue_(colorAnim, colorData->mSpecular, frame) | (colorValue << 16);
    pResult->mPrmPolygonAttr = (pResult->mPrmPolygonAttr & ~0x1f0000) |
                               (GetMatColAnmuAlphaValue_(colorAnim, colorData->mPolygonAlpha, frame) << 16);
}

void NNSi_G3dAnmObjInitNsBca(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    volatile u16 zero;
    u32 nodeIndex;
    u16 *tagOffsets;
    NNSG3dResJntAnm *anim;

    anim = pResAnm;
    pAnmObj->mResAnm = pResAnm;
    pAnmObj->mFuncAnm = NNS_G3dFuncAnmJntNsBcaDefault;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumNode;
    zero = 0;
    MIi_CpuClear16(zero, pAnmObj->mMapData, pAnmObj->mNumMapData * 2);
    tagOffsets = anim->mTagOffsets;
    for (nodeIndex = 0; nodeIndex < anim->mNumNode; nodeIndex++) {
        pAnmObj->mMapData[nodeIndex] = (*OFFSET_PTR(u32, anim, tagOffsets[nodeIndex]) >> 24) | 0x100;
    }
}

void NNSi_G3dAnmCalcNsBca(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, int dataIdx) {
    s32 clampedFrame;
    s32 end;
    NNSG3dResJntAnm *jntAnim;

    jntAnim = pAnmObj->mResAnm;
    clampedFrame = pAnmObj->mFrame;
    end = TO_FIXED12(jntAnim->mNumFrame);
    if (clampedFrame >= end) {
        clampedFrame = end - 1;
    } else if (clampedFrame < 0) {
        clampedFrame = 0;
    }
    getJntSRTAnmResult_(jntAnim, dataIdx, clampedFrame, pResult);
}

void getMdlTrans_(NNSG3dJntAnmResult *out) {
    NNSG3dRS *rs;
    NNSG3dResDict *nodeInfo;
    u8 *table;
    NNSG3dResNodeData *node;
    const u32 *src;

    rs = NNS_G3dRS;
    nodeInfo = rs->mResNodeInfo;
    table = (u8 *) nodeInfo + nodeInfo->mOfsEntry;
    node = OFFSET_PTR(NNSG3dResNodeData, nodeInfo, *(u32 *) (table + *(u16 *) table * rs->mC[1] + 4));
    if (node->mFlag & G3D_NODE_TRANS_IDENTITY) {
        out->mFlag |= G3D_JNT_ANM_TRANS_IS_IDENTITY;
        return;
    }
    src = (const u32 *) node->mTransRotData;
    out->mTrans.x = src[0];
    out->mTrans.y = src[1];
    out->mTrans.z = src[2];
}

void getMdlScale_(NNSG3dJntAnmResult *out) {
    u32 flags;
    NNSG3dResDict *nodeInfo;
    u8 *table;
    NNSG3dRS *rs;
    u32 nodeOfs;
    u8 *scalePtr;
    u8 *cmd;

    rs = NNS_G3dRS;
    nodeInfo = rs->mResNodeInfo;
    cmd = rs->mC;
    table = (u8 *) nodeInfo + nodeInfo->mOfsEntry;
    nodeOfs = *(u32 *) (table + *(u16 *) table * cmd[1] + 4);
    flags = *OFFSET_PTR(u16, nodeInfo, nodeOfs);
    scalePtr = (u8 *) nodeInfo + nodeOfs + 4;
    if (!(flags & 1)) {
        scalePtr += 0xc;
    }
    if (!(flags & 2)) {
        if (flags & 8) {
            scalePtr += 4;
        } else {
            scalePtr += 0x10;
        }
    }
    rs->mFuncJntScale(out, scalePtr, cmd, flags);
}

void getMdlRot_(NNSG3dJntAnmResult *out) {
    s32 first;
    NNSG3dRS *rs;
    s32 second;
    u8 *table;
    NNSG3dResDict *nodeInfo;
    s32 pivot;
    NNSG3dResNodeData *node;
    const s16 *vals;

    rs = NNS_G3dRS;
    nodeInfo = rs->mResNodeInfo;
    table = (u8 *) nodeInfo + nodeInfo->mOfsEntry;
    node = OFFSET_PTR(NNSG3dResNodeData, nodeInfo, *(u32 *) (table + *(u16 *) table * rs->mC[1] + 4));
    vals = node->mTransRotData;
    if (!(node->mFlag & G3D_NODE_TRANS_IDENTITY)) {
        vals += 6;
    }
    if (!(node->mFlag & G3D_NODE_ROT_IDENTITY)) {
        if (node->mFlag & G3D_NODE_ROT_PIVOT) {
            pivot = (node->mFlag & G3D_NODE_ROT_PIVOT_MASK) >> 4;
            first = vals[0];
            second = vals[1];
            MI_Zero36B(&out->mRot);
            out->mRot.mElements[pivot] = (node->mFlag & G3D_NODE_ROT_PIVOT_NEGATIVE) ? -0x1000 : 0x1000;
            out->mRot.mElements[gRotPivotIndices[pivot][0]] = first;
            out->mRot.mElements[gRotPivotIndices[pivot][1]] = second;
            if (node->mFlag & G3D_NODE_ROT_NEGATE_SECOND) {
                second = -second;
            }
            out->mRot.mElements[gRotPivotIndices[pivot][2]] = second;
            if (node->mFlag & G3D_NODE_ROT_NEGATE_FIRST) {
                first = -first;
            }
            out->mRot.mElements[gRotPivotIndices[pivot][3]] = first;
        } else {
            out->mRot.mElements[0] = node->mRotFirst;
            out->mRot.mElements[1] = vals[0];
            out->mRot.mElements[2] = vals[1];
            out->mRot.mElements[3] = vals[2];
            out->mRot.mElements[4] = vals[3];
            out->mRot.mElements[5] = vals[4];
            out->mRot.mElements[6] = vals[5];
            out->mRot.mElements[7] = vals[6];
            out->mRot.mElements[8] = vals[7];
        }
    } else {
        out->mFlag |= G3D_JNT_ANM_ROT_IS_IDENTITY;
    }
}

void getJntSRTAnmResult_(const NNSG3dResJntAnm *jntAnm, int node, s32 frame, NNSG3dJntAnmResult *out) {
    s32 scaleTmp[3][2];
    s32 scaleOut[2][3];
    int interp;
    u32 flags;
    const u32 *cursor;
    const u32 *tag;
    s32 row0X;
    s32 row0Y;
    s32 row0Z;
    s32 row1X;
    s32 row1Y;
    s32 row1Z;

    tag = OFFSET_PTR(const u32, jntAnm, jntAnm->mTagOffsets[node]);
    flags = tag[0];
    if (flags & 1) {
        out->mFlag = G3D_JNT_ANM_ALL_IDENTITY;
    } else {
        cursor = tag + 1;
        if ((frame & 0xfff) && (jntAnm->mFlag & G3D_JNT_ANM_RES_FLAG_BLEND)) {
            interp = 1;
        } else {
            interp = 0;
        }
        out->mFlag = 0;
        if (!(flags & 6)) {
            if (!(flags & 8)) {
                if (interp) {
                    getTransDataEx_(&out->mTrans.x, frame, cursor, jntAnm);
                } else {
                    getTransData_(&out->mTrans.x, frame, cursor, jntAnm);
                }
                cursor += 2;
            } else {
                out->mTrans.x = *cursor++;
            }
            if (!(flags & 0x10)) {
                if (interp) {
                    getTransDataEx_(&out->mTrans.y, frame, cursor, jntAnm);
                } else {
                    getTransData_(&out->mTrans.y, frame, cursor, jntAnm);
                }
                cursor += 2;
            } else {
                out->mTrans.y = *cursor++;
            }
            if (!(flags & 0x20)) {
                if (interp) {
                    getTransDataEx_(&out->mTrans.z, frame, cursor, jntAnm);
                } else {
                    getTransData_(&out->mTrans.z, frame, cursor, jntAnm);
                }
                cursor += 2;
            } else {
                out->mTrans.z = *cursor++;
            }
        } else if (flags & 2) {
            out->mFlag |= G3D_JNT_ANM_TRANS_IS_IDENTITY;
        } else {
            getMdlTrans_(out);
        }
        if (!(flags & 0xc0)) {
            if (!(flags & 0x100)) {
                if (interp) {
                    getRotDataEx_(&out->mRot, frame, cursor, jntAnm);
                } else {
                    getRotData_(&out->mRot, frame, cursor, jntAnm);
                }
                cursor += 2;
            } else {
                if (getRotDataByIdx_(&out->mRot, OFFSET_PTR(const s16, jntAnm, jntAnm->mOfsRot3),
                                     OFFSET_PTR(const s16, jntAnm, jntAnm->mOfsRot5), *cursor)) {
                    row1Z = out->mRot.mRows[1].z;
                    row0X = out->mRot.mRows[0].x;
                    row1X = out->mRot.mRows[1].x;
                    row0Z = out->mRot.mRows[0].z;
                    row0Y = out->mRot.mRows[0].y;
                    row1Y = out->mRot.mRows[1].y;
                    out->mRot.mRows[2].x = (row0Y * row1Z - row0Z * row1Y) >> 12;
                    out->mRot.mRows[2].y = (row0Z * row1X - row0X * row1Z) >> 12;
                    out->mRot.mRows[2].z = (row0X * row1Y - row0Y * row1X) >> 12;
                }
                cursor += 1;
            }
        } else if (flags & 0x40) {
            out->mFlag |= G3D_JNT_ANM_ROT_IS_IDENTITY;
        } else {
            getMdlRot_(out);
        }
        if (!(flags & 0x600)) {
            if (!(flags & 0x800)) {
                if (interp) {
                    getScaleDataEx_(scaleTmp[0], frame, cursor, jntAnm);
                } else {
                    getScaleData_(scaleTmp[0], frame, cursor, jntAnm);
                }
                scaleOut[0][0] = scaleTmp[0][0];
                scaleOut[1][0] = scaleTmp[0][1];
            } else {
                scaleOut[0][0] = cursor[0];
                scaleOut[1][0] = cursor[1];
            }
            if (!(flags & 0x1000)) {
                if (interp) {
                    getScaleDataEx_(scaleTmp[1], frame, cursor + 2, jntAnm);
                } else {
                    getScaleData_(scaleTmp[1], frame, cursor + 2, jntAnm);
                }
                scaleOut[0][1] = scaleTmp[1][0];
                scaleOut[1][1] = scaleTmp[1][1];
            } else {
                scaleOut[0][1] = cursor[2];
                scaleOut[1][1] = cursor[3];
            }
            if (!(flags & 0x2000)) {
                if (interp) {
                    getScaleDataEx_(scaleTmp[2], frame, cursor + 4, jntAnm);
                } else {
                    getScaleData_(scaleTmp[2], frame, cursor + 4, jntAnm);
                }
                scaleOut[0][2] = scaleTmp[2][0];
                scaleOut[1][2] = scaleTmp[2][1];
            } else {
                scaleOut[0][2] = cursor[4];
                scaleOut[1][2] = cursor[5];
            }
        } else if (flags & 0x200) {
            out->mFlag |= G3D_JNT_ANM_SCALE_IS_IDENTITY;
        } else {
            getMdlScale_(out);
            return;
        }
    }
    NNS_G3dRS->mFuncJntScale(out, scaleOut, NNS_G3dRS->mC, (out->mFlag & G3D_JNT_ANM_SCALE_IS_IDENTITY) ? 4 : 0);
}

void getTransData_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    s32 sample0;
    u32 lastStep;
    const u8 *values;
    u32 info;
    u32 indexA;
    u32 frameIndex;
    s32 sample1;
    u32 indexB;

    frameIndex = FROM_FIXED12(frame);
    values = (const u8 *) jntAnm + desc[1];
    info = desc[0];
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (frameIndex & 1) {
                if (frameIndex > lastStep) {
                    frameIndex = (lastStep >> 1) + 1;
                    goto single;
                }
                indexA = frameIndex >> 1;
            } else {
                frameIndex >>= 1;
                goto single;
            }
        } else {
            if (frameIndex & 3) {
                if (frameIndex > lastStep) {
                    frameIndex = (frameIndex & 3) + (lastStep >> 2);
                    goto single;
                }
                if (frameIndex & 1) {
                    if (frameIndex & 2) {
                        indexB = frameIndex >> 2;
                        indexA = indexB + 1;
                    } else {
                        indexA = frameIndex >> 2;
                        indexB = indexA + 1;
                    }
                    if (info & 0x20000000) {
                        sample0 = ((const s16 *) values)[indexA];
                        sample1 = ((const s16 *) values)[indexB];
                        *out = (sample0 + sample0 + sample0 + sample1) >> 2;
                    } else {
                        sample0 = ((const s32 *) values)[indexA];
                        sample1 = ((const s32 *) values)[indexB];
                        *out = ((s64) sample0 + sample0 + sample0 + sample1) >> 2;
                    }
                    return;
                }
                indexA = frameIndex >> 2;
            } else {
                frameIndex >>= 2;
                goto single;
            }
        }
        if (info & 0x20000000) {
            sample0 = ((const s16 *) values)[indexA];
            sample1 = (&((const s16 *) values)[indexA])[1];
            *out = (sample0 + sample1) >> 1;
        } else {
            sample0 = ((const s32 *) values)[indexA];
            sample1 = (&((const s32 *) values)[indexA])[1];
            *out = (sample0 >> 1) + (sample1 >> 1);
        }
        return;
    }
single:
    if (info & 0x20000000) {
        *out = ((const s16 *) values)[frameIndex];
    } else {
        *out = ((const s32 *) values)[frameIndex];
    }
}

void getTransDataEx_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    u32 lastStep;
    const u8 *values;
    s32 fraction;
    s32 sample1;
    s32 stepBits;
    u32 info;
    s32 step;
    u32 frameIndex;
    s32 sample0;

    frameIndex = FROM_FIXED12(frame);
    values = (const u8 *) jntAnm + desc[1];
    info = desc[0];
    if (frameIndex == jntAnm->mNumFrame - 1) {
        if (info & 0xc0000000) {
            if (info & 0x40000000) {
                frameIndex = (frameIndex & 1) + (frameIndex >> 1);
            } else {
                frameIndex = (frameIndex & 3) + (frameIndex >> 2);
            }
        }
        if (jntAnm->mFlag & G3D_JNT_ANM_RES_FLAG_LOOPS) {
            stepBits = frame & 0xfff;
            if (info & 0x20000000) {
                sample0 = ((const s16 *) values)[frameIndex];
                fraction = ((const s16 *) values)[0];
            } else {
                sample0 = ((const s32 *) values)[frameIndex];
                fraction = ((const s32 *) values)[0];
            }
            *out = sample0 + ((stepBits * (fraction - sample0)) >> 12);
        } else {
            if (info & 0x20000000) {
                *out = ((const s16 *) values)[frameIndex];
            } else {
                *out = ((const s32 *) values)[frameIndex];
            }
        }
        return;
    }
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (frameIndex >= lastStep) {
                frameIndex = lastStep >> 1;
                goto last;
            }
            frameIndex >>= 1;
            fraction = frame & 0x1fff;
            step = 2;
            stepBits = 1;
        } else {
            if (frameIndex >= lastStep) {
                frameIndex = (frameIndex & 3) + (frameIndex >> 2);
                goto last;
            }
            frameIndex >>= 2;
            fraction = frame & 0x3fff;
            step = 4;
            stepBits = 2;
        }
    } else {
    last:
        fraction = frame & 0xfff;
        step = 1;
        stepBits = 0;
    }
    if (info & 0x20000000) {
        sample0 = ((const s16 *) values)[frameIndex];
        sample1 = (&((const s16 *) values)[frameIndex])[1];
    } else {
        sample0 = ((const s32 *) values)[frameIndex];
        sample1 = (&((const s32 *) values)[frameIndex])[1];
    }
    *out = (sample0 * step + ((fraction * (sample1 - sample0)) >> 12)) >> stepBits;
}

void getScaleData_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    u32 info;
    const FxPairS16 *values16;
    const FxPairS32 *values32;
    u32 indexA;
    s32 second;
    u32 lastStep;
    s32 first;
    const FxPairS16 *pair16;
    const FxPairS32 *pair32;
    u32 frameIndex;

    frameIndex = FROM_FIXED12(frame);
    values16 = OFFSET_PTR(const FxPairS16, jntAnm, desc[1]);
    values32 = OFFSET_PTR(const FxPairS32, jntAnm, desc[1]);
    info = desc[0];
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (frameIndex & 1) {
                if (frameIndex > lastStep) {
                    frameIndex = (lastStep >> 1) + 1;
                    goto single;
                }
                indexA = frameIndex >> 1;
                goto half;
            }
            frameIndex >>= 1;
            goto single;
        }
        if (frameIndex & 3) {
            if (frameIndex > lastStep) {
                frameIndex = (frameIndex & 3) + (lastStep >> 2);
                goto single;
            }
            if (frameIndex & 1) {
                if (frameIndex & 2) {
                    frameIndex >>= 2;
                    indexA = frameIndex + 1;
                } else {
                    indexA = frameIndex >> 2;
                    frameIndex = indexA + 1;
                }
                if (info & 0x20000000) {
                    pair16 = values16 + indexA;
                    first = values16[indexA].mFirst;
                    second = values16[frameIndex].mFirst;
                    out[0] = (first + (first << 1) + second) >> 2;
                    first = pair16->mSecond;
                    second = (values16 + frameIndex)->mSecond;
                    out[1] = (first + (first << 1) + second) >> 2;
                } else {
                    pair32 = values32 + indexA;
                    first = values32[indexA].mFirst;
                    second = values32[frameIndex].mFirst;
                    out[0] = ((s64) first + first + first + second) >> 2;
                    first = pair32->mSecond;
                    second = (values32 + frameIndex)->mSecond;
                    out[1] = ((s64) first + first + first + second) >> 2;
                }
                return;
            }
            indexA = frameIndex >> 2;
            goto half;
        }
        frameIndex >>= 2;
    }
single:
    if (info & 0x20000000) {
        out[0] = values16[frameIndex].mFirst;
        out[1] = values16[frameIndex].mSecond;
    } else {
        out[0] = values32[frameIndex].mFirst;
        out[1] = values32[frameIndex].mSecond;
    }
    return;
half:
    if (info & 0x20000000) {
        pair16 = values16 + indexA;
        out[0] = (pair16->mFirst + pair16[1].mFirst) >> 1;
        out[1] = (pair16->mSecond + pair16[1].mSecond) >> 1;
    } else {
        pair32 = values32 + indexA;
        out[0] = (pair32->mFirst + pair32[1].mFirst) >> 1;
        out[1] = (pair32->mSecond + pair32[1].mSecond) >> 1;
    }
}

void getScaleDataEx_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    const FxPairS16 *values16;
    const FxPairS32 *values32;
    u32 info;
    s32 scale1;
    u32 frameIndex;
    u32 nextIndex;
    s32 fraction;
    s32 step;
    s32 stepBits;
    s32 invScale1;
    s32 scale0;
    s32 invScale0;
    u32 lastStep;

    frameIndex = FROM_FIXED12(frame);
    values16 = OFFSET_PTR(const FxPairS16, jntAnm, desc[1]);
    values32 = OFFSET_PTR(const FxPairS32, jntAnm, desc[1]);
    info = desc[0];
    if (frameIndex == jntAnm->mNumFrame - 1) {
        if (info & 0xc0000000) {
            if (info & 0x40000000) {
                frameIndex = (frameIndex & 1) + (frameIndex >> 1);
            } else {
                frameIndex = (frameIndex & 3) + (frameIndex >> 2);
            }
        }
        if (jntAnm->mFlag & G3D_JNT_ANM_RES_FLAG_LOOPS) {
            nextIndex = 0;
            goto last;
        }
        if (info & 0x20000000) {
            out[0] = values16[frameIndex].mFirst;
            out[1] = values16[frameIndex].mSecond;
        } else {
            out[0] = values32[frameIndex].mFirst;
            out[1] = values32[frameIndex].mSecond;
        }
        return;
    }
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (frameIndex >= lastStep) {
                frameIndex = lastStep >> 1;
                nextIndex = frameIndex + 1;
                goto last;
            }
            frameIndex >>= 1;
            nextIndex = frameIndex + 1;
            fraction = frame & 0x1fff;
            step = 2;
            stepBits = 1;
        } else {
            if (frameIndex >= lastStep) {
                frameIndex = (frameIndex & 3) + (frameIndex >> 2);
                nextIndex = frameIndex + 1;
                goto last;
            }
            frameIndex >>= 2;
            nextIndex = frameIndex + 1;
            fraction = frame & 0x3fff;
            step = 4;
            stepBits = 2;
        }
    } else {
        nextIndex = frameIndex + 1;
    last:
        fraction = frame & 0xfff;
        step = 1;
        stepBits = 0;
    }
    if (info & 0x20000000) {
        scale0 = values16[frameIndex].mFirst;
        invScale0 = values16[frameIndex].mSecond;
        scale1 = values16[nextIndex].mFirst;
        invScale1 = values16[nextIndex].mSecond;
    } else {
        scale0 = values32[frameIndex].mFirst;
        invScale0 = values32[frameIndex].mSecond;
        scale1 = values32[nextIndex].mFirst;
        invScale1 = values32[nextIndex].mSecond;
    }
    out[0] = (scale0 * step + ((fraction * (scale1 - scale0)) >> 12)) >> stepBits;
    out[1] = (invScale0 * step + ((fraction * (invScale1 - invScale0)) >> 12)) >> stepBits;
}

void getRotData_(MtxFx33 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    MtxFx33 startMtx;
    MtxFx33 endMtx;
    const s16 *rot3Table;
    const s16 *rot5Table;
    u32 info;
    const u16 *values;
    u32 frameIndex;
    u32 lastStep;
    int pairIndex;
    u32 firstIndex;
    u32 secondIndex;
    int needsCross;
    s32 row0X;
    s32 row0Y;
    s32 row0Z;
    s32 row1X;
    s32 row1Y;
    s32 row1Z;

    frameIndex = FROM_FIXED12(frame);
    rot3Table = OFFSET_PTR(const s16, jntAnm, jntAnm->mOfsRot3);
    rot5Table = OFFSET_PTR(const s16, jntAnm, jntAnm->mOfsRot5);
    info = desc[0];
    values = OFFSET_PTR(const u16, jntAnm, desc[1]);
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (frameIndex & 1) {
                if (frameIndex > lastStep) {
                    frameIndex = (lastStep >> 1) + 1;
                    goto single;
                }
                pairIndex = frameIndex >> 1;
            } else {
                frameIndex >>= 1;
                goto single;
            }
        } else {
            if (frameIndex & 3) {
                if (frameIndex > lastStep) {
                    frameIndex = (frameIndex & 3) + (lastStep >> 2);
                    goto single;
                }
                if (frameIndex & 1) {
                    needsCross = 0;
                    if (frameIndex & 2) {
                        secondIndex = frameIndex >> 2;
                        firstIndex = secondIndex + 1;
                    } else {
                        firstIndex = frameIndex >> 2;
                        secondIndex = firstIndex + 1;
                    }
                    needsCross |= getRotDataByIdx_(out, rot3Table, rot5Table, values[firstIndex]);
                    needsCross |= getRotDataByIdx_(&startMtx, rot3Table, rot5Table, values[secondIndex]);
                    out->mRows[0].x = out->mRows[0].x * 3 + startMtx.mRows[0].x;
                    out->mRows[0].y = out->mRows[0].y * 3 + startMtx.mRows[0].y;
                    out->mRows[0].z = out->mRows[0].z * 3 + startMtx.mRows[0].z;
                    out->mRows[1].x = out->mRows[1].x * 3 + startMtx.mRows[1].x;
                    out->mRows[1].y = out->mRows[1].y * 3 + startMtx.mRows[1].y;
                    out->mRows[1].z = out->mRows[1].z * 3 + startMtx.mRows[1].z;
                    VEC_Normalize(&out->mRows[0], &out->mRows[0]);
                    VEC_Normalize(&out->mRows[1], &out->mRows[1]);
                    if (needsCross == 0) {
                        out->mRows[2].x = out->mRows[2].x * 3 + startMtx.mRows[2].x;
                        out->mRows[2].y = out->mRows[2].y * 3 + startMtx.mRows[2].y;
                        out->mRows[2].z = out->mRows[2].z * 3 + startMtx.mRows[2].z;
                        VEC_Normalize(&out->mRows[2], &out->mRows[2]);
                    } else {
                        row1Z = out->mRows[1].z;
                        row0X = out->mRows[0].x;
                        row1X = out->mRows[1].x;
                        row0Z = out->mRows[0].z;
                        row0Y = out->mRows[0].y;
                        row1Y = out->mRows[1].y;
                        out->mRows[2].x = (row0Y * row1Z - row0Z * row1Y) >> 12;
                        out->mRows[2].y = (row0Z * row1X - row0X * row1Z) >> 12;
                        out->mRows[2].z = (row0X * row1Y - row0Y * row1X) >> 12;
                    }
                    return;
                }
                pairIndex = frameIndex >> 2;
            } else {
                frameIndex >>= 2;
                goto single;
            }
        }
        needsCross = 0;
        needsCross |= getRotDataByIdx_(out, rot3Table, rot5Table, values[pairIndex]);
        needsCross |= getRotDataByIdx_(&endMtx, rot3Table, rot5Table, *(values + pairIndex + 1));
        out->mRows[0].x += endMtx.mRows[0].x;
        out->mRows[0].y += endMtx.mRows[0].y;
        out->mRows[0].z += endMtx.mRows[0].z;
        out->mRows[1].x += endMtx.mRows[1].x;
        out->mRows[1].y += endMtx.mRows[1].y;
        out->mRows[1].z += endMtx.mRows[1].z;
        VEC_Normalize(&out->mRows[0], &out->mRows[0]);
        VEC_Normalize(&out->mRows[1], &out->mRows[1]);
        if (needsCross == 0) {
            out->mRows[2].x += endMtx.mRows[2].x;
            out->mRows[2].y += endMtx.mRows[2].y;
            out->mRows[2].z += endMtx.mRows[2].z;
            VEC_Normalize(&out->mRows[2], &out->mRows[2]);
        } else {
            row1Z = out->mRows[1].z;
            row0X = out->mRows[0].x;
            row1X = out->mRows[1].x;
            row0Z = out->mRows[0].z;
            row0Y = out->mRows[0].y;
            row1Y = out->mRows[1].y;
            out->mRows[2].x = (row0Y * row1Z - row0Z * row1Y) >> 12;
            out->mRows[2].y = (row0Z * row1X - row0X * row1Z) >> 12;
            out->mRows[2].z = (row0X * row1Y - row0Y * row1X) >> 12;
        }
        return;
    }
single:
    if (getRotDataByIdx_(out, rot3Table, rot5Table, values[frameIndex]) == 0) {
        return;
    }
    row1Z = out->mRows[1].z;
    row0X = out->mRows[0].x;
    row1X = out->mRows[1].x;
    row0Z = out->mRows[0].z;
    row0Y = out->mRows[0].y;
    row1Y = out->mRows[1].y;
    out->mRows[2].x = (row0Y * row1Z - row0Z * row1Y) >> 12;
    out->mRows[2].y = (row0Z * row1X - row0X * row1Z) >> 12;
    out->mRows[2].z = (row0X * row1Y - row0Y * row1X) >> 12;
}

void getRotDataEx_(MtxFx33 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    s32 row2ZStart;
    s32 row0Y;
    u32 lastStep;
    MtxFx33 startMtx;
    MtxFx33 endMtx;
    u32 needsCross;
    s32 row1Z;
    s32 row1X;
    s32 row1Y;
    u32 info;
    const s16 *rot3Table;
    s32 row1ZSaved;
    const s16 *rot5Table;
    u32 frameIndex;
    s32 fraction;
    s32 step;
    s32 row0X;
    const u16 *values;
    s32 row0Z;
    u32 nextIndex;

    frameIndex = FROM_FIXED12(frame);
    rot3Table = OFFSET_PTR(const s16, jntAnm, jntAnm->mOfsRot3);
    rot5Table = OFFSET_PTR(const s16, jntAnm, jntAnm->mOfsRot5);
    info = desc[0];
    values = OFFSET_PTR(const u16, jntAnm, desc[1]);
    if (frameIndex == jntAnm->mNumFrame - 1) {
        if (info & 0xc0000000) {
            if (info & 0x40000000) {
                frameIndex = (frameIndex & 1) + (frameIndex >> 1);
            } else {
                frameIndex = (frameIndex & 3) + (frameIndex >> 2);
            }
        }
        if (jntAnm->mFlag & G3D_JNT_ANM_RES_FLAG_LOOPS) {
            nextIndex = 0;
            goto interp1;
        }
        if (getRotDataByIdx_(out, rot3Table, rot5Table, values[frameIndex]) == 0) {
            return;
        }
        row1Z = out->mRows[1].z;
        row0X = out->mRows[0].x;
        row1X = out->mRows[1].x;
        row0Y = out->mRows[0].y;
        row0Z = out->mRows[0].z;
        row1Y = out->mRows[1].y;
        out->mRows[2].x = (row0Y * row1Z - row0Z * row1Y) >> 12;
        out->mRows[2].y = (row0Z * row1X - row0X * row1Z) >> 12;
        out->mRows[2].z = (row0X * row1Y - row0Y * row1X) >> 12;
        return;
    }
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (frameIndex >= lastStep) {
                frameIndex = lastStep >> 1;
                nextIndex = frameIndex + 1;
                goto interp1;
            }
            frameIndex >>= 1;
            nextIndex = frameIndex + 1;
            step = 2;
            fraction = frame & 0x1fff;
        } else {
            if (frameIndex >= lastStep) {
                frameIndex = (frameIndex & 3) + (frameIndex >> 2);
                nextIndex = frameIndex + 1;
                goto interp1;
            }
            frameIndex >>= 2;
            nextIndex = frameIndex + 1;
            fraction = frame & 0x3fff;
            step = 4;
        }
        goto interp;
    } else {
        nextIndex = frameIndex + 1;
    }
interp1:
    step = 1;
    fraction = frame & 0xfff;
interp:
    needsCross = 0;
    needsCross |= getRotDataByIdx_(&startMtx, rot3Table, rot5Table, values[frameIndex]);
    needsCross |= getRotDataByIdx_(&endMtx, rot3Table, rot5Table, values[nextIndex]);
    out->mRows[0].x = startMtx.mRows[0].x * step + ((fraction * (endMtx.mRows[0].x - startMtx.mRows[0].x)) >> 12);
    out->mRows[0].y = startMtx.mRows[0].y * step + ((fraction * (endMtx.mRows[0].y - startMtx.mRows[0].y)) >> 12);
    out->mRows[0].z = startMtx.mRows[0].z * step + ((fraction * (endMtx.mRows[0].z - startMtx.mRows[0].z)) >> 12);
    out->mRows[1].x = startMtx.mRows[1].x * step + ((fraction * (endMtx.mRows[1].x - startMtx.mRows[1].x)) >> 12);
    out->mRows[1].y = startMtx.mRows[1].y * step + ((fraction * (endMtx.mRows[1].y - startMtx.mRows[1].y)) >> 12);
    out->mRows[1].z = startMtx.mRows[1].z * step + ((fraction * (endMtx.mRows[1].z - startMtx.mRows[1].z)) >> 12);
    VEC_Normalize(&out->mRows[0], &out->mRows[0]);
    VEC_Normalize(&out->mRows[1], &out->mRows[1]);
    if (needsCross == 0) {
        out->mRows[2].x = startMtx.mRows[2].x * step + ((fraction * (endMtx.mRows[2].x - startMtx.mRows[2].x)) >> 12);
        out->mRows[2].y = startMtx.mRows[2].y * step + ((fraction * (endMtx.mRows[2].y - startMtx.mRows[2].y)) >> 12);
        row2ZStart = startMtx.mRows[2].z;
        out->mRows[2].z = startMtx.mRows[2].z * step + ((fraction * (endMtx.mRows[2].z - row2ZStart)) >> 12);
        VEC_Normalize(&out->mRows[2], &out->mRows[2]);
    } else {
        row1ZSaved = out->mRows[1].z;
        row0X = out->mRows[0].x;
        row0Z = out->mRows[0].z;
        row1Z = row1ZSaved;
        row1X = out->mRows[1].x;
        row0Y = out->mRows[0].y;
        row1Y = out->mRows[1].y;
        out->mRows[2].x = (row0Y * row1Z - row0Z * row1Y) >> 12;
        out->mRows[2].y = (row0Z * row1X - row0X * row1Z) >> 12;
        out->mRows[2].z = (row0X * row1Y - row0Y * row1X) >> 12;
    }
}

BOOL getRotDataByIdx_(MtxFx33 *out, const s16 *rot3, const s16 *rot5, u32 info) {
    s32 valueX;
    s32 valueY;
    s32 packed;
    const s16 *rotEntry;
    s16 extraBits;
    u32 axisIndex;
    s32 header;

    if (info & 0x8000) {
        out->mElements[0] = out->mElements[1] = out->mElements[2] = out->mElements[3] = out->mElements[4] =
            out->mElements[5] = out->mElements[6] = out->mElements[7] = out->mElements[8] = 0;
        info = (info & 0x7fff) * 3;
        rotEntry = rot3 + info;
        header = rot3[info];
        axisIndex = header & 0xf;
        valueX = rotEntry[1];
        valueY = rotEntry[2];
        out->mElements[axisIndex] = (header & 0x10) ? -0x1000 : 0x1000;
        out->mElements[gRotPivotIndices[axisIndex][0]] = valueX;
        out->mElements[gRotPivotIndices[axisIndex][1]] = valueY;
        if (rotEntry[0] & 0x20) {
            valueY = -valueY;
        }
        out->mElements[gRotPivotIndices[axisIndex][2]] = valueY;
        if (rotEntry[0] & 0x40) {
            valueX = -valueX;
        }
        out->mElements[gRotPivotIndices[axisIndex][3]] = valueX;
        return 0;
    }
    info = (info & 0x7fff) * 5;
    rotEntry = rot5 + info;
    packed = rotEntry[4];
    out->mElements[4] = packed >> 3;
    extraBits = packed & 7;
    packed = rot5[info];
    out->mElements[0] = packed >> 3;
    extraBits = (extraBits << 3) | (packed & 7);
    packed = rotEntry[1];
    out->mElements[1] = packed >> 3;
    extraBits = (extraBits << 3) | (packed & 7);
    packed = rotEntry[2];
    out->mElements[2] = packed >> 3;
    extraBits = (extraBits << 3) | (packed & 7);
    packed = rotEntry[3];
    out->mElements[3] = packed >> 3;
    extraBits = (extraBits << 3) | (packed & 7);
    out->mElements[5] = (extraBits << 19) >> 19;
    return 1;
}

void *NNSi_G3dGetBinaryBlockFromFile(const u8 *pFileHead, u32 fileSignature, u32 blockSignature) {
    const NNSG3dResFileHeader *fileHeader;
    NNSG3dResDataBlockHeader *blockHeader;
    u32 blockIndex;

    fileHeader = (const NNSG3dResFileHeader *) pFileHead;
    if (fileHeader->mSigVal == fileSignature) {
        for (blockIndex = 0; blockIndex < fileHeader->mDataBlocks; blockIndex++) {
            blockHeader = NNS_G3dGetDataBlockHeaderByIdx(fileHeader, blockIndex);
            if (blockHeader->mSignature == blockSignature) {
                return blockHeader;
            }
        }
    }
    return 0;
}

NNSG3dResVisAnm *NNS_G3dGetVisAnmByIdx(NNSG3dResVisAnmSet *pAnmSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pAnmSet->mDict, pAnmSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResVisAnm, pAnmSet, setEntry->mOffset);
}

NNSG3dResVisAnmSet *NNS_G3dGetVisAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30415642, 0x30534956);
}
