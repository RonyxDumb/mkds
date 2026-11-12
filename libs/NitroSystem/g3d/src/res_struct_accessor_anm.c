#include "res_struct_accessor_anm.h"

const u32 *NNSi_G3dGetTexPatAnmTexNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 texIdx) {
    return (const u32 *) ((const u8 *) pPatAnm + pPatAnm->mOfsTexName + (texIdx << 4));
}

const u32 *NNSi_G3dGetTexPatAnmPlttNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx) {
    return (const u32 *) ((const u8 *) pPatAnm + pPatAnm->mOfsPlttName + (plttIdx << 4));
}

NNSG3dResTexPatAnmFV *NNSi_G3dGetTexPatAnmFV(const NNSG3dResTexPatAnm *pPatAnm, u32 idx, u32 frame) {
    NNSG3dResDictTexPatAnmData *patData;
    NNSG3dResTexPatAnmFV *frames;
    u32 cur;

    patData = NNSi_G3dGetTexPatAnmDataByIdx(pPatAnm, idx);
    cur = patData->mRatioDataFrame;
    frames = OFFSET_PTR(NNSG3dResTexPatAnmFV, pPatAnm, patData->mOffset);
    cur = (cur * frame) >> 12;
    while (cur != 0 && frames[cur].mIdxFrame >= frame) {
        cur--;
    }
    while (cur + 1 < patData->mNumFV && (&frames[cur])[1].mIdxFrame <= frame) {
        cur++;
    }
    return &frames[cur];
}

NNSG3dResDictTexPatAnmData *NNSi_G3dGetTexPatAnmDataByIdx(const NNSG3dResTexPatAnm *pPatAnm, u32 idx) {
    NNSG3dResDictEntryHeader *entry;

    entry = OFFSET_PTR(NNSG3dResDictEntryHeader, &pPatAnm->mDict, pPatAnm->mDict.mOfsEntry);
    return (NNSG3dResDictTexPatAnmData *) (entry->mData + entry->mSizeUnit * idx);
}
